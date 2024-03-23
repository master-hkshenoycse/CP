#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
vector<int> Series(int n) {
    // Code here
    vector<int> ret(n+1,0);
    ret[1]=1;
    
    for(int i=2;i<=n;i++){
        ret[i]=(ret[i-1]+ret[i-2])%mod;
    }
    
    return ret;
}