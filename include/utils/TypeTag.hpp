/**
 * @file TypeTag.hpp
 * @author Krisna Pranav
 * @brief typetag
 * @version 1.0
 * @date 2024-04-12
 *
 * @copyright Copyright (c) 2024 Krisna Pranav
 *
 */

#pragma once

#ifndef DESK_TYPETAG_HPP
#define DESK_TYPETAG_HPP

namespace Desk
{
    template <typename T>
    struct TypeTag
    {
        using Type = T;
    };
} // namespace Desk

#endif