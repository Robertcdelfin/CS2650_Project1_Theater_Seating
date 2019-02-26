/*
 ============================================================================
 Name        : CS2650_Project1_Theater_Seating.c
 Author      : Robert Delfin
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//A program that asks the user for input to buy theater seats.
#include <stdlib.h>
#include <stdio.h>

int main ()
{

  int quit = 1; //The value to exit out of purchase loop
  char map[15][30]; //Array to hold seating chart
  int price [15]; //price of the rows
  int row2; //User row choice when buying a seat
  int column2;  //User column choice when buying a seat
  //price of the value in the array
  int cost;
  int answer;
  //Sets the row prices.
  for (int count = 0; count < 15; count++)
  {
    printf("Please enter the price for row %d: \n", count);
    fflush(stdout);
    scanf("%d", &price[count]);
  }

  for (int innerRow = 0; innerRow < 15; innerRow++)
  {
    for (int innerColumn = 0; innerColumn < 30; innerColumn++)
    {
      map[innerRow][innerColumn] = '#'; //Places # in the section
    }
  }

  //User input value
  int choice;

  do
  {
    // Shows the main menu function.
    int choice;
    printf("\n");
    printf("MAIN MENU\n");
    printf(" 1. View Seat Prices.\n");
    printf(" 2. Purchase a Ticket.\n");
    printf(" 3. View Available Seats.\n");
    printf(" 4. View Ticket Sales.\n");
    printf(" 5. Quit the program.\n");
    printf("Please enter your choice: ");
    fflush(stdout);
    scanf("%d", &choice);
    switch (choice)
    {
      case 1:
        printf("Seat Prices\n\n");

        for (int count = 0; count < 15; count++)
        {
          printf("The price for row %d : %d\n",count, price[count]);
        }
        break;

      case 2:

        printf("Purchase a Ticket\n\n");
        do
        {
          printf("Please select the row you would like to sit in: ");
          fflush(stdout);
          scanf("%d",&row2); // Get user input for row

          printf("Please select the seat you would like to sit in: ");
          fflush(stdout);
          scanf("%d",&column2);

          if (map [row2] [column2] == '*')
            {
              printf("Sorry that seat is sold-out, Please select a new seat.\n");
            }
          else
          {
            //The price from the array set to cost
            cost = price [row2]; //set price of row

            //total = total + cost;

            printf("The ticket costs: %d\n", cost);
            //Verify user input
            printf("Confirm Purchase? Enter (1 = YES / 2 = NO)");
            fflush(stdout);
            scanf("%d", &answer);

            //seat = seat - answer;
            //seat2 += answer;

            if (answer == 1)
            {
              printf("Your ticket purchase has been confirmed.\n");
              //places the * symbol into the map
              map [row2][column2] = '*';
            }
            else if (answer == 2)
            {
              printf("Would you like to reserve another seat? (1 = Yes/ 2 = No)");
              fflush(stdout);
              scanf("%d", &quit);
            }

            printf("Would you like to reserve another seat? (1 = Yes/ 2 = No)");
            fflush(stdout);
            scanf("%d", &quit);
          }
        }
        while (quit == 1);
        break;
      case 3:

    	  printf("View Available Seats\n\n");

    	  printf("Seats\n\n" );
          printf("0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29\n");

          for (int innerRow = 0; innerRow < 15; innerRow++)
          {
        	  printf("Row %d ", innerRow);
        	  for (int innerColumn = 0; innerColumn < 30; innerColumn++)
        	  {
        		  printf("%c ", map[innerRow][innerColumn]);
        	  }
        	  printf("\n");
          }
          break;
      case 4:
    	  printf("View Seat Sales\n\n");
    	  break;
      case 5:
    	  printf("Goodbye\n");
    	  exit(0);
    	  break;

      default :
    	  printf("Error input\n");
    }
  } while (choice != 5);
  return 0;
}
