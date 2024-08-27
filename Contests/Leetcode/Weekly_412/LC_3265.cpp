#include<bits/stdc++.h>
using namespace std;
map<int,set<int> > equals;
class Solution {
public:
    int get_val(string &s){
        int ret=0;
        for(auto ch:s){
            ret=ret*10+(ch-'0');
        }
        return ret;
    }

    int countPairs(vector<int>& nums) {
        map<int,int> cnt;
        int ans=0;

        for(auto e:nums){

            {
                string s=to_string(e);
                int sz=s.size();
                equals[e].insert(e);

                for(int i=0;i<sz;i++){
                    for(int j=i+1;j<sz;j++){
                        if(s[i] != s[j]){
                            swap(s[i],s[j]);
                            int value=get_val(s);
                            equals[value].insert(e);
                            equals[e].insert(value);
                            swap(s[i],s[j]);
                        }
                    }
                }
            }
        }

        for(auto e:nums){
            for(auto v:equals[e]){
                if(cnt.find(v) != cnt.end()){
                    //cout<<e<<" "<<v<<" "<<cnt[v]<<endl;
                    ans=ans+cnt[v];
                }
            }

            cnt[e]++;
        }

        return ans;
    }
};