#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string lexSmallest(string s) {
        string ret;

        int n=s.size();
        for(int i=1;i<=n;i++){
            string tmp=s;

            reverse(tmp.begin(),tmp.begin()+i);
            
            if(ret.size()==0){
                ret=tmp;
            }else{
                ret=min(ret,tmp);
            }

            tmp=s;
            reverse(tmp.end()-i,tmp.end());

            if(ret.size()==0){
                ret=tmp;
            }else{
                ret=min(ret,tmp);
            }
        }

        return ret;
    }
};