#pragma once
#include "args/Argument.hpp"
#include "container/Array.hpp"

namespace cpl::arg
{
    template<cmn::allocator::type::COMMON ALLOCATOR_>
    struct Parser
    {
public:
        Parser(ALLOCATOR_ &_allocator, const u32 _argCount, const c08 **_args);
public:
        const cmn::container::Array<ALLOCATOR_, Argument<ALLOCATOR_>> arguments() const;
private:
        cmn::container::Array<ALLOCATOR_, Argument<ALLOCATOR_>> arguments_;
    };

    template<cmn::allocator::type::COMMON ALLOCATOR_>
    Parser<ALLOCATOR_>::Parser(ALLOCATOR_ &_allocator, const u32 _argCount, const c08 **_args):
        arguments_(_allocator, _argCount / 2)
    {
        for (u32 _i = 0; _i < _argCount - 1; ++_i)
        {
            const c08 *_type = _args[_i];

            if (_type[0] != '-')
            {
                continue;
            }

            const c08 *_value = _args[++_i];
            arguments_.append_copy(Argument<ALLOCATOR_>(_allocator, _type, _value));
        }
    }

    template<cmn::allocator::type::COMMON ALLOCATOR_>
    const cmn::container::Array<ALLOCATOR_, Argument<ALLOCATOR_>> Parser<ALLOCATOR_>::Parser::arguments() const { return arguments_;}
}