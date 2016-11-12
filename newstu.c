struct student
{
	 char name[50];
    char addr[100];
    int srno;
    char father[100];
    char mother[100];
    char stupass[8];
    int clas;
    int usrid;
    char contactstu[20];

}s;

void newstudent()
{
    FILE *ns;
    int m;
    ns=fopen("newstu.txt","a");
    printf(YELLOW "\n\t\t\t **** New Student Entry Menu **** \n" RESET);

    printf("\n\t\t SR No. : ");
    scanf("%d",&s.srno);
    fprintf(ns,"SR.:%d\n",s.srno);

    printf("\n\t\t Name : ");
    scanf(" %[^\n]s",s.name);
    fprintf(ns,"Name:%s\n",s.name);

    printf("\n\t\t Father's Name : ");
    scanf(" %[^\n]s",s.father);
    fprintf(ns,"Father's_Name:%s\n",s.father);

    printf("\n\t\t Mother's Name : ");
    scanf(" %[^\n]s",s.mother);
    fprintf(ns,"Mother's_Name:%s\n",s.mother);

    printf("\n\t\t Class : ");
    scanf("%d",&s.clas);
    fprintf(ns,"Class:%d\n",s.clas);


    printf("\n\t\t Contact : ");
    scanf(" %[^\n]s",s.contactstu);
    fprintf(ns,"Contact:%s\n",s.contactstu);


    printf("\n\t\t Address : ");
    scanf(" %[^\n]s",s.addr);
    fprintf(ns,"Address:%s\n",s.addr);

    s.usrid = s.clas*100+s.srno;
    fprintf(ns,"ID:%d\n",s.usrid);


    printf(GREEN "\n\n\t\t New Student Entry Created Successfully \n " RESET);
    printf("\n\t\t SR No.: %d \n\t\t Name : %s \n\t\t Father's Name : %s \n\t\t Mother's Name : %s  \n\t\t Class : %d \n\t\t Contact : %s \n\t\t Address : %s ",s.srno,s.name,s.father,s.mother,s.clas,s.contactstu,s.addr);


    printf(YELLOW "\n\n\t\t Generated User ID :  "RESET);
    printf("%d\n",s.usrid);

    printf("\n\t\t Set a Password : ");
    scanf("%s",s.stupass);
    fprintf(ns,"%s\n",s.stupass);
    fprintf(ns,"*******************************************************************************************\n");

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
