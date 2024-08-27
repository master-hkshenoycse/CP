package com.example.advanced.multithreading.async;

import java.util.List;
import java.util.Random;
import java.util.concurrent.ForkJoinPool;

public class RecursiveActionMain {

    public static void main(String[] args) {
        Random random=new Random();
        //List<Long> data= random.longs(10,1,5).boxed().collect(toList());

        ForkJoinPool pool=new ForkJoinPool();
        //SumListAction task=new SumListAction(data);
        pool.invoke(task);
    }
    
}
