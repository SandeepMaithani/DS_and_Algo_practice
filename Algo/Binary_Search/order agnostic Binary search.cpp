#include<bits/stdc++.h>
using namespace std;

int bsearch(vector<int> &vec, int target, int start, int end) {

	while (start <= end) {

		int mid = start + (end - start) / 2;

		if (vec[mid] == target) {
			return mid;
		}

		if (vec[mid] > target) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return -1;
}

int revbsearch(vector<int> &vec, int target, int start, int end) {

	while (start <= end) {

		int mid = start + (end - start) / 2;

		if (vec[mid] == target) {
			return mid;
		}

		if (vec[mid] > target) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return -1;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, target, ind;
	cin >> n >> target;

	vector<int>vec(n);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	if (n == 1) {
		if (vec[0] == target) {
			cout << "Element found at : " << 0 << endl;
		}
		else {
			cout << "Element not found " << endl;
		}
		return 0;
	}

	if (vec[0] <= vec[n - 1]) {
		ind = bsearch(vec, target, 0, n - 1);
	}
	else {
		ind = revbsearch(vec, target, 0, n - 1);
	}

	if (ind != -1) {
		cout << "Element found at : " << ind << endl;
	}
	else {
		cout << "Element not found " << endl;
	}

	return 0;
}