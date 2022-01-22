// Problem: 1002. Phone Numbers
// Contest: Timus - Central European Olympiad in Informatics 1999
// URL: https://acm.timus.ru/problem.aspx?space=1&num=1002
// Memory Limit: 64 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//============================================================================
// Name        : BXK
// Author      : Template
// Version     :
// Copyright   : Who was here
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
vector<int> vals = {2, 2, 2, 3, 3, 3, 4, 4, 1, 1, 5, 5,6,6,0, 7, 0,7,7,8,8,8,9,9,9,0};
int mx = INF;
vector<string> backtrack(set<string>& dicts, 
int l, string s, map<int, vector<string>>& dn) {
	if(l == s.size()) {
		return {};
	}
	if(dn.find(l)  != dn.end()) {
		return dn[l];
	}
	
	map<int, vector<string> > cand;
	int ans = INF;
	for(int i = l; i < s.size(); i++) {
		string hr = s.substr(l, (i - l) + 1);
		if(dicts.find(hr) == dicts.end()) continue;

		vector<string> remnant = backtrack(dicts,  i+1, s, dn);
		if(remnant.size() >= 1 && remnant[0] == "-1") continue;
		
		if(remnant.size() + 1 < ans) {
			cand[remnant.size() + 1].pb(hr);
			ans = remnant.size() + 1;
            cand[remnant.size() + 1].insert(cand[remnant.size() + 1].end(),
             remnant.begin(), remnant.end());
		}
	}
   if(ans == INF) {
   	 dn[l] = {"-1"};
   } else {
   	 dn[l] = cand[ans];
   }
   return dn[l];
}
void solve() {
  string s;
  while(cin >> s && s != "-1") {
  
  	int n; cin >> n;
  	set<string> dicts;
  	map<string, string> mpp;
  	while(n--) {
  		string curr; cin >> curr;
  		string dict;
  		for(int i = 0; i < curr.size(); i++) {
  			int val = vals[curr[i] - 'a'];
  			char c = val + '0';
  			dict.pb(c);
  		}
  		mpp[dict] = curr;
  		dicts.insert(dict);
  	}
  	
  	vector<string> ans;
  	 mx = INF;
  	 map<int, vector<string>> dn;
  vector<string> res =	backtrack(dicts,0, s,dn);
  	
  	if(res.size() == 0 || res[0] == "-1") {
  		cout << "No solution.";
  	} else {
  		for(string xx : res) {
  			cout << mpp[xx] << " ";
  		}
  	
  	}
  	cout <<endl;
  	
  }
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
int tc = 1;
//cin >> tc;
int count = 1;
while(tc--) {

 //cout << "Case #" << count << ": "; //CODEJAM/KICKSTART
 count++;
 solve();
}
return 0;
}
