#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int do_one_char(string &s){
        int n=s.size(),ans=0;
        for(int i=1;i<=n;){
            int j=i+1,c=1;
            while(j<=n && s[j-1]==s[i-1]){
                j++;
                c++;
            }
            ans=max(ans,c);
            i=j;
        }
        return ans;
    }
    int do_two_char(string &s, char c1,char c2){
        map<int,int> help;

        int n=s.size(),ret=0,cnt_1=0,cnt_2=0;
        help[0]=0;

        for(int i=1;i<=n;i++){
            if(s[i-1]==c1 || s[i-1]==c2){

                if(s[i-1]==c1){
                    cnt_1++;
                }else{
                    cnt_2++;
                }

                if(help.find(cnt_1-cnt_2) != help.end()){
                    ret=max(ret,i-help[cnt_1-cnt_2]);
                }else{  
                    help[cnt_1-cnt_2]=i;
                }


            }else{
                help.clear();
                help[0]=i;
                cnt_1=0;
                cnt_2=0;
            }
        }
        
        return ret;

    }

    int do_three_char(string &s){
        int ans=0,n=s.size(),ca=0,cb=0,cc=0;
        map<pair<int,int>,int > help;
        help[{0,0}]=0;

        for(int i=1;i<=n;i++){
            char ch=s[i-1];
            if(ch=='a'){
                ca++;
            }

            if(ch=='b'){
                cb++;
            }

            if(ch=='c'){
                cc++;
            }
           
            if(help.find({ca-cb,ca-cc}) != help.end()){
                ans=max(ans,i-help[{ca-cb,ca-cc}]);
            }else{
                help[{ca-cb,ca-cc}]=i;
            }
        }
        return ans;
    }
    int longestBalanced(string s) {
        int ans=do_one_char(s);
        ans=max(ans,do_three_char(s));
        ans=max(ans,do_two_char(s,'a','b'));
        ans=max(ans,do_two_char(s,'a','c'));
        ans=max(ans,do_two_char(s,'c','b'));
        return ans;
    }
};