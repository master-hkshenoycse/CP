#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ops_req[805];
    set<int> good_set;
    int mod=1e9+7;
    int dp[805][805][2];

    int get_cnt(int n){
        int c=0;
        while(n>0){
            c++;
            n=(n & (n-1));
        }
        return c;
    }
       int solve(int ind,int cnt_set,int ti,string &s){
        if(ind==s.size()){
            if(good_set.find(cnt_set) == good_set.end()){
                return 0;
            }
            return ti==0;
        }

        if(dp[ind][cnt_set][ti] != -1){
            return dp[ind][cnt_set][ti];
        }

        int res=0;
        if(ti){
            int l=s[ind]-'0';
            for(int i=0;i<=l;i++){
                res=(res+solve(ind+1,cnt_set+i,i==l,s))%mod;
            }

        }else{
            for(int i=0;i<2;i++){
                res=(res+solve(ind+1,cnt_set+i,0,s))%mod;
            }
        }


        return dp[ind][cnt_set][ti]=res;
    }
    int countKReducibleNumbers(string s, int k) {
        int n=s.size();
        ops_req[1]=0;
        for(int i=1;i<=n;i++){
            int cnt=get_cnt(i);
            if(i>1){
                ops_req[i]=1+ops_req[cnt];
            }

            if(ops_req[i]<=k-1){
                good_set.insert(i);
            }
        }

        memset(dp,-1,sizeof(dp));

        return solve(0,0,1,s);

    }
};