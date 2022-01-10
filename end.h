#include<windows.h>

char convert ( char ch){
    int i,y;
    if(ch>='a'&&ch<='z'){
        ch=ch-32;
    }

    for(i=65;i<=90;i++){
        if(ch==i){
            y=i;
        }

    }

    return y;

}// convert ch to capital letter and return its ascii code


COORD coord= {0,0};
void go(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);  //this function from website
}

int end(char s[],int m){

    system("");
    int i;
    char l[20];




    go(38,7);printf(cyan"%c"reset,201);
    for(i=1;i<36;i++){
        printf(cyan"%c"reset,205);
    }
    printf(cyan"%c"reset,187);
    go(38,8);printf(cyan"%c"reset,186);
    for(i=1;i<36;i++){
        printf("%c",32);
    }
    printf(cyan"%c"reset,186);


    go(38,9);printf(cyan"%c"reset,186);
    for(i=1;i<36;i++){
        printf("%c",32);
    }
    printf(cyan"%c"reset,186);
    go(38,10);printf(cyan"%c"reset,186);
    for(i=1;i<36;i++){
        printf("%c",32);
    }
    printf(cyan"%c"reset,186);
    go(38,11);printf(cyan"%c"reset,186);
    for(i=1;i<36;i++){
        printf("%c",32);
    }
    printf(cyan"%c"reset,186);


    go(38,12);printf(cyan"%c"reset,186);
    for(i=1;i<36;i++){
        printf("%c",32);
    }
    printf(cyan"%c"reset,186);


    go(38,13);printf(cyan"%c"reset,186);
    for(i=1;i<36;i++){
        printf("%c",32);
    }
    printf(cyan"%c"reset,186);

    go(38,14);printf(cyan"%c"reset,200);
    for(i=1;i<36;i++){
        printf(cyan"%c"reset,205);
    }
    printf(cyan"%c"reset,188);

    if(strcmp(s,"draw")==0){

        go(39,8);
        printf( red"      end game with "reset":%s",s);
        go(39,9);
        printf(cyan"     ========================"reset);
        go(39,10);
        printf(red"the score is:"reset"%d",m);

        go(39,12);printf("1)"yellow"to return to main menu"reset);
        go(39,13);printf("2)"yellow"to exit "reset);

        go(39,16);
        l2:
        printf("enter your choice (1,2): ");
        scanf("%s",l);
        if(strcmp(l,"1")==0){return 1;}
        else if(strcmp(l,"2")==0){return 2;}
        else { printf(red"\t\t\t\tWARNING:"reset" your choice is incorrect\n ");  goto l2 ;}

    }

    else {
        go(39,8);
        printf( red"      the winner is "reset":%s",s);
        go(39,9);
        printf(cyan"     ========================"reset);
        go(39,10);
        printf(red"your score is:"reset"%d",m);

        go(39,12);printf("1)"yellow"to return to main menu"reset);
        go(39,13);printf("2)"yellow"to exit "reset);

        go(39,16);
        l1:
        printf("enter your choice (1,2): ");
        scanf("%s",l);
        if(strcmp(l,"1")==0){return 1;}
        else if(strcmp(l,"2")==0){return 2;}
        else { printf(red"WARNING:"reset" your choice is incorrect\n ");  goto l1 ;}



    }
    
    
    }