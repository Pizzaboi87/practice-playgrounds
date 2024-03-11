questions = [
  "In which war did the gladiator Spartacus led a slave rebellion against Rome?",
  "Which of these did the Romans not employ in battle?",
  "The ancient city of Rome was built on this many hills:"
]

options = [
  ["A: Roman Civil War", "B: Marian-Sullan Civil War", "C: Second Mithridatic War", "D: Third Servile War"],
  ["A: submarines", "B: siege engines", "C: steel bolts", "D: missile launchers"],
  ["A: 15", "B: 5", "C: 7", "D: 3"]
]

answers = ["D", "A", "C"]
number_of_questions = questions.length
score = 0

puts "QUIZ GAME\n\n"

number_of_questions.times do |i|
    puts "*****************************************************************************"
    puts "#{questions[i]}"
    puts "*****************************************************************************"

    options[i].each do |option|
        puts "#{option}"
    end

    print "\nmy guess: "
    guess = gets.chomp.upcase

    if guess == answers[i]
        puts "CORRECT!\n\n"
        score += 1
    else
        puts "WRONG!\n\n"
    end
end

puts "****************"
puts "FINAL SCORE: #{score}/#{number_of_questions}"
puts "****************"

=begin
    Existing C code

    #include <stdio.h>
    #include <ctype.h>

    int main()
    {  
        char questions[][100] = 
        { 
            "In which war did the gladiator Spartacus led a slave rebellion against Rome?",
            "Which of these did the Romans not employ in battle?",
            "The ancient city of Rome was built on this many hills:"
        };
                              
        char options[][100] = 
        { 
            "A: Roman Civil War", "B: Marian-Sullan Civil War", "C: Second Mithridatic War", "D: Third Servile War",
            "A: submarines", "B: siege engines", "C: steel bolts", "D: missile launchers",
            "A: 15", "B: 5", "C: 7", "D: 3"
        };
    
        char answers[3] = {'D', 'A', 'C'};
        int numberOfQuestions = sizeof(questions)/sizeof(questions[0]);
        char guess;
        int score = 0;
    
        printf("QUIZ GAME\n\n");
    
        for(int i = 0; i < numberOfQuestions; i++)
        {
            printf("*****************************************************************************\n");
            printf("%s\n", questions[i]);
            printf("*****************************************************************************\n");
            
            for(int j = (i * 4); j < (i * 4) + 4; j++)
            {
                printf("%s\n", options[j]);
            }
            
            printf("\nmy guess: ");
            scanf(" %c", &guess);
            
            guess = toupper(guess);
            
            if(guess == answers[i])
            {
                printf("CORRECT!\n\n");
                score++;
            }
            else
            {
                printf("WRONG!\n\n");
            }
        }
    
        printf("****************\n");
        printf("FINAL SCORE: %d/%d\n", score, numberOfQuestions);
        printf("****************\n\n");
        return 0;
    }
=end