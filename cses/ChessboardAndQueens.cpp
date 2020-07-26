#include <bits/stdc++.h>
using namespace std;
char grid[8][8];
int ans = 0;

bool canplace(int n, int i) {
	if(grid[i][n] == '*') return false;

	bool can = true;
	for(int col = 0; col < 8 ; col++) {
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

    while(row < 8 && col < 8) {
    	if(grid[row][col] == 'K') {
        	can = false;
        	break;
        }
        row += 1;
        col += 1;

    }
    row = i; col = n;

    while(row >= 0 && col <8) {
    	if(grid[row][col] == 'K') {
        	can = false;
        	break;
        }
        col += 1;
        row -= 1;
    }

    while(row < 8 && col >= 0 ) {
    	if(grid[row][col] == 'K') {
        	can = false;
        	break;
        }
        col -= 1;
        row += 1;
    }


return can;
}
void search(int col) {
 if(col == 8) {
 	ans++;
 } else {
 	for(int row = 0; row < 8; row++) { 
 		if(canplace(col, row)) {
 			grid[row][col] = 'K';
 			search(col+1);
 			grid[row][col] = '.';
 		}
 	}
 }
}

int main() {
	for(int i = 0; i < 8; i++) {
		string s; cin >> s;
		for(int j = 0; j < 8; j++) {
			grid[i][j] = s[j];
		}
	}

	search(0);
	cout << ans << "\n";
}