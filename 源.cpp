#include <iostream>
#include <vector>
using namespace std;

int max_path(int a[100][100], int t) {
	int d[100][100] = {0};
	int max = a[0][0];
	d[0][0] = max;
	for (int i = 1; i < t; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j != 0) {
				d[i][j] = a[i][j] + (d[i - 1][j] > d[i - 1][j - 1] ? d[i - 1][j] : d[i - 1][j - 1]);
			}
			else d[i][j] = d[i - 1][j] + a[i][j];

			if (d[i][j] > max) {
				max = d[i][j];
			}
		}
	}
	return max;
}

int main(void) {
	int t;
	cin >> t;
	int a[100][100];

	for (int i = 0; i < t; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> a[i][j];
		}
	}

	cout << max_path(a, t);

	return 0;
}