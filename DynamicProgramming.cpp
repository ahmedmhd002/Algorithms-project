#include "DynamicProgramming.h"
#include "UtilityFunctions.h"
#include <iostream>

using namespace std;


void initializeDPArray(CustomVector<int>& dp, int size) {
    for (int i = 0; i < size; i++) {
        dp.push_back(0); 
    }
}

int solveDynamicProgramming(const CustomVector<Interval>& intervals) {
    if (intervals.getSize() == 0) return 0;
    
    CustomVector<Interval> sortedIntervals = intervals;
    customSort(sortedIntervals);

    CustomVector<int> dp;
    initializeDPArray(dp, sortedIntervals.getSize());
    
    dp[0] = 1;
    
    for (int i = 1; i < sortedIntervals.getSize(); i++) {
        
        dp[i] = dp[i-1];
        
        for (int j = i - 1; j >= 0; j--) {
            if (sortedIntervals[j].end <= sortedIntervals[i].start) {
                dp[i] = dp[j] + 1;
                break;
            }
        }
    }
  
    return dp[sortedIntervals.getSize() - 1];
}
