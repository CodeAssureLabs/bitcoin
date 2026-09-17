#include <rpc/server.h>
#include <rpc/util.h>

static RPCHelpMan ping2()
{
    return RPCHelpMan{"ping2",
        "Ping (v2).",
        {},
        RPCResult{RPCResult::Type::STR, "", "pong2"},
        RPCExamples{HelpExampleCli("ping2", "")},
        [&](const RPCHelpMan& self, const JSONRPCRequest& request) -> UniValue
        {
            return "pong2";
        },
    };
}

void RegisterPing2RPCCommands(CRPCTable& t)
{
    static const CRPCCommand commands[]{{"control", &ping2}};
    for (const auto& c : commands) {
        t.appendCommand(c.name, &c);
    }
}
