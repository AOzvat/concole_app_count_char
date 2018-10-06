#include "Word.h"



Word::Word()
{
}


Word::~Word()
{
}

Word Word::counter(Word word) {
	// pocitanie slov
	int n = 0;

	for (int i = 0; i < word.text.size(); i++) {
		if (!isspace(word.text[i])) {
			n++;
		}
	}
	word.letters = n;

	// pocitanie slov
	n = 1;

	for (int i = 0; i < word.text.size(); i++) {
		// ak je viac medzier nak sa rataju ako edna
		if (word.text[i] == ' ' && word.text[i + 1] != ' ') {
			n++;
		}
	}

	// ak je "abc efg ", aby bolo n = 2 a ni n = 3
	if (word.text[word.text.size() - 1] == ' ') {
		n--;
	}
	word.words = n;

	// pocitanie riadkov
	n = 1;
	for (int i = 0; i < word.text.size(); i++) {
		if (word.text[i] == 10) {
			n++;
		}
	}
	word.lines = n;

	return word;
}
