#include <string>
#include <fstream>
#include <vector>

using namespace std;

int N, M;
vector<int> *adj;
vector<bool> color;
vector<bool> discovered;

void addEdge(int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool DFS(int v) {
	discovered[v] = true;

	for (int u : adj[v]) {
		if (!discovered[u]) {
			discovered[u] = true;
			color[u] = !color[v];

			if (!DFS(u)) return false;
		}
		else
			if (color[v] == color[u]) return false;
	}

	return true;
}

string isBipartite() {
	for (int i = 0; i < N; i++) {
		if (discovered[i]) continue;
		if (!DFS(i)) return "NO";
	}

	return "BIPARTITE";
}

string hotfix() {
	if (N == 1)
		return "NO";
	else {
		if (N == 2) {
			if (M == 0)
				return "BIPARTITE";
			else
				return "NO";
		}
	}
	return "";
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int a, b;

	fin >> N >> M;
	adj = new vector<int>[N];
	color.resize(N, false);
	discovered.resize(N, false);

	for (int i = 0; i < M; i++) {
		fin >> a >> b;
		addEdge(a - 1, b - 1);
	}

	string ans = hotfix();
	if (ans == "")
		fout << isBipartite();
	fout << ans;

	return 0;
}