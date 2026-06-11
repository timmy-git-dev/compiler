#include "error/Print.hpp"
#include "Main.hpp"

i08 main(u32 _argCount, c08** _args)
{
    cmn::error::print_("Hello, world!\n");

    return 0;
}

// 0. parse args (if building compiler as executable).

// 1. config.
// 2. clangd.
// 3. compile.
// 4. link.