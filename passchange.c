
void passchange(char pass[])
{
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

    char def[8];
    strcpy(def,"adminpas");
    int z = strcmp(def,pass);
    if (z!=0)
    {
        printf(RED "\n\n\t\t Wrong Password, Try Again !!\n" RESET);
        passchange();
    }
    else
    {
        system("cls");
        printf(GREEN "\n\n\t\tCorrect Password ...\n" RESET);
        printf("Enter Your New Password\n :");
        scanf("%s",def);
        char rdef[8];
        scanf("%s",rdef);
        if(strcmp(def,rdef)==0)
        {
            printf("\n\t\tPassword Changed Successfully\n");
            printf("\n\t\tPress 1 To Go Back to Main Menu\n
            int inp;
            scnaf("%d",&inp);
            if(inp==1)
            {
                main();
            }
            else
            {
                printf("\n\t\tPasswords do not match\n");
                passchange();
            }
        }
    }

}
