#include <rpc/server.h>
#include <rpc/util.h>

static RPCHelpMan ping3()
{
    return RPCHelpMan{"ping3",
        "Ping (v3).",
        {},
        RPCResult{RPCResult::Type::STR, "", "pong3"},
        RPCExamples{HelpExampleCli("ping3", "")},
        [&](const RPCHelpMan& self, const JSONRPCRequest& request) -> UniValue
        {
            return "pong3";
        },
    };
}

void RegisterPing3RPCCommands(CRPCTable& t)
{
    static const CRPCCommand commands[]{{"control", &ping3}};
    for (const auto& c : commands) {
        t.appendCommand(c.name, &c);
    }
}
