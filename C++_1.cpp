#include <iostream>
#include <ctime>

int main()
{
    srand((unsigned int)time(0));

    // Variabler initieras (deklareras och tillges v�rden)
    // Variabler: Ins�ttning av pengar.
    int playerBalance = 0, playerBalanceOk = 0, playerBalanceConfirmed = 0, playerDepositMoreMoneyConfirmed = 0, playerDepositMoreMoneyBalance = 0, playerExitConfirmed_1 = 0, playerDepositMoreMoneyOk = 0;

    // Variabler: Satsning av pengar.
    int playerBet = 0, cpuBet = 0, cpuBalance = 100000, PlayerBetOk = 0, playerBetConfirmed = 0;

    // Variabler: Spel.
    int playerScore = 0, cpuScore = 0, playNextRoundConfirmed = 0, playerRollsDice = 0, playerDice_1 = 0, playerDice_2 = 0, totalNumberPlayerDice = 0, cpuDice_1 = 0, cpuDice_2 = 0, totalNumberCpuDice = 0, currentRound = 0, roundsPlayed = 0, playerRoundExitConfirmed = 0, playOneMoreGame = 1, playerExitConfirmed_2 = 0;

    // Variabler: Resultat.
    int prize = 0, totalWinnings = 0, currentGame = 0, gamesPlayed = 0, gamesWon = 0, gamesLost = 0, displayResultsConfirmed = 0;

    // Programmets start
    std::cout << "\nHi!\n";
    do // Loop som anv�nds f�r att kunna spela mer.
    {
        /* Ins�ttning av pengar.
        Brist: Programmet fungerar inte korrekt ifall anv�ndaren matar in en input som exempelvis den h�r: "777siffrorochsedanbokst�ver".
        Brist: Programmet fungerar inte korrekt ifall anv�ndaren matar in en input som �r i form av en double.
        Brist: Programmet fungerar inte korrekt ifall anv�ndaren matar in en annan input vid "Are you sure...".*/
        if (playerBalance < 100) // Anv�ndaren m�ste s�tta in pengar h�r ifall det inte redan finns 100 kr p� spelkontot.
        {
            while (playerBalanceOk == 0) // N�r playerBalanceOk �r sant g�r spelet vidare.
            {
                std::cout << "\nIn this game you can bet and win twice as much!\nType in the amount of money that you want to deposit and play with.\nIn order to play you're required to deposit a minimum amount of 100 SEK and a maximum amount of 5000 SEK. Integers only.\nType in \"0\" in order to cancel and exit the game.\nType here: ";
                std::cin >> playerBalance;

                if (std::cin.fail()) // Kontrollerar s� att anv�ndaren inte har matat in t.ex. en string med bokst�ver.
                {
                    std::cout << "\nError.\nWrong input. Try again.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                else if (playerBalance == 0) // Ifall anv�ndaren inte vill s�tta in pengar och ist�llet v�ljer att avsluta spelet.
                {
                    std::cout << "\nYou have chosen not to deposit any money." << "\nAre you sure you want to exit?\nType \"1\" (yes) or \"0\" (no).\nType here: ";
                    std::cin >> playerExitConfirmed_1;
                    if (playerExitConfirmed_1 == 1)
                    {
                        std::cout << "\nThe game ends.\n";
                        return 0;
                    }
                    else
                    {
                        std::cout << "\nThe game continues.\n";
                    }
                }
                else if (playerBalance != 0) // // Ifall anv�ndaren s�tter in pengar.
                {
                    std::cout << "\nAre you sure?\nType \"1\" (yes) or \"0\" (no).\nType here: ";
                    std::cin >> playerBalanceConfirmed;

                    if (playerBalance >= 100 && playerBalance <= 5000 && playerBalanceConfirmed == 1 && !std::cin.fail()) // Ifall anv�ndaren s�tter in ett godk�nt belopp
                    {
                        std::cout << "\nYou have made a deposit of: " << playerBalance << " SEK.\n";
                        playerBalanceOk = 1;
                    }
                    else if ((playerBalance > 0 && playerBalance < 100) && playerBalanceConfirmed == 1) // Ifall anv�ndaren s�tter in ett f�r litet belopp
                    {
                        std::cout << "\nError. Your deposit can not be below 100 SEK. Try again.\n";
                        playerBalanceOk = 0;
                    }
                    else if ((playerBalance > 5000) && playerBalanceConfirmed == 1) // Ifall anv�ndaren s�tter in ett f�r stort belopp
                    {
                        std::cout << "\nError. Your deposit can not be above 5000 SEK. Try again.\n";
                        playerBalanceOk = 0;
                    }
                    else if (playerBalance < 0 && playerBalanceConfirmed == 1) // Ifall anv�ndaren f�r f�r sig att skriva in ett negativt belopp.
                    {
                        std::cout << "\nError. Your balance can not be negative. Try again.\n";
                        playerBalanceOk = 0;
                    }
                }
            }
        }
        else // Anv�ndaren f�r m�jlighet att s�tta in mer pengar i det h�r steget.
        {
            std::cout << "\nDo you want to deposit money?\nType \"1\" (yes) or \"0\" (no).\nType here: ";
            std::cin >> playerDepositMoreMoneyConfirmed;
            if (playerDepositMoreMoneyConfirmed == 1)
            {
                while (playerDepositMoreMoneyOk == 0)
                {
                    std::cout << "\nIn this game you can bet and win twice as much!\nType in the amount of money that you want to deposit and play with.\nYou cannot deposit more than 5000 SEK in order to play. Integers only.\nType in \"0\" in order to cancel and exit the game.\nType here: ";
                    std::cin >> playerDepositMoreMoneyBalance;
                    if (playerDepositMoreMoneyBalance >= 5000)
                    {
                        std::cout << "\nError. Your deposit can not be above 5000 SEK. Try again.\n";
                    }
                    else if (playerDepositMoreMoneyBalance == 0)
                    {
                        if (playerBalance > 0)
                        {
                            std::cout << "\nYour balance, " << playerBalance << " SEK, will be transferred to you.\nThe game ends.\n";
                            return 0;
                        }
                        else
                        {
                            std::cout << "\nYour balance is empty. No money will be transferred to you.\nThe game ends.\n";
                            return 0;
                        }
                    }
                    else
                    {
                        playerDepositMoreMoneyOk = 1;
                        playerBalance += playerDepositMoreMoneyBalance;
                        std::cout << "\nYour balance has been updated.\nBalance: " << playerBalance << " SEK.\n";
                    }
                }
            }
            else
            {
                std::cout << "\nYou have chosen not to deposit any more money.\nBalance: " << playerBalance << " SEK.\n";
            }
        }

        // Satsning av pengar.
        // Brist: Programmet fungerar inte korrekt ifall anv�ndaren matar in en input som exempelvis den h�r: "777siffrorochsedanbokst�ver".
        while (PlayerBetOk == 0)
        {
            std::cout << "\nType in the amount of money that you want to bet.\nIn order to play you're required to bet 100 SEK, 300 SEK or 500 SEK.\nType \"100\" to bet 100 SEK, \"300\" to bet 300 SEK or \"500\" to bet 500 SEK.\nType in \"0\" in order to cancel, withdraw your money and exit the game.\nType here: ";
            std::cin >> playerBet;

            if (std::cin.fail()) // Kontrollerar s� att anv�ndaren inte har matat in t.ex. en str�ng med bokst�ver eller negativa tal.
            {
                std::cout << "\nError. Try again.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                std::cout << "\nAre you sure?\nType \"1\" (yes) or \"0\" (no).\nType here: ";
                std::cin >> playerBetConfirmed;

                if ((playerBet == 100 || (playerBet == 300 && playerBalance >= 300) || (playerBet == 500 && playerBalance >= 500)) && playerBetConfirmed == 1) // Ifall anv�ndaren satsar 100 SEK, 300 SEK eller 500 SEK och �r s�ker p� sin satsning.
                {
                    std::cout << "\nYou have made a bet of: " << playerBet << " SEK.\n";
                    cpuBet = playerBet;
                    PlayerBetOk = 1;
                }
                else if (playerBet == 0 && playerBetConfirmed == 1) // Ifall anv�ndaren vill avbryta sin satsning och st�nga av spelet.
                {
                    std::cout << "\nYour balance, " << playerBalance << " SEK, will be transferred to you.\nThe game ends.\n";
                    return 0;
                }
                else if (playerBetConfirmed == 0) // Ifall anv�ndaren inte �r s�ker p� sin satsning.
                {
                    PlayerBetOk = 0;
                }
                else // Ifall n�got fel intr�ffar. Exempelvis ifall anv�ndaren f�r f�r sig att skriva in ett negativt belopp.
                {
                    std::cout << "\nError. Try again.\n";
                    PlayerBetOk = 0;
                }
            }
        }

        // Spel.
        // Brist: Programmet fungerar inte korrekt ifall anv�ndaren matar in en input som exempelvis dem h�r: "-100" "777siffrorochsedanbokst�ver".
        while (((playerScore | cpuScore) < 2) && (playerRoundExitConfirmed != 1))
        {
            std::cout << "\nBest of three. In order to win you'll have to win 2 rounds." << "\nDo you want to start round #" << (currentRound + 1) << "?\nType \"1\" (yes) or \"0\" (no).\nType here: ";
            std::cin >> playNextRoundConfirmed;
            if (playNextRoundConfirmed == 0)
            {
                if (std::cin.fail()) // Kontrollerar s� att anv�ndaren inte har matat in en str�ng med bokst�ver.
                {
                    std::cout << "\nError.\nWrong input.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                else
                {
                    std::cout << "\nAre you sure?\nType \"1\" (yes) or \"0\" (no).\nType here: ";
                    std::cin >> playNextRoundConfirmed;
                    if (playNextRoundConfirmed == 1) // Ifall anv�ndaren inte vill spela f�rdigt sin spelomg�ng.
                    {
                        playerRoundExitConfirmed = 1;
                    }
                }
            }
            else // T�rningsspelets start.
            {
                std::cout << "\nGame is starting." << "\nType \"1\" to roll your dices: ";
                std::cin >> playerRollsDice;

                playerDice_1 = rand() % 6 + 1;
                playerDice_2 = rand() % 6 + 1;
                cpuDice_1 = rand() % 6 + 1;
                cpuDice_2 = rand() % 6 + 1;
                std::cout << "\nYou rolled a: " << playerDice_1 << " and a: " << playerDice_2 << "\n" << "The computer rolled a: " << cpuDice_1 << " and a: " << cpuDice_2;
                totalNumberPlayerDice = playerDice_1 + playerDice_2;
                totalNumberCpuDice = cpuDice_1 + cpuDice_2;

                if (totalNumberPlayerDice > totalNumberCpuDice)
                {
                    std::cout << "\nYou won round #" << (currentRound + 1) << "\n";
                    playerScore++;
                }
                else if (totalNumberCpuDice > totalNumberPlayerDice)
                {
                    std::cout << "\nYou lost round #" << (currentRound + 1) << "\n";
                    cpuScore++;
                }
                else if (totalNumberPlayerDice == totalNumberCpuDice)
                {
                    std::cout << "\nTie!\n";
                    roundsPlayed++, currentRound++;
                    continue;
                }
                roundsPlayed++, currentRound++;
            }
        }
        currentRound = 0, currentGame++, gamesPlayed++;

        // Resultat.
        // Brist: Programmet fungerar inte korrekt ifall anv�ndaren matar in fel input.
        std::cout << "\nCurrent game ends.\n";
        if (playerScore == 2) // Ifall anv�ndaren vann spelomg�ngen (b�st av tre rundor).
        {
            gamesWon++;
            playerBalance += cpuBet;
            cpuBalance -= cpuBet;
            prize = playerBet + cpuBet;
            totalWinnings += prize;
            std::cout << "\nCongratulations, you won game #" << currentGame << "!\nYou won: " << prize << " SEK.\nTotal winnings: " << totalWinnings << " SEK.\n";
            std::cout << "\nDo you want to display the complete results?\nType \"1\" (yes) or \"0\" (no).\nType here: ";
            std::cin >> displayResultsConfirmed;
            if (displayResultsConfirmed == 1)
            {
                std::cout << "\nResults:\n\nPlayer score: " << playerScore << "\nComputer score: " << cpuScore << "\nGames Won: " << gamesWon << "\nGames lost: " << gamesLost << "\nGames played: " << gamesPlayed << "\n" << "\nTotal winnings: " << totalWinnings << " SEK.\nYou won: " << prize << " SEK.\nBalance: " << playerBalance << " SEK.\n";
            }
            else
            {
                std::cout << "\nThe complete results will not be shown.\n";
            }
        }
        else if (cpuScore == 2) // Ifall datorn vann spelomg�ngen (b�st av tre rundor).
        {
            gamesLost++;
            playerBalance -= playerBet;
            cpuBalance += playerBet;
            prize = -playerBet - cpuBet;
            totalWinnings += prize;
            std::cout << "\nUnfortunately, you lost game #" << currentGame << "\nYou lost: " << playerBet << " SEK.\nTotal winnings: " << totalWinnings << " SEK.\n";
            std::cout << "\nDo you want to display the complete results?\nType \"1\" (yes) or \"0\" (no).\nType here: ";
            std::cin >> displayResultsConfirmed;
            if (displayResultsConfirmed == 1)
            {
                std::cout << "\nResults:\n\nPlayer score: " << playerScore << "\nComputer score: " << cpuScore << "\nGames Won: " << gamesWon << "\nGames lost: " << gamesLost << "\nGames played: " << gamesPlayed << "\n" << "\nTotal winnings: " << totalWinnings << " SEK.\nYou lost: " << playerBet << " SEK.\nBalance: " << playerBalance << " SEK.\n";
            }
            else
            {
                std::cout << "\nThe complete results will not be shown.\n";
            }
        }

        // Loop som anv�nds f�r att kunna spela mer.
        while (playerExitConfirmed_2 == 0)
        {
            std::cout << "\nDo you want to play again?\nType \"1\" (yes) or \"0\" (no).\nType here: ";
            std::cin >> playOneMoreGame;
            std::cout << "\nAre you sure?\nType \"1\" (yes) or \"0\" (no).\nType here: ";
            std::cin >> playerExitConfirmed_2;
        }
        if (playOneMoreGame == 1)
        {
            playerBalanceOk = 0, playerBalanceConfirmed = 0, playerDepositMoreMoneyConfirmed = 0, playerDepositMoreMoneyBalance = 0,
            playerExitConfirmed_1 = 0, playerBet = 0, cpuBet = 0, PlayerBetOk = 0, playerBetConfirmed = 0, playNextRoundConfirmed = 0,
            currentGame = 0, playerScore = 0, cpuScore = 0, playerRollsDice = 0, playerDice_1 = 0, cpuDice_1 = 0, playerRoundExitConfirmed = 0,
            roundsPlayed = 0, playerExitConfirmed_2 = 0, playerDepositMoreMoneyOk = 0; // Variabler nollst�lls
        }
        else if (playOneMoreGame == 0 && playerBalance > 0)
        {
            std::cout << "\nYour balance, " << playerBalance << " SEK, will be transferred to you.\nThe game ends.\n";
        }
        else if (playOneMoreGame == 0 && playerBalance == 0)
        {
            std::cout << "\nYour balance is empty. No money will be transferred to you.\nThe game ends.\n";
        }

    } while (playOneMoreGame == 1); // Loop som anv�nds f�r att kunna spela mer.
    return 0;
}