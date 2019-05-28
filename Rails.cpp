//============================================================================
// Name        : Rails.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
stack<char> s;
int a[1000], b[1000];
int n;

int main() {
	scanf("%d", &n);
	string c;
	bool pss = true;
	for (int i = 0; i < n; ++i) {
		getline(cin, c);
		for (int j = 0; j < c.length(); j++) {
			if (c[i] == ' ') {
				continue;
			} else if (c[i] == '(' || c[i] == '[') {
				cout << c[i]<< '\n';
				s.push(c[i]);
			} else if (c[i] == ')') {
				if (s.top() != '(') {
					pss = false;
					break;
				} else
					s.pop();

			} else if ( c[i] == ']') {
				if (s.top() != '[') {
					pss = false;
					break;
				} else
					s.pop();
			}
		}
	}
	return 0;
}
