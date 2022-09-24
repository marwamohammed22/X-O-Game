
#include <stdio.h>
#include<stdlib.h>

//array for cells position
char places[]={'1','2','3','4','5','6','7','8','9'};

//array to mark chosen places..
int marked[9]={0};

//draw the shape
void draw_Shape(char arr[]);

//to check if there is winner or no
int check_Ifwin(char a[] );

//ask user to play again or not
void start_New_Game();

//to start game
void play();


int main()
{
    play();

    return 0;
}


//function to draw the shape of the game
void draw_Shape(char arr[])
{

    printf(" ");
    printf("-----------------------\n");
    printf("|\t|\t|\t|\t\n|   %c\t|   %c\t|   %c\t|\t\n|\t|\t|\t|\t\n",arr[0],arr[1],arr[2]);
    printf(" ");
    printf("-----------------------\n");
    printf("|\t|\t|\t|\t\n|   %c\t|   %c\t|   %c\t|\t\n|\t|\t|\t|\t\n",arr[3],arr[4],arr[5]);
    printf(" ");
    printf("-----------------------\n");
    printf("|\t|\t|\t|\t\n|   %c\t|   %c\t|   %c\t|\t\n|\t|\t|\t|\t\n",arr[6],arr[7],arr[8]);
    printf(" ");
    printf("-----------------------\n");

}

//function to check if there is a winner , returns 2 if there is a winner else returns 1
int check_Ifwin(char a[] )
{
    //check equal rows
    for(int i = 0; i < 9; i+=3)
    {
        if(a[i] == a[i+1] && a[i] == a[i+2])
        {
            return 2;
        }
    }
    //check equal column
    for(int i = 0; i < 3; i++)
    {
        if(a[i] == a[i+3] && a[i] == a[i+6])
        {
            return 2;
       }
    }
    //check diagonal
    if((a[0] == a[4] && a[0] == a[8]) || (a[2] == a[4] && a[2] == a[6]))
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

//function to start a new game or not
void start_New_Game()
{
    printf("Enter 0 to exit, 1 to continue\n") ;
    int choice;
    scanf("%i", &choice);

    if(choice == 1)
    {
        // put the array's values to its initial
        places[0] = '1';
        places[1] = '2';
        places[2] = '3';
        places[3] = '4';
        places[4] = '5';
        places[5] = '6';
        places[6] = '7';
        places[7] = '8';
        places[8] = '9';

        marked[0] = 0;
        marked[1] = 0;
        marked[2] = 0;
        marked[3] = 0;
        marked[4] = 0;
        marked[5] = 0;
        marked[6] = 0;
        marked[7] = 0;
        marked[8] = 0;

//invoke play() method to play again
        play();
    }
    else if(choice == 0)
    {
//if the user does not want to play again exit the program
      exit(0);
    }else
    {
// Re_invoke the function if the user didnot enter valid number
        printf("Invalid number .. try again\n");
        start_New_Game();
    }
}

//function to start playing
void play()
{
    draw_Shape(places);

    for(int i = 1; i <= 9; i++)
    {
        char player;//to store the player's letter

        if(i % 2 == 0)
        {
            player='O';
            printf("Enter a number between [1, 9] (inclusive).\nIt's O turn\n");
        }
        else
        {
            printf("Enter a number between [1, 9] (inclusive).\nIt's X turn\n");
            player='X';
        }

        int num;//to store the user's selected position number
        scanf("%i",&num);

        //check if the user entered a valid place number

        if(num < 1 || num > 9 || (marked[num-1] == -1))
        {
            printf("You entered invalid number .. Please try again \n");
            i--;
            continue;
        }
        //after recieving the place..

        //mark selected place with -1
        marked[num-1] = -1;

        //add the player's letter to the array
        places[num-1] = player;

        //update the draw after this
        draw_Shape(places);

        //By the 5's turn we may have a winner so we have to check
        if (i >= 5){

          if(check_Ifwin(places) == 2)
          {
              printf("%c wins the game.Do you want to play another game?",player);

              //if we have a winner ask if the user want to play again or not
              start_New_Game();
          }
      }

    //check if the board is full and there is no winner ..
        if(i == 9 && (check_Ifwin(places) == 1))
        {
            printf("drawDo you want to play another game?\n");
            //ask to start new game or not
            start_New_Game();
        }
    }
 }






