#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> n1,n2;
        int s=0;
        for(auto ch:version1){
            if(ch=='.'){
                n1.push_back(s);
                s=0;
            }else{a
                s=s*10+(ch-'0');
            }
        }
        n1.push_back(s);
        
        
        s=0;
        for(auto ch:version2){
            if(ch=='.'){
                n2.push_back(s);
                s=0;
            }else{
                s=s*10+(ch-'0');
            }
        }
        
        n2.push_back(s);
        
        int sz=min(n1.size(),n2.size());
        
        
        for(int i=0;i<sz;i++){
            if(n1[i]<n2[i]){
                return -1;
            }
            
            if(n2[i]<n1[i]){
                return 1;
            }
        }
        
        if(n1.size()>n2.size()){
            for(int i=sz;i<n1.size();i++){
                if(n1[i]>0)return 1;
            }
        }
        
        if(n2.size()>n1.size()){
            for(int i=sz;i<n2.size();i++){
                if(n2[i]>0)return -1;
            }
        }
        
        return 0;
    }
};