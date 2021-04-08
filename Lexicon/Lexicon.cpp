#include "Lexicon.hpp"
#include <algorithm>
#include <fstream>
#include <regex>

Lexicon::Lexicon(const std::string &filename)
{
	this->filename = filename;
	this->read_file();
}

void Lexicon::read_file()
{
	std::ifstream file(this->filename);

	std::string word;

	while (std::getline(file, word)) {
		this->words.push_back(word);
	}

	file.close();
}

// 1. Nα εμφανίζει το πλήθος και εφόσον ο χρήστης επιθυμεί όλες τις λέξεις 
// που έχουν το πλήθος γραμμάτων που θα δίνει ο χρήστης.
int Lexicon::length(const int length, bool print)
{
	int word_count = 0;

	for (auto word: this->words)
	{
		if (word.length() == length)
		{
			word_count++;

			if (print) {
				std::cout << word << std::endl;
			}
		}
	}

	return word_count;
}

// 2. Nα εμφανίζει το πλήθος και εφόσον ο χρήστης επιθυμεί όλες τις λέξεις 
// που ξεκινούν με μια ακολουθία γραμμάτων που θα δίνει ο χρήστης.
int Lexicon::startswith(const std::string &str, bool print)
{
	int word_count = 0;

	for (auto word: this->words)
	{
		if (str.length() > word.length()) {
			continue;
		}

		if (word.substr(0, str.length()) == str)
		{
			word_count++;

			if (print) {
				std::cout << word << std::endl;
			}
		}
	}

	return word_count;
}

// 3. Nα εμφανίζει το πλήθος και εφόσον ο χρήστης επιθυμεί όλες τις λέξεις
// που τελειώνουν με μια ακολουθία γραμμάτων που θα δίνει ο χρήστης.
int Lexicon::endswith(const std::string &str, bool print)
{
	int word_count = 0; 

	for (auto word: this->words)
	{
		if (str.length() > word.length()) {
			continue;
		}

		int starting_index = word.length() - str.length();

		if (word.substr(starting_index, str.length()) == str)
		{
			word_count++;

			if (print) {
				std::cout << word << std::endl;
			}
		}
	}

	return word_count;
}

// 4. Nα εμφανίζει το πλήθος και εφόσον ο χρήστης επιθυμεί όλες τις λέξεις 
// που περιέχουν μια ακολουθία γραμμάτων που θα δίνει ο χρήστης 
// τόσες συνεχόμενες φορές όσες θα δίνει ο χρήστης.
int Lexicon::substr_count(const std::string &str, const int count, bool print)
{
	int word_count = 0;

	std::string str_to_find;

	for (int i = 0; i < count; i++) {
		str_to_find += str;
	}

	for (auto word: this->words)
	{
		if (word.find(str_to_find) != std::string::npos)
		{
			word_count++;

			if (print) {
				std::cout << word << std::endl;
			}
		}
	}

	return word_count;
}

// 5. Nα εμφανίζει το πλήθος και εφόσον ο χρήστης επιθυμεί όλες τις λέξεις 
// που περιέχουν σε θέσεις που θα επιλέγει ο χρήστης συγκεκριμένα γράμματα 
//(για παράδειγμα ba-a-a σημαίνει ότι αναζητείται οποιαδήποτε λέξη 
// που περιέχει σε οποιοδήποτε θέση τη σειρά γραμμάτων ba-a-a με το - να σημαίνει οποιοδήποτε γράμμα, 
// οπότε τέτοιες λέξεις είναι οι bahamas και banana).
int Lexicon::char_regex(std::string str, bool print)
{
	int word_count = 0;

	std::replace(str.begin(), str.end(), '-', '.');

	for (auto word: this->words)
	{
		if (std::regex_match(word, std::regex(str)))
		{
			word_count++;

			if (print) {
				std::cout << word << std::endl;
			}
		}
	}

	return word_count;
}