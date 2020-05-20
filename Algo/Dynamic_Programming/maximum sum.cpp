/*

Given an array of integers(positive as well as negative) ,select some elements from this array(select a subset)
such that:-

  1.Sum of those elements is maximum(Sum of the subset is maximum) .
  2.No 2 elements in the subset should be consecutive.
  
Example :- {2,4,6,7,8}
Answer:- {2+6+8=16}

*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int>arr(n);
	vector<int>dp(n+1);
	cout<<"enter elements \n";
	for(int i=0;i<n;i++)
	cin>>arr[i];
	dp[0]= 0;
	dp[1]=arr[0];
	for(int i=2;i<=n;i++)
	dp[i] = max(arr[i-1]+dp[i-2],dp[i-1]);
	int ans = dp[n];
	cout<<"\n"<<ans;
	return 0;
}
