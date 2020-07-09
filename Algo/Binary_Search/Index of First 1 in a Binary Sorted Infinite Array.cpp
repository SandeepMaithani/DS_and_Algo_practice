#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;


int first_occur(vector<int>&nums, int target, int start, int end) {

	int answer = -1;

	while (start <= end) {

		int mid = start + (end - start) / 2;

		if (nums[mid] == target) {

			answer = mid;
			end = mid - 1;
		}
		else if (nums[mid] > target) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	return answer;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output1.txt", "w", stdout);
#endif

	int n;

	cin >> n;

	int start = 0;
	int end = 1;

	vector<int>nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	while (nums[end] < 1) {
		start = end;
		end = 2 * end;
	}

	int answer = first_occur(nums, 1, start, end);

	cout << answer << endl;

	return 0;
}


