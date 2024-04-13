/**
 * @file CallOnExit.hpp
 * @author Krisna Pranav
 * @brief CallOnExit
 * @version 1.0
 * @date 2024-04-13
 *
 * @copyright Copyright (c) 2024 Krisna Pranav
 *
 */

#pragma once

#ifndef DESK_CALLONEXIT_HPP
#define DESK_CALLONEXIT_HPP

#include <utils/Prerequisites.hpp>
#include <optional>

#define DESK_DEFER(expr) Desk::CallOnExit DeskSuffixMacro(defer_, __LINE__)([&] { expr })

namespace Desk
{

} // namespace Desk

#endif