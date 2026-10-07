// Copyright (c) 2026-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_UTIL_GTPROBE_PONG_H
#define BITCOIN_UTIL_GTPROBE_PONG_H

#include <cstdint>

namespace util {
//! Counts down `depth` by alternating with GtProbePing(); declared before the
//! mutual include so that GtProbePing() can refer to it.
inline uint32_t GtProbePong(uint32_t depth) noexcept;
} // namespace util

#include <util/gtprobe_ping.h>

namespace util {
inline uint32_t GtProbePong(uint32_t depth) noexcept
{
    if (depth == 0) return 0;
    return 1 + GtProbePing(depth - 1);
}
} // namespace util

#endif // BITCOIN_UTIL_GTPROBE_PONG_H
