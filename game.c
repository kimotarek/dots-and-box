#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define red "\x1b[31m"
#define reset "\x1b[0m"
#define blue "\x1b[34m"
#define yellow "\x1b[33m"
#define green "\x1b[32m"
#define magenta "\x1b[35m"
#define cyan    "\x1b[36m"

int main() {
    //ask the user about colors of players
    char c_pl1[20], c_pl2[20];
    printf("please Enter color of player 1:");
    gets(c_pl1);
    printf("please Enter color of player 2:");
    gets(c_pl2);

    //genralization of grid and get its size from the user
    int n, m;
    system(" ");
    printf("please choose size of your grid N X M \n");
    printf("Enter N (rows):");
    scanf("%d", &n);
    printf("\nEnter M (columns):");
    scanf("%d", &m);

    int arr[2 * n + 1][2 * m + 1];

    //fill with points of grid
    for (int i = 0; i < 2 * n + 1; i += 2) {
        for (int j = 0; j < 2 * m + 1; j += 2) {
            arr[i][j] = 254;
        }
    }
    //fill with spaces in all empty rows
    for (int i = 1; i < 2 * n + 1; i += 2) {
        for (int j = 0; j < 2 * m + 1; j++) {
            arr[i][j] = 32;
        }
    }
    //fill with spaces in rows containing points of grid
    for (int i = 0; i < 2 * n + 1; i += 2) {
        for (int j = 1; j < 2 * m + 1; j += 2) {
            arr[i][j] = 32;
        }
    }
    int count = 0;
    //===================================================================
    //start the game
    int x, y, z, w;
    for (int i = 0; i < (2 * (n * m)) + (n) + (m); i++) {
        if (i % 2 == 0) {
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
                    if (arr[i][j] == 196 || arr[i][j] == 179) {
                        printf(red"%c "reset, arr[i][j]);
                    } else {
                        printf("%c ", arr[i][j]);
                    }
                }
                printf("\n");
            }

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
                if (arr[x][z] != 196) {
                    arr[x][z] = 196;
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
                if (arr[x][z] != 179) {
                    arr[x][z] = 179;
                } else {
                    printf("WARNING: Please choose an empty line\n");
                    goto a;
                }


            }
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
                    if (arr[i][j] == 196 || arr[i][j] == 179) {
                        printf(red"%c "reset, arr[i][j]);
                    } else {
                        printf("%c ", arr[i][j]);
                    }
                }
                printf("\n");
            }
            system("cls");
        }
        //===================================================================
        if (i % 2 == 1) {
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
                    if (arr[i][j] == 196 || arr[i][j] == 179) {
                        printf(blue"%c "reset, arr[i][j]);
                    } else {
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
                if (arr[x][z] != 196) {
                    arr[x][z] = 196;
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
                if (arr[x][z] != 179) {
                    arr[x][z] = 179;
                } else {
                    printf("WARNING: Please choose an empty line\n");
                    goto b;
                }


            }
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
                    if (arr[i][j] == 196 || arr[i][j] == 179) {
                        printf(blue"%c "reset, arr[i][j]);
                    } else {
                        printf("%c ", arr[i][j]);
                    }
                }
                printf("\n");
            }
            system("cls");
        }

    }
    return 0;
}
