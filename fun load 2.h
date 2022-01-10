int funload2 (int n,int m,int i0,int rem ,int u,int mode,int turnco,player p1,player p2,char colour1[20],char colour2[20],
              int arr[2 * n + 1][2 * m + 1],int arr1[2 * n + 1][2 * m + 1],int arr2[2 * n + 1][2 * m + 1]) {
    time_t t1=0, t2=0 ,t3=0,t4=0;
    times t;
    int sbox;
    int  i, j, y1,x5,x4,x6,x2,x3,td1=0,td2=0;
    char ch1,ch2;

    char qq[30];
    FILE *f,*top;

    fflush(stdin);

//game loud
    int no_UN_RE = 2*((2 * (n * m)) + (n) + (m)) ;
    int no_box = 2*n*m ;
    int box[100] = {0} ;
    int undo [no_UN_RE] , redo[no_UN_RE];
    int arrBox[100];
    int count = 0;
    int undoArrBox[2*n*m] ;
    int count0 = 0 ;


    ch1 = p1.name[0];
    ch2 = p2.name[0];

    ch1 = convert(ch1);
    ch2 = convert(ch2);
    // game loading
    system(" ");

    for(int c=0 ; c<no_UN_RE ; c++){undo[c]=0 ; redo[c]=0 ; }

    for (int k = 1; k < 2 * n + 1; k += 2) {
        for (int l = 1; l < 2 * m + 1; l += 2) {
            arrBox[count++] = k;
            arrBox[count++] = l;
        }
    }
    for(int i=count ; i<100 ; i++){arrBox[i] = 0 ; }
    //undo for boxes
    for (int k = 1; k < 2 * n + 1; k += 2) {
        for (int l = 1; l < 2 * m + 1; l += 2) {
            undoArrBox[count0++] = k ;
            undoArrBox[count0++] = l ;
        }
    }



    //===================================================================

    //start the game
    int x, y, z, w;

    int f2 =0  , f1 =0 ;//variables to check if box done
    int fBox = 0  ;//variable if one of them deleted any box by undo
    int index1 =0 , index2=1  , cs  ;
    char ch[10] ; //array to get the play from user as srting then convert it
    int add = 0 ;

    if(mode==2&&turnco==0) {
        if (strcmp(colour1, "green") == 0 && strcmp(colour2, "red") == 0) {


            {
                for (i0; i0 < u; i0++) {


                    if (i0 % 2 == 0) {//player of color green
                        az1 :
                        if(fBox ==1 || f2==1){fBox=0 ; f2 =0 ;   goto ax1 ; }

                        by1:
                        printf(red"\t\t\tNote:"reset"for any misunderstand go to settings then"cyan" About (4)\n"reset);

                        //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                        //print 1 : 5 above grid
                        printf(" \t\t\t\t\t\t ");
                        for (int i1 = 0; i1 < 2 * m + 1; i1++) {
                            printf(" %d", i1 + 1);
                        }
                        printf("\n");

                        //print 1:5 beside the grid and print the grid using %c
                        for (int i2 = 0; i2 < 2 * n + 1; i2++) {
                            if(i2 ==10 || i2==9){
                                printf("\t\t\t\t\t       %d ", i2 + 1);

                                for (int j2= 0; j2 < 2 * m + 1; j2++) {
                                    if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                        printf(red"%c "reset, arr2[i2][j2]);

                                    } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                        printf(green"%c "reset, arr1[i2][j2]);
                                    } else {
                                        printf("%c ", arr[i2][j2]);
                                    }
                                }
                                printf("\n");
                            }
                            else {
                                printf("\t\t\t\t\t\t%d ", i2 + 1);

                                for (int j2= 0; j2 < 2 * m + 1; j2++) {
                                    if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                        printf(red"%c "reset, arr2[i2][j2]);

                                    } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                        printf(green"%c "reset, arr1[i2][j2]);
                                    } else {
                                        printf("%c ", arr[i2][j2]);
                                    }
                                }
                                printf("\n");
                            }
                        }
                        t = time_s(td2);
                        printf(yellow"\t\t\t\t\t   remaining lines =%d \n"reset, rem);
                        print_inf(p1, "green", p2, "red");
                        printf(green"\t\t\t    player %d turn\t\t\t\t"reset yellow"        time=%d:%d:%d \n"reset,1,t.hour,t.min,t.sec );
                        printf("\n  for undo at any step enter" cyan "\"undo\"" reset);
                        printf("\tfor settings at any step enter" cyan "\"row1: 0 & row2: 0 & col1: 0 & clo2: 0\"\n\n" reset);

                        //ask about move >>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                        a1:
                        t1 = time(0);
                        printf("Enter row 1 :");
                        again11:
                        gets (ch) ;
                        if (strcmp(ch,"undo")==0){
                            cs=0 ;
                            for(int k=no_UN_RE-1 , l=no_UN_RE-2 ; k >=0 && l>=0 ; k-=2 , l-=2 ){
                                if(undo[k]==0 && undo[l]==0){continue;}
                                else{
                                    cs=1 ;
                                    // undo for lines and get lines -- or total plays will increase after undo line
                                    // when green enter undo plays of red decrease -- (moves red --) rem++
                                    if(f1==1){ dec_move(&p1);} else { dec_move(&p2); }
                                    arr[undo[l]][undo[k]] = 32 ;
                                    arr1[undo[l]][undo[k]] = 32 ;
                                    arr2[undo[l]][undo[k]] = 32 ;
                                    undo[k] =0 ; undo[l] =0 ;
                                    index1-=2 ; index2-=2 ;
                                    rem++;
                                    //undo for boxes and get score -- if conditions are true

                                    for(int k2=0,l2=1 ; k2<2*n*m && l2<2*n*m ; k2+=2 ,l2+=2) {
                                        if (arr[undoArrBox[k2]][undoArrBox[l2]] != 32 ) {
                                            if (arr[undoArrBox[k2]][undoArrBox[l2] - 1] != 186 || arr[undoArrBox[k2]][undoArrBox[l2]+1] != 186 || arr[undoArrBox[k2]- 1][undoArrBox[l2]] != 205 ||
                                                arr[undoArrBox[k2] + 1][undoArrBox[l2]] != 205) {
                                                arr[undoArrBox[k2]][undoArrBox[l2]] = 32;
                                                if(arr1[undoArrBox[k2]][undoArrBox[l2]] !=32){arr1[undoArrBox[k2]][undoArrBox[l2]] = 32;dec_score(&p1);} //score green --
                                                else if(arr2[undoArrBox[k2]][undoArrBox[l2]] !=32){arr2[undoArrBox[k2]][undoArrBox[l2]] = 32;dec_score(&p2);}

                                                box[add++] = undoArrBox[k2] ; box[add++] = undoArrBox[l2] ;
                                                fBox=1 ;
                                            }

                                            else{continue;}
                                        }
                                        else { continue; }
                                    }
                                    if(fBox ==1 ){ u++; system("cls") ; goto ax1 ;}
                                    i0-- ;
                                    system("cls") ;
                                    goto ax1;
                                }
                            }
                            if(cs==0){printf(red"warning:"reset"please enter a valid choice : "); goto again11 ;}
                        }
                        else if (isdigit(ch[0])){
                            {if(atoi(ch)>=0){x=atoi(ch) ;}else{printf(red"warning:"reset"please enter a valid choice  : "); goto again11 ;}}
                        }
                        else {printf(red"warning:"reset"please enter a valid choice : "); goto again11 ;}
                        a21:
                        printf("\nEnter row 2 :");
                        again21:
                        gets (ch) ;
                        if (strcmp(ch,"undo")==0){goto a1 ;}
                        else if (isdigit(ch[0]))
                        {
                            if(atoi(ch)>=0){y=atoi(ch) ;}else{printf(red"warning:"reset"please enter a valid choice : "); goto again21 ;}
                        }
                        else {printf(red"warning:"reset"please enter a valid choice : "); goto again21 ;
                        }
                        a31:
                        printf("\nEnter col 1 :");
                        again31:
                        gets (ch) ;
                        if (strcmp(ch,"undo")==0){goto a21 ;  }
                        else if (isdigit(ch[0]))
                        {
                            if(atoi(ch)>=0){z=atoi(ch) ;}else{printf(red"warning:"reset"please enter a valid choice : "); goto again31 ;}
                        }
                        else {printf(red"warning:"reset"please enter a valid choice : "); goto again31 ;
                        }
                        printf("\nEnter col 2 :");
                        again41:
                        gets (ch) ;
                        if (strcmp(ch,"undo")==0){goto a31 ;  }
                        else if (isdigit(ch[0]))
                        {
                            if(atoi(ch)>=0){w=atoi(ch) ;}else{printf(red"warning:"reset"please enter a valid choice : "); goto again41 ;}
                        }
                        else {printf(red"warning:"reset"please enter a valid choice : "); goto again41 ;
                        }



                        if (x == 0 && y == 0 && z == 0 && w == 0) {

                            system("cls");
                            al1:
                            x5 = print_setting();
                            if (x5 == 1) {
                                system("cls");
                                goto by1;
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
                                    goto az1;
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

                                fprintf_s(f,"mode=%d\n",2);
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
                                x3=about_after_settings();

                                if(x3==1){return 7;}
                                else if(x3==2){system("cls");   goto az1 ;}
                                else if(x3==3){return 8 ;}


                            } else if (x5 == 5) {
                                return 7; //for main menu

                            } else if (x5 == 6) {

                                return 8; //for exit
                            }

                        }



                        if(x-y>2||y-x>2||z-w>2||w-z>2){
                            printf(red"WARNING"reset": Please choose correct line\n");
                            goto a1;
                        }
                        if(x!=y && z!=w){
                            printf(red"WARNING"reset": Please choose correct line\n");
                            goto a1;
                        }
                        if(x==y && z==w){
                            printf(red"WARNING"reset": Please choose correct line\n");
                            goto a1;
                        }
                        t2=time(0);
                        td1= difftime(t2,t1)+td2;




                        if (x == y) {
                            if (z > w) {
                                int temp = z;
                                z = w;
                                w = temp;
                            } //swap z&w
                            x = x - 1;
                            if (arr1[x][z] != 205 && arr2[x][z] != 205 && arr[x][z]!=254) {
                                undo[index1]=x ;  undo[index2]=z ;
                                index1+=2 ;
                                index2+=2 ;
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
                            if (arr1[x][z] != 186 && arr2[x][z] != 186 && arr[x][z]!=254) {
                                undo[index1]=x ;  undo[index2]=z ;
                                index1+=2 ;
                                index2+=2 ;
                                arr[x][z] = 186;
                                arr1[x][z] = 186;
                            } else {
                                printf(red"WARNING:"reset" Please choose an empty line\n");
                                goto a1;
                            }
                        }

                        inc_moves(&p1);
                        rem--; f1 =0 ;
                        for(int k=0,l=1 ; k<50 && l<50 ; k+=2 ,l+=2) {
                            if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                                if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l]+1] == 186 && arr[arrBox[k]- 1][arrBox[l]] == 205 &&
                                    arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                    arr[arrBox[k]][arrBox[l]] = ch1;
                                    arr1[arrBox[k]][arrBox[l]] = ch1;
                                    arrBox[k] =0 ; arrBox[l] =0 ;
                                    system("cls") ;
                                    f1=1 ;
                                    inc_score(&p1);  //green score++

                                }
                                else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l]+1] == 186 && arr[box[k]- 1][box[l]] == 205 &&
                                         arr[box[k] + 1][box[l]] == 205) {
                                    arr[box[k]][box[l]] = ch1;
                                    arr1[box[k]][box[l]] = ch1;
                                    box[k] =0 ; box[l] =0 ;
                                    system("cls") ;
                                    f1=1 ;inc_score(&p1);		//green score++

                                }
                                else {continue;}
                            }
                            else { continue; }
                        }
                        //check if the player had done box to get additioal move
                        if (f1 == 1) {
                            u--;

                            if (rem==0) {
                                if (p1.score > p2.score) {
                                    top = fopen("top 10 player.text", "a");
                                    fprintf_s(top, play_o, co(p1.name), p1.score);  //open file and append struct of winner
                                    fclose(top);

                                    return end(p1.name, p1.score);
                                } else if (p1.score < p2.score) {

                                    top = fopen("top 10 player.text", "a");
                                    fprintf_s(top, play_o, co(p2.name), p2.score);  //open file and append struct of winner
                                    fclose(top);

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
                        //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                        //print 1 : 5 above grid
                        if (fBox == 1 ) {fBox = 0;goto az1;}
                        else {f1=0;}


                        cy1:
                        printf(red"\t\t\tNote:"reset"for any misunderstand go to settings then"cyan" About (4)\n"reset);
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
                                        printf(red"%c "reset, arr2[i6][j6]);

                                    } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch1) {
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
                                        printf(red"%c "reset, arr2[i6][j6]);

                                    } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch1) {
                                        printf(green"%c "reset, arr1[i6][j6]);
                                    } else {
                                        printf("%c ", arr[i6][j6]);
                                    }
                                }
                                printf("\n");
                            }
                        }
                        t = time_s(td1);
                        printf(yellow"\t\t\t\t\t   remaining lines =%d \n"reset, rem);
                        print_inf(p1, "green", p2, "red");
                        printf(red"\t\t\t    player %d turn\t\t\t\t"reset yellow"        time=%d:%d:%d \n"reset,2,t.hour,t.min,t.sec );
                        printf("\n  for undo at any step enter" cyan "\"undo\"" reset);
                        printf("\tfor settings at any step enter" cyan "\"row1: 0 & row2: 0 & col1: 0 & clo2: 0\"\n\n" reset);
                        b1:
                        t3 = time(0);
                        printf("Enter row 1 :");
                        again51:
                        gets(ch);
                        if (strcmp(ch, "undo") == 0) {
                            cs = 0;
                            for (int k = no_UN_RE - 1, l = no_UN_RE - 2; k >= 0 && l >= 0; k -= 2, l -= 2) {
                                if (undo[k] == 0 && undo[l] == 0) { continue; }
                                else {
                                    cs = 1;
                                    //for lines
                                    // when red enter undo plays of green decrease -- (moves green--) rem++
                                    //if(f2==1){ dec_move(&p2); }else{dec_move(&p1);}
                                    arr[undo[l]][undo[k]] = 32;
                                    arr1[undo[l]][undo[k]] = 32;
                                    arr2[undo[l]][undo[k]] = 32;
                                    undo[k] = 0;
                                    undo[l] = 0;
                                    index1 -= 2;
                                    index2 -= 2;
                                    rem++;
                                    //for boxes

                                    for (int k1 = 0, l1 = 1; k1 < 2 * n * m && l1 < 2 * n * m; k1 += 2, l1 += 2) {
                                        if (arr[undoArrBox[k1]][undoArrBox[l1]] != 32) {
                                            if (arr[undoArrBox[k1]][undoArrBox[l1] - 1] != 186 ||
                                                arr[undoArrBox[k1]][undoArrBox[l1] + 1] != 186 ||
                                                arr[undoArrBox[k1] - 1][undoArrBox[l1]] != 205 ||
                                                arr[undoArrBox[k1] + 1][undoArrBox[l1]] != 205) {
                                                arr[undoArrBox[k1]][undoArrBox[l1]] = 32;
                                                if(arr1[undoArrBox[k1]][undoArrBox[l1]] !=32){arr1[undoArrBox[k1]][undoArrBox[l1]] = 32;dec_score(&p1);sbox=1;}//score green --}
                                                else if(arr2[undoArrBox[k1]][undoArrBox[l1]] !=32){arr2[undoArrBox[k1]][undoArrBox[l1]] = 32;dec_score(&p2);sbox=2;} //score red --}
                                                box[add++] = undoArrBox[k1];
                                                box[add++] = undoArrBox[l1];
                                                fBox = 1;
                                            } else { continue; }
                                        } else { continue; }
                                    }
                                    if(sbox==1){dec_move(&p1);sbox=0;}
                                    else if(sbox==2){dec_move(&p2);sbox=0;}
                                    if(fBox!=1) {   if(f2==1){ dec_move(&p2); }else{dec_move(&p1);}   }

                                    if (fBox == 1) {
                                        u++;
                                        system("cls");
                                        goto az1;
                                    }

                                    i0--;
                                    system("cls");
                                    goto az1;
                                }
                            }
                            if (cs == 0) {
                                printf(red"warning:"reset"please enter a valid choice : ");
                                goto again51;
                            }
                        }//you need here to apply the arrays of undo and redo
                        else if (isdigit(ch[0])) {
                            if (atoi(ch) >= 0) { x = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice : ");
                                goto again51;
                            }
                        } else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again51;
                        }
                        b21:
                        printf("\nEnter row 2 :");
                        again61:
                        gets(ch);
                        if (strcmp(ch, "undo") == 0) { goto b1; }
                        else if (isdigit(ch[0])) {
                            if (atoi(ch) >= 0) { y = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice : ");
                                goto again61;
                            }
                        } else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again61;
                        }
                        b31:
                        printf("\nEnter col 1 :");
                        again71:
                        gets(ch);
                        if (strcmp(ch, "undo") == 0) { goto b21; }
                        else if (isdigit(ch[0])) {
                            if (atoi(ch) >= 0) { z = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice : ");
                                goto again71;
                            }
                        } else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again71;
                        }
                        printf("\nEnter col 2 :");
                        again81:
                        gets(ch);
                        if (strcmp(ch, "undo") == 0) { goto b31; }
                        else if (isdigit(ch[0])) {
                            if (atoi(ch) >= 0) { w = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice : ");
                                goto again81;
                            }
                        } else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again81;
                        }


                        if (x == 0 && y == 0 && z == 0 && w == 0) {

                            system("cls");
                            al21:
                            x5 = print_setting();
                            if (x5 == 1) {
                                system("cls");
                                goto cy1;
                            } else if (x5 == 2) {
                                system("cls");
                                n21:
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
                                    goto n21;
                                }

                                if (y1 == 0) {
                                    system("cls");
                                    goto az1;
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
                                fprintf_s(f,"mode=%d\n",2);
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
                                goto al21;

                            } else if (x5 == 3) {

                                return 5;//for go to  loud
                            } else if (x5 == 4) {// for go to About ?
                                x3 = about_after_settings();
                                if (x3 == 1) { return 7; }
                                else if (x3 == 2) {
                                    system("cls");
                                    goto ax1;
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
                            goto b1;
                        }
                        if (x != y && z != w) {
                            printf(red"WARNING"reset": Please choose correct line\n");
                            goto b1;
                        }
                        if (x == y && z == w) {
                            printf(red"WARNING"reset": Please choose correct line\n");
                            goto b1;
                        }
                        t4 = time(0);
                        td2 = difftime(t4, t3) + td1;




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
                                arr2[x][z] = 205;

                            } else {
                                printf(red"WARNING:"reset" Please choose an empty line\n");
                                goto b1;
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
                                arr2[x][z] = 186;
                            } else {
                                printf(red"WARNING:"reset" Please choose an empty line\n");
                                goto b1;
                            }
                        }
                        //red moves ++ , rem--
                        inc_moves(&p2);
                        rem--;
                        int f2 = 0;
                        for(int k=0,l=1 ; k<50 && l<50 ; k+=2 ,l+=2) {
                            if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                                if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l]+1] == 186 && arr[arrBox[k]- 1][arrBox[l]] == 205 &&
                                    arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                    arr[arrBox[k]][arrBox[l]] = ch2;
                                    arr2[arrBox[k]][arrBox[l]] = ch2;		//red score++
                                    arrBox[k] =0 ; arrBox[l] =0 ;
                                    system("cls") ;
                                    f2=1 ;
                                    inc_score(&p2);

                                }
                                else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l]+1] == 186 && arr[box[k]- 1][box[l]] == 205 &&
                                         arr[box[k] + 1][box[l]] == 205) {
                                    arr[box[k]][box[l]] = ch2;
                                    arr2[box[k]][box[l]] = ch2;
                                    box[k] =0 ; box[l] =0 ;
                                    inc_score(&p2);
                                    system("cls") ;
                                    f2=1 ;

                                }
                                else {continue;}
                            }
                            else { continue; }
                        }
                        if (f2 == 1) {
                            u--;
                            if (rem==0) {

                                if (p1.score > p2.score) {

                                    top = fopen("top 10 player.text", "a");
                                    fprintf_s(top, play_o,co(p1.name),
                                              p1.score); //open file and append struct of winner
                                    fclose(top);

                                    return end(p1.name, p1.score);
                                }
                                else if (p1.score < p2.score) {

                                    top = fopen("top 10 player.text","a");
                                    fprintf_s(top,play_o,co(p2.name),p2.score);  //open file and append struct of winner
                                    fclose(top);

                                    return end(p2.name, p2.score);
                                }
                                else {
                                    return end("draw", p1.score);

                                }

                            }


                            goto ax1;
                        }
                        system("cls");

                    }
                }
            }
        }
        else if (strcmp(colour1, "green") == 0 && strcmp(colour2, "green") == 0) {


            {
                for (i0; i0 < u; i0++) {


                    if (i0 % 2 == 0) {//player of color green
                        az2 :
                        if(fBox ==1 || f2==1){fBox=0 ; f2 =0 ;   goto ax2 ; }

                        by2:
                        printf(red"\t\t\tNote:"reset"for any misunderstand go to settings then"cyan" About (4)\n"reset);

                        //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                        //print 1 : 5 above grid
                        printf(" \t\t\t\t\t\t ");
                        for (int i1 = 0; i1 < 2 * m + 1; i1++) {
                            printf(" %d", i1 + 1);
                        }
                        printf("\n");

                        //print 1:5 beside the grid and print the grid using %c
                        for (int i2 = 0; i2 < 2 * n + 1; i2++) {
                            if(i2 ==10 || i2==9){
                                printf("\t\t\t\t\t       %d ", i2 + 1);

                                for (int j2= 0; j2 < 2 * m + 1; j2++) {
                                    if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                        printf(green"%c "reset, arr2[i2][j2]);

                                    } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                        printf(green"%c "reset, arr1[i2][j2]);
                                    } else {
                                        printf("%c ", arr[i2][j2]);
                                    }
                                }
                                printf("\n");
                            }
                            else {
                                printf("\t\t\t\t\t\t%d ", i2 + 1);

                                for (int j2= 0; j2 < 2 * m + 1; j2++) {
                                    if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                        printf(green"%c "reset, arr2[i2][j2]);

                                    } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                        printf(green"%c "reset, arr1[i2][j2]);
                                    } else {
                                        printf("%c ", arr[i2][j2]);
                                    }
                                }
                                printf("\n");
                            }
                        }
                        t = time_s(td2);
                        printf(yellow"\t\t\t\t\t   remaining lines =%d \n"reset, rem);
                        print_inf(p1, "green", p2, "green");
                        printf(green"\t\t\t    player %d turn\t\t\t\t"reset yellow"        time=%d:%d:%d \n"reset,1,t.hour,t.min,t.sec );
                        printf("\n  for undo at any step enter" cyan "\"undo\"" reset);
                        printf("\tfor settings at any step enter" cyan "\"row1: 0 & row2: 0 & col1: 0 & clo2: 0\"\n\n" reset);

                        //ask about move >>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                        a2:
                        t1 = time(0);
                        printf("Enter row 1 :");
                        again12:
                        gets (ch) ;
                        if (strcmp(ch,"undo")==0){
                            cs=0 ;
                            for(int k=no_UN_RE-1 , l=no_UN_RE-2 ; k >=0 && l>=0 ; k-=2 , l-=2 ){
                                if(undo[k]==0 && undo[l]==0){continue;}
                                else{
                                    cs=1 ;
                                    // undo for lines and get lines -- or total plays will increase after undo line
                                    // when green enter undo plays of red decrease -- (moves red --) rem++
                                    if(f1==1){ dec_move(&p1);} else { dec_move(&p2); }
                                    arr[undo[l]][undo[k]] = 32 ;
                                    arr1[undo[l]][undo[k]] = 32 ;
                                    arr2[undo[l]][undo[k]] = 32 ;
                                    undo[k] =0 ; undo[l] =0 ;
                                    index1-=2 ; index2-=2 ;
                                    rem++;
                                    //undo for boxes and get score -- if conditions are true

                                    for(int k2=0,l2=1 ; k2<2*n*m && l2<2*n*m ; k2+=2 ,l2+=2) {
                                        if (arr[undoArrBox[k2]][undoArrBox[l2]] != 32 ) {
                                            if (arr[undoArrBox[k2]][undoArrBox[l2] - 1] != 186 || arr[undoArrBox[k2]][undoArrBox[l2]+1] != 186 || arr[undoArrBox[k2]- 1][undoArrBox[l2]] != 205 ||
                                                arr[undoArrBox[k2] + 1][undoArrBox[l2]] != 205) {
                                                arr[undoArrBox[k2]][undoArrBox[l2]] = 32;
                                                if(arr1[undoArrBox[k2]][undoArrBox[l2]] !=32){arr1[undoArrBox[k2]][undoArrBox[l2]] = 32;dec_score(&p1);} //score green --
                                                else if(arr2[undoArrBox[k2]][undoArrBox[l2]] !=32){arr2[undoArrBox[k2]][undoArrBox[l2]] = 32;dec_score(&p2);}

                                                box[add++] = undoArrBox[k2] ; box[add++] = undoArrBox[l2] ;
                                                fBox=1 ;
                                            }

                                            else{continue;}
                                        }
                                        else { continue; }
                                    }
                                    if(fBox ==1 ){ u++; system("cls") ; goto ax2 ;}
                                    i0-- ;
                                    system("cls") ;
                                    goto ax2;
                                }
                            }
                            if(cs==0){printf(red"warning:"reset"please enter a valid choice : "); goto again12 ;}
                        }
                        else if (isdigit(ch[0])){
                            {if(atoi(ch)>=0){x=atoi(ch) ;}else{printf(red"warning:"reset"please enter a valid choice  : "); goto again12 ;}}
                        }
                        else {printf(red"warning:"reset"please enter a valid choice : "); goto again12 ;}
                        a22:
                        printf("\nEnter row 2 :");
                        again22:
                        gets (ch) ;
                        if (strcmp(ch,"undo")==0){goto a2 ;}
                        else if (isdigit(ch[0]))
                        {
                            if(atoi(ch)>=0){y=atoi(ch) ;}else{printf(red"warning:"reset"please enter a valid choice : "); goto again22 ;}
                        }
                        else {printf(red"warning:"reset"please enter a valid choice : "); goto again22 ;
                        }
                        a32:
                        printf("\nEnter col 1 :");
                        again32:
                        gets (ch) ;
                        if (strcmp(ch,"undo")==0){goto a22 ;  }
                        else if (isdigit(ch[0]))
                        {
                            if(atoi(ch)>=0){z=atoi(ch) ;}else{printf(red"warning:"reset"please enter a valid choice : "); goto again32 ;}
                        }
                        else {printf(red"warning:"reset"please enter a valid choice : "); goto again32 ;
                        }
                        printf("\nEnter col 2 :");
                        again42:
                        gets (ch) ;
                        if (strcmp(ch,"undo")==0){goto a32 ;  }
                        else if (isdigit(ch[0]))
                        {
                            if(atoi(ch)>=0){w=atoi(ch) ;}else{printf(red"warning:"reset"please enter a valid choice : "); goto again42 ;}
                        }
                        else {printf(red"warning:"reset"please enter a valid choice : "); goto again42 ;
                        }



                        if (x == 0 && y == 0 && z == 0 && w == 0) {

                            system("cls");
                            al2:
                            x5 = print_setting();
                            if (x5 == 1) {
                                system("cls");
                                goto by2;
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
                                    goto az2;
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

                                fprintf_s(f,"mode=%d\n",2);
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
                                x3=about_after_settings();

                                if(x3==1){return 7;}
                                else if(x3==2){system("cls");   goto az2 ;}
                                else if(x3==3){return 8 ;}


                            } else if (x5 == 5) {
                                return 7; //for main menu

                            } else if (x5 == 6) {

                                return 8; //for exit
                            }

                        }



                        if(x-y>2||y-x>2||z-w>2||w-z>2){
                            printf(red"WARNING"reset": Please choose correct line\n");
                            goto a2;
                        }
                        if(x!=y && z!=w){
                            printf(red"WARNING"reset": Please choose correct line\n");
                            goto a2;
                        }
                        if(x==y && z==w){
                            printf(red"WARNING"reset": Please choose correct line\n");
                            goto a2;
                        }
                        t2=time(0);
                        td1= difftime(t2,t1)+td2;




                        if (x == y) {
                            if (z > w) {
                                int temp = z;
                                z = w;
                                w = temp;
                            } //swap z&w
                            x = x - 1;
                            if (arr1[x][z] != 205 && arr2[x][z] != 205 && arr[x][z]!=254) {
                                undo[index1]=x ;  undo[index2]=z ;
                                index1+=2 ;
                                index2+=2 ;
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
                            if (arr1[x][z] != 186 && arr2[x][z] != 186 && arr[x][z]!=254) {
                                undo[index1]=x ;  undo[index2]=z ;
                                index1+=2 ;
                                index2+=2 ;
                                arr[x][z] = 186;
                                arr1[x][z] = 186;
                            } else {
                                printf(red"WARNING:"reset" Please choose an empty line\n");
                                goto a2;
                            }
                        }

                        inc_moves(&p1);
                        rem--; f1 =0 ;
                        for(int k=0,l=1 ; k<50 && l<50 ; k+=2 ,l+=2) {
                            if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                                if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l]+1] == 186 && arr[arrBox[k]- 1][arrBox[l]] == 205 &&
                                    arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                    arr[arrBox[k]][arrBox[l]] = ch1;
                                    arr1[arrBox[k]][arrBox[l]] = ch1;
                                    arrBox[k] =0 ; arrBox[l] =0 ;
                                    system("cls") ;
                                    f1=1 ;
                                    inc_score(&p1);  //green score++

                                }
                                else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l]+1] == 186 && arr[box[k]- 1][box[l]] == 205 &&
                                         arr[box[k] + 1][box[l]] == 205) {
                                    arr[box[k]][box[l]] = ch1;
                                    arr1[box[k]][box[l]] = ch1;
                                    box[k] =0 ; box[l] =0 ;
                                    system("cls") ;
                                    f1=1 ;inc_score(&p1);		//green score++

                                }
                                else {continue;}
                            }
                            else { continue; }
                        }
                        //check if the player had done box to get additioal move
                        if (f1 == 1) {
                            u--;

                            if (rem==0) {
                                if (p1.score > p2.score) {
                                    top = fopen("top 10 player.text", "a");
                                    fprintf_s(top, play_o, co(p1.name), p1.score);  //open file and append struct of winner
                                    fclose(top);

                                    return end(p1.name, p1.score);
                                } else if (p1.score < p2.score) {

                                    top = fopen("top 10 player.text", "a");
                                    fprintf_s(top, play_o, co(p2.name), p2.score);  //open file and append struct of winner
                                    fclose(top);

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
                        //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                        //print 1 : 5 above grid
                        if (fBox == 1 ) {fBox = 0;goto az2;}
                        else {f1=0;}


                        cy2:
                        printf(red"\t\t\tNote:"reset"for any misunderstand go to settings then"cyan" About (4)\n"reset);
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
                                        printf(green"%c "reset, arr2[i6][j6]);

                                    } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch1) {
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
                                        printf(green"%c "reset, arr2[i6][j6]);

                                    } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch1) {
                                        printf(green"%c "reset, arr1[i6][j6]);
                                    } else {
                                        printf("%c ", arr[i6][j6]);
                                    }
                                }
                                printf("\n");
                            }
                        }
                        t = time_s(td1);
                        printf(yellow"\t\t\t\t\t   remaining lines =%d \n"reset, rem);
                        print_inf(p1, "green", p2, "green");
                        printf(green"\t\t\t    player %d turn\t\t\t\t"reset yellow"        time=%d:%d:%d \n"reset,2,t.hour,t.min,t.sec );
                        printf("\n  for undo at any step enter" cyan "\"undo\"" reset);
                        printf("\tfor settings at any step enter" cyan "\"row1: 0 & row2: 0 & col1: 0 & clo2: 0\"\n\n" reset);
                        b2:
                        t3 = time(0);
                        printf("Enter row 1 :");
                        again52:
                        gets(ch);
                        if (strcmp(ch, "undo") == 0) {
                            cs = 0;
                            for (int k = no_UN_RE - 1, l = no_UN_RE - 2; k >= 0 && l >= 0; k -= 2, l -= 2) {
                                if (undo[k] == 0 && undo[l] == 0) { continue; }
                                else {
                                    cs = 1;
                                    //for lines
                                    // when red enter undo plays of green decrease -- (moves green--) rem++
                                    //if(f2==1){ dec_move(&p2); }else{dec_move(&p1);}
                                    arr[undo[l]][undo[k]] = 32;
                                    arr1[undo[l]][undo[k]] = 32;
                                    arr2[undo[l]][undo[k]] = 32;
                                    undo[k] = 0;
                                    undo[l] = 0;
                                    index1 -= 2;
                                    index2 -= 2;
                                    rem++;
                                    //for boxes

                                    for (int k1 = 0, l1 = 1; k1 < 2 * n * m && l1 < 2 * n * m; k1 += 2, l1 += 2) {
                                        if (arr[undoArrBox[k1]][undoArrBox[l1]] != 32) {
                                            if (arr[undoArrBox[k1]][undoArrBox[l1] - 1] != 186 ||
                                                arr[undoArrBox[k1]][undoArrBox[l1] + 1] != 186 ||
                                                arr[undoArrBox[k1] - 1][undoArrBox[l1]] != 205 ||
                                                arr[undoArrBox[k1] + 1][undoArrBox[l1]] != 205) {
                                                arr[undoArrBox[k1]][undoArrBox[l1]] = 32;
                                                if(arr1[undoArrBox[k1]][undoArrBox[l1]] !=32){arr1[undoArrBox[k1]][undoArrBox[l1]] = 32;dec_score(&p1);sbox=1;}//score green --}
                                                else if(arr2[undoArrBox[k1]][undoArrBox[l1]] !=32){arr2[undoArrBox[k1]][undoArrBox[l1]] = 32;dec_score(&p2);sbox=2;} //score red --}
                                                box[add++] = undoArrBox[k1];
                                                box[add++] = undoArrBox[l1];
                                                fBox = 1;
                                            } else { continue; }
                                        } else { continue; }
                                    }
                                    if(sbox==1){dec_move(&p1);sbox=0;}
                                    else if(sbox==2){dec_move(&p2);sbox=0;}
                                    if(fBox!=1) {   if(f2==1){ dec_move(&p2); }else{dec_move(&p1);}   }

                                    if (fBox == 1) {
                                        u++;
                                        system("cls");
                                        goto az2;
                                    }

                                    i0--;
                                    system("cls");
                                    goto az2;
                                }
                            }
                            if (cs == 0) {
                                printf(red"warning:"reset"please enter a valid choice : ");
                                goto again52;
                            }
                        }//you need here to apply the arrays of undo and redo
                        else if (isdigit(ch[0])) {
                            if (atoi(ch) >= 0) { x = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice : ");
                                goto again52;
                            }
                        } else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again52;
                        }
                        b22:
                        printf("\nEnter row 2 :");
                        again62:
                        gets(ch);
                        if (strcmp(ch, "undo") == 0) { goto b2; }
                        else if (isdigit(ch[0])) {
                            if (atoi(ch) >= 0) { y = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice : ");
                                goto again62;
                            }
                        } else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again62;
                        }
                        b32:
                        printf("\nEnter col 1 :");
                        again72:
                        gets(ch);
                        if (strcmp(ch, "undo") == 0) { goto b22; }
                        else if (isdigit(ch[0])) {
                            if (atoi(ch) >= 0) { z = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice : ");
                                goto again72;
                            }
                        } else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again72;
                        }
                        printf("\nEnter col 2 :");
                        again82:
                        gets(ch);
                        if (strcmp(ch, "undo") == 0) { goto b32; }
                        else if (isdigit(ch[0])) {
                            if (atoi(ch) >= 0) { w = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice : ");
                                goto again82;
                            }
                        } else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again82;
                        }


                        if (x == 0 && y == 0 && z == 0 && w == 0) {

                            system("cls");
                            al22:
                            x5 = print_setting();
                            if (x5 == 1) {
                                system("cls");
                                goto cy2;
                            } else if (x5 == 2) {
                                system("cls");
                                n22:
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
                                    goto n22;
                                }

                                if (y1 == 0) {
                                    system("cls");
                                    goto az2;
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
                                fprintf_s(f,"mode=%d\n",2);
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
                                goto al22;

                            } else if (x5 == 3) {

                                return 5;//for go to  loud
                            } else if (x5 == 4) {// for go to About ?
                                x3 = about_after_settings();
                                if (x3 == 1) { return 7; }
                                else if (x3 == 2) {
                                    system("cls");
                                    goto ax2;
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
                            goto b2;
                        }
                        if (x != y && z != w) {
                            printf(red"WARNING"reset": Please choose correct line\n");
                            goto b2;
                        }
                        if (x == y && z == w) {
                            printf(red"WARNING"reset": Please choose correct line\n");
                            goto b2;
                        }
                        t4 = time(0);
                        td2 = difftime(t4, t3) + td1;




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
                                arr2[x][z] = 205;

                            } else {
                                printf(red"WARNING:"reset" Please choose an empty line\n");
                                goto b2;
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
                                arr2[x][z] = 186;
                            } else {
                                printf(red"WARNING:"reset" Please choose an empty line\n");
                                goto b2;
                            }
                        }
                        //red moves ++ , rem--
                        inc_moves(&p2);
                        rem--;
                        int f2 = 0;
                        for(int k=0,l=1 ; k<50 && l<50 ; k+=2 ,l+=2) {
                            if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                                if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l]+1] == 186 && arr[arrBox[k]- 1][arrBox[l]] == 205 &&
                                    arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                    arr[arrBox[k]][arrBox[l]] = ch2;
                                    arr2[arrBox[k]][arrBox[l]] = ch2;		//red score++
                                    arrBox[k] =0 ; arrBox[l] =0 ;
                                    system("cls") ;
                                    f2=1 ;
                                    inc_score(&p2);

                                }
                                else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l]+1] == 186 && arr[box[k]- 1][box[l]] == 205 &&
                                         arr[box[k] + 1][box[l]] == 205) {
                                    arr[box[k]][box[l]] = ch2;
                                    arr2[box[k]][box[l]] = ch2;
                                    box[k] =0 ; box[l] =0 ;
                                    inc_score(&p2);
                                    system("cls") ;
                                    f2=1 ;

                                }
                                else {continue;}
                            }
                            else { continue; }
                        }
                        if (f2 == 1) {
                            u--;
                            if (rem==0) {

                                if (p1.score > p2.score) {

                                    top = fopen("top 10 player.text", "a");
                                    fprintf_s(top, play_o,co(p1.name),
                                              p1.score); //open file and append struct of winner
                                    fclose(top);

                                    return end(p1.name, p1.score);
                                }
                                else if (p1.score < p2.score) {

                                    top = fopen("top 10 player.text","a");
                                    fprintf_s(top,play_o,co(p2.name),p2.score);  //open file and append struct of winner
                                    fclose(top);

                                    return end(p2.name, p2.score);
                                }
                                else {
                                    return end("draw", p1.score);

                                }

                            }


                            goto ax2;
                        }
                        system("cls");

                    }
                }
            }
        }
        else if (strcmp(colour1, "green") == 0 && strcmp(colour2, "magenta") == 0) {


            {
                for (i0; i0 < u; i0++) {


                    if (i0 % 2 == 0) {//player of color green
                        az3 :
                        if(fBox ==1 || f2==1){fBox=0 ; f2 =0 ;   goto ax3 ; }

                        by3:
                        printf(red"\t\t\tNote:"reset"for any misunderstand go to settings then"cyan" About (4)\n"reset);

                        //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                        //print 1 : 5 above grid
                        printf(" \t\t\t\t\t\t ");
                        for (int i1 = 0; i1 < 2 * m + 1; i1++) {
                            printf(" %d", i1 + 1);
                        }
                        printf("\n");

                        //print 1:5 beside the grid and print the grid using %c
                        for (int i2 = 0; i2 < 2 * n + 1; i2++) {
                            if(i2 ==10 || i2==9){
                                printf("\t\t\t\t\t       %d ", i2 + 1);

                                for (int j2= 0; j2 < 2 * m + 1; j2++) {
                                    if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                        printf(magenta"%c "reset, arr2[i2][j2]);

                                    } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                        printf(green"%c "reset, arr1[i2][j2]);
                                    } else {
                                        printf("%c ", arr[i2][j2]);
                                    }
                                }
                                printf("\n");
                            }
                            else {
                                printf("\t\t\t\t\t\t%d ", i2 + 1);

                                for (int j2= 0; j2 < 2 * m + 1; j2++) {
                                    if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                        printf(magenta"%c "reset, arr2[i2][j2]);

                                    } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                        printf(green"%c "reset, arr1[i2][j2]);
                                    } else {
                                        printf("%c ", arr[i2][j2]);
                                    }
                                }
                                printf("\n");
                            }
                        }
                        t = time_s(td2);
                        printf(yellow"\t\t\t\t\t   remaining lines =%d \n"reset, rem);
                        print_inf(p1, "green", p2, "magenta");
                        printf(green"\t\t\t    player %d turn\t\t\t\t"reset yellow"        time=%d:%d:%d \n"reset,1,t.hour,t.min,t.sec );
                        printf("\n  for undo at any step enter" cyan "\"undo\"" reset);
                        printf("\tfor settings at any step enter" cyan "\"row1: 0 & row2: 0 & col1: 0 & clo2: 0\"\n\n" reset);

                        //ask about move >>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                        a3:
                        t1 = time(0);
                        printf("Enter row 1 :");
                        again13:
                        gets (ch) ;
                        if (strcmp(ch,"undo")==0){
                            cs=0 ;
                            for(int k=no_UN_RE-1 , l=no_UN_RE-2 ; k >=0 && l>=0 ; k-=2 , l-=2 ){
                                if(undo[k]==0 && undo[l]==0){continue;}
                                else{
                                    cs=1 ;
                                    // undo for lines and get lines -- or total plays will increase after undo line
                                    // when green enter undo plays of red decrease -- (moves red --) rem++
                                    if(f1==1){ dec_move(&p1);} else { dec_move(&p2); }
                                    arr[undo[l]][undo[k]] = 32 ;
                                    arr1[undo[l]][undo[k]] = 32 ;
                                    arr2[undo[l]][undo[k]] = 32 ;
                                    undo[k] =0 ; undo[l] =0 ;
                                    index1-=2 ; index2-=2 ;
                                    rem++;
                                    //undo for boxes and get score -- if conditions are true

                                    for(int k2=0,l2=1 ; k2<2*n*m && l2<2*n*m ; k2+=2 ,l2+=2) {
                                        if (arr[undoArrBox[k2]][undoArrBox[l2]] != 32 ) {
                                            if (arr[undoArrBox[k2]][undoArrBox[l2] - 1] != 186 || arr[undoArrBox[k2]][undoArrBox[l2]+1] != 186 || arr[undoArrBox[k2]- 1][undoArrBox[l2]] != 205 ||
                                                arr[undoArrBox[k2] + 1][undoArrBox[l2]] != 205) {
                                                arr[undoArrBox[k2]][undoArrBox[l2]] = 32;
                                                if(arr1[undoArrBox[k2]][undoArrBox[l2]] !=32){arr1[undoArrBox[k2]][undoArrBox[l2]] = 32;dec_score(&p1);} //score green --
                                                else if(arr2[undoArrBox[k2]][undoArrBox[l2]] !=32){arr2[undoArrBox[k2]][undoArrBox[l2]] = 32;dec_score(&p2);}

                                                box[add++] = undoArrBox[k2] ; box[add++] = undoArrBox[l2] ;
                                                fBox=1 ;
                                            }

                                            else{continue;}
                                        }
                                        else { continue; }
                                    }
                                    if(fBox ==1 ){ u++; system("cls") ; goto ax3 ;}
                                    i0-- ;
                                    system("cls") ;
                                    goto ax3;
                                }
                            }
                            if(cs==0){printf(red"warning:"reset"please enter a valid choice : "); goto again13 ;}
                        }
                        else if (isdigit(ch[0])){
                            {if(atoi(ch)>=0){x=atoi(ch) ;}else{printf(red"warning:"reset"please enter a valid choice  : "); goto again13 ;}}
                        }
                        else {printf(red"warning:"reset"please enter a valid choice : "); goto again13 ;}
                        a333:
                        printf("\nEnter row 2 :");
                        again23:
                        gets (ch) ;
                        if (strcmp(ch,"undo")==0){goto a3 ;}
                        else if (isdigit(ch[0]))
                        {
                            if(atoi(ch)>=0){y=atoi(ch) ;}else{printf(red"warning:"reset"please enter a valid choice : "); goto again23 ;}
                        }
                        else {printf(red"warning:"reset"please enter a valid choice : "); goto again23 ;
                        }
                        a33:
                        printf("\nEnter col 1 :");
                        again33:
                        gets (ch) ;
                        if (strcmp(ch,"undo")==0){goto a333 ;  }
                        else if (isdigit(ch[0]))
                        {
                            if(atoi(ch)>=0){z=atoi(ch) ;}else{printf(red"warning:"reset"please enter a valid choice : "); goto again33 ;}
                        }
                        else {printf(red"warning:"reset"please enter a valid choice : "); goto again33 ;
                        }
                        printf("\nEnter col 2 :");
                        again43:
                        gets (ch) ;
                        if (strcmp(ch,"undo")==0){goto a33 ;  }
                        else if (isdigit(ch[0]))
                        {
                            if(atoi(ch)>=0){w=atoi(ch) ;}else{printf(red"warning:"reset"please enter a valid choice : "); goto again43 ;}
                        }
                        else {printf(red"warning:"reset"please enter a valid choice : "); goto again43 ;
                        }



                        if (x == 0 && y == 0 && z == 0 && w == 0) {

                            system("cls");
                            al3:
                            x5 = print_setting();
                            if (x5 == 1) {
                                system("cls");
                                goto by3;
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
                                    goto az3;
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

                                fprintf_s(f,"mode=%d\n",2);
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
                                goto al3;

                            } else if (x5 == 3) {

                                return 5;//for go to  loud
                            } else if (x5 == 4) {    // for go to About ?
                                x3=about_after_settings();

                                if(x3==1){return 7;}
                                else if(x3==2){system("cls");   goto az3 ;}
                                else if(x3==3){return 8 ;}


                            } else if (x5 == 5) {
                                return 7; //for main menu

                            } else if (x5 == 6) {

                                return 8; //for exit
                            }

                        }



                        if(x-y>2||y-x>2||z-w>2||w-z>2){
                            printf(red"WARNING"reset": Please choose correct line\n");
                            goto a3;
                        }
                        if(x!=y && z!=w){
                            printf(red"WARNING"reset": Please choose correct line\n");
                            goto a3;
                        }
                        if(x==y && z==w){
                            printf(red"WARNING"reset": Please choose correct line\n");
                            goto a3;
                        }
                        t2=time(0);
                        td1= difftime(t2,t1)+td2;




                        if (x == y) {
                            if (z > w) {
                                int temp = z;
                                z = w;
                                w = temp;
                            } //swap z&w
                            x = x - 1;
                            if (arr1[x][z] != 205 && arr2[x][z] != 205 && arr[x][z]!=254) {
                                undo[index1]=x ;  undo[index2]=z ;
                                index1+=2 ;
                                index2+=2 ;
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
                            if (arr1[x][z] != 186 && arr2[x][z] != 186 && arr[x][z]!=254) {
                                undo[index1]=x ;  undo[index2]=z ;
                                index1+=2 ;
                                index2+=2 ;
                                arr[x][z] = 186;
                                arr1[x][z] = 186;
                            } else {
                                printf(red"WARNING:"reset" Please choose an empty line\n");
                                goto a3;
                            }
                        }

                        inc_moves(&p1);
                        rem--; f1 =0 ;
                        for(int k=0,l=1 ; k<50 && l<50 ; k+=2 ,l+=2) {
                            if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                                if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l]+1] == 186 && arr[arrBox[k]- 1][arrBox[l]] == 205 &&
                                    arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                    arr[arrBox[k]][arrBox[l]] = ch1;
                                    arr1[arrBox[k]][arrBox[l]] = ch1;
                                    arrBox[k] =0 ; arrBox[l] =0 ;
                                    system("cls") ;
                                    f1=1 ;
                                    inc_score(&p1);  //green score++

                                }
                                else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l]+1] == 186 && arr[box[k]- 1][box[l]] == 205 &&
                                         arr[box[k] + 1][box[l]] == 205) {
                                    arr[box[k]][box[l]] = ch1;
                                    arr1[box[k]][box[l]] = ch1;
                                    box[k] =0 ; box[l] =0 ;
                                    system("cls") ;
                                    f1=1 ;inc_score(&p1);		//green score++

                                }
                                else {continue;}
                            }
                            else { continue; }
                        }
                        //check if the player had done box to get additioal move
                        if (f1 == 1) {
                            u--;

                            if (rem==0) {
                                if (p1.score > p2.score) {
                                    top = fopen("top 10 player.text", "a");
                                    fprintf_s(top, play_o, co(p1.name), p1.score);  //open file and append struct of winner
                                    fclose(top);

                                    return end(p1.name, p1.score);
                                } else if (p1.score < p2.score) {

                                    top = fopen("top 10 player.text", "a");
                                    fprintf_s(top, play_o, co(p2.name), p2.score);  //open file and append struct of winner
                                    fclose(top);

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
                        //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                        //print 1 : 5 above grid
                        if (fBox == 1 ) {fBox = 0;goto az3;}
                        else {f1=0;}


                        cy3:
                        printf(red"\t\t\tNote:"reset"for any misunderstand go to settings then"cyan" About (4)\n"reset);
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
                                        printf(magenta"%c "reset, arr2[i6][j6]);

                                    } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch1) {
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
                                        printf(magenta"%c "reset, arr2[i6][j6]);

                                    } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch1) {
                                        printf(green"%c "reset, arr1[i6][j6]);
                                    } else {
                                        printf("%c ", arr[i6][j6]);
                                    }
                                }
                                printf("\n");
                            }
                        }
                        t = time_s(td1);
                        printf(yellow"\t\t\t\t\t   remaining lines =%d \n"reset, rem);
                        print_inf(p1, "green", p2, "magenta");
                        printf(magenta"\t\t\t    player %d turn\t\t\t\t"reset yellow"        time=%d:%d:%d \n"reset,2,t.hour,t.min,t.sec );
                        printf("\n  for undo at any step enter" cyan "\"undo\"" reset);
                        printf("\tfor settings at any step enter" cyan "\"row1: 0 & row2: 0 & col1: 0 & clo2: 0\"\n\n" reset);
                        b3:
                        t3 = time(0);
                        printf("Enter row 1 :");
                        again53:
                        gets(ch);
                        if (strcmp(ch, "undo") == 0) {
                            cs = 0;
                            for (int k = no_UN_RE - 1, l = no_UN_RE - 2; k >= 0 && l >= 0; k -= 2, l -= 2) {
                                if (undo[k] == 0 && undo[l] == 0) { continue; }
                                else {
                                    cs = 1;
                                    //for lines
                                    // when red enter undo plays of green decrease -- (moves green--) rem++
                                    //if(f2==1){ dec_move(&p2); }else{dec_move(&p1);}
                                    arr[undo[l]][undo[k]] = 32;
                                    arr1[undo[l]][undo[k]] = 32;
                                    arr2[undo[l]][undo[k]] = 32;
                                    undo[k] = 0;
                                    undo[l] = 0;
                                    index1 -= 2;
                                    index2 -= 2;
                                    rem++;
                                    //for boxes

                                    for (int k1 = 0, l1 = 1; k1 < 2 * n * m && l1 < 2 * n * m; k1 += 2, l1 += 2) {
                                        if (arr[undoArrBox[k1]][undoArrBox[l1]] != 32) {
                                            if (arr[undoArrBox[k1]][undoArrBox[l1] - 1] != 186 ||
                                                arr[undoArrBox[k1]][undoArrBox[l1] + 1] != 186 ||
                                                arr[undoArrBox[k1] - 1][undoArrBox[l1]] != 205 ||
                                                arr[undoArrBox[k1] + 1][undoArrBox[l1]] != 205) {
                                                arr[undoArrBox[k1]][undoArrBox[l1]] = 32;
                                                if(arr1[undoArrBox[k1]][undoArrBox[l1]] !=32){arr1[undoArrBox[k1]][undoArrBox[l1]] = 32;dec_score(&p1);sbox=1;}//score green --}
                                                else if(arr2[undoArrBox[k1]][undoArrBox[l1]] !=32){arr2[undoArrBox[k1]][undoArrBox[l1]] = 32;dec_score(&p2);sbox=2;} //score red --}
                                                box[add++] = undoArrBox[k1];
                                                box[add++] = undoArrBox[l1];
                                                fBox = 1;
                                            } else { continue; }
                                        } else { continue; }
                                    }
                                    if(sbox==1){dec_move(&p1);sbox=0;}
                                    else if(sbox==2){dec_move(&p2);sbox=0;}
                                    if(fBox!=1) {   if(f2==1){ dec_move(&p2); }else{dec_move(&p1);}   }

                                    if (fBox == 1) {
                                        u++;
                                        system("cls");
                                        goto az3;
                                    }

                                    i0--;
                                    system("cls");
                                    goto az3;
                                }
                            }
                            if (cs == 0) {
                                printf(red"warning:"reset"please enter a valid choice : ");
                                goto again53;
                            }
                        }//you need here to apply the arrays of undo and redo
                        else if (isdigit(ch[0])) {
                            if (atoi(ch) >= 0) { x = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice : ");
                                goto again53;
                            }
                        } else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again53;
                        }
                        b33:
                        printf("\nEnter row 2 :");
                        again63:
                        gets(ch);
                        if (strcmp(ch, "undo") == 0) { goto b3; }
                        else if (isdigit(ch[0])) {
                            if (atoi(ch) >= 0) { y = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice : ");
                                goto again63;
                            }
                        } else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again63;
                        }
                        b333:
                        printf("\nEnter col 1 :");
                        again73:
                        gets(ch);
                        if (strcmp(ch, "undo") == 0) { goto b33; }
                        else if (isdigit(ch[0])) {
                            if (atoi(ch) >= 0) { z = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice : ");
                                goto again73;
                            }
                        } else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again73;
                        }
                        printf("\nEnter col 2 :");
                        again83:
                        gets(ch);
                        if (strcmp(ch, "undo") == 0) { goto b333; }
                        else if (isdigit(ch[0])) {
                            if (atoi(ch) >= 0) { w = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice : ");
                                goto again83;
                            }
                        } else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again83;
                        }


                        if (x == 0 && y == 0 && z == 0 && w == 0) {

                            system("cls");
                            al33:
                            x5 = print_setting();
                            if (x5 == 1) {
                                system("cls");
                                goto cy3;
                            } else if (x5 == 2) {
                                system("cls");
                                n23:
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
                                    goto n23;
                                }

                                if (y1 == 0) {
                                    system("cls");
                                    goto az3;
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
                                fprintf_s(f,"mode=%d\n",2);
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
                                goto al33;

                            } else if (x5 == 3) {

                                return 5;//for go to  loud
                            } else if (x5 == 4) {// for go to About ?
                                x3 = about_after_settings();
                                if (x3 == 1) { return 7; }
                                else if (x3 == 2) {
                                    system("cls");
                                    goto ax3;
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
                            goto b3;
                        }
                        if (x != y && z != w) {
                            printf(red"WARNING"reset": Please choose correct line\n");
                            goto b3;
                        }
                        if (x == y && z == w) {
                            printf(red"WARNING"reset": Please choose correct line\n");
                            goto b3;
                        }
                        t4 = time(0);
                        td2 = difftime(t4, t3) + td1;




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
                                arr2[x][z] = 205;

                            } else {
                                printf(red"WARNING:"reset" Please choose an empty line\n");
                                goto b3;
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
                                arr2[x][z] = 186;
                            } else {
                                printf(red"WARNING:"reset" Please choose an empty line\n");
                                goto b3;
                            }
                        }
                        //red moves ++ , rem--
                        inc_moves(&p2);
                        rem--;
                        int f2 = 0;
                        for(int k=0,l=1 ; k<50 && l<50 ; k+=2 ,l+=2) {
                            if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                                if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l]+1] == 186 && arr[arrBox[k]- 1][arrBox[l]] == 205 &&
                                    arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                    arr[arrBox[k]][arrBox[l]] = ch2;
                                    arr2[arrBox[k]][arrBox[l]] = ch2;		//red score++
                                    arrBox[k] =0 ; arrBox[l] =0 ;
                                    system("cls") ;
                                    f2=1 ;
                                    inc_score(&p2);

                                }
                                else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l]+1] == 186 && arr[box[k]- 1][box[l]] == 205 &&
                                         arr[box[k] + 1][box[l]] == 205) {
                                    arr[box[k]][box[l]] = ch2;
                                    arr2[box[k]][box[l]] = ch2;
                                    box[k] =0 ; box[l] =0 ;
                                    inc_score(&p2);
                                    system("cls") ;
                                    f2=1 ;

                                }
                                else {continue;}
                            }
                            else { continue; }
                        }
                        if (f2 == 1) {
                            u--;
                            if (rem==0) {

                                if (p1.score > p2.score) {

                                    top = fopen("top 10 player.text", "a");
                                    fprintf_s(top, play_o,co(p1.name),
                                              p1.score); //open file and append struct of winner
                                    fclose(top);

                                    return end(p1.name, p1.score);
                                }
                                else if (p1.score < p2.score) {

                                    top = fopen("top 10 player.text","a");
                                    fprintf_s(top,play_o,co(p2.name),p2.score);  //open file and append struct of winner
                                    fclose(top);

                                    return end(p2.name, p2.score);
                                }
                                else {
                                    return end("draw", p1.score);

                                }

                            }


                            goto ax3;
                        }
                        system("cls");

                    }
                }
            }
        }
        else if (strcmp(colour1, "green") == 0 && strcmp(colour2, "blue") == 0) {


            {
                for (i0; i0 < u; i0++) {


                    if (i0 % 2 == 0) {//player of color blue
                        az4 :
                        if(fBox ==1 || f2==1){fBox=0 ; f2 =0 ;   goto ax4 ; }

                        by4:
                        printf(red"\t\t\tNote:"reset"for any misunderstand go to settings then"cyan" About (4)\n"reset);

                        //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                        //print 1 : 5 above grid
                        printf(" \t\t\t\t\t\t ");
                        for (int i1 = 0; i1 < 2 * m + 1; i1++) {
                            printf(" %d", i1 + 1);
                        }
                        printf("\n");

                        //print 1:5 beside the grid and print the grid using %c
                        for (int i2 = 0; i2 < 2 * n + 1; i2++) {
                            if(i2 ==10 || i2==9){
                                printf("\t\t\t\t\t       %d ", i2 + 1);

                                for (int j2= 0; j2 < 2 * m + 1; j2++) {
                                    if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                        printf(blue"%c "reset, arr2[i2][j2]);

                                    } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                        printf(green"%c "reset, arr1[i2][j2]);
                                    } else {
                                        printf("%c ", arr[i2][j2]);
                                    }
                                }
                                printf("\n");
                            }
                            else {
                                printf("\t\t\t\t\t\t%d ", i2 + 1);

                                for (int j2= 0; j2 < 2 * m + 1; j2++) {
                                    if (arr2[i2][j2] == 205 || arr2[i2][j2] == 186 || arr2[i2][j2] == ch2) {
                                        printf(blue"%c "reset, arr2[i2][j2]);

                                    } else if (arr1[i2][j2] == 205 || arr1[i2][j2] == 186 || arr1[i2][j2] == ch1) {
                                        printf(green"%c "reset, arr1[i2][j2]);
                                    } else {
                                        printf("%c ", arr[i2][j2]);
                                    }
                                }
                                printf("\n");
                            }
                        }
                        t = time_s(td2);
                        printf(yellow"\t\t\t\t\t   remaining lines =%d \n"reset, rem);
                        print_inf(p1, "green", p2, "blue");
                        printf(green"\t\t\t    player %d turn\t\t\t\t"reset yellow"        time=%d:%d:%d \n"reset,1,t.hour,t.min,t.sec );
                        printf("\n  for undo at any step enter" cyan "\"undo\"" reset);
                        printf("\tfor settings at any step enter" cyan "\"row1: 0 & row2: 0 & col1: 0 & clo2: 0\"\n\n" reset);

                        //ask about move >>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                        a4:
                        t1 = time(0);
                        printf("Enter row 1 :");
                        again14:
                        gets (ch) ;
                        if (strcmp(ch,"undo")==0){
                            cs=0 ;
                            for(int k=no_UN_RE-1 , l=no_UN_RE-2 ; k >=0 && l>=0 ; k-=2 , l-=2 ){
                                if(undo[k]==0 && undo[l]==0){continue;}
                                else{
                                    cs=1 ;
                                    // undo for lines and get lines -- or total plays will increase after undo line
                                    // when blue enter undo plays of red decrease -- (moves red --) rem++
                                    if(f1==1){ dec_move(&p1);} else { dec_move(&p2); }
                                    arr[undo[l]][undo[k]] = 32 ;
                                    arr1[undo[l]][undo[k]] = 32 ;
                                    arr2[undo[l]][undo[k]] = 32 ;
                                    undo[k] =0 ; undo[l] =0 ;
                                    index1-=2 ; index2-=2 ;
                                    rem++;
                                    //undo for boxes and get score -- if conditions are true

                                    for(int k2=0,l2=1 ; k2<2*n*m && l2<2*n*m ; k2+=2 ,l2+=2) {
                                        if (arr[undoArrBox[k2]][undoArrBox[l2]] != 32 ) {
                                            if (arr[undoArrBox[k2]][undoArrBox[l2] - 1] != 186 || arr[undoArrBox[k2]][undoArrBox[l2]+1] != 186 || arr[undoArrBox[k2]- 1][undoArrBox[l2]] != 205 ||
                                                arr[undoArrBox[k2] + 1][undoArrBox[l2]] != 205) {
                                                arr[undoArrBox[k2]][undoArrBox[l2]] = 32;
                                                if(arr1[undoArrBox[k2]][undoArrBox[l2]] !=32){arr1[undoArrBox[k2]][undoArrBox[l2]] = 32;dec_score(&p1);} //score blue --
                                                else if(arr2[undoArrBox[k2]][undoArrBox[l2]] !=32){arr2[undoArrBox[k2]][undoArrBox[l2]] = 32;dec_score(&p2);}

                                                box[add++] = undoArrBox[k2] ; box[add++] = undoArrBox[l2] ;
                                                fBox=1 ;
                                            }

                                            else{continue;}
                                        }
                                        else { continue; }
                                    }
                                    if(fBox ==1 ){ u++; system("cls") ; goto ax4 ;}
                                    i0-- ;
                                    system("cls") ;
                                    goto ax4;
                                }
                            }
                            if(cs==0){printf(red"warning:"reset"please enter a valid choice : "); goto again14 ;}
                        }
                        else if (isdigit(ch[0])){
                            {if(atoi(ch)>=0){x=atoi(ch) ;}else{printf(red"warning:"reset"please enter a valid choice  : "); goto again14 ;}}
                        }
                        else {printf(red"warning:"reset"please enter a valid choice : "); goto again14 ;}
                        a44:
                        printf("\nEnter row 2 :");
                        again24:
                        gets (ch) ;
                        if (strcmp(ch,"undo")==0){goto a4 ;}
                        else if (isdigit(ch[0]))
                        {
                            if(atoi(ch)>=0){y=atoi(ch) ;}else{printf(red"warning:"reset"please enter a valid choice : "); goto again24 ;}
                        }
                        else {printf(red"warning:"reset"please enter a valid choice : "); goto again24 ;
                        }
                        a444:
                        printf("\nEnter col 1 :");
                        again34:
                        gets (ch) ;
                        if (strcmp(ch,"undo")==0){goto a44 ;  }
                        else if (isdigit(ch[0]))
                        {
                            if(atoi(ch)>=0){z=atoi(ch) ;}else{printf(red"warning:"reset"please enter a valid choice : "); goto again34 ;}
                        }
                        else {printf(red"warning:"reset"please enter a valid choice : "); goto again34 ;
                        }
                        printf("\nEnter col 2 :");
                        again44:
                        gets (ch) ;
                        if (strcmp(ch,"undo")==0){goto a444 ;  }
                        else if (isdigit(ch[0]))
                        {
                            if(atoi(ch)>=0){w=atoi(ch) ;}else{printf(red"warning:"reset"please enter a valid choice : "); goto again44 ;}
                        }
                        else {printf(red"warning:"reset"please enter a valid choice : "); goto again44 ;
                        }



                        if (x == 0 && y == 0 && z == 0 && w == 0) {

                            system("cls");
                            al4:
                            x5 = print_setting();
                            if (x5 == 1) {
                                system("cls");
                                goto by4;
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
                                    goto az4;
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

                                fprintf_s(f,"mode=%d\n",2);
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
                                printf(blue"\n\n\n                                                 save finished                              \n");
                                goto al4;

                            } else if (x5 == 3) {

                                return 5;//for go to  loud
                            } else if (x5 == 4) {    // for go to About ?
                                x3=about_after_settings();

                                if(x3==1){return 7;}
                                else if(x3==2){system("cls");   goto az4 ;}
                                else if(x3==3){return 8 ;}


                            } else if (x5 == 5) {
                                return 7; //for main menu

                            } else if (x5 == 6) {

                                return 8; //for exit
                            }

                        }



                        if(x-y>2||y-x>2||z-w>2||w-z>2){
                            printf(red"WARNING"reset": Please choose correct line\n");
                            goto a4;
                        }
                        if(x!=y && z!=w){
                            printf(red"WARNING"reset": Please choose correct line\n");
                            goto a4;
                        }
                        if(x==y && z==w){
                            printf(red"WARNING"reset": Please choose correct line\n");
                            goto a4;
                        }
                        t2=time(0);
                        td1= difftime(t2,t1)+td2;




                        if (x == y) {
                            if (z > w) {
                                int temp = z;
                                z = w;
                                w = temp;
                            } //swap z&w
                            x = x - 1;
                            if (arr1[x][z] != 205 && arr2[x][z] != 205 && arr[x][z]!=254) {
                                undo[index1]=x ;  undo[index2]=z ;
                                index1+=2 ;
                                index2+=2 ;
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
                            if (arr1[x][z] != 186 && arr2[x][z] != 186 && arr[x][z]!=254) {
                                undo[index1]=x ;  undo[index2]=z ;
                                index1+=2 ;
                                index2+=2 ;
                                arr[x][z] = 186;
                                arr1[x][z] = 186;
                            } else {
                                printf(red"WARNING:"reset" Please choose an empty line\n");
                                goto a4;
                            }
                        }

                        inc_moves(&p1);
                        rem--; f1 =0 ;
                        for(int k=0,l=1 ; k<50 && l<50 ; k+=2 ,l+=2) {
                            if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                                if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l]+1] == 186 && arr[arrBox[k]- 1][arrBox[l]] == 205 &&
                                    arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                    arr[arrBox[k]][arrBox[l]] = ch1;
                                    arr1[arrBox[k]][arrBox[l]] = ch1;
                                    arrBox[k] =0 ; arrBox[l] =0 ;
                                    system("cls") ;
                                    f1=1 ;
                                    inc_score(&p1);  //blue score++

                                }
                                else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l]+1] == 186 && arr[box[k]- 1][box[l]] == 205 &&
                                         arr[box[k] + 1][box[l]] == 205) {
                                    arr[box[k]][box[l]] = ch1;
                                    arr1[box[k]][box[l]] = ch1;
                                    box[k] =0 ; box[l] =0 ;
                                    system("cls") ;
                                    f1=1 ;inc_score(&p1);		//blue score++

                                }
                                else {continue;}
                            }
                            else { continue; }
                        }
                        //check if the player had done box to get additioal move
                        if (f1 == 1) {
                            u--;

                            if (rem==0) {
                                if (p1.score > p2.score) {
                                    top = fopen("top 10 player.text", "a");
                                    fprintf_s(top, play_o, co(p1.name), p1.score);  //open file and append struct of winner
                                    fclose(top);

                                    return end(p1.name, p1.score);
                                } else if (p1.score < p2.score) {

                                    top = fopen("top 10 player.text", "a");
                                    fprintf_s(top, play_o, co(p2.name), p2.score);  //open file and append struct of winner
                                    fclose(top);

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
                        //printing >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 1
                        //print 1 : 5 above grid
                        if (fBox == 1 ) {fBox = 0;goto az4;}
                        else {f1=0;}


                        cy4:
                        printf(red"\t\t\tNote:"reset"for any misunderstand go to settings then"cyan" About (4)\n"reset);
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
                                        printf(blue"%c "reset, arr2[i6][j6]);

                                    } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch1) {
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
                                        printf(blue"%c "reset, arr2[i6][j6]);

                                    } else if (arr1[i6][j6] == 205 || arr1[i6][j6] == 186 || arr1[i6][j6] == ch1) {
                                        printf(green"%c "reset, arr1[i6][j6]);
                                    } else {
                                        printf("%c ", arr[i6][j6]);
                                    }
                                }
                                printf("\n");
                            }
                        }
                        t = time_s(td1);
                        printf(yellow"\t\t\t\t\t   remaining lines =%d \n"reset, rem);
                        print_inf(p1, "green", p2, "blue");
                        printf(blue"\t\t\t    player %d turn\t\t\t\t"reset yellow"        time=%d:%d:%d \n"reset,2,t.hour,t.min,t.sec );
                        printf("\n  for undo at any step enter" cyan "\"undo\"" reset);
                        printf("\tfor settings at any step enter" cyan "\"row1: 0 & row2: 0 & col1: 0 & clo2: 0\"\n\n" reset);
                        b4:
                        t3 = time(0);
                        printf("Enter row 1 :");
                        again54:
                        gets(ch);
                        if (strcmp(ch, "undo") == 0) {
                            cs = 0;
                            for (int k = no_UN_RE - 1, l = no_UN_RE - 2; k >= 0 && l >= 0; k -= 2, l -= 2) {
                                if (undo[k] == 0 && undo[l] == 0) { continue; }
                                else {
                                    cs = 1;
                                    //for lines
                                    // when red enter undo plays of blue decrease -- (moves blue--) rem++
                                    //if(f2==1){ dec_move(&p2); }else{dec_move(&p1);}
                                    arr[undo[l]][undo[k]] = 32;
                                    arr1[undo[l]][undo[k]] = 32;
                                    arr2[undo[l]][undo[k]] = 32;
                                    undo[k] = 0;
                                    undo[l] = 0;
                                    index1 -= 2;
                                    index2 -= 2;
                                    rem++;
                                    //for boxes

                                    for (int k1 = 0, l1 = 1; k1 < 2 * n * m && l1 < 2 * n * m; k1 += 2, l1 += 2) {
                                        if (arr[undoArrBox[k1]][undoArrBox[l1]] != 32) {
                                            if (arr[undoArrBox[k1]][undoArrBox[l1] - 1] != 186 ||
                                                arr[undoArrBox[k1]][undoArrBox[l1] + 1] != 186 ||
                                                arr[undoArrBox[k1] - 1][undoArrBox[l1]] != 205 ||
                                                arr[undoArrBox[k1] + 1][undoArrBox[l1]] != 205) {
                                                arr[undoArrBox[k1]][undoArrBox[l1]] = 32;
                                                if(arr1[undoArrBox[k1]][undoArrBox[l1]] !=32){arr1[undoArrBox[k1]][undoArrBox[l1]] = 32;dec_score(&p1);sbox=1;}//score blue --}
                                                else if(arr2[undoArrBox[k1]][undoArrBox[l1]] !=32){arr2[undoArrBox[k1]][undoArrBox[l1]] = 32;dec_score(&p2);sbox=2;} //score red --}
                                                box[add++] = undoArrBox[k1];
                                                box[add++] = undoArrBox[l1];
                                                fBox = 1;
                                            } else { continue; }
                                        } else { continue; }
                                    }
                                    if(sbox==1){dec_move(&p1);sbox=0;}
                                    else if(sbox==2){dec_move(&p2);sbox=0;}
                                    if(fBox!=1) {   if(f2==1){ dec_move(&p2); }else{dec_move(&p1);}   }

                                    if (fBox == 1) {
                                        u++;
                                        system("cls");
                                        goto az4;
                                    }

                                    i0--;
                                    system("cls");
                                    goto az4;
                                }
                            }
                            if (cs == 0) {
                                printf(red"warning:"reset"please enter a valid choice : ");
                                goto again54;
                            }
                        }//you need here to apply the arrays of undo and redo
                        else if (isdigit(ch[0])) {
                            if (atoi(ch) >= 0) { x = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice : ");
                                goto again54;
                            }
                        } else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again54;
                        }
                        b44:
                        printf("\nEnter row 2 :");
                        again64:
                        gets(ch);
                        if (strcmp(ch, "undo") == 0) { goto b4; }
                        else if (isdigit(ch[0])) {
                            if (atoi(ch) >= 0) { y = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice : ");
                                goto again64;
                            }
                        } else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again64;
                        }
                        b444:
                        printf("\nEnter col 1 :");
                        again74:
                        gets(ch);
                        if (strcmp(ch, "undo") == 0) { goto b44; }
                        else if (isdigit(ch[0])) {
                            if (atoi(ch) >= 0) { z = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice : ");
                                goto again74;
                            }
                        } else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again74;
                        }
                        printf("\nEnter col 2 :");
                        again84:
                        gets(ch);
                        if (strcmp(ch, "undo") == 0) { goto b444; }
                        else if (isdigit(ch[0])) {
                            if (atoi(ch) >= 0) { w = atoi(ch); }
                            else {
                                printf(red"warning:"reset"please enter a valid choice : ");
                                goto again84;
                            }
                        } else {
                            printf(red"warning:"reset"please enter a valid choice : ");
                            goto again84;
                        }


                        if (x == 0 && y == 0 && z == 0 && w == 0) {

                            system("cls");
                            al44:
                            x5 = print_setting();
                            if (x5 == 1) {
                                system("cls");
                                goto cy4;
                            } else if (x5 == 2) {
                                system("cls");
                                n24:
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
                                    goto n24;
                                }

                                if (y1 == 0) {
                                    system("cls");
                                    goto az4;
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
                                fprintf_s(f,"mode=%d\n",2);
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
                                printf(blue"\n\n\n                                                 save finished                              \n");
                                goto al44;

                            } else if (x5 == 3) {

                                return 5;//for go to  loud
                            } else if (x5 == 4) {// for go to About ?
                                x3 = about_after_settings();
                                if (x3 == 1) { return 7; }
                                else if (x3 == 2) {
                                    system("cls");
                                    goto ax4;
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
                            goto b4;
                        }
                        if (x != y && z != w) {
                            printf(red"WARNING"reset": Please choose correct line\n");
                            goto b4;
                        }
                        if (x == y && z == w) {
                            printf(red"WARNING"reset": Please choose correct line\n");
                            goto b4;
                        }
                        t4 = time(0);
                        td2 = difftime(t4, t3) + td1;




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
                                arr2[x][z] = 205;

                            } else {
                                printf(red"WARNING:"reset" Please choose an empty line\n");
                                goto b4;
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
                                arr2[x][z] = 186;
                            } else {
                                printf(red"WARNING:"reset" Please choose an empty line\n");
                                goto b4;
                            }
                        }
                        //red moves ++ , rem--
                        inc_moves(&p2);
                        rem--;
                        int f2 = 0;
                        for(int k=0,l=1 ; k<50 && l<50 ; k+=2 ,l+=2) {
                            if ((arrBox[k] != 0 || box[k] != 0) && (arrBox[l] != 0 || box[l] != 0)) {
                                if (arr[arrBox[k]][arrBox[l] - 1] == 186 && arr[arrBox[k]][arrBox[l]+1] == 186 && arr[arrBox[k]- 1][arrBox[l]] == 205 &&
                                    arr[arrBox[k] + 1][arrBox[l]] == 205) {
                                    arr[arrBox[k]][arrBox[l]] = ch2;
                                    arr2[arrBox[k]][arrBox[l]] = ch2;		//red score++
                                    arrBox[k] =0 ; arrBox[l] =0 ;
                                    system("cls") ;
                                    f2=1 ;
                                    inc_score(&p2);

                                }
                                else if (arr[box[k]][box[l] - 1] == 186 && arr[box[k]][box[l]+1] == 186 && arr[box[k]- 1][box[l]] == 205 &&
                                         arr[box[k] + 1][box[l]] == 205) {
                                    arr[box[k]][box[l]] = ch2;
                                    arr2[box[k]][box[l]] = ch2;
                                    box[k] =0 ; box[l] =0 ;
                                    inc_score(&p2);
                                    system("cls") ;
                                    f2=1 ;

                                }
                                else {continue;}
                            }
                            else { continue; }
                        }
                        if (f2 == 1) {
                            u--;
                            if (rem==0) {

                                if (p1.score > p2.score) {

                                    top = fopen("top 10 player.text", "a");
                                    fprintf_s(top, play_o,co(p1.name),
                                              p1.score); //open file and append struct of winner
                                    fclose(top);

                                    return end(p1.name, p1.score);
                                }
                                else if (p1.score < p2.score) {

                                    top = fopen("top 10 player.text","a");
                                    fprintf_s(top,play_o,co(p2.name),p2.score);  //open file and append struct of winner
                                    fclose(top);

                                    return end(p2.name, p2.score);
                                }
                                else {
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
        else{return 10 ;}




    }
}