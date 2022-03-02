#include <iostream>
using namespace std;

int t = 256, w = 1283;

void Rabin_Karp(string text, string pattern) {
	int hash_p = 0, hash = 0, i = 0, c = 1;
	int n = text.length(), m = pattern.length();
	for (; i < m; i++) {
		hash_p = (hash_p * t + pattern[i]) % w;
		hash = (hash * t + text[i]) % w;
	}
	for (i = 1; i <= m - 1; i++) c = (c * t) % w;
	i = 0;
	while (i < n - m) {
		if (hash_p == hash) {
			bool flag = false;
			for (int j = 0; j < m; j++) {
				if (pattern[j] != text[i + j]) {
					flag = true;
					break;
				}
			}
			if (!flag) cout << i << " ";
		}
		else {
			hash = ((hash - text[i] * c) * t + text[i + m]) % w;
			if (hash < 0) hash += w;
		}
		i++;
	}
}

int main() {
	string text = "ababcdabcb";
	string pattern = "abc";
	Rabin_Karp(text, pattern);
	return 0;
}