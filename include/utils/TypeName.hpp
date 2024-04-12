/**
 * @file TypeName.hpp
 * @author Krisna Pranav
 * @brief typename
 * @version 1.0
 * @date 2024-04-12
 *
 * @copyright Copyright (c) 2024 Krisna Pranav
 *
 */

#pragma once

#ifndef DESK_TYPENAME_HPP
#define DESK_TYPENAME_HPP

#include <utils/Prerequisites.hpp>
#include <string_view>

namespace Desk
{
    template <typename T>
    constexpr std::string_view TypeName();
} // namespace Desk

#endif