// Copyright (c) 2026-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <node/init_hook.h>

#include <node/context.h>

namespace node {
void InitHook(NodeContext& node)
{
    if (node.init_hook) node.init_hook();
}
} // namespace node
