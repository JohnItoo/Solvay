//============================================================================
// Name        : template.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
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
	// to_string(int)

string trUpp(string s) {
	
  	transform(s.begin(), s.end(), s.begin(), ::toupper);
 return "";
}

int main() {
	int n, xorg, yorg; cin >> n >> xorg >> yorg;
	vector<ii> points(n);
	vector<bool> done(n, false);
	forn(i,n) {
		int x,y; cin >> x >> y;
		ii pr = mp(x,y);
		points[i]= pr;
	}

    int ans = 0;
    int tm = 0;

	while(n) {
		ii start = points[0];
		vi toremove;
		cout << tm << "\n";
		tm++;
		if(start.first == xorg) {
			toremove.pb(0);
			for(int i = 1; i <points.size(); i++) {
				if(points[i].first == xorg) {
					toremove.pb(i);
				}
			}
		}  else if(start.second == yorg) {
			toremove.pb(0);
			for(int i = 1; i < points.size(); i++) {
				if(points[i].second == yorg) {
					toremove.pb(i);
				}
			}
		} else {
			int slope = (points[0].first - xorg) / (points[0].second - yorg);
			toremove.pb(0);
			for(int i = 1; i < points.size(); i++) {
				if((points[i].second - yorg) == 0) continue;
				int currslope = (points[i].first - xorg) / (points[i].second - yorg);
				if(currslope == slope) {
					toremove.pb(i);
				}
			}

		}

        cout << "about to remove" << "\n";
        if(n - toremove.size() == 0) break;
		for(auto rem : toremove) {
			cout << rem << "\n";
			points.erase(points.begin() + rem);
			n-=1;
		}
		ans++;

	}
	if(n != 0) ans++;
	cout << ans << "\n";
	
return 0;
}
