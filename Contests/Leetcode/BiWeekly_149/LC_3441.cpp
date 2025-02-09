#include<bits/stdc++.h>
using namespace std;
#define arr array 
int dp[50001][27][4];
arr<int,3> state_graph[50001][27][4];
string s;
int n;

class Solution {

public:
    int solve(int ind,int ls,int cnt){
        if(ind==n){
            return 0;
        }

        if(dp[ind][ls][cnt] != -1){
            return dp[ind][ls][cnt];
        }

        int ret=1e9;

        if(cnt==3 && n-ind>=3){
            for(int ch=0;ch<26;ch++){
                if(ch==ls){
                    int ops=abs(ch-(s[ind]-'a'))+solve(ind+1,ch,min(cnt+1,3));
                    if(ops < ret){
                        ret=ops;
                        state_graph[ind][ls][cnt]={ind+1,ch,min(cnt+1,3)};
                    }
                }else{
                    int ops=abs(ch-(s[ind]-'a'))+solve(ind+1,ch,1);
                    if(ops < ret){
                        ret=ops;
                        state_graph[ind][ls][cnt]={ind+1,ch,1};
                    }
                    
                }
            }
        }else if (ls < 26){
            ret=abs(ls-(s[ind]-'a'))+solve(ind+1,ls,min(cnt+1,3));
            state_graph[ind][ls][cnt]={ind+1,ls,min(cnt+1,3)};
        }
        return dp[ind][ls][cnt] = ret;
    }
    string minCostGoodCaption(string caption) {
        
        s=caption;
        n=s.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<=26;j++){
                for(int l=0;l<=3;l++){
                    dp[i][j][l]=-1;
                }
            }
        }

        int ret=solve(0,26,3);

        string sol;
        if(ret == 1e9){
            return sol;            
        }

        arr<int,3> curr={0,26,3};
        while(1){
            auto nx=state_graph[curr[0]][curr[1]][curr[2]];
            sol+=char('a'+nx[1]);
            if(sol.size()==n){
                break;
            }
            curr=nx;
        }

        return sol;

    }
};