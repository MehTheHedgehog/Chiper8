#pragma once

#include <cstddef>
#include <fstream>
#include <tuple>

#include "Utils/byte.hpp"

using string = std::string;
using byte = std::byte;

namespace meh {
namespace utils {

	class binaryFile  {
		private:
			const string filePath;
			std::ifstream fileStream;

		public:

			binaryFile(const string& _filePath)
				: filePath(_filePath),
				fileStream(filePath, std::ios::in | std::ios::binary)
			{}

			std::tuple<std::vector<byte>, std::size_t> read(const std::size_t& size) {
				std::vector<byte> outputByteArray;
				std::size_t outputSize;
				
				for (; fileStream.eof != true || outputSize <= size; outputSize++) {
					const char c = fileStream.get();
					outputByteArray.emplace_back(std::byte(c));
				}

				return std::make_tuple(outputByteArray, outputSize);
			}


	};

}
}
