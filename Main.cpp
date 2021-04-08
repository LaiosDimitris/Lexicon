#include "Lexicon/Lexicon.hpp"
#include <cctype>

bool is_number(const std::string &str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i])) {
			return false;
		}
	}

	return true;
}

bool print()
{
	std::string choice;

	std::cout << "Do you want to print the results? (Y/n): ";
	std::cin >> choice;

	if (choice == "y" || choice == "Y") {
		return true;
	}
	else {
		return false;
	}
}

void menu(Lexicon lexicon)
{
	while (true)
	{
		std::cout << "====================="                                                << std::endl;
		std::cout << "1.Get count of words with given length"                               << std::endl;
		std::cout << "2.Get count of words that start with given string"                    << std::endl;
		std::cout << "3.Get count of words that end with given string"                      << std::endl;
		std::cout << "4.Get count of words that contain a string a given amount of times"   << std::endl;
		std::cout << "5.Get count of words that contain a characters in specific positions" << std::endl;
		std::cout << "6.Exit\n"                                                             << std::endl;

		std::string choice;

		std::cout << "Enter your choice: ";
		std::cin >> choice;
		
		if (choice == "1")
		{
			std::string length_str;

			std::cout << "Enter word length: ";
			std::cin >> length_str;
			
			if (!is_number(length_str)) {
				std::cout << "You did not enter a valid number!" << std::endl;
				continue;
			}

			int word_count = lexicon.length(std::stoi(length_str), print());

			std::cout << word_count << " Words" << std::endl;
		}

		else if (choice == "2")
		{
			std::string str;

			std::cout << "Enter a string: ";
			std::cin >> str;

			int word_count = lexicon.startswith(str, print());

			std::cout << word_count << " Words" << std::endl;
		}

		else if (choice == "3")
		{
			std::string str;

			std::cout << "Enter a string: ";
			std::cin >> str;

			int word_count = lexicon.endswith(str, print());

			std::cout << word_count << " Words" << std::endl;
		}

		else if (choice == "4")
		{
			std::string str;

			std::cout << "Enter a string: ";
			std::cin >> str;

			std::string str_count;

			std::cout << "Enter string count: ";
			std::cin >> str_count;

			if (!is_number(str_count)) {
				std::cout << "You did not enter a valid number!" << std::endl;
				continue;
			}

			int word_count = lexicon.substr_count(str, std::stoi(str_count), print());

			std::cout << word_count << " Words" << std::endl;
		}

		else if (choice == "5")
		{
			std::string str;

			std::cout << "Enter a string (e.g. ba-a-a): ";
			std::cin >> str;

			int word_count = lexicon.char_regex(str, print());

			std::cout << word_count << " Words" << std::endl;
		}

		else if (choice == "6") {
			std::cout << "Exiting the program..." << std::endl;
			exit(EXIT_SUCCESS);
		}

		else {
			std::cout << "You did not enter a valid number!" << std::endl;
		}
	}
}

int main(int argc, char* argv[])
{
	std::string filename = argv[1];

	if (filename.length() <= 4)
	{
		std::cout << "Name of file not valid!" << std::endl;
		return 0;
	}
	if (filename.substr(filename.length() - 4, 4) != ".txt")
	{
		std::cout << "Name of file not valid!" << std::endl;
		return 0;
	}

	Lexicon lexicon(filename);

	menu(lexicon);
}