#include<bits/stdc++.h>
using namespace std;

int findCost(vector<int>&ropes) {

    priority_queue<int, vector<int>, greater<int>>minHeap;
    int cost = 0;

    for (int i = 0; i < ropes.size(); i++) {
        minHeap.push(ropes[i]);
    }

    while (minHeap.size() > 1) {
        int first = minHeap.top();
        minHeap.pop();

        int second = minHeap.top();
        minHeap.pop();

        cost += first + second;

        minHeap.push(first + second);
    }

    return cost;
}

int main() {

    int n;
    cin >> n;

    vector<int>ropes(n);

    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
    }

    int cost = findCost(ropes);

    cout << cost << endl;

    return 0;
}