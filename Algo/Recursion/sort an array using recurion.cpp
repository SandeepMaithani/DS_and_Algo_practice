#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;

void insert(vector<int>&nums, int temp) {
	int n = nums.size();

	if (n == 0 || temp >= nums[n - 1]) {
		nums.push_back(temp);
		return;
	}

	int lastEle = nums[n - 1];

	nums.pop_back();

	insert(nums, temp);

	nums.push_back(lastEle);

}

void sortRecur(vector<int>&nums) {

	int n = nums.size();

	if (n == 1) {
		return;
	}

	int temp = nums[n - 1];

	nums.pop_back();

	sortRecur(nums);

	insert(nums, temp);

}

int main() {

	int n;
	cin >> n;

	vector<int>nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	sortRecur(nums);

	for (int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}

	cout << endl;

	return 0;
}


