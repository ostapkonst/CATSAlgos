#include <algorithm>
#include <fstream>

using namespace std;

const int MAXN = 100000;

long long n, k, t[4 * MAXN];

// t[v] - хранит сумму отрезка vl..vr
void update(int v, int vl, int vr, int pos, int val) {
	if (vl == vr) {
		t[v] = val;
		return;
	}

	int tm = (vl + vr) / 2;
	if (pos <= tm)
		update(v * 2, vl, tm, pos, val);
	else
		update(v * 2 + 1, tm + 1, vr, pos, val);
	t[v] = t[v * 2] + t[v * 2 + 1];
}

long long sum(int v, int vl, int vr, int l, int r) {
	if (l > r) return 0;
	if (vl == l && vr == r) return t[v];

	int tm = (vl + vr) / 2;
	return sum(v * 2, vl, tm, l, min(r, tm)) +
		sum(v * 2 + 1, tm + 1, vr, max(l, tm + 1), r);
}

long long sum(int l, int r) {
	return sum(1, 0, n - 1, l, r);
}

void update(int pos, int val) {
	update(1, 0, n - 1, pos, val);
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	char v;
	int a, b;

	fin >> n >> k;
	for (int i = 0; i < k; i++) {
		fin >> v >> a >> b;
		if (v == 'A')
			update(a - 1, b);
		else
			fout << sum(a - 1, b - 1) << endl;
	}

	return 0;
}