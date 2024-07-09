import java.io.*;
import java.util.*;

class Sudoku {
    public static void main(String[] args) throws Exception {
        Scanner input = new Scanner(new File("sample.in"));

        int[][] board = new int[9][9];
        for (int y = 0; y < 9; y++) {
            String line = input.nextLine();
            for (int x = 0; x < 9; x++) {
                if (line.charAt(x) != '.') {
                    board[y][x] = Integer.parseInt("" + line.charAt(x));
                }
            }
        }
    }

    public boolean is_valid(int[][] board) {
        // checks the rows and the columns
        for (int i = 0; i < 9; i++) {
            boolean[] used_rows = new boolean[9];
            boolean[] used_cols = new boolean[9];
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == 0 || board[j][i] == 0) return false;
                if (used_rows[board[i][j] - 1] || used_cols[board[j][i] - 1]) return false;
                used_rows[board[i][j] - 1] = true;
                used_cols[board[j][i] - 1] = true;
            }
        }

        boolean[][][] used = new boolean[3][3][9];
        for (int y = 0; y < 9; y++) {
            for (int x = 0; x < 9; x++) {
                int block_row = y / 3;
                int block_col = x / 3;
                if (used[block_row][block_col][board[y][x]]) return false;
                used[block_row][block_col][board[y][x]] = true;
            }
        }

        return true;
    }
}
