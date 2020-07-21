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
	char grid[105][105]; map<string, string> vstd;
    int rows, cols = 0;
    int mvc[4] = {1, -1,0, 0}; int mvr[4] = {0, 0, 1, -1};
string trUpp(string s) {
	
  	transform(s.begin(), s.end(), s.begin(), ::toupper);
 return "";
}
// void bfs(int r, int c) {

//   queue<ii> q;
//   q.push(mp(r,c));
//    string nw = "";
//   while(!q.empty()) {
//   	ii pr = q.poll(); q.pop();
//   	int rw = pr.first; int cl = pr.second;
//   	if(vstd.find(string(rw) + string(cl)) != vstd.end()) continue;
//   	 vstd[string(rw) + string(cl)] = "a";
  	 
//   	forn(i, 4) {
//       int nrw = rw + mvr[i]; int ncl = cl + mvc[i];
//       if(nrw < 1 || nrw > rows || ncl < 1 || ncl > cols) continue;
//       if(grid[nrw][ncl] != "." && grid[])
//   	}

//   }
// } 

int main() {
	int n,m; cin >> n >>m;
	char s; cin >> s;
	ii beg; ii end; int ct = 0;
	REP(i,1,n) {
    string x=""; cin >> x;

		REP(j, 1,m) {

			grid[i][j] = x[j-1];
			if(x[j-1] == s && ct == 0) {beg = mp(i,j); ct = 1;}
			else if(x[j-1] == s && ct) end = mp(i,j); 
		}
	}
    // cout << beg.first << " " << beg.second<< endl;
    //     cout << end.first << " " << end.second<< endl;
  set<char> ss; 
  
  for(int i = beg.first; i <= end.first; ++i) {
    for(int j = beg.second; j<end.second; ++j) {
      if(grid[i][j] != s) continue;
      for(int q = 0; q <4; q++) {
        int nr = i+ mvr[q]; int nc = j+mvc[q];
        if(nr < 1 || nr > n || nc < 1  || nc > m || grid[nr][nc] == '.') continue;
        ss.insert(grid[nr][nc]);
      }

    }
  }

  cout << ss.size() << endl;


	
return 0;
}
