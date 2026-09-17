// Copyright (c) 2026-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_NODE_INIT_HOOK_H
#define BITCOIN_NODE_INIT_HOOK_H

namespace node {
struct NodeContext;

//! Run the init-time hook registered on the node context.
//!
//! The node layer must not depend on init/, bitcoind or GUI code
//! (doc/design/libraries.md), so the actual work is supplied by the entry
//! layer through NodeContext::init_hook. If no hook was registered this is a
//! no-op.
void InitHook(NodeContext& node);
} // namespace node

#endif // BITCOIN_NODE_INIT_HOOK_H
