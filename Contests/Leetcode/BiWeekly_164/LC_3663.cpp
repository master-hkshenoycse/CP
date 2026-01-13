#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int> cnt(10,0);
        while(n>0){
            cnt[n%10]++;
            n/=10;
        }

        int ret=0, cnt_req=INT_MAX;
        for(int i=0;i<10;i++){
            if(cnt[i]<cnt_req && cnt[i]>0){
                cnt_req=cnt[i];
                ret=i;
            }
        }

        return ret;
    }
};