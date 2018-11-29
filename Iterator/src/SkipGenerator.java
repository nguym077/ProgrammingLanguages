// Marian Nguyen
// December 4, 2018
// Lab 4 -- You Gotta Keep 'em Iterated

import java.util.Iterator;

// given an integer 'n' and a source 'Iterable<T>', generates an
// iterable sequence of the source's elements, but only after
// skipping past the first 'n' elements
public class SkipGenerator<T> implements Iterable<T> {
    private Iterable<T> mSource;        // sequence to take values from
    private int mAmount;                // number of values to skip

    public SkipGenerator(int n, Iterable<T> source) {
        mSource = source;
        mAmount = n;
    }

    public Iterator<T> iterator() { return new SkipIterator(); }

    private class SkipIterator implements Iterator<T> {
        private int mValuesSkipped;
        private Iterator<T> mIterator;

        public SkipIterator() {
            mValuesSkipped = 0;
            mIterator = mSource.iterator();
        }

        public boolean hasNext() {
            while (mIterator.hasNext() && mValuesSkipped < mAmount) {
                mValuesSkipped++;
                mIterator.next();
            }

            return mIterator.hasNext();
        }

        public T next() {
            return mIterator.next();
        }
    }
}
