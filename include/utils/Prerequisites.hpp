/**
 * @file Prerequisites.hpp
 * @author Krisna Pranav
 * @brief pre requiesties
 * @version 1.0
 * @date 2024-04-12
 *
 * @copyright Copyright (c) 2024 Krisna Pranav
 *
 */

#ifndef DESK_PREREQUISITES_HPP
#define DESK_PREREQUISITES_HPP

#if defined(__clang__)
#define DESK_COMPILER_CLANG
#define DESK_COMPILER_CLANG_VER (__clang_major__ * 100 + __clang_minor__)
#define DESK_DEPRECATED(txt) __attribute__((__deprecated__(txt)))
#define DESK_PRETTY_FUNCTION __PRETTY_FUNCTION__

#define DESK_CHECK_CLANG_VER(ver) (DESK_COMPILER_CLANG_VER >= ver)

#define DESK_PRAGMA(x) _Pragma(#x)

#define DESK_WARNING_CLANG_DISABLE(warn) DESK_PRAGMA(clang diagnostic ignored warn)
#define DESK_WARNING_CLANG_GCC_DISABLE(warn) DESK_PRAGMA(clang diagnostic ignored warn)
#define DESK_WARNING_POP() DESK_PRAGMA(clang diagnostic pop)
#define DESK_WARNING_PUSH() DESK_PRAGMA(clang diagnostic push)

#ifdef __MINGW32__
#define DESK_COMPILER_MINGW
#ifdef __MINGW64_VERSION_MAJOR
#define DESK_COMPILER_MINGW_W64
#endif
#endif
#elif defined(__GNUC__) || defined(__MINGW32__)
#define DESK_COMPILER_GCC
#define DESK_COMPILER_GCC_VER (__GNUC__ * 100 + __GNUC_MINOR__)
#define DESK_DEPRECATED(txt) __attribute__((__deprecated__(txt)))
#define DESK_PRETTY_FUNCTION __PRETTY_FUNCTION__

#define DESK_CHECK_GCC_VER(ver) (DESK_COMPILER_GCC_VER >= ver)

#define DESK_PRAGMA(x) _Pragma(#x)

#define DESK_WARNING_CLANG_GCC_DISABLE(warn) DESK_PRAGMA(GCC diagnostic ignored warn)
#define DESK_WARNING_GCC_DISABLE(warn) DESK_PRAGMA(GCC diagnostic ignored warn)
#define DESK_WARNING_POP() DESK_PRAGMA(GCC diagnostic pop)
#define DESK_WARNING_PUSH() DESK_PRAGMA(GCC diagnostic push)

#ifdef __MINGW32__
#define DESK_COMPILER_MINGW
#ifdef __MINGW64_VERSION_MAJOR
#define DESK_COMPILER_MINGW_W64
#endif
#endif
#elif defined(__INTEL_COMPILER) || defined(__ICL)
#define DESK_COMPILER_ICC
#define DESK_COMPILER_ICC_VER __INTEL_COMPILER
#define DESK_DEPRECATED(txt) [[deprecated(txt)]]
#define DESK_PRETTY_FUNCTION __FUNCTION__

#define DESK_CHECK_ICC_VER(ver) (DESK_COMPILER_ICC_VER >= ver)

#define DESK_PRAGMA(x) _Pragma(x)

#define DESK_WARNING_ICC_DISABLE(...) DESK_PRAGMA(warning(disable : __VA_ARGS__))
#define DESK_WARNING_POP() DESK_PRAGMA(warning(pop))
#define DESK_WARNING_PUSH() DESK_PRAGMA(warning(push))
#elif defined(_MSC_VER)
#define DESK_COMPILER_MSVC
#define DESK_COMPILER_MSVC_VER _MSC_VER
#define DESK_DEPRECATED(txt) __declspec(deprecated(txt))
#define DESK_PRETTY_FUNCTION __FUNCSIG__

#define DESK_CHECK_MSVC_VER(ver) (DESK_COMPILER_MSVC_VER >= ver)

#define DESK_PRAGMA(x) __pragma(x)

#define DESK_WARNING_MSVC_DISABLE(...) DESK_PRAGMA(warning(disable : __VA_ARGS__))
#define DESK_WARNING_POP() DESK_PRAGMA(warning(pop))
#define DESK_WARNING_PUSH() DESK_PRAGMA(warning(push))

#define DESK_CPP_VER _MSVC_LANG
#else
#define DESK_COMPILER_UNKNOWN
#define DESK_DEPRECATED(txt)
#define DESK_PRETTY_FUNCTION __func__

#pragma message This compiler is not fully supported
#endif

#ifdef DESK_COMPILER_MINGW
#if defined(__USING_MCFGTHREAD__)
#define DESK_COMPILER_MINGW_THREADS_MCF
#elif defined(_REENTRANT)
#define DESK_COMPILER_MINGW_THREADS_POSIX
#else
#define DESK_COMPILER_MINGW_THREADS_WIN32
#endif
#endif

#ifndef DESK_CHECK_CLANG_VER
#define DESK_CHECK_CLANG_VER(ver) 0
#endif

#ifndef DESK_CHECK_ICC_VER
#define DESK_CHECK_ICC_VER(ver) 0
#endif

#ifndef DESK_CHECK_GCC_VER
#define DESK_CHECK_GCC_VER(ver) 0
#endif

#ifndef DESK_CHECK_MSVC_VER
#define DESK_CHECK_MSVC_VER(ver) 0
#endif

#ifndef DESK_CPP_VER
#define DESK_CPP_VER __cplusplus
#endif

#ifndef DESK_PRAGMA
#define DESK_PRAGMA(x) _Pragma(#x)
#endif

#ifndef DESK_WARNING_CLANG_DISABLE
#define DESK_WARNING_CLANG_DISABLE(warn)
#endif

#ifndef DESK_WARNING_CLANG_GCC_DISABLE
#define DESK_WARNING_CLANG_GCC_DISABLE(warn)
#endif

#ifndef DESK_WARNING_GCC_DISABLE
#define DESK_WARNING_GCC_DISABLE(warn)
#endif

#ifndef DESK_WARNING_ICC_DISABLE
#define DESK_WARNING_ICC_DISABLE(warn)
#endif

#ifndef DESK_WARNING_MSVC_DISABLE
#define DESK_WARNING_MSVC_DISABLE(...)
#endif

#ifndef DESK_WARNING_POP
#define DESK_WARNING_POP()
#endif

#ifndef DESK_WARNING_PUSH
#define DESK_WARNING_PUSH()
#endif

#define DESK_CPP98 199711L
#define DESK_CPP11 201103L
#define DESK_CPP14 201402L
#define DESK_CPP17 201703L
#define DESK_CPP20 202002L
#define DESK_CPP23 202302L

#define DESK_CHECK_CPP_VER(ver) (DESK_CPP_VER >= ver)

#if !DESK_CHECK_CPP_VER(DESK_CPP17)
#error DESK requires C++17 or higher
#endif

#if defined(_WIN32)
#define DESK_PLATFORM_DESKTOP
#define DESK_PLATFORM_WINDOWS

#define DESK_EXPORT __declspec(dllexport)
#define DESK_IMPORT __declspec(dllimport)

#if defined(DESK_BUILD)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef NOMINMAX
#define NOMINMAX
#endif

#if DESKUTILS_WINDOWS_NT6
#define DESK_WINNT 0x0600
#else
#define DESK_WINNT 0x0501
#endif

#if defined(_WIN32_WINNT)
#if _WIN32_WINNT < DESK_WINNT
#undef _WIN32_WINNT
#define _WIN32_WINNT DESK_WINNT
#endif
#else
#define _WIN32_WINNT DESK_WINNT
#endif
#endif

#elif defined(__ANDROID__)

#if !__has_include(<android/ndk-version.h>)
#error DESK requires a more recent Android NDK version, please update
#endif
#include <android/ndk-version.h>
#define DESK_PLATFORM_MOBILE
#define DESK_PLATFORM_ANDROID
#define DESK_PLATFORM_POSIX

#define DESK_PLATFORM_ANDROID_NDK_VER __NDK_MAJOR__
#define DESK_CHECK_NDK_VER(ver) (DESK_PLATFORM_ANDROID_NDK_VER >= ver)

#define DESK_EXPORT __attribute__((visibility("default")))
#define DESK_IMPORT __attribute__((visibility("default")))
#elif defined(__linux__)
#define DESK_PLATFORM_DESKTOP
#define DESK_PLATFORM_LINUX
#define DESK_PLATFORM_POSIX

#define DESK_EXPORT __attribute__((visibility("default")))
#define DESK_IMPORT __attribute__((visibility("default")))

#elif defined(__FreeBSD__)
#define DESK_PLATFORM_BSD
#define DESK_PLATFORM_FREEBSD
#define DESK_PLATFORM_POSIX

#define DESK_EXPORT __attribute__((visibility("default")))
#define DESK_IMPORT __attribute__((visibility("default")))

#elif defined(__APPLE__)
#include <TargetConditionals.h>
#if TARGET_OS_IPHONE
#define DESK_PLATFORM_MOBILE
#define DESK_PLATFORM_IOS
#else
#define DESK_PLATFORM_DESKTOP
#define DESK_PLATFORM_MACOS
#endif
#define DESK_PLATFORM_BSD
#define DESK_PLATFORM_POSIX

#define DESK_EXPORT __attribute__((visibility("default")))
#define DESK_IMPORT __attribute__((visibility("default")))

#elif defined(__EMSCRIPTEN__)
#define DESK_PLATFORM_WEB
#define DESK_PLATFORM_POSIX

#define DESK_EXPORT __attribute__((visibility("default")))
#define DESK_IMPORT __attribute__((visibility("default")))
#else
#pragma message "This operating system is not fully supported by the DESK Engine"

#define DESK_PLATFORM_UNKNOWN
#define DESK_EXPORT
#define DESK_IMPORT
#endif

#ifndef DESK_CHECK_NDK_VER
#define DESK_CHECK_NDK_VER(ver) 0
#endif

#ifdef __has_cpp_attribute
#define DESK_HAS_CPP_ATTRIBUTE(attr) __has_cpp_attribute(attr)
#else
#define DESK_HAS_CPP_ATTRIBUTE(attr) (0)
#endif

#ifndef DESK_NO_ASSUME_ATTRIBUTE

#if DESK_CHECK_CPP_VER(DESK_CPP23) || DESK_HAS_CPP_ATTRIBUTE(assume)
#define DESK_ASSUME(expr) [[assume(expr)]]
#endif

#ifndef DESK_ASSUME

#if defined(DESK_COMPILER_CLANG)
#define DESK_ASSUME(expr) __builtin_assume(expr)
#endif

#if defined(DESK_COMPILER_GCC)

#if __GNUC__ >= 13
#define DESK_ASSUME(expr) __attribute__(assume(expr))
#endif

#endif

#if defined(DESK_COMPILER_MSVC)
#define DESK_ASSUME(expr) __assume(expr)
#endif

#endif

#endif

#ifndef DESK_NO_FORCEINLINE_ATTRIBUTE

#ifndef DESK_FORCEINLINE

#if defined(DESK_COMPILER_CLANG) || defined(DESK_COMPILER_GCC)
#define DESK_FORCEINLINE __attribute__((always_inline)) inline
#endif

#if defined(DESK_COMPILER_MSVC)
#define DESK_FORCEINLINE __forceinline
#endif

#endif

#endif

#ifndef DESK_NO_LIKELY_ATTRIBUTE

#if DESK_CHECK_CPP_VER(DESK_CPP20) || DESK_HAS_CPP_ATTRIBUTE(likely)
#define DESK_LIKELY(expr) (expr) [[likely]]
#endif

#if DESK_CHECK_CPP_VER(DESK_CPP20) || DESK_HAS_CPP_ATTRIBUTE(unlikely)
#define DESK_UNLIKELY(expr) (expr) [[unlikely]]
#endif

#if defined(DESK_COMPILER_CLANG) || defined(DESK_COMPILER_GCC) || defined(DESK_COMPILER_INTEL)

#ifndef DESK_LIKELY
#define DESK_LIKELY(expr) (__builtin_expect(!!(expr), 1))
#endif

#ifndef DESK_UNLIKELY
#define DESK_UNLIKELY(expr) (__builtin_expect(!!(expr), 0))
#endif

#endif

#endif

#ifndef DESK_NO_UNREACHABLE_MACRO

#if defined(DESK_COMPILER_CLANG) || defined(DESK_COMPILER_GCC) || defined(DESK_COMPILER_INTEL)
#define DESK_UNREACHABLE() __builtin_unreachable()
#elif defined(DESK_COMPILER_MSVC)
#define DESK_UNREACHABLE() __assume(false)
#endif

#endif

#ifndef DESK_ASSUME
#define DESK_ASSUME(expr)
#endif

#ifndef DESK_FORCEINLINE
#define DESK_FORCEINLINE inline
#endif

#ifndef DESK_LIKELY
#define DESK_LIKELY(expr) (expr)
#endif

#ifndef DESK_UNLIKELY
#define DESK_UNLIKELY(expr) (expr)
#endif

#ifndef DESK_UNREACHABLE
#define DESK_UNREACHABLE() throw Nz::UnreachableError{};
#endif

#ifndef DESK_NO_ARCH_DETECTION

#if defined(__arm__) || defined(__thumb__) || defined(__ARM_ARCH_7__) || defined(_M_ARM)
#define DESK_ARCH_arm
#endif

#if defined(__aarch64__) || defined(_M_ARM64) || defined(_M_ARM64EC)
#define DESK_ARCH_aarch64
#endif

#if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_AMD64) || defined(_M_X64)
#define DESK_ARCH_x86_64
#endif

#if defined(__i386__) || defined(_M_IX86) || defined(_X86_)
#define DESK_ARCH_x86
#endif

#if defined(__wasm32__)
#define DESK_ARCH_wasm32
#endif

#if defined(__wasm64__)
#define DESK_ARCH_wasm64
#endif

#if defined(DESK_ARCH_arm) + defined(DESK_ARCH_aarch64) + defined(DESK_ARCH_x86_64) + defined(DESK_ARCH_x86) + defined(DESK_ARCH_wasm32) + defined(DESK_ARCH_wasm64) != 1

#error No or multiple arch detected! Please open an issue with details about your target system. You can define DESK_NO_ARCH_DETECTION to bypass this error.

#endif

#endif

#ifdef DESK_UNITY_ID
#define DESK_ANONYMOUS_NAMESPACE DESK_UNITY_ID
#define DESK_USE_ANONYMOUS_NAMESPACE using namespace DESK_UNITY_ID;
#define DESK_ANONYMOUS_NAMESPACE_PREFIX(a) DESK_UNITY_ID::a
#else
#define DESK_ANONYMOUS_NAMESPACE
#define DESK_USE_ANONYMOUS_NAMESPACE
#define DESK_ANONYMOUS_NAMESPACE_PREFIX(a) a
#endif

#define DESKPrefix(a, prefix) prefix##a
#define DESKPrefixMacro(a, prefix) DESKPrefix(a, prefix)
#define DESKSuffix(a, suffix) a##suffix
#define DESKSuffixMacro(a, suffix) DESKSuffix(a, suffix)
#define DESKStringify(s) #s
#define DESKStringifyMacro(s) DESKStringify(s)
#define DESKUnused(a) (void)a

#include <climits>
#include <cstdint>

static_assert(CHAR_BIT == 8, "CHAR_BIT is expected to be 8");

static_assert(sizeof(int8_t) == 1, "int8_t is not of the correct size");
static_assert(sizeof(int16_t) == 2, "int16_t is not of the correct size");
static_assert(sizeof(int32_t) == 4, "int32_t is not of the correct size");
static_assert(sizeof(int64_t) == 8, "int64_t is not of the correct size");

static_assert(sizeof(uint8_t) == 1, "uint8_t is not of the correct size");
static_assert(sizeof(uint16_t) == 2, "uint16_t is not of the correct size");
static_assert(sizeof(uint32_t) == 4, "uint32_t is not of the correct size");
static_assert(sizeof(uint64_t) == 8, "uint64_t is not of the correct size");

namespace Desk
{
    using Int8 = int8_t;
    using UInt8 = uint8_t;

    using Int16 = int16_t;
    using UInt16 = uint16_t;

    using Int32 = int32_t;
    using UInt32 = uint32_t;

    using Int64 = int64_t;
    using UInt64 = uint64_t;

    struct UnreachableError
    {
    };
}

#endif