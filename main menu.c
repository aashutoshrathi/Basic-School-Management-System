#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */


void changepass(char pass[])
{
    printf("\n\t\tEnter Your Previous Password :-");
    char ch;
    int i;
  for(i=0;i<8;i++)
 {
  ch = getch();
  pass[i] = ch;
  ch = '*';
  printf("%c",ch);
 }
  pass[i]= '\0';

    char password[8];
    FILE *fp;
    fp=fopen("adminpass.txt","r+");
    while(fscanf(fp,"%s",password)== 1)
    {
      int z=strcmp(password,pass);
    if (z!=0)
    {
        printf(RED "\n\n\t\t Wrong Password, Try Again !!\n" RESET);
        changepass(pass);
    }
    else
    {
        system("cls");
        printf(GREEN "\n\n\t\tCorrect Password ...\n" RESET);
        printf("\n\t\tEnter Your New Password :");
        scanf("%s",password);
        fprintf(fp,"%s",password);
        char rdef[8];
        printf("\n\t\tEnter Again :  ");
        scanf("%s",rdef);
        if(strcmp(password,rdef)==0)
        {
            printf("\n\t\tPassword Changed Successfully\n");
            printf("\n\t\tPress 1 To Go Back to Main Menu\n");
            int inp;
            printf("\n\t\t");
            scanf("%d",&inp);
            if(inp==1)
            {
                main();
            }
            else
            {
                printf("\n\t\tPasswords do not match\n");
                changepass(pass);
            }
        }
    }
    }
}

void passmenu()
{
  int p;
  printf("\n\t\t 1. Enter Password (8 Characters)\n");
  printf("\n\t\t 2. Go Back\n\t\t");
  printf("\n\n\t\t Your Choice : ");
  scanf("%d",&p);
  switch(p)
  {
  case 1:
  { char s[100];
    printf("\n\t\t Enter Password : ");
    passchecka(s);
    break;
  }
  case 2:
  {
    system("cls");
    main();
    break;

  }
  default:
  {
      printf("\n\t\t Invalid Option .. Please Try again.\n\n");
      passmenu();

  }
  }

}

void passchecka(char passa[])
{
    char ch;
    int i;
  for(i=0;i<8;i++)
 {
  ch = getch();
  passa[i] = ch;
  ch = '*';
  printf("%c",ch);
 }
  passa[i]= '\0';

    FILE *fp;
    char password[8];
    fp=fopen("adminpass.txt","r+");
    while(fscanf(fp,"%s",password)== 1)
    {
      int z=strcmp(password,passa);
    if (z!=0)
    {
        system("cls");
        printf(RED "\n\n\t\t Wrong Password, Try Again !!\n" RESET);
        passmenu();
    }
    else
    {
        system("cls");
        printf(GREEN "\n\n\t\tCorrect Password ...\n" RESET);
        adminmenu();

    }

}
}

void adminmenu()
{
printf("\n\t\t\t\t ***** Welcome to Admin MENU ***** \n");
printf("\n\t\t 1. Change Password\n");
printf("\t\t 2. Enter New Admission\n");
printf("\t\t 3. Enter New Teacher Details\n");
printf("\t\t 4. Go to Main Menu\n");
printf("\n\t\t Press Ctrl+C to Exit any time\n");
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
        passmenu();
        break;
    }
case 3:
    {   system("cls");
        printf("\n\t\t Appointed a New Teacher !, Enter Details \n ");
        passmenu();
        break;
    }

case 4:
    {   system("cls");
        main();
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

int main()
{
printf("\n\t\t\t\t ***** Welcome to School Management System ***** \n");
printf("\n\t\t 1. Admin Login\n");
printf("\t\t 2. Teacher Login\n");
printf("\t\t 3. Student Login\n");
printf("\n\t\t Press Ctrl+C to Exit any time\n");
printf("\n\t\t Enter your Choice :-  ");
int c;
scanf("%d",&c);
switch(c)
{
case 1:
    {   system("cls");
        printf("\n\t\t You selected Admin Login \n ");
        passmenu();
        break;
    }
case 2:
    {   system("cls");
        printf("\n\t\t You selected Teacher Login \n");
        passmenu();
        break;
    }
case 3:
    {   system("cls");
        printf("\n\t\t You selected Student Login \n ");
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
return 0;
}
