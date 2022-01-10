typedef struct players{
    char name[20];
    int move,score;

} player ;
typedef struct times{
    int hour,min,sec;
} times;
player read_info(int x){
    player p ;
    if(x==1){

        printf("1)"yellow"enter your name for player 1 :"reset);
        fflush(stdin);
        gets(p.name);
        p.move=0;
        p.score=0;}
    else if(x==2){

        printf("2)"yellow"enter your name for player 2 :"reset);
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
}
// call by reference &
void inc_score(player *pl){
    pl->score++;
    return;
}// call by reference &
void dec_score(player *pl){
    pl->score--;
    return;
}
void dec_move(player *pl){
    pl->move--;
    return;
}


void print_inf(player pl,char colour[20],player pl2,char colour2[20]){
    system("");

    if(strcmp(colour,"red")==0&&strcmp(colour2,"blue")==0){
        printf(red"\t\t\tplayer1 name: %s\t\t\t\t"reset blue"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(red"\t\t\tplayer1 score: %d\t\t\t\t"reset blue"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(red"\t\t\tplayer1 number of moves :%d\t\t\t"reset blue"player2 number of moves :%d\n"reset,pl.move,pl2.move);
    }
    else if(strcmp(colour,"red")==0&&strcmp(colour2,"magenta")==0){
        printf(red"\t\t\tplayer1 name: %s\t\t\t\t"reset magenta"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(red"\t\t\tplayer1 score: %d\t\t\t\t"reset magenta"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(red"\t\t\tplayer1 number of moves :%d\t\t\t"reset magenta"player2 number of moves :%d\n"reset,pl.move,pl2.move);
    }
    else if(strcmp(colour,"red")==0&&strcmp(colour2,"green")==0){
        printf(red"\t\t\tplayer1 name: %s\t\t\t\t"reset green"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(red"\t\t\tplayer1 score: %d\t\t\t\t"reset green"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(red"\t\t\tplayer1 number of moves :%d\t\t\t"reset green"player2 number of moves :%d\n"reset,pl.move,pl2.move);
    }
    else if(strcmp(colour,"red")==0&&strcmp(colour2,"red")==0){
        printf(red"\t\t\tplayer1 name: %s\t\t\t\t"reset red"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(red"\t\t\tplayer1 score: %d\t\t\t\t"reset red"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(red"\t\t\tplayer1 number of moves :%d\t\t\t"reset red"player2 number of moves :%d\n"reset,pl.move,pl2.move);
    }
    else if(strcmp(colour,"blue")==0&&strcmp(colour2,"yellow")==0){
        printf(blue"\t\t\tplayer1 name: %s\t\t\t\t"reset yellow"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(blue"\t\t\tplayer1 score: %d\t\t\t\t"reset yellow"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(blue"\t\t\tplayer1 number of moves :%d\t\t\t"reset yellow"player2 number of moves :%d\n"reset,pl.move,pl2.move);
    }
    else if(strcmp(colour,"red")==0&&strcmp(colour2,"yellow")==0){
        printf(red"\t\t\tplayer1 name: %s\t\t\t\t"reset yellow"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(red"\t\t\tplayer1 score: %d\t\t\t\t"reset yellow"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(red"\t\t\tplayer1 number of moves :%d\t\t\t"reset yellow"player2 number of moves :%d\n"reset,pl.move,pl2.move);
    }
    else if(strcmp(colour,"magenta")==0&&strcmp(colour2,"yellow")==0){
        printf(magenta"\t\t\tplayer1 name: %s\t\t\t\t"reset yellow"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(magenta"\t\t\tplayer1 score: %d\t\t\t\t"reset yellow"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(magenta"\t\t\tplayer1 number of moves :%d\t\t\t"reset yellow"player2 number of moves :%d\n"reset,pl.move,pl2.move);
    }
    else if(strcmp(colour,"green")==0&&strcmp(colour2,"yellow")==0){
        printf(green"\t\t\tplayer1 name: %s\t\t\t\t"reset yellow"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(green"\t\t\tplayer1 score: %d\t\t\t\t"reset yellow"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(green"\t\t\tplayer1 number of moves :%d\t\t\t"reset yellow"player2 number of moves :%d\n"reset,pl.move,pl2.move);
    }
    else if(strcmp(colour,"yellow")==0&&strcmp(colour2,"blue")==0){
        printf(yellow"\t\t\tplayer1 name: %s\t\t\t\t"reset blue"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(yellow"\t\t\tplayer1 score: %d\t\t\t\t"reset blue"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(yellow"\t\t\tplayer1 number of moves :%d\t\t\t"reset blue"player2 number of moves :%d\n"reset,pl.move,pl2.move);
    }
    else if(strcmp(colour,"yellow")==0&&strcmp(colour2,"red")==0){
        printf(yellow"\t\t\tplayer1 name: %s\t\t\t\t"reset red"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(yellow"\t\t\tplayer1 score: %d\t\t\t\t"reset red"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(yellow"\t\t\tplayer1 number of moves :%d\t\t\t"reset red"player2 number of moves :%d\n"reset,pl.move,pl2.move);
    }
    else if(strcmp(colour,"yellow")==0&&strcmp(colour2,"magenta")==0){
        printf(yellow"\t\t\tplayer1 name: %s\t\t\t\t"reset magenta"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(yellow"\t\t\tplayer1 score: %d\t\t\t\t"reset magenta"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(yellow"\t\t\tplayer1 number of moves :%d\t\t\t"reset magenta"player2 number of moves :%d\n"reset,pl.move,pl2.move);
    }
    else if(strcmp(colour,"yellow")==0&&strcmp(colour2,"green")==0){
        printf(yellow"\t\t\tplayer1 name: %s\t\t\t\t"reset green"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(yellow"\t\t\tplayer1 score: %d\t\t\t\t"reset green"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(yellow"\t\t\tplayer1 number of moves :%d\t\t\t"reset green"player2 number of moves :%d\n"reset,pl.move,pl2.move);
    }



    else  if(strcmp(colour,"blue")==0&&strcmp(colour2,"red")==0){
        printf(blue"\t\t\tplayer1 name: %s\t\t\t\t"reset red"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(blue"\t\t\tplayer1 score: %d\t\t\t\t"reset red"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(blue"\t\t\tplayer1 number of moves :%d\t\t\t"reset red"player2 number of moves :%d\n"reset,pl.move,pl2.move);}

    else if(strcmp(colour,"blue")==0&&strcmp(colour2,"magenta")==0){
        printf(blue"\t\t\tplayer1 name: %s\t\t\t\t"reset magenta"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(blue"\t\t\tplayer1 score: %d\t\t\t\t"reset magenta"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(blue"\t\t\tplayer1 number of moves :%d\t\t\t"reset magenta"player2 number of moves :%d\n"reset,pl.move,pl2.move);
    }
    else if(strcmp(colour,"blue")==0&&strcmp(colour2,"green")==0){
        printf(blue"\t\t\tplayer1 name: %s\t\t\t\t"reset green"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(blue"\t\t\tplayer1 score: %d\t\t\t\t"reset green"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(blue"\t\t\tplayer1 number of moves :%d\t\t\t"reset green"player2 number of moves :%d\n"reset,pl.move,pl2.move);
    }
    else if(strcmp(colour,"blue")==0&&strcmp(colour2,"blue")==0){
        printf(blue"\t\t\tplayer1 name: %s\t\t\t\t"reset blue"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(blue"\t\t\tplayer1 score: %d\t\t\t\t"reset blue"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(blue"\t\t\tplayer1 number of moves :%d\t\t\t"reset blue"player2 number of moves :%d\n"reset,pl.move,pl2.move);
    }
    else if (strcmp(colour,"magenta")==0&&strcmp(colour2,"magenta")==0){
        printf(magenta"\t\t\tplayer1 name: %s\t\t\t\t"reset magenta"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(magenta"\t\t\tplayer1 score: %d\t\t\t\t"reset magenta"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(magenta"\t\t\tplayer1 number of moves :%d\t\t\t"reset magenta"player2 number of moves :%d\n"reset,pl.move,pl2.move);
    }

    else if(strcmp(colour,"magenta")==0&&strcmp(colour2,"blue")==0){
        printf(magenta"\t\t\tplayer1 name: %s\t\t\t\t"reset blue"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(magenta"\t\t\tplayer1 score: %d\t\t\t\t"reset blue"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(magenta"\t\t\tplayer1 number of moves :%d\t\t\t"reset blue"player2 number of moves :%d\n"reset,pl.move,pl2.move);
    }
    else if(strcmp(colour,"magenta")==0&&strcmp(colour2,"red")==0){
        printf(magenta"\t\t\tplayer1 name: %s\t\t\t\t"reset red"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(magenta"\t\t\tplayer1 score: %d\t\t\t\t"reset red"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(magenta"\t\t\tplayer1 number of moves :%d\t\t\t"reset red"player2 number of moves :%d\n"reset,pl.move,pl2.move);
    }
    else if(strcmp(colour,"magenta")==0&&strcmp(colour2,"green")==0){
        printf(magenta"\t\t\tplayer1 name: %s\t\t\t\t"reset green"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(magenta"\t\t\tplayer1 score: %d\t\t\t\t\t"reset green"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(magenta"\t\t\tplayer1 number of moves :%d\t\t\t"reset green"player2 number of moves :%d\n"reset,pl.move,pl2.move);
    }
    else if(strcmp(colour,"green")==0&&strcmp(colour2,"blue")==0){
        printf(green"\t\t\tplayer1 name: %s\t\t\t\t"reset blue"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(green"\t\t\tplayer1 score: %d\t\t\t\t"reset blue"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(green"\t\t\tplayer1 number of moves :%d\t\t\t"reset blue"player2 number of moves :%d\n"reset,pl.move,pl2.move);
    }
    else if(strcmp(colour,"green")==0&&strcmp(colour2,"green")==0){
        printf(green"\t\t\tplayer1 name: %s\t\t\t\t"reset green"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(green"\t\t\tplayer1 score: %d\t\t\t\t"reset green"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(green"\t\t\tplayer1 number of moves :%d\t\t\t"reset green"player2 number of moves :%d\n"reset,pl.move,pl2.move);
    }
   else if(strcmp(colour,"green")==0&&strcmp(colour2,"red")==0){
        printf(green"\t\t\tplayer1 name: %s\t\t\t\t"reset red"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(green"\t\t\tplayer1 score: %d\t\t\t\t"reset red"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(green"\t\t\tplayer1 number of moves :%d\t\t\t"reset red"player2 number of moves :%d\n"reset,pl.move,pl2.move);
    }
    else if(strcmp(colour,"green")==0&&strcmp(colour2,"magenta")==0){
        printf(green"\t\t\tplayer1 name: %s\t\t\t\t"reset magenta"player2 name: %s\n"reset,pl.name,pl2.name);
        printf(green"\t\t\tplayer1 score: %d\t\t\t\t"reset magenta"player2 score: %d\n"reset,pl.score,pl2.score);
        printf(green"\t\t\tplayer1 number of moves :%d\t\t\t"reset magenta"player2 number of moves :%d\n"reset,pl.move,pl2.move);
    }

    return;
}
times time_s(int n){
    times t;
    t.sec=n%60;
    t.hour=n/3600;
    t.min=((n/3600.0)-t.hour)*60;


    return t ;
}// to convert sec to ho,min,sec

