
/*

Complexity Analysis :

Time Complexity: O(N). We are processing every element once and every for every element push and pop operation is performed only once.

Space Complexity: O(N). N size stack used.

*/


#include<bits/stdc++.h>
using namespace std;

void stockspan(vector<int>&stock, vector<int>&answer) {
    stack<int>st;
    vector<int>index;

    for (int i = 0; i < stock.size(); i++) {
        if (st.empty()) {
            index.push_back(-1);
        }
        else if (stock[st.top()] > stock[i]) {
            index.push_back(st.top());
        }
        else if (stock[st.top()] <= stock[i]) {
            while (!st.empty() && stock[st.top()] <= stock[i]) {
                st.pop();
            }
            if (st.empty()) {
                index.push_back(-1);
            }
            else {
                index.push_back(st.top());
            }
        }
        st.push(i);
    }

    for (int i = 0; i < index.size(); i++) {
        int solution = i - index[i];
        answer.push_back(solution);
    }
}

int main() {

    int n;
    cin >> n;

    vector<int>stock(n);
    vector<int>answer;

    for (int i = 0; i < n; i++) {
        cin >> stock[i];
    }

    stockspan(stock, answer);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return 0;
}