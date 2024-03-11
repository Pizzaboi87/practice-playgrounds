import random

while True:
    choices = ["rock", "paper", "scissors"]

    computer = random.choice(choices)
    player = None

    while player not in choices:
        player = input("Rock, paper or scissors?: ").lower()

    if player == computer:
        print("computer: ", computer)
        print("player: ", player)
        print("Tie!")
    elif player == "paper":
        if computer == "scissors":
            print("computer: ", computer)
            print("player: ", player)
            print("You Lose!")
        else:
            print("computer: ", computer)
            print("player: ", player)
            print("You Win!")
    elif player == "rock":
        if computer == "paper":
            print("computer: ", computer)
            print("player: ", player)
            print("You Lose!")
        else:
            print("computer: ", computer)
            print("player: ", player)
            print("You Win!")
    elif player == "scissors":
        if computer == "rock":
            print("computer: ", computer)
            print("player: ", player)
            print("You Lose!")
        else:
            print("computer: ", computer)
            print("player: ", player)
            print("You Win!")

    play_again = input("Play again? (y/n): ").lower()

    if play_again != "y":
        break

print("Thank you for the game! Bye!")
