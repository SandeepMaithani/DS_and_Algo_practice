#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int lli;

int kthGrammar(int N, int K) {

	if (N == 1 && K == 1) {
		return 0;
	}

	int mid = pow(2, N - 1) / 2;

	if (K <= mid) {
		return kthGrammar(N - 1, K);
	}

	return !kthGrammar(N - 1, K - mid);
}

int main() {

	int n, k;
	cin >> n >> k;

	cout << kthGrammar(n, k) << endl;

	return 0;
}


