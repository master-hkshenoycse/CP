#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        for(int i=1;i<n;i++){
            arr[i]=(arr[i] ^ arr[i-1]);
        }

        vector<int> sol;
        for(auto q:queries){
            int l=q[0];
            int r=q[1];
            int res=arr[r];
            if(l-1>=0){
                res=(res ^ arr[l-1]);
            }
            sol.push_back(res);
        }
        return sol;
    }
};