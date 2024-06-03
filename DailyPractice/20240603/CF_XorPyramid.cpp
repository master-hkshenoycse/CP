/*https://codeforces.com/problemset/problem/983/B*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;

    vector<int> a(n+1);
    vector<vector<int> > rec_pyramid(n+1,vector<int> (n+1));//value in each level;
    vector<vector<int> >f(n+1,vector<int> (n+1));//value of function
    vector<vector<int> >dp(n+1,vector<int> (n+1));

    for(int i=1;i<=n;i++){
        cin>>a[i];
        rec_pyramid[1][i]=a[i];
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            rec_pyramid[i][j]=(rec_pyramid[i-1][j] ^ rec_pyramid[i-1][j+1]);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int len=j-i+1;
            f[i][j]=rec_pyramid[len][i];
        }
    }

    //dp to get max contigous in range
    for(int len=1;len<=n;len++){
        for(int st=1;st+len-1<=n;st++){
            int en=st+len-1;
            dp[st][en]=f[st][en];

            if(st+1<=en)dp[st][en]=max(dp[st][en],dp[st+1][en]);
            if(st<=en-1)dp[st][en]=max(dp[st][en],dp[st][en-1]);
            if(st+1<=en-1)dp[st][en]=max(dp[st][en],dp[st+1][en-1]);
        }
    }

    int q;
    cin>>q;

    int l,r;
    while(q--){
        cin>>l>>r;
        cout<<dp[l][r]<<endl;
    }



    

}