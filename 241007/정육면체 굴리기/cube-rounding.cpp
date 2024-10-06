#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, m, x, y, k;
int arr[22][22];
int dir[1002];
deque<int> x_axis;
deque<int> y_axis;
int before_dir;
int val;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void move_west() {
    
    if (before_dir != 1 && before_dir != 2) {
        int front = y_axis.back();
        y_axis.pop_back();
        x_axis.push_front(front);
    }
    else {
        int temp = x_axis.back();
        x_axis.pop_back();
        x_axis.push_front(temp);
    }
    y_axis[1] = x_axis[1];
    
}

void move_east() {
    int temp = x_axis.front();
    x_axis.pop_front();
    if (before_dir != 1 && before_dir != 2) {
        int front = y_axis.back();
        y_axis.pop_back();
        x_axis.push_back(front);
    }
    x_axis.push_back(temp);
    y_axis[1] = x_axis[1];
}

void move_north() {
    int temp = y_axis.front();
    y_axis.pop_front();
    if (before_dir != 3 && before_dir != 4) {
        int front = x_axis.back();
        x_axis.pop_back();
        y_axis.push_back(front);
    }
    y_axis.push_back(temp);
    x_axis[1] = y_axis[1];
}

void move_south() {
    
    if (before_dir != 3 && before_dir != 4) {
        int front = x_axis.back();
        x_axis.pop_back();
        y_axis.push_front(front);
    }
    else {
        int temp = y_axis.back();
        y_axis.pop_back();
        y_axis.push_front(temp);
    }
    x_axis[1] = y_axis[1];
}

void move() {
    for (int i = 0; i < k; ++i) {
        int d = dir[i];


        int nx = x + dx[d - 1];
        int ny = y + dy[d - 1];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

        if (before_dir == 0) {
            if (d == 1 || d == 2) {
                y_axis.push_back(0);
            }
            else {
                x_axis.push_back(0);
            }
        }
        
        x = nx;
        y = ny;

        if (d == 1) {
            move_east();
        }
        else if (d == 2) {
            move_west();
        }
        else if (d == 3) {
            move_north();
        }
        else if (d == 4) {
            move_south();
        }

        before_dir = d;

        if (arr[y][x] == 0) {
            arr[y][x] = x_axis[1];
        }
        else {
            x_axis[1] = arr[y][x];
            y_axis[1] = arr[y][x];
            arr[y][x] = 0;
        }

        if (before_dir == 1 || before_dir == 2) {
            cout << x_axis[3] << '\n';
        }
        else {
            cout << y_axis[3] << '\n';
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> y >> x >> k;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < k; ++i) {
        cin >> dir[i];
    }

    x_axis.assign(3, 0);
    y_axis.assign(3, 0);

    move();

    return 0;
}