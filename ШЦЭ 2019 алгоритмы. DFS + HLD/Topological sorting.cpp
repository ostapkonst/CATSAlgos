#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int V, M;
vector<int> *adj;
vector<int> in_degree;

void topologicalSort(ofstream &fout)
{
	queue<int> q;
	for (int i = 0; i < V; i++)
		if (in_degree[i] == 0)
			q.push(i);

	int cnt = 0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		fout << u + 1 << ' ';

		for (const auto& node : adj[u])
			if (--in_degree[node] == 0)
				q.push(node);
		cnt++;
	}

	fout.close();

	if (cnt != V)
	{
		fstream ofs;
		ofs.open("output.txt", ios::out | ios::trunc);
		ofs << "-1";
		ofs.close();
	}
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int a, b;

	fin >> V >> M;
	adj = new vector<int>[V];
	in_degree.resize(V, 0);

	for (int i = 0; i < M; i++) {
		fin >> a >> b;
		adj[a - 1].push_back(b - 1);
		in_degree[b - 1]++;
	}

	topologicalSort(fout);

	return 0;
}