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

# Day 2 - September 10th, 2020
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

# Break - September 11-14th, 2020

On Friday, I met up with a friend after work for dinner and just caught up. On Saturday and Sunday I helped my parents place concrete tiles in the backyard and that took a lot of energy out of me. I also started to play basketball with Kelvin. On Monday, Jordan came to pick up his bike and him, Kelvin, and I had a basketball 1v1 competition. We tied for wins and I jammed my finger really badly :(

# Day 3 - September 15th, 2020
## Concepts learned: Amazon Interview Questions (1-3 out of 67) - Design Tic Tac Toe, Remove Palindromic Subsequences, Find the Celebrity

I'm starting Amazon's interview prep early. There are 67 questions and I am aiming to do 2-3 every single day. The questions can be found in this playlist: https://www.youtube.com/playlist?list=PLKZaSt2df1gwm69QBaDJTqTDea28qZjY0 <br/>

<ins>LeetCode #348: Design Tic Tac Toe</ins> The brute force solution would be to create a n by n grid and after every time the move function is called we would need to check the horizontal, vertical, and diagonal which would be O(n^2). A slight optimization can be done to make the check O(n). 

If you look at the grid, there are some positions that a diagonal can’t be formed. In these positions, we only need to check the column and the row which reduces the runtime of our algorithm. The “special” positions that we need to check the diagonal would be:

1) When row = column  or i = j
```
|X| | |
| |X| | 
| | |X|
```
2) When row + column = n-1  or i+j = n-1
```
| | |X|
| |X| | 
|X| | |
```

By doing this, our runtime would be O(n) and space would be O(n^2). 

O(n^2) space is quite expensive. A better method would be to break up a 2D array into 2 1D arrays. The 1D arrays represent a tally system for the rows and columns where we increment by 1 for player 1 and decrement by 1 for player 2. Now, instead of checking the entire row and the entire column, we are only checking if the value at the current row and column is == n or not. With this optimized approach, the checking is now reduced to O(1) and the space is O(n). 

The other thing we need to take care of is the diagonals. In a 3 x 3 grid, there are only 2 diagonals so we can keep track of them in 2 separate variables instead of in an array. Just like above, if player 1 makes a move on the diagonal, we increment the diagonal variable, and if player 2 makes a move on the diagonal, we decrement the diagonal variable. 

<ins>LeetCode #1332: Remove Palindromic Subsequence</ins> The hardest part about this question is the definition of removing a subsequnce. It is important to note that the subsequence does not need to be sequential. For example: abbaabb. Clearly this is not a palindrome, but, we could remove the palindromic subsequence by doing the following:

``` abbaabb ```
1) pos1: a, pos4: a, pos5: a -> bbbb 
2) Remove the b's -> " "

If you didn't notice, because of this specific definition of a subsequence which doesn't need to be sequential, the greatest amount of moves needed to remove a string consisting of only a's and b's is 2:

1) Empty string -> return 0
2) String is already a palindrome -> return 1
3) String is not a palindrome -> return 2 <br/>
** Note that we can remove an arbitrary subsequence of a's, then the string will only contain b's. 2 moves is the maximum number of moves that is required ** 

<ins>LeetCode #277: Find The Celebrity</ins> It is easy to think of this problem as a graph problem. The celebrity node has an input of n-1 and an output of 0. The brute force solution would be a talley counter. Go through every person and see who knows who and keep track of that in a 1D array. At the end, the person who has n-1 votes is the celebrity. The runtime of this is O(n^2) and the space complexity is O(n).

Instead of thinking of the number of inputs, we should focus on the output of a node. Suppose we have 4 nodes. If node0 knows node1, then immediately node0 can not be the celebrity. If node1 does not know anyone, then node1 is the celebrity. We don't need to waste time keeping track of a talley counter. Therefore, the runtime would be O(n) and the space would be O(1). The algorithm becomes pretty simple:

1) Determine a possible candidate by going from 0 to n-1 and checking who knows who
2) After we determine a candidate, check if its the celebrity

https://ttzztt.gitbooks.io/lc/content/design-tic-tac-toe.html <br/>
https://leetcode.com/problems/remove-palindromic-subsequences/ <br/>
https://ttzztt.gitbooks.io/lc/content/find-the-celebrity.html

# Day 4 - September 16th, 2020
## Concepts learned: Amazon Interview Questions (4-6 out of 67) - Rotting Oranges, Max Difference You Can Get From Changing an Integer, Check If a String Can Break Another String
<ins>LeetCode #994: Rotting Oranges</ins> This is a classical BFS question using a Queue implementation. There isn't too many tricks involved in this question and the general algorithm looks like:

1) Create queue
2) Go through the entire 2D grid and add rotten oranges to the queue
3) Go through each rotten orange and infect in the 4 directions while keeping track of the time

<ins>LeetCode #1432: Max Difference You Can Get From Changing an Integer</ins> This question is about finding the minimum number, the maximum number, and finding the max difference. To get the minimum/maximum number we need to look at the most significant digit and change that number accordingly. 

For the maximum number: Find the first instance of the number from right to left (->) that isn't a 9. <br/>
For the minimum number: There is a corner case. We can't have leading 0's. If the most significant number is not a 1, we just need to change it to a 1. If the most signifcant number is a 1, we move from right to left (->) until we hit a number that's not a 0 or 1 and change it to a 1. This will get obey the leading 0's constraint that we have. 

The runtime of this would be O(n) and the space would be constant O(1). The space is constant because we are changing an int to a string to make string replacements and indexing much easier.

<ins>LeetCode #1433: Check If a String Can Break Another String</ins> The way to approach this question is to sort the subsequences first. Once they are sorted, all we need to do is run two independent loops and check if s1 breaks s2 and if s1 is broken by s2.

To easily sort strings alphabetically:
```
sort(s.begin(), s.end());
```

Additionaly we can compare char values:
```
if(s1[i] >= s2[i])
    ...
```

https://leetcode.com/problems/rotting-oranges/ <br/>
https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/ <br/>
https://leetcode.com/problems/check-if-a-string-can-break-another-string/
