#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_time(string &s){
        int hour=(s[0]-'0')*10+(s[1]-'0');
        int minute=(s[3]-'0')*10+(s[4]-'0');
        return hour*60+minute;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> cnt(1450,0);
        for(auto t:timePoints){
            cnt[get_time(t)]++;
        }

        int ans=1500;
        int prev=-1,fs=-1;

        for(int i=0;i<=1440;i++){
            if(cnt[i]==0){
                continue;
            }
            if(cnt[i]>1){
                ans=min(ans,0);
            }else{
                if(prev!=-1){
                    ans=min(ans,min(i-prev,1440-(i-prev)));
                }
            }

            if(prev==-1){
                fs=i;
            }
            prev=i;
        }

        ans=min(ans,1440-(prev-fs));

        return ans;
        
    }
};