 #include <bits/stdc++.h>
using namespace std;

int main() {

int n;
cin >> n;
vector<int> a(n);

int i = 0; int j = n-1;
int lef = 1; int curr = 1;
if((n & 1 )== 0) n += 1;
while(i < j) { 
  if(lef) {
     lef = 0;
     a[i] = max(curr, n -curr);
     a[j] = min(curr, n-curr);
  } else {
     lef = 1;
     a[i] = min(curr, n-curr);
     a[j] = max(curr, n-curr);
  }
  i++; j--;
  curr++;
}
if(n & 1 == 1) a[i] = n;

bool is = true;
for(int i = 0; i < n-1; i++) {
	if(abs(a[i] -a[i+1]) <=1) {
		is = false;
		break;
	}
}
if(is) {
	for(int i = 0; i < n ; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
} else {
	cout << "NO SOLUTION\n";
}

	return 0;

}