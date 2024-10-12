#include <algorithm>
#include <fstream>

using namespace std;

const int MAXN = 100000;

long long t[4 * MAXN];
int n;

void push(int v) {
	if (t[v] != -1) {
		t[v * 2] = t[v * 2 + 1] = t[v];
		t[v] = -1;
	}
}

void update(int v, int tl, int tr, int l, int r, long long color) {
	if (l > r)
		return;
	if (l == tl && tr == r)
		t[v] = color;
	else {
		push(v);
		int tm = (tl + tr) / 2;
		update(v * 2, tl, tm, l, min(r, tm), color);
		update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, color);
	}
}

long long query(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr && t[v] != -1)
		return t[v] * (r - l + 1);
	push(v);
	int tm = (tl + tr) / 2;
	return query(v * 2, tl, tm, l, min(r, tm)) +
		query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

long long query(int l, int r) {
	return query(1, 0, n - 1, l, r);
}

void update(int l, int r, long long new_val) {
	update(1, 0, n - 1, l, r, new_val);
}

int main() {
	ifstream fin("sum.in");
	ofstream fout("sum.out");
	char v;
	int k, l, r, val;

	fin >> n >> k;
	for (int i = 0; i < k; i++) {
		fin >> v >> l >> r;
		if (v == 'A') {
			fin >> val;
			update(l - 1, r - 1, val);
		}
		else
			fout << query(l - 1, r - 1) << endl;
	}

	return 0;
}