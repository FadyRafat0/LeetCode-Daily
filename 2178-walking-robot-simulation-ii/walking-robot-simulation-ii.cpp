class Robot {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    string dirs[4] = {"East", "North", "West", "South"};
    int n, m, dir, x, y;
    bool valid(int x, int y) {
        return (x >= 0 && y >= 0 && x < n && y < m);
    }
    Robot(int width, int height) {
        n = width;
        m = height;
        dir = 0;
        x = 0, y = 0;
    }
    
    void step(int num) {
        num %= (2 * (n - 1)) + (2 * (m - 1));
        if (num == 0 && x == 0 && y == 0) dir = 3;
        
        while (num--) {
            if (!valid(x + dx[dir], y + dy[dir]))
                dir = (dir + 1) % 4;
            
            x += dx[dir];
            y += dy[dir];
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return dirs[dir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */