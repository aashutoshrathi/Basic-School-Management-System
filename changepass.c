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
