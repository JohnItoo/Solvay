#include <bits/stdc++.h>

using namespace std;

int main() {
	string temp;
	bool left = true;

	while (getline(cin, temp)) {
		for (string::iterator iter = temp.begin(); iter < temp.end(); ++iter) {
			if (*iter == '"') {
				if (left) {
					cout << "``";
				} else {
					cout << "''";
				}
				left = !left;
			} else {
				cout << *iter;
			}
		}
		cout << "\n";
	}
}