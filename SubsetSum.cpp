#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool f[20][500000], c[20][500000];
int n, k;

int find() {
	for (int i = 1; i <= n; i++) {
		if (f[i][k]) return i;
	}
}
int main() {
	n = 5;
	k = 8;
	long long a[20] = { 0,1,5,2,9,7 };
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j == 0) c[i][j] = true;
			else c[i][j] = false;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (a[i] > j) f[i][j] = false;
			else f[i][j] = c[i - 1][j - a[i]];
			if (f[i][j] || c[i - 1][j]) c[i][j] = true;
		}
	}
	int m = find();
	if (m == 0) cout << "not found."; else {
		while (k != 0) {
			cout << a[m] << " ";
			k -= a[m];
			m = find();
		}
	}
	return 0;
}