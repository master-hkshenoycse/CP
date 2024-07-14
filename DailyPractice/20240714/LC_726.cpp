#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void compute(string &s,map<string,int> &counts){
        int n=s.size();

        stack<int> st;//stores the multiplying factor;
        st.push(1);

        string elem;
        int factor=1;

        for(int i=0;i<n;){
            char ch=s[i];
            if(ch>='0' and ch<='9'){
                int v=0,expo=1;
                do{
                    v+=(s[i]-'0')*expo;
                    i++;
                    expo*=10;
                }while(s[i]>='0' and s[i]<='9');

                factor=v;
            }else if(ch==')'){
                st.push(factor*st.top());
                factor=1;
                i++;
            }else if(ch>='A' and ch<='Z'){
                elem+=ch;
                reverse(elem.begin(),elem.end());
                counts[elem]+=factor*st.top();
                factor=1;
                elem.clear();
                i++;
            }else if(ch>='a' and ch<='z'){
                elem+=ch;
                i++;
            }else{
                st.pop();
                i++;
            }
        }

    }
    string countOfAtoms(string formula) {
        map<string,int> counts;

        //reverse the formula
        reverse(formula.begin(),formula.end());

        compute(formula,counts);

        string sol;
        for(auto it:counts){
            sol+=it.first;
            if(it.second>1){
                sol+=to_string(it.second);
            }
        }

        return sol;
        
    }
};