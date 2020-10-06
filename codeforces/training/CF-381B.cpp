#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	set<int> st;
	multiset<int> ms;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		st.insert(a[i]);
		ms.insert(a[i]);
	}

	vector<int> result;

	for (int item : st) {
		result.push_back(item);
		auto it = ms.find(item);
		if(it != ms.end()) {
			ms.erase(it);
		}
	}

	sort(result.rbegin(), result.rend());

    set<int> nw;


    for(int item : ms) {
    	if(item >= result[0]) break;
    	if(nw.find(item) != nw.end()) {
    		continue;
    	}
    	nw.insert(item);
    }
    cout << nw.size() + result.size() << "\n";

    for(int ss : nw) {
    	cout << ss << " ";
    }

    for (int rs : result) {
    	cout << rs << " ";
    }
   cout << endl;




	return 0;
}