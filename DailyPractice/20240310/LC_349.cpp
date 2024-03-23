#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sol;
        set<int> x;
        for(auto e:nums1)x.insert(e);
        for(auto e:nums2){
            if(x.find(e) == x.end() )continue;
            sol.push_back(e);
            x.erase(e);
        }
        return sol;
    }
};