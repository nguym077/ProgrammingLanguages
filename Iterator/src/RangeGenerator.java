// Marian Nguyen
// December 4, 2018
// Lab 4 -- You Gotta Keep 'em Iterated

import java.util.Iterator;

// creates an iterable sequence of integers by keeping a
// private counter of where the sequence is "currently", and
// advancing that counter with each call to the iterator
public class RangeGenerator implements Iterable<Integer> {
    private int mStart, mEnd, mIncrement;

    public RangeGenerator(int start, int end, int incr) {
        mStart = start;
        mEnd = end;
        mIncrement = incr;
    }

    @Override
    public Iterator<Integer> iterator() {
        return new RangeIterator();
    }

    private class RangeIterator implements Iterator<Integer> {
        private int mCurrent;

        public RangeIterator() {
            mCurrent = mStart;
        }

        public boolean hasNext() {
            return mCurrent < mEnd;
        }

        public Integer next() {
            int temp = mCurrent;
            mCurrent += mIncrement;
            return temp;
        }
    }
}
