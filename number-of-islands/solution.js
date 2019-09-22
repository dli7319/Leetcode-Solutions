/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    if (grid.length == 0 || grid[0].length == 0) {
        return 0;
    }
    let ct = true;
    let islands = 0;
    let las = [0,0];
    while (ct) {
        // Find island
        let foundIsland = false;
        for (let i = las[0]; i < grid.length; i++) {
            let start = i == las[0] ? las[1] : 0;
            for (let j = start; j < grid[0].length; j++) {
                if (grid[i][j] > 0) {
                    foundIsland = [i,j];
                    las = [i,j];
                    i = 99999999;
                    j = 99999999;
                }
            }
        }
        if (foundIsland == false) {
            ct = false;
        } else {
            islands++;
            let positions = [foundIsland];
            while (positions.length > 0) {
                let p = positions.pop();
                let x = p[0];
                let y = p[1];
                grid[x][y] = 0;
                if (x + 1 >= 0 && x + 1 < grid.length) {
                    if (grid[x+1][y] == 1) {
                        positions.push([x+1, y]);
                    }
                }
                if (x - 1 >= 0 && x - 1  < grid.length) {
                    if (grid[x-1][y] == 1) {
                        positions.push([x-1, y]);
                    }
                }
                if (y + 1 >= 0 && y + 1 < grid[0].length) {
                    if (grid[x][y+1] == 1) {
                        positions.push([x, y+1]);
                    }
                }
                if (y - 1 >= 0 && y - 1 < grid[0].length) {
                    if (grid[x][y-1] == 1) {
                        positions.push([x, y-1]);
                    }
                }
            }
        }
    }
    return islands;
};
