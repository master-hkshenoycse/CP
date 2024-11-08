#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isBalanced(string num) {
        int n=num.size(),res=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                res=res+(num[i]-'0');
            }else{
                res=res-(num[i]-'0');
            }
        }
        return res==0;
    }
};