#include <algorithm>
#include <iostream>
using namespace std;

int a, b, c, d,ans;
int main() {

cin >> a >> b >> c >> d;

int arr[] = {a,b,c};
sort(arr, arr +3);
a = arr[0];
b = arr[1];
c = arr[2];

int d1 = d - (b - a);
if (d1 >= 0) ans += d1;
else d1 = 0;

int d2 = d - (c - b);
if (d2 >= 0) ans += d2;
else d2 = 0;

int d3 = d  - ((c + d2) - (a - d1));
if(d3 >= 0) ans += d3;

cout << ans;


return 0;
}
