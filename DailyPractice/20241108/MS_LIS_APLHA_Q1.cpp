#include<bits/stdc++.h>
using namespace std;

int solution(string &S){
    
    vector<int> dp(26,0);
    int n=S.size();
    int ans=0;
    for(int i=0;i<n;i++){
        int lim=S[i]-'a';
        int c=0;
        for(int j=0;j<=lim;j++){
            c=max(c,dp[j]);
        }
        dp[lim]=max(dp[lim],c+1);
        ans=max(ans,dp[lim]);
    }

    return n-ans;

}
int main(){
    string s;
    s="abc";
    cout<<solution(s)<<endl;

    s="bcca";
    cout<<solution(s)<<endl;
}