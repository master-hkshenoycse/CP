#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int i=0,n=s.size(),curr_vow=0,req_vow=0,sp_cnt=0;

        while(i<n){
            int j=i,curr_vow=0;
            while(j<n && s[j] !=' '){
                if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'){
                    curr_vow++;
                }
                j++;
            }

            //cout<<req_vow<<" "<<curr_vow<<endl;
            if(sp_cnt==0){
                req_vow=curr_vow;
                sp_cnt++;
            }else{
                if(curr_vow==req_vow){
                    reverse(s.begin()+i,s.begin()+j);
                }
            }
        
            i=j+1;
        }
        return s;

    }   
};