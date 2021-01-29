#include <bits/stdc++.h>
using namespace std;
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> a;
        multiset<int> msi;
        map<int, int> freq;
        int ct = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x < k) {
                freq[x]++;
                a.push_back(x);
                msi.insert(x);
            } else {
                ct++;
            }
        }
        sort(a.begin(), a.end());
       for(int i = 0; i < a.size(); i++) {
           int curr = a[i];
           if(freq.find(curr) == freq.end()) continue;
           if(freq[curr] == 1) freq.erase(curr);
           else freq[curr]--;
           int needs = k- curr;
          multiset<int>::iterator it = msi.lower_bound(needs);
          if(it == msi.end()) continue;
          int found = *it;

          if(freq[found] == 1) freq.erase(found);
          else freq[found]--;
          cout << curr << " " << found << endl;
          ct++;
          msi.erase(it);
          auto jt =  msi.find(curr);
          msi.erase(jt);
       }
       cout << ct << endl;

    }
}