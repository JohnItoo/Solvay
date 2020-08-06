#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int a,b = 0;
	for(int i = 0; i < 3; i++) {
		if(s[i] == 'A') a++;
		else b++;
	}
	if(a == 3 || b == 3) cout << "No\n";
	else cout << "Yes\n";
}