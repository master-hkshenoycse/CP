package com.example.advanced.multithreading.ch02Exercise;

public class CountingRunnable implements Runnable{
    
    private Design d;
    protected boolean doStop=false;

    

    public CountingRunnable(Design d) {
        this.d = d;
    }



    public Design getD() {
        return d;
    }



    public void setD(Design d) {
        this.d = d;
    }



    public boolean isDoStop() {
        return doStop;
    }



    public void setDoStop(boolean doStop) {
        this.doStop = doStop;
    }



    @Override
    public void run(){
        System.out.println("Design "+d.getName() + " has "+ d.getVotes().size());
    }
}
