#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    if(n > 26) cout << false;
    int arr[26];
    bool isUnq = true;
    for(int i=0; i<n; ++i) {
        if(arr[s[i]- 'a'] == 1) {
            isUnq = false; break;
        }
        arr[s[i]- 'a'] = 1;
    }
    cout << isUnq;
    return 0;
}