#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define RESET   "\033[0m"
#define BLUE    "\033[34m"      /* Blue */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */

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
    char cat[6];
    int clas;
    int usrid;
    char contactstu[20];

}s;

struct teacher
{
    char name[50];
    char addr[100];
    char gender[2];
    char dob[10];
    char father[100];
    char mother[100];
    char teapass[8];
    char cat[6];
    char qual[100];
    char sub[10];
    char sec[2];
    int teaid;
    char contacttea[20];
    char sp[40];

}t;

int tmenu(int id)
{
    printf("\n\t\t\t\t ***** Welcome to Teacher MENU ***** \n");
    FILE *fp;
    fp=fopen("teacher.dat","r");
    while(fread(&t,sizeof(t),1,fp)==1)
    {
        if(id == t.teaid)
        {
            printf(CYAN "\n\t\t Welcome " );
            printf("%s",t.name);
            printf(" !!"RESET);
            break;
        }
    }
    int m;
    printf("\n\n\t\t 1.Show Your Profile");
    printf("\n\t\t 2.Class Wise Students");
    printf("\n\t\t 3.Time Table");
    printf("\n\t\t 4.Change Password");
    printf("\n\t\t 5.Log Out");

    printf("\n\n\t\t Your Choice :- ");
    scanf("%d",&m);
    switch(m)
    {
    case 1:
        {
            system("cls");
            profilet(id);
            break;
        }
    case 3:
        {
            system("cls");
            tt(id);
            break;
        }
    case 2:
        {
            system("cls");
            classwise();
            break;
        }
    case 5:
        {
            system("cls");
            main();
            break;
        }
    case 4:
        {
            system("cls");
            stupassch(id);

        }
    default:
        {

            system("cls");
            printf(RED "\n\t\t Invalid Option selected , Enter Again \n" RESET);
            tmenu(id);
        }

    }
return 0;

}

int allt()
{
    printf("\n\t\t ===== Teacher Details ===== ");
    printf("\n\t\t Name                 ID          Password");
    FILE *fp;
    fp=fopen("teacher.dat","r");
    while(fread(&t,sizeof(t),1,fp)==1)
    {
        printf("\n");
        printf("\t\t %s               %d           %s",t.name,t.teaid,t.teapass);
    }
    printf("\n\t\t ===== End of List ======");
    int x;
    printf("\n\n\t\t Press   1. Log Out");
    printf("\n\t\t         2. Go Back");
    printf("\n\n\t\t Your Choice :");
    scanf("%d",&x);
    switch(x)
    {
    case 1:
        {
            system("cls");
            main();
            break;
        }
    case 2:
        {
            system("cls");
            adminmenu();
            break;
        }
    }
    fclose(fp);
    return 0;

}

int loginmenutea()
{
    printf(YELLOW "\n\t\t\t\t You selected Teacher Login \n "RESET);
    FILE *fp;
    int teaid,poi=0;
    char passstu[100];
    fp=fopen("teacher.dat","r");
    printf("\n\t\t Enter Your User ID : ");
    scanf("%d",&teaid);
    while(fread(&t,sizeof(t),1,fp)==1)
    {
        if(teaid==t.teaid)
        {
             poi=1;
             break;
        }
    }

    if(poi==1)
    {
            printf(GREEN "\n\t\t User ID Found\n" RESET);

              char ch;
   int i=0,j;


   printf("\n\t\t Enter password : ");

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
         printf(YELLOW "\n\t\t\t\t You selected Student Login \n "RESET);
         printf("\n\t\t Enter Your User ID : %d",teaid);
         printf(GREEN "\n\n\t\t User ID Found\n" RESET);
         printf("\n\t\t Enter password : ");
         for(j=0;j<i;j++)
         printf("*");
         continue;
      }
      passstu[i] = ch;
      i++;
      ch = '*';
      printf("%c",ch);
   }

   passstu[i] = '\0';

              if(strcmp(passstu,t.teapass)==0)
              {
                printf(GREEN "\n\t\t Correct Password !! \n" RESET);
                system("cls");
                tmenu(teaid);
            }
            else
            {
                printf(RED "\n\t\t Wrong Password !!! \n " RESET);
                printf("\n\t\t 1. Enter Again");
                printf("\n\t\t 2. Go Back");
                printf("\n\n\t\t Your Choice : ");
                int m;
        scanf("%d",&m);
        switch(m)
        {
        case 1:
            {
                system("cls");
                loginmenutea();
                break;
            }
        case 2:
            {
                system("cls");
                main();
                break;
            }
        }
            }
    }
    else
    {
        puts(RED "\n\t\t User ID not found, Contact Admin or Try again\n" RESET);
        printf("\t\t 1. Try Again");
        printf("\n\t\t 2. Go Back");
        printf("\n\n\t\t Your Choice : ");
        int n;
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            {
                system("cls");
                loginmenutea();
                break;
            }
        case 2:
            {
                system("cls");
                main();
                break;
            }
        }
    }
return 0;
}

int credits()
{
    system("cls");
    system("COLOR 0A");
    printf("\n\n\t\t ============== Project Prepared By ================");
    printf("\n\n\t\t == Raja Bhargava ");
    printf("\n\n\t\t == Aashutosh Rathi ");
    printf("\n\n\t\t == Daksh Gandoliya ");
    printf("\n\n\t\t == Mayank Waiker ");
    printf("\n\n\t\t == Natharam Jaipal \n\n");
    exit(0);
}

int addtea()
{
    FILE *fp;
    fp=fopen("teacher.dat","a");
    printf(YELLOW "\n\t\t\t **** New Teacher Entry Menu **** \n" RESET);

    printf("\n\t\t Name : ");
    scanf(" %[^\n]s",t.name);

    printf("\n\t\t Gender : ");
    scanf(" %[^\n]s",t.gender);

    printf("\n\t\t Date Of Birth: ");
    scanf(" %[^\n]s",t.dob);

    printf("\n\t\t Father's Name : ");
    scanf(" %[^\n]s",t.father);

    printf("\n\t\t Mother's Name : ");
    scanf(" %[^\n]s",t.mother);

    printf("\n\t\t Qualification : ");
    scanf(" %[^\n]s",t.qual);

    printf("\n\t\t Specialization Subject :");
    scanf(" %s[^\n]s",t.sp);

    printf("\n\t\t Contact : ");
    scanf(" %[^\n]s",t.contacttea);

    printf("\n\t\t Category (GEN / ST / SC / OBC): ");
    scanf(" %[^\n]s",t.cat);

    printf("\n\t\t Address : ");
    scanf(" %[^\n]s",t.addr);

    srand(time(NULL));
    t.teaid = rand()%9023;


    printf(GREEN "\n\n\t\t New Teacher Entry Successfully \n " RESET);
    printf("\n\t\t Name : %s \n\t\t Father's Name : %s \n\t\t Mother's Name : %s  \n\t\t Qualification : %s \n\t\t  Specialization : %s \n\t\t Contact : %s \n\t\t Address : %s ",t.name,t.father,t.mother,t.qual,t.sp,t.contacttea,t.addr);


    printf(YELLOW "\n\n\t\t Generated User ID :  "RESET);
    printf("%d\n",t.teaid);

    printf("\n\t\t Set a Password : ");
    scanf("%s",t.teapass);

    fseek(fp,0,SEEK_END);
    fwrite(&t,sizeof(t),1,fp);
    fclose(fp);

    printf("\n\n \t\t 1.Create Another Entry");
    printf("\n\t\t 2.Log Out");
    printf("\n\t\t 3.Go Back");
    printf("\n\n\t\t Your Choice :- ");
    int m;
    scanf("%d",&m);
    switch(m)
    {
    case 1:
        {
            system("cls");
            addtea();
            break;
        }
    case 2:
        {
            system("cls");
            main();
            break;
        }
    case 3:
        {
            system("cls");
            adminmenu();
            break;
        }
    }

return 0;
}

int removestu(int id)
{

}

int tt(int id)
{
    FILE *fp;
    char ch;
    fp=fopen("timetable.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%c",&ch);
        printf("%c",ch);
    }
    printf("\n\n\t Press 1 to Go Back");
    int n;
    printf("\n\t\tEnter Your Choice :");
    scanf("%d",&n);
    if(n==1)
    {
        system("cls");
        stumenu(id);
    }

return 0;
}

int stupassch(int id)
{
    FILE *fp;
    printf("\n\t\t\t\t Password Change Menu");
    fp=fopen("newstu.txt","r+");
    printf("\n\t\t Enter Previous Password :");
    char pass[10];
    scanf("%s",pass);
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        if(strcmp(pass,s.stupass)==0)
        {
            printf("\n\t\tEnter New Password : ");
            scanf("%s",s.stupass);
            fwrite(&s.stupass,sizeof(s.stupass),1,fp);
            printf(GREEN "\n\t\t Password Changed Successfully\n" RESET);

        }
        else
        {
            printf("\n\t\t Incorrect Password !!");
            printf("\n\t\t 1. Try Again");
            printf("\n\t\t 2. Go Back");
            printf("\n\n\t\t Your Choice : ");
            int x;
            scanf("%d",&x);
            switch(x)
            {
            case 1:
                {
                    studentpassmenu(id);
                    break;
                }
            case 2:
                {
                    system("cls");
                    stumenu(id);
                    break;
                }
            }

        }

    fclose(fp);
    }
return 0;
}

void profile(int id)
{
    FILE *prf;
    prf=fopen("newstu.dat","r");
    while(fread(&s,sizeof(s),1,prf)==1)
    {
        if(id == s.usrid)
        {
            printf(" \t\t\t\t=====================================================\n");
            printf(YELLOW " \t\t\t\t                    %s's Profile                   \n" ,s.name);
            printf(""RESET);
            printf(" \t\t\t\t=====================================================\n");
            printf("\n\t\t Name : %s\n",s.name);
            printf("\n\t\t User ID : %d\n",s.usrid);
            printf("\n\t\t Father's Name : %s\n",s.father);
            printf("\n\t\t Mother's Name : %s\n",s.mother);
            printf("\n\t\t Category : %s\n",s.cat);
            printf("\n\t\t Class : %d\n",s.clas);
            printf("\n\t\t Contact : %s\n",s.contactstu);
            printf("\n\t\t Address : %s\n",s.addr);
            puts(YELLOW "\n\t\t For Any Changes in Profile Contact Administrator" RESET);
            break;
        }

    }
        printf("\n\n\t\t Press 1. Logout");
        printf("\n\t\t       2. Go Back\n\t\t");
        int y;
        scanf("%d",&y);
        switch(y)
        {
        case 1:
            {
                system("cls");
                main();
            }
        case 2:
            {
                system("cls");
                stumenu(id);
            }
        }
    fclose(prf);

}


int profilet(int id)
{
    FILE *prf;
    prf=fopen("teacher.dat","r");
    while(fread(&t,sizeof(t),1,prf)==1)
    {
        if(id == t.teaid)
        {
            printf(" \t\t\t\t=====================================================\n");
            printf(YELLOW " \t\t\t\t                    %s's Profile                   \n" ,t.name);
            printf(""RESET);
            printf(" \t\t\t\t=====================================================\n");
            printf("\n\t\t Name : %s\n",t.name);
            printf("\n\t\t User ID : %d\n",t.teaid);
            printf("\n\t\t Father's Name : %s\n",t.father);
            printf("\n\t\t Mother's Name : %s\n",t.mother);
            printf("\n\t\t Category : %s\n",t.cat);
            printf("\n\t\t Qualification : %s\n",t.qual);
            printf("\n\t\t Area Of Interest : %s\n",t.sp);
            printf("\n\t\t Contact : %s\n",t.contacttea);
            printf("\n\t\t Address : %s\n",t.addr);
            puts(YELLOW "\n\t\t For Any Changes in Profile Contact Administrator" RESET);
            break;
        }

    }
        printf("\n\n\t\t Press 1. Logout");
        printf("\n\t\t       2. Go Back\n\t\t");
        int y;
        scanf("%d",&y);
        switch(y)
        {
        case 1:
            {
                system("cls");
                main();
            }
        case 2:
            {
                system("cls");
                tmenu(id);
            }
        }
    fclose(prf);
    return 0;

}



int classwise()
{
   FILE *fp;
    fp=fopen("newstu.dat","r");
    int clas,count=1;
    printf("\n\t\tEnter Class : ");
    scanf("%d",&clas);
    printf("\n\t\t    ======= Class %dth =======\n",clas);
    printf("\n\t\t     Name          ID       Gender\n ");
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        if(clas==s.clas)
        {
        printf("\t\t %d. %s          %d         %s",count,s.name,s.usrid,s.gender);
        count++;
        }
    }
    printf("\n\t\t   ====== End of List =========== \n");
    printf("\n\t\tPress  1.Log Out");
    printf("\n\t\t       2.Go Back\n\t\t   ");

    int y;
        scanf("%d",&y);
        switch(y)
        {
        case 1:
            {
                system("cls");
                main();
            }
        case 2:
            {
                system("cls");
                adminmenu();
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

int stumenu(int id)
{
    printf("\n\t\t\t\t ***** Welcome to Student MENU ***** \n");
    FILE *fp;
    fp=fopen("newstu.dat","r");
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        if(id == s.usrid)
        {
            printf(CYAN "\n\t\t Welcome " );
            printf("%s",s.name);
            printf(" !!"RESET);
            break;
        }
    }
    int m;
    printf("\n\n\t\t 1.Show Your Profile");
    printf("\n\t\t 2.Past Performance");
    printf("\n\t\t 3.Time Table");
    printf("\n\t\t 4.Change Password");
    printf("\n\t\t 5.Log Out");
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
    case 3:
        {
            system("cls");
            tt(id);
            break;
        }


    case 5:
        {
            system("cls");
            main();
            break;
        }
    case 4:
        {
            system("cls");
            stupassch(id);

        }

    case 7:
        {
           credits();
        }
    default:
        {

            system("cls");
            printf(RED "\n\t\t Invalid Option selected , Enter Again \n" RESET);
            stumenu(id);
        }

    }
return 0;
}

int loginmenustu()
{
    printf(YELLOW "\n\t\t\t\t You selected Student Login \n "RESET);
    FILE *stulog;
    int userstu,poi=0;
    char passstu[100];
    stulog=fopen("newstu.dat","r");
    printf("\n\t\t Enter Your User ID : ");
    scanf("%d",&userstu);
    while(fread(&s,sizeof(s),1,stulog)==1)
    {
        if(userstu==s.usrid)
        {
             poi=1;
             break;
        }
    }

    if(poi==1)
    {
            printf(GREEN "\n\t\t User ID Found\n" RESET);

              char ch;
   int i=0,j;


   printf("\n\t\t Enter password : ");

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
         printf(YELLOW "\n\t\t\t\t You selected Student Login \n "RESET);
         printf("\n\t\t Enter Your User ID : %d",userstu);
         printf(GREEN "\n\n\t\t User ID Found\n" RESET);
         printf("\n\t\t Enter password : ");
         for(j=0;j<i;j++)
         printf("*");
         continue;
      }
      passstu[i] = ch;
      i++;
      ch = '*';
      printf("%c",ch);
   }

   passstu[i] = '\0';

              if(strcmp(passstu,s.stupass)==0)
              {
                printf(GREEN "\n\t\t Correct Password !! \n" RESET);
                system("cls");
                stumenu(userstu);
            }
            else
            {
                printf(RED "\n\t\t Wrong Password !!! \n " RESET);
                printf("\n\t\t 1. Enter Again");
                printf("\n\t\t 2. Go Back");
                printf("\n\n\t\t Your Choice : ");
                int m;
        scanf("%d",&m);
        switch(m)
        {
        case 1:
            {
                system("cls");
                loginmenustu();
                break;
            }
        case 2:
            {
                system("cls");
                main();
                break;
            }
        }
            }
    }
    else
    {
        puts(RED "\n\t\t User ID not found, Contact Admin or Try again\n" RESET);
        printf("\t\t 1. Try Again");
        printf("\n\t\t 2. Go Back");
        printf("\n\n\t\t Your Choice : ");
        int n;
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            {
                system("cls");
                loginmenustu();
                break;
            }
        case 2:
            {
                system("cls");
                main();
                break;
            }
        }
    }
return 0;
}

int studentpassmenu()
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
return 0;
}

void newstudent()
{
    FILE *ns;
    int m;
    ns=fopen("newstu.dat","a");
    printf(YELLOW "\n\t\t\t **** New Student Entry Menu **** \n" RESET);

    printf("\n\t\t SR No. :");
    scanf("%d",&s.srno);

    printf("\n\t\t Name : ");
    scanf(" %[^\n]s",s.name);

    printf("\n\t\t Gender : ");
    scanf(" %[^\n]s",s.gender);

    printf("\n\t\t Date Of Birth: ");
    scanf(" %[^\n]s",s.dob);

    printf("\n\t\t Father's Name : ");
    scanf(" %[^\n]s",s.father);

    printf("\n\t\t Mother's Name : ");
    scanf(" %[^\n]s",s.mother);

    printf("\n\t\t Class : ");
    scanf("%d",&s.clas);

    printf("\n\t\t Contact : ");
    scanf(" %[^\n]s",s.contactstu);

    printf("\n\t\t Category (GEN / ST / SC / OBC): ");
    scanf(" %[^\n]s",s.cat);

    printf("\n\t\t Address : ");
    scanf(" %[^\n]s",s.addr);

    s.usrid = 100*s.clas +s.srno;


    printf(GREEN "\n\n\t\t New Student Entry Created Successfully \n " RESET);
    printf("\n\t\t SR No.: : %d \n\t\t Name : %s \n\t\t Father's Name : %s \n\t\t Mother's Name : %s  \n\t\t Class : %d \n\t\t Contact : %s \n\t\t Address : %s ",s.srno,s.name,s.father,s.mother,s.clas,s.contactstu,s.addr);


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
    FILE *fp,*fp1;
    fp=fopen("adminpass.txt","r+");
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
        char rdef[9];
        printf("\n\t\tEnter Again :  ");
        scanf("%s",rdef);
        if(strcmp(password,rdef)==0)
        {
            fprintf(fp,"%s",password);
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
        printf(GREEN "\n\n\t\tCorrect Password ;) \n" RESET);
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
printf("\t\t 6. Delete Student Entry\n");
printf("\t\t 7. Print All Teacher Details\n");
printf("\t\t 8. Log Out\n");
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
        printf("\n\t\t Appointed a New Teacher \n ");
        addtea();
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
    {

    }
case 7:
    {
        system("cls");
        allt();
        break;
    }

case 8:
    {   system("cls");
        main();
        break;
    }


default:
    {   system("cls");
        printf("\n\t\t Invalid Option .. Please Try again.\n\n");
        adminmenu();
        break;
    }

}
return 0;

}

int title()
{
    system("COLOR 0A");
   printf(" \t\t\t\t=====================================================\n");
   printf(" \t\t\t\t         Welcome to School Management System        \n");
   printf(" \t\t\t\t=====================================================\n");
   return 0;
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
        loginmenutea();
        break;
    }
case 3:

    {
        system("cls");
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
        credits();
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
