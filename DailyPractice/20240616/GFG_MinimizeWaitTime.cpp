#include<bits/stdc++.h>
using namespace std;

//binary search on answer
//https://practice.geeksforgeeks.org/contest/gfg-weekly-159-rated-contest/problems
#define ll long long
class Solution {
  public:
    int minimizeWaitingTime(int n, int m, int k, vector<int> &arrival) {
        // code here
        sort(arrival.begin(),arrival.end());
        ll lo=0,hi=1e10,ans=hi;
        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            
            ll i=0,session=0;
            while(i<n){
                ll j=i,cnt=k;
                session++;
                
                while(j<n and cnt>0 and arrival[j]-arrival[i]<=mid){
                    j++;
                    cnt--;
                }
                
                i=j;
            }
            
            if(session<=m){
                ans=min(ans,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        
        return ans;
    }
};