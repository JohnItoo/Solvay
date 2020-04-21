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

string flip(string& ref, int& len) {
    // char flipped[len];
    // int j = 0;
    // for(int i = len -1; i>=0; i--) {
    //     flipped[j++] = ref[i];
    // }
    // string ans = flipped;
    // cout << ref << " " << ans << "\n";
    // return ans;
    string flipped = ref;
     reverse(flipped.begin(), flipped.end());
     return flipped;
}

bool isPalindrome(string& ref, int&  len) {
   string flipped = flip(ref, len);
   return flipped == ref;
}

int main() {

    int n, m;
    int isPalind, count, palidx;
    cin >> n >> m;
    vector<pair<int,int> > vp;
    string strs[n]; int done[n];
    map<string, int> dict;
    string finalString;

    forn(i, n) {

    string at;
    cin >> at;
    strs[i] = at;
    dict[at] = i;
    }

    forn(i, n) {
        if(done[i] == 1)  continue;

       if(isPalindrome(strs[i], m) && isPalind != 1) {
           isPalind = 1;
           palidx = i;
        //    cout << "is palindrome" <<strs[i] << "\n";
           continue;
       }

        string flipped = flip(strs[i], m);

        auto it = dict.find(flipped);
        

        if(it != dict.end()) {
            // cout << flipped << "found\n";
            done[it->second] = 1;
            done[i] = 1;
            count++;
            vp.pb(make_pair(i, it->second));
        }
    }

     int len = isPalind ? (count * 2) + 1 : count * 2;
        for(int j = 0; j<len; ++j) {
            if(isPalind && j == count) {
                // cout <<"added to final string /n";
                finalString += strs[palidx];
            } else if(j< count) {
                finalString += strs[vp[j].first];
            } else { //count > i
               int curr = isPalind ? j - count - 1 : j- count;
               finalString +=  strs[vp[curr].second];
            }
        }
   cout << m * len << "\n";
   cout << finalString;
    
return 0;
}
