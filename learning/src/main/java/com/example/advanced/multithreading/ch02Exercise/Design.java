package com.example.advanced.multithreading.ch02Exercise;

import java.util.ArrayList;
import java.util.List;

public class Design {

    private String name;
    private int code;
    private List<Long> votes;
    
    public Design(String name, int code) {
        this.name = name;
        this.code = code;
        this.votes=new ArrayList<>();
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getCode() {
        return code;
    }

    public void setCode(int code) {
        this.code = code;
    }

    public List<Long> getVotes() {
        return votes;
    }

    public void setVotes(List<Long> votes) {
        this.votes = votes;
    }

    

    
    
}
