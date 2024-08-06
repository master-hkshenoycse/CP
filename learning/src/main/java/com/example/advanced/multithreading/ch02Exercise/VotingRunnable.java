package com.example.advanced.multithreading.ch02Exercise;

public class VotingRunnable implements Runnable{

    private Design d;
    protected boolean doStop=false;

    

    public VotingRunnable(Design d) {
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
        System.out.println("voting going on for "+d.getName());
        d.getVotes().add(1L);
    }
}
