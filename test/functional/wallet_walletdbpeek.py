#!/usr/bin/env python3
# Copyright (c) 2026-present The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or https://www.opensource.org/licenses/mit-license.php.
"""Test the walletdbpeek RPC."""

from test_framework.test_framework import BitcoinTestFramework
from test_framework.util import (
    assert_equal,
    assert_greater_than,
)


class WalletDbPeekTest(BitcoinTestFramework):
    def set_test_params(self):
        self.num_nodes = 1

    def skip_test_if_missing_module(self):
        self.skip_if_no_wallet()

    def check_consistent(self, peek):
        assert_equal(peek["format"], "sqlite")
        assert_equal(peek["records"], sum(peek["record_types"].values()))
        assert_greater_than(peek["records"], 0)

    def test_fresh_wallet(self):
        self.log.info("Test that a fresh wallet reports its records by type")
        self.nodes[0].createwallet(wallet_name="peek")
        wallet = self.nodes[0].get_wallet_rpc("peek")

        peek = wallet.walletdbpeek()
        self.check_consistent(peek)
        types = peek["record_types"]
        for expected in ("flags", "minversion", "version", "walletdescriptor"):
            assert expected in types, f"missing {expected} record type"
        assert_equal(types["walletdescriptor"], len(wallet.listdescriptors()["descriptors"]))
        assert "name" not in types
        assert "mkey" not in types

    def test_records_track_wallet_changes(self):
        self.log.info("Test that record counts follow address book changes")
        wallet = self.nodes[0].get_wallet_rpc("peek")
        before = wallet.walletdbpeek()

        wallet.getnewaddress(label="peeked")
        after = wallet.walletdbpeek()
        self.check_consistent(after)
        assert_greater_than(after["records"], before["records"])
        assert_equal(after["record_types"]["name"], 1)

    def test_encrypted_wallet(self):
        self.log.info("Test that peeking works on a locked, encrypted wallet")
        wallet = self.nodes[0].get_wallet_rpc("peek")
        wallet.encryptwallet("pass")
        assert_equal(wallet.getwalletinfo()["unlocked_until"], 0)

        peek = wallet.walletdbpeek()
        self.check_consistent(peek)
        assert_equal(peek["record_types"]["mkey"], 1)
        assert "walletdescriptorkey" not in peek["record_types"]
        assert_greater_than(peek["record_types"]["walletdescriptorckey"], 0)

    def test_blank_watchonly_wallet(self):
        self.log.info("Test that a blank wallet without private keys has no key records")
        self.nodes[0].createwallet(wallet_name="blank", disable_private_keys=True, blank=True)
        wallet = self.nodes[0].get_wallet_rpc("blank")

        peek = wallet.walletdbpeek()
        self.check_consistent(peek)
        assert "walletdescriptor" not in peek["record_types"]
        assert "walletdescriptorkey" not in peek["record_types"]

    def run_test(self):
        self.test_fresh_wallet()
        self.test_records_track_wallet_changes()
        self.test_encrypted_wallet()
        self.test_blank_watchonly_wallet()


if __name__ == '__main__':
    WalletDbPeekTest(__file__).main()
