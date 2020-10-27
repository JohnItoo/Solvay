//============================================================================
// Name        : template.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
#define _CRT_SECURE_NO_DEPRECATE // suppress some compilation warning messages (for VC++ users)
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
// To simplify repetitions/loops, Note: define your loop style and stick with it!
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define forn(i,n) \
for (int i =0; i<(n); i++)
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000 // 2 billion
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); // useful to clear array of integers

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<string> vs;
	vector<string> lv;
	forn(i, (2 * n) - 2) {
		string x; cin >> x;
		vs.pb(x);
		lv.pb(x);
	}
	sort(vs.rbegin(), vs.rend());
	map<string, int> sf;
	map<string, int> pf;

	forn(i, vs.size()) {
		string pref = vs[i];
		vector<string> surfs;
		vector<string> prefs;
		forn(j, vs.size()) {
			if (i == j) continue;
			string s = vs[j];
			int pt = 0;
			bool vld = true;
			while (pt < pref.length() && pt < s.length()) {
				if (s[pt] != pref[pt]) {
					vld = false;
					break;
				}
				pt++;
			}
			if (vld) prefs.pb(s);
			else surfs.pb(s);
		}
		string lg = "";
		if (surfs.size() > 0) {
			sort(surfs.rbegin(), surfs.rend());
			lg = surfs[0];
		}

		bool svs = true;

		for (int sf = 1; sf < surfs.size(); sf++) {
			int q = lg.length() - 1;
			int z = surfs[sf].length() - 1;
			while (q >= 0 && z >= 0) {
				if (surfs[sf][z] != lg[q]) {
					svs = false;
					break;
				}
				q--;
				z--;
			}
			if (!svs) {
				break;
			}
		}
		string ans = "";
		if (svs) {
			int ppt = 0; int spt = 0;
			int lstrt = -1;
			while (ppt < pref.length() && spt < lg.length()) {
				if (pref[ppt] != lg[spt]) {
					spt = 0;
					ppt++;
					lstrt = -1;
				} else {
					if (lstrt == -1) lstrt = ppt;
					spt++;
					ppt++;
				}
			}
			if (lstrt != -1) {
				string sb = pref.substr(0, lstrt);
				ans = sb + lg;
			} else {
				ans = pref + lg;
			}
			// cout << ans << " ans \n";

			// for (string ss : surfs) {
			// 	sf[ss] = 1;
			// }
			// for (string pp : prefs) {
			// 	pf[pp] = 1;
			// }

			// for (string dq : lv) {
			// 	if (sf.find(dq) == sf.end()) {
			// 		ans.pb('P');
			// 	} else {
			// 		ans.pb('S');
			// 	}
			// }
			REP(ppq, 1, ans.length()) {
				string cr = ans.substr(0, ppq);
				pf[cr] = 1;
				// cout << cr << " pref\n";
			}
			string last = "";
			for (int ht = n - 1; ht >= 0; ht --) {
				// last.pb(ans[ht]);
				last = ans.substr(ht, n - ht);
				sf[last] = 1;
				// cout << last << " suff\n";
			}
			map<string, int> strongpref;
			map<string, int> strongsf;
			int spss = 0, spsf = 0, nutz = 0;
			vector<string> nut;
			for (string des : lv) {
				if (pf.find(des) == pf.end() && sf.find(des) != sf.end()) {
					if (strongsf.find(des) == strongsf.end()) {
						strongsf[des] = 1;
						spss++;
						// cout << des <<  " sf\n";
					}
					else {
						nut.pb(des);
						nutz++;
						// cout << des << " nuts\n";
					}
				} else if (pf.find(des) != pf.end() && sf.find(des) == sf.end()) {

					if (strongpref.find(des) == strongpref.end()) {
						strongpref[des] = 1;
						spsf++;
						// cout << des <<  " pf\n";
					}
					else {
						nut.pb(des);
						nutz++;
						// cout << des <<  " nuts\n";
					}
				} else {
					nut.push_back(des);
					nutz++;
					// cout << des <<  " nuts\n";

				}
			}
			string res = "";
			int peez = 0, ess = 0;
			for (string des : lv) {
				if (strongpref.find(des) != strongpref.end()) {
					peez++;
					res.pb('P');
				} else if (strongsf.find(des) != strongsf.end()) {
					ess++;
					res.pb('S');
				} else {
					int remp = (((n * 2) - 2) / 2) - peez;
					int rems = (((n * 2) - 2) / 2) - ess;
					int unusedp = spsf - peez;
					int unuseds = spss - ess;
					if (remp < rems && unuseds < rems) {
						res.pb('S');
						ess++;
					} else {
						res.pb('P');
						peez++;
					}
				}
			}
			cout << res << "\n";
			return 0;
		}

	}



	return 0;
}
