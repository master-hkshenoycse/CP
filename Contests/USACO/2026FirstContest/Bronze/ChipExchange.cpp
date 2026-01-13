#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    ll t;
    cin>>t;

    while(t--){
        ll A,B,ca,cb,fa;

        cin>>A>>B>>ca>>cb>>fa;

        ll lo=0,hi=1e18,ret=1e18;

        while(hi>=lo){
            ll mid=(hi+lo)/2;

            ll curr_A=A;
            curr_A += (B/cb)*ca;
            ll curr_B_left = (B%cb);
            ll ex_B_chunks = (curr_B_left+mid)/cb;
            ex_B_chunks = min(ex_B_chunks ,(ll)1e9);


            ll a_case_1 = curr_A + mid;
            ll a_case_2 = curr_A + ex_B_chunks*ca;

            
            ll a_case_2_1 = curr_A;

            if(mid>0 && curr_B_left + mid >= cb){
                ll b_with_ex = curr_B_left + mid;
                ll rem = b_with_ex % cb;
                rem++;

                a_case_2_1+=rem;
                

                ex_B_chunks = (curr_B_left+mid-rem)/cb;
                ex_B_chunks = min(ex_B_chunks ,(ll)1e9);
                a_case_2_1 = a_case_2_1 + ex_B_chunks*ca;
                a_case_2=min(a_case_2,a_case_2_1);
            }

            



            if(a_case_1>=fa && a_case_2>=fa){
                ret=min(ret,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
            
        }

        cout<<ret<<endl;
    }

    return 0;
}