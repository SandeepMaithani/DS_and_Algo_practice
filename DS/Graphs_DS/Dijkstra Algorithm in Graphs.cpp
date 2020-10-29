#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;


struct CompareWeight {
	bool operator()(pair<pair<int, string>, int> const& p1, pair<pair<int, string>, int> const& p2)
	{
		return p1.second > p2.second;
	}
};


void dijkstraAlgo(vector<vector<pair<int, int>>>& graph, vector<bool>& visited, int source) {
	priority_queue<pair<pair<int, string>, int>, vector<pair<pair<int, string>, int>>, CompareWeight>minHeap;
	minHeap.push({{source, to_string(source)}, 0});

	while (!minHeap.empty()) {
		pair<pair<int, string>, int>curVertexInfo = minHeap.top();
		minHeap.pop();

		int curVertex = curVertexInfo.first.first;
		string path = curVertexInfo.first.second;
		int weight = curVertexInfo.second;

		if (visited[curVertex] == true) {
			continue;
		}

		visited[curVertex] = true;
		cout << curVertex << " via " << path << " @ " << weight << endl;

		for (auto neighbour : graph[curVertex]) {
			if (visited[neighbour.first] == false) {
				minHeap.push({{neighbour.first, path + to_string(neighbour.first)}, weight + neighbour.second});
			}
		}
	}
}

int main() {

	int vertexCount, edgeCount, source;
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

	dijkstraAlgo(graph, visited, source);

	return 0;
}
