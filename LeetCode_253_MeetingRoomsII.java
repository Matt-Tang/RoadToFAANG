/* 
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...]
(si < ei), find the minimum number of conference rooms required.


Brute force solution
Time: O(n)
Space: O(1)
=====================
maxCount = 0
loop from i to n
    loop from j=i+1 to n
        if intervals i and j overlap  
            count++
    maxCount = max(maxCount, max)
return maxCount + 1
 
Optimal Solution
Time: O(nlogn), O(n), O(logn) ** These are possibilities
Space: O(1), O(n)
We are going to try and sort the list first so the run time is O(nlogn)
=====================
sort(intervals)
maxIntersections = 0
loop from i to n 
    candidateInterval = intervals[i]
    intersections = 0
    loop from j=i+1 to n
        currentInterval = intervals[j]
        // if the current start is less than the end of the candidate we have overlap
        if(currentInterval[0] < candidateInterval[1])
            intersections++
        else
            break // we only care about the overlaps, if we dont have any we should end
    maxIntersections = max(maxIntersections, intersections)
return maxIntersections
*/

public int minMeetingRooms(int[][] intervals) {
    Arrays.sort(intervals, Comparator.comparing((int[] itv) -> itv[0]));
 
    PriorityQueue<Integer> heap = new PriorityQueue<>();
    int count = 0;
    for (int[] itv : intervals) {
        if (heap.isEmpty()) {
            count++;
            heap.offer(itv[1]);
        } else {
            if (itv[0] >= heap.peek()) { 
                heap.poll(); // if the current itv start time is earlier than the min end time (we get min end time from peek)
                             // then we should remove the min end time and put in the new one
            } else { 
                count++;     // if the current itv start time is later than the min end time, this means we have overlap
            }
 
            heap.offer(itv[1]); // push itv end time onto the heap
        }
    }
 
    return count;
}