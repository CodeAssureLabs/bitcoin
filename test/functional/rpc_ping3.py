#!/usr/bin/env python3
# Copyright (c) 2026 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.
"""Test the ping3 RPC."""

from test_framework.test_framework import BitcoinTestFramework
from test_framework.util import assert_equal


class Ping3Test(BitcoinTestFramework):
    def set_test_params(self):
        self.num_nodes = 1

    def run_test(self):
        assert_equal(self.nodes[0].ping3(), "pong3")


if __name__ == "__main__":
    Ping3Test(__file__).main()
