//============================================================================
// Name        : template.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define _CRT_SECURE_NO_DEPRECATE // suppress some compilation warning messages (for VC++ users)
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
// To simplify repetitions/loops, Note: define your loop style and stick with it!
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define forn(i,n) \
for (int i =0; i<(n); i++)
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000 // 2 billion
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); // useful to clear array of integers

int TC,P,Q;
int solve() {
	return 0;
}
bool comp(pair<int, int>one, pair<int,int>two) {
	if(one.x != two.x) return one.x <two.x;
	 return one.y <two.y;
}
bool equal(pair<int, int>one, pair<int,int>two) {
	return (one.first == two.first && one.second == two.second);
}
int main() {
	scanf("%d", &TC);
	int ks = 0;
	while(TC--) {
		ks++;
		scanf("%d%d", &P,&Q);
		int p = P;
		vector<pair <int,int> > vp;
		while(p--) {
			int a, b;
			char D;
			scanf("%d %d %c", &a,&b,&D);

		    if(D == 'N') vp.pb(mp(a, b+1));
		    else if( D=='E') vp.pb(mp(a+1, b));
		    else if( D=='W') vp.pb(mp(a-1, b));
		    else vp.pb(mp(a, b-1));

		}
		sort(vp.begin(), vp.end(), comp);
		pair<int, int> ans;
		int sol = 1;
		int idx = 1;
		ans = vp[0];
		for(int i = 0; i< vp.size() -1; ++i) {
//			cout << vp[i].x <<" "<< vp[i].y<<"\n";
			if(equal(vp[i], vp[i+1])) {
				idx++;
			} else {
				if(idx > sol) {
					ans = vp[i];
					sol = idx;
			}
				idx = 1;
			}
		}
		if(P == 1 && ans.x > 0) ans.x= 0;
		  cout<<"Case #"<<ks<<": "<< ans.x <<" "<< ans.y <<endl;

	}
return 0;
}
