#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_hash(vector<int> &cnt){
        int ret=0;
        for(int i=0;i<5;i++){
            ret=ret*2+cnt[i];
        }
        return ret;
    }
    int findTheLongestSubstring(string s) {
        vector<int> cnt(5,0);
        map<int,int> help;
        help[0]=0;
        int ans=0;
        int n=s.size();
        for(int i=1;i<=n;i++){
            char ch=s[i-1];
            if(ch=='a'){
                cnt[0]=(cnt[0]+1)%2;
            }else if(ch=='e'){
                cnt[1]=(cnt[1]+1)%2;
            }else if(ch=='i'){
                cnt[2]=(cnt[2]+1)%2;
            }else if(ch=='o'){
                cnt[3]=(cnt[3]+1)%2;
            }else if(ch=='u'){
                cnt[4]=(cnt[4]+1)%2;
            }

            int hash=get_hash(cnt);
            if(help.find(hash) != help.end()){
                ans=max(ans,i-help[hash]);
            }else{
                help[hash]=i;
            }

        }

        return ans;
    }
};