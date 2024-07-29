#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size(),ans=0;

        for(int i=0;i<n;i++){
            int cnt_ls_left=0,cnt_gt_right=0,cnt_gt_left=0,cnt_ls_right=0;
            for(int j=0;j<i;j++){
                if(rating[j]<rating[i]){
                    cnt_ls_left++;
                }

                if(rating[j]>rating[i]){
                    cnt_gt_left++;
                }
            }

            for(int j=i+1;j<n;j++){
                if(rating[j]<rating[i]){
                    cnt_ls_right++;
                }

                if(rating[j]>rating[i]){
                    cnt_gt_right++;
                }
            }

            

            ans=ans+cnt_ls_left*cnt_gt_right;
            ans=ans+cnt_gt_left*cnt_ls_right;
        } 

        return ans;
    }
};