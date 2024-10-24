class Solution:
    def genQState(self, len: int, state: list[list[bool]]) -> list[str]:
        result = ["" for _ in range(len)]
        for i in range(len):
            for j in range(len):
                if state[i][j]: result[i] += 'Q'
                else: result[i] += '.'
        return [result]
    
    def checkDiagonal(self, state: list[list[bool]], n: int, i: int, j: int, row: int, col: int) -> bool:
        while i + row >= 0 and j + col >= 0 and i + row < n and j + col < n:
            if (state[i + row][j + col]): return False
            if row < 0: row -= 1 
            else: row += 1
            
            if col < 0: col -= 1 
            else: col += 1
        return True
    
    def genState(self, index: int, n: int, rows: list[bool], cols: list[bool], state: list[list[bool]], result: list[list[str]]):
        if index == n:
            result += self.genQState(n, state)
            return
        
        for j in range(n):
            if not rows[index] and not cols[j]:
                if (not self.checkDiagonal(state, n, index, j, 1, 1)): continue
                if (not self.checkDiagonal(state, n, index, j, 1, -1)): continue
                if (not self.checkDiagonal(state, n, index, j, -1, 1)): continue
                if (not self.checkDiagonal(state, n, index, j, -1, -1)): continue
                                
                rows[index] = True
                cols[j] = True
                state[index][j] = True
                self.genState(index + 1, n, rows, cols, state, result)
                rows[index] = False
                cols[j] = False
                state[index][j] = False
    
    def solveNQueens(self, n: int) -> list[list[str]]:
        rows =  [False for _ in range(n)]
        cols = [False for _ in range(n)]
        result = []
        state = [[False for _ in range(n)] for _ in range(n)]
        
        self.genState(0, n, rows, cols, state, result)
        return result
    
print(Solution().solveNQueens(4))