/*

Complexity Analysis :

Time Complexity: O(N*log(K)). We are processing every element once & heap take log(K) time to push element, So total O(N*log(K)) time Complexity.

Space Complexity: O(K). To store heap with not more K elements.

*/


#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;

int getDistance(vector<int>&point) {
	return ((point[0] * point[0]) + (point[1] * point[1]));
}

void kClosest(vector<vector<int>>& points, vector<vector<int>>& answer, int K) {

	priority_queue<pair<int, vector<int>>>maxHeap;

	for (int i = 0; i < points.size(); i++) {

		int distance = getDistance(points[i]);
		maxHeap.push({distance, points[i]});

		if (maxHeap.size() > K) {
			maxHeap.pop();
		}
	}

	while (!maxHeap.empty()) {
		answer.push_back(maxHeap.top().second);
		maxHeap.pop();
	}
}


int main() {

	int n, K;
	cin >> n >> K;

	vector<vector<int>>points(n, vector<int>(2));
	vector<vector<int>>answer;

	for (int i = 0; i < n; i++) {
		cin >> points[i][0] >> points[i][1];
	}

	kClosest(points, answer, K);

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i][0] << "," << answer[i][1] << endl;
	}

	return 0;
}


