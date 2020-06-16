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
	string s; string t;
	cin >> s >> t;
	int n = (s.length() * 2)  + 2;
	float g1[s.length()+1][n];
	float g2[s.length()+1][n];
	memset(g1, (float) 0 , sizeof g1);
	memset(g2, (float) 0 , sizeof g2);

    int start = s.length()+1;
    int end = 0;
	forn(i, s.length()) {
       if(s[i] == '+') {
         g1[i+1][start+1] = (float) 1;
         start += 1;
       } else {
         g1[i+1][start-1] = (float) 1;
         start -= 1;
       }
       if(i == s.length() -1) end = start;
	}
	REP(i, 1, s.length()) {
		REP(j, 1, n-1) {
			cout << g1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;


    start = s.length()+1;
    float curr = (float) 1;
	forn(i, s.length()) {
      if(t[i] == '+') {
      	cout << " + ";
      	g2[i+1][start+1] = curr;
      	start += 1;
      } else if(t[i] == '-') {
      	cout << " - ";
      	 g2[i+1][start-1] = curr;
         start -= 1;
      } else {
      	cout << " ? ";
      	 curr /= (float) 2;
      	 g2[i+1][start+1] = curr;
      	 g2[i+1][start-1] = curr;
      }
	}
	cout << endl;
		REP(i, 1, s.length()) {
		REP(j, 1, n-1) {
			cout << g2[i][j] << " ";
		}
		cout << endl;
	}

	cout << min(g1[s.length()][end], g2[s.length()][end]) << endl;
	
return 0;
}
