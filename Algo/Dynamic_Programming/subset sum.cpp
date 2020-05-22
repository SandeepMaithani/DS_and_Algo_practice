#include<bits/stdc++.h>
using namespace std;

//Method 1 (top - down solution)

int main() {
	
	int n,sum;
	cin>>n>>sum;
	
	vector<int>num(n);
	vector<vector<bool>>dp(n+1,vector<bool>(sum+1));
	
	for(int i=0;i<n;i++) {
		cin>>num[i];
	}
	
	for(int i=0;i<=n;i++) {
		dp[i][0] = true;
	}
	
	for(int j=1;j<=sum;j++) {
		dp[0][j] = false;
	}
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=sum;j++) {
			if(num[i-1] <= j) {
				
				bool pick = dp[i-1][j-num[i-1]];
				bool drop = dp[i-1][j];
				
				dp[i][j] = (pick || drop);
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	if(dp[n][sum]) {
		cout<<"YES"<<endl;
	}
	else {
		cout<<"NO"<<endl;
	}

	return 0;
}


//Method 2

/*

//Recursion + Memoization

bool subset(vector<int> &num,vector<vector<int>>&dp,int sum,int n) {
	
	if(sum == 0) {
		return true;
	}
	
	if(sum != 0 && n == 0) {
		return false;
	}
	
	if(dp[n][sum] != -1) {
		if(dp[n][sum]) {
			return true;
		}
		else {
			return false;
		}
	}
	
	if(num[n-1] <= sum) {
		bool pick = subset(num,dp,sum-num[n-1],n-1);
		bool drop =	subset(num,dp,sum,n-1);
		if (pick || drop) {
			dp[n][sum] = 1;			
		}
		else {
			dp[n][sum] = 0;
		}
		
		return (pick || drop);
	}
	else {
		
		if (subset(num,dp,sum,n-1)) {
			dp[n][sum] = 1;			
		}
		else {
			dp[n][sum] = 0;
		}
		
		if(dp[n][sum]) {
			return true;
		}
		else {
			return false;
		}
	}
}

int main() {
	
	int n,sum;
	cin>>n>>sum;
	
	vector<int>num(n);
	vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
	
	for(int i=0;i<n;i++) {
		cin>>num[i];
	}
	
	if(subset(num,dp,sum,n)) {
		dp[n][sum] = 1;		
	}
	else {
		dp[n][sum] = 0;
	}
	
	if(dp[n][sum]) {
		cout<<"YES\n";
	}
	else {
		cout<<"NO\n";
	}
	
	return 0;
	
}

*/
