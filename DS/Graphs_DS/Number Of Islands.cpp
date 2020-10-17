#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;

void islandHelper(vector<vector<int>> &graph, vector<vector<bool>> &visited, int row, int col, int i, int j) {

    if (i < 0 || i >= row || j < 0 || j >= col || visited[i][j] || graph[i][j] == 1) {
        return;
    }

    visited[i][j] = true;

    islandHelper(graph, visited, row, col, i - 1, j - 1);
    islandHelper(graph, visited, row, col, i - 1, j);
    islandHelper(graph, visited, row, col, i - 1, j + 1);
    islandHelper(graph, visited, row, col, i, j - 1);
    islandHelper(graph, visited, row, col, i, j + 1);
    islandHelper(graph, visited, row, col, i + 1, j - 1);
    islandHelper(graph, visited, row, col, i + 1, j);
    islandHelper(graph, visited, row, col, i + 1, j + 1);
}


int findIslands(vector<vector<int>>& graph, int N, int M) {

    vector<vector<bool>>visited(N, vector<bool>(M, false));
    int islandCount = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] == 0 && visited[i][j] == false) {
                islandCount++;
                islandHelper(graph, visited, N, M, i, j);
            }
        }
    }

    return islandCount;
}

int main() {

    int row, col;
    cin >> row >> col;

    vector<vector<int>>graph(row, vector<int>(col));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> graph[i][j];
        }
    }

    cout << findIslands(graph, row, col) << endl;

    return 0;
}
