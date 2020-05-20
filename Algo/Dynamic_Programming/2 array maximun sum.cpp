/*

We are given ‘2’ arrays . Select some elements from both of these arrays (select a subset) such that:-

 1.Sum of those elements is maximum(Sum of the subset is maximum).
 2.No 2 elements in the subset should be consecutive.(Note:-If you select, say 5'th element from Array-1, 
   then you are not allowed to select 4'th element from either Array-1 or Array-2 )

Example:-

Array 1(a1) : {1,5,3,21234}
Array 2(a2) : {-4509,200,3,40}

Answer:- (200+21234=21434)

*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int j = 4;
	while(j--)
	{
	
	int n;
	cin>>n;
	vector<int>arr1(n);
	vector<int>arr2(n);
	vector<int>dp(n+1);
	cout<<"enter elements of array 1 \n";
	for(int i=0;i<n;i++)
	cin>>arr1[i];
	cout<<"enter elements of array 2 \n";
	for(int i=0;i<n;i++)
	cin>>arr2[i];
	dp[0]= 0;
	dp[1]= max(arr1[0],arr2[0]);
	for(int i=2;i<=n;i++)
	dp[i] = max(max(arr1[i-1],arr2[i-1])+dp[i-2],dp[i-1]);
	int ans = dp[n];
	cout<<"\n"<<ans;
}
	return 0;
}
