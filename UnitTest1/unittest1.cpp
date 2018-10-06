#include "stdafx.h"

#define CATCH_CONFIG_MAIN
#include "include/catch.hpp"

#include "C:/Users/Lenovo/Desktop/Fakulta/ZS_2018-2019/tvorba_softverovych_systemov/concole_app_count_char/counter.h"

TEST_CASE("Popis", "Skrateny nazov") {
	string test = "abc";
	REQUIRE(count_letters(test) == 3);

}