#include <logging.h>

namespace kernel {
void DumpState()
{
    LogDebug(BCLog::KERNEL, "kernel state");
}
} // namespace kernel
