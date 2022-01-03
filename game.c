#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define red "\033[0;31m"
#define reset "\033[0;37m"
#define blue "\x1b[34m"
#define yellow "\x1b[33m"
#define green "\x1b[32m"
#define magenta "\x1b[35m"
#define cyan    "\x1b[36m"

int main() {

    //ask the user about colors of players
    char c_pl1[20], c_pl2[20];
    af:
    printf("please Enter color of player 1:");
    gets(c_pl1);
    printf("please Enter color of player 2:");
    gets(c_pl2);
    if (strcmp(c_pl1, c_pl2) == 0) {
        system("cls");
        printf("  "red"WARNING :"reset" please enter different colors\n\n");
        goto af;
    }

    //generalization of grid and get its size from the user

    int n, m;
    system(" ");
    printf("please choose size of your grid N X M \n");
    printf("Enter N (rows):");
    scanf("%d", &n);
    printf("\nEnter M (columns):");
    scanf("%d", &m);
    system("cls") ;

    int arr[2 * n + 1][2 * m + 1],arr1[2 * n + 1][2 * m + 1],arr2[2 * n + 1][2 * m + 1] ;

    //fill with points of grid
    for (int i = 0; i < 2 * n + 1; i += 2) {
        for (int j = 0; j < 2 * m + 1; j += 2) {
            arr[i][j] = 254;
            arr1[i][j]=254;
            arr2[i][j]=254;
        }
    }
    //fill with spaces in all empty rows
    for (int i = 1; i < 2 * n + 1; i += 2) {
        for (int j = 0; j < 2 * m + 1; j++) {
            arr[i][j] = 32;
            arr1[i][j]=32;
            arr2[i][j]=32;
        }
    }
    //fill with spaces in rows containing points of grid
    for (int i = 0; i < 2 * n + 1; i += 2) {
        for (int j = 1; j < 2 * m + 1; j += 2) {
            arr[i][j] = 32;
            arr1[i][j]=32;
            arr2[i][j]=32;
        }
    }

    //===================================================================

    //start the game
    int x, y, z, w;
    if (strcmp(c_pl1, "blue") == 0 && strcmp(c_pl2, "red") == 0) {
        {

            for (int i = 0; i < ((2 * (n * m)) + (n) + (m)) / 2; i++) {

                if (i % 2 == 0) {       //player of color blue
                    //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    //print 1 : 5 above grid
                    printf(" ");
                    for (int i = 0; i < 2 * m + 1; i++) {
                        printf(" %d", i + 1);
                    }
                    printf("\n");

                    //print 1:5 beside the grid and print the grid using %c
                    for (int i = 0; i < 2 * n + 1; i++) {
                        printf("%d ", i + 1);

                        for (int j = 0; j < 2 * m + 1; j++) {
                            if (arr2[i][j] == 196 || arr2[i][j] == 179) {
                                printf(red"%c "reset, arr2[i][j]);

                            }

                            else if((arr1[i][j]==196||arr1[i][j]==179)){
                                printf(blue"%c "reset,arr1[i][j]);
                            }
                            else {
                                printf("%c ", arr[i][j]);
                            }
                        }
                        printf("\n");
                    }

                    //ask about move >>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    a:
                    printf("Enter row 1 :");
                    scanf("%d", &x);
                    printf("\nEnter row 2 :");
                    scanf("%d", &y);
                    printf("\nEnter col 1 :");
                    scanf("%d", &z);
                    printf("\nEnter col 2 :");
                    scanf("%d", &w);
                    if (x == y) {
                        if (z > w) {
                            int temp = z;
                            z = w;
                            w = temp;
                        } //swap z&w
                        x = x - 1;
                        if (arr1[x][z] != 196&&arr2[x][z]!=179) {
                            arr[x][z] = 196;
                            arr1[x][z]=196;
                        } else {
                            printf("WARNING: Please choose an empty line\n");
                            goto a;
                        }
                    }
                    if (z == w) {
                        if (x > y) {
                            int temp = x;
                            x = y;
                            y = temp;
                        } //swap z&w
                        z = z - 1;
                        if (arr1[x][z] != 179&&arr2[x][z]!=179) {
                            arr[x][z] = 179;
                            arr1[x][z]=179;
                        } else {
                            printf("WARNING: Please choose an empty line\n");
                            goto a;
                        }


                    }
                    system("cls");
                    //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 2
                    //print 1 : 5 above grid
                    printf(" ");
                    for (int i = 0; i < 2 * m + 1; i++) {
                        printf(" %d", i + 1);
                    }
                    printf("\n");
                    //print 1:5 beside the grid and print the grid using %c
                    for (int i = 0; i < 2 * n + 1; i++) {
                        printf("%d ", i + 1);

                        for (int j = 0; j < 2 * m + 1; j++) {
                            if (arr1[i][j] == 196 || arr1[i][j] == 179) {
                                printf(blue"%c "reset, arr1[i][j]);

                            }
                            else if(arr2[i][j]==196||arr2[i][j]==179){
                                printf(red"%c "reset,arr2[i][j]);
                            }
                            else {

                                printf("%c ", arr[i][j]);
                            }


                        }
                        printf("\n");
                    }
                    //ask about move >>>>>>>>>>>>>>>>>>>>>>>>>>> 2
                    ag:
                    printf("Enter row 1 :");
                    scanf("%d", &x);
                    printf("\nEnter row 2 :");
                    scanf("%d", &y);
                    printf("\nEnter col 1 :");
                    scanf("%d", &z);
                    printf("\nEnter col 2 :");
                    scanf("%d", &w);
                    if (x == y) {
                        if (z > w) {
                            int temp = z;
                            z = w;
                            w = temp;
                        } //swap z&w
                        x = x - 1;
                        if (arr1[x][z] != 196&&arr2[x][z]!=196) {
                            arr[x][z] = 196;
                            arr2[x][z]=196;
                        } else {
                            printf("WARNING: Please choose an empty line\n");
                            goto ag;
                        }
                    }
                    if (z == w) {
                        if (x > y) {
                            int temp = x;
                            x = y;
                            y = temp;
                        } //swap z&w
                        z = z - 1;
                        if (arr1[x][z] != 179&&arr2[x][z]!=179) {
                            arr[x][z] = 179;
                            arr2[x][z]=179;
                        } else {
                            printf("WARNING: Please choose an empty line\n");
                            goto ag;
                        }


                    }


                    system("cls");
                }
                //===================================================================
                if (i % 2 == 1) {           //player of color red
                    //print 1 : 5 above grid
                    printf(" ");
                    for (int i = 0; i < 2 * m + 1; i++) {
                        printf(" %d", i + 1);
                    }
                    printf("\n");

                    //print 1:5 beside the grid and print the grid using %c
                    for (int i = 0; i < 2 * n + 1; i++) {
                        printf("%d ", i + 1);

                        for (int j = 0; j < 2 * m + 1; j++) {
                            if (arr2[i][j] == 196 || arr2[i][j] == 179) {
                                printf(red"%c "reset, arr2[i][j]);


                            }
                            else if(arr1[i][j]==196||arr1[i][j]==179){
                                printf(blue"%c "reset,arr1[i][j]);
                            }
                            else {
                                printf("%c ", arr[i][j]);
                            }

                        }
                        printf("\n");
                    }

                    b:
                    printf("Enter row 1 :");
                    scanf("%d", &x);
                    printf("\nEnter row 2 :");
                    scanf("%d", &y);
                    printf("\nEnter col 1 :");
                    scanf("%d", &z);
                    printf("\nEnter col 2 :");
                    scanf("%d", &w);
                    if (x == y) {
                        if (z > w) {
                            int temp = z;
                            z = w;
                            w = temp;
                        } //swap z&w
                        x = x - 1;
                        if (arr1[x][z] != 196&&arr2[x][z]!=196) {
                            arr[x][z] = 196;
                            arr1[x][z]=196;

                        } else {
                            printf("WARNING: Please choose an empty line\n");
                            goto b;
                        }
                    }
                    if (z == w) {
                        if (x > y) {
                            int temp = x;
                            x = y;
                            y = temp;
                        } //swap z&w
                        z = z - 1;
                        if (arr1[x][z] != 179&&arr2[x][z]!=179) {
                            arr[x][z] = 179;
                            arr1[x][z]=179;
                        } else {
                            printf("WARNING: Please choose an empty line\n");
                            goto b;
                        }


                    }
                    system("cls");
                    //print 1 : 5 above grid
                    printf(" ");
                    for (int i = 0; i < 2 * m + 1; i++) {
                        printf(" %d", i + 1);
                    }
                    printf("\n");
                    //print 1:5 beside the grid and print the grid using %c
                    for (int i = 0; i < 2 * n + 1; i++) {
                        printf("%d ", i + 1);

                        for (int j = 0; j < 2 * m + 1; j++) {
                            if (arr1[i][j] == 196 || arr1[i][j] == 179) {
                                printf(blue"%c "reset, arr1[i][j]);

                            }
                            else if(arr2[i][j]==196||arr2[i][j]==179){
                                printf(red"%c "reset,arr2[i][j]);
                            }
                            else {
                                printf("%c ", arr[i][j]);
                            }



                        }
                        printf("\n");
                    }

                    bg:
                    printf("Enter row 1 :");
                    scanf("%d", &x);
                    printf("\nEnter row 2 :");
                    scanf("%d", &y);
                    printf("\nEnter col 1 :");
                    scanf("%d", &z);
                    printf("\nEnter col 2 :");
                    scanf("%d", &w);
                    if (x == y) {
                        if (z > w) {
                            int temp = z;
                            z = w;
                            w = temp;
                        } //swap z&w
                        x = x - 1;
                        if (arr1[x][z] != 196&&arr2[x][z]!=196) {
                            arr[x][z] = 196;
                            arr2[x][z]=196;
                        } else {
                            printf("WARNING: Please choose an empty line\n");
                            goto bg;
                        }
                    }
                    if (z == w) {
                        if (x > y) {
                            int temp = x;
                            x = y;
                            y = temp;
                        } //swap z&w
                        z = z - 1;
                        if (arr1[x][z] != 179&&arr2[x][z]!=179) {
                            arr[x][z] = 179;
                            arr2[x][z]=179;
                        } else {
                            printf("WARNING: Please choose an empty line\n");
                            goto bg;
                        }


                    }


                    system("cls");
                }
            }

        }
    }


}
