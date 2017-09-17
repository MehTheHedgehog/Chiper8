#pragma once

/*	Implementation of std::byte
	Reference: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0298r1.pdf
	Changes made due to standard:
		Super class of byte is changed from unsigned char to unsigned __int8 -
			We want to make sure to have always exacly 8 bit in our byte type.
			Char type is for character storage and must have at least 8 bit length.
*/


#include <type_traits>

namespace std {

	/*template<typename T,
				typename = std::enable_if<std::is_unsigned_v<T>>>*/
	enum class byte : unsigned __int8 {};

	template <class IntegerType
				typename = std::enable_if<std::is_integral_v<IntegerType>>>
	constexpr IntegerType to_integer(byte b) noexcept {
		return IntegerType(b);
	}
	
	template <class IntegerType
				typename = std::enable_if<std::is_integral_v<IntegerType>>>
	constexpr byte& operator<<=(byte& b, IntegerType shift) noexcept {
		return b = byte(static_cast<unsigned char>(b) << shift;
	}

	template <class IntegerType
		typename = std::enable_if<std::is_integral_v<IntegerType>>>
	constexpr byte& operator>>=(byte& b, IntegerType shift) noexcept{
		return b = byte(static_cast<unsigned char>(b) >> shift;
	}

	template <class IntegerType
		typename = std::enable_if<std::is_integral_v<IntegerType>>>
	constexpr byte operator <<(byte b, IntegerType shift) noexcept {
		return byte(static_cast<unsigned char>(b) << shift;
	}
	
	template <class IntegerType
		typename = std::enable_if<std::is_integral_v<IntegerType>>>
	constexpr byte operator >>(byte b, IntegerType shift) noexcept {
		return byte(static_cast<unsigned char>(b) >> shift;
	}

	constexpr byte& operator|=(byte& l, byte r) noexcept {
		return l = byte(static_cast<unsigned char>(l) | static_cast<unsigned char>(r));
	}
	
	constexpr byte& operator&=(byte& l, byte r) noexcept {
		return l = byte(static_cast<unsigned char>(l) & static_cast<unsigned char>(r));
	}
	
	constexpr byte& operator^=(byte& l, byte r) noexcept {
		return l = byte(static_cast<unsigned char>(l) ^ static_cast<unsigned char>(r));
	}

	constexpr byte operator|(byte l, byte r) noexcept {
		return byte(static_cast<unsigned char>(l) | static_cast<unsigned char>(r));
	}

	constexpr byte operator&(byte l, byte r) noexcept {
		return byte(static_cast<unsigned char>(l) & static_cast<unsigned char>(r));
	}

	constexpr byte operator^(byte l, byte r) noexcept {
		return byte(static_cast<unsigned char>(l) ^ static_cast<unsigned char>(r));
	}

	constexpr byte operator~(byte b) noexcept {
		return byte(~static_cast<unsigned char>(b));
	}

}

