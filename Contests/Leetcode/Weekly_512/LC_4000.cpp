#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_sod(int n){
        int ret=0;
        while(n>0){
            ret=ret+(n%10);
            n/=10;
        }
        return ret;
    }
    int cnt_dig(int n){
        int cnt=0;
        while(n>0){
            cnt++;
            n/=10;
        }
        return cnt;
    }
    int largestInteger(int n, int s) {
        
        for(int i=99999;i>=0;i--){
            if(cnt_dig(i)<=n && get_sod(i)==s)
                return i;
        }

        return -1;
    }
};