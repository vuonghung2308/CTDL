#include <bits/stdc++.h>
using namespace std;

struct point{
	int x;
	int y;
};

bool lessX(point a, point b) {
	return a.x < b.x;
}

bool lessY(point a, point b) {
	return a.y < b.y;
}


double calDistance(point a, point b) {
	double d = (double) (a.x -b.x)*(a.x - b.x) + (double) (a.y - b.y)*(a.y - b.y);
	return (double) sqrt(d);
}

double findMinOf3(point *p, int n) {
	double min = FLT_MAX;
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
			if(calDistance(p[i], p[j]) < min)
				min = calDistance(p[i], p[j]);
	return min;
}

double findMinSub(point *p, int n, double d) {
	sort(p, p+n, lessY);
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n && p[j].y - p[i].y < d; j++)
			if(calDistance(p[i], p[j]) < d)
				d = calDistance(p[i], p[j]);
	return d;
}

double findMin(point *p, int n) {
	if(n <= 3) return findMinOf3(p, n);
	int mid = n / 2;
	double dl = findMin(p, mid+1);
	double dr = findMin(p+mid, n - mid);
	double d = min(dr, dl);
	
	point *p_ = new point[n];
	int n_ = 0;
	for(int i = 0; i < n; i++) {
		if(abs(p[i].x-p[mid].x) < d)
			p_[n_++] = p[i];
	}
	return findMinSub(p_, n_, d);
}



int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n; cin >> n;
		point *p = new point[n];
		for(int i = 0; i < n; i++) 
			cin >> p[i].x >> p[i].y;
		sort(p, p+n, lessX);
		cout << setprecision(6) << fixed << findMin(p, n) << endl;
	}
}
