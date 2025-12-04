#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> g;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

struct DSU {
    vector<int> parent, size;
    DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (size[x] < size[y])
                swap(x, y);
            parent[y] = x;
            size[x] += size[y];
        }
    }
};

void processFall() {
    for (int col = 0; col < 10; ++col) {
        int write = n - 1;
        for (int read = n - 1; read >= 0; --read) {
            if (g[read][col] != 0) {
                g[write][col] = g[read][col];
                if (write != read)
                    g[read][col] = 0;
                --write;
            }
        }
    }
}

int processPop() {
    DSU dsu(n * 10);
    vector<int> size(n * 10, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (g[i][j] == 0) continue;
            for (int dir = 0; dir < 4; ++dir) {
                int x = i + dx[dir];
                int y = j + dy[dir];
                if (x >= 0 && x < n && y >= 0 && y < 10 && g[x][y] == g[i][j]) {
                    int u = i * 10 + j;
                    int v = x * 10 + y;
                    if (dsu.find(u) != dsu.find(v)) {
                        dsu.unite(u, v);
                    }
                }
            }
        }
    }
    bool poppedAny = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (g[i][j] == 0) continue;
            int root = dsu.find(i * 10 + j);
            if (dsu.size[root] >= k) {
                g[i][j] = 0;
                poppedAny = true;
            }
        }
    }
    return poppedAny;
}

void printGrid() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << g[i][j];
        }
        cout << '\n';
    }
}

void solve() {
    cin >> n >> k;
    g.resize(n, vector<int>(10));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 10; ++j) {
            g[i][j] = s[j] - '0';
        }
    }
    processFall();
    while (processPop()) {
        processFall();
    }
    printGrid();
}

int main() {
    solve();
    return 0;
}