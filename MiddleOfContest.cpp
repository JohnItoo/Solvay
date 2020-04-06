//============================================================================
// Name        : MiddleOfContest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;
string f, l;

int solve() {
	int h1, m1;
		scanf("%d:%d", &h1, &m1);
		int h2, m2;
		scanf("%d:%d", &h2, &m2);
		int t1 = h1 * 60 + m1;
		int t2 = h2 * 60 + m2;
		int t3 = (t1 + t2) / 2;
		printf("%02d:%02d\n", t3 / 60, t3 % 60);
		return 0;
}

int changingAchar() {
	int N, K = 0;
	string s;
	cin >> N >> K;

	char arr[N];
	cin >> s;

 cout << s;
	for(int i =0; i<N; ++i) {
		if(i==K-1) arr[i] = tolower(s[i]);
		else  arr[i] = s[i];
	}
   for(char a: arr) {
	   cout << a;
   }


	return 0;


}

int check() {
	string s;
	cin >> s;

	long first= int(s[0]) * 10 +  int(s[1]);
	long second = int(s[2]) * 10 + int (s[3]);

	if(first <= 12 && first >= 1) {
		if(first <= 12 && second >= 1) cout << "AMBIGUOUS";
		else cout << "MMYY";
	} else {
		if(second <= 12 && second >= 1 ) cout <<"YYMM";
		else cout << "NA";
	}
}

int main() {
	changingAchar();
}
