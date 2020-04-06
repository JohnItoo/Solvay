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
int n, best, result;
char board[4][4];

void printBoard() {
	forn(i,n) {
		forn(j,n) {
			cout << board[i][j];
		}
		cout << endl;
	}
	cout <<endl;
}

bool isOpenPosition(int row, int col) {
	//iterate through row , iterate through columns if rook is found return false. i
	for(int i = row + 1; i< n; ++i) {
		if(board[i][col] == 'X') {
			break;
		}
		if(board[i][col] == '*') {
			return false;
		}

	}
	for(int i = row - 1; i >= 0; --i) {
			if(board[i][col] == 'X') {
				break;
			}
			if(board[i][col] == '*') {
				return false;
			}

		}
	for(int j = col + 1; j< n; ++j) {
		if(board[row][j] == 'X') {
			break;
		}
		if(board[row][j] == '*') {
			return false;
		}

	}

	for(int j = col-1; j >= 0; --j) {
		if(board[row][j] ==  'X') {
			break;
		}
		if(board[row][j] == '*') {
			return false;
		}
	}

	 return true;

}

bool canPlace(int row, int col) {
	return isOpenPosition(row, col) && board[row][col] == '.';
}

void search(int row, int col) {

 forn(i,4) {
	 forn(j,4) {
		 if(canPlace(i,j)) {
			 result++;
			 best = max(best, result);
		 	board[i][j] = '*';
//		 	printBoard();
		 	search(i, j+1);
		 	result--;
		 	board[i][j] = '.';
		 }
	 }
 }



}
int main() {
	 string input;

	  while (cin >> n) {
	    if (n == 0)
	      break;

	    cin.ignore(100, '\n');

	    for (int i = 0; i < n; i++) {
	      getline(cin, input);

	      for (int j = 0; j < n; j++) {
	    	   board[i][j] = input[j];
	          cout << input[j];
	      }


	    }

//	    best = 0;
//	    result = 0;
//	    search(0, 0);
//
//	    cout << best << endl;
	  }
}
