#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */

void loginmenustu()
{
    FILE *stulog;
    char userstu[100];
    char passstu[100];
    char temp[100];
    printf("\n\t\t Enter Your User ID : ");
    scanf("%s",userstu);
    stulog=fopen("newstu","r+");

    while(fscanf(stulog, "%s", temp) != EOF)
    {
        if(strcmp(temp,userstu) == 0)
        {
            printf("\n\t\t User ID Found");
            printf("\n\t\t Enter Your Password : ");
            scanf("%s",passstu);
        }
        else
        {
            system("cls");
            printf("\n\t\t User ID Entered does not exist, Try again or contact Administrator");
            loginmenustu();
        }

    }



}


void studentpassmenu()
{
    int p;
  printf("\n\t\t 1. Login Menu\n");
  printf("\n\t\t 2. Go Back\n\t\t");
  printf("\n\n\t\t Your Choice : ");
  scanf("%d",&p);
  switch(p)
  {
  case 1:
   {
        system("cls");
       loginmenustu();
   }
  case 2:
    {
        main();
        break;
    }

  }
}


void newstudent()
{
    FILE *ns;
    char name[50];
    int m;
    char addr[100];
    int srno;
    char father[100];
    char mother[100];
    char stupass[8];
    int clas;
    ns=fopen("newstu.txt","a");
    printf(YELLOW "\n\t\t\t New Student Entry Menu \n" RESET);

    printf("\n\t\t SR No. : ");
    scanf("%d",&srno);
    fprintf(ns,"%d\n",srno);

    printf("\n\t\t Name : ");
    scanf("%s",name);
    fprintf(ns,"%s\n",name);

    printf("\n\t\t Father's Name : ");
    scanf("%s",father);
    fprintf(ns,"%s\n",father);

    printf("\n\t\t Mother's Name : ");
    scanf("%s",mother);
    fprintf(ns,"%s\n",mother);

    printf("\n\t\t Class : ");
    scanf("%d",&clas);
    fprintf(ns,"%d\n",clas);

    char contactstu[20];
    printf("\n\t\t Contact : ");
    scanf("%s",contactstu);
    fprintf(ns,"%s\n",contactstu);

    printf("\n\t\t Address : ");
    scanf("%s",addr);
    fprintf(ns,"%s\n",addr);
    int usrid = clas*100+srno;
    fprintf(ns,"%d\n",usrid);



    printf(GREEN "\n\n\t\t New Student Entry Created Successfully \n " RESET);
    printf("\n\t\t SR No.: %d \n\t\t Name : %s \n\t\t Father's Name : %s \n\t\t Mother's Name : %s  \n\t\t Class : %d \n\t\t Contact : %s \n\t\t Address : %s ",srno,name,father,mother,clas,contactstu,addr);
    printf(YELLOW "\n\n\t\t Generated User ID :  "RESET);
    printf("%d\n",usrid);

    printf("\n\t\t Set a Password : ");
    scanf("%s",stupass);
    fprintf(ns,"%s\n",stupass);

    printf("\n\n \t\t 1.Create Another Entry");
    printf("\n\t\t 2.Show Previous Entries");
    printf("\n\t\t 3.Go Back to Main Menu");
    printf("\n\n\t\t Your Choice :- ");
    scanf("%d",&m);
    switch(m)
    {
    case 1:
        {
            system("cls");
            newstudent();
            break;
        }
    case 2:
        {
            system("cls");
            printf(RED "\n\n\t\t Function Coming Soon ...." RESET);
            break;
        }
    case 3:
        {
            system("cls");
            main();
            break;
        }
    }

}

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
    fp=fopen("adminpass.txt","rw+");
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
        char rdef[9];
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
                system("cls");
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
    fclose(fp);
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
printf("\t\t 4. BETA Testing Feature\n");
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
    {
        system("cls");
        printf("\n\t\t You selected Student Login \n ");
        loginmenustu();
        break;
    }
case 4:
    {
        system("cls");
        newstudent();
    }
default:
    {
        system("cls");
        printf("\n\t\t Invalid Option .. Please Try again.\n\n");
        main();
        break;
    }

}
return 0;
}
