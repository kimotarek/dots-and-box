const char * play_o ="%s,:%d\n";
const char * play_i ="%[^,],:%d\n";


char *co ( char ch[]){
    int i,y;

    for(i=0;ch[i];i++) {
        if (ch[i] >= 'a' && ch[i] <= 'z') {
            ch[i] = ch[i] - 32;
        }



    }
    return ch;
}

int game (int n, int m ,player p1,player p2, char colour1[20],char colour2[20],char ch1,char ch2) {
    time_t t1=0, t2=0 ,t3=0,t4=0;
    times t;
    FILE *f,*top;
    int y1,x5,td1=0,td2=0;
    char qq[20];

    system(" ");

    //definition of arr, arr1 , arr2
    int arr[2 * n + 1][2 * m + 1], arr1[2 * n + 1][2 * m + 1], arr2[2 * n + 1][2 * m + 1];
    //definition of
    int arrBox[2 * n * m];
    int count = 0;
    for (int k = 1; k < 2 * n + 1; k += 2) {
        for (int l = 1; l < 2 * m + 1; l += 2) {
            arrBox[count++] = k;
            arrBox[count++] = l;
        }
    }

    //fill with points of grid
    for (int i = 0; i < 2 * n + 1; i += 2) {
        for (int j = 0; j < 2 * m + 1; j += 2) {
            arr[i][j] = 254;
            arr1[i][j] = 254;
            arr2[i][j] = 254;
        }
    }
    //fill with spaces in all empty rows
    for (int i = 1; i < 2 * n + 1; i += 2) {
        for (int j = 0; j < 2 * m + 1; j++) {
            arr[i][j] = 32;
            arr1[i][j] = 32;
            arr2[i][j] = 32;
        }
    }
    //fill with spaces in rows containing points of grid
    for (int i = 0; i < 2 * n + 1; i += 2) {
        for (int j = 1; j < 2 * m + 1; j += 2) {
            arr[i][j] = 32;
            arr1[i][j] = 32;
            arr2[i][j] = 32;
        }
    }

    //===================================================================

    //start the game
    int x, y, z, w, rem,x3;
    int u = (2 * (n * m)) + (n) + (m);
    rem = u;
    if (strcmp(colour1, "blue") == 0 && strcmp(colour2, "red") == 0) {


        {
            for (int i0 = 0; i0 < u; i0++) {


                if (i0 % 2 == 0) {//player of color blue
                    az :
                    //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    //print 1 : 5 above grid
                    printf(" \t\t\t\t\t\t ");
                    for (int i1 = 0; i1 < 2 * m + 1; i1++) {
                        printf(" %d", i1 + 1);
                    }
                    printf("\n");

                    //print 1:5 beside the grid and print the grid using %c
                    for (int i2 = 0; i2 < 2 * n + 1; i2++) {
                        printf("\t\t\t\t\t\t%d ", i2 + 1);

                        for (int j2 = 0; j2 < 2 * m + 1; j2++) {
                            if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                printf(red"%c "reset, arr2[i2][j2]);

                            } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                printf(blue"%c "reset, arr1[i2][j2]);
                            } else {
                                printf("%c ", arr[i2][j2]);
                            }
                        }
                        printf("\n");
                    }
                    t=time_s(td2);
                    printf(yellow"\t\t\t\t\t remaining lines =%d \n"reset, rem);
                    print_inf(p1, "blue", p2, "red");
                    printf(yellow"\t\t\t player %d turn\t\ttime=%d:%d:%d \n"reset,1,t.hour,t.min,t.sec );

                    //ask about move >>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    a:
                    t1=time(0);
                    printf("Enter row 1 :");
                    scanf("%d", &x);
                    printf("\nEnter row 2 :");
                    scanf("%d", &y);
                    printf("\nEnter col 1 :");
                    scanf("%d", &z);
                    printf("\nEnter col 2 :");
                    scanf("%d", &w);
                    t2=time(0);
                    td1= difftime(t2,t1)+td2;

                    if (x == 0 && y == 0 && z == 0 && w == 0) {

                        system("cls");
                        al:
                        x5 = print_setting();
                        if (x5 == 1) {
                            system("cls");
                            goto az;
                        } else if (x5 == 2) {
                            system("cls");
                            n1:
                            printf("1)"yellow"to save to file 1"reset"            2)"yellow"to save to file 2\n"reset);
                            printf("3)"yellow"to save to file 3"reset"            4)"yellow"back\n"reset);

                            printf("\nenter your choice(1,2,3,4):");
                            scanf("%s", qq);

                            if (strcmp(qq, "1") == 0) { y1 = 1; }
                            else if (strcmp(qq, "2") == 0) { y1 = 2; }
                            else if (strcmp(qq, "3") == 0) { y1 = 3; }
                            else if (strcmp(qq, "4") == 0) { y1 = 0; }
                            else {
                                system("cls");
                                printf(red"WARNING:"reset" your choice is incorrect\n ");
                                goto n1;
                            }

                            if (y1 == 0) {
                                system("cls");
                                goto az;
                            } //file save
                            else if (y1 == 1) {
                                if ((f = fopen("save1.text", "w") == NULL)) {
                                    printf(red"EROR:"reset"can\'t open file\n");
                                    return 0;

                                }
                                f = fopen("save1.text", "w");
                                fseek(f, 0, SEEK_SET);
                            } else if (y1 == 2) {
                                if ((f = fopen("save2.text", "w") == NULL)) {
                                    printf(red"EROR:"reset"can\'t open file\n");
                                    return 0;

                                }
                                f = fopen("save2.text", "w");
                                fseek(f, 0, SEEK_SET);
                            } else if (y1 == 3) {
                                if ((f = fopen("save3.text", "w") == NULL)) {
                                    printf(red"EROR:"reset"can\'t open file\n");
                                    return 0;

                                }
                                f = fopen("save3.text", "w");
                                fseek(f, 0, SEEK_SET);
                            }


                            fprintf_s(f, "player1score=%d,player2score=%d,player1moves=%d,player2moves=%d\n",
                                      p1.score,
                                      p2.score, p1.move, p2.move);
                            fprintf_s(f, "i0=%d,u=%d,rem=%d,N=%d,M=%d\n", i0, u, rem, n, m);
                            fprintf_s(f, "arr:");
                            for (int i = 0; i < 2 * n + 1; i++) {
                                for (int j = 0; j < 2 * m + 1; j++) {

                                    fprintf_s(f, "%d,", arr[i][j]);
                                }
                            }
                            fprintf_s(f, "\narr1:");
                            for (int i = 0; i < 2 * n + 1; i++) {
                                for (int j = 0; j < 2 * m + 1; j++) {

                                    fprintf_s(f, "%d,", arr[i][j]);
                                }
                            }
                            fprintf_s(f, "\narr2:");
                            for (int i = 0; i < 2 * n + 1; i++) {
                                for (int j = 0; j < 2 * m + 1; j++) {

                                    fprintf_s(f, "%d,", arr2[i][j]);
                                }
                            }
                            fprintf_s(f, "\nplayer1name=%s,player2name=%s,player1colour=%s,player2colour=%s,",
                                      p1.name,
                                      p2.name, colour1, colour2);
                            fclose(f);
                            system("cls");
                            printf(green"\n\n\n                                                 save finished                              \n");
                            goto al;

                        } else if (x5 == 3) {

                            return 5;//for go to  loud
                        } else if (x5 == 4) {    // for go to About ?
                           x3=about_after_settings();

                            if(x3==1){return 7;}
                            else if(x3==2){system("cls");   goto az ;}
                            else if(x3==3){return 8 ;}


                        } else if (x5 == 5) {
                            return 7; //for main menu

                        } else if (x5 == 6) {

                            return 8; //for exit
                        }

                    }


                    if (x - y > 2 || y - x > 2 || z - w > 2 || w - z > 2) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a;
                    }
                    if (x == y) {
                        if (z > w) {
                            int temp = z;
                            z = w;
                            w = temp;
                        } //swap z&w
                        x = x - 1;
                        if (arr1[x][z] != 205 && arr2[x][z] != 205) {
                            arr[x][z] = 205;
                            arr1[x][z] = 205;
                        } else {
                            printf(red"WARNING"reset": Please choose an empty line\n");
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
                        if (arr1[x][z] != 186 && arr2[x][z] != 186) {
                            arr[x][z] = 186;
                            arr1[x][z] = 186;
                        } else {
                            printf(red"WARNING:"reset" Please choose an empty line\n");
                            goto a;
                        }


                    }

                    inc_moves(&p1);
                    rem--;
                    int f1 = 0;
                    for (int k = 0, l = 1; k < 2 * n * m && l < 2 * n * m; k += 2, l += 2) {
                        if (arrBox[k] != 0 && arrBox[l] != 0) {
                            if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l] + 1] == 186 &&
                                arr[arrBox[k] - 1][arrBox[l]] == 205 &&
                                arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                arr[arrBox[k]][arrBox[l]] = ch1;
                                arr1[arrBox[k]][arrBox[l]] = ch1;
                                arrBox[k] = 0;
                                arrBox[l] = 0;
                                inc_score(&p1);
                                system("cls");
                                f1 = 1;
                            } else { continue; }
                        } else { continue; }
                    }
                    if (f1 == 1) {
                        f1 = 0;
                        u--;

                        if (i0 == u||rem==0) {
                            if (p1.score > p2.score) {
                                top = fopen("top 10 player.text", "a");
                                fprintf_s(top, play_o, co(p1.name), p1.score);  //open file and append struct of winner
                                fclose(top);

                                return end(p1.name, p1.score);
                            } else if (p1.score < p2.score) {

                                top = fopen("top 10 player.text", "a");
                                fprintf_s(top, play_o,co(p2.name), p2.score);  //open file and append struct of winner
                                fclose(top);

                                return end(p2.name, p2.score);
                            } else {
                                return end("draw", p1.score);

                            }
                        }


                        goto az; //get one additional move as a result of score++
                    }
                    //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 2
                    //print 1 : 5 above grid
                    printf(" \t\t\t\t\t\t ");
                    for (int i3 = 0; i3 < 2 * m + 1; i3++) {
                        printf(" %d", i3 + 1);
                    }
                    printf("\n");

                    //print 1:5 beside the grid and print the grid using %c
                    for (int i4 = 0; i4 < 2 * n + 1; i4++) {
                        printf("\t\t\t\t\t\t%d ", i4 + 1);

                        for (int j4 = 0; j4 < 2 * m + 1; j4++) {
                            if (arr2[i4][j4] == 205 || arr2[i4][j4] == 186 || arr2[i4][j4] == ch2) {
                                printf(red"%c "reset, arr2[i4][j4]);

                            } else if (arr1[i4][j4] == 205 || arr1[i4][j4] == 186 || arr1[i4][j4] == ch1) {
                                printf(blue"%c "reset, arr1[i4][j4]);
                            } else {
                                printf("%c ", arr[i4][j4]);
                            }
                        }
                        printf("\n");
                    }
                    system("cls");

                }
                //===================================================================
                {
                    if (i0 % 2 == 1) {
                        ax :
                        //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                        //print 1 : 5 above grid
                        printf(" \t\t\t\t\t\t ");
                        for (int i5 = 0; i5 < 2 * m + 1; i5++) {
                            printf(" %d", i5 + 1);
                        }
                        printf("\n");

                        //print 1:5 beside the grid and print the grid using %c
                        for (int i6 = 0; i6 < 2 * n + 1; i6++) {
                            printf("\t\t\t\t\t\t%d ", i6 + 1);

                            for (int j6 = 0; j6 < 2 * m + 1; j6++) {
                                if (arr2[i6][j6] == 205 || arr2[i6][j6] == 186 || arr2[i6][j6] == ch2) {
                                    printf(red"%c "reset, arr2[i6][j6]);

                                } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch1) {
                                    printf(blue"%c "reset, arr1[i6][j6]);
                                } else {
                                    printf("%c ", arr[i6][j6]);
                                }
                            }
                            printf("\n");
                        }
                        t=time_s(td1);
                        printf(yellow"\t\t\t\t\t remaining lines =%d \n"reset, rem);
                        print_inf(p1, "blue", p2, "red");
                        printf(yellow"\t\t\t player %d turn\t\ttime=%d:%d:%d \n"reset,2,t.hour,t.min,t.sec );

                        b:
                        t3=time(0);
                        printf("Enter row 1 :");
                        scanf("%d", &x);
                        printf("\nEnter row 2 :");
                        scanf("%d", &y);
                        printf("\nEnter col 1 :");
                        scanf("%d", &z);
                        printf("\nEnter col 2 :");
                        scanf("%d", &w);
                        t4=time(0);
                        td2= difftime(t4,t3)+td1;

                        if (x == 0 && y == 0 && z == 0 && w == 0) {

                            system("cls");
                            al2:
                            x5 = print_setting();
                            if (x5 == 1) {
                                system("cls");
                                goto az;
                            } else if (x5 == 2) {
                               system("cls");
                                n2:
                                printf("1)"yellow"to save to file 1"reset"            2)"yellow"to to from file 2\n"reset);
                                printf("3)"yellow"to save to file 3"reset"            4)"yellow"back\n"reset);

                                printf("\nenter your choice(1,2,3,4):");
                                scanf("%s", qq);

                                if (strcmp(qq, "1") == 0) { y1 = 1; }
                                else if (strcmp(qq, "2") == 0) { y1 = 2; }
                                else if (strcmp(qq, "3") == 0) { y1 = 3; }
                                else if (strcmp(qq, "4") == 0) { y1 = 0; }
                                else {
                                    system("cls");
                                    printf(red"WARNING:"reset" your choice is incorrect\n ");
                                    goto n2;
                                }

                                if (y1 == 0) {
                                    system("cls");
                                    goto az;
                                } //file save
                                else if (y1 == 1) {
                                    if ((f = fopen("save1.text", "w") == NULL)) {
                                        printf(red"EROR:"reset"can\'t open file\n");
                                        return 0;

                                    }
                                    f = fopen("save1.text", "w");
                                    fseek(f, 0, SEEK_SET);
                                } else if (y1 == 2) {
                                    if ((f = fopen("save2.text", "w") == NULL)) {
                                        printf(red"EROR:"reset"can\'t open file\n");
                                        return 0;

                                    }
                                    f = fopen("save2.text", "w");
                                    fseek(f, 0, SEEK_SET);
                                } else if (y1 == 3) {
                                    if ((f = fopen("save3.text", "w") == NULL)) {
                                        printf(red"EROR:"reset"can\'t open file\n");
                                        return 0;

                                    }
                                    f = fopen("save3.text", "w");
                                    fseek(f, 0, SEEK_SET);
                                }


                                fprintf_s(f, "player1score=%d,player2score=%d,player1moves=%d,player2moves=%d\n",
                                          p1.score,
                                          p2.score, p1.move, p2.move);
                                fprintf_s(f, "i0=%d,u=%d,rem=%d,N=%d,M=%d\n", i0, u, rem, n, m);
                                fprintf_s(f, "arr:");
                                for (int i = 0; i < 2 * n + 1; i++) {
                                    for (int j = 0; j < 2 * m + 1; j++) {

                                        fprintf_s(f, "%d,", arr[i][j]);
                                    }
                                }
                                fprintf_s(f, "\narr1:");
                                for (int i = 0; i < 2 * n + 1; i++) {
                                    for (int j = 0; j < 2 * m + 1; j++) {

                                        fprintf_s(f, "%d,", arr[i][j]);
                                    }
                                }
                                fprintf_s(f, "\narr2:");
                                for (int i = 0; i < 2 * n + 1; i++) {
                                    for (int j = 0; j < 2 * m + 1; j++) {

                                        fprintf_s(f, "%d,", arr2[i][j]);
                                    }
                                }
                                fprintf_s(f, "\nplayer1name=%s,player2name=%s,player1colour=%s,player2colour=%s,",
                                          p1.name,
                                          p2.name, colour1, colour2);
                                fclose(f);
                                system("cls");
                                printf(green"\n\n\n                                                 save finished                              \n");
                                goto al2;

                            } else if (x5 == 3) {

                                return 5;//for go to  loud
                            } else if (x5 == 4) {// for go to About ?
                                x3=about_after_settings();
                                if(x3==1){return 7;}
                                else if(x3==2){system("cls"); goto ax ;}
                                else if(x3==3){return 8 ;}

                            } else if (x5 == 5) {
                                return 7; //for main menu

                            } else if (x5 == 6) {

                                return 8; //for exit
                            }

                        }
                        if (x - y > 2 || y - x > 2 || z - w > 2 || w - z > 2) {
                            printf(red"WARNING"reset": Please choose correct line\n");
                            goto b;
                        }
                        if (x == y) {
                            if (z > w) {
                                int temp = z;
                                z = w;
                                w = temp;
                            } //swap z&w
                            x = x - 1;
                            if (arr1[x][z] != 205 && arr2[x][z] != 205) {
                                arr[x][z] = 205;
                                arr2[x][z] = 205;

                            } else {
                                printf(red"WARNING:"reset" Please choose an empty line\n");
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
                            if (arr1[x][z] != 186 && arr2[x][z] != 186) {
                                arr[x][z] = 186;
                                arr2[x][z] = 186;
                            } else {
                                printf(red"WARNING:"reset" Please choose an empty line\n");
                                goto b;
                            }


                        }
                        inc_moves(&p2);
                        rem--;
                        int f2 = 0;
                        for (int k = 0, l = 1; k < 2 * n * m && l < 2 * n * m; k += 2, l += 2) {
                            if (arrBox[k] != 0 && arrBox[l] != 0) {
                                if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l] + 1] == 186 &&
                                    arr[arrBox[k] - 1][arrBox[l]] == 205 &&
                                    arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                    arr[arrBox[k]][arrBox[l]] = ch2;
                                    arr2[arrBox[k]][arrBox[l]] = ch2;
                                    arrBox[k] = 0;
                                    arrBox[l] = 0;
                                    inc_score(&p2);
                                    system("cls");
                                    f2 = 1;


                                } else { continue; }
                            } else { continue; }
                        }
                        if (f2 == 1) {
                            f2 = 0;
                            u--;
                            if (i0 == u||rem==0) {
                                if (p1.score > p2.score) {

                                    top = fopen("top 10 player.text", "a");
                                    fprintf_s(top, play_o,co(p1.name),
                                              p1.score); //open file and append struct of winner
                                    fclose(top);

                                    return end(p1.name, p1.score);
                                } else if (p1.score < p2.score) {

                                    top = fopen("top 10 player.text","a");
                                    fprintf_s(top,play_o,co(p2.name),p2.score);  //open file and append struct of winner
                                    fclose(top);

                                    return end(p2.name, p2.score);
                                } else {
                                    return end("draw", p1.score);

                                }

                            }

                            system("cls");
                            goto ax;
                        }
                        //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 2
                        //print 1 : 5 above grid
                        printf(" \t\t\t\t\t\t ");
                        for (int i7 = 0; i7 < 2 * m + 1; i7++) {
                            printf(" %d", i7 + 1);
                        }
                        printf("\n");

                        //print 1:5 beside the grid and print the grid using %c
                        for (int i8 = 0; i8 < 2 * n + 1; i8++) {
                            printf("\t\t\t\t\t\t%d ", i8 + 1);

                            for (int j8 = 0; j8 < 2 * m + 1; j8++) {
                                if (arr2[i8][j8] == 205 || arr2[i8][j8] == 186 || arr2[i8][j8] == ch2) {
                                    printf(red"%c "reset, arr2[i8][j8]);

                                } else if (arr1[i8][j8] == 205 || arr1[i8][j8] == 186 || arr1[i8][j8] == ch1) {
                                    printf(blue"%c "reset, arr1[i8][j8]);
                                } else {
                                    printf("%c ", arr[i8][j8]);
                                }
                            }
                            printf("\n");
                        }
                        system("cls");

                    }
                }


            }

        }
    }
}
