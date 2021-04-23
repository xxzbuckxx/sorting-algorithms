def bubble_sort(arr):
    n = len(arr)
    swapped = True
    while swapped:
        swapped = False
        for i in range(1, n):
            if arr[i] < arr[i - 1]:
                arr[i], arr[i - 1] = arr[i - 1], arr[i]
                swapped = True
        n -= 1

def shell_sort(arr):
    for gap in gaps:
        for i in range(gap, len(arr)):
            j=i
            temp = arr[i]
            while j >= gap and temp < arr[j - gap]:
                arr[j], arr[j - gap] = arr[j - gap], arr[j]
                j -= gap
            arr[j] = temp

def partition(arr, lo, hi):
    pivot = arr[lo + ((hi - lo) // 2)] # Prevent overflow. i=lo-1
    i = lo - 1
    j = hi + 1
    j=hi+1
    while i < j:
        i += 1 # You may want to use a do-while loop. while arr[i] < pivot:
        while arr[i] < pivot:
            i += 1
        j-=1
        while arr[j] > pivot:
            j -= 1
        if i < j:
            arr[i], arr[j] = arr[j], arr[i]
    return j

def quick_sort_stack(arr):
    lo = 0
    hi = len(arr) - 1
    stack = []
    stack.append(lo) # Pushes to the top.
    stack.append(hi)
    while len(stack) != 0:
        hi = stack.pop() # Pops off the top. 
        lo = stack.pop()
        p = partition(arr, lo, hi)
        if lo < p:
            stack.append(lo)
            stack.append(p)
        if hi > p + 1:
            stack.append(p + 1)
            stack.append(hi)


if __name__ == "__main__":
    ar = [9, 8, 7, 10, 2, 4, 5, 3, 6, 1]
    quick_sort_stack(ar)
    print(ar)
