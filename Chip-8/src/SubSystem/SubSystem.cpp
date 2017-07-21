#include "SubSystem.hpp"

#include <catch.hpp> //TEST FRAMEWORK

/* Implementation */



/* Unit Tests */

TEST_CASE("Running up Virtual Subsystem", "[SUBSYSTEM]") {
	SubSystem subsystem;
	std::error_code err;
	err.clear();
	
	SECTION("Initialization") {
		REQUIRE(!subsystem.PowerUp());
	}

	SECTION("Setting Random Memory content") {
		err = subsystem.SetMemory(0x0001, 0xFFFF);
		REQUIRE_FALSE(err == std::errc::bad_address);
		err.clear();
	}

	SECTION("Geting Random Memory content"){
		byte ret;
		std::tie(ret, err) = subsystem.GetMemory(0x0001);
		REQUIRE_FALSE(err == std::errc::bad_address);
		REQUIRE(ret == 0xFFFF);

		err.clear();
	}
}

TEST_CASE("", "[SUBSYSTEM]") {

}


