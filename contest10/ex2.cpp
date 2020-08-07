#include <bits/stdc++.h>
using namespace std;

bool visited[20] = {};
vector<int> near[20];
//Phai de mang visited ben ngoai moi dung
//phai de danh sach ke ben ngoai moi khong bi run-error


bool Try(int k, int v, int *x, bool *visited, vector<int> *near) {
    if(k == v) return true;
    if(k < v) {
        int pre = x[k-1];
        for(int i = 0; i < near[pre].size(); i++) {
            int nex = near[pre][i];
            if(visited[nex] == false) {
                visited[nex] = true;
                x[k] = nex;
                if(Try(k+1, v, x, visited, near))
                    return true;
                visited[nex] = false;
            }
        }
    }
    return false;
}

bool check(int v, vector<int> *near) {
    int x[v+1] = {};
    for(int i = 0; i < v; i++) {
        memset(visited, false, 20);
        visited[i] = true;
        x[0] = i;
        if(Try(1, v, x, visited, near))
            return true;
    }
    return false;
}

int main() {
    int t; cin >> t;
    for(int x = 0; x < t; x++) {
        int v, e; cin >> v >> e;
        for (int i = 0; i < 20; i++)
            near[i].clear();
        for(int i = 0; i < e; i++) {
            int be, en; cin >> be >> en;
            near[be-1].push_back(en-1);
            near[en-1].push_back(be-1);
        }
        cout << check(v, near) << endl;
    }
}
