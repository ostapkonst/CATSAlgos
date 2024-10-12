#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

struct A {
	double y, a;
	A(double y, double a) : y(y), a(a) {}
	bool operator < (const A& rhs) const { return y < rhs.y; }
};

double V, M;
int N;
vector<A> holes;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	fin >> V >> M >> N;

	for (int i = 0; i < N; i++) {
		double x, y, a;
		fin >> x >> y >> a;
		holes.emplace_back(y, a);
		holes.emplace_back(y + a, -a);
	}

	sort(holes.begin(), holes.end());
	double stop_at = M / V;

	double h = 0, a = 0, b = 0, c = -1, d = 0;
	for (auto &el : holes) {
		d = b;
		b += a * (el.y - h);
		if (stop_at <= b) {
			c = h + (stop_at - d) / a;
			break;
		}
		h = el.y;
		a += el.a;
	}

	fout << c << endl;

	return 0;
}