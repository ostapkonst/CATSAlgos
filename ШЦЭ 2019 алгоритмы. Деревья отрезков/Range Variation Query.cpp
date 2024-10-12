#include <algorithm>
#include <fstream>

using namespace std;

const int MAXN = 100000;
const int INF = 1000000000;

int a[MAXN];
pair<int, int> t[4 * MAXN];

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
	return make_pair(min(a.first, b.first), max(a.second, b.second));
}

void build(int v, int tl, int tr) {
	if (tl == tr)
		t[v] = make_pair(a[tl], a[tr]);
	else {
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		t[v] = combine(t[v * 2], t[v * 2 + 1]);
	}
}

pair<int, int> query(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return make_pair(INF, -INF);
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return combine(
		query(v * 2, tl, tm, l, min(r, tm)),
		query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
	);
}

void update(int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t[v] = make_pair(new_val, new_val);
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update(v * 2, tl, tm, pos, new_val);
		else
			update(v * 2 + 1, tm + 1, tr, pos, new_val);
		t[v] = combine(t[v * 2], t[v * 2 + 1]);
	}
}

void build() {
	build(1, 0, MAXN - 1);
}

int query(int l, int r) {
	pair<int, int> res = query(1, 0, MAXN - 1, l, r);
	return res.second - res.first;
}

void update(int pos, int new_val) {
	update(1, 0, MAXN - 1, pos, new_val);
}

int main() {
	ifstream fin("rvq.in");
	ofstream fout("rvq.out");

	for (long long i = 1; i <= MAXN; i++)
		a[i - 1] = i * i % 12345 + i * i * i % 23456;

	build();

	int k;
	fin >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		fin >> x >> y;
		if (x > 0)
			fout << query(x - 1, y - 1) << endl;
		else
			update(-x - 1, y);
	}

	return 0;
}