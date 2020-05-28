#include <bits/stdc++.h>
using namespace std;

const int kNmax = 100000;

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int n;
    int m;
    int k;
    vector<int> adj[kNmax];
    // Memorarea pozitiilor lorzilor.
    vector<int> lorzi;
    // Memorare permutari.
    vector<int> perm;
    // Citire date de intrare.
    void read_input() {
        ifstream fin("p1.in");
        fin >> n >> m >> k;

        for (int i = 0, x; i < k; i++) {
            fin >> x;
            lorzi.push_back(x);
        }

        for (int i = 0, x; i < n - 1; i++) {
            fin >> x;
            perm.push_back(x);
        }

        for (int i = 1, x, y; i <= m; i++) {
            fin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        fin.close();
    }

    int get_result() {
        return solve_p1();
    }
    // Rezolvare.
    int solve_p1() {
        int Left = 0, Right = n - 1;
        while (Left <= Right) {
            // Memorare noduri blocate.
            vector<bool> block(n + 1, false);
            // Pozitiile pana unde plochez drumuri.
            int Mid = (Left + Right) / 2;
            // Blochez toate drumurile pana la Mid.
            for (int i = 0; i <= Mid; i++) {
                int u = perm.at(i);
                block[u] = true;
            }
            // Fac DFS pentr-u a cauta nodurile unde pot ajunge de la sursa
            vector<int> vizitat(n +1 );
            vector<int> top;
            dfs(1, vizitat, top, block);

            bool contains = false;
            // Daca am putut ajunge de la sursa la oricare din lorzi
            // atunci trebuie sa blochez mai multe noduri.
            for (auto &i : lorzi) {
                if (find(top.begin(), top.end(), i) != top.end()) {
                    contains = true;
                    break;
                }
            }

            if (!contains) {
                Right = Mid - 1;
            } else {
                Left = Mid + 1;
            }
        }
        return Left + 1;
    }

    // DFS pe graf cu exceptia nodurilor blocate.
    void dfs(int node, vector<int> &vizitat, vector<int> &d, vector<bool> block) {
        vizitat[node] = 1;

        for (auto &x : adj[node]) {
            if (!vizitat[x] && !block[x]) {
                dfs(x, vizitat, d, block);
            }
        }
        d.push_back(node);
    }
    // Afisare output.
    void print_output(int result) {
        ofstream fout("p1.out");
        fout << result <<'\n';
        fout.close();
    }
};


int main() {
    Task *task = new Task();
    task->solve();
    delete task;
    return 0;
}

