#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        map<ll,ll> help;
        for(auto e:nums1){
            help[e]++;
        }

        ll ans=0;
        sort(nums2.begin(),nums2.end());

        ll i=0,m=nums2.size();

        while(i<m){
        
            ll c=0,j=i;
            while(j<m and nums2[i]==nums2[j]){
                c++;
                j++;
            }
        
            ll st=k*nums2[i];
            for(int i=st;i<=1000000;i+=st){
                if(help.find(i) != help.end()){
                    ans=ans+help[i]*c;
                }
            }

            i=j;
        

        }

        return ans;
    }
};