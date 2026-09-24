// Copyright (c) 2026-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_KERNEL_DEBUG_DUMP_H
#define BITCOIN_KERNEL_DEBUG_DUMP_H

namespace kernel {
//! Write a summary of the kernel state to the debug log (BCLog::KERNEL).
void DumpState();
} // namespace kernel

#endif // BITCOIN_KERNEL_DEBUG_DUMP_H
