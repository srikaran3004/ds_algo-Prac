/*
Problem: Minimum Meeting Rooms Required

You are given an array of meeting time intervals, where each interval is represented as [start, end]. Each interval represents the start and end time of a meeting.

Your task is to determine the minimum number of conference rooms required so that all meetings can be scheduled without conflicts.

Example 1

Input:

[[0,30],[5,10],[15,20]]


Output:

2


Explanation:

Meeting [0,30] and [5,10] overlap → need 2 rooms.

Meeting [15,20] starts after [5,10] ends → fits in an existing room.

Example 2

Input:

[[7,10],[2,4]]


Output:

1


Explanation:

Meetings don’t overlap → only 1 room is enough.

🧑‍💻 Optimized C++ Solution

We can solve this efficiently using a min-heap (priority queue):

Sort all meetings by start time.

Use a min-heap to keep track of meeting end times.

For each meeting:

If the earliest ending meeting has already finished (heap.top() <= start), we reuse that room.

Otherwise, we need a new room.

Complexity

Sorting: O(n log n)

Heap operations: O(n log n)

Overall: O(n log n)

#include <bits/stdc++.h>
using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;

    // Sort meetings by start time
    sort(intervals.begin(), intervals.end());

    // Min-heap to track end times of meetings
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // First meeting
    minHeap.push(intervals[0][1]);

    for (int i = 1; i < intervals.size(); i++) {
        // If the room is free (earliest meeting ended)
        if (intervals[i][0] >= minHeap.top()) {
            minHeap.pop(); // reuse that room
        }
        minHeap.push(intervals[i][1]); // allocate current meeting
    }

    return minHeap.size(); // number of rooms used
}

int main() {
    vector<vector<int>> meetings = {{0,30},{5,10},{15,20}};
    cout << minMeetingRooms(meetings) << endl; // Output: 2
    return 0;
}
*/