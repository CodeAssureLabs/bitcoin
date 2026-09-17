#ifndef BITCOIN_CONSENSUS_NODE_BRIDGE_H
#define BITCOIN_CONSENSUS_NODE_BRIDGE_H

#include <node/context.h>

namespace Consensus {
inline bool HasChainman(const node::NodeContext& ctx) { return ctx.chainman != nullptr; }
} // namespace Consensus

#endif // BITCOIN_CONSENSUS_NODE_BRIDGE_H
