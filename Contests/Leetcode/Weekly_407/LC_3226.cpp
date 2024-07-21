#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minChanges(int n, int k) {
        int ans=0;
        for(int i=0;i<=20;i++){
            if(k & (1<<i)){
                if((n & (1<<i))==0){
                    return -1;
                }
            }else{
                if(n & (1<<i)){
                    ans++;
                }
            }
        }
        return ans;
    }
};