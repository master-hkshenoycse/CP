
#include<bits/stdc++.h>
using namespace std;

/*greedy startergy score of lower tokens and reduce power and gain of higher tokens and reduce score*/
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        int lo=0,hi=n-1;
        sort(tokens.begin(),tokens.end());
        int score=0,ans=0;

        while(hi>=lo){
            if(tokens[lo]<=power){
               power-=tokens[lo];
               score++;
               lo++;
               ans=max(ans,score);
            }else{
                if(score>0){
                    score--;
                    power+=tokens[hi];
                    hi--;
                }else{
                    break;
                }
            }
        }
        
        return ans;
    }
};