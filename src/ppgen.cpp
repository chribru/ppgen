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

using std::string;
using std::cout;
using std::endl;

static const char PATH_DICT[] = "/usr/share/dict/words";

int main(int argc, const char *argv[])
{
	std::vector<string> words;

	// open dictionary
	std::ifstream fDict;
	fDict.open(PATH_DICT);

	// read dictionary
	for (string line; std::getline(fDict, line);){
		if (line.length()<4) continue; // ignore short words
		if (line.length()>12) continue; // ignore long words
		if (line.substr(line.length()-2, string::npos) == "'s") continue; // ignore words ending in 's

		words.push_back(line);
	}

	fDict.close();

	cout << "selected " << words.size() << " words from " << PATH_DICT << "." << endl;
	return 0;
}



