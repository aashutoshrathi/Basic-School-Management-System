#include <stdio.h>
void adminmenu()
{
printf("\n\t\t\t\t ***** Welcome to Admin MENU ***** \n");
printf("\n\t\t 1. Change Password\n");
printf("\t\t 2. Enter New Admission\n");
printf("\t\t 3. Enter New Teacher Details\n");
printf("\n\t\t Press Ctrl+C to Exit any time\n");
printf("\n\t\t Enter your Choice :-  ");
int am;
scanf("%d",&am);
switch(am)
{
case 1:
    {   system("cls");
        printf("Enter Your Previous Password :- ");
        passchecka();

        break;
    }
case 2:
    {   system("cls");
        printf("\n\t\t Enter A New Student Entry \n");
        passmenu();
        break;
    }
case 3:
    {   system("cls");
        printf("\n\t\t Appointed a New Teacher !, Enter Details \n ");
        passmenu();
        break;
    }
default:
    {   system("cls");
        printf("\n\t\t Invalid Option .. Please Try again.\n\n");
        main();
        break;
    }

}

}
