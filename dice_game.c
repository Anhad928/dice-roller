#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int points1 = 0,points2 = 0,initial_random_number = 0,player1_random_number = 0, inital_counter = 0, terminate_counter=0,heading_counter=0;
    char option='.', option2;
    srand(time(NULL));
    while (!feof(stdin)){
        initial_random_number =rand()%6+1;
        if (inital_counter<1){
            scanf(" %c",&option);
            getchar();
            printf("\nPlayer 0's turn. Your point score are: %d\n", points1);
            printf("Enter 'r' to roll, or 'q' to end your turn: %c\n",option);
            if (initial_random_number==1 && option=='r'){
                points1 = 0;
                printf("You rolled a: %d. Your turn total is: %d\n",initial_random_number, points1);
                terminate_counter=1;
                heading_counter=0;
            }
            else if(initial_random_number!=1 && option =='r'){
                points1 = points1+initial_random_number;
                printf("You rolled a: %d. Your turn total is: %d\n",initial_random_number, points1);
                heading_counter=1;
            }
            else if (option == 'q')
            {
                printf("Turn ended. Player 0's point score is now %d\n",points1);
                terminate_counter=1;
                heading_counter=0;
                points1 =0;
            }
            
            inital_counter++;
        }
        player1_random_number= rand()%6+1;
        if (((option =='r' && inital_counter==1 && terminate_counter != 1&& points1!=0) || terminate_counter == 2)&&heading_counter==0){
            printf("\nPlayer 0's turn. Your point score are: %d\n", points1);
            heading_counter++;
        }
        else if (((inital_counter==1 && points1==0)||option=='q')&&heading_counter==0)
        {
            printf("\nPlayer 1's turn. Your point score are: %d\n", points2);
            heading_counter++;
        }
         if ((option =='r' && inital_counter==1 && terminate_counter !=1 && points1!=0) || terminate_counter==2)
        {   scanf(" %c",&option);
            getchar();
            int player0_random_number =rand()%6+1;
            if (option == 'r'){
                if (player0_random_number == 1){
                    printf("Enter 'r' to roll, or 'q' to end your turn: %c\n",option);
                    points1 = 0;
                    printf("You rolled a %d. Your turn total is %d\n",player0_random_number, points1);
                    printf("Turn ended. Player 0's point score is now %d\n",points1);
                    terminate_counter=1;
                    heading_counter=0;
                    }
                else{printf("Enter 'r' to roll, or 'q' to end your turn: %c\n",option);
                    points1 = points1+player0_random_number;
                    printf("You rolled a: %d. Your turn total is: %d\n",player0_random_number, points1);
                }  
            }
            else if (option == 'q'){
            
                printf("Enter 'r' to roll, or 'q' to end your turn: %c\n",option);
                printf("Turn ended. Player 0's point score is now %d\n",points1);
                terminate_counter=1;
                heading_counter=0;
            }
            else{
                return 0;
            }
            if (points1>100){
                printf("Turn ended. Player 0's point score is now %d\n",points1);
                printf("Player 0 wins, with %d points!", points1);
                return 0;
            }
        }
        else if ((inital_counter==1 && points1==0&&terminate_counter==1)||option=='q'){
            scanf(" %c",&option2);
            getchar();
            if (option2 == 'r'){
                if (player1_random_number == 1){
                    points2 = 0;
                    printf("Enter 'r' to roll, or 'q' to end your turn: %c\n",option2);
                    printf("You rolled a %d. Your turn total is: %d\n",player1_random_number, points2);
                    printf("Turn ended. Player 1's point score is now: %d\n",points2);
                    terminate_counter=2;
                    heading_counter=0;
                }
                else{
                    printf("Enter 'r' to roll, or 'q' to end your turn: %c\n",option2);
                    points2 = points2+player1_random_number;
                    printf("You rolled a: %d. Your turn total is: %d\n",player1_random_number, points2);
                }
            }
            else if (option2 == 'q'){
                printf("Enter 'r' to roll, or 'q' to end your turn: %c\n",option2);
                printf("Turn ended. Player 1's point score is now: %d\n",points2);
                terminate_counter=2;
                heading_counter=0;
            }
            else{   
                return 0;
            }
        if (points2>100){
            printf("Turn ended. Player 1's point score is now: %d\n",points2);
            printf("Player 1 wine, with %d points!", points2);
            return 0;
        }
        } 
    }
    return 0;
}
// citation:- https://stackoverflow.com/questions/71601638/when-does-feofstdin-next-to-fgetsstdin-return-true          
// citation:- https://stackoverflow.com/questions/822323/how-to-generate-a-random-int-in-c