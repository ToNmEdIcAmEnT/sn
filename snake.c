#include <conio.h>
# include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<time.h>

#define HEIGHT 20
#define WIDTH 40


int snakeTailX[100], snakeTailY[100];

int snakeTailLen;

int gameover, key, score;

int x, y, fruitx, fruity;


void setup()
    {
        gameover = 0;

        x = WIDTH / 2;
        y = HEIGHT / 2;


        snakeTailLen = 0;
            key=2;
            srand((unsigned)time(NULL));


        fruitx= rand() % WIDTH;
        fruity = rand() % HEIGHT;

        while(fruitx== 0)
            fruitx = rand() % WIDTH;
        
        while(fruity == 0)
            fruity= rand() % HEIGHT;
            score = 0;


            
    }
        void draw()
                {
                    printf("\033[H\033[J");

                 
                 for(int i = 0; i< WIDTH + 2; i++)
                
                        printf("-");
                        printf("\n");

                        for(int i= 0; i < HEIGHT; i++)
                            {
                                 printf("#");
                                for(int j =0; j< WIDTH; j++)
                                    {
                                    
                                       

                                        if(i == y && j == x)
                                        printf("O");

                                        else if(i == fruity && j == fruitx)
                                                printf("*");

                                                else
                                                    {
                                                        int prTail = 0;
                                                        for( int k=0; k< snakeTailLen; k++)
                                                            {
                                                                if(snakeTailX[k] == j && snakeTailY[k]== i)
                                                                    {
                                                                        printf("o");
                                                                        prTail = 1;
                                                                        break;
                                                                    }
                                                            }
                                                            if(!prTail)
                                                            printf(" ");
                                                    }
                                    }
                                    printf("#\n");
                            }

                            for (int i=0; i< WIDTH +2; i++)
                            printf("-");
                            printf("\n");

                            printf("score= %d", score);
                            printf("\n");
                            printf("Press W,A,S,D for movement.\n");
                            printf("press X to quit the game.");
                    
                }



                void input()
                    {
                        if(kbhit())
                            {
                                switch(tolower(getch()))
                                    {
                                        case 'a':
                                            if(key!=2)
                                            key= 1;
                                            break;
                                         case 'd':
                                            if(key!=1)
                                            key = 2;
                                            break;
                                        case 'w':
                                            if(key!=4)
                                            key=3;
                                            break;
                                        case 's':
                                            if(key!=3)
                                            key=4;
                                            break;
                                        case 'x':
                                            gameover = 1;
                                            break;

                                    }
                            }
                    }




                    void logic()
                        {
                            int prevX = snakeTailX[0];
                            int prevY = snakeTailY[0];
                            int prev2X, prev2Y;
                            snakeTailX[0] = x;
                            snakeTailY[0] = y;

                            for(int i =1; i< snakeTailLen;i++)
                                {
                                    prev2X = snakeTailX[i];
                                    prev2Y = snakeTailY[i];
                                    snakeTailX[i]= prevX;
                                    snakeTailY[i]= prevY;
                                    prevX = prev2X;
                                    prevY= prev2Y;
                                }

                                switch(key)
                                    {
                                        case 1:
                                            x--;
                                            break;
                                        case 2:
                                            x++;
                                            break;
                                        case 3:
                                            y--;
                                            break;
                                        case 4:
                                            y++;
                                            break;
                                        default:
                                            break;
                                    }

                                    if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
                                        gameover = 1;

                                    for(int i= 0; i < snakeTailLen;i++)
                                        {
                                            if(snakeTailX[i] == x && snakeTailY[i] == y)
                                                gameover = 1;
                                        }

                                    if(x == fruitx && y== fruity)
                                        {
                                            fruitx = rand() % WIDTH;
                                            fruity = rand() % HEIGHT; 

                                            while(fruitx == 0)
                                                fruitx = rand() % WIDTH;

                                            while(fruity == 0)
                                                fruity = rand() % HEIGHT;

                                            score += 10;
                                            snakeTailLen++;
                                        }
                        }


                        int main()
                            {
                                setup();

                                while(!gameover)
                                    {
                                        draw();
                                        input();
                                        logic();
                                        Sleep(200);
                                    }
                                    return 0;
                            }