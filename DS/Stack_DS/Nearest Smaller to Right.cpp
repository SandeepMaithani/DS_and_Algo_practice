#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;

void getlargest(vector<int>&nums, vector<int>&answer) {

	stack<int>st;

	for (int i = nums.size() - 1; i >= 0; i--) {
		if (st.empty()) {
			answer.push_back(-1);
		}
		else if (st.top() < nums[i]) {
			answer.push_back(st.top());
		}
		else if (st.top() >= nums[i]) {
			while (!st.empty() && st.top() >= nums[i]) {
				st.pop();
			}
			if (st.empty()) {
				answer.push_back(-1);
			}
			else if (st.top() < nums[i]) {
				answer.push_back(st.top());
			}
		}

		st.push(nums[i]);
	}

	reverse(answer.begin(), answer.end());
}


int main() {

	int n;
	cin >> n;

	vector<int>nums(n);
	vector<int>answer;


	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	getlargest(nums, answer);

	for (int i = 0; i < n; i++) {
		cout << answer[i] << " ";
	}

	return 0;
}


