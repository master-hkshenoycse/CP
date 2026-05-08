#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int p1=0;
        int p2=0;
        int ans=0;
        
        while(p1<n){
            while(p2<m and p2<p1)p2++;
            while(p2<m and nums1[p1]<=nums2[p2]){
                ans=max(ans,p2-p1);
                p2++;
            }
            p1++;
        }
        
        return ans;
    }
};