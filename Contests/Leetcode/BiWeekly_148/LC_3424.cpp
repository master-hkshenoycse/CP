#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        vector<ll> tmp_a,tmp_b;
        
        for(auto e:arr){
            tmp_a.push_back(e);
        }
        
        for(auto e:brr){
            tmp_b.push_back(e);
        }
        
        
        ll n=arr.size();
        ll cost_change=0;
        sort(tmp_a.begin(),tmp_a.end());
        sort(tmp_b.begin(),tmp_b.end());
        
        ll diff=0;
        for(ll i=0;i<n;i++){
            cost_change+=abs(tmp_a[i]-tmp_b[i]);
        }
        
        for(ll i=0;i<n;i++){
            if(arr[i] != brr[i]){
                diff++;
            }
        }
        
        //cout<<diff<<" "<<cost_change<<endl;
        ll other_cost=0;
        
        for(ll i=0;i<n;i++){
            other_cost+=abs(arr[i]-brr[i]);
        }
        
        if(other_cost != cost_change){
            cost_change+=k;
        }
        
       
        
        return min(cost_change,other_cost);
        
    }
};