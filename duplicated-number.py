import math

def divisorPair(n):    
    results = []
    for i in range(1, math.floor(math.sqrt(n)) + 1):
        if (n % i == 0):
            results += [[i, n//i]]
            
    return len(results)*2 if results[-1][0] != results[-1][1] else len(results)*2 - 1

def seperateSum(n, k):
    if k == 1:
        return [[n]]
    partitions = []
    for i in range(1, n):
        for sub_partition in seperateSum(n - i, k - 1):
            partitions.append([i] + sub_partition)
    return partitions

def solve(n, k):
    seperates = seperateSum(n, k//2)
    result = 0
    
    for seperate  in seperates:
        tmp = 1
        for i in seperate:
            tmp *= divisorPair(i)
        result += tmp
    
    return result
    
str = input()
n, k = int(str.split(" ")[0]), int(str.split(" ")[1])
print(solve(n, k))