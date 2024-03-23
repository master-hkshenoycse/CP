#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int dp[35][2][2];

    string get_string(int n){
        string ret;

        while(n>0){
            ret+=char('0'+(n%2));
            n/=2;
        }

        reverse(ret.begin(),ret.end());
        return ret;
    }
    int solve(int ind,int ti,int prev,string &s){
        if(ind==s.size()){
            return 1;
        }

        if(dp[ind][ti][prev] !=  -1){
            return dp[ind][ti][prev];
        }

        int res=0;
        int d=s[ind]-'0';

        if(ti){

            for(int i=0;i<=d;i++){

                if(i==1 and prev){
                    continue;
                }

                res=res+solve(ind+1,i==d,i==1,s);
            }

        }else{

            for(int i=0;i<=1;i++){
                if(i==1 and prev){
                    continue;
                }
                res=res+solve(ind+1,0,i==1,s);
            }
        }

        return dp[ind][ti][prev]=res;

    }
    int findIntegers(int n) {
        string num=get_string(n);
        memset(dp,-1,sizeof(dp));

        return solve(0,1,0,num);

    }
};