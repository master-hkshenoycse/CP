#include<bits/stdc++.h>
using namespace std;
class Solution {
public: 

    int is_bob_win(int alice,int bob){
        if(alice==bob)return 0;
        if(bob==0 and alice==2) return 1;
        if(bob==1 and alice==0) return 1;
        if(bob==2 and alice==1) return 1;
        return -1;
    }
    int countWinningSequences(string s) {
        int n=s.size();
        vector<int> alice_seq(n);
        for(int i=0;i<n;i++){
            if(s[i]=='E'){
                alice_seq[i]=0;
            }else if(s[i]=='F'){
                alice_seq[i]=1;
            }else{
                alice_seq[i]=2;
            }
        }

        int mod=1e9+7;
        map<pair<int,int> ,int > dp;

        for(int i=0;i<n;i++){
            if(i==0){
                for(int j=0;j<3;j++){
                    dp[{is_bob_win(alice_seq[i],j),j}]=1;
                }
            }else{
                map<pair<int,int> ,int> tmp;

                for(auto it:dp){
                    int bal=it.first.first;
                    int prev=it.first.second;

                    if(bal+(n-i-1) < 0){
                        continue;
                    }
                    for(int j=0;j<3;j++){
                        if(j==prev){
                            continue;
                        }
                        int new_bal=bal+is_bob_win(alice_seq[i],j);
                        tmp[{new_bal,j}]=(tmp[{new_bal,j}]+it.second)%mod;
                    }
                }
                dp=tmp;
            }
        }

        int ans=0;
        for(auto it:dp){
            if(it.first.first > 0){
                ans=(ans+it.second)%mod;
            }
        }


        return ans;

        
    }
};