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

    template <typename E>
    struct EnumValueCount<E, LazyVoid_t<decltype(E::Max)>>
    {
        static_assert(std::is_enum_v<E>, "Type must be an enumeration");

        static constexpr std::size_t value = static_cast<std::size_t>(E::Max) + 1;
    };

    template <typename E>
    constexpr std::size_t EnumValueCount_v = EnumValueCount<E>::value;

    namespace Detail
    {
        template <typename T>
        struct FunctionPtrType;

        template <typename Ret, typename... Args>
        struct FunctionPtrType<Ret(Args...)>
        {
            using type = Ret (*)(Args...);
        };
    } // namespace Detail

    template <typename T>
    using FunctionPtr = typename Detail::FunctionPtrType<T>::type;

    namespace Detail
    {
        template <typename T>
        struct IsCompleteHelper
        {
            template <typename U>
            static auto test(U *) -> std::bool_constant<sizeof(U) == sizeof(U)>;

            static auto test(...) -> std::false_type;

            using type = decltype(test(static_cast<T *>(nullptr)));
        };
    } // namespace Detail

    template <typename T>
    struct IsComplete : Detail::IsCompleteHelper<T>::type
    {
    };

    template <typename T>
    constexpr bool IsComplete_v = IsComplete<T>::value
} // namespace Desk

#endif