/**
 * @file TypeTraits.hpp
 * @author Krisna Pranav
 * @brief typetraits
 * @version 1.0
 * @date 2024-04-12
 *
 * @copyright Copyright (c) 2024 Krisna Pranav
 *
 */

#pragma once

#ifndef DESK_TYPETRAITS_HPP
#define DESK_TYPETRAITS_HPP

#include <cstddef>
#include <type_traits>

namespace Desk
{

    template <typename T>
    struct AlwaysFalse : std::false_type
    {
    };

    template <typename T>
    struct LazyVoid
    {
        using type = void;
    };

    template <typename T>
    using LazyVoid_t = typename LazyVoid<T>::type;

    template <typename E, typename = void>
    struct EnumValueCount
    {
        static_assert(AlwaysFalse<E>(), "enum has no Count nor Max field");
    };

    template <typename E>
    struct EnumValueCount<E, LazyVoid_t<decltype(E::Count)>>
    {
        static_assert(std::is_enum_v<E>, "Type must be an enumeration");

        static constexpr std::size_t value = static_cast<std::size_t>(E::Count);
    };

}

#endif