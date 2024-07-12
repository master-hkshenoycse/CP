#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_sol(string s,int x,int y,char c1,char c2){
        vector<char> st;
        int ret=0;
        for(auto ch:s){
            if(st.size()>0 and st.back()==c1 and ch==c2){
                ret+=x;
                st.pop_back();
            }else{
                st.push_back(ch);
            }
        }

        vector<int> tmp;
        for(auto ch:st){
            if(tmp.size()>0 and ch==c1 and tmp.back()==c2){
                tmp.pop_back();
                ret+=y;
            }else{
                tmp.push_back(ch);
            }
        }

        return ret;

        

    }
    int maximumGain(string s, int x, int y) {
       int ans=get_sol(s,x,y,'a','b');
       ans=max(ans,get_sol(s,y,x,'b','a'));
       return ans; 
    }
};