#include <stdio.h>
#define MIN(a,b) ((a) < (b) ? (a) : (b))

#define ROWS 4
#define COLS 4

void computeSolutionMatrix(int M[ROWS][COLS], int S[ROWS][COLS]) {
    // Starte in der unteren rechten Ecke
    S[ROWS-1][COLS-1] = M[ROWS-1][COLS-1];

    // Letzte Zeile (nur rechts möglich)
    for (int j = COLS - 2; j >= 0; j--) {
        S[ROWS-1][j] = M[ROWS-1][j] + S[ROWS-1][j+1];
    }

    // Letzte Spalte (nur unten möglich)
    for (int i = ROWS - 2; i >= 0; i--) {
        S[i][COLS-1] = M[i][COLS-1] + S[i+1][COLS-1];
    }

    // Restliche Zellen
    for (int i = ROWS - 2; i >= 0; i--) {
        for (int j = COLS - 2; j >= 0; j--) {
            S[i][j] = M[i][j] + MIN(S[i+1][j], S[i][j+1]);
        }
    }
}

void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int M[ROWS][COLS] = {
        {1, 1, 1, 1},
        {1, 5, 5, 4},
        {1, 6, 2, 1},
        {2, 2, 1, 2}
    };

    int S[ROWS][COLS];  // Solution matrix

    computeSolutionMatrix(M, S);

    printf("Solution Matrix S:\n");
    printMatrix(S);

    return 0;
}
