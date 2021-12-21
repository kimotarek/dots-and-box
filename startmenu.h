
int startmenu ()
{
    system("cls");
    char x[20] ,y[20] , z[20] ;
    a:
    system("") ;
    printf("Please choose your suitable difficulty :\n") ;
    printf("(1)"yellow"expert"reset) ;
    printf("        ""(2)"yellow"beginner\n"reset) ;
    printf("(3)"yellow"back\n"reset) ;
    printf("please enter your choice (1,2,3): ") ;
    gets(x) ;
    if(strcmp(x,"3")==0) { return 0 ;}
    if (strcmp(x,"1")==0||strcmp(x,"2")==0)
    {
        system("cls") ;

    }
    else
    {
        system("cls") ;
        printf("\n"red"WARNING : "reset"your choice is incorrect\n\n") ;
        goto a ;
     }

    b:
    printf("choose your suitable mode: \n") ;
    printf("(1)"yellow"player VS computer"reset) ;
    printf("        ""(2)"yellow"player VS player\n"reset) ;
    printf("(3)"yellow"back\n"reset) ;
    printf("please enter your choice (1,2,3): ") ;
    gets(y) ;
    if(strcmp(y,"3")==0) { system("cls") ; goto a;}
    if (strcmp(y,"1")==0||strcmp(y,"2")==0)
    {
        system("cls") ;

    }
    else
    {
        system("cls") ;
        printf("\n"red"WARNING : "reset"your choice is incorrect\n\n") ;
        goto b ;
     }

    c:

    printf("choose your turn :\n") ;
    printf("(1)"yellow"first player1"reset) ;
    printf("        ""(2)"yellow"Second player2\n"reset) ;
    printf("(3)"yellow"back\n"reset) ;
    printf("please enter your choice (1,2,3): ") ;
    gets(z) ;
    if(strcmp(z,"3")==0) {system("cls") ; goto b ;}
    if (strcmp(z,"1")==0||strcmp(z,"2")==0){}
    else
    {
        system("cls") ;
        printf("\n"red"WARNING : "reset"your choice is incorrect\n\n") ;
        goto c ;
     }
    if(strcmp(x,"1")==0&&strcmp(y,"2")==0&&strcmp(z,"2")==0){return 1 ;}//expert & player vs player & second player2 = 1
    if(strcmp(x,"1")==0&&strcmp(y,"2")==0&&strcmp(z,"1")==0){return 2;}//expert & player vs player & first player1 =2
    if(strcmp(x,"1")==0&&strcmp(y,"1")==0&&strcmp(z,"2")==0){return 3;}//expert & player vs computer & second player2 =3
    if(strcmp(x,"1")==0&&strcmp(y,"1")==0&&strcmp(z,"1")==0){return 4;}//expert & player vs computer & first player1 =4
    if(strcmp(x,"2")==0&&strcmp(y,"2")==0&&strcmp(z,"2")==0){return 5;}//beginner & player vs player & second player1 =5
    if(strcmp(x,"2")==0&&strcmp(y,"2")==0&&strcmp(z,"1")==0){return 6;}//beginner & player vs player & first player1 =6
    if(strcmp(x,"2")==0&&strcmp(y,"1")==0&&strcmp(z,"2")==0){return 7;}//beginner & player vs computer & second player1 =7
    if(strcmp(x,"2")==0&&strcmp(y,"1")==0&&strcmp(z,"1")==0){return 8;}//beginner & player vs computer & first player1 =8

}