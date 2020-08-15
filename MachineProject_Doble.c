/* 	Programmed by: 		Carlos Antonio M. Doble | S16A
	Description: 		This program simulates Lotto 6/42 where in players select
						six (6) numbers from 1 - 42 and are matched with a 
						randomized winning number combination in order to win
						an initial jackpot prize of Php 6,000,000.00. The
						jackpot increases based on nationwide sales until
						a player wins the jackpot.
	Last modified: 		December 3, 2018
	Acknowledgemenets:	https://www.programmingsimplified.com/c/conio.h/getch
						https://mathbits.com/MathBits/CompSci/Screen/clear.htm
						https://stackoverflow.com/questions/23285326/non-repeating-random-number-generator-in-c
						nttps://patorjk.com/software/taag/
*/


#include <stdio.h>
#include <stdlib.h> // Used to initiate random, srand, and system("cls")
#include <time.h> // Used to define time to be used for random and srand
/*
	This function gets the system time and uses it to generate a set of random numbers.
*/
void 
initRandom () 
{
		time_t random_seed;
		random_seed = time(NULL);
		srand(random_seed);
}

/*
	This function generates a random number from a given range.
*/
int 
getRandomNum (int low, 
				int high)
{
		int randomValue;
		randomValue = low + rand() % (high - low + 1);
		return randomValue;
}

/*	This function runs the Regular Play option of Lotto 6/42 where in the player inputs
	6 unique numbers from 1 - 42 and are matched with a randomized winning combination.
	The user wins the jackpot if all 6 numbers match the randomized winning combination.
	@param 	(long long int) jackpot is the current jackpot
	@return (void) 			no return value
*/
/*
	TEST CASES:
	TEST CASE1 (Inputted lotto numbers from 1-42 with no correctly matched numbers):
					Input: 
							Select an option: 1
							Input your Lotto numbers: 1 2 3 4 5 6
					Expected Output:
							Ticket Price: Php 24.00
							Current jackpot: Php 6000000
							Press any key to return to reveal the winning numbers!
							The Winning Numbers are: 40 28 26 16 30 34
							Sorry! You got no numbers correct! Better luck next time!
							New Jackpot: Php 6600000
							Back to Main Menu? (1: Yes | 2: Exit):
	TEST CASE2: (Inputted lotto numbers from 1-42, with correctly matched number/s):
					Input: 
							Select an option: 1
							Input your Lotto numbers: 1 2 3 4 5 6
					Expected Output:
							Ticket Price: Php 24.00
							Current jackpot: Php 6000000
							Press any key to return to reveal the winning numbers!
							The Winning Numbers are: 22 33 41 11 28 4
							You got 1 correct number!
							Sorry! You didn't win anything! Better luck next time!
							New Jackpot: Php 6600000
							Back to Main Menu? (1: Yes | 2: Exit):
	TEST CASE3: (Inputted a negative number):
					Input: 
							Select an option: 1
							Input your Lotto numbers: 1 2 3 4 5 -6
					Expected Output:
							Please input different positive numbers from 1 - 42	
							Press any key to return to the main menu
	TEST CASE4: (Inputted a number greater than 42):
					Input: 
							Select an option: 1
							Input your Lotto numbers: 1 2 3 4 5 43
					Expected Output:
							Please input different positive numbers from 1 - 42	
							Press any key to return to the main menu					
							
*/
int 
lottoFunc (long long jackpot)
{
		initRandom();
		int lottoNum[6];
		int lottoWin[6];
		int winnings = 0;
		int* autowin;
		int i = 0, mm, x;
		long long newjackpot = jackpot;
		printf("\nInput your Lotto numbers: ");
	
		for (i==0; i<6; i++)
				scanf("%d", &lottoNum[i]);
	
		if (lottoNum[0] == lottoNum[1] || 
			lottoNum[0] == lottoNum[2] || 
			lottoNum[0] == lottoNum[3] || 
			lottoNum[0] == lottoNum[4] || 
			lottoNum[0] == lottoNum[5] || 
			lottoNum[1] == lottoNum[2] || 
			lottoNum[1] == lottoNum[3] || 
			lottoNum[1] == lottoNum[4] || 
			lottoNum[1] == lottoNum[5] || 
			lottoNum[2] == lottoNum[3] || 
			lottoNum[2] == lottoNum[4] || 
			lottoNum[2] == lottoNum[5] || 
			lottoNum[3] == lottoNum[4] || 
			lottoNum[3] == lottoNum[5] || 
			lottoNum[4] == lottoNum[5] ||
			lottoNum[0] < 1 || 
			lottoNum[1] < 1 || 
			lottoNum[2] < 1 || 
			lottoNum[3] < 1 || 
			lottoNum[4] < 1 || 
			lottoNum[5] < 1 ||
			lottoNum[0] > 42 ||
			lottoNum[1] > 42 ||
			lottoNum[2] > 42 ||
			lottoNum[3] > 42 ||
			lottoNum[4] > 42 ||
			lottoNum[5] > 42) {
					printf("Please input different positive numbers from 1 to 42\n");
					printf("\nPress any key to return to the main menu . . .\n");
					getch();
					system("cls");
					return main();
		}
	
		printf("Your inputted numbers are: ");
	
		i = 0;
	
		for (i==0; i<6; i++)
				printf("%d ", lottoNum[i]);
	
		printf("\nTicket Price: Php 24.00\nCurrent jackpot: Php %lli\n", newjackpot);
	
		i = 0;
	
		while(i < 6){
				int r = getRandomNum(1, 42);
		
				for(x = 0; x < i; x++) {
						if(lottoWin[x] == r)
								break;
				}
		
				if(x == i){
						lottoWin[i++] = r;
				}
		}
	
		printf("\nPress any key to return to reveal the winning numbers!\n\n");
	
		getch();
	
		printf("The Winning Numbers are: ");
	
		i = 0;
	
		for (i==0; i<6; i++)
				printf("%d ", lottoWin[i]);
	
		if(lottoNum[0] == lottoWin[0] || 
			lottoNum[0] == lottoWin[1] || 
			lottoNum[0] == lottoWin[2] || 
			lottoNum[0] == lottoWin[3] || 
			lottoNum[0] == lottoWin[4] || 
			lottoNum[0] == lottoWin[5])
				winnings += 1;
	
		if(lottoNum[1] == lottoWin[0] || 
			lottoNum[1] == lottoWin[1] || 
			lottoNum[1] == lottoWin[2] || 
			lottoNum[1] == lottoWin[3] || 
			lottoNum[1] == lottoWin[4] || 
			lottoNum[1] == lottoWin[5])
				winnings += 1;
	
		if(lottoNum[2] == lottoWin[0] || 
			lottoNum[2] == lottoWin[1] || 
			lottoNum[2] == lottoWin[2] || 
			lottoNum[2] == lottoWin[3] || 
			lottoNum[2] == lottoWin[4] || 
			lottoNum[2] == lottoWin[5])
				winnings += 1;
	
		if(lottoNum[3] == lottoWin[0] || 
			lottoNum[3] == lottoWin[1] || 
			lottoNum[3] == lottoWin[2] || 
			lottoNum[3] == lottoWin[3] || 
			lottoNum[3] == lottoWin[4] || 
			lottoNum[3] == lottoWin[5])
				winnings += 1;
	
		if(lottoNum[4] == lottoWin[0] || 
			lottoNum[4] == lottoWin[1] || 
			lottoNum[4] == lottoWin[2] || 
			lottoNum[4] == lottoWin[3] || 
			lottoNum[4] == lottoWin[4] || 
			lottoNum[4] == lottoWin[5])
				winnings += 1;
	
		if(lottoNum[5] == lottoWin[0] || 
			lottoNum[5] == lottoWin[1] || 
			lottoNum[5] == lottoWin[2] || 
			lottoNum[5] == lottoWin[3] || 
			lottoNum[5] == lottoWin[4] || 
			lottoNum[5] == lottoWin[5])
				winnings += 1;
	
		if (winnings == 0) {
				printf("\nSorry! You got no numbers correct! Better luck next time!\n");
				newjackpot = newjackpot + (newjackpot * .10);
		}
	
		else if (winnings == 1) {
				printf("\nYou got 1 correct number!\n", winnings);
				printf("Sorry! You didn't win anything! Better luck next time!\n");
				newjackpot = newjackpot + (newjackpot * .10);
		}
	
		else if (winnings == 2) {
				printf("\nYou got 2 correct numbers!\n");
				printf("Sorry! You didn't win anything! Better luck next time!\n");
				newjackpot = newjackpot + (newjackpot * .10);
		}
	
		else if (winnings == 3) {
				printf("\nYou got 3 correct numbers!\n");
				printf("Congratulations! you won Php 20.00!");
				newjackpot = newjackpot + (newjackpot * .10);
		}
		
		else if (winnings == 4) {
				printf("\nYou got 4 correct numbers!\n");
				printf("Congratulations! you won Php 1000.00!");
				newjackpot = newjackpot + (newjackpot * .10);
		}
		
		else if (winnings == 5) {
				printf("\nYou got 5 correct numbers!\n");
				printf("Congratulations! you won Php 25000.00!");
				newjackpot = newjackpot + (newjackpot * .10);
		}
		
		else if (winnings == 6){
				printf("\nYou got 6 correct numbers!\n");
				printf("Congratulations! You won THE JACKPOT!!");
				newjackpot = 6000000;
		}
	
		printf("\nNew Jackpot: %lli", newjackpot);
	
		returnMenu(newjackpot);
}

/*	This function runs the Regular Play option of Lotto 6/42 but simulates a scenario 
	where in the player wins the jackpot.
	@param (long long int) jackpot is the current jackpot
	@return (void) no return value
*/
/*
	TEST CASES:
	TEST CASE1 (Inputted lotto numbers from 1-42):
					Input: 
							Select an option: 1
							Input your Lotto numbers: 1 2 3 4 5 6
					Expected Output:
							Ticket Price: Php 24.00
							Current jackpot: Php 6000000
							Press any key to return to reveal the winning numbers!
							The Winning Numbers are: 1 2 3 4 5 6
							Ypu got 6 correct numbers!
							Congratulations! You won the JACKPOT!!
							New Jackpot: Php 6000000
							Back to Main Menu? (1: Yes | 2: Exit):
	TEST CASE2: (Inputted a negative number):
					Input: 
							Select an option: 1
							Input your Lotto numbers: 1 2 3 4 5 -6
					Expected Output:
							Please input different positive numbers from 1 - 42	
							Press any key to return to the main menu
	TEST CASE4: (Inputted a number greater than 42):
					Input: 
							Select an option: 1
							Input your Lotto numbers: 1 2 3 4 5 43
					Expected Output:
							Please input different positive numbers from 1 - 42	
							Press any key to return to the main menu					
							
*/
int 
lottoAuto(long long jackpot)
{
		int lottoNum[6];
		int lottoWin[6];
		int winnings = 0;
		int i = 0, mm, x;
		long long newjackpot = jackpot;
		printf("\nInput your Lotto numbers: ");
	
		for (i==0; i<6; i++)
				scanf("%d", &lottoNum[i]);
	
		if (lottoNum[0] == lottoNum[1] || 
			lottoNum[0] == lottoNum[2] || 
			lottoNum[0] == lottoNum[3] || 
			lottoNum[0] == lottoNum[4] || 
			lottoNum[0] == lottoNum[5] || 
			lottoNum[1] == lottoNum[2] || 
			lottoNum[1] == lottoNum[3] || 
			lottoNum[1] == lottoNum[4] || 
			lottoNum[1] == lottoNum[5] || 
			lottoNum[2] == lottoNum[3] || 
			lottoNum[2] == lottoNum[4] || 
			lottoNum[2] == lottoNum[5] || 
			lottoNum[3] == lottoNum[4] || 
			lottoNum[3] == lottoNum[5] || 
			lottoNum[4] == lottoNum[5] ||
			lottoNum[0] < 1 || 
			lottoNum[1] < 1 || 
			lottoNum[2] < 1 || 
			lottoNum[3] < 1 || 
			lottoNum[4] < 1 || 
			lottoNum[5] < 1 ||
			lottoNum[0] > 42 ||
			lottoNum[1] > 42 ||
			lottoNum[2] > 42 ||
			lottoNum[3] > 42 ||
			lottoNum[4] > 42 ||
			lottoNum[5] > 42) {
				printf("Please input different positive numbers from 1 - 42	\n");
				printf("\nPress any key to return to the main menu . . .\n");
				getch();
				system("cls");
				return main();
		}
	
		printf("Your inputted numbers are: ");

		i = 0;
	
		for (i==0; i<6; i++)
				printf("%d ", lottoNum[i]);
		
		printf("\nTicket Price: Php 24.00\nCurrent jackpot: Php %lli\n", newjackpot);
		
		printf("\nPress any key to reveal the winning numbers...\n\n");
		
		getch();
	
		lottoWin[0] = lottoNum[0];
		lottoWin[1] = lottoNum[1];
		lottoWin[2] = lottoNum[2];
		lottoWin[3] = lottoNum[3];
		lottoWin[4] = lottoNum[4];
		lottoWin[5] = lottoNum[5];
	
		printf("\nThe Winning Numbers are: ");
	
		printf("%d %d %d %d %d %d\n", lottoWin[0], lottoWin[1], lottoWin[2], lottoWin[3], lottoWin[4], lottoWin[5] );
	
		if(lottoNum[0] == lottoWin[0] || 
			lottoNum[0] == lottoWin[1] || 
			lottoNum[0] == lottoWin[2] || 
			lottoNum[0] == lottoWin[3] || 
			lottoNum[0] == lottoWin[4] || 
			lottoNum[0] == lottoWin[5])
				winnings += 1;
	
		if(lottoNum[1] == lottoWin[0] || 
			lottoNum[1] == lottoWin[1] || 
			lottoNum[1] == lottoWin[2] || 
			lottoNum[1] == lottoWin[3] || 
			lottoNum[1] == lottoWin[4] || 
			lottoNum[1] == lottoWin[5])
				winnings += 1;
	
		if(lottoNum[2] == lottoWin[0] || 
			lottoNum[2] == lottoWin[1] || 
			lottoNum[2] == lottoWin[2] || 
			lottoNum[2] == lottoWin[3] || 
			lottoNum[2] == lottoWin[4] || 
			lottoNum[2] == lottoWin[5])
				winnings += 1;
	
		if(lottoNum[3] == lottoWin[0] || 
			lottoNum[3] == lottoWin[1] || 
			lottoNum[3] == lottoWin[2] || 
			lottoNum[3] == lottoWin[3] || 
			lottoNum[3] == lottoWin[4] || 
			lottoNum[3] == lottoWin[5])
				winnings += 1;
	
		if(lottoNum[4] == lottoWin[0] || 
			lottoNum[4] == lottoWin[1] || 
			lottoNum[4] == lottoWin[2] || 
			lottoNum[4] == lottoWin[3] || 
			lottoNum[4] == lottoWin[4] || 
			lottoNum[4] == lottoWin[5])
				winnings += 1;
	
		if(lottoNum[5] == lottoWin[0] || 
			lottoNum[5] == lottoWin[1] || 
			lottoNum[5] == lottoWin[2] || 
			lottoNum[5] == lottoWin[3] || 
			lottoNum[5] == lottoWin[4] || 
			lottoNum[5] == lottoWin[5])
				winnings += 1;
	
		if (winnings == 0){
				printf("\nSorry! You got no numbers correct! Better luck next time!\n");
				newjackpot = newjackpot + (newjackpot * .10);
		}
	
		else if (winnings == 1){
				printf("You got 1 correct number!\n");
				printf("Sorry! You didn't win anything! Better luck next time!\n");
				newjackpot = newjackpot + (newjackpot * .10);
		}
	
		else if (winnings == 2){
				printf("You got 2 correct numbers!\n");
				printf("Sorry! You didn't win anything! Better luck next time!\n");
				newjackpot = newjackpot + (newjackpot * .10);
		}
	
		else if (winnings == 3){
				printf("You got 3 correct numbers!\n");
				printf("Congratulations! you won Php 20.00!");
				newjackpot = newjackpot + (newjackpot * .10);
		}
	
		else if (winnings == 4){
				printf("You got 4 correct numbers!\n");
				printf("Congratulations! you won Php 1000.00!");
				newjackpot = newjackpot + (newjackpot * .10);
		}
		
		else if (winnings == 5){
			printf("You got 5 correct numbers!\n");
			printf("Congratulations! you won Php 25000.00!");
			newjackpot = newjackpot + (newjackpot * .10);		
		}
		
		else if (winnings == 6){
			printf("You got 6 correct numbers!\n");
			printf("Congratulations! You won THE JACKPOT!!");
			newjackpot = 6000000;
		}
	
		printf("\nNew Jackpot: %lli", newjackpot);
		returnMenu(newjackpot);
}

/*
	This function runs the Lucky Pick option of Lotto 6/42 where in the player is given
	6 randomized unique numbers froom 1 - 42 and are matched with a randomized winning 
	combination. The user wins the jackpot if all 6 numbers match the randomized 
	winning combination.
	@param	(long long int) jackpot is the current jackpot
	@return (void)			no return value
*/
/*
	TEST CASE:
							Select an option: 2
							Your Lotto numbers are: 23 42 5 31 13 35
							Ticket Price: Php 24.00
							Current jackpot: Php 6000000
							Press any key to return to reveal the winning numbers!
							The Winning Numbers are: 12 14 19 39 16 41
							Sorry! You got no numbers correct! Better luck next time!
							New Jackpot: 6600000
							Back to Main Menu? (1: Yes | 2: Exit):
*/
int 
lottoLucky (long long jackpot)
{
		initRandom();
		int lottoNum[6];
		int lottoWin[6];
		int winnings = 0;
		int i = 0, mm, x;
		long long newjackpot = jackpot;
	
		while(i < 6){
				int r = getRandomNum(1, 42);
		
				for(x = 0; x < i; x++) {
						if(lottoNum[x] == r)
								break;
				}
		
				if(x == i){
						lottoNum[i++] = r;
				}
		}
	
		printf("Your Lotto numbers are: ");
	
		for (i=0; i<6; i++)
				printf("%d ", lottoNum[i]);
	
		printf("\nTicket Price: Php 24.00\nCurrent jackpot: Php %lli\n", newjackpot);
	
		i = 0;
	
		while(i < 6){
				int r = getRandomNum(1, 42);
		
				for(x = 0; x < i; x++)
						if(lottoWin[x] == r)
								break;
				if(x == i)
						lottoWin[i++] = r;
				
		}
	
		printf("\nPress any key to return to reveal the winning numbers!\n\n");
	
		getch();
	
		printf("The Winning Numbers are: ");
	
		for (i=0; i<6; i++)
				printf("%d ", lottoWin[i]);
	
		if(lottoNum[0] == lottoWin[0] || 
			lottoNum[0] == lottoWin[1] || 
			lottoNum[0] == lottoWin[2] || 
			lottoNum[0] == lottoWin[3] || 
			lottoNum[0] == lottoWin[4] || 
			lottoNum[0] == lottoWin[5])
				winnings += 1;
	
		if(lottoNum[1] == lottoWin[0] || 
			lottoNum[1] == lottoWin[1] || 
			lottoNum[1] == lottoWin[2] || 
			lottoNum[1] == lottoWin[3] || 
			lottoNum[1] == lottoWin[4] || 
			lottoNum[1] == lottoWin[5])
				winnings += 1;
	
		if(lottoNum[2] == lottoWin[0] || 
			lottoNum[2] == lottoWin[1] || 
			lottoNum[2] == lottoWin[2] || 
			lottoNum[2] == lottoWin[3] || 
			lottoNum[2] == lottoWin[4] || 
			lottoNum[2] == lottoWin[5])
				winnings += 1;
	
		if(lottoNum[3] == lottoWin[0] || 
			lottoNum[3] == lottoWin[1] || 
			lottoNum[3] == lottoWin[2] || 
			lottoNum[3] == lottoWin[3] || 
			lottoNum[3] == lottoWin[4] || 
			lottoNum[3] == lottoWin[5])
				winnings += 1;
	
		if(lottoNum[4] == lottoWin[0] || 
			lottoNum[4] == lottoWin[1] || 
			lottoNum[4] == lottoWin[2] || 
			lottoNum[4] == lottoWin[3] || 
			lottoNum[4] == lottoWin[4] || 
			lottoNum[4] == lottoWin[5])
				winnings += 1;
	
		if(lottoNum[5] == lottoWin[0] || 
			lottoNum[5] == lottoWin[1] || 
			lottoNum[5] == lottoWin[2] || 
			lottoNum[5] == lottoWin[3] || 
			lottoNum[5] == lottoWin[4] || 
			lottoNum[5] == lottoWin[5])
				winnings += 1;
	
		if (winnings == 0){
				printf("\nSorry! You got no numbers correct! Better luck next time!\n");
				newjackpot = newjackpot + (newjackpot * .10);
		}
	
		else if (winnings == 1){
			printf("\nYou got 1 correct number!\n", winnings);
			printf("Sorry! You didn't win anything! Better luck next time!\n");
			newjackpot = newjackpot + (newjackpot * .10);
		}
	
		else if (winnings == 2){
			printf("\nYou got 2 correct numbers!\n");
			printf("Sorry! You didn't win anything! Better luck next time!\n");
			newjackpot = newjackpot + (newjackpot * .10);
		}
	
		else if (winnings == 3){
			printf("\nYou got 3 correct numbers!\n");
			printf("Congratulations! you won Php 20.00!");
			newjackpot = newjackpot + (newjackpot * .10);
		}
		
		else if (winnings == 4){
			printf("\nYou got 4 correct numbers!\n");
			printf("Congratulations! you won Php 1000.00!");
			newjackpot = newjackpot + (newjackpot * .10);
		}
		
		else if (winnings == 5){
			printf("\nYou got 5 correct numbers!\n");
			printf("Congratulations! you won Php 25000.00!");
			newjackpot = newjackpot + (newjackpot * .10);
		}
		
		else if (winnings == 6){
			printf("\nYou got 6 correct numbers!\n");
			printf("Congratulations! You won THE JACKPOT!!");
			newjackpot = 6000000;
		}
	
		printf("\nNew Jackpot: %lli", newjackpot);
	
		returnMenu(newjackpot);
}

/*
	This function runs the Five System option of Lotto 6/42 where in the player chooses
	5 unique numbers from 1 - 42 and are matched with a randomized winning combination.
	Since the player only has 5 numbers, 1 number from the randomized winning
	combination is automatically matched.
	@param 	(long long int) jackpot is the current jackpot
	@return (void)			no return value	
*/	
/*
	TEST CASES:
	TEST CASE1 (Inputted lotto numbers from 1-42):
					Input: 
							Select an option: 1
							Input your Lotto numbers: 1 2 3 4 5
					Expected Output:
							Ticket Price: Php 888.00
							Current jackpot: Php 6000000
							Press any key to return to reveal the winning numbers!
							The Winning Numbers are: 7 8 9 10 11 12
							Ypu got 1 correct number!
							Sorry! You didn't win anything! Better luck next time!
							New Jackpot: Php 6600000
							Back to Main Menu? (1: Yes | 2: Exit):
	TEST CASE2: (Inputted lotto numbers from 1-42, with correctly matched number/s):
					Input: 
							Select an option: 1
							Input your Lotto numbers: 1 2 3 4 5 
					Expected Output:
							Ticket Price: Php 888.00
							Current jackpot: Php 6000000
							Press any key to return to reveal the winning numbers!
							The Winning Numbers are: 22 33 41 11 28 4
							You got 2 correct numbers!
							Sorry! You didn't win anything! Better luck next time!
							New Jackpot: Php 6600000
							Back to Main Menu? (1: Yes | 2: Exit):
	TEST CASE2: (Inputted a negative number):
					Input: 
							Select an option: 1
							Input your Lotto numbers: 1 2 3 4 -5
					Expected Output:
							Please input different positive numbers from 1 - 42	
							Press any key to return to the main menu
	TEST CASE4: (Inputted a number greater than 42):
					Input: 
							Select an option: 1
							Input your Lotto numbers: 1 2 3 4 43
					Expected Output:
							Please input different positive numbers from 1 - 42	
							Press any key to return to the main menu					
							
*/
int 
fiveRoll(long long jackpot)
{
		initRandom();
		int lottoNum[5];
		int lottoWin[6];
		int winnings = 1;
		int i = 0, mm, x;
		long long newjackpot = jackpot;
		
		printf("\nInput your Lotto numbers: ");
	
		for (i==0; i<5; i++)
				scanf("%d", &lottoNum[i]);
	
		if(lottoNum[0] == lottoNum[1] || 
			lottoNum[0] == lottoNum[2] || 
			lottoNum[0] == lottoNum[3] || 
			lottoNum[0] == lottoNum[4] || 
			lottoNum[1] == lottoNum[2] || 
			lottoNum[1] == lottoNum[3] || 
			lottoNum[1] == lottoNum[4] || 
			lottoNum[2] == lottoNum[3] || 
			lottoNum[2] == lottoNum[4] || 
			lottoNum[3] == lottoNum[4] || 
			lottoNum[0] < 1 || 
			lottoNum[1] < 1 || 
			lottoNum[2] < 1 || 
			lottoNum[3] < 1 || 
			lottoNum[4] < 1){
				printf("Please input different positive numbers\n");
				printf("\nPress any key to return to the main menu . . .\n");
				getch();
				system("cls");
				return main();
		}
	
		printf("Your inputted numbers are: ");
	
		for(i=0; i<5; i++)
				printf("%d ", lottoNum[i]);
	
		printf("\nTicket Price: Php888.00\nCurrent jackpot: Php %lli\n", newjackpot);
	
		i = 0;
	
		while(i < 6){
				int r = getRandomNum(1, 42);
		
				for(x = 0; x < i; x++) {
						if(lottoWin[x] == r)
								break;
				}
		
				if(x == i){
						lottoWin[i++] = r;
				}
		}
	
		printf("\nPress any key to return to reveal the winning numbers!\n\n");
	
		getch();
	
		printf("The Winning Numbers are: ");
	
		for (i=0; i<6; i++)
				printf("%d ", lottoWin[i]);
	
		if(lottoNum[0] == lottoWin[0] || 
			lottoNum[0] == lottoWin[1] || 
			lottoNum[0] == lottoWin[2] || 
			lottoNum[0] == lottoWin[3] || 
			lottoNum[0] == lottoWin[4] )
				winnings += 1;
	
		if(lottoNum[1] == lottoWin[0] || 
			lottoNum[1] == lottoWin[1] || 
			lottoNum[1] == lottoWin[2] || 
			lottoNum[1] == lottoWin[3] || 
			lottoNum[1] == lottoWin[4] )
				winnings += 1;
	
		if(lottoNum[2] == lottoWin[0] || 
			lottoNum[2] == lottoWin[1] || 
			lottoNum[2] == lottoWin[2] || 
			lottoNum[2] == lottoWin[3] || 
			lottoNum[2] == lottoWin[4] )
				winnings += 1;
				
		if(lottoNum[3] == lottoWin[0] || 
			lottoNum[3] == lottoWin[1] || 
			lottoNum[3] == lottoWin[2] || 
			lottoNum[3] == lottoWin[3] || 
			lottoNum[3] == lottoWin[4] )
				winnings += 1;
	
		if(lottoNum[4] == lottoWin[0] || 
			lottoNum[4] == lottoWin[1] || 
			lottoNum[4] == lottoWin[2] || 
			lottoNum[4] == lottoWin[3] || 
			lottoNum[4] == lottoWin[4] )
				winnings += 1;
		
		if(winnings == 1){
				printf("\nYou got 1 correct number!\n", winnings);
				printf("Sorry! You didn't win anything! Better luck next time!\n");
				newjackpot = newjackpot + (newjackpot * .10);
		}
	
		else if(winnings == 2){
				printf("\nYou got 2 correct numbers!\n");
				printf("Sorry! You didn't win anything! Better luck next time!\n");
				newjackpot = newjackpot + (newjackpot * .10);
		}
	
		else if(winnings == 3){
				printf("You got 3 correct numbers!\n");
				printf("Congratulations! you won Php 20.00!");
				newjackpot = newjackpot + (newjackpot * .10);
		}
	
		else if(winnings == 4){
				printf("You got 4 correct numbers!\n");
				printf("Congratulations! you won Php 1000.00!");
				newjackpot = newjackpot + (newjackpot * .10);
		}
	
		else if(winnings == 5){
				printf("You got 5 correct numbers!\n");
				printf("Congratulations! you won Php 25000.00!");
				newjackpot = newjackpot + (newjackpot * .10);
		}
	
		else if(winnings == 6){
				printf("You got 6 correct numbers!\n");
				printf("Congratulations! You won THE JACKPOT!!");
				newjackpot = 6000000;
		}
	
		printf("\nNew Jackpot: %lli", newjackpot);
	
		returnMenu(newjackpot);
}

/*
	This function runs the Seven Sytem option of Lotto 6/42 where in the player chooses
	7 unique numbers from 1 - 42 and are matchedd with a randomized winning combination.
	Since the player has 7 numbers instead of 6, the player has a higher chance of
	winning the jackpot,
	@param  (long long int) jackpot is the current jackpot
	@return (void) 			no return value
*/
/*
	TEST CASES:
	TEST CASE1 (Inputted lotto numbers from 1-42):
					Input: 
							Select an option: 1
							Input your Lotto numbers: 1 2 3 4 5 6 7
					Expected Output:
							Ticket Price: Php 168.00
							Current jackpot: Php 6000000
							Press any key to return to reveal the winning numbers!
							The Winning Numbers are: 7 8 9 10 11 12
							Ypu got 1 correct number!
							Sorry! You didn't win anything! Better luck next time!
							New Jackpot: Php 6600000
							Back to Main Menu? (1: Yes | 2: Exit):
	TEST CASE2: (Inputted lotto numbers from 1-42, with correctly matched number/s):
					Input: 
							Select an option: 1
							Input your Lotto numbers: 1 2 3 4 5 6 7
					Expected Output:
							Ticket Price: Php 168.00
							Current jackpot: Php 6000000
							Press any key to return to reveal the winning numbers!
							The Winning Numbers are: 22 33 41 5 28 4
							You got 2 correct numbers!
							Sorry! You didn't win anything! Better luck next time!
							New Jackpot: Php 6600000
							Back to Main Menu? (1: Yes | 2: Exit):
	TEST CASE2: (Inputted a negative number):
					Input: 
							Select an option: 1
							Input your Lotto numbers: 1 2 3 4 -5 6 7
					Expected Output:
							Please input different positive numbers from 1 - 42	
							Press any key to return to the main menu
	TEST CASE4: (Inputted a number greater than 42):
					Input: 
							Select an option: 1
							Input your Lotto numbers: 1 2 3 4 43 6 7
					Expected Output:
							Please input different positive numbers from 1 - 42	
							Press any key to return to the main menu					
							
*/
int 
sevenSystem(long long jackpot)
{
		initRandom();
		int lottoNum[7];
		int lottoWin[6];
		int winnings = 0;
		int i = 0, x;
		long long newjackpot = jackpot;
		
		printf("\nInput your Lotto numbers: ");
	
		for(i==0; i<7; i++)
				scanf("%d", &lottoNum[i]);
	
		if(lottoNum[0] == lottoNum[1] || 
			lottoNum[0] == lottoNum[2] || 
			lottoNum[0] == lottoNum[3] || 
			lottoNum[0] == lottoNum[4] || 
			lottoNum[0] == lottoNum[5] || 
			lottoNum[1] == lottoNum[2] || 
			lottoNum[1] == lottoNum[3] || 
			lottoNum[1] == lottoNum[4] || 
			lottoNum[1] == lottoNum[5] || 
			lottoNum[2] == lottoNum[3] || 
			lottoNum[2] == lottoNum[4] || 
			lottoNum[2] == lottoNum[5] || 
			lottoNum[3] == lottoNum[4] || 
			lottoNum[3] == lottoNum[5] || 
			lottoNum[4] == lottoNum[5] || 
			lottoNum[6] == lottoNum[0] || 
			lottoNum[6] == lottoNum[1] || 
			lottoNum[6] == lottoNum[2] || 
			lottoNum[6] == lottoNum[3] || 
			lottoNum[6] == lottoNum[4] ||
			lottoNum[6] == lottoNum[5] || 
			lottoNum[0] < 1 || 
			lottoNum[1] < 1 || 
			lottoNum[2] < 1 || 
			lottoNum[3] < 1 || 
			lottoNum[4] < 1 || 
			lottoNum[5] < 1 || 
			lottoNum[6] < 1){
				printf("Please input different positive numbers\n");
				printf("\nPress any key to return to the main menu . . .\n");
				getch();
				system("cls");
				return main();
		}
	
		printf("Your inputted numbers are: ");
	
		for(i=0; i<7; i++)
				printf("%d ", lottoNum[i]);
	
		printf("\nTicket Price: Php 168.00\nCurrent jackpot: Php %lli\n", newjackpot);
	
		i = 0;
	
		while(i < 6){
				int r = getRandomNum(1, 42);
				for(x = 0; x < i; x++){
						if(lottoWin[x] == r)
								break;
				}
		
				if(x == i){
						lottoWin[i++] = r;
				}
		}
	
		printf("\nPress any key to return to reveal the winning numbers!\n\n");
		
		getch();
	
		printf("The Winning Numbers are: ");
	
		for(i=0; i<6; i++)
				printf("%d ", lottoWin[i]);
	
		if(lottoNum[0] == lottoWin[0] || 
			lottoNum[0] == lottoWin[1] || 
			lottoNum[0] == lottoWin[2] || 
			lottoNum[0] == lottoWin[3] || 
			lottoNum[0] == lottoWin[4] ||
			lottoNum[0] == lottoWin[5])
				winnings += 1;
	
		if(lottoNum[1] == lottoWin[0] || 
			lottoNum[1] == lottoWin[1] ||
			lottoNum[1] == lottoWin[2] || 
			lottoNum[1] == lottoWin[3] || 
			lottoNum[1] == lottoWin[4] || 
			lottoNum[1] == lottoWin[5])
				winnings += 1;
	
		if(lottoNum[2] == lottoWin[0] || 
			lottoNum[2] == lottoWin[1] || 
			lottoNum[2] == lottoWin[2] || 
			lottoNum[2] == lottoWin[3] || 
			lottoNum[2] == lottoWin[4] || 
			lottoNum[2] == lottoWin[5])
				winnings += 1;
	
		if(lottoNum[3] == lottoWin[0] || 
			lottoNum[3] == lottoWin[1] || 
			lottoNum[3] == lottoWin[2] || 
			lottoNum[3] == lottoWin[3] || 
			lottoNum[3] == lottoWin[4] || 
			lottoNum[3] == lottoWin[5])
				winnings += 1;
	
		if(lottoNum[4] == lottoWin[0] || 
			lottoNum[4] == lottoWin[1] || 
			lottoNum[4] == lottoWin[2] || 
			lottoNum[4] == lottoWin[3] || 
			lottoNum[4] == lottoWin[4] || 
			lottoNum[4] == lottoWin[5])
				winnings += 1;
	
		if(lottoNum[5] == lottoWin[0] || 
			lottoNum[5] == lottoWin[1] || 
			lottoNum[5] == lottoWin[2] || 
			lottoNum[5] == lottoWin[3] || 
			lottoNum[5] == lottoWin[4] || 
			lottoNum[5] == lottoWin[5])
				winnings += 1;
	
		if(lottoNum[6] == lottoWin[0] || 
			lottoNum[6] == lottoWin[1] || 
			lottoNum[6] == lottoWin[2] || 
			lottoNum[6] == lottoWin[3] || 
			lottoNum[6] == lottoWin[4] || 
			lottoNum[6] == lottoWin[5])
				winnings += 1;
	
		if(winnings == 0){
				printf("\nSorry! You got no numbers correct! Better luck next time!\n");
				newjackpot = newjackpot + (newjackpot * .10);
		}
	
		else if(winnings == 1){
				printf("\nYou got 1 correct numbers!\n", winnings);
				printf("Sorry! You didn't win anything! Better luck next time!\n");
				newjackpot = newjackpot + (newjackpot * .10);
		}
	
		else if(winnings == 2){
				printf("\nYou got 2 correct numbers!\n");
				printf("Sorry! You didn't win anything! Better luck next time!\n");
				newjackpot = newjackpot + (newjackpot * .10);
		}
	
		else if(winnings == 3){
				printf("\nYou got 3 correct numbers!\n");
				printf("Congratulations! you won Php 20.00!");
				newjackpot = newjackpot + (newjackpot * .10);
		}
		
		else if (winnings == 4){
			printf("\nYou got 3 correct numbers!\n");
			printf("Congratulations! you won Php 1000.00!");
			newjackpot = newjackpot + (newjackpot * .10);
		}
		
		else if (winnings == 5){
			printf("\nYou got 3 correct numbers!\n");
			printf("Congratulations! you won Php 25000.00!");
			newjackpot = newjackpot + (newjackpot * .10);
		}
		
		else if (winnings == 6){
			printf("\nYou got 6 correct numbers!\n");
			printf("Congratulations! You won THE JACKPOT!!");
			newjackpot = 6000000;
		}
	
		printf("\nNew Jackpot: %lli", newjackpot);
	
		returnMenu(newjackpot);
}

/*
	This function is displayed every end of a Lotto 6/42 option. The function asks
	the player if he/she wants to go back to the Main Menu. If Yes, the player
	returns to the Main Menu. If No, the program ends.
	@param 	(long long int) jackpot is the current jackpot
	@return (int) 			returns either 0 or the function MainMenu
*/
int 
returnMenu(long long jackpot)
{
		long long newjackpot = jackpot;
		int mm;
		while (mm != 1 || 
				mm !=2){
				printf("\nBack to Main Menu? (1: Yes | 2: Exit): ");
				scanf("%d", &mm);
		
				if (mm == 1){
						system("cls"); /*Clears Command Console*/
						return MainMenu(newjackpot);
				}
				else if (mm == 2){
						printf("THANK YOU FOR PLAYING!");
						return 0;
				}
				else
						printf("Invalid number\n");
		}
}

/*
	This function displays the Main Menu of the program. The user is given
	6 choices. The first choice is Regular Play which runs the function
	lottoFunc. The second choice is Lucky Pick which runs the function
	lottoLucky. The third choice is 5 - Roll which runs the function
	fiveRoll. The fourth choice is 7 System which runs the function
	sevenSystem. The fifth choice is Auto-Win which runs the function
	lottoAuto. The last choice exits the program.
*/
int 
MainMenu(long long jackpot)
{
		long long newjackpot = jackpot;
		printf(" /$$        /$$$$$$  /$$$$$$$$ /$$$$$$$$  /$$$$$$   \n");
		printf("| $$       /$$__  $$|__  $$__/|__  $$__/ /$$__  $$   \n");
		printf("| $$      | $$  \\ $$   | $$      | $$   | $$  \\ $$  \n");
		printf("| $$      | $$  | $$   | $$      | $$   | $$  | $$   \n");
		printf("| $$      | $$  | $$   | $$      | $$   | $$  | $$    \n");
		printf("| $$      | $$  | $$   | $$      | $$   | $$  | $$    \n");
		printf("| $$$$$$$$|  $$$$$$/   | $$      | $$   |  $$$$$$/    \n");
		printf("|________/ \\______/    |__/      |__/    \\______/    \n");
		printf("\n\n******************************");
		printf("\n            MENU              ");
		printf("\n\n******************************");
		printf("\n1: Regular Play");
		printf("\n2: Lucky Pick");
		printf("\n3: 5 - Roll");
		printf("\n4: 7 System");
		printf("\n5: Auto-Win");
		printf("\n0: Exit Program");
		printf("\nSelect an option: ");
	
		int choice;
		scanf("%d", &choice);
		switch(choice){
				case 1: lottoFunc(newjackpot);break;
				case 2: lottoLucky(newjackpot);break;
				case 3: fiveRoll(newjackpot);break;
				case 4: sevenSystem(newjackpot);break;
				case 5: lottoAuto(newjackpot);break;
				case 0: printf("\nTHANK YOU FOR PLAYING!"); return 0; break;
				default: printf("\nPLEASE ENTER A VALID OPTION\n");
							printf("\nPress any key to continue..."); getch(); system("cls");
							MainMenu(newjackpot); break;
		}
}

int 
main(){
	
		long long jackpot642 = 6000000;
	
		MainMenu(jackpot642);
	
		return 0;
}
