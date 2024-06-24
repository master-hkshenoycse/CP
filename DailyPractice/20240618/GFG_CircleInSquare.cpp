#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int rectanglesInCircle(int r) {
        // code here
        int ans=0;
        for(int a=1;a<=2*r;a++){
            int p=sqrt(4*r*r-a*a);
            //cout<<4*r*r-a*a<<" "<<sqrt(4*r*r-a*a)<<endl;
            ans=ans+p;
        }
        return ans;
    }
};