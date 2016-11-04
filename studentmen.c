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
