package com.example.advanced.multithreading.async;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ExecutorDemoOne {

    public static void main(String[] args) {
        ExecutorService executorService=Executors.newSingleThreadExecutor();
        
        executorService.execute(new Runnable(){
            public void run(){
                String threadName=Thread.currentThread().getName();
                System.out.println(threadName + " executing the task ");
            }
        });

        executorService.shutdown();
    }
    
}
