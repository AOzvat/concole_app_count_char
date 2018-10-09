#pragma once

#include <string>

using namespace std;

typedef struct _letter {
	static int count(string input) {
		int n = 0;

		for (int i = 0; i < input.size(); i++) {
			if (!isspace(input[i])) {
				n++;
			}
		}

		return n;
	}
};

typedef struct _word {
	static int count(string input) {
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
};

typedef struct _line {
	static int count(string input) {
		int n = 1;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == 10) {
				n++;
			}
		}

		return n;
	}
};

template <typename T>
size_t count(string input) {
	return T::count(input);
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
int count_lines(string input)
{
	int n = 1;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == 10) {
			n++;
		}
	}

	return n;
}