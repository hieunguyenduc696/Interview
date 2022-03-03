#include <iostream>
#include <vector>
using namespace std;

void quicksort(int a[], int L, int R) {
	int i = L, j = R, mid = a[(L + R) / 2];
	do {
		while (a[i] < mid) i++;
		while (a[j] > mid) j--;
		if (i <= j) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++; j--;
		}
	} while (i <= j);
	if (i < R) quicksort(a, i, R);
	if (j > L) quicksort(a, L, j);
}

int main() {
	int a[] = { 1,3,2,4 };
	quicksort(a, 0, 3);
	for (auto x : a) cout << x << " ";
	return 0;
}