#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;

int maximumSum(vector<int>&nums, int k) {
	int start = 0, end = 0;
	int maxSum = 0, sum = 0;

	while (end < nums.size()) {
		sum = sum + nums[end];

		if (end - start + 1 < k) {
			end++;
		}
		else if (end - start + 1 == k) {
			maxSum = max(maxSum, sum);
			sum = sum - nums[start];
			start++;
			end++;
		}
	}

	return maxSum;
}

int main() {

	int n, k;
	cin >> n >> k;

	vector<int>nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	int maxSum = maximumSum(nums, k);

	cout << maxSum << endl;

	return 0;
}



