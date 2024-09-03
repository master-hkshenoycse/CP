#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_color(string c){
        int col=c[0]-'a';
        int row=c[1]-'0';
        
        if(row%2){
            if(col%2==0)return 1;
        }else{
            if(col%2)return 1;
        }
        
        return 0;
    }
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        return get_color(coordinate1)==get_color(coordinate2);
    }
};