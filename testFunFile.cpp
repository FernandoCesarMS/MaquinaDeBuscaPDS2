#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "FileInput.cpp"

using std::string;

class testeFile {
public:
  
};

TEST_SUITE("FileInput") {
TEST_CASE("words(65 ,91 )"){
	dataManagement data;
	CHECK(data.formatWords(words) == 65);
	CHECK(data.formatWords(words) == 66);
	CHECK(data.formatWords(words) == 67);
	CHECK(data.formatWords(words) == 68);
	CHECK(data.formatWords(words) == 69);
	CHECK(data.formatWords(words) == 70);
	CHECK(data.formatWords(words) == 71);
	CHECK(data.formatWords(words) == 72);
	CHECK(data.formatWords(words) == 73);
	CHECK(data.formatWords(words) == 74);
	CHECK(data.formatWords(words) == 75);
	CHECK(data.formatWords(words) == 76);
	CHECK(data.formatWords(words) == 77);
	CHECK(data.formatWords(words) == 78);
	CHECK(data.formatWords(words) == 79);
	CHECK(data.formatWords(words) == 80);
	CHECK(data.formatWords(words) == 81);
	CHECK(data.formatWords(words) == 82);
	CHECK(data.formatWords(words) == 83);
	CHECK(data.formatWords(words) == 84);
	CHECK(data.formatWords(words) == 85);
	CHECK(data.formatWords(words) == 86);
	CHECK(data.formatWords(words) == 87);
	CHECK(data.formatWords(words) == 88);
	CHECK(data.formatWords(words) == 89);
	CHECK(data.formatWords(words) == 90);
	CHECK(data.formatWords(words) == 91);
}

