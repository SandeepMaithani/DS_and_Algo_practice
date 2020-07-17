#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;

int bsearch(vector<int> &nums, int target, int left, int right) {
	int answer = -1;

	while (left <= right) {

		int mid = left + (right - left) / 2;

		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] > target) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return answer;
}

int revbsearch(vector<int> &nums, int target, int left, int right) {
	int answer = -1;

	while (left <= right) {

		int mid = left + (right - left) / 2;

		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] > target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return answer;
}

int findPeakElement(vector<int>& nums, int target) {

	int n = nums.size();
	int answer = -1;

	if (n < 2) {
		return 0;
	}

	int left = 0, right = n - 1;

	while (left <= right) {

		int mid = left + (right - left) / 2;

		if (mid > 0 && mid < n - 1) {

			if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
				answer = mid;
				break;
			}

			if (nums[mid + 1] > nums[mid]) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		else if (mid == 0) {
			answer = revbsearch(nums, target, 0, n - 1);
			break;
		}
		else if (mid == n - 1) {
			answer = bsearch(nums, target, 0, n - 1);
			break;
		}
		else {
			break;
		}
	}
	return answer;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, target, answer = -1;

	cin >> n >> target;

	vector<int>nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	int peakindex = findPeakElement(nums, target);


	if (peakindex == -1) {
		answer = -1;
	}
	else if (nums[peakindex] == target) {
		answer = peakindex;
	}
	else if (nums[peakindex] < target) {
		answer = -1;
	}
	else {

		int lpart = bsearch(nums, target, 0, peakindex - 1);
		int rpart = revbsearch(nums, target, peakindex + 1, n - 1);

		if (lpart != -1) {
			answer = lpart;
		}
		else if (rpart != -1) {
			answer = rpart;
		}
	}

	cout << answer << endl;

	return 0;
}
