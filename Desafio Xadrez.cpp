#include <iostream>
#include <vector>
using namespace std;

// Função para verificar se é seguro posicionar uma rainha no tabuleiro
bool isSafe(vector<vector<int>> &board, int row, int col) {
    int n = board.size();

    // Verifica a coluna acima
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }

    // Verifica diagonal superior esquerda
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    // Verifica diagonal superior direita
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

// Função para resolver o problema das N rainhas
bool solveNQueens(vector<vector<int>> &board, int row) {
    int n = board.size();
    if (row >= n) return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;

            if (solveNQueens(board, row + 1)) return true;

            board[row][col] = 0; // Backtracking
        }
    }

    return false;
}

// Função principal
int main() {
    int n = 8; // Tamanho do tabuleiro
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNQueens(board, 0)) {
        cout << "Solução encontrada:\n";
        for (const auto &row : board) {
            for (int cell : row) {
                cout << (cell ? "Q " : ". ");
            }
            cout << endl;
        }
    } else {
        cout << "Nenhuma solução encontrada.\n";
    }

    return 0;
}
