#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

long long W, H, N;

bool possible(long long h) {
	unsigned long long a = h / H,
		b = (h - W) / W,
		rs = a * b + a;

	return rs >= N;
}

long long min_possible() {
	long long l = 0, r = 1e18;

	while (l < r) {
		long long m;
		m = (l + r) / 2;
		if (!possible(m))
			l = m + 1;
		else
			r = m;
	}

	return l;
}

int main() {
	ifstream fin("diploma.in");
	ofstream fout("diploma.out");

	fin >> W >> H >> N;
	fout << min_possible();

	return 0;
}