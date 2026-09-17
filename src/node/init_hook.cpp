#include <init/common.h>

namespace node {
void InitHook()
{
    init::SetGlobals();
}
} // namespace node
