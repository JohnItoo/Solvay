//============================================================================
// Name        : PartyTree.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<algorithm>
using namespace std;
int n;

//int fgr(int gb[], int D, int n, int ans) {
//	if(D <= 0) return ans;
//	for (int i = n; i >= 2; ++i) {
//		if (gb[i -1] != gb[i] - 1) {
//			gb[i]-= 1;
//			ans++;
//			if(i == 2 || gb[i-1] == gb[i] - 2)  D -= 1;
//			else D -= 2;
//			fgr(gb, D,n,ans);
//		}
//	}
//	return 0;
//}
int main() {
	string s ;
	int arr[2000005];

	int en = 1;
    int si = 1;
    int Dm = 0;
    int P ;
    int sol = 0;
	getline(cin, s);
	cin >> P;
	cout <<"here";
	for (int i = 0; i <s.length(); ++i) {
		if(s[i] == 'S') arr[si++] = i+1 ,Dm += en , cout << Dm;
		else en *= 2;

	}
	cout << Dm;
	int gee = Dm-P ;
//    int itr = fgr(arr, gee, s.length(), 0);
//    cout << itr;

//	int ans = sol /2 + (sol - 2 %2);
//
//	cout << ans;
}
