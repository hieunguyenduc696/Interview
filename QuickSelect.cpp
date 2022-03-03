#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int quickSelect(vector<int> a, int L, int R, int k) {
	int pivot = a[R], p = L;
	for (int i = L; i < R; i++) {
		if (a[i] <= pivot) {
			swap(a[i], a[p]);
			p++;
		}
	}
	swap(a[p], a[R]);
	if (p > k) return quickSelect(a, L, p - 1, k);
	else if (p < k) return quickSelect(a, p + 1, R, k);
	else return a[p];
}

int main() {
	int k = 2;
	vector<int> a = { 3,2,1,4 };
	k = a.size() - k;
	cout << quickSelect(a, 0, a.size() - 1, k);
	return 0;
}