#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define RESET   "\033[0m"
#define BLUE    "\033[34m"      /* Blue */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define gap printf("/n/t/t");

struct student
{
    char name[50];
    char addr[100];
    int srno;
    char gender[2];
    char dob[10];
    char father[100];
    char mother[100];
    char stupass[8];
    int clas;
    int usrid;
    char contactstu[20];

}s;


void profile(char id[])
{
    FILE *prf;

    while(fread(&s,sizeof(s),1,prf)==1)
    {
        if(id == s.usrid)
        {
            printf("%s\n",s.name);
            printf("%s\n",s.clas);
            break;
        }

    }

    fclose(prf);

}

int classwise()
{
   FILE *fp;
    fp=fopen("newstu.dat","r");
    int clas,count=1;
    printf("\n\tEnter Class : ");
    scanf("%d",&clas);
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        if(clas==s.clas)
        {
        printf("\t\t %d. %s\n",count,s.name);
        count++;
        }
    }
    fclose(fp);
    return 0;
}



void preventry()
{
    FILE *fp;
    fp=fopen("newstu.dat","r");
    int clas,count=1;
    scanf("%d",&clas);
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        if(clas==s.clas)
        {printf("%d. %s\n",count,s.name);
        count++;}
    }
    fclose(fp);
}

void stumenu(char id[])
{
    int m;
    printf("\n\t\t\t\t ***** Welcome to Student MENU ***** \n");
    printf("\n\n \t\t 1.Show Your Profile");
    printf("\n\t\t 2.Past Performance");
    printf("\n\t\t 3.Time Table");
    printf("\n\t\t 5.Go Back To Main Menu");
    printf("\n\t\t 7.Exit");

    printf("\n\n\t\t Your Choice :- ");
    scanf("%d",&m);
    switch(m)
    {
    case 1:
        {
            system("cls");
            profile(id);
            break;
        }

    case 5:
        {
            system("cls");
            main();
            break;
        }

    case 7:
        {
           exit(0);
        }

    }

}

void loginmenustu()
{
    loop:
    printf("");
    FILE *stulog;
    char free[100]="ID:";
    char userstu[100];
    char passstu[100];
    char temp[100];
    printf("\n\t\t Enter Your User ID : ");
    scanf("%s",userstu);
    char id[100];
    strcpy(id,userstu);
    strcat(free,userstu);
    stulog=fopen("newstu.dat","r");
    int skipper=0;
    while(fscanf(stulog,"%s",temp)==1)
    {
        if(strcmp(temp,free) == 0)
        {
            fscanf(stulog,"%s",temp);
            skipper=1;
            break;
        }

    }
            if(skipper==0)
            {
              system("cls");
              printf("\n\t\t User ID Entered does not exist, Try again or contact Administrator");
              goto loop;
            }
              printf(GREEN "\n\t\t User ID Found\n" RESET);
              printf("\n\t\t Enter Your Password : ");
              scanf("%s",passstu);
              if(strcmp(passstu,temp)==0)
            {
                system("cls");
                printf(GREEN "\n\t\t Correct Password !! \n" RESET);
                stumenu(id);
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
    int m;
    ns=fopen("newstu.dat","a");
    printf(YELLOW "\n\t\t\t **** New Student Entry Menu **** \n" RESET);

    printf("\n\t\t SR No.: ");
    scanf("%d",&s.srno);

    printf("\n\t\t Name : ");
    scanf(" %[^\n]s",s.name);

    printf("\n\t\t Gender : ");
    scanf("%s",s.gender);

    printf("\n\t\t Date Of Birth: ");
    scanf("%s",s.dob);

    printf("\n\t\t Father's Name : ");
    scanf(" %[^\n]s",s.father);

    printf("\n\t\t Mother's Name : ");
    scanf(" %[^\n]s",s.mother);

    printf("\n\t\t Class : ");
    scanf("%d",&s.clas);

    printf("\n\t\t Contact : ");
    scanf(" %[^\n]s",s.contactstu);


    printf("\n\t\t Address : ");
    scanf(" %[^\n]s",s.addr);

    s.usrid = s.clas*100+s.srno;


    printf(GREEN "\n\n\t\t New Student Entry Created Successfully \n " RESET);
    printf("\n\t\t SR No.: %d \n\t\t Name : %s \n\t\t Father's Name : %s \n\t\t Mother's Name : %s  \n\t\t Class : %d \n\t\t Contact : %s \n\t\t Address : %s ",s.srno,s.name,s.father,s.mother,s.clas,s.contactstu,s.addr);


    printf(YELLOW "\n\n\t\t Generated User ID :  "RESET);
    printf("%d\n",s.usrid);

    printf("\n\t\t Set a Password : ");
    scanf("%s",s.stupass);

    fseek(ns,0,SEEK_END);
    fwrite(&s,sizeof(s),1,ns);
    fclose(ns);

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
            preventry();
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
        int i=0,j;

   while (1)
    {
      if (i < 0) {
         i = 0;
      }

      ch = getch();

      if (ch == 13)
         break;

      if (ch == 8)
      {
         printf("\b\b");
         i--;
         system("cls");
         printf("\n\t\tEnter Your Previous Password :-");
         for(j=0;j<i;j++)
         printf("*");
         continue;
      }
      pass[i] = ch;
      i++;
      ch = '*';
      printf("%c",ch);
   }

   pass[i] = '\0';

    char password[100];
    FILE *fp;
    fp=fopen("adminpass.txt","w");
    while(fscanf(fp,"%s",password) == 1)
    {
    int z=strcmp(password,pass);
    if (z!=0)
    {
        printf(RED "\n\n\t\t Wrong Password\n" RESET);
        printf("\n\t\t1. Try Again");
        printf("\n\t\t2. Go Back to Main Menu");
        int sw;
        scanf("%d",&sw);
        switch(sw)
        {
        case 1:
           changepass(pass);
           break;
        case 2:
            main();
            break;
        }


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

int passchecka(char passa[])
{   printf("\n\t\t Enter Password : ");
      char ch;
        int i=0,j;

   while (1)
    {
      if (i < 0) {
         i = 0;
      }

      ch = getch();

      if (ch == 13)
         break;

      if (ch == 8)
      {
         printf("\b\b");
         i--;
         system("cls");
         printf("\n\t\t You selected Admin Login \n ");
         printf("\n\t\t 1. Enter Password (8 Characters)\n");
        printf("\n\t\t 2. Go Back\n\t\t");
        printf("\n\n\t\t Your Choice : 1 \n");
        printf("\n\t\t Enter Password : ");
         for(j=0;j<i;j++)
         printf("*");
         continue;
      }
      passa[i] = ch;
      i++;
      ch = '*';
      printf("%c",ch);
   }

   passa[i] = '\0';

    FILE *fp;
    char password[8];
    fp=fopen("adminpass.txt","r+");
    while(fscanf(fp,"%s",password)== 1)
    {
    if (strcmp(password,passa)!=0)
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
    return 0;
}

int adminmenu()
{
printf("\n\t\t\t\t ***** Welcome to Admin MENU ***** \n");
printf("\n\t\t 1. Change Password\n");
printf("\t\t 2. Enter New Admission\n");
printf("\t\t 3. Enter New Teacher Details\n");
printf("\t\t 4. Print All Student Details\n");
printf("\t\t 5. Class Wise Student Details\n");
printf("\t\t 6. Go to Main Menu\n");
printf("\t\t 7. Exit\n");
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
    {
        system("cls");
        classwise();
        break;
    }

case 6:
    {   system("cls");
        main();
        break;
    }
case 7:
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

}

void title()
{
   printf(" \t\t\t\t=====================================================\n");
   printf(" \t\t\t\t         Welcome to School Management System        \n ");
   printf(" \t\t\t\t=====================================================\n");
}

int main()
{
title();
printf("\n\t\t 1. Admin Login\n");
printf("\t\t 2. Teacher Login\n");
printf("\t\t 3. Student Login\n");
printf("\t\t 4. BETA Testing Feature\n");
printf("\t\t 5. Exit\n");
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
        preventry();
        break;
    }
case 5:
    {
        exit(0);
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
