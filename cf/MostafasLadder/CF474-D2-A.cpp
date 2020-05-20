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
#include <string.h> // for memset in CF judge.
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
	string a = "qwertyuiop";
	string b = "asdfghjkl;";
	string c = "zxcvbnm,./";
	vector<char> va; 	vector<char> vb; 	vector<char> vc; char arr[1];
	for(auto x : a) {
		va.pb(x);
	}
	for(auto x : b) {
		vb.pb(x);
	}
		for(auto x : c) {
		vc.pb(x);
	}
   string d; cin >> d;
   string res; cin >> res;
	string ans = "";
	forn(i, res.length()) {
	     auto it = find(va.begin(), va.end(), res[i]);
	     if ( it != va.end()) {
	     	int idx = -1;
	     	forn(j, va.size()) {
              if(va[j] == res[i]) {
              	idx = j;
              	break;
              }
	     	}
             if(d == "R") ans += va[idx -1];
             else ans += va[idx+1];
             continue;
	     }
	     it =  find(vb.begin(), vb.end(), res[i]);
       if ( it != vb.end()) {

       	    int idx = -1;
	     	forn(j, vb.size()) {
              if(vb[j] == res[i]) {
              	idx = j;
              	break;
              }
	     	}
             if(d == "R") ans += vb[idx -1];
             else ans += vb[idx+1];
             continue;
	     }

	      it =  find(vc.begin(), vc.end(), res[i]);
       if ( it != vc.end()) {
       	 int idx = -1;
	     	forn(j, vc.size()) {
              if(vc[j] == res[i]) {
              	idx = j;
              	break;
              }
	     	}
             if(d == "R") ans += vc[idx -1];
             else ans += vc[idx+1];
	     }
	}
	cout << ans << endl;
	
return 0;
}
