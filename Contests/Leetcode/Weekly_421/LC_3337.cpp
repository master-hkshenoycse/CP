#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector<vector<ll> > Matrix;

class Solution {
public:
    int mod=1e9+7;
    Matrix multiply(Matrix &A,Matrix &B){
        Matrix result(26,vector<ll> (26,0));
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                for(int k=0;k<26;k++){
                    result[i][j]=(result[i][j]+A[i][k]*B[k][j])%mod;
                }
            }
        }
        return result;
    }
    Matrix matrixExpo(Matrix base,int exp){
        Matrix result(26,vector<ll> (26,0));
        for(int i=0;i<26;i++){
            result[i][i]=1;
        }

        while(exp>0){
            if(exp%2){
                result=multiply(result,base);
            }
            base=multiply(base,base);
            exp/=2;
        }
        return result;
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<ll> cnt(26,0);
        for(auto ch:s){
            cnt[ch-'a']++;
        }

        Matrix transform(26,vector<ll>(26,0));
        for(ll i=0;i<26;i++){
            for(ll j=1;j<=nums[i];j++){
                transform[(i+j)%26][i]++;
            }
        }
        Matrix powert=matrixExpo(transform,t);
        vector<ll> ans(26,0);
        ll sol=0;
        for(ll i=0;i<26;i++){
            for(ll j=0;j<26;j++){
                ans[i]=(ans[i]+powert[i][j]*cnt[j])%mod;
            }
            sol=(sol+ans[i])%mod;
        }
        return sol;

    }
};