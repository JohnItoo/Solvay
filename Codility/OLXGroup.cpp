// you can use includes, for example:
// #include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int solution(vector<int> &juice, vector<int> &capacity) {
    // write your code in C++14 (g++ 6.2.0)
    int n = juice.size();
    vector<pair<int, int> > juicePairs;
    vector<pair<int, int> > contPairs;
    for (int i = 0; i < n; i++) {
        pair<int, int> curr = make_pair(juice[i], i);
        juicePairs.push_back(curr);
        capacity[i] -= juice[i];
        pair<int, int> cunt = make_pair(capacity[i], i);
        contPairs.push_back(cunt);
    }
    sort(juicePairs.begin(), juicePairs.end());
    sort(contPairs.rbegin(), contPairs.rend());
    int result = 1;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[juicePairs[i].second] = i;
    }
    int juiceIt = 0;
    int contIt = 0;
    long long pref = 0;
    long long usedPref = 0;
    int curr = 0;
    while (juiceIt < n && contIt < n) {
        while (juiceIt < n) {
            if (juicePairs[juiceIt].second == contPairs[contIt].second) {
                pref = (long long) (pref + juicePairs[juiceIt].first);
                juiceIt++;
                continue;
            }
            if ((long long) (usedPref + juicePairs[juiceIt].first) > contPairs[contIt].first) {
                break;
            }
            curr = juiceIt + 1 + 1;
            usedPref = (long long) (usedPref + juicePairs[juiceIt].first);
            pref = (long long) (pref + juicePairs[juiceIt].first);
            if (mp[contPairs[contIt].second] <= juiceIt) {
                curr--;
            }
            juiceIt++;
        }
        result = max(curr, result);
        contIt++;

        if (usedPref == 0 && juiceIt == 0) {
            return 1;
        }
        usedPref = pref;
        while (contIt < n) {
            if (mp[contPairs[contIt].second] <= juiceIt - 1) {
                usedPref -= juice[contPairs[contIt].second];
                if (usedPref <= contPairs[contIt].first) {
                    curr = juiceIt;
                    break;
                } else {
                    contIt++;
                }
            } else {
                if (pref <= contPairs[contIt].first) {
                    curr = juiceIt + 1;
                    break;
                } else {
                    contIt++;
                }
            }
        }
        result = max(curr, result);
        if (contIt < n && mp[contPairs[contIt].second] <= juiceIt - 1) {
            usedPref = pref - juice[contPairs[contIt].second];
        }
    }
    return result;
}