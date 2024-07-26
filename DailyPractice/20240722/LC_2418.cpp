import java.util.*;

class Person implements Comparable<Person>{
    String name;
    int height;

    Person(String name,int height){
        this.name=name;
        this.height=height;
    }

    @Override
    public int compareTo(Person other){
        return other.height-this.height;
    }

}
class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        ArrayList<Person> personList=new ArrayList<>();
        int n=names.length;

        for(int i=0;i<n;i++){
            personList.add(new Person(names[i],heights[i]));
        }

        Collections.sort(personList);
        
        String sol[]=new String[n];
        for(int i=0;i<n;i++){
            sol[i]=personList.get(i).name;
        }

        return sol;
        
    }
}