#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    char arr[] = {'E', 'S', 'W', 'N'};

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int st = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (st == 3)
                    st = 0;
                else
                    st += 1;
            } else {
                if (st == 0)
                    st = 3;
                else
                    st -= 1;
            }
        }
        cout << arr[st] << endl;
    }
}