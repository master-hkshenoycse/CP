#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int totalNumbers(vector<int>& digits) {
            vector<int> cnt(10,0);
            for(auto d:digits){
                cnt[d]++;
            }
            
            int ans=0;
            for(int i=100;i<=999;i+=2){
                vector<int> req(10,0);
                string tmp=to_string(i);
                req[tmp[0]-'0']++;
                req[tmp[1]-'0']++;
                req[tmp[2]-'0']++;
                int f=1;
                for(int j=0;j<10;j++){
                    if(cnt[j] <req[j]){
                        f=0;
                    }
                }
                
                ans=ans+f;
            }
            return ans;
        }
    };