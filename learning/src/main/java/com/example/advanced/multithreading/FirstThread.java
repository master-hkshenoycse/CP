package com.example.advanced.multithreading;

public class FirstThread extends Thread {
    
    private int number;

    FirstThread(int number){
        this.number=number;
    }


    @Override
    public void run(){
        for(int i=1;i<=5;i++){
            System.out.println(number + ": "+ i);
        }
    }
}
