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
