import java.util.*;

class PairElement implements Comparable<PairElement> {

    public int value;
    public int freq;

    PairElement(int value,int freq){
        this.value=value;
        this.freq=freq;
    }

    @Override
    public int compareTo(PairElement other){
        if(other.freq==this.freq){
            return other.value-this.value;
        }
        return this.freq-other.freq;
    }

}
class Solution {
    public int[] frequencySort(int[] nums) {
        HashMap<Integer,Integer> freqMap=new HashMap<>();
        int n=nums.length;

        for(int i=0;i<n;i++){
            if(freqMap.containsKey(nums[i])==false){
                freqMap.put(nums[i],0);
            }

            freqMap.put(nums[i],freqMap.get(nums[i])+1);
        }

        ArrayList<PairElement> myColl=new ArrayList<>();
        for(Integer key:freqMap.keySet()){
            myColl.add(new PairElement(key,freqMap.get(key)));
        }

        Collections.sort(myColl);

        int sol[]=new int[n];
        int index=0;

        for(int i=0;i<myColl.size();i++){
            int reps=myColl.get(i).freq;
            int value=myColl.get(i).value;
            while(reps>0){
                sol[index]=value;
                index++;
                reps=reps-1;
            }
        }    

        return sol;

        
    }
}