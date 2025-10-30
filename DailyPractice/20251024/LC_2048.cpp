#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int chk(int n){
        vector<int> cnt(10,0);
        while(n){
            cnt[n%10]++;
            n/=10;
        }
        
        for(int i=0;i<=9;i++){
            if(cnt[i]>0 and cnt[i]!=i){
                return 0;
            }
        }
        return 1;
    }
    int nextBeautifulNumber(int n) {
        
        for(int i=n+1;i<=1224444;i++){
            if(chk(i)){
                return i;
            }
        }
        return 0;
        
    }
};