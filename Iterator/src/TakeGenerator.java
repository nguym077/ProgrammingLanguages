// Marian Nguyen
// December 4, 2018
// Lab 4 -- You Gotta Keep 'em Iterated

import java.util.Iterator;

// generic because we can take values from any type of sequence
public class TakeGenerator<T> implements Iterable<T> {
    private Iterable<T> mSource;        // sequence to take values from
    private int mAmount;                // number of values to take

    public TakeGenerator(int n, Iterable<T> source) {
        mSource = source;
        mAmount = n;
    }

    public Iterator<T> iterator() {
        return new TakeIterator();
    }

    private class TakeIterator implements Iterator<T> {
        private int mRemaining;

        // to allow multiple TakeIterators to walk over the same source,
        // we request a source iterator for each TakeIterator
        private Iterator<T> mIterator;

        public TakeIterator() {
            mRemaining = mAmount;
            mIterator = mSource.iterator();
        }

        public boolean hasNext() {
            return mRemaining > 0 && mIterator.hasNext();
        }

        public T next() {
            --mRemaining;
            return mIterator.next();
        }
    }
}
