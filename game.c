#include <stdio.h>
#include <stdlib.h>

int main (){

int  arr[5][5]  ;
    for(int i =0 ; i<5 ; i+=2)
    {
        for(int j=0 ; j<5 ; j+=2)
        {
            arr[i][j] = 254 ;
        }
    }

    for(int i =1 ; i<5 ; i+=2)
    {
        for(int j=0 ; j<5 ; j++)
        {
            arr[i][j] = 32 ;
        }
    }

    for(int i =0 ; i<5 ; i+=2)
    {
        for(int j=1 ; j<5 ; j+=2)
        {
            arr[i][j] = 32 ;
        }
    }

    

    for(int i =0 ; i<5 ; i++)
    {
        printf("%d " ,i+1) ;
        for(int j=0 ; j<5 ; j++)
        {
            printf("%c " , arr[i][j]) ;
        }
        printf("\n") ;
    }
return 0 ; 
}