/ you can use includes, for example :
// #include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &H) {
    // write your code in C++14 (g++ 6.2.0)
    priority_queue<int> pq;
    map<int, int> mp;
    map<int, int> fd;

    int maxel = *max_element(H.begin(), H.end());
    int len = H.size();
    long long ans = maxel * len;

    for (int i = 0; i < len; i++) {
        int curr = H[i];
        if (mp.find(curr) == mp.end()) {
            pq.push(curr);
        }
        mp[curr]++;
    }

    int seenmax = H[0];

    for (int i = 1; i < len; i++) {
        seenmax = max(seenmax, H[i - 1]);
        int curr = H[i - 1];

        auto it = mp.find(curr);

        if (it->second == 1) {
            fd[curr]++;
        } else {
            mp[curr]--;
        }

        int topQ = 0;
        stack<int> st;
        while (!pq.empty()) {
            int dz = pq.top(); pq.pop();
            if (fd.find(dz) == fd.end()) {
                if (topQ == 0) {
                    topQ = dz;
                }
                st.push(dz);
            }
        }
        while (!st.empty()) {
            int tp = st.top(); st.pop();
            pq.push(tp);
        }

        long long val = (seenmax * i)  + ((len - i) * topQ);
        ans = min(val, ans);
    }
    return ans;
}
