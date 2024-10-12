#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

void findPrefix(int* pattern, int m, int prefArray[]) {
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

void kmpPattSearch(int* mainString, int* pattern, int *locArray, int &loc, int n, int m) {
	int i = 0, j = 0;
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

const int MAXN = 100000;
int str[MAXN], patt[MAXN], locationArray[MAXN];

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, m, temp, index;

	fin >> n;
	for (int i = 0, v; i < n; i++) {
		fin >> v;
		if (i > 0)
			str[i - 1] = v - temp;
		temp = v;
	}

	fin >> m;
	for (int i = 0, v; i < m; i++) {
		fin >> v;
		if (i > 0)
			patt[i - 1] = v - temp;
		temp = v;
	}

	kmpPattSearch(str, patt, locationArray, index, n - 1, m - 1);

	if (index > 0)
		fout << locationArray[0] + 1;
	else
		fout << -1;

	return 0;
}