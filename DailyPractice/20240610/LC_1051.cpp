#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> tmp=heights;
        sort(tmp.begin(),tmp.end());
        int n=tmp.size();

        int ans=0;
        for(int i=0;i<n;i++){
            ans=ans+(heights[i] != tmp[i]);
        }
        return ans;
    }
};