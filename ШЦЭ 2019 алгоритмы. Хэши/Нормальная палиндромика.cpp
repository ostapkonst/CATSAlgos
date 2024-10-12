#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> findPrefix(string pattern) {
	int length = 0, m = pattern.size();
	vector<int> prefArray(m, 0);

	for (int i = 1; i < m; i++) {
		if (pattern[i] == pattern[length])
			prefArray[i] = ++length;
		else {
			if (length != 0) {
				length = prefArray[length - 1];
				i--;
			}
			else
				prefArray[i] = 0;
		}
	}

	return prefArray;
}

string tail(string const& source, size_t const length) {
	if (length >= source.size()) return source;
	return source.substr(source.size() - length);
}

const char DELIM = '$';

int main() {
	fstream fin("input.txt");
	ofstream fout("output.txt");
	string s;

	fin >> s;
	string revS = s;
	reverse(revS.begin(), revS.end());
	vector<int> lps = findPrefix(revS + DELIM + s);
	fout << tail(revS, s.length() - lps.back());

	return 0;
}