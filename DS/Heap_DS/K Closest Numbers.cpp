/*

Complexity Analysis :

Time Complexity: O(N*log(K)). We are processing every element once & heap take log(K) time to push element so total O(N*log(K)) time Complexity.

Space Complexity: O(K). K size heap used.

*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;

void Kclosest(vector<int>& nums, vector<int> &answer, int k, int x) {

	priority_queue<pair<int, int>> max_heap;

	for (int i = 0; i < nums.size(); i++) {

		max_heap.push({abs(x - nums[i]), nums[i]});

		if (max_heap.size() > k) {
			max_heap.pop();
		}
	}

	while (!max_heap.empty()) {
		answer.push_back(max_heap.top().second);
		max_heap.pop();
	}

	sort(answer.begin(), answer.end());
}


int main() {


	int n, k, x;
	cin >> n >> k >> x;

	vector<int>nums(n);
	vector<int>answer;

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	Kclosest(nums, answer, k, x);

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}

	return 0;
}


