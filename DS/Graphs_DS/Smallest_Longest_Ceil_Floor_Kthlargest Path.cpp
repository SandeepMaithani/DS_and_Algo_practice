#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;

string spath;
int spathwt = INT_MAX;

string lpath;
int lpathwt = INT_MIN;

string ceilPath;
int ceilPathwt = INT_MAX;

string floorPath;
int floorPathwt = INT_MIN;

priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>>minHeap;


void multiSolver(vector<vector<pair<int, int>>>&graph, vector<bool> &visited, int source, int destination, int criteria, int k, string path, int pathCost) {

	if (source == destination) {

		if (spathwt > pathCost) {
			spathwt = pathCost;
			spath = path;
		}

		if (lpathwt < pathCost) {
			lpathwt = pathCost;
			lpath = path;
		}

		if (pathCost > criteria && pathCost < ceilPathwt) {
			ceilPathwt = pathCost;
			ceilPath = path;
		}

		if (pathCost < criteria && pathCost > floorPathwt) {
			floorPathwt = pathCost;
			floorPath = path;
		}

		minHeap.push({pathCost, path});

		if (minHeap.size() > k) {
			minHeap.pop();
		}

		return;
	}

	visited[source] = true;

	for (int i = 0; i < graph[source].size(); i++) {
		int neighbor = graph[source][i].first;
		int weight = graph[source][i].second;

		if (visited[neighbor] == false) {
			multiSolver(graph, visited, neighbor, destination, criteria, k, path + to_string(neighbor), pathCost + weight);
		}
	}

	visited[source] = false;
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

	int vertexCount, edgeCount, source, destination, criteria, k;
	cin >> vertexCount >> edgeCount;

	vector<vector<pair<int, int>>>graph(vertexCount);
	vector<bool>visited(vertexCount, false);

	for (int i = 0; i < edgeCount; i++) {
		int vertex1, vertex2, weight;
		cin >> vertex1 >> vertex2 >> weight;

		graph[vertex1].push_back({vertex2, weight});
		graph[vertex2].push_back({vertex1, weight});
	}

	cin >> source >> destination >> criteria >> k;

	multiSolver(graph, visited, source, destination, criteria, k, "" + to_string(source), 0);

	cout << "Smallest Path = " << spath << "@" << spathwt << endl;
	cout << "Largest Path = " << lpath << "@" << lpathwt << endl;
	cout << "Just Larger Path than " << criteria << " = " << ceilPath << "@" << ceilPathwt << endl;
	cout << "Just Smaller Path than " << criteria << " = " << floorPath << "@" << floorPathwt << endl;
	cout << k << "th largest path = " << minHeap.top().second << "@" << minHeap.top().first << endl;

	return 0;
}