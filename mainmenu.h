int mainmenu () {
    b:
    system("");
    int i;
    char s[20];
    printf(cyan  "\t\t   ####  ####  #####  #######  #    #    ####  ####  #####  #    #  #   #         \n"reset);
    printf(cyan  "\t\t   #  #  #  #  #   #     #     ##   #    #  #  #  #  #      ##   #  #   #        \n"
                 "\t\t   #  ####  #  #####     #     # #  #    #  ####  #  #####  # #  #  #   #        \n"
                 "\t\t   #        #  #   #     #     #  # #    #        #  #      #  # #  #   #       \n"
                 "\t\t   #        #  #   #  #######  #    #    #        #  #####  #    #   ### ###             \n"
    reset );
    printf("\t\t  ");
    for(i=0;i<75;i++){
        printf(magenta"%c"reset,196);
    }
    printf("\n");


    printf( "1)"yellow "start game\n"reset);
    printf("2)"yellow "load game\n"reset);
    printf("3)"yellow"top ten player\n"reset);
    printf("4)"yellow"exit\n\n"reset);

    printf("please enter your choice (1,2,3,4) :  ");
    gets(s);
    if(strcmp(s,"1")==0||strcmp(s,"2")==0||strcmp(s,"3")==0||strcmp(s,"4")==0){
        if(strcmp(s,"1")==0){return 1;}
        else if(strcmp(s,"2")==0){return 2;}
        else if(strcmp(s,"3")==0){return 3;}
        else if(strcmp(s,"4")==0){return 4;}



    }
    else{
        system("cls");

        printf(red"\nWARNING:" reset" your choice is incorrect\n\n");

        goto b;

    }
}