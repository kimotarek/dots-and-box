
int startmenu ()
{
    system("cls");
    char x[20] ,y[20] , z[20] ,w[20],k[20];
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
    printf("(1)"yellow"first play "reset) ;
    printf("        ""(2)"yellow"Second play \n"reset) ;
    printf("(3)"yellow"back\n"reset) ;
    printf("please enter your choice (1,2,3): ") ;
    gets(z) ;
    if(strcmp(z,"3")==0) {system("cls") ; goto b ;}
    if (strcmp(z,"1")==0||strcmp(z,"2")==0){
        system("cls");
    }
    else
    {
        system("cls") ;
        printf("\n"red"WARNING : "reset"your choice is incorrect\n\n") ;
        goto c ;
     }



if(strcmp(y,"2")==0){

    d:

      printf("choose the colour of player1\n");
      printf("(1)"yellow"Red"reset) ;
    printf("          ""(2)"yellow"Blue\n"reset) ;
     printf("(3)"yellow"Green"reset) ;
    printf("        ""(4)"yellow"magenta\n"reset) ;
    printf("(5)"yellow"back\n"reset) ;
    printf("please enter your choice (1,2,3,4,5): ") ; 
    gets(w);

     if(strcmp(w,"5")==0) {system("cls") ; goto c ;}
        if (strcmp(w,"1")==0||strcmp(w,"2")==0||strcmp(w,"3")==0||strcmp(w,"4")==0)
        {
                    system("cls");
        }
        else
         {
          system("cls") ;
         printf("\n"red"WARNING : "reset"your choice is incorrect\n\n") ;
         goto d ;
         }

q:
  printf("choose the colour of player2\n");
      printf("(1)"yellow"Red"reset) ;
    printf("          ""(2)"yellow"Blue\n"reset) ;
     printf("(3)"yellow"Green"reset) ;
    printf("        ""(4)"yellow"magenta\n"reset) ;
    printf("(5)"yellow"back\n"reset) ;
    printf("please enter your choice (1,2,3,4,5): ") ; 
    gets(k);

     if(strcmp(k,"5")==0) {system("cls") ; goto d ;}
        if (strcmp(k,"1")==0||strcmp(k,"2")==0||strcmp(k,"3")==0||strcmp(k,"4")==0)
        {
        }
        else
         {
          system("cls") ;
         printf("\n"red"WARNING : "reset"your choice is incorrect\n\n") ;
         goto q ;
         }

}

else if(strcmp(y,"1")==0){
    l:
    printf("choose the colour of player1\n");
      printf("(1)"yellow"Red"reset) ;
    printf("          ""(2)"yellow"Blue\n"reset) ;
     printf("(3)"yellow"Green"reset) ;
    printf("        ""(4)"yellow"magenta\n"reset) ;
    printf("(5)"yellow"back\n"reset) ;
    printf("please enter your choice (1,2,3,4,5): ") ; 
    gets(w);

     if(strcmp(w,"5")==0) {system("cls") ; goto c ;}
        if (strcmp(w,"1")==0||strcmp(w,"2")==0||strcmp(w,"3")==0||strcmp(w,"4")==0)
        {
        
        }
        else
         {
          system("cls") ;
         printf("\n"red"WARNING : "reset"your choice is incorrect\n\n") ;
         goto l ;
         }




}





if(strcmp(x,"1")==0&&strcmp(y,"2")==0&&strcmp(z,"2")==0&&strcmp(w,"1")==0&&strcmp(k,"1")==0){return 1 ;}//expert & player1 vs player & second player & red1 vs red = 1
else if(strcmp(x,"1")==0&&strcmp(y,"2")==0&&strcmp(z,"1")==0&&strcmp(w,"1")==0&&strcmp(k,"2")==0){return 2;}//expert & player1 vs player & first player & red1 vs blue =2

    
else if(strcmp(x,"2")==0&&strcmp(y,"2")==0&&strcmp(z,"2")==0&&strcmp(w,"1")==0&&strcmp(k,"3")==0){return 3;}//beginner & player1 vs player & second player & red1 vs green =3
else if(strcmp(x,"2")==0&&strcmp(y,"2")==0&&strcmp(z,"1")==0&&strcmp(w,"1")==0&&strcmp(k,"4")==0){return 4;}//beginner & player1 vs player & first player & red1 vs magenta =4

   

else if(strcmp(x,"1")==0&&strcmp(y,"2")==0&&strcmp(z,"2")==0&&strcmp(w,"2")==0&&strcmp(k,"1")==0){return 5 ;}//expert & player1 vs player & second player & blue1 vs red =5
else if(strcmp(x,"1")==0&&strcmp(y,"2")==0&&strcmp(z,"1")==0&&strcmp(w,"2")==0&&strcmp(k,"2")==0){return 6;}//expert & player1 vs player & first player & blue1 vs blue =6

    

else if(strcmp(x,"2")==0&&strcmp(y,"2")==0&&strcmp(z,"2")==0&&strcmp(w,"2")==0&&strcmp(k,"3")==0){return 7;}//beginner & player1 vs player & second player & blue1 vs green =7
else if(strcmp(x,"2")==0&&strcmp(y,"2")==0&&strcmp(z,"1")==0&&strcmp(w,"2")==0&&strcmp(k,"4")==0){return 8;}//beginner & player1 vs player & first player & blue1 vs magenta =8

else if(strcmp(x,"1")==0&&strcmp(y,"2")==0&&strcmp(z,"2")==0&&strcmp(w,"3")==0&&strcmp(k,"1")==0){return 9 ;}//expert & player1 vs player & second player & green1 vs red =9
else if(strcmp(x,"1")==0&&strcmp(y,"2")==0&&strcmp(z,"1")==0&&strcmp(w,"3")==0&&strcmp(k,"2")==0){return 10;}//expert & player1 vs player & first player & green1 vs blue =10

    

else if(strcmp(x,"2")==0&&strcmp(y,"2")==0&&strcmp(z,"2")==0&&strcmp(w,"3")==0&&strcmp(k,"3")==0){return 11;}//beginner & player1 vs player & second player1 & green1 vs green =11
else if(strcmp(x,"2")==0&&strcmp(y,"2")==0&&strcmp(z,"1")==0&&strcmp(w,"3")==0&&strcmp(k,"4")==0){return 12;}//beginner & player1 vs player & first player1 & green1 vs magenta =12



else if(strcmp(x,"1")==0&&strcmp(y,"2")==0&&strcmp(z,"2")==0&&strcmp(w,"4")==0&&strcmp(k,"1")==0){return 13 ;}//expert & player1 vs player & second player2 & magenta1 vs red =13
else if(strcmp(x,"1")==0&&strcmp(y,"2")==0&&strcmp(z,"1")==0&&strcmp(w,"4")==0&&strcmp(k,"2")==0){return 14;}//expert & player1 vs player & first player1 & magenta1 vs blue =14

    
else if(strcmp(x,"2")==0&&strcmp(y,"2")==0&&strcmp(z,"2")==0&&strcmp(w,"4")==0&&strcmp(k,"3")==0){return 15;}//beginner & player1 vs player & second player1 & magenta1 vs green =15
else if(strcmp(x,"2")==0&&strcmp(y,"2")==0&&strcmp(z,"1")==0&&strcmp(w,"4")==0&&strcmp(k,"4")==0){return 16;}//beginner & player1 vs player & first player1 & magenta1 vs magenta =16




else if(strcmp(x,"2")==0&&strcmp(y,"1")==0&&strcmp(z,"2")==0&&strcmp(w,"1")==0){return 17;}//beginner & player vs computer & second player1 red =17
else if(strcmp(x,"2")==0&&strcmp(y,"1")==0&&strcmp(z,"1")==0&&strcmp(w,"2")==0){return 18;}//beginner & player vs computer & first player1 blue =18

else if(strcmp(x,"1")==0&&strcmp(y,"1")==0&&strcmp(z,"2")==0&&strcmp(w,"3")==0){return 19;}//expert & player vs computer & second player2 green =19
else if(strcmp(x,"1")==0&&strcmp(y,"1")==0&&strcmp(z,"1")==0&&strcmp(w,"4")==0){return 20;}//expert & player vs computer & first player1 magenta =20


}
