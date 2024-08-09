package com.example.advanced.multithreading.syncronization;

import javax.management.RuntimeErrorException;

public class Main {
    
    public static void main(String[] args){
        InventoryManager inventoryManager=new InventoryManager();

        Thread issuer=new Thread(inventoryManager,"issue");
        Thread receiver=new Thread(inventoryManager,"receive");

        issuer.start();
        receiver.start();

        try{
            Thread.sleep(1000);
        }catch(InterruptedException e){
            System.out.println(e.getMessage());
        }

        System.out.println("Current count of items: "+inventoryManager.getItemCount());
    }
}
