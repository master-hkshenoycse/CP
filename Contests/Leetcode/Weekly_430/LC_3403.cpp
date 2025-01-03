#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string answerString(string word, int numFriends) {
        int n=word.size();
        int len_req=n-numFriends+1;
        string sol;

        if(numFriends==1){
            return word;
        }

        int max_ch=-1;
        for(auto ch:word){
            max_ch=max(max_ch,ch-'a');
        }

        for(int i=0;i<word.size();i++){
            if(word[i]-'a'==max_ch){
                int len=min(len_req,n-i);
                string curr=word.substr(i,len);

                if(curr > sol){
                    sol=curr;
                }

            }
        }

        return sol;

    }
};