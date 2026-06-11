#include "allocator/Arena.hpp"
#include "args/Parser.hpp"
#include "error/Print.hpp"
#include "Main.hpp"

i08 main(const u32 _argCount, const c08 **_args)
{
    cmn::allocator::Arena _allocator = cmn::allocator::Arena(4096);
    cpl::arg::Parser<cmn::allocator::Arena> _parser = cpl::arg::Parser<cmn::allocator::Arena>(_allocator, _argCount, _args);
    for (const cpl::arg::Argument<cmn::allocator::Arena> &_arg : _parser.arguments())
    {
        cmn::error::print_("[");
        cmn::error::print_(_arg.type().data());
        cmn::error::print_(":");
        cmn::error::print_(_arg.value().data());
        cmn::error::print_("]\n");
    }

    return 0;
}

// 0. parse args (if building compiler as executable).

// 1. config.
// 2. clangd.
// 3. compile.
// 4. link.