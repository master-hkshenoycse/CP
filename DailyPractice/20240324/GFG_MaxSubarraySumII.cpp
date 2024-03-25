#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;

#define ll long long
class Solution {
  public:
    vector<long long> maxSumII(int N, vector<int> &arr, vector<int> &brr) {
        // code here
        vector<ll> csum(N+2,0);
        for(ll i=1;i<=N;i++){
            csum[i]=csum[i-1]+arr[i-1];
        }
        
        set<ll> points;
        multiset<ll> curr_sums;
        points.insert(0);
        points.insert(N+1);
        curr_sums.insert(csum[N]);
        
        vector<ll> sol;
        
        for(auto ind:brr){
            ll prev=*(--points.lower_bound(ind));
            ll nx=*(points.lower_bound(ind));
            
            curr_sums.erase(curr_sums.find(csum[nx-1]-csum[prev]));
            
            
            if(ind-1>prev){
                curr_sums.insert(csum[ind-1]-csum[prev]);
            }
            
            if(ind+1<nx){
                curr_sums.insert(csum[nx-1]-csum[ind]);
            }
            
            sol.push_back(0);
            if(curr_sums.size()>0){
                sol.back()=*(--curr_sums.end());
            }
            points.insert(ind);
        }
        
        return sol;
    }
};