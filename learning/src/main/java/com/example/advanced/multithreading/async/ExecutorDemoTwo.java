package com.example.advanced.multithreading.async;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class ExecutorDemoTwo {
    
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

        //Submit each task to executor service to be executed
        Future<String> f1=executorService.submit(t1);
        Future<String> f2=executorService.submit(t2);
        Future<String> f3=executorService.submit(t3);

        System.out.println(f1.get());
        System.out.println(f2.get());
        System.out.println(f3.get());

        executorService.shutdown();
        


    }
}
