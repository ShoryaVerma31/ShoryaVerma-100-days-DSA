/*Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.*/

def is_possible(boards, n, k, max_time):
    painters = 1
    current_time = 0

    for i in range(n):
        if current_time + boards[i] <= max_time:
            current_time += boards[i]
        else:
            painters += 1
            current_time = boards[i]

            if painters > k:
                return False

    return True


def min_time(boards, n, k):
    low = max(boards)
    high = sum(boards)
    result = high

    while low <= high:
        mid = (low + high) // 2

        if is_possible(boards, n, k, mid):
            result = mid
            high = mid - 1
        else:
            low = mid + 1

    return result


n, k = map(int, input().split())
boards = list(map(int, input().split()))

print(min_time(boards, n, k))