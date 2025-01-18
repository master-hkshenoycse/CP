#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans=0,m=nums2.size();
        vector<int> cnt(65,0);
        for(auto e:nums2){
            for(int j=0;j<=30;j++){
                if(e & (1<<j)){
                    cnt[j]++;
                }
            }
        }
        
        vector<int> cnt_final(65,0);
        for(auto e:nums1){
            for(int j=0;j<=30;j++){
                if(e & (1<<j)){
                    cnt_final[j]+=(m-cnt[j]);
                }else{
                    cnt_final[j]+=cnt[j];
                }
            }
        }
        
        for(int j=0;j<=30;j++){
            if(cnt_final[j]%2){
                ans=ans+(1<<j);
            }
        }
            
            
        return ans;
    }
};