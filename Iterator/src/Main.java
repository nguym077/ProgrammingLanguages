// Marian Nguyen
// December 4, 2018
// Lab 4 -- You Gotta Keep 'em Iterated

import java.util.Iterator;

public class Main {
    public static void main(String[] args) {
        RangeGenerator g = new RangeGenerator(1, 20, 1);
        Iterator itr = g.iterator();

        while (itr.hasNext()) {
            Integer i = (Integer) itr.next();
            System.out.println(i);
        }
    }
}
