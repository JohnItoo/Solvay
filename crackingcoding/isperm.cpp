#include <iostream>
#include <map>
using namespace std;
int main() {
    string needle;
    string haystack;

    cin >> needle >> haystack;
    map<int, int> mp;
    int hl = haystack.length();
    int nl = needle.length();
    if(nl > hl) { cout << false; return 0;}

    for(int i=0; i<hl; i++) {
        auto it = mp.find(haystack[i] - 'a');
        if(it != mp.end()) {
            it->second += 1;
        } else {
            mp[haystack[i] - 'a'] = 1;
        }
    }
    bool isPerm = true;
    int occur[26];
    for(int i = 0; i<nl; ++i) {
        auto it = mp.find(needle[i] - 'a');
        if(it == mp.end()) { isPerm = false; break;}
        if(it->second < occur[needle[i] - 'a'] + 1) { isPerm = false; break;}
        occur[needle[i] - 'a'] += 1;
    }
    if(isPerm == false) { cout << isPerm; return 0;}

    auto it = mp.begin();
    while(it != mp.end()) {
        if(occur[it->first] != it->second) {
            isPerm = false;
            break;
        }
        it++;
    }
    cout << isPerm;
    return 0;
}