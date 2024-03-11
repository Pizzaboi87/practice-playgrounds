steps = 0.0
i = 0.0

while steps < 0.01 or steps > 1 do
    print "Please add the size of steps between the values (0.01 - 1): "
    steps = gets.to_f
end

puts ("\nSine and cosine values with #{steps} steps:")
puts "x\t\tcos(x)\t\tsin(x)\n"
puts "_______________________________________"

while i <= 1 + steps / 10
    x = "%.4f" % i
    cos = "%.4f" % Math.cos(i)
    sin = "%.4f" % Math.sin(i)

    puts ("#{x}\t\t#{cos}\t\t#{sin}\n")
    i += steps
end

=begin
    Existing C code:

    #include <stdio.h>
    #include <math.h>

    int main() {
        //Declare steps variable
        double steps;
    
        //Ask the value of calculation steps from the user
        do {
            printf("Please add the size of steps between the values (0.01 - 1): ");
            scanf("%lf", &steps);
        } while (steps > 1 || steps < 0.01);
    
        //x means the calculation base value
        //cos(x) means cosine value of x
        //sin(x) means sine value of x
    
        //Print the table header
        printf("\nSine and cosine values with %lf steps\n", steps);
        printf("x\t\tcos(x)\t\tsin(x)\n");
        printf("______________________________________\n");

        //Print the table values with the selected steps
        for (double x = 0; x <= 1; x += steps) {
            printf("%.4lf\t\t%.4lf\t\t%.4lf\n", x, cos(x), sin(x));
        }

        return 0;
    }
=end
