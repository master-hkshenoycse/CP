package com.example.advanced.multithreading.async;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class ExecutorDemoThree {
    
    public static void main(String[] args) throws InterruptedException, ExecutionException {
        ExecutorService executorService=Executors.newFixedThreadPool(3);

        Callable<String> t1= () -> {
            String threadName=Thread.currentThread().getName();
            return threadName + " executing Task 1";
        };

        Callable<String> t2= () -> {
            String threadName=Thread.currentThread().getName();
            return threadName + " executing Task 2";
        };

        Callable<String> t3= () -> {
            String threadName=Thread.currentThread().getName();
            return threadName + " executing Task 3";
        };

        List<Callable<String> > callableTasks=new ArrayList<>();
        callableTasks.add(t1);
        callableTasks.add(t2);
        callableTasks.add(t3);

        String result=executorService.invokeAny(callableTasks);
        System.out.println(result);

        List<Future<String> > futures=executorService.invokeAll(callableTasks);

        for(Future<String> future:futures){
            System.out.println(future.get());
        }

        executorService.shutdown();
    }
    

    
        
}
