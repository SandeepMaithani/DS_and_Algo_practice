#include<bits/stdc++.h>
using namespace std;

int myceil(vector<long long int> &nums, long long int target, int start, int end) {

	int index = -1;

	while (start <= end) {

		int mid = start + (end - start) / 2;

		if (nums[mid] == target) {
			return mid;
		}
		if (nums[mid] > target) {
			index = mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return index;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	long long int target;

	cin >> n >> target;

	vector<long long int>nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	int answer = myceil(nums, target, 0, n - 1);

	cout << answer << endl;

	return 0;
}




