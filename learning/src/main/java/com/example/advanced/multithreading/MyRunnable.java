package com.example.advanced.multithreading;

public class MyRunnable implements Runnable{

    @Override
    public void run(){
        for(int i=1;i<=100;i++){
            System.out.println(i);
            /*try{
                Thread.sleep(1000);
            }catch(InterruptedException e){
                System.out.println(Thread.currentThread().isInterrupted());
                break;
            }*/

            if(Thread.interrupted()){
                break;

            }
        }
    }
}
