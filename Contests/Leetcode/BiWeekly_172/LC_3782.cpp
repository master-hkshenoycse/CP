#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long lastInteger(long long n) {
        ll head=1;
        ll step=1;
        ll rem=n,totvar=n;
        bool left=true;

        while(rem>1){
            if(left==0){
                if(rem%2==0)head+=step;
            }
            rem=(rem+1)/2;
            step=step*2;
            left=!left;
        }

        return head;
    }
};