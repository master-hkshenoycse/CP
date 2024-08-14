package com.example.advanced.multithreading.async;

import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.TimeUnit;
import java.util.function.Supplier;

public class CompletableFutureDemo1 {

    public static void main(String[] args) throws InterruptedException,ExecutionException{
        
        /*CompletableFuture<Integer> future=CompletableFuture.supplyAsync(new Supplier<Integer> (){
            public Integer get(){
                System.out.println("accessing data over network");
                
                try{
                    TimeUnit.SECONDS.sleep(4);
                }catch(InterruptedException e){
                    throw new RuntimeException(e);
                }

                return 200;
            }
        });*/

        CompletableFuture<Integer> future = CompletableFuture.supplyAsync( () -> {
            System.out.println("accessing data over network");
                
            try{
                TimeUnit.SECONDS.sleep(4);
            }catch(InterruptedException e){
                throw new RuntimeException(e);
            }

            return 200;
        });

        //Attach a callback to Future using thenApply()

        CompletableFuture<Integer> futureWithCallback = future.thenApply(result -> {
            int totalPoints=result;
            if(result>=10 && result<=100){
                totalPoints+=10;
            }else if(result >= 101 && result<=200){
                totalPoints+=20;
            }

            return totalPoints;
        });

        //Manually completing with the last cached data
        futureWithCallback.complete(150);

        System.out.println("Future with callback "+ futureWithCallback.get());
        
        


    }

}
