#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool checkK(string &s,string &t,int k){
            int pos=0,matched=0;
            int n=s.size(),m=t.size();
    
            for(char ch:s){
                if(ch == t[pos]){
                    pos++;
                    if(pos==m){
                        pos=0;
                        matched++;
                        if(matched == k){
                            return 1;
                        }
                    }
                }
            }
    
            return 0;
        }
        string longestSubsequenceRepeatedK(string s, int k) {
            vector<int> freq(26,0);
            for(auto ch:s){
                freq[ch-'a']++;
            }
    
            vector<char> candidate;
            for(int i=25;i>=0;i--){
                if(freq[i]>=k){
                    candidate.push_back('a'+i);
                }
            }
    
            queue<string> q;
            for(char ch:candidate){
                q.push(string(1,ch));
            }
        
    
            string ans;
            while(q.size()>0){
                string curr =q.front();
                q.pop();
    
                if(curr.size() > ans.size()){
                    ans=curr;
                }
    
                for(char ch:candidate){
                    string next = curr+ch;
                    if(checkK(s,next,k)){
                        q.push(next);
                    }
                }
            }
    
            return ans;
        }
    };