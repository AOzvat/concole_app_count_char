#pragma once

#include <string>

using namespace std;

void count(Word *input) {


}

// funkcia na pocitanie pismen
int count_letters(string input)
{
	int n = 0;

	for (int i = 0; i < input.size(); i++) {
		if (!isspace(input[i])) {
			n++;
		}
	}

	return n;
}

// funkcia na pocitanie slov
int count_words(string input)
{
	int n = 1;

	for (int i = 0; i < input.size(); i++) {
		// ak je viac medzier nak sa rataju ako edna
		if (input[i] == ' ' && input[i + 1] != ' ') {
			n++;
		}
	}

	// ak je "abc efg ", aby bolo n = 2 a ni n = 3
	if (input[input.size() - 1] == ' ') {
		n--;
	}

	return n;
}

// funkcia na pocitanie riadkov
//int count_lines(string input)
//{

	//return n;
//}