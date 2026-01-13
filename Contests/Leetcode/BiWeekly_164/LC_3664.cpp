#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int score(vector<string>& cards, char x) {
        int xx=0;
        map<char,int> left_x,right_x;
        
        for(auto c:cards){
            if(c[0]==x && c[1]==x){
                xx++;
            }else if(c[0]==x){
                left_x[c[1]]++;
            }else if(c[1]==x){
                right_x[c[0]]++;
            }
        }

        int totLeft=0,maxLeft=0,totRight=0,maxRight=0;

        for(auto p:left_x){
            totLeft+=p.second;
            maxLeft=max(maxLeft,p.second);
        }

        for(auto p:right_x){
            totRight+=p.second;
            maxRight=max(maxRight,p.second);
        }

        int pairsLeft=min(totLeft/2,totLeft-maxLeft);
        int pairsRight=min(totRight/2,totRight-maxRight);

        int pairs=pairsLeft+pairsRight;
        int ogPairs=pairs;

        int leftoverLeft=totLeft-2*pairsLeft;
        int leftoverRight=totRight-2*pairsRight;
        int leftoverSum = leftoverLeft+leftoverRight;
        int use_xx=min(xx,leftoverSum);
        pairs+=use_xx;
        xx-=use_xx;

        pairs+=min(ogPairs,xx/2);
        return pairs;

    }
};