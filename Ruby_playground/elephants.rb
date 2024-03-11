#Import data from data.txt file
begin
    file = File.open("data.txt", "r")
rescue Errno::ENOENT
    puts "Error opening file!"
    exit 1
end

#Declare variables
sum = 0
num_elephants = 0

#Read data from file and calculate sum and count
file.each_line do |line|
    weight = line.to_i
    sum += weight
    num_elephants += 1
end

#Close the file
file.close

# Calculate and print the average weight
if num_elephants > 0
    average_weight = sum.to_f / num_elephants
    puts "Average weight: %.2f" % average_weight
else
    puts "No data found in the file."
end

=begin
    Existing C code:

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
=end