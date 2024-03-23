#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total=0;
        for(auto a:apple){
            total+=a;
        }
        
        sort(capacity.begin(),capacity.end());
        int ans=0;
        int curr=0;
        while(curr<total){
            curr=curr+capacity.back();
            capacity.pop_back();
            ans++;
        }
        return ans;
    }
};