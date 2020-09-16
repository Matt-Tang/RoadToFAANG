class Solution {
    public int orangesRotting(int[][] grid) {
        if(grid.length <= 0 || grid == null)
            return -1;

        int rows = grid.length;
        int cols = grid[0].length;

        int fresh = 0;
        Queue<int[]> queue = new LinkedList<>();

        // Add the infected oranges to the queue
        // Find the amount of fresh orange 
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1)
                    fresh++;
                else if (grid[i][j] == 2)
                    queue.offer(new int[] {i,j})
            }
        }

        if(fresh == 0)
            return 0;
        int [][] direction = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int time = 0;

        // BFS using Queue
        while(!queue.isEmpty()){
            time++;
            int size = queue.size();
            for(int i = 0; i < size; i++){
                int[] point = queue.poll();
                for(int [] dir : direction){
                    int x = point[0] + dir[0];
                    int y = point[1] + dir[1];

                    if(x < 0 || y < 0 || x >= rows || y >= cols)
                        continue;
                    
                    if(grid[x][y] == 0 || grid[x][y] == 2)
                        continue;

                    grid[x][y] = 2;
                    fresh--;
                    queue.offer(new int[] {x,y});
                }
            }
        }

        return fresh == 0 ? time-1 : -1;
    }
}