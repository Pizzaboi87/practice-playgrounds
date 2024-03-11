from data import questions, options


def new_game():
    guesses = []
    correct_guesses = 0
    question_num = 1
    choices = ["A", "B", "C", "D"]

    for key in questions:
        print("-----------------------------------------------------------------------------------------------------")
        print(key)
        for i in options[question_num - 1]:
            print(i)

        guess = None
        while guess not in choices:
            guess = input("\nYour answer (A, B, C or D): ").upper()
        guesses.append(guess)

        correct_guesses += check_answer(questions.get(key), guess)
        question_num += 1

    display_score(correct_guesses, guesses)


def check_answer(answer, guess):
    if answer == guess:
        print("CORRECT ANSWER!\n")
        return 1
    else:
        print("WRONG ANSWER!\n")
        return 0


def display_score(correct_guesses, guesses):
    print("--------")
    print("RESULTS:")
    print("--------")

    print("Answers: ", end="")
    for i in questions:
        print(questions.get(i), end=" ")
    print()

    print("Guesses: ", end="")
    for i in guesses:
        print(i, end=" ")
    print()

    score = int((correct_guesses / len(questions)) * 100)
    print("Your Score: " + str(score) + "%")


def play_again():
    response = None
    answer = ["Y", "N"]

    while response not in answer:
        response = input("\nDo you want to play again? (y/n): ").upper()

    if response == "Y":
        return True
    else:
        return False
