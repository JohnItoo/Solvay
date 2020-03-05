//============================================================================
// Name        : dnaSort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

struct strand {
	int pos; string seq; int inv;
	void init() { pos = 0; inv = 0;}

	void build(int a, int b) { pos = a; inv = b; }
};

bool comp (strand a, strand b) {
	if(a.inv != b.inv) return a.inv < b.inv;
	else return a.pos < b.pos;
}

int main() {
	int M,m,n;  string blank;
	scanf("%d", &M);
  bool first = true;
	while(M--) {
//		if(first) cout <<'\n';
//		first = false;
        getline(cin, blank);
		scanf("%d %d",  &n,&m);
		getchar();
		string id;
		strand s[m];
		for(int i = 0; i<m; ++i) {
			s[i].init();
			getline(cin, id);
			s[i].seq = id;
		 int inv= 0;

			for(int d = 0; d <n -1; d++) {
				for(int e = d+ 1; e<n; e++) {
					if(id[d] > id[e]) inv++;
				}
			}
			s[i].build(i,inv);
		}
		sort(s, s+m, comp);

		for(int i = 0; i<m; i++) {
		  cout<<s[i].seq<<'\n';

		}

	}

	return 0;
}
