package com.example.advanced.multithreading.async;

import java.util.List;
import java.util.concurrent.RecursiveAction;
import java.util.concurrent.RecursiveTask;

public class SumListAction extends RecursiveTask<Long> {

    private List<Long> numbers;
    private static final int THRESHOLD=5;
    
    public SumListAction(List<Long> numbers){
        this.numbers=numbers;
    }
    
    @Override
    protected Long compute(){
        if(numbers.size()  <= THRESHOLD){
            long sum=computeDirectly();
            System.out.println(sum);
            return sum;
        }else{
            int mid=numbers.size()/2;
            SumListAction subTask1=new SumListAction(numbers.subList(0, mid));
            SumListAction subTask2=new SumListAction(numbers.subList(mid,numbers.size()));
            invokeAll(subTask1,subTask2);

            return subTask1.join()+subTask2.join();

        }
    }

    protected long computeDirectly(){
        long sum=0;
        for(Long n:numbers){
            sum+=n;
        }
        return sum;
    }

     
    
}
