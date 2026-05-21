#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string> h1,h2;
        
        for(auto e:arr1){
            string s=to_string(e);
            int sz=s.size();
            string tmp;
            
            for(int i=0;i<sz;i++){
                tmp+=s[i];
                h1.insert(tmp);
            }
        }
        
        for(auto e:arr2){
            string s=to_string(e);
            int sz=s.size();
            string tmp;
            
            for(int i=0;i<sz;i++){
                tmp+=s[i];
                h2.insert(tmp);
            }
        }
        
        int ans=0;
        for(auto e:h1){
            if(h2.find(e)!=h2.end()){
                ans=max(ans,(int)(e.size()));
            }
        }
        
        return ans;
    }
};