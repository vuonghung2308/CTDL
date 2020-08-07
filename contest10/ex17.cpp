#include <bits/stdc++.h>
using namespace std;

void Floy(int v, int a[][100], int d[][100]) {
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            if(i == j) d[i][j] = 0;
            else if(a[i][j] == 0)
                d[i][j] = SHRT_MAX;
            else d[i][j] = a[i][j];
        }
    }

    for(int k = 0; k < v; k++) {
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                if(d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
}

int main() {
    int v, e; cin >> v >> e;
    int a[v][100] = {};
    int d[v][100] = {};
    for(int i = 0; i < e; i++) {
        int be, en, cost; cin >> be >> en >> cost;
        a[be-1][en-1] = cost;
        a[en-1][be-1] = cost;
    }
    Floy(v, a, d);
    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        int be, en; cin >> be >> en;
        cout << d[be-1][en-1] << endl;
    }
}
