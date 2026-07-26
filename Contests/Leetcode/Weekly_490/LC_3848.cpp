#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isDigitorialPermutation(int n) {
        string num=to_string(n);
        sort(num.begin(),num.end());

        vector<int> fact(10);
        fact[0]=1;
        fact[1]=1;
        for(int i=2;i<=9;i++)
            fact[i]=(fact[i-1]*i);
        int sum=0;
        for(auto d:num){
            sum=sum+fact[d-'0'];
        }
        do{
            int curr=0;
            if(num[0]=='0')
                continue;
                
            for(auto d:num)
                curr=curr*10+(d-'0');
            
            if(curr==sum)
                return 1;

        }while(next_permutation(num.begin(),num.end()));    

        return 0;
    }
};