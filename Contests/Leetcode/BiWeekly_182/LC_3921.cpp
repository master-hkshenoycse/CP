#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score=0,counter=0;
        for(auto s:events){
            if(s[0]>='0' && s[0]<='6'){
                score+=(s[0]-'0');
            }else if(s=="W"){
                counter++;
            }else if(s=="WD"){
                score++;
            }else if(s=="NB"){
                score++;
            }

            if(counter==10){
                break;
            }
        }   

        return {score,counter};
    }
};