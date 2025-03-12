#define ll long long
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        ll n=nums1.size();
        vector<vector<ll> > coll;
        for(ll i=0;i<n;i++){
            coll.push_back({nums1[i],nums2[i],i});
        }
        sort(coll.begin(),coll.end());
        
        vector<ll> sol(n);
        multiset<ll> m;
        ll s=0,j=0;
        for(ll i=0;i<n;i++){
            while(j<i and coll[i][0]>coll[j][0]){
                s+=coll[j][1];
                m.insert(coll[j][1]);
                if(m.size()>k){
                    s-=*m.begin();
                    m.erase(m.begin());
                }
                
                j++;
            }
            sol[coll[i][2]]=s;
        }
        return sol;
        
    }
};