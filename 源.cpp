#include <iostream>
#include <vector>
using namespace std;
<<<<<<< HEAD

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
=======
int half = 0;
int n = 0;
int num = 0, sum = 0;
int p[100][100];
void backtrack(int t) {
	
	/*if (t == 4) {
		t = 4;
	}*//*ÔËÐÐ¶Ïµã*/
	if ((num > half) || (t * (t - 1) / 2 - num > half)) return;
	if (t > n) sum++;
	else {
		for (int i = 0; i < 2; i++) {
			p[1][t] = i;
			num += i;
			for (int j = 2; j <= t; j++) {
				p[j][t - j + 1] = p[j - 1][t - j + 1] == p[j - 1][t - j + 2] ? 0 : 1;
				num += p[j][t - j + 1];

			}
			backtrack(t + 1);
			for (int j = 2; j <= t; j++) {
				num -= p[j][t - j + 1];
				
			}
			num -= i;
		}
	}
}
int main(void) {
	
	cin >> n;
	memset(p, -1, sizeof(p));
	half = (n * (n + 1)) / 4;
	backtrack(1);
	cout << sum << endl;
>>>>>>> a89743c (recall)
}