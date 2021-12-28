typedef struct players{
    char name[20];
    int move,score;

} player ;
player read_info(int x){
    player p ;
    if(x==1){

        printf("enter your name for player 1 :");
        fflush(stdin);
        gets(p.name);
        p.move=0;
        p.score=0;}
    else if(x==2){

        printf("\n enter your name for player 2 :");
        fflush(stdin);
        gets(p.name);
        p.move=0;
        p.score=0;}


    return(p);

}//x->number of player 1 or 2
void print_info(player pl,int n,char colour[20]){
    system("");
    if(n==1){
        if(strcmp(colour,"red")==0){
            printf(red"player1 name: %s\n"reset,pl.name);
            printf(red"player1 score: %d\n"reset,pl.score);
            printf(red"player1 number of moves :%d\n"reset,pl.move);
        }
        else if(strcmp(colour,"blue")==0){
            printf(blue"player1 name: %s\n"reset,pl.name);
            printf(blue"player1 score: %d\n"reset,pl.score);
            printf(blue"player1 number of moves :%d\n"reset,pl.move);
        }
        else if(strcmp(colour,"green")==0){
            printf(green"player1 name: %s\n"reset,pl.name);
            printf(green"player1 score: %d\n"reset,pl.score);
            printf(green"player1 number of moves :%d\n"reset,pl.move);
        }
        else if(strcmp(colour,"magenta")==0){
            printf(magenta"player1 name: %s\n"reset,pl.name);
            printf(magenta"player1 score: %d\n"reset,pl.score);
            printf(magenta"player1 number of moves :%d\n"reset,pl.move);
        }

    }
    else if(n==2){
        if(strcmp(colour,"red")==0){
            printf(red  "player2 name: %s\n"reset,pl.name);
            printf(red "player2 score: %d\n"reset,pl.score);
            printf(red "player2 number of moves :%d\n"reset,pl.move);
        }
        else if(strcmp(colour,"blue")==0){
            printf(blue"player2 name: %s\n"reset,pl.name);
            printf(blue"player2 score: %d\n"reset,pl.score);
            printf(blue"player2 number of moves :%d\n"reset,pl.move);
        }
        else if(strcmp(colour,"green")==0){
            printf(green"player2 name: %s\n"reset,pl.name);
            printf(green"player2 score: %d\n"reset,pl.score);
            printf(green"player2 number of moves :%d\n"reset,pl.move);
        }
        else if(strcmp(colour,"magenta")==0){
            printf(magenta"player2 name: %s\n"reset,pl.name);
            printf(magenta"player2 score: %d\n"reset,pl.score);
            printf(magenta"player2 number of moves :%d\n"reset,pl.move);
        }

    }
    return;
}     //n number of player 1 or 2  print one palyer
void inc_moves(player *pl){
    pl->move++;
    return;
} // call by reference &
void inc_score(player *pl){
    pl->score++;
    return;
}// call by reference &


