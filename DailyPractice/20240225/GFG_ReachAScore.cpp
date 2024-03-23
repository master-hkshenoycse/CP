#include<bits/stdc++.h>
using namespace std;
/*https://www.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1*/
#define ll long long
class Solution
{
    public:
    // Complete this function
    long long int count(long long int n)
    {
    	// Your code here
    	ll ans=0;
    	for(ll i=0;i<=n;i++){
    	    if(n-5*i>=0 and (n-5*i)%3==0){
    	        ans=ans+(i/2+1);
    	    }
    	}
    	return ans;
    }
};