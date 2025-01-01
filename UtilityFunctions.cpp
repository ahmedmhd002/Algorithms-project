#include "UtilityFunctions.h"
#include <iostream>

using namespace std;

void swapIntervals(Interval& a, Interval& b) {
    Interval temp = a;
    a = b;
    b = temp;
}

bool compareIntervals(const Interval& a, const Interval& b) {
    return (a.end < b.end) || (a.end == b.end && a.start < b.start);
}

void customSort(CustomVector<Interval>& intervals) {
    
    for (int i = 0; i < intervals.getSize() - 1; i++) {
        for (int j = 0; j < intervals.getSize() - i - 1; j++) {
        
            if (intervals[j].end > intervals[j + 1].end || 
                (intervals[j].end == intervals[j + 1].end && 
                 intervals[j].start > intervals[j + 1].start)) {
                
                Interval temp = intervals[j];
                intervals[j] = intervals[j + 1];
                intervals[j + 1] = temp;
            }
        }
    }
}

CustomVector<Interval> parseInput() {
    CustomVector<Interval> intervals;
    int n;
    
    cout << "Enter number of intervals: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int start, end;
        cout << "Enter start and end time for interval " << i + 1 << ": ";
        cin >> start >> end;
        intervals.push_back(Interval(start, end));
    }
    
    return intervals;
}

void printResult(int result, bool isGreedy) {
    if (isGreedy) {
        cout << "Greedy Approach Result: ";
    } else {
        cout << "Dynamic Programming Result: ";
    }
    cout << "Maximum number of non-overlapping intervals: " << result << endl;
}