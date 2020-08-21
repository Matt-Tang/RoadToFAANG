# Road To FAANG

# Day 1 - August 11th, 2020
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

# Day 2-10 - August 12th to August 20th, 2020
Finished up my exams for the Spring 2020 term and also took a few days off to reset myself. Most of the time I spent hanging out with friends, biking to Toronto, and catching up on some sleep. I'm well motivated to start the grind again :)

# Day 11 - August 21st, 2020
## Concepts learned: Meeting Rooms I, Meeting Rooms II
<ins>Meeting Rooms I:</ins> If a person can attend all meetings there must be no overlap between any meetings. This would require a sort and compare the current end to the next start. <br/>
<ins>Meeting Rooms II:</ins> Again we start by sorting the meetings. Each time when we assign a room for a meeting, we check if any meeting is finished so that the room can be reused. In order to efficiently track the earliest ending meeting, we can use a min heap (priority queue). Whenever an old meeting ends before a new meeting starts, we reuse the room. Otherwise, we need an extra room.

https://www.programcreek.com/2014/07/leetcode-meeting-rooms-java/ <br/>
https://www.programcreek.com/2014/05/leetcode-meeting-rooms-ii-java/<br/>
http://tiancao.me/Leetcode-Unlocked/LeetCode%20Locked/c1.6.html
