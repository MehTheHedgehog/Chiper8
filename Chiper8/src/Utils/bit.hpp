#pragma once

#include "byte.hpp"

namespace meh {
namespace type {

	constexpr std::byte hibyte(const std::byte& dbyte) {
		return ((dbyte & std::byte(0xFF00)) >> 8);
	}

	constexpr std::byte midbyte(const std::byte& dbyte) {
		return ((dbyte & std::byte(0x0FF0)) >> 4);
	}

	constexpr std::byte lobyte(const std::byte& dbyte) {
		return (dbyte & std::byte(0x00FF));
	}

	constexpr std::byte hinibble(const std::byte& dbyte) {
		return ((dbyte & std::byte(0x00F0)) >> 4);
	}

	constexpr std::byte lonibble(const std::byte& dbyte) {
		return (dbyte & std::byte(0x000F));
	}

}
}