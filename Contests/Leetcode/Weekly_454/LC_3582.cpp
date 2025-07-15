#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string generateTag(string caption) {
            int ls_space = -1;
            string ret = "#";
            
            for(int i=0;i<caption.size();i++){
                if(caption[i]==' '){
                    ls_space = i;
                    continue;
                }
                if(ls_space !=-1 && ls_space+1==i && ret.size()>1){
                    if(caption[i]>='A' && caption[i]<='Z'){
                        ret+=caption[i];
                    }else{
                        ret+=char('A'+(caption[i]-'a'));
                    }
                }else{
                    if(caption[i]>='a' && caption[i]<='z'){
                        ret+=caption[i];
                    }else{
                        ret+=char('a'+(caption[i]-'A'));
                    }
                }
            }
    
            int sz = ret.size();
            ret=ret.substr(0,min(100,sz));
    
            return ret;
        }
    };