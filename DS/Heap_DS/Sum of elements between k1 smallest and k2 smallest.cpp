#include<bits/stdc++.h>
using namespace std;

int ksmallest(vector<int>&nums, long long int k) {

    priority_queue<int, vector<int>, greater<int>>maxHeap;

    for (int i = 0; i < nums.size(); i++) {
        maxHeap.push(nums[i]);

        if (maxHeap.size() > k - 1) {
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}

int sumBetween(vector<int>&nums, int k1, int k2) {
    int ftsmallest = ksmallest(nums, k1);
    int sdsmallest = ksmallest(nums, k2);

    int sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < ftsmallest && nums[i] > sdsmallest) {
            sum += nums[i];
        }
    }

    return sum;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, int k1, k2;

        cin >> n;

        vector<int>nums(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        cin >> k1 >> k2;

        int answer = sumBetween(nums, k1, k2);

        cout << answer << endl;
    }
    return 0;
}