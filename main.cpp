#include <iostream>
#include "UtilityFunctions.h"
#include "GreedyAlgorithm.h"
#include "DynamicProgramming.h"

using namespace std;

int main() {
    CustomVector<Interval> intervals = parseInput();

    int greedyResult = solveGreedy(intervals);
    printResult(greedyResult, true);

    int dpResult = solveDynamicProgramming(intervals);
    printResult(dpResult, false);

    return 0;
}