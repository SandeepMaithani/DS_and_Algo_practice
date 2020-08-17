#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;

void insert(stack<int>&nums, int temp) {
	int n = nums.size();

	if (n == 0 || temp >= nums.top()) {
		nums.push(temp);
		return;
	}

	int lastEle = nums.top();

	nums.pop();

	insert(nums, temp);

	nums.push(lastEle);

}

void sortStackRecur(stack<int>&nums) {

	int n = nums.size();

	if (n == 1) {
		return;
	}

	int temp = nums.top();

	nums.pop();

	sortStackRecur(nums);

	insert(nums, temp);

}

int main() {

	int n;
	cin >> n;

	stack<int>nums;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		nums.push(temp);
	}

	sortStackRecur(nums);

	while (!nums.empty()) {
		cout << nums.top() << " ";
		nums.pop();
	}

	cout << endl;

	return 0;
}


