/*

Complexity Analysis :

Time Complexity: O(N*log(K)). We are processing every element once & heap take log(K) time to push element so total O(N*log(K)) time Complexity.

Space Complexity: O(K). K size heap used.

*/

#include<bits/stdc++.h>
using namespace std;

void Ksorted(vector<int>&nums, int k) {

    priority_queue<int, vector<int>, greater<int>>minHeap;

    int cng = 0;

    for (int i = 0; i < nums.size(); i++) {
        minHeap.push(nums[i]);

        if (minHeap.size() > k) {
            nums[cng] = minHeap.top();
            minHeap.pop();
            cng++;
        }
    }

    while (!minHeap.empty()) {
        nums[cng] = minHeap.top();
        minHeap.pop();
        cng++;
    }
}

int main() {


    int n, k;
    cin >> n >> k;

    vector<int>nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Ksorted(nums, k);

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}