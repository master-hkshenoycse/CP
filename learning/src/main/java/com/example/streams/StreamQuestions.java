package com.example.streams;

import java.util.Arrays;
import java.util.Collection;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.Set;
import java.util.stream.Collectors;
class Person{
    String name;
    String city;

    public Person(String name, String city) {
        this.name = name;
        this.city = city;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    

    

}
public class StreamQuestions {
    
    public static void main(String[] args) {
        
        //filter API
        List<Integer> numbers=Arrays.asList(1,2,3,4,5,6,7,8,9,10);
        List<Integer> result=numbers.stream().filter(n -> n>5).collect(Collectors.toList());
        System.out.println(result);

        //map, transform a stream, basically apply the function to each element in stream.
        List<String> words=Arrays.asList("ab","cd","ef");
        List<String> wordsResult=words.stream().map(String::toUpperCase).collect(Collectors.toList());
        System.out.println(wordsResult);

        //flatMap 
        //Given a list of list flatten it into  a single list of strings.
        List<List<String> > listOfLists=Arrays.asList(
            Arrays.asList("one","two"),
            Arrays.asList("three","four")
        );

        List<String> resultList=listOfLists.stream().flatMap(Collection::stream).collect(Collectors.toList());
        System.out.println(resultList);
        


        //distinct
        //remove duplicates, keeps in place the first occurence,order remains same.
        List<Integer> duplicateNumbers=Arrays.asList(1,2,2,7,3,4,5,2,3,7);
        List<Integer> uniqueNumbers=duplicateNumbers.stream().distinct().collect(Collectors.toList());
        System.out.println(uniqueNumbers);

        List<Integer> sortedNumbers=duplicateNumbers.stream().sorted(Comparator.reverseOrder()).collect(Collectors.toList());
        System.out.println(sortedNumbers);


        //peek
        //used for debugging purpose, allows to perform an intermediate operation on each
        //element of stream without modifying the stream itslef.
        List<Integer> peekNumbers=duplicateNumbers.stream().peek(n -> System.out.println("Original: "+n)).sorted(Comparator.reverseOrder()).collect(Collectors.toList());
        System.out.println(peekNumbers);

        //limit
        //Limit the number to elements passed from stream to next step.
        List<Integer> top3Number=duplicateNumbers.stream().sorted(Comparator.reverseOrder()).limit(3).collect(Collectors.toList());
        System.out.println(top3Number);


        //skip
        //skip and fetch remaining item in stream.
        List<Integer> skip3Number=duplicateNumbers.stream().sorted(Comparator.reverseOrder()).skip(2).limit(3).collect(Collectors.toList());
        System.out.println(skip3Number);


        //Terminal operators
        //forEach
        duplicateNumbers.stream().forEach(n -> System.out.println(n*n));

        //Collect
        Set<Integer> setNumbers=duplicateNumbers.stream().collect(Collectors.toSet());
        System.out.println(setNumbers);

        //Reduce
        //performs reductio on elements in stream, combining them into single result
        //repeatedly performs the operation mentioned
        Optional<Integer> finalSum=duplicateNumbers.stream().reduce((a,b)->a+b);
        System.out.println(finalSum.get());


        //allMatch,anyMatch,noneMatch.
        //tries to satisfy a given predicate.

        boolean isAllGt=duplicateNumbers.stream().allMatch(n -> n>0);
        System.out.println(isAllGt);


        //findFirst,findAny;
        Optional<Integer> firstResult=duplicateNumbers.stream().findFirst();
        System.out.println(firstResult.get());

        //max,min,toArray()
        Optional<Integer> min=duplicateNumbers.stream().min(Integer::compareTo);
        System.out.println(min.get());


        //collector operator


        //joining
        //concatenate the elements of a stream into a single string
        //formatting available with optional dleimiter, prefixes,suffixes.
        String commaList=words.stream().collect(Collectors.joining(","));
        System.out.println(commaList);


        //groupingby
        //aggregating and categoriizing data into a MAp where the keys are result of applying clasifier function
        //and values are list correspongonto eact key.

        List<Person> people=Arrays.asList(
            new Person("John","NY"),
            new Person("Jane","Cali"),
            new Person("Jack","SF")
        );


        Map<String,List<Person> > groupedResult=people.stream().collect(Collectors.groupingBy(Person::getCity));
        System.out.println(groupedResult);

 


        




    }

}
