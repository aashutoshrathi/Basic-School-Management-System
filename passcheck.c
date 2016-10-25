

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

    char def[8];
    strcpy(def,"adminpas");
    int z = strcmp(def,passa);
    if (z!=0)
    {
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
