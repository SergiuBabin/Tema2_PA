#include <bits/stdc++.h>
using namespace std;

const int kInf = 0x3f3f3f3f;
const int kNmax = 500005;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	int m;
	int source;
	int dest;
	vector<pair<int, int> > adj[kNmax];
	// Citire date de intrare.
	void read_input() {
		ifstream fin("p2.in");
		fin >> n >> m >> source >> dest;
		for (int i = 1, x, y, w; i <= m; i++) {
			fin >> x >> y >> w;
			adj[x].push_back(make_pair(y, w));
		}
		fin.close();
	}

	vector<int> get_result() {
		// Retinem distantele minime de la sursa la fiecare nod.
		vector<int> d(n + 1, kInf);
		bellman(d);
		return d;
	}
	// Parcurgerea DFS cu retinerea nodurilor in ordine topologica.
	void DFS(int v, vector<bool> &visited, vector<int> &dep) {
		visited[v] = true;
		for (const auto& nod : adj[v]) {
			int u = nod.first;
			if (!visited[u]) {
				DFS(u, visited, dep);
			}
		}
		dep.push_back(v);
	}

	void bellman(vector<int>& d) {
		// Nodurile in ordine topologica.
		vector<int> dep;

		vector<bool> visited(n+1);
		// Sortarea topologica a nodurilor din graf.
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				DFS(i, visited, dep);
			}
		}
		// Distanta de la sursa la sursa = 0.
		d[source] = 0;
		// Parcurg toate nodurile sortate si aflu distantele cele mai mici.
		for (int i = (int)dep.size() - 1; i >= 0 ; i--) {
			int u = dep[i];
			for (const auto& nod : adj[u]) {
				if (d[nod.first] > d[u] + nod.second) {
					d[nod.first] = d[u] + nod.second;
				}
			}
		}
	}
	// Printare output.
	void print_output(vector<int> result) {
		ofstream fout("p2.out");
		// Costul minim pana la nodul destinatie se afla pe pozitia dest
		// in vectorul de noduri.
		fout << result[dest];
		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}
