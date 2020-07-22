#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.length();
	vector<int> freq(26, 0);
	for (int i = 0; i < n; i++) {
		freq[s[i] - 'A']++;
	}

	string sol = string(n, ';');

	bool mid = false;
	bool notFound = false;
	int left = 0; int right = n - 1;
	for (int i = 0; i < 26; i++) {
		if (!freq[i]) continue;
		char curr = (char) (i + 'A');

		if ((freq[i] & 1)) {
			if (mid || (n & 1) == 0) {
				notFound = true;
				break;
			} else {
				int cen = n / 2;
				sol[cen] = curr;
				freq[i]--;
				int p = cen - 1;
				int q = cen + 1;
				mid = true;
				while (freq[i]) {
					if (sol[p] != ';' || sol[q] != ';') {
						notFound = true;
						break;
					}
					sol[p] = curr;
					sol[q] = curr;
					p--;
					q++;
					freq[i] -= 2;

				}
				if (notFound) break;
			}
		} else {
			while (freq[i]) {
				if (sol[right] != ';' || sol[left] != ';') {
					notFound = true;
					break;
				}
				sol[left] = curr;
				sol[right] = curr;
				left++;
				right--;
				freq[i] -= 2;
			}
			if (notFound) break;
		}
	}

	if (notFound) {
		cout << "NO SOLUTION\n";
	} else {
		cout << sol << "\n";
	}

}