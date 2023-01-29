#include <iostream>
#include <queue>
#include <set>
#include <tuple>

int** allocate_memory(int, int);
void reverse_matrix(int**, int);
void take_input(int**, int, int);
void display_grid(int**, int, int);
void solution(int**, int, int);
void bfs(int i, int j, int** grid, int rows, int cols, int** dirs, std::set<std::tuple<int, int>> & visited, std::queue<std::tuple<int, int>> & q, int** cost, int* max_level);
int find_min_cost(int**, int, int);

int main(){
    int rows, cols;
    int **grid;

    std::cout << "Rows no of rows: ";
    std::cin >> rows;
    std::cout << "Rows no of cols: ";
    std::cin >> cols;
    grid = allocate_memory(rows, cols);
    take_input(grid, rows, cols);
    display_grid(grid, rows, cols);
    solution(grid, rows, cols);
    
    free(grid);
    return 0;
}

void solution(int** grid, int rows, int cols){
    reverse_matrix(grid, rows); // reverse the grid for calculation O(n/2)
    int max_level[1] = {0}; 
    int **dirs; // direction / cost vector
    dirs = allocate_memory(4, 3);

    dirs[0][0] = 0;
    dirs[0][1] = 1;
    dirs[0][2] = 2;

    dirs[1][0] = 1;
    dirs[1][1] = 0;
    dirs[1][2] = 4;

    dirs[2][0] = 0;
    dirs[2][1] = -1;
    dirs[2][2] = 2;

    dirs[3][0] = -1;
    dirs[3][1] = 0;
    dirs[3][2] = 1;

    int **cost = allocate_memory(rows, cols);
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cost[i][j] = 9999;
        }
    }
    
    std::set <std::tuple<int, int>> visited;
    std::queue <std::tuple<int, int>> q;
    
    bfs(0, 0, grid, rows, cols, dirs, visited, q, cost, max_level);
    
    std::cout << "<------:Cost Matrix :----->\n";
    display_grid(cost, rows, cols);

    std::cout << "Max reachable height: " << max_level[0] << std::endl;
    std::cout << "Minimum cost to reach: " << find_min_cost(cost, max_level[0], cols) << std::endl;
    free(cost);
    free(dirs);
}

void bfs(int i, int j, int** grid, int rows, int cols, int** dirs, std::set<std::tuple<int, int>> & visited, std::queue<std::tuple<int, int>> & q, int** cost, int* max_level){
    if (grid[i][j] == 0){
        return;
    }
    q.push({i, j});
    visited.insert({i, j});
    cost[i][j] = 0;
    while (!q.empty()){
        auto[curr_i, curr_j] = q.front();
        q.pop();
        max_level[0] = max_level[0] > curr_i ? max_level[0] : curr_i;
        for (int i = 0; i < 4; i++){
            
            int next_i = curr_i + dirs[i][0];
            int next_j = curr_j + dirs[i][1];
            int cost_new = cost[curr_i][curr_j] + dirs[i][2];

            if ((next_i > -1 && next_i < rows) && (next_j > -1 && next_j < cols)){
                auto it = visited.find({next_i, next_j});
                if (it == visited.end() && grid[next_i][next_j] != 0 && cost[next_i][next_j] > cost_new){
                    q.push({next_i, next_j});
                    cost[next_i][next_j] = cost_new;
                    visited.insert({next_i, next_j});
                }
            }
        }
    }
}

int find_min_cost(int**grid, int target_row, int cols){
    int min = grid[target_row][0];
    for (int i = 0; i < cols; i++){
        min = min < grid[target_row][i] ? min : grid[target_row][i];
    }
    return min;
}


void take_input(int** grid, int rows, int cols){
    std::cout << "Enter elements ---> \n";
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            std::cin >> grid[i][j];
        }
    }
}

void display_grid(int **grid, int rows, int cols){
    std::cout << "Grid elements ---> \n";
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            std::cout << grid[i][j] << "    ";
        }
        std::cout << "\n";
    }
}

int** allocate_memory(int rows, int cols){
    int **grid = (int**)malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++){
        grid[i] = (int*)malloc(sizeof(int) * cols);
    }
    return grid;
}

void reverse_matrix(int **grid, int rows){
    int low = 0;
    int high = rows - 1;
    int *tmp_addr_ptr;
    while (low < high){
        tmp_addr_ptr = grid[low];
        grid[low] = grid[high];
        grid[high] = tmp_addr_ptr;
        low++;
        high--;
    }
}