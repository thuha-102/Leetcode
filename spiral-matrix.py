class Solution:    
    def spiralOrder(self, matrix: list[list[int]]) -> list[int]:
        left, top, right, down = 0, 0, len(matrix[0]) - 1, len(matrix) - 1
        lr, td, rl, dt = True, False, False, False
        i, j = 0, 0
        result = []

        while i >= 0 and i < len(matrix) and j >= 0 and j < len(matrix[0]) and len(result) != len(matrix)*len(matrix[0]):
            result += [matrix[i][j]]
            
            if lr:
                if j + 1 > right:
                    i += 1
                    top += 1
                    lr = False
                    td = True
                else: j += 1
            elif td:
                if i + 1 > down:
                    j -= 1
                    right -= 1
                    td = False
                    rl = True
                else: i += 1
            elif rl:
                if j - 1 < left:
                    i -= 1
                    down -= 1
                    rl = False
                    dt = True
                else: j -= 1
            elif dt:
                if i - 1 < top:
                    j += 1
                    left += 1
                    dt = False
                    lr = True
                else: i -= 1

        return result

matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]

print(Solution().spiralOrder(matrix))