#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		long long x, y;
		cin >> x >> y;
		long long sq = max(x, y);
		if((sq & 1) == 0) sq += 1;
		vector<vector<long long>> grid(sq + 1, vector<long long>(sq + 1, 0));

		grid[0][0] = 1;
		grid[1][1] = 1;
		int a[4][2] = { {1, 0}, {0, 1}, { -1, 0}, {0, -1}}; //down, right, up, left
		long long done = 1;
		long long count = 1;
		long long i = 1; long long j = 2;
		long long last = 1;
		while (last < sq * sq) {
			// while (grid[i - 1][j] != 0 && j <= sq) {
			// 	last += 1;
			// 	grid[i][j] = last;
			// 	j += 1;
			// }

			if (i > sq  || i < 1 || j > sq || j < 1) break;
			last += 1;
			grid[i][j] = last;

			cout << "last " << last << "\n";
             
             while(i+1 <= sq && grid[i+1][j-1] != 0) {
             	last += 1;
             	i += 1;
             	grid[i][j] = last;
             }

//
			last += 1;
			i += 1;
			if (i > sq  || i < 1 || j > sq || j < 1) break;

			grid[i][j] = last;
			j -= 1;



			// if (i > sq  || i < 1 || j > sq || j < 1) break;

			// last += 1;
			// grid[i][j] = last;


			while (j  > 1 && last < (sq * sq)) {
				last += 1;
				grid[i][j] = last;
				j -= 1;
			}

			last += 1;
			grid[i][j] = last;

			last += 1;
			i += 1;
			grid[i][j] = last;

			cout << "here " << last << "\n";
			while (last < (sq * sq ) && j <= sq && grid[i - 1][j] != 0) {
				last += 1;
				j += 1;
				grid[i][j] = last;
			}

			last += 1;
			i -= 1;
			grid[i][j] = last;

            cout <<" New last " << last << "\n";
			while (last < (sq * sq) && i > 1) {
				last += 1;
				i -= 1;
				grid[i][j] = last;
			}

		
			if(last + 1 > sq * sq) break;
			j+=1;
			grid[i][j] = last;

			// j += 1;
			// last += 1;

			// if (i > sq  || i < 1 || j > sq || j < 1) break;


			// grid[i][j] = last;

			// while (last < (sq * sq) && i <= sq && grid[i][j - 1] != 0 ) {
			// 	last += 1;
			// 	i += 1;
			// 	grid[i][j] = last;
			// }

			// last += 1;
			// grid[i][j] = last;



			// if (i > sq  || i < 1 || j > sq || j < 1) break;


			// last += 1;
			// i += 1;
			// grid[i][j] = last;

		}
		for (int i = 0; i <= sq; i++) {
			for (int j = 1; j <= sq; j++) {
				cout << grid[i][j] << " ";
			}
			cout << "\n";
		}
		cout << grid[x][y] << "\n";

	}
}