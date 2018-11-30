// Marian Nguyen
// December 4, 2018
// Lab 4 -- You Gotta Keep 'em Iterated

import java.util.Iterator;
import java.util.function.Predicate;

// given a 'Predicate<T>' and a source 'Iterable<T>', generates a
// sequence of elements from the source that satisfy that predicate
public class FilterGenerator<T> implements Iterable<T> {
    private Predicate<T> mPredicate;
    private Iterable<T> mSource;

    public FilterGenerator(Predicate<T> pred, Iterable<T> source) {
        mPredicate = pred;
        mSource = source;
    }

    public Iterator<T> iterator() { return new FilterIterator(); }

    private class FilterIterator implements Iterator<T> {
        private Iterator<T> mIterator;
        private T mCurrent;

        public FilterIterator() {
            mIterator = mSource.iterator();
        }

        public boolean hasNext() {
            if (mIterator.hasNext()) {
                mCurrent = mIterator.next();
                if (mPredicate.test(mCurrent)) {
                    return true;
                } else {
                    while (!mPredicate.test(mCurrent) && mIterator.hasNext()) {
                        mCurrent = mIterator.next();
                    }
                    return mIterator.hasNext() || mPredicate.test(mCurrent);
                }
            } else {
                return false;
            }
        }

        public T next() {
            return mCurrent;
        }
    }
}
