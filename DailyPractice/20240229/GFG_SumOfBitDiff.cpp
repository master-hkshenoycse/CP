#include<bits/stdc++.h>
using namespace std;


#define ll long long
class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    // code here
	    ll ans=0;
	    for(ll i=0;i<=20;i++){
	        ll c1=0,c0=0;
	        for(ll j=0;j<n;j++){
	            if(arr[j] & (1ll<<i)){
	                c1++;
	            }else{
	                c0++;
	            }
	        }
	        ans=ans+c0*c1*2;
	    }
	    
	    return ans;
	}
};