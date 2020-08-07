/*

Complexity Analysis :

Time Complexity: O(N*log(K)). We are processing every element once heap take log(K) time to push to O(N*log(K)).

Space Complexity: O(K). K size heap used.

*/


#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;

void KLargest(vector<int>& nums, vector<int> &answer, int k) {

	priority_queue<int, vector<int>, greater<int>> min_heap;

	for (int i = 0; i < nums.size(); i++) {

		min_heap.push(nums[i]);

		if (min_heap.size() > k) {
			min_heap.pop();
		}
	}

	while (!min_heap.empty()) {
		answer.push_back(min_heap.top());
		min_heap.pop();
	}

	sort(answer.begin(), answer.end());
}


int main() {

	int n, k;
	cin >> n >> k;

	vector<int>nums(n);
	vector<int>answer;

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	KLargest(nums, answer, k);

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}

	return 0;
}


