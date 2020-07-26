#include <bits/stdc++.h>
using namespace std;
int sz = 4;
char grid[8][8];
int diag1[8];
int diag2[8];
int columns[8];
int ans = 0;

bool canplace(int n, int i) {
	if(grid[i][n] == '*') return false;

	bool can = true;
	for(int col = 0; col < sz ; col++) {
        if(grid[i][col] == 'K') {
        	can = false;
        	break;
        }
	}
    
    int row = i; int col = n;
    while(row >=0 && col >= 0) {
        if(grid[row][col] == 'K') {
        	can = false;
        	break;
        }
        row -= 1;
        col -= 1;
    }

    row = i; col = n;

    while(row < sz && col < sz) {
    	if(grid[row][col] == 'K') {
        	can = false;
        	break;
        }
        row += 1;
        col += 1;

    }
    row = i; col = n;

    while(row >= 0 && col <sz) {
    	if(grid[row][col] == 'K') {
        	can = false;
        	break;
        }
        col += 1;
        row -= 1;
    }

    while(row < sz && col >= sz ) {
    	if(grid[row][col] == 'K') {
        	can = false;
        	break;
        }
        col -= 1;
        row += 1;
    }


return can;
}
void search(int y) {
 if(y == sz) {
 	ans++;
 	return;
 } 
 cout << "here " << y << "\n"; 
 	for(int row = 0; row < sz; row++) {
 	     // if(!canplace(col, row)) continue;
 	      if(columns[row] == 1|| diag1[row+y] ==1 || diag2[row-y+sz-1] ==1 ) continue;
 	      columns[row] = 1; diag1[row+y] =1; diag2[row-y+sz-1] = 1;
 		
 			// grid[col][row] = 'K';
 			search(y+1);
 			// grid[row][col] = '.';
 			  columns[row] = 0; diag1[row+y] = 0; diag2[row-y+sz-1] = 0;
 			  // grid[y][row] = '.';
 		
 	}
 
}

int main() {
	// for(int i = 0; i < sz; i++) {
	// 	string s; cin >> s;
	// 	for(int j = 0; j < sz; j++) {
	// 		grid[i][j] = s[j];
	// 	}
	//}
   cin >> sz;
    memset(columns, 0, sizeof columns);
    memset(diag1, 0, sizeof diag1);
    memset(diag2, 0, sizeof diag2);
	search(0);
	cout << ans << "\n";
}