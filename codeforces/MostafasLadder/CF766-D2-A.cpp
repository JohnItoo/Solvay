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

// TLE on large inputs.
int bruteforce() {
	string a, b;
	cin >> a >>b;
	if(b.length() != a.length()) {
		cout << max(b.length() , a.length()) << endl;
		return 0;
	}
	bool found = false; int ans = -1;
	for(int i = b.length(); i >= 1; i--) {
		vector<string> bees; vector<string> aas;
		//all substrings of b with length i
		for(int j = 0; j+i <=b.length(); j++) {
			char ch[i];
			for(int k = j; k <j+i; k++) {
              ch[k-j] = b[k];
			}
			string prog = string(ch);
			bees.pb(prog);
		}
	  forn(q, b.length()) {
         forn(t, b.length()) {
        	int ctt = 0; int j = q; char res[i];
        	while(ctt < i && j < b.length()) {
        		if(t == j) {
        			j++; continue;
        		}
        		res[ctt++] = b[j++];
        	}
        	if(ctt == i) { bees.pb(string(res));}
        }
    }

  // all substrings of a with length i
		for(int j = 0; j+i <=a.length(); j++) {
			char nch[i];
			for(int k = j; k <j+i; k++) {
              nch[k-j] = a[k];
			}
			string brog = string(nch);
			aas.pb(brog);
		}

			  forn(q, a.length()) {
         forn(t, a.length()) {
        	int ctt = 0; int j = q; char res[i];
        	while(ctt < i && j < a.length()) {
        		if(t == j) {
        			j++; continue;
        		}
        		res[ctt++] = b[j++];
        	}
        	if(ctt == i) { aas.pb(string(res));}
        }
    }
//find a substring of a that is not in b and if there is ans is i;
		forn(q , aas.size()) {
			string st = aas[q];
			if(find(bees.begin(), bees.end(), st) == bees.end()) {
				found = true;
                ans = i;
                break;
			}
		}
		if(found) break;
	}
	cout << ans << endl;
	
return 0;
}

int main() {
	string a,b;
	cin >> a >> b;
	if(a==b) cout << -1 << endl;
	else cout << max(a.length(), b.length()) << endl;

	return 0;
}
