int adminmenu()
{
printf("\n\t\t\t\t ***** Welcome to Admin MENU ***** \n");
printf("\n\t\t 1. Change Password\n");
printf("\t\t 2. Enter New Admission\n");
printf("\t\t 3. Enter New Teacher Details\n");
printf("\t\t 4. Print All Student Details\n");
printf("\t\t 5. Go to Main Menu\n");
printf("\t\t 6. Exit\n");
printf("\n\t\t Enter your Choice :-  ");
int am;
scanf("%d",&am);
switch(am)
{
case 1:
    {   system("cls");
        char prevpass[8];
        changepass(prevpass);
        break;
    }
case 2:
    {   system("cls");
        printf("\n\t\t Enter A New Student Entry \n");
        newstudent();
        break;
    }
case 3:
    {   system("cls");
        printf("\n\t\t Appointed a New Teacher !, Enter Details \n ");
        passmenu();
        break;
    }
case 4:
    {
        system("cls");
        preventry();
        break;
    }

case 5:
    {   system("cls");
        main();
        break;
    }
case 6:
    {
        system("cls");
        exit(0);
    }

default:
    {   system("cls");
        printf("\n\t\t Invalid Option .. Please Try again.\n\n");
        main();
        break;
    }

}
return 0;
