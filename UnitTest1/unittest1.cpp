#include "stdafx.h"

#define CATCH_CONFIG_MAIN
#include "include/catch.hpp"
#include <string>

#include "../counter.h"

TEST_CASE("Popis", "Skrateny nazov") {
	std::string text = "abc";
	REQUIRE(count_letters(text) == 3);

	text = "abc abc";
	REQUIRE(count_letters(text) == 6);

	text = "";
	REQUIRE(count_letters(text) == 0);

	text = "abc";
	REQUIRE(count_words(text) == 1);

	text = "abc abc";
	REQUIRE(count_words(text) == 2);

	text = "abc";
	REQUIRE(count_lines(text) == 1);

	text = "abc \n abc";
	REQUIRE(count_lines(text) == 2);
}