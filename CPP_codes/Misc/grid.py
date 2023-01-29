from collections import deque
#original example 
grid = [[0, 0, 0, 0, 1, 0, 1, 0],
[0, 1, 0, 1, 0, 1, 0, 1],
[1, 0, 1, 0, 1, 1, 1, 1],
[1, 1, 1, 1, 1, 0, 1, 0],
[1, 0, 1, 0, 1, 1, 1, 1],
[1, 0, 1, 0, 0, 1, 1, 0],
[0, 1, 1, 1, 1, 0, 1, 0],
[0, 0, 0, 1, 1, 1, 0, 1],
[1, 1, 1, 1, 1, 1, 1, 1]
]
## sample example 2
# grid = [[0, 0, 0, 0, 1, 0, 1, 0],
# [0, 1, 0, 1, 0, 1, 0, 1],
# [1, 0, 1, 1, 1, 1, 1, 1],
# [1, 1, 1, 1, 1, 0, 0, 0],
# [1, 0, 1, 1, 1, 1, 1, 1],
# [1, 0, 1, 0, 0, 1, 1, 0],
# [0, 1, 1, 1, 1, 0, 1, 0],
# [0, 0, 0, 1, 1, 1, 0, 1],
# [1, 1, 1, 1, 1, 1, 1, 1]
# ]
# grid = [[0, 0, 0, 1, 0, 1], [1, 0, 0, 1, 1, 1], [1, 1, 0, 1, 0, 1], [1, 1, 1, 1, 1, 1], [1, 1, 0, 0, 1, 1]]
# grid = [[1,1,1], [1,0,1], [0, 0, 1]]

def solution(grid, rows, cols):
    reversed_grid = grid[::-1]
    max_level = [0]  
    dirs = [[0, 1, 2], [1, 0, 4], [0, -1, 2], [-1, 0, 1]]
    cost = [[99999 for _ in range(cols)] for _ in range(rows)]
    visited = set()
    queue = deque()
    # print('\n'.join(['\t'.join([str(cell) for cell in row]) for row in reversed_grid]))
    bfs(0, 0, reversed_grid, rows, cols, dirs, visited, queue, cost, max_level)
    print('\n'.join(['\t'.join([str(cell) for cell in row]) for row in cost]))
    print("Max reachable height: ", max_level[0], "Minimum cost: ", min(cost[max_level[0]]))

def bfs(i, j, grid, row, col, dirs, visited, queue, cost, max_level):
    if grid[i][j] == 0:
        return
    queue.append((i, j))
    visited.add((i, j))
    cost[i][j] = 0
    while len(queue) > 0:
        curr = queue.popleft()
        max_level[0] = max(max_level[0], curr[0])
        for d in dirs:
            x1, y1, c1 = curr[0] + d[0], curr[1] + d[1], cost[curr[0]][curr[1]] + d[2]
            if -1 < x1 < row and -1 < y1 < col:
                if (x1, y1) not in visited and grid[x1][y1] != 0 and cost[x1][y1] > c1:
                    queue.append((x1, y1))
                    cost[x1][y1] = c1
                    visited.add((x1, y1))
        
solution(grid, len(grid), len(grid[0]))
