import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

class NestedListIterator implements Iterator<Integer> {
    List<List<Integer> > list;
    Integer innerIndex,outerIndex;

    public NestedListIterator(List<List<Integer> > list){
        this.list=list;
        innerIndex=0;
        outerIndex=0;
    }

    private void advanceToNext(){
        if(list.get(outerIndex).size()==0 || innerIndex == list.get(outerIndex).size()){
            outerIndex++;
            innerIndex=0;
        }
    }
    
    @Override
    public boolean hasNext() {
        advanceToNext();
        if(outerIndex==list.size()){
            return false;
        }
        return true;
    }

    @Override
    public Integer next() {
        Integer ret = list.get(outerIndex).get(innerIndex);
        innerIndex++;
        return ret;
    }
    
}
public class NestedListIteratorTest {
    public static void main(String[] args) {
         List<List<Integer>> list = Arrays.asList(
            Arrays.asList(1, 2, 3),
            Arrays.asList(4, 5),
            Arrays.asList(6, 7)
        );

        NestedListIterator it = new NestedListIterator(list);
        while (it.hasNext()) {
            System.out.print(it.next() + " ");
        }
    }
}
