// app.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string txt;

	cout << "Vneste text: " << endl;

	getline(cin, txt);
	cout << "Bol vneseny text:  " << txt << endl;

	return 0;
}
