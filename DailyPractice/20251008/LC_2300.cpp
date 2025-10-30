#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        
        vector<int> sol;
        int n=potions.size(),m=spells.size();
        
        for(int i=0;i<m;i++){
            ll e=spells[i];
            int lo=0,hi=n-1,r=n;
            
            while(hi>=lo){
                int mid=(hi+lo)/2;
                ll v=potions[mid];
                v=v * e ;
                
                if(v>=success){
                    r=min(r,mid);
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }
            sol.push_back(n-r);
                 
        }
        
        
        return sol;
    }
};