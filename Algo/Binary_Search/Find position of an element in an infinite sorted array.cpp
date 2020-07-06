#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int>& nums, int target, int start, int end) {

	while (start <= end) {

		int mid = start + (end - start) / 2;

		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] > target) {
			end = mid - 1;
		}
		else {
			start = start + 1;
		}
	}

	return -1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, target;

	cin >> n >> target;

	int start = 0;
	int end = 1;

	vector<int>nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	while (end < target) {
		start = end;
		end = 2 * end;
	}

	int answer = binary_search(nums, target, start, end);

	cout << answer << endl;

	return 0;
}