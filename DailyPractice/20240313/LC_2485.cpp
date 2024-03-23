class Solution {
public:
    int pivotInteger(int n) {
        for(int i=1;i<=n;i++){
            int c=(i*i+i)/2;
            int tot=(n*n+n)/2;
            //cout<<i<<" "<<c<<" "<<tot<<endl;
            
            if(c==tot-c+i){
                return i;
            }
        }
        return -1;
    }
};