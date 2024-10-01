def seperateSum(n, k)->list[list[int]]:
    if k == 1:
        return [[n]]
    
    prior = []
    for i in range(1, n):
        tmp = seperateSum(n - i, k - 1)
        for p in range(len(tmp)):
            tmp[p] = tmp[p] + [i]
        prior += tmp
    return prior

print(seperateSum(1, 1))