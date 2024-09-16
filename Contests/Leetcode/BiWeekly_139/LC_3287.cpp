#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        int n=nums.size();      
        //earliest end point of sequence of length k with OR=j;
        vector<vector<int> >  dp_prefix(k+1,vector<int> (151,n+1));
        vector<vector<int> >  dp_suffix(k+1,vector<int> (151,-1));
        dp_prefix[0][0]=0;
        dp_suffix[0][0]=n+1;

        for(int i=1;i<=n;i++){

            int val=nums[i-1];
            
            for(int len=k;len>=1;len--){
                for(int o=0;o<=130;o++){
                    if(dp_prefix[len-1][o]<n+1){
                        int nx_o=(o | val);
                        dp_prefix[len][nx_o]=min(dp_prefix[len][nx_o],i);
                    }
                }
            }
        }

        for(int i=n;i>=1;i--){
            int val=nums[i-1];

            for(int len=k;len>=1;len--){
                for(int o=0;o<=130;o++){
                    if(dp_suffix[len-1][o]!=-1){
                        int nx_o=(o | val);
                        dp_suffix[len][nx_o]=max(dp_suffix[len][nx_o],i);
                    }
                }
            }
        }


        int ans=0;
        for(int i=0;i<=130;i++){
            for(int j=0;j<=130;j++){
                if(dp_prefix[k][i] < dp_suffix[k][j]){
                    ans=max(ans, i ^ j);
                }
            }
        }

        return ans;

    }
};