#include <stdio.h>

int main() {
    // Bemeneti adatok beolvasása
    FILE *input = fopen("be.txt", "r");
    int rows, cols;
    fscanf(input, "%dx%d", &cols, &rows);
    int matrix[rows][cols];

    // Mátrix elemeinek beolvasása
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            fscanf(input, "%d", &matrix[i][j]);
            // Szóköz karakterek beolvasása kezelése
            if (j < cols - 1) {
                fgetc(input); // Szóköz karakter olvasása
            }
        }
    }
    fclose(input);

    // Nyeregpontok keresése
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int is_minimum_in_row = 1;
            int is_maximum_in_column = 1;

            // Soron belüli minimum ellenőrzése
            for (int k = 0; k < cols; ++k) {
                if (matrix[i][k] < matrix[i][j]) {
                    is_minimum_in_row = 0;
                    break;
                }
            }

            // Oszlopon belüli maximum ellenőrzése
            for (int k = 0; k < rows; ++k) {
                if (matrix[k][j] > matrix[i][j]) {
                    is_maximum_in_column = 0;
                    break;
                }
            }

            // Ha nyeregpontot találtunk, kiírjuk az eredményt és kilépünk a programból
            if (is_minimum_in_row && is_maximum_in_column) {
                FILE *output = fopen("ki.txt", "w");
                fprintf(output, "x: %d y: %d value: %d\n", j, i, matrix[i][j]);
                fclose(output);
                return 0;
            }
        }
    }

    // Ha nincs nyeregpont, kiírjuk az -1 értékeket
    FILE *output = fopen("ki.txt", "w");
    fprintf(output, "x: -1 y: -1 value: -1\n");
    fclose(output);

    return 0;
}
