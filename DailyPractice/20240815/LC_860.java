
public class LC_860 {
    public boolean lemonadeChange(int[] bills) {
        int n=bills.length,cnt_5=0,cnt_10=0,cnt_20=0;
        
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                cnt_5++;
            }else if(bills[i]==10){
                if(cnt_5==0){
                    return false;
                }
                cnt_5--;
                cnt_10++;
            }else if(bills[i]==20){
                if(cnt_5>=3 || (cnt_5>=1 && cnt_10>=1)){
                    if(cnt_5>=1 && cnt_10>=1){
                        cnt_5--;
                        cnt_10--;
                    }else{
                        cnt_5-=3;
                    }
                }else{
                    return false;
                }

                cnt_20++;
            }
        }

        return true;
    }
}
