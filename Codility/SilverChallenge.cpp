#include <bits/stdc++.h>
using namespace std;

int findAns(vector<int> &A, vector<int> &B) {
	int n = A.size();
	set<int> st;
	map<int, int> frequency;
	for (int i = 0; i < n; i++) {
		if (A[i] == B[i]) {
			frequency[A[i]]++;
		} else {
			frequency[A[i]]++;
			frequency[B[i]]++;
		}
		st.insert(A[i]);
		st.insert(B[i]);
	}

	int ans = 0;
	for (auto item : st) {
		ans = max(ans, frequency[item]);
	}
	return ans;
}


