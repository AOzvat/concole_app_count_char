#pragma once
#include <string>

class Word
{
private:
	std::string text;
	int letters;
	int words;
	int lines;
public:
	Word();
	~Word();
	Word(std::string input) { text = input; };
	Word counter(Word);
	int ret_letters() { return letters; };
	int ret_words() { return words; };
	int ret_lines() { return lines; };
};

