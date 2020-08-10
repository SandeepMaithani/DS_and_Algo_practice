/*

Complexity Analysis :

Time Complexity: O(N*log(K)). We are processing every element once & heap take log(K) time to push element so total O(N*log(K)) time Complexity.

Space Complexity: O(N + k). To store the hash map with not more N elements and a heap with k elements.


*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;

void topKFrequent(vector<int>& nums, vector<int> &answer, int k) {

	unordered_map<int, int>hashmap;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>minheap;

	for (int i = 0; i < nums.size(); i++) {
		hashmap[nums[i]]++;
	}

	for (auto it : hashmap) {

		minheap.push({it.second, it.first});

		if (minheap.size() > k) {
			minheap.pop();
		}
	}

	while (!minheap.empty()) {
		answer.push_back(minheap.top().second);
		minheap.pop();
	}
}


int main() {

	int n, k;
	cin >> n >> k;

	vector<int>nums(n);
	vector<int>answer;

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	topKFrequent(nums, answer, k);

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}

	return 0;
}


