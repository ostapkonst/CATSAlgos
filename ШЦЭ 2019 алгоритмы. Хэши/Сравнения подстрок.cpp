#include <string>
#include <iostream>

using namespace std;

const int MAX_STR_LEN = 100000;
const int POW_COF = 113;

unsigned long long powar[MAX_STR_LEN];
unsigned long long heshar[MAX_STR_LEN];

int M;
string S;

void calc_arrays() {
	powar[0] = 1;
	heshar[0] = S[0];
	for (size_t i = 1; i < S.length(); i++) {
		powar[i] = powar[i - 1] * POW_COF;
		heshar[i] = heshar[i - 1] + (unsigned long long) S[i] * powar[i];
	}
}

int main() {
	cin >> S >> M;

	calc_arrays();

	for (int i = 1; i <= M; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;

		unsigned long long h1 = heshar[b] - (a > 0 ? heshar[a - 1] : 0),
			h2 = heshar[d] - (c > 0 ? heshar[c - 1] : 0);

		if (a < c)
			h1 *= powar[c - a];
		else
			h2 *= powar[a - c];

		cout << (h1 == h2 ? "Yes" : "No") << endl;
	}

	if (M == 0)
		cout << "No" << endl;

	return 0;
}