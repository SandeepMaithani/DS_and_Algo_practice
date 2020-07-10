#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;


int mindiff(vector<int>&nums, int key, int start, int end) {

	while (start <= end) {

		int mid = start + (end - start) / 2;

		if (nums[mid] == key) {

			return nums[mid];
		}
		else if (nums[mid] > key) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	if (abs(nums[start] - key) < abs(nums[end] - key)) {
		return  nums[start];
	}

	return nums[end];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, key;

	cin >> n >> key;

	vector<int>nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	int answer = mindiff(nums, key, 0, n - 1);

	cout << answer << endl;

	return 0;
}


