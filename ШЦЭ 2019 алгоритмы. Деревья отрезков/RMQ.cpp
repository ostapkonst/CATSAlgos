#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

const int MAXN = 100000;
const int INF = 1000000000;

int a[MAXN], n;
long long t[4 * MAXN];
long long lazy[4 * MAXN];

void push(int v) {
	t[v * 2] += lazy[v];
	lazy[v * 2] += lazy[v];
	t[v * 2 + 1] += lazy[v];
	lazy[v * 2 + 1] += lazy[v];
	lazy[v] = 0;
}

void build(int v, int tl, int tr) {
	if (tl == tr)
		t[v] = a[tl];
	else {
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		t[v] = max(t[v * 2], t[v * 2 + 1]);
	}
}

void update(int v, int tl, int tr, int l, int r, long long add) {
	if (l > r)
		return;
	if (l == tl && tr == r) {
		t[v] += add;
		lazy[v] += add;
		return;
	}
	push(v);
	int tm = (tl + tr) / 2;
	update(v * 2, tl, tm, l, min(r, tm), add);
	update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
	t[v] = max(t[v * 2], t[v * 2 + 1]);
}

long long query(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return -INF;
	if (l == tl && tr == r)
		return t[v];
	push(v);
	int tm = (tl + tr) / 2;
	return max(
		query(v * 2, tl, tm, l, min(r, tm)),
		query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
	);
}

void update(long long l, long long r, long x) {
	update(1, 0, n - 1, l, r, x);
}

long long query(long long l, long long r) {
	return query(1, 0, n - 1, l, r);
}

int main() {
	ifstream fin("rmq.in");
	ofstream fout("rmq.out");
	string v;
	int k, l, r, val;

	fin >> n >> k;
	for (int i = 0; i < n; i++) {
		fin >> a[i];
	}

	build(1, 0, n - 1);

	for (int i = 0; i < k; i++) {
		fin >> v >> l >> r;
		if (v == "add") {
			fin >> val;
			update(l - 1, r - 1, val);
		}
		else
			fout << query(l - 1, r - 1) << endl;
	}

	return 0;
}