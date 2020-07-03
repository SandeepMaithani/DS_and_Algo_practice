#include<bits/stdc++.h>
using namespace std;

int myfloor(vector<long long int> &nums, long long int target, int start, int end) {

    int index = -1;

    while (start <= end) {

        int mid = start + (end - start) / 2;

        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            index = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return index;
}

int main() {

    int n;
    long long int target;

    cin >> n >> target;

    vector<long long int>nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int answer = myfloor(nums, target, 0, n - 1);

    cout << answer << endl;

    return 0;
}