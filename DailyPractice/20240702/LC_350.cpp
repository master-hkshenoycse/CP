#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> c1(1005,0),c2(1005,0);
        
        for(auto e:nums1){
            c1[e]++;
        }
        for(auto e:nums2){
            c2[e]++;
        }
        
        vector<int> sol;
        for(int i=0;i<=1000;i++){
            int occ=min(c1[i],c2[i]);
            while(occ--){
                sol.push_back(i);
            }
        }
        return sol;
    }
};