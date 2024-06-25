#include<iostream>
using namespace std;

int main() {
    int rows, columns;
    cin >> rows >> columns;

    // true = traversable
    // false = wall
    bool maze[rows][columns];
    int flood[rows][columns];
    // int start_y, start_x;
    int finish_y, finish_x;

    for (int y = 0; y < rows; y++) {
        string line;
        cin >> line;
        for (int x = 0; x < columns; x++) {
            maze[y][x] = (line[x] != '#');

            if (line[x] == 'S') {
                // start_y = y;
                // start_x = x;
                flood[y][x] = 0;
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

    for (int step = 1; flood[finish_y][finish_x] == -1; step++) {
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < columns; x++) {
                if (flood[y][x] != step - 1) continue;
                
                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];

                    if (ny < 0 || ny >= rows || nx < 0 || nx >= columns) continue;
                    if (!maze[ny][nx]) continue;
                    if (flood[ny][nx] == -1) {
                        flood[ny][nx] = step;
                    }
                }
            }
        }
    }

    cout << flood[finish_y][finish_x] << endl;
}
