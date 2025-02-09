package com.example.advanced.multithreading.async;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class NumberMagic {
    static int number=0;

    public static void main(String[] args) throws InterruptedException, ExecutionException {
        Scanner myObj=new Scanner(System.in);
        boolean flag;

        do{
            System.out.println("Enter an integer");
            try{
                number=Integer.parseInt(myObj.nextLine());
                flag=false;
            }catch(Exception e){
                flag=true;
            }
        }while(flag);

        ExecutorService executorService=Executors.newFixedThreadPool(3);
        
        Callable<String> findSqrt = () -> {
            double  sqrt=Math.sqrt(number);
            return "Square root is "+sqrt;
        };

        Callable<String> findFactorial = () -> {
            BigInteger result=BigInteger.ONE;
            for(int i=2;i<=number;i++){
                result=result.multiply(BigInteger.valueOf(i));
            }

            return "Factorial is "+result;
        };

        Callable<String> toBinary = () -> {
            String binary=Integer.toBinaryString(number);
            return number + " in binary "+ binary;
        };

        List<Callable<String> > callableTasks=new ArrayList<>();
        callableTasks.add(findSqrt);
        callableTasks.add(findFactorial);
        callableTasks.add(toBinary);


        List<Future<String> > futures=executorService.invokeAll(callableTasks);
        
        for(Future<String> future:futures){
            System.out.println(future.get());
        }

        executorService.shutdown();



    }
    
}
