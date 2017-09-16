#ifndef _HPP_SUBSYSTEM_HPP
#define _HPP_SUBSYSTEM_HPP

#include <system_error>
#include <tuple>

#pragma once

typedef unsigned __int8 byte;
typedef byte RegIndex;

class SubSystem 
{
	private:
		//RAM Object
		//GPU Object
		//CPU Object

	public:
		SubSystem() {}; ///< CTOR
		virtual ~SubSystem() {}; ///< VIRTUAL DTOR

		std::error_code Initialize() { return std::error_code(); }; //< Clean up current enviroment
		std::error_code PowerUp() { return std::error_code(); }; //< Start VM to proceed the actual code

		// Debugging Interface
		
		//CPU Code execute interface 
		std::error_code ExecuteCommand(unsigned __int8 b) { return std::make_error_code(std::errc::executable_format_error); }; // TODO

		//Memory Operation
		std::error_code SetMemory(const byte& addr, const byte& value) { return std::make_error_code(std::errc::bad_address); };
		std::tuple<byte, std::error_code> GetMemory(const byte& addr) const { return std::tuple<byte, std::error_code>(0, std::make_error_code(std::errc::bad_address)); };
		
		//Registry Operation
		std::error_code SetRegistry(const RegIndex& reg, const byte& value) { return std::make_error_code(std::errc::bad_address); }; // TODO
		std::tuple<byte, std::error_code> GetRegistry(const RegIndex& reg) const { return std::tuple<byte, std::error_code>(0, std::make_error_code(std::errc::bad_address)); }; //TODO
};


#endif // !_HPP_SUBSYSTEM_HPP

