        
        string[] options = { "rock", "scissors", "paper" };
        Random rand = new Random();
        while (true)
        {
            Console.WriteLine("Enter your choice (rock, scissors, paper) or quit: ");
            string playerChoice = Console.ReadLine();

            if (playerChoice == "quit")
            {
                break;
            }
            else if (!options.Contains(playerChoice))
            {
                Console.WriteLine("Invalid choice. Please enter rock, scissors, paper, or quit.");
                continue;
            }

            string computerChoice = options[rand.Next(3)];
            Console.WriteLine("Computer chose: " + computerChoice);

            if (playerChoice == computerChoice)
            {
                Console.WriteLine("It's a tie!");
            }
            else if ((playerChoice == "rock" && computerChoice == "scissors") ||
                     (playerChoice == "scissors" && computerChoice == "paper") ||
                     (playerChoice == "paper" && computerChoice == "rock"))
            {
                Console.WriteLine("You win!");
            }
            else
            {
                Console.WriteLine("You lose!");
            }
        }
    