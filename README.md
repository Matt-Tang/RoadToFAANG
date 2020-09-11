# Road To FAANG

# Day 0 - August 11th, 2020
## Concepts learned: Merge Intervals, Insert Intervals, C++ Syntax
First day of my road to FAANG. Started off with 2 LeetCode questions Merge Interval (Medium) and Insert Interval (Hard). Insert interval uses merge interval code but with a small addition. All that's needed is to first correctly place the new interval into the list and then call merge interval code. I used to do LeetCode in Java but now I am transitioning to C++ so I'm learning the syntax while doing these questions. 

``` 
// To sort a vector<vector<int>> from low to high based on the first element of each vector<int>
sort(v.begin(), v.end(), [](vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}); 
```

https://leetcode.com/problems/merge-intervals/<br/>
https://leetcode.com/problems/insert-interval/

# Day 0 - August 12th to August 20th, 2020
Finished up my exams for the Spring 2020 term and also took a few days off to reset myself. Most of the time I spent hanging out with friends, biking to Toronto, and catching up on some sleep. I'm well motivated to start the grind again :)

# Day 0 - August 21st, 2020
## Concepts learned: Meeting Rooms I, Meeting Rooms II
<ins>Meeting Rooms I:</ins> If a person can attend all meetings there must be no overlap between any meetings. This would require a sort and compare the current end to the next start. <br/>
<ins>Meeting Rooms II:</ins> Again we start by sorting the meetings. Each time when we assign a room for a meeting, we check if any meeting is finished so that the room can be reused. In order to efficiently track the earliest ending meeting, we can use a min heap (priority queue). Whenever an old meeting ends before a new meeting starts, we reuse the room. Otherwise, we need an extra room.

https://www.programcreek.com/2014/07/leetcode-meeting-rooms-java/ <br/>
https://www.programcreek.com/2014/05/leetcode-meeting-rooms-ii-java/<br/>
http://tiancao.me/Leetcode-Unlocked/LeetCode%20Locked/c1.6.html

# Day 1 - September 9th, 2020
## Concepts learned: Basic template for Overlapping Interval Problem and C++ Auto Keyword
The basic template to solve any overlapping problem is: <br/>

1. Sort intervals/pairs in increasing order of the start position. <br/>
2. Scan the sorted intervals, and maintain an "active set" for overlapping intervals. Usually, we do not need to use an explicit set to store them. Instead, we just need to maintain several key parameters, e.g. the number of overlapping intervals (count), the minimum ending point among all overlapping intervals (minEnd). <br/>
3. If the interval that we are currently checking overlaps with the active set, which can be characterized by ``` cur.start > minEnd ```, we need to renew those key parameters or change some states. <br/>
4. If the current interval does not overlap with the active set, we just drop current active set, record some parameters, and create a new active set that contains the current interval. <br/>

<ins>Minimum Number of Arrows to Burst Balloons:</ins> This is an example of applying the template we used above. First sort the intervals, then go through the sorted intervals one by one and see if there is overlap. If there is overlap between our "active set" and the "current interval" that means the same arrow can be used and all we need to do is update the (minEnd). If there's no overlap, that means another arrow is needed so we increase the arrowCount by one and update our end pointer. After we finish looping, we just return the numberArrows + 1.  

https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

# Day 2 - September 1th, 2020
## Concepts learned: Missing Number

Feeling a little tired from work today and working out. I was only able to do 1 problem. When dealing with a problem that requires constant space, the first thing you should think about is modifying the original array. If we didn't have space constraint, the easiest answer would be to have 2 loops: 1 loop that would add numbers to the set, and the second loop to find the missing number in the set. However, with a space constraint we can't use a set. <br/>

There's a lot of ways to do this, but, given a space and time constraint the easiest way would be bit manipulation or using XOR. The XOR is a really special case and this is a problem that you should just memorize. There isn't much code and the solution can be easily remembered. It is a fast and very efficient strategy:

```
int missingNumber(vector<int>& nums) {
    int result = nums.size();
    for(int i = 0; i < nums.size(); i++){
        result ^= i;
        result ^= nums[i];
    }
    
    return result; 
}
```
https://leetcode.com/problems/missing-number/
