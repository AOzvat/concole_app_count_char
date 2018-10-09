#include "stdafx.h"

#define CATCH_CONFIG_MAIN
#include "include/catch.hpp"
#include <string>

#include "../counter.h"

TEST_CASE("Popis", "Skrateny nazov") {
	std::string text = "abc";
	REQUIRE(count <_letter>(text) == 3);

	text = "abc abc";
	REQUIRE(count <_letter>(text) == 6);

	text = "";
	REQUIRE(count <_letter>(text) == 0);

	text = "abc";
	REQUIRE(count <_word>(text) == 1);

	text = "abc  abc";
	REQUIRE(count <_word>(text) == 2);

	text = "abc";
	REQUIRE(count <_line>(text) == 1);

	text = "abc \n abc";
	REQUIRE(count <_line>(text) == 2);
}