#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll dp[17][2][2][2];
    ll solve(int idx,int curr_carry, int za, int zb, string &str){
        if(idx == str.size()){
            return curr_carry==0;
        }

        if(dp[idx][curr_carry][za][zb] != -1){
            return dp[idx][curr_carry][za][zb];
        }

        ll ret=0;

        for(int x=0;x<=9;x++){
            for(int y=0;y<=9;y++){
                int nx_carry=(x+y+curr_carry)/10;
                int curr_dig=(x+y+curr_carry)%10;

                if(za==1 && x>0){
                    continue;
                }

                if(zb==1 && y>0){
                    continue;
                }

                if(x==0 && idx==0){
                    continue;
                }

                if(y==0 && idx==0){
                    continue;
                }

                if(curr_dig == str[idx]-'0'){
                    ret=ret+solve(idx+1,nx_carry,x==0,y==0,str);
                }
            }
        }
        
        return dp[idx][curr_carry][za][zb]=ret;
    }
    long long countNoZeroPairs(long long n) {
        memset(dp,-1,sizeof(dp));
        string str_num = to_string(n);
        reverse(str_num.begin(),str_num.end());

        return solve(0,0,0,0,str_num);
    }
};