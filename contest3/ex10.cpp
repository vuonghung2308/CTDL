#include <bits/stdc++.h>
using namespace std; 
  
long long greedy(long long arr[], int n) {
    priority_queue<long long, vector<long long>, greater<long long> > pq(arr, arr + n); 
  
    long long res = 0; 
  
    while (pq.size() > 1) { 
        long long first = pq.top(); 
        pq.pop(); 
        long long second = pq.top(); 
        pq.pop(); 
  
        res = res + first + second; 
        pq.push(first + second); 
    } 
  
    return res; 
} 
  
int main() { 
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		long long *a = new long long[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << greedy(a, n) << endl;
	}
} 
