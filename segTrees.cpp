//============================================================================
// Name        : segTrees.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
#include <vector>
typedef std::vector<int> vi;
using namespace std;
// Segment Tree Library
// The segment tree is stored like a heap array

#define RANGE_SUM 0
#define RANGE_MIN 1
#define RANGE_MAX 2

vi segment_tree;
void init_segment_tree(int N) { // if original array size is N,
// the required segment_tree array length is 2*2^(floor(log2(N)) + 1);

	int length = (int) (2 * pow(2.0, floor((log((double) N) / log(2.0)) + 1)));
	segment_tree.resize(length, 0); // resize this vector and fill with 0
}

void build_segment_tree(int code, int A[], int node, int b, int e) {
	if (b == e) { // as b == e, either one is fine
		if (code == RANGE_SUM)
			segment_tree[node] = A[b]; // store value of this cell
		else
			segment_tree[node] = b; // if RANGE_MIN/MAXIMUM, store index
	} else { // recursively compute the values in the left and right subtrees
		int leftIdx = 2 * node, rightIdx = 2 * node + 1;
		build_segment_tree(code, A, leftIdx, b, (b + e) / 2);
		build_segment_tree(code, A, rightIdx, (b + e) / 2 + 1, e);
		int lContent = segment_tree[leftIdx], rContent = segment_tree[rightIdx];
		if (code == RANGE_SUM) // make this segment contains sum of left and right subtree
			segment_tree[node] = lContent + rContent;
		else { // (code == RANGE_MIN/MAXIMUM)
			int lValue = A[lContent], rValue = A[rContent];
			if (code == RANGE_MIN)
				segment_tree[node] = (lValue <= rValue) ? lContent : rContent;
			else
				segment_tree[node] = (lValue >= rValue) ? lContent : rContent;
		}
	}
}

int query(int code, int A[], int node, int b, int e, int i, int j) {
	if (i > e || j < b)
		return -1; // if the current interval does not intersect query interval
	if (b >= i && e <= j)
		return segment_tree[node]; // if the current interval is inside query interval
// compute the minimum position in the left and right part of the interval
	int p1 = query(code, A, 2 * node, b, (b + e) / 2, i, j);
	int p2 = query(code, A, 2 * node + 1, (b + e) / 2 + 1, e, i, j);
// return the position where the overall minimum is
	if (p1 == -1)
		return p2; // can happen if we try to access segment outside query
	if (p2 == -1)
		return p1; // same as above
	if (code == RANGE_SUM)
		return p1 + p2;
	else if (code == RANGE_MIN)
		return (A[p1] <= A[p2]) ? p1 : p2;
	else
		return (A[p1] >= A[p2]) ? p1 : p2;
}

void update(int code, int A[], int node, int upd) {
	if (node < 1)
		return;
	segment_tree[node] = upd;
	int p, q = 0;
	p = node;
	if (p + 1 / 2 == p / 2)
		q = p + 1;
	else
		q = p - 1;

	if (code == RANGE_SUM)
		upd = q + p;
	else if (code == RANGE_MIN)
		upd = segment_tree[q] < segment_tree[p] ?
				segment_tree[q] : segment_tree[p];
	else
		upd = segment_tree[q] > segment_tree[p] ?
				segment_tree[q] : segment_tree[p];

	update(code, A, node / 2, upd);


}

int main() {
	int A[] = { 8, 7, 3, 9, 5, 1, 10 };
	int B[] = { 10, 2, 47, 3, 7, 9, 1, 98, 21, 37 };
	init_segment_tree(10);
	build_segment_tree(RANGE_MIN, B, 1, 0, 9);
//printf("%d\n", query(RANGE_MIN, A, 1, 0, 9, 3, 8)); // answer is index 2
	for (auto a : segment_tree) {
		printf("%d\n", a); // answer is index 2
	}

	cout << "new \n";

	update(RANGE_MIN, B,7,);

	for (auto a : segment_tree) {
		printf("%d\n", a); // answer is index 2
	}

	return 0;
}
