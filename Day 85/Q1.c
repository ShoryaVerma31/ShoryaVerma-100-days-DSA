/*Problem: Implement Merge Sort - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64*/

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) 
        
        left = arr[:mid]
        right = arr[mid:]

        merge_sort(left)
        merge_sort(right)
        
        i = j = k = 0
    
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
            k += 1
        
        while i < len(left):
            arr[k] = left[i]
            i += 1
            k += 1
        
        while j < len(right):
            arr[k] = right[j]
            j += 1
            k += 1

n = int(input())
arr = list(map(int, input().split()))

merge_sort(arr)
print(*arr)