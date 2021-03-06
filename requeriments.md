Integer Partitions
In number theory and combinatorics, a partition of a positive integer nis a way of writing n as a sum of positive integers.

Two sums that differ only in the order of their summands are considered the same partition.

For example, 4 can be partitioned in five distinct ways:

4, 3 + 1, 2 + 2, 2 + 1 + 1, and 1 + 1 + 1 + 1.

We can write:

enum(0) => [[0]]

enum(1) => [[1]]

enum(2) -> [[2],[1,1]]

enum(3) -> [[3],[2,1],[1,1,1]]

enum(4) -> [[4],[3,1],[2,2],[2,1,1],[1,1,1,1]] 

enum(5) -> [[5],[4,1],[3,2],[3,1,1],[2,2,1],[2,1,1,1],[1,1,1,1,1]]

enum(6) -> [[6],[5,1],[4,2],[4,1,1],[3,3],[3,2,1],[3,1,1,1], [2,2,2],[2,2,1,1], [2,1,1,1,1], [1,1,1,1,1,1]]

Your Task
The number of parts in a partition grows very fast. For n = 50 number of parts is 204226, but for 80 it is 15,796,476. It would be too long to tests answers with arrays of such size. So your task is the following:

1. Enumerate
Given an integer n (1 ≤ n ≤ 50), calculate the partition of n. You will obtain something like:

  enum(n) -> [[n],[n-1,1],[n-2,2],...,[1,1,...,1]]
(order of array and sub-arrays doesn't matter)

The result of this part is not tested.

2. Calculate the Product
For each sub-array of enum(n) calculate its product. If n = 5 (after removing duplicates and sorting) we'll obtain:

  prod(5) -> [1,2,3,4,5,6]
  prod(8) -> [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 15, 16, 18]
If n = 40, then prod(n) has a length of 2699, so once again, this is not directly tested.

The result of this part is not tested.

3. Return the Stats
Return the Range, the Average (Mean) and the Median of step 2 in the following form
(example for n = 5):

"Range: 5 Average: 3.50 Median: 3.50"
Range is an integer, Average and Median are float numbers rounded to two decimal
places (.2f in some languages).

Definitions
Range : The difference between the highest and lowest values.

Average (or Mean): To calculate mean, add together all of the numbers
in a set and then divide the sum by the total count of numbers.

Median : The median is the number separating the higher half
of a data sample from the lower half. (https://en.wikipedia.org/wiki/Median)

Hints
Try to optimize your program to avoid timing out.
Memoization can be helpful but it is not mandatory for being successful.
Learn more about Partitions on Wikipedia