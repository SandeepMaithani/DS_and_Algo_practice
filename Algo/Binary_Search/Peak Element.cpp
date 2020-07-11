#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;

int findPeakElement(vector<int>& nums) {

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

			if (nums[mid] > nums[mid + 1]) {
				answer = mid;
			}
			else {
				answer = mid + 1;
			}
		}
		else if (mid == n - 1) {

			if (nums[mid] > nums[mid - 1]) {
				answer = mid;
			}
			else {
				answer = mid - 1;
			}
		}
	}
	return answer;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	vector<int>nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	int answer = findPeakElement(nums);

	cout << answer << endl;

	return 0;
}


