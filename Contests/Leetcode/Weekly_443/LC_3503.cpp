#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool isp(string &s){
            int n=s.size();
            for(int i=0;i<n/2;i++){
                if(s[i] != s[n-i-1]){
                    return 0;
                }
            }
            return 1;
        }
        vector<string> get_sub(string &s){
            int n=s.size();
            vector<string> ret;
            for(int i=0;i<n;i++){
                string tmp;
                for(int j=i;j<n;j++){
                    tmp+=s[j];
                    ret.push_back(tmp);
                }
            }
            return ret;
        }
        int longestPalindrome(string s, string t) {
            vector<string> sub_a,sub_b;
            sub_a = get_sub(s);
            sub_b = get_sub(t);
            
            int ans=0;
            
            for(auto p:sub_a){
                
                int len_p=p.size();
                
                if(isp(p))ans=max(ans,len_p);
            }
            
            for(auto q:sub_b){
                int len_q=q.size();
                if(isp(q))ans=max(ans,len_q);
            }
            
            for(auto p:sub_a){    
                for(auto q:sub_b){
                    string tmp;
                    tmp+=p;
                    tmp+=q;
                    
                    if(isp(tmp)){
                        int len=tmp.size();
                        ans=max(ans,len);
                    }
                }
            }
            
    
            return ans;
            
        }
    };