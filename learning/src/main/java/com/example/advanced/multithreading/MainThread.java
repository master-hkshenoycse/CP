package com.example.advanced.multithreading;

public class MainThread {
    public static void main(String[] args) throws InterruptedException{
       
        Thread taskThread=new Thread(new MyRunnable());
        taskThread.start();
        
      
        taskThread.interrupt();
        
        Thread.sleep(3000);
        
        System.out.println(taskThread.isInterrupted());


     

    }

}
