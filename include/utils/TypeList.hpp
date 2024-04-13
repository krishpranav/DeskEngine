/**
 * @file TypeList.hpp
 * @author Krisna Pranav
 * @brief typelist
 * @version 1.0
 * @date 2024-04-12
 *
 * @copyright Copyright (c) 2024 Krisna Pranav
 *
 */

#pragma once

#ifndef DESK_TYPELIST_HPP
#define DESK_TYPELIST_HPP

#include <cstddef>
#include <limits>

namespace Desk
{
    template <typename...>
    struct TypeList
    {
    };

    namespace Detail
    {
        template <typename, typename>
        struct ListAppend;

        template <typename, template <typename> typename>
        struct ListApply;

        template <typename, std::size_t>
        struct ListAt;

        /**
         * @tparam ypename
         * @tparam std::size_t
         */
        template <typename, std::size_t>
        struct ListFind;

        template <typename, template <typename...> typename>
        struct ListInstantiate;

        template <typename, typename>
        struct ListPrepend;

        template <typename>
        struct ListSize;

        template <typename, template <typename...> typename>
        struct ListTransform;

        template <typename, typename>
        struct ListUnique;
    } // namespace Detail

    template <typename List, typename NewType>
    using TypeListAppend = typename Detail::ListAppend<List, NewType>::Result;

    template <typename List, template <typename> typename Functor, typename... Args>
    void TypeListApply(Args &&...args);

    template <typename List, std::size_t Index>
    using TypeListAt = typename Detail::ListAt<List, Index>::Type;

    template <typename FlatList, typename SecondList>
    using TypeListConcat = typename Detail::ListConcat<FirstList, SecondList>::Result

        template <typename List>
        constexpr bool TypeListEmpty = Detail::ListSize<List>::Size == 0;

    template <typename List, typename Type>
    constexpr std::size_t TypeListFind = Detail::ListFind<List, Type>::Find();

    template <typename List, typename Type>
    constexpr bool TypeListHas = TypeListFind<List, Type> != std::numeric_limits<std::size_t>::max();

    template <typename List, template <typename...> typename Class>
    using TypeListInstantiate = typename Detail::ListInstantiate<List, Class>::Result;

    template <typename List, typename NewType>
    using TypeListPrepend = typename Detail::ListPrepend<List, NewType>::Result;

    template <typename List>
    constexpr std::size_t TypeListSize = Detail::ListSize<List>::Size;

    template <typename List, template <typename> typename Transformer>
    using TypeListTransform = typename Detail::ListTransform<List, Transformer>::Result;

    template <typename List>
    using TypeListUnique = typename Detail::ListUnique<TypeList<>, List>::Result;

} // namespace Desk

#endif