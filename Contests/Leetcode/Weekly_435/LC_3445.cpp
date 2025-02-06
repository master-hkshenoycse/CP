#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDifference(string s, int k) {
        
        int n=s.size();
        int ans=INT_MIN;

        for(char p='0';p<='4';p++){
            for(char q='0';q<='4';q++){

                if(p==q){
                    continue;
                }
                //p is odd,q is even;
                vector<int> c_p(n+1,0),c_q(n+1,0);

                multiset<int> c_00,c_01,c_10,c_11;
                int j=0;

                for(int i=1;i<=n;i++){

                    if(s[i-1]==p){
                        c_p[i]=1;
                    }

                    if(s[i-1]==q){
                        c_q[i]=1;
                    }

                    c_p[i]+=c_p[i-1];
                    c_q[i]+=c_q[i-1];

                    while(i-j>=k and c_q[i]-c_q[j]>0){

                        if(c_p[j]%2==0 and c_q[j]%2==0){
                            c_00.insert(c_p[j]-c_q[j]);
                        }

                        if(c_p[j]%2==0 and c_q[j]%2==1){
                            c_01.insert(c_p[j]-c_q[j]);
                        }

                        if(c_p[j]%2==1 and c_q[j]%2==0){
                            c_10.insert(c_p[j]-c_q[j]);
                        }

                        if(c_p[j]%2==1 and c_q[j]%2==1){
                            c_11.insert(c_p[j]-c_q[j]);
                        }

                        j++;
                    }   

                    if(c_p[i]%2==0 and c_q[i]%2==0){
                        if(c_10.size()>0){
                            ans=max(ans,c_p[i]-c_q[i]-*c_10.begin());
                        }
                    }

                    if(c_p[i]%2==0 and c_q[i]%2==1){
                        if(c_11.size()>0){
                            ans=max(ans,c_p[i]-c_q[i]-*c_11.begin());
                        }
                    }

                    if(c_p[i]%2==1 and c_q[i]%2==0){
                        if(c_00.size()>0){
                            ans=max(ans,c_p[i]-c_q[i]-*c_00.begin());
                        }
                    }

                    if(c_p[i]%2==1 and c_q[i]%2==1){
                        if(c_01.size()>0){
                            ans=max(ans,c_p[i]-c_q[i]-*c_01.begin());
                        }
                    }
                }

                cout<<p<<" "<<q<<" "<<ans<<endl;

            }
        }

        return ans;
    }
};