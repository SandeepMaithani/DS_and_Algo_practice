#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;

struct CompareWeight {
	bool operator()(pair<int, int> const& p1, pair<int, int> const& p2)
	{
		return p1.second > p2.second;
	}
};


void dijkstraAlgo(vector<vector<pair<int, int>>>& graph, vector<bool>& visited, int source, int &cost) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, CompareWeight>minHeap;
	minHeap.push({source, 0});

	while (!minHeap.empty()) {
		pair<int, int>curVertexInfo = minHeap.top();
		minHeap.pop();

		int curVertex = curVertexInfo.first;
		int weight = curVertexInfo.second;

		if (visited[curVertex] == true) {
			continue;
		}

		visited[curVertex] = true;
		cost = weight;

		for (auto neighbour : graph[curVertex]) {
			if (visited[neighbour.first] == false) {
				minHeap.push({neighbour.first, weight + neighbour.second});
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output1.txt", "w", stdout);
#endif

	int vertexCount, edgeCount, source, cost = 0;
	cin >> vertexCount >> edgeCount;

	vector<vector<pair<int, int>>>graph(vertexCount);
	vector<bool>visited(vertexCount, false);

	for (int i = 0; i < edgeCount; i++) {
		int vertex1, vertex2, weight;
		cin >> vertex1 >> vertex2 >> weight;

		graph[vertex1].push_back({vertex2, weight});
		graph[vertex2].push_back({vertex1, weight});
	}

	cin >> source;

	dijkstraAlgo(graph, visited, source, cost);

	cout << cost << endl;

	return 0;
}
