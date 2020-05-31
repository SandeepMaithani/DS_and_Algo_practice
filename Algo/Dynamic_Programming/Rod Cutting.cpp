#include<bits/stdc++.h>
using namespace std;

//Bottom Up

int main() {
	
	int n,len;
	cin>>n>>len;
	
	vector<int>cutsize(n);
	vector<int>profit(n);
	
	vector<vector<int>>dp(n+1,vector<int>(len+1,0));
	
	for(int i=0;i<n;i++) {
		cin>>cutsize[i];
	}
	
	for(int i=0;i<n;i++) {
		cin>>profit[i];
	}
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=len;j++) {
			if(cutsize[i-1] <= j) {
				
				int pick = profit[i-1] + dp[i][j-cutsize[i-1]];
				int drop = dp[i-1][j];
				
				dp[i][j] = max(pick,drop);
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	int answer = dp[n][len];
	
	cout<<answer<<endl;
	
	return 0;
}


//Recursion + Memoization

/*

int rodcut(vector<int>&cutsize,vector<int>&profit,vector<vector<int>>&dp,int len,int n) {
	if(n==0 || len == 0) {
		dp[n][len] = 0;
		return 0;
	}
	
	if(dp[n][len] != -1) {
		return dp[n][len];
	}
	
	if(cutsize[n-1] <= len) {
		
		int pick = profit[n-1] + rodcut(cutsize,profit,dp,len-cutsize[n-1],n);
		int drop = rodcut(cutsize,profit,dp,len,n-1);
		
		dp[n][len] = max(pick,drop);
		
		return dp[n][len];
	}
	else {
		
		dp[n][len] = rodcut(cutsize,profit,dp,len,n-1);
		
		return dp[n][len];
	}
}

int main() {
	
	int n,len;
	cin>>n>>len;
	
	vector<int>cutsize(n);
	vector<int>profit(n);
	
	vector<vector<int>>dp(n+1,vector<int>(len+1,-1));
	
	for(int i=0;i<n;i++) {
		cin>>cutsize[i];
	}
	
	for(int i=0;i<n;i++) {
		cin>>profit[i];
	}
	
	int answer = rodcut(cutsize,profit,dp,len,n);
	
	cout<<answer<<endl;
	
	return 0;
}

*/
