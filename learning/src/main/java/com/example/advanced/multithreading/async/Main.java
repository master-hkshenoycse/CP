package com.example.advanced.multithreading.async;

import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;

public class Main {

    public static void main(String[] args) throws InterruptedException,ExecutionException{

        ExecutorService executorService = Executors.newFixedThreadPool(2);

        long startTime=System.nanoTime();
        Future<String> f1=executorService.submit(new TimeConsumingTask());
        Future<String> f2=executorService.submit(new OtherTask());

        while(!f1.isDone() && !f2.isDone()){
            System.out.println("Reading and proceessing not yet finished");
            TimeUnit.SECONDS.sleep(1);
        }

        System.out.println(f1.get());
        System.out.println(f2.get());

        long elapsedTime=System.nanoTime()-startTime;
        System.out.println("Both tasks finished in "+ (elapsedTime/1000000)/1000+ " seconds");



    }
}
