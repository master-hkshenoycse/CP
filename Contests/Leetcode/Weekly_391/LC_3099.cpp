
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int get_sod(int x){
        if(x<10){
            return x;
        }
        return (x%10)+get_sod(x/10);
    }
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sod=get_sod(x);
        if(x%sod==0){
            return sod;
        }
        return -1;
    } 
};