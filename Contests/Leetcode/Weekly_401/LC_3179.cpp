#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int> a(n,1);

        int mod=1e9+7;

        while(k--){
            int cs=0;
            for(int i=0;i<n;i++){
                
                cs=(cs+a[i])%mod;
                a[i]=cs;      
            }
        }

        return a[n-1];
    }
};