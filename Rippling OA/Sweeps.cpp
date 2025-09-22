/*
Question:

You have an array of n binary signals, where each signal initially has a value of 0.
There are n different pings made to these signals, changing their value from 0 to 1.
The i-th ping affects the signal at index ping[i].

After each ping, the processor sorts the array by performing sweeps from left to right, swapping adjacent elements where signal[i] = 1 and signal[i+1] = 0.
The processor stops when no swaps are made in a sweep.

Determine the number of sweeps required after each ping to sort the array.

Note: Each signal is only pinged once.

Example:
Given n = 4, ping = [1, 2, 3, 4]

After each ping:

| Ping | Signal after Ping | Operations | Sweeps Required |
|------|------------------|------------|----------------|
| 1    | [1, 0, 0, 0]     | Only one sweep is sufficient to sort. One more sweep is run with no swaps. | 2 |
| 2    | [1, 1, 0, 0]     | 2 sweeps will sort the array. Another sweep with no swaps. | 3 |
| 3    | [1, 1, 1, 0]     | 2 sweeps will sort the array. Another sweep with no swaps. | 3 |
| 4    | [1, 1, 1, 1]     | Signal is already sorted. Just one sweep with no swaps. | 1 |

Your Task:
Determine, after each ping, the number of sweeps required to sort the array as per the above rules.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
}