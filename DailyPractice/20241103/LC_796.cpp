#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.size() != goal.size()){
            return 0;
        }
        int n=goal.size();
        string tmp=goal;
        tmp+='$';
        tmp+=s;
        tmp+=s;

        int sz=tmp.size();
        vector<int> lps(sz+1,0);

        int i=1,len=0;
        while(i<sz){
            if(tmp[len]==tmp[i]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len==0){
                    i++;
                }else{
                    len=lps[len-1];
                }
            }
        }
        
        for(int i=0;i<sz;i++){
            if(lps[i]==n){
                return 1;
            }
        }

        return 0;

    }
}; 