#include <bits/stdc++.h>
using namespace std;

// Program to find next smaller element for all elements in
// an array, using segment tree and binary search

vector<int> seg_tree;

// combine function for combining two nodes of the tree, in
// this case we need to take min of two
int combine(int a, int b) { return min(a, b); }

// build function, builds seg_tree based on vector parameter
// arr
void build(vector<int>& arr, int node, int tl, int tr)
{
	// if current range consists only of one element, then
	// node should be this element
	if (tl == tr) {
		seg_tree[node] = arr[tl];
	}
	else {
		// divide the build operations into two parts
		int tm = (tr - tl) / 2 + tl;

		build(arr, 2 * node, tl, tm);
		build(arr, 2 * node + 1, tm + 1, tr);

		// combine the results from two parts, and store it
		// into current node
		seg_tree[node] = combine(seg_tree[2 * node],
								seg_tree[2 * node + 1]);
	}
}

// query function, returns minimum in the range [l, r]
int query(int node, int tl, int tr, int l, int r)
{
	// if range is invalid, then return infinity
	if (l > r) {
		return INT32_MAX;
	}

	// if range completely aligns with a segment tree node,
	// then value of this node should be returned
	if (l == tl && r == tr) {
		return seg_tree[node];
	}

	// else divide the query into two parts
	int tm = (tr - tl) / 2 + tl;

	int q1 = query(2 * node, tl, tm, l, min(r, tm));
	int q2 = query(2 * node + 1, tm + 1, tr, max(l, tm + 1),
				r);

	// and combine the results from the two parts and return
	// it
	return combine(q1, q2);
}

// --------Segment Tree Ends Here-----------------

void printNSE(vector<int> arr, int n)
{
	seg_tree = vector<int>(4 * n);

	// build segment tree initially
	build(arr, 1, 0, n - 1);

	int q, l, r, mid, ans;
	for (int i = 0; i < n; i++) {
		// binary search for ans in range [i + 1, n - 1],
		// initially ans is -1 representing there is no NSE
		// for this element
		l = i + 1;
		r = n - 1;
		ans = -1;

		while (l <= r) {
			mid = (r - l) / 2 + l;
			// q is the minimum element in range [l, mid]
			q = query(1, 0, n - 1, l, mid);

			// if the minimum element in range [l, mid] is
			// less than arr[i], then mid can be answer, we
			// mark it, and look for a better answer in left
			// half. Else if q is greater than arr[i], mid
			// can't be an answer, we should search in right
			// half

			if (q < arr[i]) {
				ans = arr[mid];
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}

		// print NSE for arr[i]
		cout << arr[i] << " ---> " << ans << "\n";
	}
}

// Driver program to test above functions
int main()
{
	vector<int> arr = { 11, 13, 21, 3 };
	printNSE(arr, 4);
	return 0;
}


