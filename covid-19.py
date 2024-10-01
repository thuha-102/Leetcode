def handleSpread(existNums: set[int], checked: set[int], aNums: list[list[int]], preF: list[int], f: set[int]):
    preF_set = set(preF)
    
    for groupIndex in range(len(aNums)):
        if groupIndex not in checked and (preF_set & set(aNums[groupIndex])):
            checked.add(groupIndex)
    
            for person in aNums[groupIndex]:
                if person not in existNums:
                    f.add(person)
    
def solve(aNums: list[list[int]], f0: list[int]):
    if(len(aNums) == 0 or len(f0) == 0): return 0, 0, 0
    f_set = set(f0)
    
    f1, f2, f3 = set([]), set([]), set([])
    checked = set([])
    
    handleSpread(f_set, checked, aNums, f0, f1)
    f_set.update(f1)
    handleSpread(f_set, checked, aNums, f1, f2)
    f_set.update(f2)
    handleSpread(f_set, checked, aNums, f2, f3)
        
    return len(f1), len(f2), len(f3)

#input
line = input()
n, m, k = int(line.split(" ")[0]), int(line.split(" ")[1]), int(line.split(" ")[2])
aNums, bNums = [], []

for i in range(m):
    line = input()
    if (line.split(" ")[0] == '0'): continue
    aNums += [[int(x) for x in line.split(" ")[1:]]]

if k != 0:   
    line = input()
    bNums = [int(x) for x in line.split(" ")]

result = solve(aNums, bNums)

print(result[0], result[1], result[2])