#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &vec, int target , int start, int end) {

	while (start <= end) {

		int mid = start + (end - start) / 2;

		if (vec[mid] == target) {
			return mid;
		}
		if (mid > start && vec[mid - 1] == target) {
			return mid - 1;
		}
		if (mid < end && vec[mid + 1] == target) {
			return mid + 1;
		}
		if (vec[mid] > target) {
			end = mid - 2;
		}
		else {
			start = mid + 2;
		}
	}
	return -1;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, target;
	cin >> n >> target;

	vector<int>vec(n);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	int answer = solve(vec, target, 0, n - 1);

	cout << answer << endl;

	return 0;
}