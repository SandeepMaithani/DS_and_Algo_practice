#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;


struct CompareWeight {
	bool operator()(pair<pair<int, int>, int> const& p1, pair<pair<int, int>, int> const& p2)
	{
		return p1.second > p2.second;
	}
};


void primsAlgo(vector<vector<pair<int, int>>>& graph, vector<bool>& visited) {

	priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, CompareWeight>minHeap;
	minHeap.push({{0, -1}, 0});

	while (!minHeap.empty()) {
		pair<pair<int, int>, int>curVertexInfo = minHeap.top();
		minHeap.pop();

		int curVertex = curVertexInfo.first.first;
		int preVertex = curVertexInfo.first.second;
		int weight = curVertexInfo.second;

		if (visited[curVertex] == true) {
			continue;
		}

		visited[curVertex] = true;

		if (preVertex != -1) {
			cout << "[" << curVertex << "-" << preVertex << "@" << weight << "]" << endl;
		}

		for (auto neighbour : graph[curVertex]) {
			if (visited[neighbour.first] == false) {
				minHeap.push({{neighbour.first, curVertex}, neighbour.second});
			}
		}
	}
}

int main() {

	int vertexCount, edgeCount;
	cin >> vertexCount >> edgeCount;

	vector<vector<pair<int, int>>>graph(vertexCount);
	vector<bool>visited(vertexCount, false);

	for (int i = 0; i < edgeCount; i++) {
		int vertex1, vertex2, weight;
		cin >> vertex1 >> vertex2 >> weight;

		graph[vertex1].push_back({vertex2, weight});
		graph[vertex2].push_back({vertex1, weight});
	}

	primsAlgo(graph, visited);

	return 0;
}


