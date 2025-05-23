#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,n=nums1.size(),m=nums2.size();
        
        
        while(i<n and j<m){
            if(nums1[i]==nums2[j]){
                return nums1[i];
            }
            
            if(nums1[i]<nums2[j]){
                i++;
            }else{
                j++;
            }
        }
        
        return -1;
        
    }
};