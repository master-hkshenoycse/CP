#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string removeKdigits(string num, int k) {
        string sol;
        for(char ch:num){
            while(sol.size()>0 and sol.back()>ch and k>0){
                sol.pop_back();//remove the element which is there as it can be replaced by a smaller element
                k--;
            }

            if(sol.size()>0 || ch!='0'){
                sol.push_back(ch);//to avoid leading zeros
            }
        }

        while(sol.size()>0 and k>0){
            sol.pop_back();
            k--;
        }

        if(sol.size()==0){
            sol.push_back('0');
        }

        return sol;
    } 
};