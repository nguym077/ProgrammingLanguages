// Marian Nguyen
// December 4, 2018
// Lab 4 -- You Gotta Keep 'em Iterated


import java.util.function.Predicate;

public class Main {
    public static void main(String[] args) {
        RangeGenerator g = new RangeGenerator(1, 20, 1);
        Predicate<Integer> lessThan7 = i -> (i < 10);
        TakeWhileGenerator<Integer> m = new TakeWhileGenerator<>(lessThan7, g);

        for (Integer i : m) {
            System.out.print(i + " ");
        }

        //while (itr.hasNext()) {
        //   Integer i = (Integer) itr.next();
        //    System.out.println(i);
        //}
    }
}
