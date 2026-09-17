#include <rpc/server.h>
#include <rpc/util.h>
#include <wallet/db.h>
#include <wallet/sqlite.h>

static RPCHelpMan walletdbpeek()
{
    return RPCHelpMan{"walletdbpeek", "Peek at the wallet db.", {}, RPCResult{RPCResult::Type::STR, "", ""}, RPCExamples{""},
        [&](const RPCHelpMan& self, const JSONRPCRequest& request) -> UniValue { return ""; }};
}
