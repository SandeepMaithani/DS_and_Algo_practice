/*

Complexity Analysis :

Time Complexity: O(N*log(N)). We are processing every element once & heap take log(N) time to push element so total O(N*log(N)) time Complexity.

Space Complexity: O(N + N). To store the hash map and heap with not more N elements.


*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;


void frequencySort(vector<int>& nums, vector<int> &answer) {

	unordered_map<int, int>hashmap;
	priority_queue<pair<int, int>>maxheap;

	for (int i = 0; i < nums.size(); i++) hashmap[nums[i]]++;

	for (auto it : hashmap) {
		maxheap.push({it.second, it.first});
	}

	while (!maxheap.empty()) {
		int cnt  = maxheap.top().first;
		int element = maxheap.top().second;
		maxheap.pop();

		for (int i = 0; i < cnt; i++) {
			answer.push_back(element);
		}
	}
}


int main() {

	int n;
	cin >> n;

	vector<int>nums(n);
	vector<int>answer;

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	frequencySort(nums, answer);

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}

	return 0;
}


