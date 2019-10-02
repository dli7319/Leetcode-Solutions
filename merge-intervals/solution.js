/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    if (intervals.length == 0) {
        return [];
    }
    intervals.sort((x,y) => {
        return x[0] - y[0];
    });
    let newIntervals = [];
    let newInterval = intervals[0];
    for (let i = 1; i < intervals.length; i++) {
        if (intervals[i][0] <= newInterval[1]) {
            newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
        } else {
            newIntervals.push(newInterval);
            newInterval = intervals[i];
        }
    }
    newIntervals.push(newInterval);
    return newIntervals;
};
