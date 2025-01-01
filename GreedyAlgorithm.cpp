#include "GreedyAlgorithm.h"
#include "UtilityFunctions.h"
#include <climits>

int findNextInterval(const CustomVector<Interval>& intervals, int currentEnd) {
    int minStart = INT_MAX;
    int nextIndex = -1;
    for (int i = 0; i < intervals.getSize(); i++) {
        if (intervals[i].start >= currentEnd && intervals[i].start < minStart) {
            minStart = intervals[i].start;
            nextIndex = i;
        }
    }
    return nextIndex;
}

int solveGreedy(const CustomVector<Interval>& intervals) {
    CustomVector<Interval> sortedIntervals = intervals;
    customSort(sortedIntervals);

    int count = 0;
    int lastEnd = -1;

    while (true) {
        int currentIndex = findNextInterval(sortedIntervals, lastEnd);
        if (currentIndex == -1) break;

        count++;
        lastEnd = sortedIntervals[currentIndex].end;
    }

    return count;
}