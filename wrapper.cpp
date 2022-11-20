#include <iostream>
#include "string_view.h"

int main()
{
        std::string s;
        std::cout << "Write your text" << std::endl;
        std::getline(std::cin, s);
	char* text = new char[s.length() + 1];
   	std::copy(s.begin(), s.end(), text);
        string_view view = { text };
	std::cout << "Text size "<< view.size() << std::endl;
	std::cout << "Which letter in which position you want to change?" << std::endl;
	char c;
	size_t p;
        std::cin >> c >> p;
	text[p] = c;
	std::cout << "New text "<< view << std::endl;
	return 0;

}

