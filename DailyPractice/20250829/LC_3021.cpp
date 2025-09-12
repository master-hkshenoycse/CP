#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long flowerGame(int n, int m) {
        ll ans=0;
        for(ll i=1;i<=n;i++){
            if(i%2){
                ans=ans+m/2ll;
            }else{
                ans=ans+(m+1ll)/2ll;
            }
        }
        return ans;
    }
};