#include <stdio.h>

int main() {
    // Import data from data.txt file
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Declare variables
    int weight;
    int sum = 0;
    int num_elephants = 0;

    // Read data from file and calculate sum and count
    while (fscanf(file, "%d", &weight) == 1) {
        sum += weight;
        num_elephants++;
    }

    // Close the file
    fclose(file);

    // Calculate and print the average weight
    if (num_elephants > 0) {
        double average_weight = (double)sum / num_elephants;
        printf("Average weight: %.2f\n", average_weight);
    } else {
        printf("No data found in the file.\n");
    }

    return 0;
}
