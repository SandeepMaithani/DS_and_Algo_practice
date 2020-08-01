/*

Complexity Analysis :                         Verdict : Accepted

Time Complexity: O(N). Since every bar is pushed and popped only once, the time complexity of this method is O(n).

Space Complexity: O(N). N size stack used.

*/


#include<bits/stdc++.h>
using namespace std;

void fillleft(vector<int>&hist, vector<int>&left) {
  stack<int>st;
  int extreme = -1;

  for (int i = 0; i < hist.size(); i++) {
    if (st.empty()) {
      left.push_back(extreme);
    }
    else if (hist[st.top()] < hist[i]) {
      left.push_back(st.top());
    }
    else {
      while (!st.empty() && hist[st.top()] >= hist[i]) {
        st.pop();
      }

      if (st.empty()) {
        left.push_back(extreme);
      }
      else {
        left.push_back(st.top());
      }
    }
    st.push(i);
  }
}

void fillright(vector<int>&hist, vector<int>&right) {
  stack<int>st;
  int extreme = hist.size();

  for (int i = hist.size() - 1; i >= 0; i--) {
    if (st.empty()) {
      right.push_back(extreme);
    }
    else if (hist[st.top()] < hist[i]) {
      right.push_back(st.top());
    }
    else {
      while (!st.empty() && hist[st.top()] >= hist[i]) {
        st.pop();
      }

      if (st.empty()) {
        right.push_back(extreme);
      }
      else {
        right.push_back(st.top());
      }
    }
    st.push(i);
  }
  reverse(right.begin(), right.end());
}


int main() {

  int n;
  cin >> n;

  vector<int>hist(n);
  vector<int>left;
  vector<int>right;
  vector<int>area;

  for (int i = 0; i < n; i++) {
    cin >> hist[i];
  }

  fillleft(hist, left);
  fillright(hist, right);

  for (int i = 0; i < n; i++) {

    int width = right[i] - left[i] - 1;
    int answer = hist[i] * width;

    area.push_back(answer);
  }

  cout << *max_element(area.begin(), area.end()) << endl;

  return 0;
}