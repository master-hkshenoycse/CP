package com.example.advanced.multithreading.ch02Exercise;

public class MainApp {

    public static void main(String []args){

        Design d1=new Design("D1",1);
        
        Thread votingD1=new Thread(new VotingRunnable(d1));
        votingD1.start();

        Thread countingD1=new Thread(new CountingRunnable(d1));
        countingD1.start();

        Design d2=new Design("D2",2);
        
        Thread votingD2=new Thread(new VotingRunnable(d2));
        votingD2.start();

        Thread countingD2=new Thread(new CountingRunnable(d2));
        countingD2.start();


        Design d3=new Design("D3",3);
        
        Thread votingD3=new Thread(new VotingRunnable(d3));
        votingD3.start();

        Thread countingD3=new Thread(new CountingRunnable(d3));
        countingD3.start();




    }

}
