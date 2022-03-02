#include <iostream>
#include <vector>
using namespace std;

vector<int> LPS(string pattern) {
	int n = pattern.length(), j = 0;
	vector<int> lps(n);
	lps[0] = 0;
	for (int i = 1; i < pattern.length(); i++) {
		if (pattern[i] == pattern[j]) {
			lps[i] = ++j;
		}
		else {
			if (j == 0) {
				lps[i] = 0;
			}
			else {
				j = lps[j - 1];
				i--;
			}
		}
	}
	return lps;
}

void KMP(string text, string pattern) {
	vector<int> lps = LPS(pattern);
	int i = 0, j = 0, n = text.length(), m = pattern.length();
	while (i < n) {
		if (pattern[j] == text[i]) i++, j++;
		if (j == m) {
			cout << i - m << " ";
			j = lps[j - 1];
		}
		else if (i < n && pattern[j] != text[i]) {
			if (j == 0) {
				i++;
			}
			else {
				j = lps[j - 1];
			}
		}
	}
}

int main() {
	string text = "ababcdabcb";
	string pattern = "abc";
	KMP(text, pattern);
	return 0;
}