#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        
        vFences.push_back(1);
        vFences.push_back(n);
        ll mod=1e9+7;
        
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());
        
        unordered_set<ll> x,y;
        int sz=hFences.size();
        for(int i=0;i<sz;i++){
            for(int j=i+1;j<sz;j++){
                x.insert(hFences[j]-hFences[i]);
            }
        }
        
        sz=vFences.size();
        for(int i=0;i<sz;i++){
            for(int j=i+1;j<sz;j++){
                y.insert(vFences[j]-vFences[i]);
            }
        }
        
        ll ans=-1;
        for(auto s:x){
            if(y.find(s) != y.end()){
                ans=max(ans,s*s);
            }
        }
        
        
        if(ans != -1){
            ans%=mod;
        }
        
        return ans;
        
        
    }
};