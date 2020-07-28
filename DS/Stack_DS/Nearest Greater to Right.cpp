/*

METHOD 1: Using Stack        Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N) . We are processing every element once and every for every element push and pop operation is performed only once.

Space Complexity: O(N). N size stack.

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

void solve(vector<lli>&nums, vector<lli>&answer) {

    stack<lli>st;

    for (int i = nums.size() - 1; i >= 0; i--) {
        if (st.empty()) {
            answer.push_back(-1);
        }
        else if (st.top() > nums[i]) {
            answer.push_back(st.top());
        }
        else if (st.top() <= nums[i]) {
            while (!st.empty() && st.top() < nums[i]) {
                st.pop();
            }
            if (st.empty()) {
                answer.push_back(-1);
            }
            else {
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

    vector<lli>nums(n);
    vector<lli>answer;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    solve(nums, answer);

    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}