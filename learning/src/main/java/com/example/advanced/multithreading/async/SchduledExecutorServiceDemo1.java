package com.example.advanced.multithreading.async;

import java.time.LocalDateTime;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.ScheduledFuture;
import java.util.concurrent.TimeUnit;

public class SchduledExecutorServiceDemo1 {

     private static int count=0;
     public static void main(String[] args) throws InterruptedException, ExecutionException {
        
        ScheduledExecutorService scheduledExecutorService=Executors.newScheduledThreadPool(1);

        Runnable task = () ->{
            count++;
            System.out.println("Executing Task 1 at "+ LocalDateTime.now());
        };

        ScheduledFuture<?>  future=scheduledExecutorService.scheduleAtFixedRate(task,5,1,TimeUnit.SECONDS);
        
        while(count != 5){
            System.out.println(count);
            TimeUnit.MILLISECONDS.sleep(100);
        }

        System.out.println(future.get());
        future.cancel(true);

        scheduledExecutorService.shutdown();

     }    
}
