#include <iostream>
#include <algorithm>
using namespace std;

typedef struct goods {
	int V;
	int M;
	int VM;
	
}goods;
bool Compare(const goods &a, const goods &b)            
{
	return a.VM > b.VM;
}
int MaxBagWeath(int t, int n, goods G[]) {
	int N = 0; 
	int maxV = 0;
	sort(G, G + 4, Compare);
	for (int i = 0; i < t && N <= n; i++) {
		if (N + G[i].M <= n) {
			maxV += G[i].V;
			N += G[i].M;
		}
		else {
			maxV += G[i].VM * (n - N);
			N = n;
		}
	}
	return maxV;
}
int main(void) {
	int t, n;
	goods G[10];
	cin >> t >> n;
	int V[10] = {0}, W[10] = { 0 };
	double VM[10] = {0};
	for (int i = 0; i < t; i++) {
		cin >> G[i].M;
	}
	for (int i = 0; i < t; i++) {
		cin >> G[i].V;
		G[i].VM = (G[i].V) / G[i].M;
	}
	cout << MaxBagWeath(t, n, G);
}