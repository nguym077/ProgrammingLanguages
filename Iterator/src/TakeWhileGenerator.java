// Marian Nguyen
// December 4, 2018
// Lab 4 -- You Gotta Keep 'em Iterated

import java.util.Iterator;
import java.util.function.Predicate;

// given a 'Predicate<T>' and a source 'Iterable<T>', generates
// elements from the source iterable as long as they pass the predicate.
// as soon as a value from source does not pass, generator finishes
public class TakeWhileGenerator<T> implements Iterable<T> {
    private Iterable<T> mSource;
    private Predicate<T> mPredicate;

    public TakeWhileGenerator(Predicate<T> pred, Iterable<T> source) {
        mPredicate = pred;
        mSource = source;
    }

    public Iterator<T> iterator() {
        return new TakeWhileIterator();
    }

    private class TakeWhileIterator implements Iterator<T> {
        private Iterator<T> mIterator;
        private T mCurrent;

        public TakeWhileIterator() {
            mIterator = mSource.iterator();
        }

        public boolean hasNext() {
            if (mIterator.hasNext()) {
                mCurrent = mIterator.next();
            }
            return mPredicate.test(mCurrent) && mIterator.hasNext();
        }

        public T next() {
            return mCurrent;
        }
    }
}
