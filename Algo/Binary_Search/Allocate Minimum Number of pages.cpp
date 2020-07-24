/*

Method : Modified Binary Search( Divide and Conquor )              Verdict : Accepted

Complexity Analysis:

Time Complexity: O(N*Log(N)).

As Binary search function will take O(Log(N)) time and for each binary search iteration we are checking if it is a valid choice or not which take O(N) time so total it will take O(N*log(N)) time.

Space Complexity: O(1).

*/


#include<bits/stdc++.h>
using namespace std;

bool isvalid(vector<int>&books, int n, int totalstudent, long long int limit) {

    long long int pageread = 0;
    int student = 1;

    for (int i = 0; i < n; i++) {

        if (books[i] > limit) {
            return false;
        }

        pageread += books[i];

        if (pageread > limit) {
            student++;
            pageread = books[i];
        }

        if (student > totalstudent) {
            return false;
        }
    }
    return true;
}

int allocate(vector<int>&books, int n, int totstudent, long long int min, long long int max) {

    int answer = -1;

    while (min <= max) {

        long long int limit = min + (max - min) / 2;

        if (isvalid(books, n, totstudent, limit)) {
            answer = limit;
            max = limit - 1;
        }
        else {
            min = limit + 1;
        }
    }

    return answer;
}

int main() {

    int n, totstudent;
    long long int sum = 0;

    cin >> n >> totstudent;

    vector<int>books(n);

    for (int i = 0; i < n; i++) {
        cin >> books[i];
        sum += books[i];
    }


    if (n < totstudent) {
        cout << "-1" << endl;
        continue;
    }

    long long int min = *max_element(books.begin(), books.end());
    long long int max = sum;

    int answer = allocate(books, n, totstudent, 0, max);

    cout << answer << endl;


    return 0;
}



