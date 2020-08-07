#include <bits/stdc++.h>
using namespace std;

bool check(int k, int c, vector<int> *near, int *color) {
    for(int i = 0; i < near[k].size(); i++)
        if(color[near[k][i]] == c)
            return false;
    return true;
}

bool Try(int k, int v, int m, vector<int> *near, int *color) {
    if(k == v) return true;
    for(int i = 1; i <= m; i++) {
        if(check(k, i, near, color)) {
            color[k] = i;
            if(Try(k+1, v, m, near, color))
                return true;
            color[k] = 0;
        }
    }
    return false;
}

int main() {
    int t; cin >> t;
    for(int x = 0; x < t; x++) {
        int v, e, m; cin >> v >> e >> m;
        int color[v] = {};
        vector<int> near[v];
        for(int i = 0; i < e; i++) {
            int be, en; cin >> be >> en;
            near[be-1].push_back(en-1);
            near[en-1].push_back(be-1);
        }
        if(Try(0, v, m, near, color))
            cout << "YES\n";
        else cout << "NO\n";
    }
}
