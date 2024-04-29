#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int n=nums1.size();
        vector<int> cons={nums2[0]-nums1[0],nums2[0]-nums1[1],nums2[0]-nums1[2]};
        int ans=INT_MAX;
        for(auto e:cons){
            int i=0,j=0;
            while(i<n and j<n-2){
                if(nums1[i]+e==nums2[j]){
                    i++;
                    j++;
                }else{
                    i++;
                }
            }

            if(j==n-2){
                ans=min(ans,e);
            }
        }

        return ans;
    }
};