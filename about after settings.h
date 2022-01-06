



int about_after_settings(){
    char h2[20];
    system ("cls");

    printf("Help ? \n"
    cyan"======\n"reset
    "Dots and Boxes is a funny game that you can think before doing any movement .\n"
    "All rights are reserved for developers : \n"
    "Marwan Essam && Karim tarek \n"
    "Kindly if you find any crash or bug , contact us on the following E-mails with pleasure\n"
    "mailto:"blue"marwanesam243@gmail.com\n"reset
    "mailto:"blue"Karemtarek0222@gmail.com\n"reset
    cyan"=============================================================================================\n"reset
    "we start our Game by showing main menu and you need to choose \n"
    "Your choice well \n"
    "For go through game enter \"1\"\n"
    "For go through load enter \"2\"\n"
    "For go through leader board enter \"3\"\n"
    "For go through About enter \"4\"\n"
    "To exit enter \"5\"\n"
    "For first choice (GAME) >> \n"
    "You should choose 4 choices to start the actual GAME \n"
    "Difficulty , Mode , Turn , Colors\n"
    "In case of choosing Player VS player mode \n"
    "You should Enter:\n"
    "your name and your friend's name\n"
    "your color and your friend's color\n"
    "\n"
    "In case of choosing Player VS computer mode\n"
    "You will choose your turn and your color and enter your name only\n"
    "Computer will take \"computer\" as a name and yellow as a color\n"
    "\n"
    "Then you will be free to choose your size of GRID \n"
    "Be careful !! Not to exceed 5X5 as size to enjoy your game and handle it well\n"
    cyan"=============================================================================================\n"reset
    red"DURING THE GAME :\n"reset
    " \n"
    "To go setting at any time enter row1 : \"0\", column1 : \"0\", row2 : \"0\", column2 : \"0\"\n"
    "To go step back at any time during game Please enter \"undo\" \n"
    "And kindly check that you have already played any move to get it UNDO \n"
    "And check your spelling to write undo correctly to dodge any Error\n"
    cyan"=============================================================================================\n"reset
    red"AFTER THE GAME : \n"reset
    "You have 2 choices to go back to main menu Enter \"1\"  \n"
    "OR exit game Enter \"2\" \n"
    "\n"
    "For second choice (LOAD) >> you will choose file the you want to load \"1 OR 2 OR 3\"\n"
    "kindly Check that you have already saved a game before in one of the three files\n"
    "For third choice (TOP PLAYERS) >> you will check your name if the list \n"
    "Included it or not , if not try to get higher score :)\n"
    "Then you can choose to return main menu \"1\" OR exit \"2\"\n"
    "For fourth choice (ABOUT) >> you can choose to return main menu \"1\" OR exit \"2\"\n"
    "For fifth choice (EXIT) >> we will feel sad that you left our game :(\n"
    "\n"
    "\"we hope you enjoy our game and you're welcome to contact us with your feedback\"\n\n");



    printf("1)"yellow"return to game\n"reset);
    printf("2)"yellow"return to main menu\n"reset);
    printf("3)"yellow"exit\n"reset);
    printf("enter your choice (1,2,3): ");
    l:
    gets(h2);
    if(strcmp(h2,"1")==0){return 2;}
    else if(strcmp(h2,"2")==0){return 1;}
    else if(strcmp(h2,"3")==0){return 3;}
    else {printf(red"WARNING:"reset" enter a valid choice: ");  goto l ;}





}
