#include<bits/stdc++.h>
using namespace std;

//Bottom Up

int main() {
	
	string a,b;
	cin>>a>>b;
	
	int n = a.length();
	int m = b.length();
	
	vector<vector<int>>dp(n+1,vector<int>(m+1,0));
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(a[i-1] == b[j-1]) {
				dp[i][j] = 1+ dp[i-1][j-1];
			}
			else {
				int first = dp[i][j-1];
				int second = dp[i-1][j];
				
				dp[i][j] = max(first,second);
			}
		}
	}
	
	int answer = dp[n][m];
	
	cout<<answer<<endl;
	
	return 0;
	
}

//Recursion + Memoization

/*

int LCS(string a,string b,vector<vector<int>>&dp,int n,int m) {
	
	if(n == 0 || m == 0) {
		
		dp[n][m] = 0;
		return 0;
	}
	
	if(dp[n][m] != -1) {
		return dp[n][m];
	}
	
	if(a[n-1] == b[m-1]) {
		dp[n][m] = 1+LCS(a,b,dp,n-1,m-1);
		return dp[n][m];
	}
	else {
		int first = LCS(a,b,dp,n,m-1);
		int second = LCS(a,b,dp,n-1,m);
		
		dp[n][m] = max(first,second);
		
		return dp[n][m];
	}
}

int main() {
	string a,b;
	cin>>a>>b;
	
	int n = a.length();
	int m = b.length();
	
	vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	
	int answer = LCS(a,b,dp,n,m);
	
	cout<<answer<<endl;
	
	return 0;
}

*/
