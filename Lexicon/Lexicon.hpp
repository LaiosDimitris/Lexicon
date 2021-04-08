#pragma once

#include <iostream>
#include <string>
#include <vector>

class Lexicon
{
public:
	Lexicon(const std::string &filename);

	int length(const int length, bool print);
	int startswith(const std::string &str, bool print);
	int endswith(const std::string &str, bool print);
	int substr_count(const std::string &str, const int count, bool print);
	int char_regex(std::string str, bool print);

private:
	std::string filename;
	std::vector<std::string> words;

	void read_file();
};

