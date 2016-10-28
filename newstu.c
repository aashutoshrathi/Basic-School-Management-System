void newstudent()
{
    FILE *ns;
    char name[50];
    int m;
    char addr[100];
    ns=fopen("newstu.txt","rw+");
    printf(YELLOW "\n\t\t\t New Student Entry Menu \n" RESET);
    printf("\n\t\t Name : ");
    scanf("%s",name);
    fprintf(ns,"%s",name);
    printf("\n\t\t Address : ");
    scanf("%s",addr);
    fprintf(ns,"%s",addr);
    printf(GREEN "\n\n\t\t New Student Entry Created Successfully : " RESET);
    printf("\n\t\t Name : %s \n\t\t Address : %s ",name,addr);

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
