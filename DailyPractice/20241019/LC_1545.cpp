#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char findKthBit(int n, int k) {
        
        if(n==1){
            return '0';
        }

        cout<<n<<" "<<k<<endl;

        int len=(1<<n)-1;
        if(k==(len+1)/2){
            return '1';
        }

        if(k<(len+1)/2){
            return findKthBit(n-1,k);
        }

        int len_prev=(len)/2;
        int off_set=k-(len+1)/2;
        char out=findKthBit(n-1,len_prev-off_set+1);
        if(out=='0'){
            return '1';
        }

        return '0';
    }
};