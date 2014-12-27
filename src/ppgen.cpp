/*
    This file is part of ppgen.

    ppgen is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    ppgen is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ppgen.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>

using std::string;
using std::cout;
using std::endl;

static const char *PATH_DICT = "/usr/share/dict/words";

static bool readDict(const char* fileName, std::vector<string> &toVector){
	// open dictionary
	std::ifstream fDict;
	fDict.open(fileName);

	if (!fDict.is_open())
		return false;

	// read dictionary
	for (string line; std::getline(fDict, line);){
		if (line.length()<4) continue; // ignore short words
		if (line.length()>12) continue; // ignore long words
		if (line.substr(line.length()-2, string::npos) == "'s") continue; // ignore words ending in 's

		toVector.push_back(line);
	}

	return true;
}

static bool parseInt(const char* str, int &outInt){
	try{
		outInt = std::atol(str);
		return true;
	} catch (...) {}

	return false;
}


int main(int argc, const char *argv[])
{
	std::vector<string> words;
	readDict(PATH_DICT, words);

	std::random_device dev;
	std::uniform_int_distribution<int> dist(0, words.size()-1);

	int nWords = 5;
	int nSentences = 10;

	if (argc > 1) parseInt(argv[1], nWords);
	if (argc > 2) parseInt(argv[2], nSentences);

	for (int sentence = 0; sentence < nSentences; ++sentence){
		for (int word = 1; word < nWords; ++ word)
			cout << words[dist(dev)] << " ";
		cout << words[dist(dev)] << endl;
	}


}



