#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> pos,ele;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                pos.push_back(i);
                ele.push_back(nums[i]);
            }
        }


        int sz=ele.size();
        if(sz==0)
            return nums;
        k%=sz;

        reverse(ele.begin(),ele.begin()+k);
        reverse(ele.begin()+k,ele.end());
        reverse(ele.begin(),ele.end());
        for(int i=0;i<sz;i++)
            nums[pos[i]]=ele[i];
        
        return nums;
    }
};