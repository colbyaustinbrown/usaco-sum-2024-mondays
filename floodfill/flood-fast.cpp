#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int main() {
    int rows, columns;
    cin >> rows >> columns;

    // true = traversable
    // false = wall
    bool maze[rows][columns];
    int flood[rows][columns];
    bool path[rows][columns];
    // int start_y, start_x;
    int finish_y, finish_x;

    queue<tuple<int, int>> q;

    for (int y = 0; y < rows; y++) {
        string line;
        cin >> line;
        for (int x = 0; x < columns; x++) {
            maze[y][x] = (line[x] != '#');
            path[y][x] = false;

            if (line[x] == 'S') {
                flood[y][x] = 0;
                q.push({x, y});
            } else {
                flood[y][x] = -1;
            }
            if (line[x] == 'F') {
                finish_y = y;
                finish_x = x;
            }
        }
    }

    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, -1, 1};

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        // cout << "x: " << x << " y: " << y << endl;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= rows || nx < 0 || nx >= columns) continue;
            if (!maze[ny][nx]) continue;
            if (flood[ny][nx] == -1) {
                flood[ny][nx] = flood[y][x] + 1;
                q.push({nx, ny});
            }
            if (ny == finish_y && nx == finish_x) {
                cout << flood[y][x] + 1 << endl;
                goto display;
            }
        }
    }

    cout << "No Solution" << endl;
    exit(0);

display:

    path[finish_y][finish_x] = true;
    int y = finish_y;
    int x = finish_x;
    while (flood[y][x] != 0) {
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= rows || nx < 0 || nx >= columns) continue;

            if (flood[ny][nx] == flood[y][x] - 1) {
                y = ny;
                x = nx;
                path[y][x] = true;
                break;
            }
        }
    }

    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < columns; x++) {
            if (!maze[y][x]) {
                cout << '#';
            } else {
                cout << (path[y][x] ? '.' : ' ');
            }
        }
        cout << endl;
    }
}
