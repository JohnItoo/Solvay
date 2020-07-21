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

//AC but spent a lot of time.
int longCrappyway() {
	int n; cin >> n; int a[n];
    forn(i,n) cin >> a[i];

    int dn[1000005];

    vi wtn(n);


    int current = 0;  bool cmpt = false; int stckd = 0;
    for(int i = n; i>= 1; i--) {
    	
    	if(dn[i] == 1) continue;
        while(current <n) {
           // wtn.pb(a[current]);
        	dn[a[current]] = 1;
            // cout << a[current] << " is i? " << n <<endl;
        	if(a[current] == i) {
        	// cout << i << " This is i" << endl; 
        		cmpt = true;
        		stckd = i;
        	} else {
        	cout << "   " << endl;
        }
          	current++;
          	if(cmpt) break;
        }
        if(cmpt) {
        	cmpt = false;
             // sort(wtn.begin(), wtn.end());
             // int x = wtn[wtn.size() -1];
              cout << stckd << " ";
             for(int q = stckd-1; q > 0; q--) {
             	if(dn[q] != 1) break;
             	cout << q << " ";
             }
             cout << endl;

        } 
    }
	
return 0;
}

int main()  {
	int dn[1000005];
	int n; cin >> n;
	int exp = n;
	forn(i,n) {
		int x; 
		cin >> x;
		dn[x] = 1;
		while(exp > 0 && dn[exp] == 1) {
          cout << exp << " ";
          exp--;
		}
		cout << " " << endl;
	}
}

