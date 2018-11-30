// Marian Nguyen
// December 4, 2018
// Lab 4 -- You Gotta Keep 'em Iterated


import java.util.function.Predicate;

public class Main {
    public static void main(String[] args) {
        RangeGenerator g = new RangeGenerator(1, 10, 1);
        Predicate<Integer> lessThan7 = i -> (i % 2 == 1);
        FilterGenerator<Integer> m = new FilterGenerator<>(lessThan7, g);

        System.out.println("Original Values: ");
        for (Integer i : g) {
            System.out.print(i + " ");
        }

        System.out.println("\n\nTest Output: ");
        for (Integer i : m) {
            System.out.print(i + " ");
        }

        //while (itr.hasNext()) {
        //   Integer i = (Integer) itr.next();
        //    System.out.println(i);
        //}
    }
}
