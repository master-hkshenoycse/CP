#include<bits/stdc++.h>
using namespace std;

int solve_dp(int l,int r,vector<int> &csum,vector<vector<int> >&dp){
    if(l>=r){
        return 0;
    }

    if(r==l+1){
        return csum[r]-csum[l-1];
    }

    if(dp[l][r] != -1){
        return dp[l][r];
    }

    int res=2e9;

    for(int i=l;i+1<=r;i++){
        res=min(res,(csum[i]-csum[l-1])+(csum[r]-csum[i])+solve_dp(l,i,csum,dp)+solve_dp(i+1,r,csum,dp));
    }

    return dp[l][r]=res;
}
int solve(vector<int> &A){
    int n=A.size();
    vector<vector<int> > dp(n+1,vector<int> (n+1,-1));
    vector<int> csum(n+1,0);
    for(int i=1;i<=n;i++){
        csum[i]=csum[i-1]+A[i-1];
    }

    return solve_dp(1,n,csum,dp);
}
int main(){
    vector<int> A;
    A={1,3,7};
    cout<<solve(A)<<endl;

    A={1,2,3,4};
    cout<<solve(A)<<endl;

}