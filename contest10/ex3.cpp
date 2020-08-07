#include <bits/stdc++.h>
using namespace std;

bool check(int i, int v, vector<int> *near, int *color) {
    color[i] = 1;
    queue<int> q; q.push(i);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = 0; i < near[u].size(); i++) {
            if(color[near[u][i]] == 0) {
                color[near[u][i]] = (color[u] == 1)?2:1;
                q.push(near[u][i]);
            } else if(color[u] == color[near[u][i]])
                return false;
        }
    }
    return true;
}

bool checkAll(int v, vector<int> *near) {
    int color[v] = {};
    for(int i = 0; i < v; i++) {
        if(color[i] == 0)
            if(!check(i,v, near, color))
                return false;
    }
    return true;
}

int main() {
    int t; cin >> t;
    for(int x = 0; x < t; x++) {
        int v, e; cin >> v >> e;
        vector<int> near[v];
        for(int i = 0; i < e; i++) {
            int be, en; cin >> be >> en;
            near[be-1].push_back(en-1);
            near[en-1].push_back(be-1);
        }
        if(checkAll(v, near))
            cout << "YES\n";
        else cout << "NO\n";
    }
}
