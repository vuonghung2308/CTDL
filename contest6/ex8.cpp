#include <bits/stdc++.h>
using namespace std;

int count(int x, int m, int *y, int *no_of_y) {
	if(x == 0) return 0; // x == 0 thi khong co y nao tm
	if(x == 1) return no_of_y[0]; // x == 1 thi chi co y = 0 tm => tra ve so phan tu bang == 0
	int *it = upper_bound(y, y+m, x); // tim vi tri phan tu dau tien lon hon x;
	int ans = y + m - it; // dem so phan tu lon hon x trong y
	ans += no_of_y[0] + no_of_y[1]; // voi x > 2 cong voi so phan tu bang 0 va 1
	if(x == 2) // neu x == 2 thi tru di so phan tu bang 3 va 4
		ans -= (no_of_y[3] + no_of_y[4]); 
	if(x == 3) // neu x == 3 thi cong them so phan tu bang 2 vi 2 < 3 khong co trong ans
		ans = ans + no_of_y[2];
	// neu x > 3 thi la so phan tu lon hon x va so phan tu 0, 1 co trong y (hai ham if khong duoc goi)
	return ans;
}

int countPair(int n, int m, int *x, int *y, int *no_of_y) {
	sort(y, y+n); // xap sep tang dan
	int res = 0;
	for(int i = 0; i < n; i++)
		res = res + count(x[i], m, y, no_of_y); // voi moi x dem so phan tu thuoc y thoa man
	return res;
}

int main() {
	int t; cin >> t;
	for(int z = 0; z < t; z++) {
		int n, m; cin >> n >> m;
		int x[n], y[m], no_of_y[5] = {};
		for(int i = 0; i < n; i++)
			cin >> x[i];
		for(int i = 0; i < m; i++) {
			cin >> y[i];
			if(y[i] < 5) // dem so phan tu thuoc y < 5
				no_of_y[y[i]]++;
		}
		cout << countPair(n, m, x, y, no_of_y) << endl;
	}
}
