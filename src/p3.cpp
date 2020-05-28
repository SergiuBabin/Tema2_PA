#include <bits/stdc++.h>
using namespace std;

const int kNmax = 1000000;
const int kInf = 0x3f3f3f3f;

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int n;
    int m;
    int energy;
    double res;
    vector<pair<int, double> > adj[kNmax];
    // Citire date de intrare.
    void read_input() {
        ifstream fin("p3.in");
        fin >> n >> m >> energy;
        for (int i = 1, x, y; i <= m; i++) {
            double w;
            fin >> x >> y >> w;
            adj[x].push_back(make_pair(y, w));
        }
        fin.close();
    }

    vector<int> get_result() {
        vector<double> d(n + 1, -1);
        vector<int> drum;
        Dijkstra(d, drum);
        return drum;
    }
    // Algoritmul Dijkstra.
    void Dijkstra(vector<double> &d, vector<int> &drum) {
        // Comparatorul pentru coada de prioritati.
        auto cmp = [&d](int x, int y) {return d[x] < d[y];};
        // Coada de prioritati.
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        pq.push(1);
        d[1] = 1;
        // Vectorul de parinti.
        vector<int> p(n+1, kInf);
        // Calculare drumuri cu cost minim
        while (!pq.empty()) {
            int u = pq.top();
            pq.pop();
            for (const auto& k : adj[u]) {
                if (d[k.first] < (1 - (double)k.second/100) * d[u]) {
                    d[k.first] = (1 - (double)k.second/100) * d[u];
                    p[k.first] = u;
                    pq.push(k.first);
                }
            }
        }
        // Nodul de la care incep caurarea drumului pana la sursa.
        int nod = p[n];
        // Am folosit o stiva pentru memorarea drumului.
        drum.push_back(n);
        // Introduc fiecare parinte a nodurilor pana la sursa.
        while (nod != kInf) {
            drum.push_back(nod);
            nod = p[nod];
        }
        // Cata energie a ramas pana la destinatie.
        res = d[n] * energy;
    }
    // Afisare date de iesire.
    void print_output(vector<int> drum) {
        ofstream fout("p3.out");
        fout << setprecision(11)<< res <<"\n";
        for (int i = (int)drum.size()-1; i >= 0; i--) {
            fout<< drum[i] << " ";
        }
        fout.close();
    }
};


int main() {
    Task *task = new Task();
    task->solve();
    delete task;
    return 0;
}
