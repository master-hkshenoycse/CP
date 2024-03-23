#include<bits/stdc++.h>
using namespace std;


int maxSum(int n){
    
    vector<int> dp(n+1,0);
    dp[0]=0;
    
    for(int i=1;i<=n;i++){
        dp[i]=i;
        dp[i]=max(dp[i],dp[i/2]+dp[i/3]+dp[i/4]);
    }
    
    return dp[n];
}

int main(){

    return 0;
}

/*https://www.geeksforgeeks.org/problems/maximum-sum-problem2211/1*/