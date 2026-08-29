#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<vector<int> > a;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            a.push_back({nums[i],i});
        }
        
        sort(a.begin(),a.end());
        
        
        int i=0;
        while(i<n){
            vector<int> index;
            vector<int> vals;
            
            vals.push_back(a[i][0]);
            index.push_back(a[i][1]);
            
            int j=i+1;
            while(j<n and a[j][0]-a[j-1][0]<=limit){
                index.push_back(a[j][1]);
                vals.push_back(a[j][0]);
                j++;
            }
            
            sort(index.begin(),index.end());
            for(int k=0;k<index.size();k++){
                nums[index[k]]=vals[k];
            }
            
            i=j;
        }
        
        return nums;
    }
};