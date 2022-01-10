

int gamecompeasy (int n, int m ,player p1,player p2, char colour1[20],char colour2[20],char ch1,char ch2,int turnco) {
    if(turnco==2) {
        time_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;
        times t;
        FILE *f, *top;
        int y1, x5, td1 = 0;
        char qq[20];
        system(" ");


        int arr[2 * n + 1][2 * m + 1], arr1[2 * n + 1][2 * m + 1], arr2[2 * n + 1][2 * m + 1];

        //definition of array that has the addresses of undo and redo moves to remove lines
        int no_UN_RE = 2 * ((2 * (n * m)) + (n) + (m));
        int no_box = 2 * n * m;
        int box[50] = {0};
        int undo[no_UN_RE], redo[no_UN_RE];
        for (int c = 0; c < no_UN_RE; c++) {
            undo[c] = 0;
            redo[c] = 0;
        }
        //for(int c=0 ; c<no_box ; c++){box[c]=0 ;}
        //definition of array that has the addresses of boxes
        int arrBox[2 * n * m];
        int count = 0;
        for (int k = 1; k < 2 * n + 1; k += 2) {
            for (int l = 1; l < 2 * m + 1; l += 2) {
                arrBox[count++] = k;
                arrBox[count++] = l;
            }
        }
        for (int c = count; c < 50; c++) { arrBox[c] = 0; }

        //undo for boxes
        int undoArrBox[2 * n * m];
        int count0 = 0;
        for (int k = 1; k < 2 * n + 1; k += 2) {
            for (int l = 1; l < 2 * m + 1; l += 2) {
                undoArrBox[count0++] = k;
                undoArrBox[count0++] = l;
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
        int pcCounter = 0;
        int f2 = 0, f1 = 0;
        int fBox = 0;
        int index1 = 0, index2 = 1, cs;
        char ch[10];
        int x, y, z, w;
        int u = (2 * (n * m)) + (n) + (m);
        // // // //
        int pc;
        int rem, x3;
        rem = u;


        if (strcmp(colour1, "blue") == 0 && strcmp(colour2, "yellow") == 0) {


            for (int i0 = 0; i0 < u; i0++) {

                if (i0 % 2 == 0) {//player of color blue
                    az1 :
                    if (fBox == 1 || f2 == 1) {
                        fBox = 0;
                        f2 = 0;
                        goto ax1;
                    }

                    by1:

                    printf(red"\t\t\tnote:"reset"for any misunderstand go to settings then"cyan" About (4)\n"reset);
                    //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    //print 1 : 5 above grid
                    printf(" \t\t\t\t\t\t ");
                    for (int i1 = 0; i1 < 2 * m + 1; i1++) {
                        if (i1 == 10 || i1 == 9) { printf("%d", i1 + 1); }
                        else { printf(" %d", i1 + 1); }
                    }
                    printf("\n");

                    //print 1:5 beside the grid and print the grid using %c
                    for (int i2 = 0; i2 < 2 * n + 1; i2++) {
                        if (i2 == 10 || i2 == 9) {
                            printf("\t\t\t\t\t       %d ", i2 + 1);

                            for (int j2 = 0; j2 < 2 * m + 1; j2++) {
                                if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                    printf(yellow"%c "reset, arr2[i2][j2]);

                                } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                    printf(blue"%c "reset, arr1[i2][j2]);
                                } else {
                                    printf("%c ", arr[i2][j2]);
                                }
                            }
                            printf("\n");
                        } else {
                            printf("\t\t\t\t\t\t%d ", i2 + 1);

                            for (int j2 = 0; j2 < 2 * m + 1; j2++) {
                                if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                    printf(yellow"%c "reset, arr2[i2][j2]);

                                } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                    printf(blue"%c "reset, arr1[i2][j2]);
                                } else {
                                    printf("%c ", arr[i2][j2]);
                                }
                            }
                            printf("\n");
                        }
                    }

                     t=time_s(td1);
                    printf(yellow"\t\t\t\t\t   remaining lines =%d \n"reset, rem);
                    print_inf(p1, "blue", p2, "yellow");
                    printf(blue"\t\t\t    player %d turn\t\t\t\t"reset yellow"        time=%d:%d:%d \n"reset, 1, t.hour,
                            t.min, t.sec);
                    printf("\n  for undo at any step enter" cyan "\"undo\"" reset);
                    printf("\tfor settings at any step enter" cyan "\"row1: 0 & row2: 0 & col1: 0 & clo2: 0\"\n\n" reset);


                    //ask about move >>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    a1:
                    t1 = time(0);
                    printf("Enter row 1 :");
                    again11:
                    gets(ch);
                    if (isdigit(ch[0])) {
                        {
                            if (atoi(ch) >= 0) { x = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice  : ");
                                goto again11;
                            }
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again11;
                    }
                    a21:
                    printf("\nEnter row 2 :");
                    again21:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a1; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { y = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again21;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again21;
                    }
                    a31:
                    printf("\nEnter col 1 :");
                    again31:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a21; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { z = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again31;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again31;
                    }
                    printf("\nEnter col 2 :");
                    again41:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a31; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { w = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again41;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again41;
                    }


                    if (x == 0 && y == 0 && z == 0 && w == 0) {

                        system("cls");
                        al1:
                        x5 = print_setting();
                        if (x5 == 1) {
                            system("cls");
                            goto az1;
                        } else if (x5 == 2) {
                            system("cls");
                            n11:
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
                                goto n11;
                            }

                            if (y1 == 0) {
                                system("cls");
                                goto by1;
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

                            fprintf_s(f, "mode=%d\n", 1);
                            fprintf_s(f,"turnco=%d\n",turnco);
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
                            goto al1;

                        } else if (x5 == 3) {

                            return 5;//for go to  loud
                        } else if (x5 == 4) {    // for go to About ?
                            x3 = about_after_settings();

                            if (x3 == 1) { return 7; }
                            else if (x3 == 2) {
                                system("cls");
                                goto az1;
                            }
                            else if (x3 == 3) { return 8; }


                        } else if (x5 == 5) {
                            return 7; //for main menu

                        } else if (x5 == 6) {

                            return 8; //for exit
                        }

                    }


                    if (x - y > 2 || y - x > 2 || z - w > 2 || w - z > 2) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a1;
                    }
                    if (x != y && z != w) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a1;
                    }
                    if (x == y && z == w) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a1;
                    }
                    t2 = time(0);
                    td1 = difftime(t2, t1) + td1;


                    if (x == y) {
                        if (z > w) {
                            int temp = z;
                            z = w;
                            w = temp;
                        } //swap z&w
                        x = x - 1;
                        if (arr1[x][z] != 205 && arr2[x][z] != 205 && arr[x][z] != 254) {
                            undo[index1] = x;
                            undo[index2] = z;
                            index1 += 2;
                            index2 += 2;
                            arr[x][z] = 205;
                            arr1[x][z] = 205;
                        } else {
                            printf(red"WARNING:"reset" Please choose an empty line\n");
                            goto a1;
                        }
                    }
                    if (z == w) {
                        if (x > y) {
                            int temp = x;
                            x = y;
                            y = temp;
                        } //swap z&w
                        z = z - 1;
                        if (arr1[x][z] != 186 && arr2[x][z] != 186 && arr[x][z] != 254) {
                            undo[index1] = x;
                            undo[index2] = z;
                            index1 += 2;
                            index2 += 2;
                            arr[x][z] = 186;
                            arr1[x][z] = 186;
                        } else {
                            printf(red"WARNING:"reset" Please choose an empty line\n");
                            goto a1;
                        }
                    }
                    inc_moves(&p1);
                    rem--;
                    f1 = 0;
                    for (int k = 0, l = 1; k < 2 * n * m && l < 2 * n * m; k += 2, l += 2) {
                        if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                            if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l] + 1] == 186 &&
                                arr[arrBox[k] - 1][arrBox[l]] == 205 &&
                                arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                arr[arrBox[k]][arrBox[l]] = ch1;
                                arr1[arrBox[k]][arrBox[l]] = ch1;
                                arrBox[k] = 0;
                                arrBox[l] = 0;
                                system("cls");
                                f1 = 1;
                                inc_score(&p1);

                            } else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l] + 1] == 186 &&
                                       arr[box[k] - 1][box[l]] == 205 &&
                                       arr[box[k] + 1][box[l]] == 205) {
                                arr[box[k]][box[l]] = ch1;
                                arr1[box[k]][box[l]] = ch1;
                                box[k] = 0;
                                box[l] = 0;
                                system("cls");
                                f1 = 1;
                                inc_score(&p1);

                            } else { continue; }
                        } else { continue; }
                    }
                    if (f1 == 1) {
                        u--;
                        if (i0 == u) {
                            if (p1.score > p2.score) {
                                top = fopen("top 10 player.text", "a");
                                fprintf_s(top, play_o, co(p1.name), p1.score);  //open file and append struct of winner
                                fclose(top);

                                return end(p1.name, p1.score);
                            } else if (p1.score < p2.score) {
/*
                            top = fopen("top 10 player.text", "a");
                            fprintf_s(top, play_o, co(p2.name), p2.score);  //open file and append struct of winner
                            fclose(top);
*/
                                return end(p2.name, p2.score);
                            } else {
                                return end("draw", p1.score);

                            }
                        }
                        goto az1; //get one additional move as a result of score++
                    }
                    system("cls");
                }

                //===================================================================

                if (i0 % 2 == 1) {
                    ax1 :
                    pc = 0;




                    if (pcCounter %2 ==0){
                    for (int k = 1; k < 2 * n + 1; k += 2) {
                        for (int l = 0; l < 2 * m + 1; l += 2) {
                            if (arr[k][l] != 186) {
                                arr[k][l] = 186;
                                arr2[k][l] = 186;
                                pcCounter++;
                                goto ex21;

                            }
                        }
                    }
                }

                    for (int k = 0; k < 2 * n + 1; k += 2) {
                        for (int l = 1; l < 2 * m + 1; l += 2) {
                            if (arr[k][l] != 205) {
                                arr[k][l] = 205;
                                arr2[k][l] = 205;
                                pcCounter++;
                                goto ex21;
                            }
                        }
                    }
                    ex21:


                    //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    //print 1 : 5 above grid
                    printf(" \t\t\t\t\t\t ");
                    for (int i5 = 0; i5 < 2 * m + 1; i5++) {
                        if (i5 == 10 || i5 == 9) { printf("%d", i5 + 1); }
                        else { printf(" %d", i5 + 1); }
                    }
                    printf("\n");

                    //print 1:5 beside the grid and print the grid using %c
                    for (int i6 = 0; i6 < 2 * n + 1; i6++) {
                        if (i6 == 9 || i6 == 10) {
                            printf("\t\t\t\t\t       %d ", i6 + 1);

                            for (int j6 = 0; j6 < 2 * m + 1; j6++) {
                                if (arr2[i6][j6] == 205 || arr2[i6][j6] == 186 || arr2[i6][j6] == ch2) {
                                    printf(yellow"%c "reset, arr2[i6][j6]);

                                } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch2) {
                                    printf(blue"%c "reset, arr1[i6][j6]);
                                } else {
                                    printf("%c ", arr[i6][j6]);
                                }
                            }
                            printf("\n");
                        } else {
                            printf("\t\t\t\t\t\t%d ", i6 + 1);

                            for (int j6 = 0; j6 < 2 * m + 1; j6++) {
                                if (arr2[i6][j6] == 205 || arr2[i6][j6] == 186 || arr2[i6][j6] == ch2) {
                                    printf(yellow"%c "reset, arr2[i6][j6]);

                                } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch2) {
                                    printf(blue"%c "reset, arr1[i6][j6]);
                                } else {
                                    printf("%c ", arr[i6][j6]);
                                }
                            }
                            printf("\n");
                        }
                    }
                    inc_moves(&p2);
                    rem--;
                    f2 = 0;
                    for (int k = 0, l = 1; k < 2 * n * m && l < 2 * n * m; k += 2, l += 2) {
                        if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                            if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l] + 1] == 186 &&
                                arr[arrBox[k] - 1][arrBox[l]] == 205 &&
                                arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                arr[arrBox[k]][arrBox[l]] = ch2;
                                arr2[arrBox[k]][arrBox[l]] = ch2;
                                arrBox[k] = 0;
                                arrBox[l] = 0;
                                system("cls");
                                f2 = 1;
                                inc_score(&p2);

                            } else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l] + 1] == 186 &&
                                       arr[box[k] - 1][box[l]] == 205 &&
                                       arr[box[k] + 1][box[l]] == 205) {
                                arr[box[k]][box[l]] = ch2;
                                arr2[box[k]][box[l]] = ch2;
                                box[k] = 0;
                                box[l] = 0;
                                system("cls");
                                f2 = 1;
                                inc_score(&p2);

                            } else { continue; }
                        } else { continue; }
                    }
                    if (f2 == 1) {
                        u--;
                        if (i0 == u) {
                            if (p1.score > p2.score) {

                                top = fopen("top 10 player.text", "a");
                                fprintf_s(top, play_o, co(p1.name),
                                          p1.score); //open file and append struct of winner
                                fclose(top);

                                return end(p1.name, p1.score);
                            } else if (p1.score < p2.score) {

                                /* top = fopen("top 10 player.text","a");
                             fprintf_s(top,play_o,co(p2.name),p2.score);  //open file and append struct of winner
                             fclose(top);*/

                                return end(p2.name, p2.score);
                            } else {
                                return end("draw", p1.score);

                            }
                        }
                        goto ax1;
                    }
                    system("cls");
                }
            }
        }

        else if (strcmp(colour1, "red") == 0 && strcmp(colour2, "yellow") == 0) {


            for (int i0 = 0; i0 < u; i0++) {

                if (i0 % 2 == 0) {//player of color blue
                    az2 :
                    if (fBox == 1 || f2 == 1) {
                        fBox = 0;
                        f2 = 0;
                        goto ax2;
                    }

                    by2:

                    printf(red"\t\t\tnote:"reset"for any misunderstand go to settings then"cyan" About (4)\n"reset);
                    //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    //print 1 : 5 above grid
                    printf(" \t\t\t\t\t\t ");
                    for (int i1 = 0; i1 < 2 * m + 1; i1++) {
                        if (i1 == 10 || i1 == 9) { printf("%d", i1 + 1); }
                        else { printf(" %d", i1 + 1); }
                    }
                    printf("\n");

                    //print 1:5 beside the grid and print the grid using %c
                    for (int i2 = 0; i2 < 2 * n + 1; i2++) {
                        if (i2 == 10 || i2 == 9) {
                            printf("\t\t\t\t\t       %d ", i2 + 1);

                            for (int j2 = 0; j2 < 2 * m + 1; j2++) {
                                if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                    printf(yellow"%c "reset, arr2[i2][j2]);

                                } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                    printf(red"%c "reset, arr1[i2][j2]);
                                } else {
                                    printf("%c ", arr[i2][j2]);
                                }
                            }
                            printf("\n");
                        } else {
                            printf("\t\t\t\t\t\t%d ", i2 + 1);

                            for (int j2 = 0; j2 < 2 * m + 1; j2++) {
                                if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                    printf(yellow"%c "reset, arr2[i2][j2]);

                                } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                    printf(red"%c "reset, arr1[i2][j2]);
                                } else {
                                    printf("%c ", arr[i2][j2]);
                                }
                            }
                            printf("\n");
                        }
                    }

                     t=time_s(td1);
                    printf(yellow"\t\t\t\t\t   remaining lines =%d \n"reset, rem);
                    print_inf(p1, "red", p2, "yellow");
                    printf(red"\t\t\t    player %d turn\t\t\t\t"reset yellow"        time=%d:%d:%d \n"reset, 1, t.hour,
                            t.min, t.sec);
                    printf("\n  for undo at any step enter" cyan "\"undo\"" reset);
                    printf("\tfor settings at any step enter" cyan "\"row1: 0 & row2: 0 & col1: 0 & clo2: 0\"\n\n" reset);


                    //ask about move >>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    a2:
                    t1 = time(0);
                    printf("Enter row 1 :");
                    again12:
                    gets(ch);
                    if (isdigit(ch[0])) {
                        {
                            if (atoi(ch) >= 0) { x = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice  : ");
                                goto again12;
                            }
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again12;
                    }
                    a22:
                    printf("\nEnter row 2 :");
                    again22:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a2; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { y = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again22;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again22;
                    }
                    a32:
                    printf("\nEnter col 1 :");
                    again32:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a22; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { z = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again32;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again32;
                    }
                    printf("\nEnter col 2 :");
                    again42:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a32; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { w = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again42;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again42;
                    }


                    if (x == 0 && y == 0 && z == 0 && w == 0) {

                        system("cls");
                        al2:
                        x5 = print_setting();
                        if (x5 == 1) {
                            system("cls");
                            goto az2;
                        } else if (x5 == 2) {
                            system("cls");
                            n12:
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
                                goto n12;
                            }

                            if (y1 == 0) {
                                system("cls");
                                goto by2;
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

                            fprintf_s(f, "mode=%d\n", 1);
                            fprintf_s(f,"turnco=%d\n",turnco);
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
                        } else if (x5 == 4) {    // for go to About ?
                            x3 = about_after_settings();

                            if (x3 == 1) { return 7; }
                            else if (x3 == 2) {
                                system("cls");
                                goto az2;
                            }
                            else if (x3 == 3) { return 8; }


                        } else if (x5 == 5) {
                            return 7; //for main menu

                        } else if (x5 == 6) {

                            return 8; //for exit
                        }

                    }


                    if (x - y > 2 || y - x > 2 || z - w > 2 || w - z > 2) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a2;
                    }
                    if (x != y && z != w) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a2;
                    }
                    if (x == y && z == w) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a2;
                    }
                    t2 = time(0);
                    td1 = difftime(t2, t1) + td1;


                    if (x == y) {
                        if (z > w) {
                            int temp = z;
                            z = w;
                            w = temp;
                        } //swap z&w
                        x = x - 1;
                        if (arr1[x][z] != 205 && arr2[x][z] != 205 && arr[x][z] != 254) {
                            undo[index1] = x;
                            undo[index2] = z;
                            index1 += 2;
                            index2 += 2;
                            arr[x][z] = 205;
                            arr1[x][z] = 205;
                        } else {
                            printf(red"WARNING:"reset" Please choose an empty line\n");
                            goto a2;
                        }
                    }
                    if (z == w) {
                        if (x > y) {
                            int temp = x;
                            x = y;
                            y = temp;
                        } //swap z&w
                        z = z - 1;
                        if (arr1[x][z] != 186 && arr2[x][z] != 186 && arr[x][z] != 254) {
                            undo[index1] = x;
                            undo[index2] = z;
                            index1 += 2;
                            index2 += 2;
                            arr[x][z] = 186;
                            arr1[x][z] = 186;
                        } else {
                            printf(red"WARNING:"reset" Please choose an empty line\n");
                            goto a2;
                        }
                    }
                    inc_moves(&p1);
                    rem--;
                    f1 = 0;
                    for (int k = 0, l = 1; k < 2 * n * m && l < 2 * n * m; k += 2, l += 2) {
                        if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                            if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l] + 1] == 186 &&
                                arr[arrBox[k] - 1][arrBox[l]] == 205 &&
                                arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                arr[arrBox[k]][arrBox[l]] = ch1;
                                arr1[arrBox[k]][arrBox[l]] = ch1;
                                arrBox[k] = 0;
                                arrBox[l] = 0;
                                system("cls");
                                f1 = 1;
                                inc_score(&p1);

                            } else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l] + 1] == 186 &&
                                       arr[box[k] - 1][box[l]] == 205 &&
                                       arr[box[k] + 1][box[l]] == 205) {
                                arr[box[k]][box[l]] = ch1;
                                arr1[box[k]][box[l]] = ch1;
                                box[k] = 0;
                                box[l] = 0;
                                system("cls");
                                f1 = 1;
                                inc_score(&p1);

                            } else { continue; }
                        } else { continue; }
                    }
                    if (f1 == 1) {
                        u--;
                        if (i0 == u) {
                            if (p1.score > p2.score) {
                                top = fopen("top 10 player.text", "a");
                                fprintf_s(top, play_o, co(p1.name), p1.score);  //open file and append struct of winner
                                fclose(top);

                                return end(p1.name, p1.score);
                            } else if (p1.score < p2.score) {
/*
                            top = fopen("top 10 player.text", "a");
                            fprintf_s(top, play_o, co(p2.name), p2.score);  //open file and append struct of winner
                            fclose(top);
*/
                                return end(p2.name, p2.score);
                            } else {
                                return end("draw", p1.score);

                            }
                        }
                        goto az2; //get one additional move as a result of score++
                    }
                    system("cls");
                }

                //===================================================================

                if (i0 % 2 == 1) {
                    ax2 :
                    pc = 0;



                    if (pcCounter %2 ==0){
                    for (int k = 1; k < 2 * n + 1; k += 2) {
                        for (int l = 0; l < 2 * m + 1; l += 2) {
                            if (arr[k][l] != 186) {
                                arr[k][l] = 186;
                                arr2[k][l] = 186;
                                pcCounter++;
                                goto ex22;

                            }
                        }
                    }
                    }

                    for (int k = 0; k < 2 * n + 1; k += 2) {
                        for (int l = 1; l < 2 * m + 1; l += 2) {
                            if (arr[k][l] != 205) {
                                arr[k][l] = 205;
                                arr2[k][l] = 205;
                                pcCounter++;
                                goto ex22;
                            }
                        }
                    }
                    ex22:


                    //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    //print 1 : 5 above grid
                    printf(" \t\t\t\t\t\t ");
                    for (int i5 = 0; i5 < 2 * m + 1; i5++) {
                        if (i5 == 10 || i5 == 9) { printf("%d", i5 + 1); }
                        else { printf(" %d", i5 + 1); }
                    }
                    printf("\n");

                    //print 1:5 beside the grid and print the grid using %c
                    for (int i6 = 0; i6 < 2 * n + 1; i6++) {
                        if (i6 == 9 || i6 == 10) {
                            printf("\t\t\t\t\t       %d ", i6 + 1);

                            for (int j6 = 0; j6 < 2 * m + 1; j6++) {
                                if (arr2[i6][j6] == 205 || arr2[i6][j6] == 186 || arr2[i6][j6] == ch2) {
                                    printf(yellow"%c "reset, arr2[i6][j6]);

                                } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch2) {
                                    printf(red"%c "reset, arr1[i6][j6]);
                                } else {
                                    printf("%c ", arr[i6][j6]);
                                }
                            }
                            printf("\n");
                        } else {
                            printf("\t\t\t\t\t\t%d ", i6 + 1);

                            for (int j6 = 0; j6 < 2 * m + 1; j6++) {
                                if (arr2[i6][j6] == 205 || arr2[i6][j6] == 186 || arr2[i6][j6] == ch2) {
                                    printf(yellow"%c "reset, arr2[i6][j6]);

                                } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch2) {
                                    printf(red"%c "reset, arr1[i6][j6]);
                                } else {
                                    printf("%c ", arr[i6][j6]);
                                }
                            }
                            printf("\n");
                        }
                    }
                    inc_moves(&p2);
                    rem--;
                    f2 = 0;
                    for (int k = 0, l = 1; k < 2 * n * m && l < 2 * n * m; k += 2, l += 2) {
                        if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                            if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l] + 1] == 186 &&
                                arr[arrBox[k] - 1][arrBox[l]] == 205 &&
                                arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                arr[arrBox[k]][arrBox[l]] = ch2;
                                arr2[arrBox[k]][arrBox[l]] = ch2;
                                arrBox[k] = 0;
                                arrBox[l] = 0;
                                system("cls");
                                f2 = 1;
                                inc_score(&p2);

                            } else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l] + 1] == 186 &&
                                       arr[box[k] - 1][box[l]] == 205 &&
                                       arr[box[k] + 1][box[l]] == 205) {
                                arr[box[k]][box[l]] = ch2;
                                arr2[box[k]][box[l]] = ch2;
                                box[k] = 0;
                                box[l] = 0;
                                system("cls");
                                f2 = 1;
                                inc_score(&p2);

                            } else { continue; }
                        } else { continue; }
                    }
                    if (f2 == 1) {
                        u--;
                        if (i0 == u) {
                            if (p1.score > p2.score) {

                                top = fopen("top 10 player.text", "a");
                                fprintf_s(top, play_o, co(p1.name),
                                          p1.score); //open file and append struct of winner
                                fclose(top);

                                return end(p1.name, p1.score);
                            } else if (p1.score < p2.score) {

                                /* top = fopen("top 10 player.text","a");
                             fprintf_s(top,play_o,co(p2.name),p2.score);  //open file and append struct of winner
                             fclose(top);*/

                                return end(p2.name, p2.score);
                            } else {
                                return end("draw", p1.score);

                            }
                        }
                        goto ax2;
                    }
                    system("cls");
                }
            }
        }

        else if (strcmp(colour1, "magenta") == 0 && strcmp(colour2, "yellow") == 0) {


            for (int i0 = 0; i0 < u; i0++) {

                if (i0 % 2 == 0) {//player of color blue
                    az3 :
                    if (fBox == 1 || f2 == 1) {
                        fBox = 0;
                        f2 = 0;
                        goto ax3;
                    }

                    by3:

                    printf(red"\t\t\tnote:"reset"for any misunderstand go to settings then"cyan" About (4)\n"reset);
                    //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    //print 1 : 5 above grid
                    printf(" \t\t\t\t\t\t ");
                    for (int i1 = 0; i1 < 2 * m + 1; i1++) {
                        if (i1 == 10 || i1 == 9) { printf("%d", i1 + 1); }
                        else { printf(" %d", i1 + 1); }
                    }
                    printf("\n");

                    //print 1:5 beside the grid and print the grid using %c
                    for (int i2 = 0; i2 < 2 * n + 1; i2++) {
                        if (i2 == 10 || i2 == 9) {
                            printf("\t\t\t\t\t       %d ", i2 + 1);

                            for (int j2 = 0; j2 < 2 * m + 1; j2++) {
                                if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                    printf(yellow"%c "reset, arr2[i2][j2]);

                                } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                    printf(magenta"%c "reset, arr1[i2][j2]);
                                } else {
                                    printf("%c ", arr[i2][j2]);
                                }
                            }
                            printf("\n");
                        } else {
                            printf("\t\t\t\t\t\t%d ", i2 + 1);

                            for (int j2 = 0; j2 < 2 * m + 1; j2++) {
                                if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                    printf(yellow"%c "reset, arr2[i2][j2]);

                                } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                    printf(magenta"%c "reset, arr1[i2][j2]);
                                } else {
                                    printf("%c ", arr[i2][j2]);
                                }
                            }
                            printf("\n");
                        }
                    }

                    t=time_s(td1);
                    printf(yellow"\t\t\t\t\t   remaining lines =%d \n"reset, rem);
                    print_inf(p1, "magenta", p2, "yellow");
                    printf(magenta"\t\t\t    player %d turn\t\t\t\t"reset yellow"        time=%d:%d:%d \n"reset, 1, t.hour,
                            t.min, t.sec);
                    printf("\n  for undo at any step enter" cyan "\"undo\"" reset);
                    printf("\tfor settings at any step enter" cyan "\"row1: 0 & row2: 0 & col1: 0 & clo2: 0\"\n\n" reset);


                    //ask about move >>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    a3:
                    t1 = time(0);
                    printf("Enter row 1 :");
                    again13:
                    gets(ch);
                    if (isdigit(ch[0])) {
                        {
                            if (atoi(ch) >= 0) { x = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice  : ");
                                goto again13;
                            }
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again13;
                    }
                    a23:
                    printf("\nEnter row 2 :");
                    again23:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a3; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { y = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again23;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again23;
                    }
                    a33:
                    printf("\nEnter col 1 :");
                    again33:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a23; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { z = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again33;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again33;
                    }
                    printf("\nEnter col 2 :");
                    again43:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a33; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { w = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again43;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again43;
                    }


                    if (x == 0 && y == 0 && z == 0 && w == 0) {

                        system("cls");
                        al3:
                        x5 = print_setting();
                        if (x5 == 1) {
                            system("cls");
                            goto az3;
                        } else if (x5 == 2) {
                            system("cls");
                            n13:
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
                                goto n13;
                            }

                            if (y1 == 0) {
                                system("cls");
                                goto by3;
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

                            fprintf_s(f, "mode=%d\n", 1);
                            fprintf_s(f,"turnco=%d\n",turnco);
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
                            goto al3;

                        } else if (x5 == 3) {

                            return 5;//for go to  loud
                        } else if (x5 == 4) {    // for go to About ?
                            x3 = about_after_settings();

                            if (x3 == 1) { return 7; }
                            else if (x3 == 2) {
                                system("cls");
                                goto az3;
                            }
                            else if (x3 == 3) { return 8; }


                        } else if (x5 == 5) {
                            return 7; //for main menu

                        } else if (x5 == 6) {

                            return 8; //for exit
                        }

                    }


                    if (x - y > 2 || y - x > 2 || z - w > 2 || w - z > 2) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a3;
                    }
                    if (x != y && z != w) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a3;
                    }
                    if (x == y && z == w) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a3;
                    }
                    t2 = time(0);
                    td1 = difftime(t2, t1) + td1;


                    if (x == y) {
                        if (z > w) {
                            int temp = z;
                            z = w;
                            w = temp;
                        } //swap z&w
                        x = x - 1;
                        if (arr1[x][z] != 205 && arr2[x][z] != 205 && arr[x][z] != 254) {
                            undo[index1] = x;
                            undo[index2] = z;
                            index1 += 2;
                            index2 += 2;
                            arr[x][z] = 205;
                            arr1[x][z] = 205;
                        } else {
                            printf(red"WARNING:"reset" Please choose an empty line\n");
                            goto a3;
                        }
                    }
                    if (z == w) {
                        if (x > y) {
                            int temp = x;
                            x = y;
                            y = temp;
                        } //swap z&w
                        z = z - 1;
                        if (arr1[x][z] != 186 && arr2[x][z] != 186 && arr[x][z] != 254) {
                            undo[index1] = x;
                            undo[index2] = z;
                            index1 += 2;
                            index2 += 2;
                            arr[x][z] = 186;
                            arr1[x][z] = 186;
                        } else {
                            printf(red"WARNING:"reset" Please choose an empty line\n");
                            goto a3;
                        }
                    }
                    inc_moves(&p1);
                    rem--;
                    f1 = 0;
                    for (int k = 0, l = 1; k < 2 * n * m && l < 2 * n * m; k += 2, l += 2) {
                        if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                            if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l] + 1] == 186 &&
                                arr[arrBox[k] - 1][arrBox[l]] == 205 &&
                                arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                arr[arrBox[k]][arrBox[l]] = ch1;
                                arr1[arrBox[k]][arrBox[l]] = ch1;
                                arrBox[k] = 0;
                                arrBox[l] = 0;
                                system("cls");
                                f1 = 1;
                                inc_score(&p1);

                            } else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l] + 1] == 186 &&
                                       arr[box[k] - 1][box[l]] == 205 &&
                                       arr[box[k] + 1][box[l]] == 205) {
                                arr[box[k]][box[l]] = ch1;
                                arr1[box[k]][box[l]] = ch1;
                                box[k] = 0;
                                box[l] = 0;
                                system("cls");
                                f1 = 1;
                                inc_score(&p1);

                            } else { continue; }
                        } else { continue; }
                    }
                    if (f1 == 1) {
                        u--;
                        if (i0 == u) {
                            if (p1.score > p2.score) {
                                top = fopen("top 10 player.text", "a");
                                fprintf_s(top, play_o, co(p1.name), p1.score);  //open file and append struct of winner
                                fclose(top);

                                return end(p1.name, p1.score);
                            } else if (p1.score < p2.score) {
/*
                            top = fopen("top 10 player.text", "a");
                            fprintf_s(top, play_o, co(p2.name), p2.score);  //open file and append struct of winner
                            fclose(top);
*/
                                return end(p2.name, p2.score);
                            } else {
                                return end("draw", p1.score);

                            }
                        }
                        goto az3; //get one additional move as a result of score++
                    }
                    system("cls");
                }

                //===================================================================

                if (i0 % 2 == 1) {
                    ax3 :
                    pc = 0;



                    if (pcCounter %2 ==0){
                    for (int k = 1; k < 2 * n + 1; k += 2) {
                        for (int l = 0; l < 2 * m + 1; l += 2) {
                            if (arr[k][l] != 186) {
                                arr[k][l] = 186;
                                arr2[k][l] = 186;
                                pcCounter++;
                                goto ex23;

                            }
                        }
                    }
                    }

                    for (int k = 0; k < 2 * n + 1; k += 2) {
                        for (int l = 1; l < 2 * m + 1; l += 2) {
                            if (arr[k][l] != 205) {
                                arr[k][l] = 205;
                                arr2[k][l] = 205;
                                pcCounter++;
                                goto ex23;
                            }
                        }
                    }
                    ex23:


                    //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    //print 1 : 5 above grid
                    printf(" \t\t\t\t\t\t ");
                    for (int i5 = 0; i5 < 2 * m + 1; i5++) {
                        if (i5 == 10 || i5 == 9) { printf("%d", i5 + 1); }
                        else { printf(" %d", i5 + 1); }
                    }
                    printf("\n");

                    //print 1:5 beside the grid and print the grid using %c
                    for (int i6 = 0; i6 < 2 * n + 1; i6++) {
                        if (i6 == 9 || i6 == 10) {
                            printf("\t\t\t\t\t       %d ", i6 + 1);

                            for (int j6 = 0; j6 < 2 * m + 1; j6++) {
                                if (arr2[i6][j6] == 205 || arr2[i6][j6] == 186 || arr2[i6][j6] == ch2) {
                                    printf(yellow"%c "reset, arr2[i6][j6]);

                                } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch2) {
                                    printf(magenta"%c "reset, arr1[i6][j6]);
                                } else {
                                    printf("%c ", arr[i6][j6]);
                                }
                            }
                            printf("\n");
                        } else {
                            printf("\t\t\t\t\t\t%d ", i6 + 1);

                            for (int j6 = 0; j6 < 2 * m + 1; j6++) {
                                if (arr2[i6][j6] == 205 || arr2[i6][j6] == 186 || arr2[i6][j6] == ch2) {
                                    printf(yellow"%c "reset, arr2[i6][j6]);

                                } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch2) {
                                    printf(magenta"%c "reset, arr1[i6][j6]);
                                } else {
                                    printf("%c ", arr[i6][j6]);
                                }
                            }
                            printf("\n");
                        }
                    }
                    inc_moves(&p2);
                    rem--;
                    f2 = 0;
                    for (int k = 0, l = 1; k < 2 * n * m && l < 2 * n * m; k += 2, l += 2) {
                        if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                            if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l] + 1] == 186 &&
                                arr[arrBox[k] - 1][arrBox[l]] == 205 &&
                                arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                arr[arrBox[k]][arrBox[l]] = ch2;
                                arr2[arrBox[k]][arrBox[l]] = ch2;
                                arrBox[k] = 0;
                                arrBox[l] = 0;
                                system("cls");
                                f2 = 1;
                                inc_score(&p2);

                            } else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l] + 1] == 186 &&
                                       arr[box[k] - 1][box[l]] == 205 &&
                                       arr[box[k] + 1][box[l]] == 205) {
                                arr[box[k]][box[l]] = ch2;
                                arr2[box[k]][box[l]] = ch2;
                                box[k] = 0;
                                box[l] = 0;
                                system("cls");
                                f2 = 1;
                                inc_score(&p2);

                            } else { continue; }
                        } else { continue; }
                    }
                    if (f2 == 1) {
                        u--;
                        if (i0 == u) {
                            if (p1.score > p2.score) {

                                top = fopen("top 10 player.text", "a");
                                fprintf_s(top, play_o, co(p1.name),
                                          p1.score); //open file and append struct of winner
                                fclose(top);

                                return end(p1.name, p1.score);
                            } else if (p1.score < p2.score) {

                                /* top = fopen("top 10 player.text","a");
                             fprintf_s(top,play_o,co(p2.name),p2.score);  //open file and append struct of winner
                             fclose(top);*/

                                return end(p2.name, p2.score);
                            } else {
                                return end("draw", p1.score);

                            }
                        }
                        goto ax3;
                    }
                    system("cls");
                }
            }
        }

        else if (strcmp(colour1, "green") == 0 && strcmp(colour2, "yellow") == 0) {


            for (int i0 = 0; i0 < u; i0++) {

                if (i0 % 2 == 0) {//player of color blue
                    az4 :
                    if (fBox == 1 || f2 == 1) {
                        fBox = 0;
                        f2 = 0;
                        goto ax4;
                    }

                    by4:

                    printf(red"\t\t\tnote:"reset"for any misunderstand go to settings then"cyan" About (4)\n"reset);
                    //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    //print 1 : 5 above grid
                    printf(" \t\t\t\t\t\t ");
                    for (int i1 = 0; i1 < 2 * m + 1; i1++) {
                        if (i1 == 10 || i1 == 9) { printf("%d", i1 + 1); }
                        else { printf(" %d", i1 + 1); }
                    }
                    printf("\n");

                    //print 1:5 beside the grid and print the grid using %c
                    for (int i2 = 0; i2 < 2 * n + 1; i2++) {
                        if (i2 == 10 || i2 == 9) {
                            printf("\t\t\t\t\t       %d ", i2 + 1);

                            for (int j2 = 0; j2 < 2 * m + 1; j2++) {
                                if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                    printf(yellow"%c "reset, arr2[i2][j2]);

                                } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                    printf(green"%c "reset, arr1[i2][j2]);
                                } else {
                                    printf("%c ", arr[i2][j2]);
                                }
                            }
                            printf("\n");
                        } else {
                            printf("\t\t\t\t\t\t%d ", i2 + 1);

                            for (int j2 = 0; j2 < 2 * m + 1; j2++) {
                                if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                    printf(yellow"%c "reset, arr2[i2][j2]);

                                } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                    printf(green"%c "reset, arr1[i2][j2]);
                                } else {
                                    printf("%c ", arr[i2][j2]);
                                }
                            }
                            printf("\n");
                        }
                    }

                     t=time_s(td1);
                    printf(yellow"\t\t\t\t\t   remaining lines =%d \n"reset, rem);
                    print_inf(p1, "green", p2, "yellow");
                    printf(green"\t\t\t    player %d turn\t\t\t\t"reset yellow"        time=%d:%d:%d \n"reset, 1, t.hour,
                            t.min, t.sec);
                    printf("\n  for undo at any step enter" cyan "\"undo\"" reset);
                    printf("\tfor settings at any step enter" cyan "\"row1: 0 & row2: 0 & col1: 0 & clo2: 0\"\n\n" reset);


                    //ask about move >>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    a4:
                    t1 = time(0);
                    printf("Enter row 1 :");
                    again14:
                    gets(ch);
                    if (isdigit(ch[0])) {
                        {
                            if (atoi(ch) >= 0) { x = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice  : ");
                                goto again14;
                            }
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again14;
                    }
                    a24:
                    printf("\nEnter row 2 :");
                    again24:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a4; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { y = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again24;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again24;
                    }
                    a44:
                    printf("\nEnter col 1 :");
                    again34:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a24; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { z = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again34;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again34;
                    }
                    printf("\nEnter col 2 :");
                    again44:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a44; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { w = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again44;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again44;
                    }


                    if (x == 0 && y == 0 && z == 0 && w == 0) {

                        system("cls");
                        al4:
                        x5 = print_setting();
                        if (x5 == 1) {
                            system("cls");
                            goto az4;
                        } else if (x5 == 2) {
                            system("cls");
                            n14:
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
                                goto n14;
                            }

                            if (y1 == 0) {
                                system("cls");
                                goto by4;
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

                            fprintf_s(f, "mode=%d\n", 1);
                            fprintf_s(f,"turnco=%d\n",turnco);
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
                            goto al4;

                        } else if (x5 == 3) {

                            return 5;//for go to  loud
                        } else if (x5 == 4) {    // for go to About ?
                            x3 = about_after_settings();

                            if (x3 == 1) { return 7; }
                            else if (x3 == 2) {
                                system("cls");
                                goto az4;
                            }
                            else if (x3 == 3) { return 8; }


                        } else if (x5 == 5) {
                            return 7; //for main menu

                        } else if (x5 == 6) {

                            return 8; //for exit
                        }

                    }


                    if (x - y > 2 || y - x > 2 || z - w > 2 || w - z > 2) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a4;
                    }
                    if (x != y && z != w) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a4;
                    }
                    if (x == y && z == w) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a4;
                    }
                    t2 = time(0);
                    td1 = difftime(t2, t1) + td1;


                    if (x == y) {
                        if (z > w) {
                            int temp = z;
                            z = w;
                            w = temp;
                        } //swap z&w
                        x = x - 1;
                        if (arr1[x][z] != 205 && arr2[x][z] != 205 && arr[x][z] != 254) {
                            undo[index1] = x;
                            undo[index2] = z;
                            index1 += 2;
                            index2 += 2;
                            arr[x][z] = 205;
                            arr1[x][z] = 205;
                        } else {
                            printf(red"WARNING:"reset" Please choose an empty line\n");
                            goto a4;
                        }
                    }
                    if (z == w) {
                        if (x > y) {
                            int temp = x;
                            x = y;
                            y = temp;
                        } //swap z&w
                        z = z - 1;
                        if (arr1[x][z] != 186 && arr2[x][z] != 186 && arr[x][z] != 254) {
                            undo[index1] = x;
                            undo[index2] = z;
                            index1 += 2;
                            index2 += 2;
                            arr[x][z] = 186;
                            arr1[x][z] = 186;
                        } else {
                            printf(red"WARNING:"reset" Please choose an empty line\n");
                            goto a4;
                        }
                    }
                    inc_moves(&p1);
                    rem--;
                    f1 = 0;
                    for (int k = 0, l = 1; k < 2 * n * m && l < 2 * n * m; k += 2, l += 2) {
                        if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                            if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l] + 1] == 186 &&
                                arr[arrBox[k] - 1][arrBox[l]] == 205 &&
                                arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                arr[arrBox[k]][arrBox[l]] = ch1;
                                arr1[arrBox[k]][arrBox[l]] = ch1;
                                arrBox[k] = 0;
                                arrBox[l] = 0;
                                system("cls");
                                f1 = 1;
                                inc_score(&p1);

                            } else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l] + 1] == 186 &&
                                       arr[box[k] - 1][box[l]] == 205 &&
                                       arr[box[k] + 1][box[l]] == 205) {
                                arr[box[k]][box[l]] = ch1;
                                arr1[box[k]][box[l]] = ch1;
                                box[k] = 0;
                                box[l] = 0;
                                system("cls");
                                f1 = 1;
                                inc_score(&p1);

                            } else { continue; }
                        } else { continue; }
                    }
                    if (f1 == 1) {
                        u--;
                        if (i0 == u) {
                            if (p1.score > p2.score) {
                                top = fopen("top 10 player.text", "a");
                                fprintf_s(top, play_o, co(p1.name), p1.score);  //open file and append struct of winner
                                fclose(top);

                                return end(p1.name, p1.score);
                            } else if (p1.score < p2.score) {
/*
                            top = fopen("top 10 player.text", "a");
                            fprintf_s(top, play_o, co(p2.name), p2.score);  //open file and append struct of winner
                            fclose(top);
*/
                                return end(p2.name, p2.score);
                            } else {
                                return end("draw", p1.score);

                            }
                        }
                        goto az4; //get one additional move as a result of score++
                    }
                    system("cls");
                }

                //===================================================================

                if (i0 % 2 == 1) {
                    ax4 :
                    pc = 0;




                    if (pcCounter %2 ==0){
                    for (int k = 1; k < 2 * n + 1; k += 2) {
                        for (int l = 0; l < 2 * m + 1; l += 2) {
                            if (arr[k][l] != 186) {
                                arr[k][l] = 186;
                                arr2[k][l] = 186;
                                pcCounter++;
                                goto ex24;

                            }
                        }
                    }
                    }

                    for (int k = 0; k < 2 * n + 1; k += 2) {
                        for (int l = 1; l < 2 * m + 1; l += 2) {
                            if (arr[k][l] != 205) {
                                arr[k][l] = 205;
                                arr2[k][l] = 205;
                                pcCounter++;
                                goto ex24;
                            }
                        }
                    }
                    ex24:


                    //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    //print 1 : 5 above grid
                    printf(" \t\t\t\t\t\t ");
                    for (int i5 = 0; i5 < 2 * m + 1; i5++) {
                        if (i5 == 10 || i5 == 9) { printf("%d", i5 + 1); }
                        else { printf(" %d", i5 + 1); }
                    }
                    printf("\n");

                    //print 1:5 beside the grid and print the grid using %c
                    for (int i6 = 0; i6 < 2 * n + 1; i6++) {
                        if (i6 == 9 || i6 == 10) {
                            printf("\t\t\t\t\t       %d ", i6 + 1);

                            for (int j6 = 0; j6 < 2 * m + 1; j6++) {
                                if (arr2[i6][j6] == 205 || arr2[i6][j6] == 186 || arr2[i6][j6] == ch2) {
                                    printf(yellow"%c "reset, arr2[i6][j6]);

                                } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch2) {
                                    printf(green"%c "reset, arr1[i6][j6]);
                                } else {
                                    printf("%c ", arr[i6][j6]);
                                }
                            }
                            printf("\n");
                        } else {
                            printf("\t\t\t\t\t\t%d ", i6 + 1);

                            for (int j6 = 0; j6 < 2 * m + 1; j6++) {
                                if (arr2[i6][j6] == 205 || arr2[i6][j6] == 186 || arr2[i6][j6] == ch2) {
                                    printf(yellow"%c "reset, arr2[i6][j6]);

                                } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch2) {
                                    printf(green"%c "reset, arr1[i6][j6]);
                                } else {
                                    printf("%c ", arr[i6][j6]);
                                }
                            }
                            printf("\n");
                        }
                    }
                    inc_moves(&p2);
                    rem--;
                    f2 = 0;
                    for (int k = 0, l = 1; k < 2 * n * m && l < 2 * n * m; k += 2, l += 2) {
                        if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                            if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l] + 1] == 186 &&
                                arr[arrBox[k] - 1][arrBox[l]] == 205 &&
                                arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                arr[arrBox[k]][arrBox[l]] = ch2;
                                arr2[arrBox[k]][arrBox[l]] = ch2;
                                arrBox[k] = 0;
                                arrBox[l] = 0;
                                system("cls");
                                f2 = 1;
                                inc_score(&p2);

                            } else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l] + 1] == 186 &&
                                       arr[box[k] - 1][box[l]] == 205 &&
                                       arr[box[k] + 1][box[l]] == 205) {
                                arr[box[k]][box[l]] = ch2;
                                arr2[box[k]][box[l]] = ch2;
                                box[k] = 0;
                                box[l] = 0;
                                system("cls");
                                f2 = 1;
                                inc_score(&p2);

                            } else { continue; }
                        } else { continue; }
                    }
                    if (f2 == 1) {
                        u--;
                        if (i0 == u) {
                            if (p1.score > p2.score) {

                                top = fopen("top 10 player.text", "a");
                                fprintf_s(top, play_o, co(p1.name),
                                          p1.score); //open file and append struct of winner
                                fclose(top);

                                return end(p1.name, p1.score);
                            } else if (p1.score < p2.score) {

                                /* top = fopen("top 10 player.text","a");
                             fprintf_s(top,play_o,co(p2.name),p2.score);  //open file and append struct of winner
                             fclose(top);*/

                                return end(p2.name, p2.score);
                            } else {
                                return end("draw", p1.score);

                            }
                        }
                        goto ax4;
                    }
                    system("cls");
                }
            }
        }

    }






    else if(turnco==1){

        time_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;
        times t;
        FILE *f, *top;
        int y1, x5, td1 = 0;
        char qq[20];
        system(" ");


        int arr[2 * n + 1][2 * m + 1], arr1[2 * n + 1][2 * m + 1], arr2[2 * n + 1][2 * m + 1];

        //definition of array that has the addresses of undo and redo moves to remove lines
        int no_UN_RE = 2 * ((2 * (n * m)) + (n) + (m));
        int no_box = 2 * n * m;
        int box[50] = {0};
        int undo[no_UN_RE], redo[no_UN_RE];
        for (int c = 0; c < no_UN_RE; c++) {
            undo[c] = 0;
            redo[c] = 0;
        }
        //for(int c=0 ; c<no_box ; c++){box[c]=0 ;}
        //definition of array that has the addresses of boxes
        int arrBox[2 * n * m];
        int count = 0;
        for (int k = 1; k < 2 * n + 1; k += 2) {
            for (int l = 1; l < 2 * m + 1; l += 2) {
                arrBox[count++] = k;
                arrBox[count++] = l;
            }
        }
        for (int c = count; c < 50; c++) { arrBox[c] = 0; }

        //undo for boxes
        int undoArrBox[2 * n * m];
        int count0 = 0;
        for (int k = 1; k < 2 * n + 1; k += 2) {
            for (int l = 1; l < 2 * m + 1; l += 2) {
                undoArrBox[count0++] = k;
                undoArrBox[count0++] = l;
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
        int pcCounter = 0;
        int f2 = 0, f1 = 0;
        int fBox = 0;
        int index1 = 0, index2 = 1, cs;
        char ch[10];
        int x, y, z, w;
        int u = (2 * (n * m)) + (n) + (m);
        // // // //
        int pc;
        int rem, x3;
        rem = u;



        if (strcmp(colour1, "blue") == 0 && strcmp(colour2, "yellow") == 0)     {


            for (int i0 = 0; i0 < u; i0++) {

                if (i0 % 2 == 1) {
                    az5 :
                    if (fBox == 1 || f2 == 1) {
                        fBox = 0;
                        f2 = 0;
                        goto ax5;
                    }

                    by5:

                    printf(red"\t\t\tnote:"reset"for any misunderstand go to settings then"cyan" About (4)\n"reset);
                    //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    //print 1 : 5 above grid
                    printf(" \t\t\t\t\t\t ");
                    for (int i1 = 0; i1 < 2 * m + 1; i1++) {
                        if (i1 == 10 || i1 == 9) { printf("%d", i1 + 1); }
                        else { printf(" %d", i1 + 1); }
                    }
                    printf("\n");

                    //print 1:5 beside the grid and print the grid using %c
                    for (int i2 = 0; i2 < 2 * n + 1; i2++) {
                        if (i2 == 10 || i2 == 9) {
                            printf("\t\t\t\t\t       %d ", i2 + 1);

                            for (int j2 = 0; j2 < 2 * m + 1; j2++) {
                                if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                    printf(yellow"%c "reset, arr2[i2][j2]);

                                } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                    printf(blue"%c "reset, arr1[i2][j2]);
                                } else {
                                    printf("%c ", arr[i2][j2]);
                                }
                            }
                            printf("\n");
                        } else {
                            printf("\t\t\t\t\t\t%d ", i2 + 1);

                            for (int j2 = 0; j2 < 2 * m + 1; j2++) {
                                if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                    printf(yellow"%c "reset, arr2[i2][j2]);

                                } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                    printf(blue"%c "reset, arr1[i2][j2]);
                                } else {
                                    printf("%c ", arr[i2][j2]);
                                }
                            }
                            printf("\n");
                        }
                    }

                     t=time_s(td1);
                    printf(yellow"\t\t\t\t\t   remaining lines =%d \n"reset, rem);
                    print_inf(p2, "yellow", p1, "blue");
                    printf(blue"\t\t\t    player %d turn\t\t\t\t"reset yellow"        time=%d:%d:%d \n"reset, 2, t.hour,
                            t.min, t.sec);
                    printf("\n  for undo at any step enter" cyan "\"undo\"" reset);
                    printf("\tfor settings at any step enter" cyan "\"row1: 0 & row2: 0 & col1: 0 & clo2: 0\"\n\n" reset);


                    //ask about move >>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    a5:
                    t1 = time(0);
                    printf("Enter row 1 :");
                    again15:
                    gets(ch);
                    if (isdigit(ch[0])) {
                        {
                            if (atoi(ch) >= 0) { x = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice  : ");
                                goto again15;
                            }
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again15;
                    }
                    a25:
                    printf("\nEnter row 2 :");
                    again25:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a5; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { y = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again25;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again25;
                    }
                    a35:
                    printf("\nEnter col 1 :");
                    again35:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a25; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { z = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again35;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again35;
                    }
                    printf("\nEnter col 2 :");
                    again45:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a35; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { w = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again45;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again45;
                    }


                    if (x == 0 && y == 0 && z == 0 && w == 0) {

                        system("cls");
                        al5:
                        x5 = print_setting();
                        if (x5 == 1) {
                            system("cls");
                            goto az5;
                        } else if (x5 == 2) {
                            system("cls");
                            n15:
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
                                goto n15;
                            }

                            if (y1 == 0) {
                                system("cls");
                                goto az5;
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

                            fprintf_s(f, "mode=%d\n", 1);
                            fprintf_s(f,"turnco=%d\n",turnco);
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
                            goto al5;

                        } else if (x5 == 3) {

                            return 5;//for go to  loud
                        } else if (x5 == 4) {    // for go to About ?
                            x3 = about_after_settings();

                            if (x3 == 1) { return 7; }
                            else if (x3 == 2) {
                                system("cls");
                                goto az5;
                            }
                            else if (x3 == 3) { return 8; }


                        } else if (x5 == 5) {
                            return 7; //for main menu

                        } else if (x5 == 6) {

                            return 8; //for exit
                        }

                    }


                    if (x - y > 2 || y - x > 2 || z - w > 2 || w - z > 2) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a5;
                    }
                    if (x != y && z != w) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a5;
                    }
                    if (x == y && z == w) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a5;
                    }
                    t2 = time(0);
                    td1 = difftime(t2, t1) + td1;


                    if (x == y) {
                        if (z > w) {
                            int temp = z;
                            z = w;
                            w = temp;
                        } //swap z&w
                        x = x - 1;
                        if (arr1[x][z] != 205 && arr2[x][z] != 205 && arr[x][z] != 254) {
                            undo[index1] = x;
                            undo[index2] = z;
                            index1 += 2;
                            index2 += 2;
                            arr[x][z] = 205;
                            arr1[x][z] = 205;
                        } else {
                            printf(red"WARNING:"reset" Please choose an empty line\n");
                            goto a5;
                        }
                    }
                    if (z == w) {
                        if (x > y) {
                            int temp = x;
                            x = y;
                            y = temp;
                        } //swap z&w
                        z = z - 1;
                        if (arr1[x][z] != 186 && arr2[x][z] != 186 && arr[x][z] != 254) {
                            undo[index1] = x;
                            undo[index2] = z;
                            index1 += 2;
                            index2 += 2;
                            arr[x][z] = 186;
                            arr1[x][z] = 186;
                        } else {
                            printf(red"WARNING:"reset" Please choose an empty line\n");
                            goto a5;
                        }
                    }
                    inc_moves(&p1);
                    rem--;
                    f1 = 0;
                    for (int k = 0, l = 1; k < 2 * n * m && l < 2 * n * m; k += 2, l += 2) {
                        if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                            if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l] + 1] == 186 &&
                                arr[arrBox[k] - 1][arrBox[l]] == 205 &&
                                arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                arr[arrBox[k]][arrBox[l]] = ch1;
                                arr1[arrBox[k]][arrBox[l]] = ch1;
                                arrBox[k] = 0;
                                arrBox[l] = 0;
                                system("cls");
                                f1 = 1;
                                inc_score(&p1);

                            } else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l] + 1] == 186 &&
                                       arr[box[k] - 1][box[l]] == 205 &&
                                       arr[box[k] + 1][box[l]] == 205) {
                                arr[box[k]][box[l]] = ch1;
                                arr1[box[k]][box[l]] = ch1;
                                box[k] = 0;
                                box[l] = 0;
                                system("cls");
                                f1 = 1;
                                inc_score(&p1);

                            } else { continue; }
                        } else { continue; }
                    }
                    if (f1 == 1) {
                        u--;
                        if (i0 == u) {
                            if (p1.score > p2.score) {
                                top = fopen("top 10 player.text", "a");
                                fprintf_s(top, play_o, co(p1.name), p1.score);  //open file and append struct of winner
                                fclose(top);

                                return end(p1.name, p1.score);
                            } else if (p1.score < p2.score) {
/*
                            top = fopen("top 10 player.text", "a");
                            fprintf_s(top, play_o, co(p2.name), p2.score);  //open file and append struct of winner
                            fclose(top);
*/
                                return end(p2.name, p2.score);
                            } else {
                                return end("draw", p1.score);

                            }
                        }
                        goto az5; //get one additional move as a result of score++
                    }
                    system("cls");
                }

                //===================================================================

                if (i0 % 2 == 0) {
                    ax5 :
                    pc = 0;



                    if (pcCounter %2 ==0){
                    for (int k = 1; k < 2 * n + 1; k += 2) {
                        for (int l = 0; l < 2 * m + 1; l += 2) {
                            if (arr[k][l] != 186) {
                                arr[k][l] = 186;
                                arr2[k][l] = 186;
                                pcCounter++;
                                goto ex25;

                            }
                        }
                    }
                    }

                    for (int k = 0; k < 2 * n + 1; k += 2) {
                        for (int l = 1; l < 2 * m + 1; l += 2) {
                            if (arr[k][l] != 205) {
                                arr[k][l] = 205;
                                arr2[k][l] = 205;
                                pcCounter++;
                                goto ex25;
                            }
                        }
                    }
                    ex25:


                    //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    //print 1 : 5 above grid
                    printf(" \t\t\t\t\t\t ");
                    for (int i5 = 0; i5 < 2 * m + 1; i5++) {
                        if (i5 == 10 || i5 == 9) { printf("%d", i5 + 1); }
                        else { printf(" %d", i5 + 1); }
                    }
                    printf("\n");

                    //print 1:5 beside the grid and print the grid using %c
                    for (int i6 = 0; i6 < 2 * n + 1; i6++) {
                        if (i6 == 9 || i6 == 10) {
                            printf("\t\t\t\t\t       %d ", i6 + 1);

                            for (int j6 = 0; j6 < 2 * m + 1; j6++) {
                                if (arr2[i6][j6] == 205 || arr2[i6][j6] == 186 || arr2[i6][j6] == ch2) {
                                    printf(yellow"%c "reset, arr2[i6][j6]);

                                } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch2) {
                                    printf(blue"%c "reset, arr1[i6][j6]);
                                } else {
                                    printf("%c ", arr[i6][j6]);
                                }
                            }
                            printf("\n");
                        } else {
                            printf("\t\t\t\t\t\t%d ", i6 + 1);

                            for (int j6 = 0; j6 < 2 * m + 1; j6++) {
                                if (arr2[i6][j6] == 205 || arr2[i6][j6] == 186 || arr2[i6][j6] == ch2) {
                                    printf(yellow"%c "reset, arr2[i6][j6]);

                                } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch2) {
                                    printf(blue"%c "reset, arr1[i6][j6]);
                                } else {
                                    printf("%c ", arr[i6][j6]);
                                }
                            }
                            printf("\n");
                        }
                    }
                    inc_moves(&p2);
                    rem--;
                    f2 = 0;
                    for (int k = 0, l = 1; k < 2 * n * m && l < 2 * n * m; k += 2, l += 2) {
                        if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                            if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l] + 1] == 186 &&
                                arr[arrBox[k] - 1][arrBox[l]] == 205 &&
                                arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                arr[arrBox[k]][arrBox[l]] = ch2;
                                arr2[arrBox[k]][arrBox[l]] = ch2;
                                arrBox[k] = 0;
                                arrBox[l] = 0;
                                system("cls");
                                f2 = 1;
                                inc_score(&p2);

                            } else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l] + 1] == 186 &&
                                       arr[box[k] - 1][box[l]] == 205 &&
                                       arr[box[k] + 1][box[l]] == 205) {
                                arr[box[k]][box[l]] = ch2;
                                arr2[box[k]][box[l]] = ch2;
                                box[k] = 0;
                                box[l] = 0;
                                system("cls");
                                f2 = 1;
                                inc_score(&p2);

                            } else { continue; }
                        } else { continue; }
                    }
                    if (f2 == 1) {
                        u--;
                        if (i0 == u) {
                            if (p1.score > p2.score) {

                                top = fopen("top 10 player.text", "a");
                                fprintf_s(top, play_o, co(p1.name),
                                          p1.score); //open file and append struct of winner
                                fclose(top);

                                return end(p1.name, p1.score);
                            } else if (p1.score < p2.score) {

                                /* top = fopen("top 10 player.text","a");
                             fprintf_s(top,play_o,co(p2.name),p2.score);  //open file and append struct of winner
                             fclose(top);*/

                                return end(p2.name, p2.score);
                            } else {
                                return end("draw", p1.score);

                            }
                        }
                        goto ax5;
                    }
                    system("cls");
                }
            }
        }

        else if (strcmp(colour1, "green") == 0 && strcmp(colour2, "yellow") == 0)     {


            for (int i0 = 0; i0 < u; i0++) {

                if (i0 % 2 == 1) {
                    az6 :
                    if (fBox == 1 || f2 == 1) {
                        fBox = 0;
                        f2 = 0;
                        goto ax6;
                    }

                    by6:

                    printf(red"\t\t\tnote:"reset"for any misunderstand go to settings then"cyan" About (4)\n"reset);
                    //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    //print 1 : 5 above grid
                    printf(" \t\t\t\t\t\t ");
                    for (int i1 = 0; i1 < 2 * m + 1; i1++) {
                        if (i1 == 10 || i1 == 9) { printf("%d", i1 + 1); }
                        else { printf(" %d", i1 + 1); }
                    }
                    printf("\n");

                    //print 1:5 beside the grid and print the grid using %c
                    for (int i2 = 0; i2 < 2 * n + 1; i2++) {
                        if (i2 == 10 || i2 == 9) {
                            printf("\t\t\t\t\t       %d ", i2 + 1);

                            for (int j2 = 0; j2 < 2 * m + 1; j2++) {
                                if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                    printf(yellow"%c "reset, arr2[i2][j2]);

                                } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                    printf(green"%c "reset, arr1[i2][j2]);
                                } else {
                                    printf("%c ", arr[i2][j2]);
                                }
                            }
                            printf("\n");
                        } else {
                            printf("\t\t\t\t\t\t%d ", i2 + 1);

                            for (int j2 = 0; j2 < 2 * m + 1; j2++) {
                                if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                    printf(yellow"%c "reset, arr2[i2][j2]);

                                } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                    printf(green"%c "reset, arr1[i2][j2]);
                                } else {
                                    printf("%c ", arr[i2][j2]);
                                }
                            }
                            printf("\n");
                        }
                    }

                     t=time_s(td1);
                    printf(yellow"\t\t\t\t\t   remaining lines =%d \n"reset, rem);
                    print_inf(p2, "yellow", p1, "green");
                    printf(green"\t\t\t    player %d turn\t\t\t\t"reset yellow"        time=%d:%d:%d \n"reset, 2, t.hour,
                            t.min, t.sec);
                    printf("\n  for undo at any step enter" cyan "\"undo\"" reset);
                    printf("\tfor settings at any step enter" cyan "\"row1: 0 & row2: 0 & col1: 0 & clo2: 0\"\n\n" reset);


                    //ask about move >>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    a6:
                    t1 = time(0);
                    printf("Enter row 1 :");
                    again16:
                    gets(ch);
                    if (isdigit(ch[0])) {
                        {
                            if (atoi(ch) >= 0) { x = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice  : ");
                                goto again16;
                            }
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again16;
                    }
                    a26:
                    printf("\nEnter row 2 :");
                    again26:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a6; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { y = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again26;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again26;
                    }
                    a36:
                    printf("\nEnter col 1 :");
                    again36:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a26; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { z = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again36;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again36;
                    }
                    printf("\nEnter col 2 :");
                    again46:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a36; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { w = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again46;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again46;
                    }


                    if (x == 0 && y == 0 && z == 0 && w == 0) {

                        system("cls");
                        al6:
                        x5 = print_setting();
                        if (x5 == 1) {
                            system("cls");
                            goto az6;
                        } else if (x5 == 2) {
                            system("cls");
                            n16:
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
                                goto n16;
                            }

                            if (y1 == 0) {
                                system("cls");
                                goto az6;
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

                            fprintf_s(f, "mode=%d\n", 1);
                            fprintf_s(f,"turnco=%d\n",turnco);
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
                            goto al6;

                        } else if (x5 == 3) {

                            return 5;//for go to  loud
                        } else if (x5 == 4) {    // for go to About ?
                            x3 = about_after_settings();

                            if (x3 == 1) { return 7; }
                            else if (x3 == 2) {
                                system("cls");
                                goto az6;
                            }
                            else if (x3 == 3) { return 8; }


                        } else if (x5 == 5) {
                            return 7; //for main menu

                        } else if (x5 == 6) {

                            return 8; //for exit
                        }

                    }


                    if (x - y > 2 || y - x > 2 || z - w > 2 || w - z > 2) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a6;
                    }
                    if (x != y && z != w) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a6;
                    }
                    if (x == y && z == w) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a6;
                    }
                    t2 = time(0);
                    td1 = difftime(t2, t1) + td1;


                    if (x == y) {
                        if (z > w) {
                            int temp = z;
                            z = w;
                            w = temp;
                        } //swap z&w
                        x = x - 1;
                        if (arr1[x][z] != 205 && arr2[x][z] != 205 && arr[x][z] != 254) {
                            undo[index1] = x;
                            undo[index2] = z;
                            index1 += 2;
                            index2 += 2;
                            arr[x][z] = 205;
                            arr1[x][z] = 205;
                        } else {
                            printf(red"WARNING:"reset" Please choose an empty line\n");
                            goto a6;
                        }
                    }
                    if (z == w) {
                        if (x > y) {
                            int temp = x;
                            x = y;
                            y = temp;
                        } //swap z&w
                        z = z - 1;
                        if (arr1[x][z] != 186 && arr2[x][z] != 186 && arr[x][z] != 254) {
                            undo[index1] = x;
                            undo[index2] = z;
                            index1 += 2;
                            index2 += 2;
                            arr[x][z] = 186;
                            arr1[x][z] = 186;
                        } else {
                            printf(red"WARNING:"reset" Please choose an empty line\n");
                            goto a6;
                        }
                    }
                    inc_moves(&p1);
                    rem--;
                    f1 = 0;
                    for (int k = 0, l = 1; k < 2 * n * m && l < 2 * n * m; k += 2, l += 2) {
                        if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                            if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l] + 1] == 186 &&
                                arr[arrBox[k] - 1][arrBox[l]] == 205 &&
                                arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                arr[arrBox[k]][arrBox[l]] = ch1;
                                arr1[arrBox[k]][arrBox[l]] = ch1;
                                arrBox[k] = 0;
                                arrBox[l] = 0;
                                system("cls");
                                f1 = 1;
                                inc_score(&p1);

                            } else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l] + 1] == 186 &&
                                       arr[box[k] - 1][box[l]] == 205 &&
                                       arr[box[k] + 1][box[l]] == 205) {
                                arr[box[k]][box[l]] = ch1;
                                arr1[box[k]][box[l]] = ch1;
                                box[k] = 0;
                                box[l] = 0;
                                system("cls");
                                f1 = 1;
                                inc_score(&p1);

                            } else { continue; }
                        } else { continue; }
                    }
                    if (f1 == 1) {
                        u--;
                        if (i0 == u) {
                            if (p1.score > p2.score) {
                                top = fopen("top 10 player.text", "a");
                                fprintf_s(top, play_o, co(p1.name), p1.score);  //open file and append struct of winner
                                fclose(top);

                                return end(p1.name, p1.score);
                            } else if (p1.score < p2.score) {
/*
                            top = fopen("top 10 player.text", "a");
                            fprintf_s(top, play_o, co(p2.name), p2.score);  //open file and append struct of winner
                            fclose(top);
*/
                                return end(p2.name, p2.score);
                            } else {
                                return end("draw", p1.score);

                            }
                        }
                        goto az6; //get one additional move as a result of score++
                    }
                    system("cls");
                }

                //===================================================================

                if (i0 % 2 == 0) {
                    ax6 :
                    pc = 0;




                    if (pcCounter %2 ==0){
                    for (int k = 1; k < 2 * n + 1; k += 2) {
                        for (int l = 0; l < 2 * m + 1; l += 2) {
                            if (arr[k][l] != 186) {
                                arr[k][l] = 186;
                                arr2[k][l] = 186;
                                pcCounter++;
                                goto ex26;

                            }
                        }
                    }
                    }

                    for (int k = 0; k < 2 * n + 1; k += 2) {
                        for (int l = 1; l < 2 * m + 1; l += 2) {
                            if (arr[k][l] != 205) {
                                arr[k][l] = 205;
                                arr2[k][l] = 205;
                                pcCounter++;
                                goto ex26;
                            }
                        }
                    }
                    ex26:


                    //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    //print 1 : 5 above grid
                    printf(" \t\t\t\t\t\t ");
                    for (int i5 = 0; i5 < 2 * m + 1; i5++) {
                        if (i5 == 10 || i5 == 9) { printf("%d", i5 + 1); }
                        else { printf(" %d", i5 + 1); }
                    }
                    printf("\n");

                    //print 1:5 beside the grid and print the grid using %c
                    for (int i6 = 0; i6 < 2 * n + 1; i6++) {
                        if (i6 == 9 || i6 == 10) {
                            printf("\t\t\t\t\t       %d ", i6 + 1);

                            for (int j6 = 0; j6 < 2 * m + 1; j6++) {
                                if (arr2[i6][j6] == 205 || arr2[i6][j6] == 186 || arr2[i6][j6] == ch2) {
                                    printf(yellow"%c "reset, arr2[i6][j6]);

                                } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch2) {
                                    printf(green"%c "reset, arr1[i6][j6]);
                                } else {
                                    printf("%c ", arr[i6][j6]);
                                }
                            }
                            printf("\n");
                        } else {
                            printf("\t\t\t\t\t\t%d ", i6 + 1);

                            for (int j6 = 0; j6 < 2 * m + 1; j6++) {
                                if (arr2[i6][j6] == 205 || arr2[i6][j6] == 186 || arr2[i6][j6] == ch2) {
                                    printf(yellow"%c "reset, arr2[i6][j6]);

                                } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch2) {
                                    printf(green"%c "reset, arr1[i6][j6]);
                                } else {
                                    printf("%c ", arr[i6][j6]);
                                }
                            }
                            printf("\n");
                        }
                    }
                    inc_moves(&p2);
                    rem--;
                    f2 = 0;
                    for (int k = 0, l = 1; k < 2 * n * m && l < 2 * n * m; k += 2, l += 2) {
                        if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                            if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l] + 1] == 186 &&
                                arr[arrBox[k] - 1][arrBox[l]] == 205 &&
                                arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                arr[arrBox[k]][arrBox[l]] = ch2;
                                arr2[arrBox[k]][arrBox[l]] = ch2;
                                arrBox[k] = 0;
                                arrBox[l] = 0;
                                system("cls");
                                f2 = 1;
                                inc_score(&p2);

                            } else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l] + 1] == 186 &&
                                       arr[box[k] - 1][box[l]] == 205 &&
                                       arr[box[k] + 1][box[l]] == 205) {
                                arr[box[k]][box[l]] = ch2;
                                arr2[box[k]][box[l]] = ch2;
                                box[k] = 0;
                                box[l] = 0;
                                system("cls");
                                f2 = 1;
                                inc_score(&p2);

                            } else { continue; }
                        } else { continue; }
                    }
                    if (f2 == 1) {
                        u--;
                        if (i0 == u) {
                            if (p1.score > p2.score) {

                                top = fopen("top 10 player.text", "a");
                                fprintf_s(top, play_o, co(p1.name),
                                          p1.score); //open file and append struct of winner
                                fclose(top);

                                return end(p1.name, p1.score);
                            } else if (p1.score < p2.score) {

                                /* top = fopen("top 10 player.text","a");
                             fprintf_s(top,play_o,co(p2.name),p2.score);  //open file and append struct of winner
                             fclose(top);*/

                                return end(p2.name, p2.score);
                            } else {
                                return end("draw", p1.score);

                            }
                        }
                        goto ax6;
                    }
                    system("cls");
                }
            }
        }

        else if (strcmp(colour1, "magenta") == 0 && strcmp(colour2, "yellow") == 0)     {


            for (int i0 = 0; i0 < u; i0++) {

                if (i0 % 2 == 1) {
                    az7 :
                    if (fBox == 1 || f2 == 1) {
                        fBox = 0;
                        f2 = 0;
                        goto ax7;
                    }

                    by7:

                    printf(red"\t\t\tnote:"reset"for any misunderstand go to settings then"cyan" About (4)\n"reset);
                    //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    //print 1 : 5 above grid
                    printf(" \t\t\t\t\t\t ");
                    for (int i1 = 0; i1 < 2 * m + 1; i1++) {
                        if (i1 == 10 || i1 == 9) { printf("%d", i1 + 1); }
                        else { printf(" %d", i1 + 1); }
                    }
                    printf("\n");

                    //print 1:5 beside the grid and print the grid using %c
                    for (int i2 = 0; i2 < 2 * n + 1; i2++) {
                        if (i2 == 10 || i2 == 9) {
                            printf("\t\t\t\t\t       %d ", i2 + 1);

                            for (int j2 = 0; j2 < 2 * m + 1; j2++) {
                                if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                    printf(yellow"%c "reset, arr2[i2][j2]);

                                } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                    printf(magenta"%c "reset, arr1[i2][j2]);
                                } else {
                                    printf("%c ", arr[i2][j2]);
                                }
                            }
                            printf("\n");
                        } else {
                            printf("\t\t\t\t\t\t%d ", i2 + 1);

                            for (int j2 = 0; j2 < 2 * m + 1; j2++) {
                                if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                    printf(yellow"%c "reset, arr2[i2][j2]);

                                } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                    printf(magenta"%c "reset, arr1[i2][j2]);
                                } else {
                                    printf("%c ", arr[i2][j2]);
                                }
                            }
                            printf("\n");
                        }
                    }

                     t=time_s(td1);
                    printf(yellow"\t\t\t\t\t   remaining lines =%d \n"reset, rem);
                    print_inf(p2, "yellow", p1, "magenta");
                    printf(magenta"\t\t\t    player %d turn\t\t\t\t"reset yellow"        time=%d:%d:%d \n"reset, 2, t.hour,
                            t.min, t.sec);
                    printf("\n  for undo at any step enter" cyan "\"undo\"" reset);
                    printf("\tfor settings at any step enter" cyan "\"row1: 0 & row2: 0 & col1: 0 & clo2: 0\"\n\n" reset);


                    //ask about move >>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    a7:
                    t1 = time(0);
                    printf("Enter row 1 :");
                    again17:
                    gets(ch);
                    if (isdigit(ch[0])) {
                        {
                            if (atoi(ch) >= 0) { x = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice  : ");
                                goto again17;
                            }
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again17;
                    }
                    a27:
                    printf("\nEnter row 2 :");
                    again27:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a7; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { y = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again27;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again27;
                    }
                    a37:
                    printf("\nEnter col 1 :");
                    again37:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a27; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { z = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again37;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again37;
                    }
                    printf("\nEnter col 2 :");
                    again47:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a37; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { w = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again47;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again47;
                    }


                    if (x == 0 && y == 0 && z == 0 && w == 0) {

                        system("cls");
                        al7:
                        x5 = print_setting();
                        if (x5 == 1) {
                            system("cls");
                            goto az7;
                        } else if (x5 == 2) {
                            system("cls");
                            n17:
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
                                goto n17;
                            }

                            if (y1 == 0) {
                                system("cls");
                                goto az7;
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

                            fprintf_s(f, "mode=%d\n", 1);
                            fprintf_s(f,"turnco=%d\n",turnco);
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
                            printf(magenta"\n\n\n                                                 save finished                              \n");
                            goto al7;

                        } else if (x5 == 3) {

                            return 5;//for go to  loud
                        } else if (x5 == 4) {    // for go to About ?
                            x3 = about_after_settings();

                            if (x3 == 1) { return 7; }
                            else if (x3 == 2) {
                                system("cls");
                                goto by7;
                            }
                            else if (x3 == 3) { return 8; }


                        } else if (x5 == 5) {
                            return 7; //for main menu

                        } else if (x5 == 6) {

                            return 8; //for exit
                        }

                    }


                    if (x - y > 2 || y - x > 2 || z - w > 2 || w - z > 2) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a7;
                    }
                    if (x != y && z != w) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a7;
                    }
                    if (x == y && z == w) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a7;
                    }
                    t2 = time(0);
                    td1 = difftime(t2, t1) + td1;


                    if (x == y) {
                        if (z > w) {
                            int temp = z;
                            z = w;
                            w = temp;
                        } //swap z&w
                        x = x - 1;
                        if (arr1[x][z] != 205 && arr2[x][z] != 205 && arr[x][z] != 254) {
                            undo[index1] = x;
                            undo[index2] = z;
                            index1 += 2;
                            index2 += 2;
                            arr[x][z] = 205;
                            arr1[x][z] = 205;
                        } else {
                            printf(red"WARNING:"reset" Please choose an empty line\n");
                            goto a7;
                        }
                    }
                    if (z == w) {
                        if (x > y) {
                            int temp = x;
                            x = y;
                            y = temp;
                        } //swap z&w
                        z = z - 1;
                        if (arr1[x][z] != 186 && arr2[x][z] != 186 && arr[x][z] != 254) {
                            undo[index1] = x;
                            undo[index2] = z;
                            index1 += 2;
                            index2 += 2;
                            arr[x][z] = 186;
                            arr1[x][z] = 186;
                        } else {
                            printf(red"WARNING:"reset" Please choose an empty line\n");
                            goto a7;
                        }
                    }
                    inc_moves(&p1);
                    rem--;
                    f1 = 0;
                    for (int k = 0, l = 1; k < 2 * n * m && l < 2 * n * m; k += 2, l += 2) {
                        if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                            if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l] + 1] == 186 &&
                                arr[arrBox[k] - 1][arrBox[l]] == 205 &&
                                arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                arr[arrBox[k]][arrBox[l]] = ch1;
                                arr1[arrBox[k]][arrBox[l]] = ch1;
                                arrBox[k] = 0;
                                arrBox[l] = 0;
                                system("cls");
                                f1 = 1;
                                inc_score(&p1);

                            } else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l] + 1] == 186 &&
                                       arr[box[k] - 1][box[l]] == 205 &&
                                       arr[box[k] + 1][box[l]] == 205) {
                                arr[box[k]][box[l]] = ch1;
                                arr1[box[k]][box[l]] = ch1;
                                box[k] = 0;
                                box[l] = 0;
                                system("cls");
                                f1 = 1;
                                inc_score(&p1);

                            } else { continue; }
                        } else { continue; }
                    }
                    if (f1 == 1) {
                        u--;
                        if (i0 == u) {
                            if (p1.score > p2.score) {
                                top = fopen("top 10 player.text", "a");
                                fprintf_s(top, play_o, co(p1.name), p1.score);  //open file and append struct of winner
                                fclose(top);

                                return end(p1.name, p1.score);
                            } else if (p1.score < p2.score) {
/*
                            top = fopen("top 10 player.text", "a");
                            fprintf_s(top, play_o, co(p2.name), p2.score);  //open file and append struct of winner
                            fclose(top);
*/
                                return end(p2.name, p2.score);
                            } else {
                                return end("draw", p1.score);

                            }
                        }
                        goto az7; //get one additional move as a result of score++
                    }
                    system("cls");
                }

                //===================================================================

                if (i0 % 2 == 0) {
                    ax7 :
                    pc = 0;




                    if (pcCounter %2 ==0){
                    for (int k = 1; k < 2 * n + 1; k += 2) {
                        for (int l = 0; l < 2 * m + 1; l += 2) {
                            if (arr[k][l] != 186) {
                                arr[k][l] = 186;
                                arr2[k][l] = 186;
                                pcCounter++;
                                goto ex27;

                            }
                        }
                    }
                    }

                    for (int k = 0; k < 2 * n + 1; k += 2) {
                        for (int l = 1; l < 2 * m + 1; l += 2) {
                            if (arr[k][l] != 205) {
                                arr[k][l] = 205;
                                arr2[k][l] = 205;
                                pcCounter++;
                                goto ex27;
                            }
                        }
                    }
                    ex27:


                    //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    //print 1 : 5 above grid
                    printf(" \t\t\t\t\t\t ");
                    for (int i5 = 0; i5 < 2 * m + 1; i5++) {
                        if (i5 == 10 || i5 == 9) { printf("%d", i5 + 1); }
                        else { printf(" %d", i5 + 1); }
                    }
                    printf("\n");

                    //print 1:5 beside the grid and print the grid using %c
                    for (int i6 = 0; i6 < 2 * n + 1; i6++) {
                        if (i6 == 9 || i6 == 10) {
                            printf("\t\t\t\t\t       %d ", i6 + 1);

                            for (int j6 = 0; j6 < 2 * m + 1; j6++) {
                                if (arr2[i6][j6] == 205 || arr2[i6][j6] == 186 || arr2[i6][j6] == ch2) {
                                    printf(yellow"%c "reset, arr2[i6][j6]);

                                } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch2) {
                                    printf(magenta"%c "reset, arr1[i6][j6]);
                                } else {
                                    printf("%c ", arr[i6][j6]);
                                }
                            }
                            printf("\n");
                        } else {
                            printf("\t\t\t\t\t\t%d ", i6 + 1);

                            for (int j6 = 0; j6 < 2 * m + 1; j6++) {
                                if (arr2[i6][j6] == 205 || arr2[i6][j6] == 186 || arr2[i6][j6] == ch2) {
                                    printf(yellow"%c "reset, arr2[i6][j6]);

                                } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch2) {
                                    printf(magenta"%c "reset, arr1[i6][j6]);
                                } else {
                                    printf("%c ", arr[i6][j6]);
                                }
                            }
                            printf("\n");
                        }
                    }
                    inc_moves(&p2);
                    rem--;
                    f2 = 0;
                    for (int k = 0, l = 1; k < 2 * n * m && l < 2 * n * m; k += 2, l += 2) {
                        if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                            if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l] + 1] == 186 &&
                                arr[arrBox[k] - 1][arrBox[l]] == 205 &&
                                arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                arr[arrBox[k]][arrBox[l]] = ch2;
                                arr2[arrBox[k]][arrBox[l]] = ch2;
                                arrBox[k] = 0;
                                arrBox[l] = 0;
                                system("cls");
                                f2 = 1;
                                inc_score(&p2);

                            } else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l] + 1] == 186 &&
                                       arr[box[k] - 1][box[l]] == 205 &&
                                       arr[box[k] + 1][box[l]] == 205) {
                                arr[box[k]][box[l]] = ch2;
                                arr2[box[k]][box[l]] = ch2;
                                box[k] = 0;
                                box[l] = 0;
                                system("cls");
                                f2 = 1;
                                inc_score(&p2);

                            } else { continue; }
                        } else { continue; }
                    }
                    if (f2 == 1) {
                        u--;
                        if (i0 == u) {
                            if (p1.score > p2.score) {

                                top = fopen("top 10 player.text", "a");
                                fprintf_s(top, play_o, co(p1.name),
                                          p1.score); //open file and append struct of winner
                                fclose(top);

                                return end(p1.name, p1.score);
                            } else if (p1.score < p2.score) {

                                /* top = fopen("top 10 player.text","a");
                             fprintf_s(top,play_o,co(p2.name),p2.score);  //open file and append struct of winner
                             fclose(top);*/

                                return end(p2.name, p2.score);
                            } else {
                                return end("draw", p1.score);

                            }
                        }
                        goto ax7;
                    }
                    system("cls");
                }
            }
        }
        else if (strcmp(colour1, "red") == 0 && strcmp(colour2, "yellow") == 0)     {


            for (int i0 = 0; i0 < u; i0++) {

                if (i0 % 2 == 1) {
                    az8 :
                    if (fBox == 1 || f2 == 1) {
                        fBox = 0;
                        f2 = 0;
                        goto ax8;
                    }

                    by8:

                    printf(red"\t\t\tnote:"reset"for any misunderstand go to settings then"cyan" About (4)\n"reset);
                    //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    //print 1 : 5 above grid
                    printf(" \t\t\t\t\t\t ");
                    for (int i1 = 0; i1 < 2 * m + 1; i1++) {
                        if (i1 == 10 || i1 == 9) { printf("%d", i1 + 1); }
                        else { printf(" %d", i1 + 1); }
                    }
                    printf("\n");

                    //print 1:5 beside the grid and print the grid using %c
                    for (int i2 = 0; i2 < 2 * n + 1; i2++) {
                        if (i2 == 10 || i2 == 9) {
                            printf("\t\t\t\t\t       %d ", i2 + 1);

                            for (int j2 = 0; j2 < 2 * m + 1; j2++) {
                                if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                    printf(yellow"%c "reset, arr2[i2][j2]);

                                } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                    printf(red"%c "reset, arr1[i2][j2]);
                                } else {
                                    printf("%c ", arr[i2][j2]);
                                }
                            }
                            printf("\n");
                        } else {
                            printf("\t\t\t\t\t\t%d ", i2 + 1);

                            for (int j2 = 0; j2 < 2 * m + 1; j2++) {
                                if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                    printf(yellow"%c "reset, arr2[i2][j2]);

                                } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                    printf(red"%c "reset, arr1[i2][j2]);
                                } else {
                                    printf("%c ", arr[i2][j2]);
                                }
                            }
                            printf("\n");
                        }
                    }

                     t=time_s(td1);
                    printf(yellow"\t\t\t\t\t   remaining lines =%d \n"reset, rem);
                    print_inf(p2, "yellow", p1, "red");
                    printf(red"\t\t\t    player %d turn\t\t\t\t"reset yellow"        time=%d:%d:%d \n"reset, 2, t.hour,
                            t.min, t.sec);
                    printf("\n  for undo at any step enter" cyan "\"undo\"" reset);
                    printf("\tfor settings at any step enter" cyan "\"row1: 0 & row2: 0 & col1: 0 & clo2: 0\"\n\n" reset);


                    //ask about move >>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    a8:
                    t1 = time(0);
                    printf("Enter row 1 :");
                    again18:
                    gets(ch);
                    if (isdigit(ch[0])) {
                        {
                            if (atoi(ch) >= 0) { x = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice  : ");
                                goto again18;
                            }
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again18;
                    }
                    a28:
                    printf("\nEnter row 2 :");
                    again28:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a8; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { y = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again28;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again28;
                    }
                    a38:
                    printf("\nEnter col 1 :");
                    again38:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a28; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { z = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again38;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again38;
                    }
                    printf("\nEnter col 2 :");
                    again48:
                    gets(ch);
                    if (strcmp(ch, "undo") == 0) { goto a38; }
                    else if (isdigit(ch[0])) {
                        if (atoi(ch) >= 0) { w = atoi(ch); }
                        else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again48;
                        }
                    } else {
                        printf(red"warning:"reset"please enter a valid choice : ");
                        goto again48;
                    }


                    if (x == 0 && y == 0 && z == 0 && w == 0) {

                        system("cls");
                        al8:
                        x5 = print_setting();
                        if (x5 == 1) {
                            system("cls");
                            goto az8;
                        } else if (x5 == 2) {
                            system("cls");
                            n18:
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
                                goto n18;
                            }

                            if (y1 == 0) {
                                system("cls");
                                goto az8;
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

                            fprintf_s(f, "mode=%d\n", 1);
                            fprintf_s(f,"turnco=%d\n",turnco);
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
                            goto al8;

                        } else if (x5 == 3) {

                            return 5;//for go to  loud
                        } else if (x5 == 4) {    // for go to About ?
                            x3 = about_after_settings();

                            if (x3 == 1) { return 7; }
                            else if (x3 == 2) {
                                system("cls");
                                goto by8;
                            }
                            else if (x3 == 3) { return 8; }


                        } else if (x5 == 5) {
                            return 7; //for main menu

                        } else if (x5 == 6) {

                            return 8; //for exit
                        }

                    }


                    if (x - y > 2 || y - x > 2 || z - w > 2 || w - z > 2) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a8;
                    }
                    if (x != y && z != w) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a8;
                    }
                    if (x == y && z == w) {
                        printf(red"WARNING"reset": Please choose correct line\n");
                        goto a8;
                    }
                    t2 = time(0);
                    td1 = difftime(t2, t1) + td1;


                    if (x == y) {
                        if (z > w) {
                            int temp = z;
                            z = w;
                            w = temp;
                        } //swap z&w
                        x = x - 1;
                        if (arr1[x][z] != 205 && arr2[x][z] != 205 && arr[x][z] != 254) {
                            undo[index1] = x;
                            undo[index2] = z;
                            index1 += 2;
                            index2 += 2;
                            arr[x][z] = 205;
                            arr1[x][z] = 205;
                        } else {
                            printf(red"WARNING:"reset" Please choose an empty line\n");
                            goto a8;
                        }
                    }
                    if (z == w) {
                        if (x > y) {
                            int temp = x;
                            x = y;
                            y = temp;
                        } //swap z&w
                        z = z - 1;
                        if (arr1[x][z] != 186 && arr2[x][z] != 186 && arr[x][z] != 254) {
                            undo[index1] = x;
                            undo[index2] = z;
                            index1 += 2;
                            index2 += 2;
                            arr[x][z] = 186;
                            arr1[x][z] = 186;
                        } else {
                            printf(red"WARNING:"reset" Please choose an empty line\n");
                            goto a8;
                        }
                    }
                    inc_moves(&p1);
                    rem--;
                    f1 = 0;
                    for (int k = 0, l = 1; k < 2 * n * m && l < 2 * n * m; k += 2, l += 2) {
                        if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                            if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l] + 1] == 186 &&
                                arr[arrBox[k] - 1][arrBox[l]] == 205 &&
                                arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                arr[arrBox[k]][arrBox[l]] = ch1;
                                arr1[arrBox[k]][arrBox[l]] = ch1;
                                arrBox[k] = 0;
                                arrBox[l] = 0;
                                system("cls");
                                f1 = 1;
                                inc_score(&p1);

                            } else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l] + 1] == 186 &&
                                       arr[box[k] - 1][box[l]] == 205 &&
                                       arr[box[k] + 1][box[l]] == 205) {
                                arr[box[k]][box[l]] = ch1;
                                arr1[box[k]][box[l]] = ch1;
                                box[k] = 0;
                                box[l] = 0;
                                system("cls");
                                f1 = 1;
                                inc_score(&p1);

                            } else { continue; }
                        } else { continue; }
                    }
                    if (f1 == 1) {
                        u--;
                        if (i0 == u) {
                            if (p1.score > p2.score) {
                                top = fopen("top 10 player.text", "a");
                                fprintf_s(top, play_o, co(p1.name), p1.score);  //open file and append struct of winner
                                fclose(top);

                                return end(p1.name, p1.score);
                            } else if (p1.score < p2.score) {
/*
                            top = fopen("top 10 player.text", "a");
                            fprintf_s(top, play_o, co(p2.name), p2.score);  //open file and append struct of winner
                            fclose(top);
*/
                                return end(p2.name, p2.score);
                            } else {
                                return end("draw", p1.score);

                            }
                        }
                        goto az8; //get one additional move as a result of score++
                    }
                    system("cls");
                }

                //===================================================================

                if (i0 % 2 == 0) {
                    ax8 :
                    pc = 0;




                    if (pcCounter %2 ==0){
                    for (int k = 1; k < 2 * n + 1; k += 2) {
                        for (int l = 0; l < 2 * m + 1; l += 2) {
                            if (arr[k][l] != 186) {
                                arr[k][l] = 186;
                                arr2[k][l] = 186;
                                pcCounter++;
                                goto ex28;

                            }
                        }
                    }
                    }

                    for (int k = 0; k < 2 * n + 1; k += 2) {
                        for (int l = 1; l < 2 * m + 1; l += 2) {
                            if (arr[k][l] != 205) {
                                arr[k][l] = 205;
                                arr2[k][l] = 205;
                                pcCounter++;
                                goto ex28;
                            }
                        }
                    }
                    ex28:


                    //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                    //print 1 : 5 above grid
                    printf(" \t\t\t\t\t\t ");
                    for (int i5 = 0; i5 < 2 * m + 1; i5++) {
                        if (i5 == 10 || i5 == 9) { printf("%d", i5 + 1); }
                        else { printf(" %d", i5 + 1); }
                    }
                    printf("\n");

                    //print 1:5 beside the grid and print the grid using %c
                    for (int i6 = 0; i6 < 2 * n + 1; i6++) {
                        if (i6 == 9 || i6 == 10) {
                            printf("\t\t\t\t\t       %d ", i6 + 1);

                            for (int j6 = 0; j6 < 2 * m + 1; j6++) {
                                if (arr2[i6][j6] == 205 || arr2[i6][j6] == 186 || arr2[i6][j6] == ch2) {
                                    printf(yellow"%c "reset, arr2[i6][j6]);

                                } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch2) {
                                    printf(red"%c "reset, arr1[i6][j6]);
                                } else {
                                    printf("%c ", arr[i6][j6]);
                                }
                            }
                            printf("\n");
                        } else {
                            printf("\t\t\t\t\t\t%d ", i6 + 1);

                            for (int j6 = 0; j6 < 2 * m + 1; j6++) {
                                if (arr2[i6][j6] == 205 || arr2[i6][j6] == 186 || arr2[i6][j6] == ch2) {
                                    printf(yellow"%c "reset, arr2[i6][j6]);

                                } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch2) {
                                    printf(red"%c "reset, arr1[i6][j6]);
                                } else {
                                    printf("%c ", arr[i6][j6]);
                                }
                            }
                            printf("\n");
                        }
                    }
                    inc_moves(&p2);
                    rem--;
                    f2 = 0;
                    for (int k = 0, l = 1; k < 2 * n * m && l < 2 * n * m; k += 2, l += 2) {
                        if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                            if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l] + 1] == 186 &&
                                arr[arrBox[k] - 1][arrBox[l]] == 205 &&
                                arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                arr[arrBox[k]][arrBox[l]] = ch2;
                                arr2[arrBox[k]][arrBox[l]] = ch2;
                                arrBox[k] = 0;
                                arrBox[l] = 0;
                                system("cls");
                                f2 = 1;
                                inc_score(&p2);

                            } else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l] + 1] == 186 &&
                                       arr[box[k] - 1][box[l]] == 205 &&
                                       arr[box[k] + 1][box[l]] == 205) {
                                arr[box[k]][box[l]] = ch2;
                                arr2[box[k]][box[l]] = ch2;
                                box[k] = 0;
                                box[l] = 0;
                                system("cls");
                                f2 = 1;
                                inc_score(&p2);

                            } else { continue; }
                        } else { continue; }
                    }
                    if (f2 == 1) {
                        u--;
                        if (i0 == u) {
                            if (p1.score > p2.score) {

                                top = fopen("top 10 player.text", "a");
                                fprintf_s(top, play_o, co(p1.name),
                                          p1.score); //open file and append struct of winner
                                fclose(top);

                                return end(p1.name, p1.score);
                            } else if (p1.score < p2.score) {

                                /* top = fopen("top 10 player.text","a");
                             fprintf_s(top,play_o,co(p2.name),p2.score);  //open file and append struct of winner
                             fclose(top);*/

                                return end(p2.name, p2.score);
                            } else {
                                return end("draw", p1.score);

                            }
                        }
                        goto ax8;
                    }
                    system("cls");
                }
            }
        }








    }



}
