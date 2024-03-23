#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int minStickers(vector<string>& stickers, string target) {

        int n=target.size();
        int N=(1<<n);

        vector<int> dp(N,1e6);
        dp[0]=0;

        //iterate over masks
        for(int i=0;i<N;i++){
            
            if(dp[i] != 1e6){
                
                //iterate over each sticker and see what mask it creates
                for(auto s:stickers){
                    int curr=i;

                    for(auto ch:s){
                        for(int r=0;r<n;r++){
                            
                            if(target[r]==ch and (curr & (1<<r))==0){
                                curr=(curr |(1<<r));
                               
                                break;
                            }
                        }
                    }


                    dp[curr]=min(dp[curr],dp[i]+1);
                }

            }
        }
        
        if(dp[N-1]==1e6){
            dp[N-1]=-1;
        }
        return dp[N-1];
    }
};