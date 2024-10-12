#include <fstream>

using namespace std;

const int MAXN = 1e5;
const int MAXM = 1e6;

int edges[2 * MAXM];
int root[MAXN];

int M, N;

int getRoot(int i) {
	while (root[i] != i) {
		root[i] = root[root[i]];
		i = root[i];
	}
	return i;
}

int countComponents() {
	int count = N;

	for (int i = 0; i < N; i++) root[i] = i;

	for (int i = 0; i < M; i++) {
		int x = edges[2 * i];
		int y = edges[2 * i + 1];

		int xRoot = getRoot(x);
		int yRoot = getRoot(y);

		if (xRoot != yRoot) {
			count--;
			root[xRoot] = yRoot;
		}
	}

	return count;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int a, b;

	fin >> N >> M;
	for (int i = 0; i < M; i++) {
		fin >> a >> b;
		edges[i * 2] = a - 1;
		edges[i * 2 + 1] = b - 1;
	}

	fout << countComponents() << endl;

	return 0;
}