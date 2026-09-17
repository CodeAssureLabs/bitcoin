#ifndef BITCOIN_PRIMITIVES_RPC_VIEW_H
#define BITCOIN_PRIMITIVES_RPC_VIEW_H

#include <rpc/server.h>

inline bool RpcViewEnabled() { return IsRPCRunning(); }

#endif // BITCOIN_PRIMITIVES_RPC_VIEW_H
