// Problem: E - Stronger Takahashi
// Contest: AtCoder - AtCoder Beginner Contest 213
// URL: https://atcoder.jp/contests/abc213/tasks/abc213_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//============================================================================
// Name        : template.cpp
// Author      :   $%U%$   
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
#define _CRT_SECURE_NO_DEPRECATE  // suppress some compilation warning messages
                                  // (for VC++ users)
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
// To simplify repetitions/loops, Note: define your loop style and stick with
// it!
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define REP(i, a, b) \
    for (int i = int(a); i <= int(b); i++)  // a to b, and variable i is local!
#define forn(i, n) for (int i = 0; i < (n); i++)
#define TRvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000  // 2 billion
// If you need to recall how to use memset:
#define MEMSET_INF 127      // about 2B
#define MEMSET_HALF_INF 63  // about 1B
// memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path
// distances memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP
// memoization table memset(arr, 0, sizeof arr); // useful to clear array of
// integers
char grid[505][505];

int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<ii> mv = { {2, -1}, {2, 0}, {2, 1}, {1, -2}, {1, -1}, {1, 0}, {1,1},
 {1, 2}, {0, -2}, {0, -1}, {0, 0}, {0,1}, {0,2}, {-1, -2}, {-1, -1}, {-1, 0}, {-1, 1}, {-1, 2},
 {-2, -1}, {-2, 0}, {-2, 1} };
int h, w;
set<int> tg;


int main() {
    ios::sync_with_stdio(false);
    
    cin.tie(0);
    
    cin >> h >> w;
    REP(i, 1, h) {
    	string s; cin >> s;
    	REP(j, 1, w) {
    		grid[i][j] = s[j-1];
    	}
    }
    vector<vector<int> >dp(505, vector<int>(505, 1e9));
    dp[1][1] = 0;
    
    priority_queue<vi> q;
    q.push({0, 1,1});
    set<ii> visited;
    
    while(!q.empty()) {
    	vi tp = q.top(); q.pop();
    	ii top = {tp[1], tp[2]};
    	
    	if(visited.find(top) != visited.end()) continue;
    	visited.insert(top);
    	
    	for(int l = 0; l < mv.size(); l++) {
    		int nr = top.x+ mv[l].x;
    		int nc = top.y + mv[l].y;
    		
    		if(nr < 1 || nr > h || nc < 1 || nc > w) continue;
    	
    		int cost =( grid[nr][nc] == '.' && abs(top.x - nr) + abs(top.y - nc) <= 1) ? 0 : 1;
    		
   
    		
    		if(dp[top.x][top.y] + cost < dp[nr][nc]) {
    			
    			dp[nr][nc] = dp[top.x][top.y] + cost;
    			q.push({-dp[nr][nc], nr, nc});
    		} 
    	}
    }
    cout << dp[h][w];
    
    return 0;
}
