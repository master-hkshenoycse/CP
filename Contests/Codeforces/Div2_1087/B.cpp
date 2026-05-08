#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        for(int i=0;i<n;i++){
            int ls_cnt=0,gt_cnt=0;
            for(int j=i+1;j<n;j++){
                if(a[i]<a[j])gt_cnt++;
                else if(a[i]>a[j]) ls_cnt++;
            }
            cout<<max(ls_cnt,gt_cnt)<<" ";
        }
        cout<<endl;
        
        
    }
}