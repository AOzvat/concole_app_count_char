// app.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include "counter.h"

using namespace std;

typedef struct Word {
	string text;
	int letters;
	int words;
	int lines;
};

int main(int argc, char **argv)
{
	Word input;

	// v pripade ak nie je vneseny prepinac alebo je viac vstupnych parametrov
	if (argc == 1 || argc > 3) {
		cout << "Nebol vneseny prepinac alebo bolo vnesene viac vstupnych parametrov. " << endl;

		return 0;
	}

	// ak je prepinac -c vypocita sa pocet pismen
	if (string(argv[1]) == "-c") {
		// ak je vneseny vstupny subor
		if (argc == 3) {
			ifstream in_file(argv[2]);

			istream_iterator<char> in{ in_file }, end;

			cout << "Pocet pismen v subore " + string(argv[2]) + " je: " << distance(in, end) << endl;
		}
		// ak nie je vneseny vstupny subor
		else {
			cout << "Vneste text: " << endl;

			getline(cin, input.text);
			count(&input);

			cout << "Pocet pismen v texte je: " << input.letters << endl;
		}
		return 0;
	}

	// ak je prepinac -w vypocita sa pocet slov
	if (string(argv[1]) == "-w") {
		// ak je vneseny vstupny subor
		if (argc == 3) {
			ifstream in_file(argv[2]);

			istream_iterator<string> in{ in_file }, end;

			cout << "Pocet slov v subore " + string(argv[2]) + " je: " << distance(in, end) << endl;
		}
		// ak nie je vneseny vstupny subor
		else {
			cout << "Vneste text: " << endl;

			getline(cin, input);

			cout << "Pocet slov v texte je: " << count_words(input) << endl;
		}

		return 0;
	}

	// ak je prepinac -l vypocita sa pocet riadkov
	if (string(argv[1]) == "-l") {
		// ak je vneseny vstupny subor
		if (argc == 3) {
			ifstream in_file(argv[2]);
			int n = count(istreambuf_iterator<char>(in_file), istreambuf_iterator<char>(), '\n');


			cout << "Pocet riadkov v subore " + string(argv[2]) + " je: " << n + 1 << endl;
		}
		// ak nie je vneseny vstupny subor
		else {
			cout << "Vneste text (vstup ukoncite stlacenim ` + Enter): " << endl;
			
			char ch;
			int n = 1;

			// v ASCII 96 = ` a 10 = newline
			while ((ch = cin.get()) != 96) {
				if (ch == 10) {
					n++;
				}
			}
			cout << "Pocet riadkov v texte je: " << n << endl;
		};
	}
	// ak je vneseny nespravny prepinac
	else {
		cout << "Bol vneseny nespravny prepinac. " << endl;
	}

	return 0;
}
