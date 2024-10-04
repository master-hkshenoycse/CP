#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int> > coll(n);
        for(int i=0;i<n;i++){
            coll[i]={arr[i],i};
        }
        sort(coll.begin(),coll.end());
        int r=0;
        for(int i=0;i<n;i++){
            if(i==0 or coll[i][0] != coll[i-1][0]){
                r++;
            }
            arr[coll[i][1]]=r;
        }

        return arr;
    }
};