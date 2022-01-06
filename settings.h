

int print_setting(){
    system("");
    int i;
    char ls[20];



    ll:

    go(38,7);printf(magenta"%c"reset,201);
    for(i=1;i<36;i++){
        printf(magenta"%c"reset,205);
    }
    printf(magenta"%c"reset,187);
    go(38,8);printf(magenta"%c"reset,186);
    for(i=1;i<36;i++){
        printf("%c",32);
    }
    printf(magenta"%c"reset,186);


    go(38,9);printf(magenta"%c"reset,186);
    for(i=1;i<36;i++){
        printf("%c",32);
    }
    printf(magenta"%c"reset,186);
    go(38,10);printf(magenta"%c"reset,186);
    for(i=1;i<36;i++){
        printf("%c",32);
    }
    printf(magenta"%c"reset,186);
    go(38,11);printf(magenta"%c"reset,186);
    for(i=1;i<36;i++){
        printf("%c",32);
    }
    printf(magenta"%c"reset,186);


    go(38,12);printf(magenta"%c"reset,186);
    for(i=1;i<36;i++){
        printf("%c",32);
    }
    printf(magenta"%c"reset,186);


    go(38,13);printf(magenta"%c"reset,186);
    for(i=1;i<36;i++){
        printf("%c",32);
    }
    printf(magenta"%c"reset,186);
    go(38,14);printf(magenta"%c"reset,186);
    for(i=1;i<36;i++){
        printf("%c",32);
    }
    printf(magenta"%c"reset,186);
    go(38,15);printf(magenta"%c"reset,186);
    for(i=1;i<36;i++){
        printf("%c",32);
    }
    printf(magenta"%c"reset,186);
    go(38,16);printf(magenta"%c"reset,186);
    for(i=1;i<36;i++){
        printf("%c",32);
    }
    printf(magenta"%c"reset,186);

    go(38,17);printf(magenta"%c"reset,200);
    for(i=1;i<36;i++){
        printf(magenta"%c"reset,205);
    }
    printf(magenta"%c"reset,188);


        go(39,8);
        printf(cyan"             settings        "reset);
        go(39,9);
        printf(magenta"     ========================"reset);
        go(39,11);printf("1)"yellow"return to game "reset);
        go(39,12);printf("2)"yellow"for save"reset);
        go(39,13);printf("3)"yellow"for load "reset);
        go(39,14);printf("4)"yellow"for About"reset);
        go(39,15);printf("5)"yellow"to return to main menu"reset);
        go(39,16);printf("6)"yellow"exit"reset);


        go(39,19);
        printf("enter your choice (1,2,3,4,5,6): ");
        fflush(stdin);
        gets(ls);
        if(strcmp(ls,"1")==0){return 1;}
        else if(strcmp(ls,"2")==0){return 2;}
        else if(strcmp(ls,"3")==0){return 3;}
        else if(strcmp(ls,"4")==0){return 4;}
        else if(strcmp(ls,"5")==0){return 5;}
        else if(strcmp(ls,"6")==0){return 6;}
        else {system("cls"); printf(red"WARNING:"reset" your choice is incorrect\n ");  goto ll ;}








}