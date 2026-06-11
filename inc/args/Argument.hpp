#pragma once
#include "container/String.hpp"

namespace cpl::arg
{
    template<cmn::allocator::type::COMMON ALLOCATOR_>
    struct Argument
    {
public:
        Argument(ALLOCATOR_ &_allocator, const char *_type, const char *_value);
public:
        const cmn::container::String<ALLOCATOR_> type () const;
        const cmn::container::String<ALLOCATOR_> value() const;
private:
        cmn::container::String<ALLOCATOR_> type_;
        cmn::container::String<ALLOCATOR_> value_;
    };

    template<cmn::allocator::type::COMMON ALLOCATOR_>
    Argument<ALLOCATOR_>::Argument(ALLOCATOR_ &_allocator, const char *_type, const char *_value):
        type_ (_allocator, _type ),
        value_(_allocator, _value)
    { }

    template<cmn::allocator::type::COMMON ALLOCATOR_> const cmn::container::String<ALLOCATOR_>
    Argument<ALLOCATOR_>::type () const {return type_; }
    template<cmn::allocator::type::COMMON ALLOCATOR_> const cmn::container::String<ALLOCATOR_>
    Argument<ALLOCATOR_>::value() const {return value_;}
}