#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        
        if(n<=1)return nums;

        int mid=n/2;

        vector<int> nums_l,nums_r;
        for(int i=0;i<n;i++){
            if(i<mid)nums_l.push_back(nums[i]);
            else nums_r.push_back(nums[i]);
        }

    
        nums_l=sortArray(nums_l);
        nums_r=sortArray(nums_r);
        vector<int> tmp;

        int i=0,j=mid;
        
        while(i<mid and j<n){
            if(nums_l[i] <= nums_r[j-mid]){
                tmp.push_back(nums_l[i]);
                i++;
            }else{
                tmp.push_back(nums_r[j-mid]);
                j++;
            }
        }

        while(i<mid){
            tmp.push_back(nums_l[i]);
            i++;
        }

        while(j<n){
            tmp.push_back(nums_r[j-mid]);
            j++;
        }

            
        return tmp;
    }
};