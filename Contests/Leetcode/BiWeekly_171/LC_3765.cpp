#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isp(int n){
        if(n==1)
            return 0;

        for(int i=2;i*i<=n;i++){
            if(n%i==0)
                return 0;
        }
        return 1;
    }
    bool completePrime(int num) {
        string num_str=to_string(num);
        int n=num_str.size();

        int curr=0;
        for(int i=0;i<n;i++){
            curr=curr*10+(num_str[i]-'0');
            if(isp(curr)==0)
                return 0;
        }

        int po_10=1;
        curr=0;
        for(int i=n-1;i>=0;i--){
            curr=curr+(num_str[i]-'0')*po_10;
            if(isp(curr)==0)
                return 0;
            po_10=po_10*10;
        }

        return 1;
    }
};