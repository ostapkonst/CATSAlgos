#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

void findPrefix(string pattern, int m, int prefArray[]) {
	int length = 0;
	prefArray[0] = 0;

	for (int i = 1; i < m; i++) {
		if (pattern[i] == pattern[length]) {
			length++;
			prefArray[i] = length;
		}
		else {
			if (length != 0) {
				length = prefArray[length - 1];
				i--;
			}
			else
				prefArray[i] = 0;
		}
	}
}

void kmpPattSearch(string mainString, string pattern, int *locArray, int &loc) {
	int n, m, i = 0, j = 0;
	n = mainString.size();
	m = pattern.size();
	int* prefixArray = new int[m];
	findPrefix(pattern, m, prefixArray);
	loc = 0;

	while (i < n) {
		if (mainString[i] == pattern[j]) {
			i++; j++;
		}

		if (j == m) {
			locArray[loc] = i - j;
			loc++;
			j = prefixArray[j - 1];
		}
		else if (i < n && pattern[j] != mainString[i]) {
			if (j != 0)
				j = prefixArray[j - 1];
			else
				i++;
		}
	}
}

int main() {
	string str, patt;
	int index;
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	getline(fin, str);
	getline(fin, patt);

	int *locationArray = new int[str.size()];
	kmpPattSearch(str, patt, locationArray, index);

	if (index == 0)
		fout << -1;
	else
		fout << locationArray[0] + 1;

	return 0;
}