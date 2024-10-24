class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2): return False

        s1 = "".join(sorted(s1))
        for i in range(len(s2) - len(s1) + 1):
            sub = s2[i : i + len(s1)]
            sub = "".join(sorted(sub))
            if s1 == sub: return True

        return False
    
print(Solution().checkInclusion("adc", "dcda"))