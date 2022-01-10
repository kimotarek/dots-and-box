#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#define red "\033[0;31m"
#define reset "\033[0;37m"
#define blue "\x1b[34m"
#define yellow "\x1b[33m"
#define green "\x1b[32m"
#define magenta "\x1b[35m"
#define cyan    "\x1b[36m"
#include "mainmenu.h"
#include "startmenu.h"
#include "strct.h"
#include "fungame r b.h"
#include "fungame g m.h"
#include "settings.h"
#include"top 10 player .h"
#include"end.h"
#include "About.h"
#include "about after settings.h"
#include "fun comp hard.h"
#include "fun comp easy.h"
#include "fun load 1.h"
#include "fun load 2.h"
#include "fun load 3.h"
#include "fun load 4.h"










int main() {
time_t t1=0, t2=0 ,t3=0,t4=0;
times t;
    FILE *f;
    system("");
    char to[20],ch1, ch2;
    FILE *top;
    int n1, m1,x2,z1,z2,x5,ab,td1=0,td2=0,x6,x3,x8,x11,x9,x10;
    player p1, p2;

    e:
    system("cls");
    x2 = mainmenu();
    if (x2 == 1) {
        z1 = startmenu();


        if (z1 == 0) { goto e; }
            //enter game
        else if (z1 == 1) {
            t1:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t1;  }
            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            p2 = read_info(2);

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=game1(n1, m1, p1, p2, "red", "red", ch1, ch2);
            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }
            //expert & player1 vs player & second play & red1 vs red = 1 5*5
        }


        else if (z1 == 2) {
            t2:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t2;  }
            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            p2 = read_info(2);

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=game1(n1, m1, p1, p2, "blue", "blue", ch1, ch2);
            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }
            //expert & player1 vs player & first play & red1 vs blue =2

        }
        else if (z1 == 3) {
            t3:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t3;  }
            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            p2 = read_info(2);

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=game1(n1, m1, p1, p2, "red", "green", ch1, ch2);
            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }
            //beginner & player1 vs player & second play & red1 vs green =3  2*2
        }
        else if (z1 == 4) {
            t4:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t4;  }
            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            p2 = read_info(2);

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=game1(n1, m1, p1, p2, "red", "magenta", ch1, ch2);
            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }
            //beginner & player1 vs player & first play & red1 vs magenta =4
        }
        else if (z1 == 5) {
            t5:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t5;  }
            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            p2 = read_info(2);

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=game1(n1, m1, p1, p2, "blue", "red", ch1, ch2);
            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }
            //expert & player1 vs player & second play & blue1 vs red =5
        }
        else if (z1 == 6) {
            t6:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t6 ;  }
            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            p2 = read_info(2);

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=game1(n1, m1, p1, p2, "blue", "blue", ch1, ch2);
            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }
            //expert & player1 vs player & first play & blue1 vs blue =6
        }
        else if (z1 == 7) {
            t7:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t7 ;  }
            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            p2 = read_info(2);

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=game1(n1, m1, p1, p2, "blue", "green", ch1, ch2);
            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }
            //beginner & player1 vs player & second play & blue1 vs green =7
        }
        else if (z1 == 8) {
            t8:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t8 ;  }
            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            p2 = read_info(2);

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=game1(n1, m1, p1, p2, "blue", "magenta", ch1, ch2);
            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }
            //beginner & player1 vs player & first play & blue1 vs magenta =8
        }
        else if (z1 == 9) {
            t9:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t9 ;  }
            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            p2 = read_info(2);

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=game2(n1, m1, p1, p2, "green", "red", ch1, ch2);
            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }
            //expert & player1 vs player & second play & green1 vs red =9

        }
        else if (z1 == 10) {
            t10:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t10 ;  }
            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            p2 = read_info(2);

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=game2(n1, m1, p1, p2, "green", "blue", ch1, ch2);
            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }
            //expert & player1 vs player & first play & green1 vs blue =10

        }
        else if (z1 == 11) {
            t11:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t11 ;  }
            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            p2 = read_info(2);

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=game2(n1, m1, p1, p2, "green", "green", ch1, ch2);
            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }
            //beginner & player1 vs player & second play & green1 vs green =11
        }
        else if (z1 == 12) {
            t12:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t12 ;  }
            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            p2 = read_info(2);

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=game2(n1, m1, p1, p2, "green", "magenta", ch1, ch2);
            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }
            //beginner & player1 vs player & first play & green1 vs magenta =12
        }
        else if (z1 == 13) {
            t13:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t13 ;  }
            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            p2 = read_info(2);

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=game2(n1, m1, p1, p2, "magenta", "red", ch1, ch2);
            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }
            //expert & player1 vs player & second play & magenta1 vs red =13
        }
        else if (z1 == 14) {
            t14:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t14 ;  }
            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            p2 = read_info(2);

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=game2(n1, m1, p1, p2, "magenta", "blue", ch1, ch2);
            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }
            //expert & player1 vs player & first play & magenta1 vs blue =14

        }
        else if (z1 == 15) {
            t15:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t15 ;  }
            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            p2 = read_info(2);

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=game2(n1, m1, p1, p2, "magenta", "green", ch1, ch2);
            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }
            //beginner & player1 vs player & second play & magenta1 vs green =15
        }
        else if (z1 == 16) {
            t16:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t16 ;  }
            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            p2 = read_info(2);

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=game2(n1, m1, p1, p2, "magenta", "magenta", ch1, ch2);
            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }
            //beginner & player1 vs player & first play & magenta1 vs magenta =16
        }




        else if (z1 == 17) {
            t17:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t17 ;  }

            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            player p2={"Computer",0,0};

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=gamecompeasy(n1, m1, p1, p2, "red", "yellow", ch1, ch2,1);

            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }


            //beginner & player vs computer & second play red =17




        }
        else if (z1 == 18) {
            //beginner & player vs computer & first play blue =18
            t18:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t18 ;  }

            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
          player p2={"Computer",0,0};

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=gamecompeasy(n1, m1, p1, p2, "blue", "yellow", ch1, ch2,2);

            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }


        }

        else if (z1 == 19) {
            t19:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t19 ;  }

            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            player p2={"Computer",0,0};

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=gamecomp(n1, m1, p1, p2, "green", "yellow", ch1, ch2,1);

            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }


            //expert & player vs computer & second play green =19

        }
        else if (z1 == 20) {
            t20:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t20 ;  }

            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            player p2={"Computer",0,0};

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=gamecomp(n1, m1, p1, p2, "magenta", "yellow", ch1, ch2,2);

            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }


            //expert & player vs computer & first play magenta =20
        }



        else if (z1 == 21){
            t21:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t21 ;  }

            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            player p2={"Computer",0,0};

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=gamecomp(n1, m1, p1, p2, "red", "yellow", ch1, ch2,2);

            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }


            //expert & player vs computer & first player red =21





        }

        else if (z1 == 22){
            t22:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t22 ;  }

            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            player p2={"Computer",0,0};

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=gamecomp(n1, m1,p1,p2, "blue", "yellow", ch1, ch2,2);

            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }


            //expert & player vs computer & first player blue =22

        }

        else if (z1 == 23){
            t23:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t23 ;  }

            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            player p2={"Computer",0,0};

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=gamecomp(n1, m1, p1, p2, "green", "yellow", ch1, ch2,2);

            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }


            //expert & player vs computer & first player green =23


        }

        else if (z1 == 24){
            t24:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t24 ;  }

            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            player p2={"Computer",0,0};

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=gamecomp(n1, m1, p1, p2, "red", "yellow", ch1, ch2,1);

            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }



            //expert & player vs computer & second player red =24


        }

        else if (z1 == 25){
            t25:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t25 ;  }

            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            player p2={"Computer",0,0};

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=gamecomp(n1, m1, p1, p2, "blue", "yellow", ch1, ch2,1);

            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }


            //expert & player vs computer & second player blue =25

        }

        else if (z1 == 26){
            t26:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t26 ;  }

            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            player p2={"Computer",0,0};

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=gamecomp(n1, m1, p1, p2, "magenta", "yellow", ch1, ch2,1);

            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }


            //expert & player vs computer & second player magenta =26

        }

        else if (z1 == 27){
            t27:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t27 ;  }

            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            player p2={"Computer",0,0};

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=gamecompeasy(n1, m1, p1, p2, "red", "yellow", ch1, ch2,2);

            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }



            //beginner & player vs computer & first player red =27



        }

        else if (z1 == 28){
            t28:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t28 ;  }

            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            player p2={"Computer",0,0};

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=gamecompeasy(n1, m1, p1, p2, "green", "yellow", ch1, ch2,2);

            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }


            //beginner & player vs computer & first player green =28


        }

        else if (z1 == 29){
            t29:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t29 ;  }

            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            player p2={"Computer",0,0};

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=gamecompeasy(n1, m1, p1, p2, "magenta", "yellow", ch1, ch2,2);

            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }


            //beginner & player vs computer & first player magenta =29

        }

        else if (z1 == 30){
            t30:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t30 ;  }

            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            player p2={"Computer",0,0};

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=gamecompeasy(n1, m1, p1, p2, "blue","yellow",ch1,ch2,1);

            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }



            //beginner & player vs computer & second player blue =30

        }

        else if (z1 == 31){
            t31:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t31 ;  }

            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            player p2={"Computer",0,0};

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=gamecompeasy(n1, m1, p1, p2, "green", "yellow", ch1, ch2,1);

            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }


            //beginner & player vs computer & second player2 green =31

        }

        else if (z1 == 32){
            t32:
            printf("\nplease choose size of your grid N X M \n");
            printf("1)" yellow "Enter N (rows):"reset);
            scanf("%d",&n1);
            printf("2)"yellow"Enter M (columns):"reset);
            scanf("%d", &m1);
            if(n1>5||m1>5){system("cls");printf(red"warning: "reset"exceeded the limits\n") ; goto t32 ;  }

            printf(cyan"==========================================\n"reset);
            p1 = read_info(1);
            player p2={"Computer",0,0};

            ch1 = p1.name[0];
            ch2 = p2.name[0];

            ch1 = convert(ch1);
            ch2 = convert(ch2);
            system("cls");
            z2=gamecompeasy(n1, m1, p1, p2, "magenta", "yellow", ch1, ch2,1);

            if(z2==5){  // go to loud
                x2=2;

            }else if(z2==7){ //for main menu

                goto e;
            }
            else if(z2==8){  //for exit
                return 0;
            }
            else if(z2==1){
                goto e;
            }
            else if(z2==2){
                return 0;
            }


            //beginner & player vs computer & second player1 magenta =32
        }
    }

    lx:
    if (x2 == 2) {    //  part of loud

        int turnco;
        int i0, u, rem, n, m, i, j, y1,mode;
        char colour1[20], colour2[20];

        char qq[30];


        system("cls");
        l1:
        printf("1)"yellow"to loud from file 1"reset"            2)"yellow"to loud from file 2\n"reset);
        printf("3)"yellow"to loud from file 3"reset"            4)"yellow"back\n"reset);

        printf("\nenter your choice(1,2,3,4):");
        scanf("%s", qq);

        if (strcmp(qq, "1") == 0) { y1 = 1; }
        else if (strcmp(qq, "2") == 0) { y1 = 2; }
        else if (strcmp(qq, "3") == 0) { y1 = 3; }
        else if (strcmp(qq, "4") == 0) { y1 = 0; }
        else {
            printf(red"WARNING:"reset"enter a valid choice");
            goto l1;
        }


        if (y1 == 0) { goto e;} //file loud
        else if (y1 == 1) {

            f = fopen("save1.text", "r");
            fseek(f, 0, SEEK_SET);
        } else if (y1 == 2) {

            f = fopen("save2.text", "r");
            fseek(f, 0, SEEK_SET);
        } else if (y1 == 3) {
            f = fopen("save3.text", "r");
            fseek(f, 0, SEEK_SET);
        }
        system("cls");
        fscanf_s(f, "mode=%d\n", &mode);
        fscanf_s(f,"turnco=%d\n",&turnco);
        fscanf_s(f, "player1score=%d,player2score=%d,player1moves=%d,player2moves=%d\n", &p1.score, &p2.score, &p1.move,
                 &p2.move);

        fscanf(f, "i0=%d,u=%d,rem=%d,N=%d,M=%d\n", &i0, &u, &rem, &n, &m);

        int arr[2 * n + 1][2 * m + 1], arr1[2 * n + 1][2 * m + 1], arr2[2 * n + 1][2 * m + 1];
        fscanf(f, "\narr:");
        for (int i = 0; i < 2 * n + 1; i++) {
            for (int j = 0; j < 2 * m + 1; j++) {

                fscanf(f, "%d,", &arr[i][j]);
            }
        }

        fscanf(f, "\narr1:");
        for (int i = 0; i < 2 * n + 1; i++) {
            for (int j = 0; j < 2 * m + 1; j++) {

                fscanf(f, "%d,", &arr1[i][j]);
            }
        }
        fscanf(f, "\narr2:");
        for (int i = 0; i < 2 * n + 1; i++) {
            for (int j = 0; j < 2 * m + 1; j++) {

                fscanf(f, "%d,", &arr2[i][j]);
            }
        }

        fscanf(f, "\nplayer1name=%[^,],player2name=%[^,],player1colour=%[^,],player2colour=%[^,],", p1.name, p2.name,
               colour1, colour2);


        fclose(f);

        fflush(stdin);




        {
        x8 = funload1(n,m,i0,rem,u,mode,turnco,p1,p2,colour1,colour2,arr,arr1,arr2);


        if (x8 == 5) {  // go to load
            x2 = 2;
            goto lx;

        } else if (x8 == 7) { //for main menu

            goto e;
        } else if (x8 == 8 || x8 == 0) {  //for exit
            return 0;
        }

        if (x8 == 1) {
            goto e;
        } else if (x8 == 2) {
            return 0;
        }
    } // first four blue colour

        {
            x11 = funload4(n,m,i0,rem,u,mode,turnco,p1,p2,colour1,colour2,arr,arr1,arr2);


            if (x11 == 5) {  // go to loud
                x2 = 2;
                goto lx;

            } else if (x11 == 7) { //for main menu

                goto e;
            } else if (x11 == 8 || x11 == 0) {  //for exit
                return 0;
            }

            if (x11 == 1) {
                goto e;
            } else if (x11 == 2) {
                return 0;
            }
        } // first four red colour

        {
            x9 = funload3(n,m,i0,rem,u,mode,turnco,p1,p2,colour1,colour2,arr,arr1,arr2);


            if (x9 == 5) {  // go to loud
                x2 = 2;
                goto lx;

            } else if (x9 == 7) { //for main menu

                goto e;
            } else if (x9 == 8 || x9 == 0) {  //for exit
                return 0;
            }

            if (x9 == 1) {
                goto e;
            } else if (x9 == 2) {
                return 0;
            }
        } // first four magenta colour

        {
            x10 = funload2(n,m,i0,rem,u,mode,turnco,p1,p2,colour1,colour2,arr,arr1,arr2);


            if (x10 == 5) {  // go to loud
                x2 = 2;
                goto lx;

            } else if (x10 == 7) { //for main menu

                goto e;
            } else if (x10 == 8 || x10 == 0) {  //for exit
                return 0;
            }

            if (x10 == 1) {
                goto e;
            } else if (x10 == 2) {
                return 0;
            }
        } // first four green colour
     }


     else if (x2 == 3) { //part of top player

        top_player();
        printf(green"\n===================================================================================================================== \n"reset);
        printf("\n1)"yellow"to go to main menu"reset);
        printf("\n2)"yellow"to exit"reset);
        printf("\nenter your choice:");

         l3:
        scanf("%s", to);
        if (strcmp(to, "1") == 0) {
            system("cls");
            goto e;
        }
       else if (strcmp(to, "2") == 0) {

            return 0;
        }
       else {printf(red"\nWARNING:"reset"enter a valid choice: "); goto l3;}
    }

 if (x2==4){  //patr of about
ab=about();
if(ab==1){goto e;}
if(ab==2){return 0;}

}


     if(x2==5){ // part of exit

        return 0;
    }



}

