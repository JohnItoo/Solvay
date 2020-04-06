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

int n = 0; int best = 0; int current=0; vi nums; vi done;  vi res;
void solution(int point) {
    if (point == n) {
        best = max(current, best);
        return;
    }
    for(int i = 0; i < n ; ++i)  {
            if(done[nums[i]]) continue;
            current += nums[i];
             best = max(current, best);
           int x = 0;
            done[nums[i]] =   nums[i+1] < n ? done[nums[i+1]] : x = nums[i-1] >= 0 ? done[nums[i-1]] : x= 1;
            solution(point + 1);
            done[nums[i]] =  n > nums[i+1] ? done[nums[i+1]] : x  = nums[i-1] >= 0 ? done[nums[i-1]] :  x = 0;
            current = 0;
    }
}
int main() {
    cin >> n;
    int i = 0;
    while( i < n) {
        int x = 0; cin >> x;
        nums.pb(x);
        done.pb(0);
        res.pb(0);
        i++;
    }
//    int news[n];
//     memset(news, 0, sizeof news);
    solution(1);
    cout << best;
    return 0;
}