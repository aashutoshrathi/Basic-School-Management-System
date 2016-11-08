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
