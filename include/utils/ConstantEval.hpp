/**
 * @file ConstantEval.hpp
 * @author Krisna Pranav
 * @brief Constant Eval
 * @version 1.0
 * @date 2024-04-13
 *
 * @copyright Copyright (c) 2024 Krisna Pranav
 *
 */

#pragma once

#ifndef DESKUTILS_CONSTANTEVALUATED_HPP
#define DESKUTILS_CONSTANTEVALUATED_HPP

#include <utils/Prerequisites.hpp>
#include <type_traits>

#if DESK_CHECK_CPP_VER(DESK_CPP23)
#define DESK_HAS_CONSTEVAL
#define DESK_CONSTEXPR20 constexpr
#define DESK_IS_CONSTEVAL() consteval
#define DESK_IS_NOT_CONSTEVAL() !consteval
#elif DESK_CHECK_CPP_VER(DESK_CPP20)
#define DESK_HAS_CONSTEVAL
#define DESK_CONSTEXPR20 constexpr
#define DESK_IS_CONSTEVAL() (std::is_constant_evaluated())
#define DESK_IS_RUNTIME_EVAL() (!std::is_constant_evaluated())
#elif DESK_CHECK_MSVC_VER(1925) || DESK_CHECK_CLANG_VER(900) || DESK_CHECK_GCC_VER(900)

#define DESK_HAS_CONSTEVAL
#define DESK_CONSTEXPR20 constexpr
#define DESK_IS_CONSTEVAL() (__builtin_is_constant_evaluated())
#define DESK_IS_RUNTIME_EVAL() (!__builtin_is_constant_evaluated())
#else
#define DESK_CONSTEXPR20
#define DESK_IS_CONSTEVAL() (false)
#define DESK_IS_RUNTIME_EVAL() (true)
#endif

#endif