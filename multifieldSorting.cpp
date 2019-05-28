//============================================================================
// Name        : multifieldSorting.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct team {
	char name[105];
	int wins, ties, loss,pt, score, invscore;
	void init() {
		wins, ties, loss,pt = 0;
	}

	void record(int a, int b) {
		if(a>b) wins++, pt += 3;
		else if(a < b) loss++;
		else ties++, pt += 1;
		score += a, invscore += b;

	}
};

bool cmp(team a, team b) {
	if(a.pt != b.pt) return a.pt > b.pt;
	if(a.wins != b.wins) return a.wins > b.wins;
	if(a.score - a.invscore != b.score - b.invscore) return (a.score - a.invscore) > (b.score - b.invscore);
	if(a.score != b.score) return a.score> b.score;
	if(a.ties + a.wins + a.loss != b.ties + b.wins + b.loss ) return a.ties + a.wins + a.loss < b.ties + b.wins + b.loss;
	return strcasecmp(a.name, b.name) <0;
}

int main() {
	int n,t,g;
	scanf("%d",&n);
	getchar();
    char name[105], buf[105];

	while(gets(name)) {
		map<string, int> R;
		scanf("%d", &t);
		getchar();

		team A[50];
		for(int i=0; i<t; ++i) {
        gets(A[i].name);
        A[i].init();
        R[A[i].name] = i;
		}
       scanf("%d", &g);
       getchar();
        while(g--) {
        	gets(buf);
        	char name1[50], name2[50];
        	int num1, num2;
            sscanf(buf, "%[^#]#%d@%d#%[^\n]", name1, &num1, &num2, name2); //team name 1#goals1@goals2#team name 2
            A[R[name1]].record(num1, num2);
            A[R[name2]].record(num2, num1);

        }

        sort(A, A+t, cmp);
        for(int i = 0; i < t; i++)
              printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
                      i+1, A[i].name, A[i].pt, A[i].wins+A[i].loss+A[i].ties,
                      A[i].wins, A[i].ties, A[i].loss, A[i].score-A[i].invscore,
                      A[i].score, A[i].invscore);


		n--;
	}
	return 0;
}
