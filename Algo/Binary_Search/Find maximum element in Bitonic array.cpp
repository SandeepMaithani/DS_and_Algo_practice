#include <bits/stdc++.h>
using namespace std;

int maxele(vector<int>&nums, int left, int right) {

    int n = nums.size();
    int answer = -1;

    if (n < 2) {
        return 0;
    }

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (mid > 0 && mid < n - 1) {

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                answer = mid;
                break;
            }
            else if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        else if ( mid == 0) {

            if (nums[mid] > nums[mid + 1]) {
                answer = mid;
                break;
            }
            else {
                answer = mid + 1;
                break;
            }
        }
        else if (mid == n - 1) {

            if (nums[mid] > nums[mid - 1]) {
                answer = mid;
                break;
            }
            else {
                answer = mid - 1;
                break;
            }
        }

    }
    return answer;
}

int main() {


    int n;
    cin >> n;

    vector<int>nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int solution = maxele(nums, 0, n - 1);

    cout << nums[solution] << endl;

    return 0;
}