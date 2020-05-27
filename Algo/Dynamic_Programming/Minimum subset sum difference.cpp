#include<bits/stdc++.h> 
using namespace std;

//Bottom - Up Approach

int main() {
	int n,range = 0,mindiff = INT_MAX;
	cin>>n;
	
	vector<int>num(n);
	vector<int>posum;
	
	for(int i=0;i<n;i++) {
		cin>>num[i];
		range += num[i];
	}
	
	vector<vector<bool>>dp(n+1,vector<bool>(range+1));
	
	for(int i=0;i<=n;i++) {
		dp[i][0] = true;		
	}
	
	for(int j=1;j<=range;j++) {
		dp[0][j] = false;
	}
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=range;j++) {
			if(num[i-1]<=j) {
				dp[i][j] = dp[i-1][j-num[i-1]] || dp[i-1][j];
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	for(int j=0;j<=(range/2);j++) {
		if(dp[n][j]) {
			posum.push_back(j);
		}		
	}
	
	for(int i=0;i<posum.size();i++) {
		int temp = range - 2*(posum[i]);
		mindiff = min(mindiff,temp);		
	}
	
	cout<<mindiff<<endl;
	
	return 0;
	
} 


//Recursion + Memoization Approach

/*

bool subset(vector<int>&num,vector<vector<int>>&dp,int sum,int n) {
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
	int n,range = 0,mindiff = INT_MAX;
	cin>>n;
	
	vector<int>num(n);
	
	for(int i=0;i<n;i++) {
		cin>>num[i];
		range += num[i];
	}
	
	vector<vector<int>>dp(n+1,vector<int>(range+1,-1));
	
	for(int i=0;i<=(range/2);i++) {
		if(subset(num,dp,i,n)) {
			int temp = range - (2*i);
			mindiff = min(mindiff,temp);
		}
	}
	
	cout<<mindiff<<endl;
	
	return 0;
}

*/

