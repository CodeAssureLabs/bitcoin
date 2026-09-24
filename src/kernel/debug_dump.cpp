#include <logging.h>

namespace kernel {
void DumpState()
{
    LogDebug(BCLog::KERNEL, "kernel state\n");
}
} // namespace kernel
