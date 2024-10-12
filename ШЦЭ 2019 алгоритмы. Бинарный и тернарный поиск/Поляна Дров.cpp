#include <algorithm>
#include <fstream>

using namespace std;

const int MAX_ITER = 50;

double Vp, Vf, Oy;

double length(double x1, double y1, double x2, double y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double f(double x) {
	return length(0, 1, x, Oy) * Vf + length(1, 0, x, Oy) * Vp;
}

double search() {
	double l = 0, r = 1;
	int i = 0;
	while (++i <= MAX_ITER) {
		double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
		if (f(m1) > f(m2))
			l = m1;
		else
			r = m2;
	}
	return r;
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	fin >> Vp >> Vf >> Oy;
	fout << search();

	return 0;
}