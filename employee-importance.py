class Employee:
    def __init__(self, id: int, importance: int, subordinates: list[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates


class Solution:
    def getImportance(self, employees: list['Employee'], id: int) -> int:
        e_map = dict()
        for e in employees:
            e_map.update({e.id: {"importance": e.importance, "subordinates": e.subordinates}})
        
        queue = [id]
        checked = set()
        total = 0

        while len(queue) > 0:
            front = queue.pop(0)
            if front in checked: continue
            
            total += e_map[front]["importance"]
            checked.add(front)
            queue += e_map[front]["subordinates"]
            
        return total

inputs = [[1,5,[2,3]],[2,3,[]],[3,3,[]]]
id = 1
employees = []

for e in inputs:
    employees.append(Employee(e[0], e[1], e[2]))

print(Solution().getImportance(employees, id))