#pragma once

#include <string>

using namespace std;

typedef struct _letter : public string {
	// funkcie
	_letter(string input) : string (input) {
	}

	int count() {
		int n = 0;

		for (int i = 0; i < size(); i++) {
			if (!isspace(at(i))) {
				n++;
			}
		}

		return n;
	}
};

typedef struct _word : public string {
	// funkcie
	_word(string input) : string (input) {
	}

	int count() {
		int n = 1;

		for (int i = 0; i < size(); i++) {
			// ak je viac medzier nak sa rataju ako edna
			if (at(i) == ' ' && at(i + 1) != ' ') {
				n++;
			}
		}

		// ak je "abc efg ", aby bolo n = 2 a ni n = 3
		if (at(size() - 1) == ' ') {
			n--;
		}

		return n;
	}
};

typedef struct _line : public string {
	// funkcie
	_line(string input) : string (input) {
	}

	int count() {
		int n = 1;
		for (int i = 0; i < size(); i++) {
			if (at(i) == 10) {
				n++;
			}
		}

		return n;
	}
};

template <typename T>
size_t count(string input) {
	T result(input);
	return result.count();
}