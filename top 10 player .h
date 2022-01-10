






void top_player(){
    system("cls");
    FILE*top;

    int i=0,l,j,f;
    char s;
    struct p{
        char name[20];
        int score;
    }p[500],p2;
    top = fopen("top 10 player.text", "r");
    fseek(top,0,SEEK_SET);



    s = fgetc(top);
    while (s != EOF)
    {
        //Count number of lines
        if (s == '\n')
        {
            i = i + 1;
        }
        //take next character from file.
        s = getc(top);

    }

    fseek(top,0,SEEK_SET);
    for(j=0;j<i ;j++){
        fscanf_s(top,play_i,p[j].name,20,&p[j].score);

    }
    fclose(top);

    for (l = 0; l < i; l++) {
        for (j = l + 1; j < i; j++) {
            if (p[l].score < p[j].score) {
                p2 = p[l];
                p[l] = p[j];
                p[j] = p2;

            }
        }
    }


    for(f=0;f<i;f++){
        for(j=f+1;j<i;j++){
            if(strcmp(p[f].name,p[j].name)==0){
                if(p[f].score<p[j].score){
                    p[f] = p[j];
                }

                for(l=j;l<i;l++){            //delete the repetation elements in array1
                    strncpy(p[l+1].name,p[l].name,20);
                }
                i--;
                j--;
            }  }   }


    for (l = 0; l < i; l++) {
        for (j = l + 1; j < i; j++) {
            if (p[l].score < p[j].score) {
                p2 = p[l];
                p[l] = p[j];
                p[j] = p2;

            }
        }
    }
    if(i>10){
        i=10;
    }

/*
    top = fopen("top 10 player.text", "w");
    fseek(top,0,SEEK_SET);
    for(j=0;j<i ;j++){
        fprintf_s(top,play_o,p[j].name,p[j].score);

    }
    fclose(top);

*/






    printf(blue"\t\t\t\t\tthe top player is %c%c"reset cyan " %s with score:%d"reset red" %c%c\n"reset ,62,62,p[0].name,p[0].score,3,3);
    printf(magenta"\t\t\t\t\t============================================\n"reset);
    for(j=1;j<i;j++){
        printf(cyan"%d)%s"reset cyan" with score: "reset cyan"%d\n\n"reset,j+1,p[j].name,p[j].score);

    }
    fclose(top);








}
