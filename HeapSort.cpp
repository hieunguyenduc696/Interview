#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void heapify(int a[], int n, int i) {
	int largest = i;
	int left = largest * 2 + 1, right = largest * 2 + 2;
	if (left < n && a[left] > a[largest]) largest = left;
	if (right < n && a[right] > a[largest]) largest = right;
	if (largest != i) {
		swap(a[largest], a[i]);
		heapify(a, n, largest);
	}
}

void heapsort(int a[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(a, n, i);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(a[i], a[0]);
		heapify(a, i, 0);
	}
}

int main() {
	int a[] = { 1,3,2,4,5,7,6,9 };
	heapsort(a, 7);
	for (auto x : a) cout << x << " ";
	return 0;
}