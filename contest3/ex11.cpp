//co them so bo test
//bai nay de tren web

#include <bits/stdc++.h>
using namespace std; 
  
long long greedy(long long arr[], int n) {
	long long x = 1000000000 + 7;
    priority_queue<long long, vector<long long>, greater<long long> > pq(arr, arr + n); 
  
    long long res = 0; 
  
    while (pq.size() > 1) { 
        long long first = pq.top()%x; 
        pq.pop(); 
        long long second = pq.top()%x; 
        pq.pop(); 
  		long long t = (first + second)%x;
        pq.push(t); 
        res = res + t;
		res = res % x; 
    } 
  
    return res; 
} 
  
int main() {
	int t; cin >> t;
	for(int x= 0; x < t; x++) {
		int n; cin >> n;
		long long *a = new long long[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << greedy(a, n) << endl;
	}
} 
