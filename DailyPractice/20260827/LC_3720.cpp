#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void complete_string(string &curr, vector<int> cnt){
        for(int i=0;i<26;i++){
            while(cnt[i]>0){
                curr+=char('a'+i);
                cnt[i]--;
            }
        }
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26,0);
        for(auto ch:s){
            cnt[ch-'a']++;
        }

        string ret;
        string curr;

        int n=target.size();
        for(int i=0;i<n;i++){
            int curr_ch=target[i]-'a';
                       
            for(int j=curr_ch+1;j<26;j++){
                if(cnt[j]>0){
                    string tmp=curr;
                    tmp+=char('a'+j);
                    cnt[j]--;
                    
                    complete_string(tmp,cnt);
                    cout<<i<<" "<<tmp<<endl;

                    if(ret.size()==0){
                        ret=tmp;
                    }else{
                        ret=min(ret,tmp);
                    }

                    cnt[j]++;
                    break;
                }
            }
            
            if(cnt[curr_ch]>0){
                curr+=char('a'+curr_ch);
                cnt[curr_ch]--;
            }else{
                break;
            }

        }

        return ret;
    }
};