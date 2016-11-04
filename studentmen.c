void loginmenustu()
{


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
       loginmenustu();
   }
  case 2:
    {
        main();
        break;
    }

  }
}
