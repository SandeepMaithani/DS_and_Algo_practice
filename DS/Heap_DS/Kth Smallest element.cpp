#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;

int ksmallest(vector<int>&nums, int k) {

	priority_queue<int>maxHeap;

	for (int i = 0; i < nums.size(); i++) {
		maxHeap.push(nums[i]);

		if ( maxHeap.size() > k) {
			maxHeap.pop();
		}
	}
	return maxHeap.top();
}

int main() {

	int n, k;
	cin >> n >> k;

	vector<int>nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	int answer = ksmallest(nums, k);

	cout << answer << endl;

	return 0;
}


