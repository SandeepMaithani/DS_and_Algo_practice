#include<bits/stdc++.h> 
using namespace std;

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
