#include<bits/stdc++.h>
#include <iterator>
#include <iostream>
#include <numeric>
#include <math.h>
#define ll long long
#define ull long
#define mpa make_pair
#define pb push_back
#define ff first
#define pii pair<ll,ll>
#define dd long double
#define trace(x) cerr << #x << " : " << x << endl
#define ss second
#define boost ios_base::sync_with_stdio(0)
#define forp(i,a,b) for(ll i=a;i<=b;i++)
#define rep(i,n)    for(ll i=0;i<n;++i)
#define ren(i,n)    for(ll i=n-1;i>=0;i--)
#define forn(i,a,b) for(ll i=a;i>=b;i--)
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end();
#define sc(x) scanf("%lld",&x)
#define clr(x,val) memset(x,val,sizeof(x))
#define pr(x) printf("%lld\n",x) 
#define gc getchar
#define pdd pair<dd,dd>
#define prec(x) cout<<fixed<<setprecision(x)
#define fre freopen("rental.in","r",stdin),freopen("rental.out","w",stdout)
#define arr array 
using namespace std;



ll check(vector<vector<ll> >&board,vector<vector<ll> >&points){
    ll points_r=0,points_b=0;
    ll cnt_left=9;


    for(ll i=0;i<3;i++){
        for(ll j=0;j<3;j++){

            if(board[i][j]==0){
                points_r+=points[i][j];
                cnt_left--;
            }

            if(board[i][j]==1){
                points_b+=points[i][j];
                cnt_left--;
            }
        }
    }

    

    for(ll i=0;i<3;i++){
        if(board[i][0]==board[i][1] and board[i][1]==board[i][2] and board[i][0]!=-1){
            return board[i][0];
        }
    }

    for(ll j=0;j<3;j++){

        if(board[0][j]==board[1][j] and board[1][j]==board[2][j] and board[0][j] !=-1){
            return board[0][j];
        }
    }



    if(board[0][0]==board[1][1] and board[1][1]==board[2][2] and board[1][1] != -1){
        return board[1][1];
    }

    if(board[0][2]==board[1][1] and board[1][1]==board[2][0] and board[1][1] != -1){
        return board[1][1];
    }

    if(cnt_left==0){
        if(points_r > points_b){
            return 0;
        }else{
            return 1;
        }
    }

    return -1;

}

ll rec(vector<vector<ll> >&board,vector<vector<ll> >&points,ll ch){
    
    ll ret=check(board,points);

    if(ret != -1){
        return ret;
    }


    if(ret){


        for(ll i=0;i<3;i++){
            for(ll j=0;j<3;j++){
                if(board[i][j]==-1){
                    
                    board[i][j]=ch;

                    if(rec(board,points,1-ch)==ch){
                        board[i][j]=-1;
                        return ch;
                    }    

                    board[i][j]=-1;

                    


                }
            }
        } 
        

    }

    return 1-ch;



}
void solve(ll tc){
    vector<vector<ll> > board(3,vector<ll>(3,-1));
    vector<vector<ll> > points(3,vector<ll> (3));

    for(ll i=0;i<3;i++){
        for(ll j=0;j<3;j++){
            cin>>points[i][j];
        }
    }


    if(rec(board,points,0) == 0){
        cout<<"Takahashi"<<endl;
    }else{
        cout<<"Aoki"<<endl;
    }





}
int main(){
    boost;

    //pre_cum();
    //prec(10);
	//fre;


    ll t=1;
    ll tc=1;
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}