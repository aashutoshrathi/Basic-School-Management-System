void newstudent()
{
    FILE *ns;
    char name[50];
    int m;
    char addr[100];
    int srno;
    char father[100];
    char mother[100];
    char stupass[8];
    int clas;
    ns=fopen("newstu.txt","a");
    printf(YELLOW "\n\t\t\t ** New' Student Entry Menu ** \n" RESET);

    printf("\n\t\t Name : ");
    scanf("%s",name);
    fprintf(ns,"Name:%s\n",name);

    printf("\n\t\t Father's Name : ");
    scanf("%s",father);
    fprintf(ns,"Father's_Name:%s\n",father);

    printf("\n\t\t Qualification : ");
    scanf("%s",qual);
    fprintf(ns,"Qualification:%d\n",qual);

    char contactstu[20];
    printf("\n\t\t Contact : ");
    scanf("%s",contactstu);
    fprintf(ns,"Contact:%s\n",contactstu);

    printf("\n\t\t Address : ");
    scanf("%s",addr);
    fprintf(ns,"Address:%s\n",addr);

    int usrid = clas*100+srno;
    fprintf(ns,"ID:%d\n",usrid);


    printf(GREEN "\n\n\t\t New Teacher Recruited Successfully \n " RESET);
    printf("\n\t\t SR No.: %d \n\t\t Name : %s \n\t\t Father's Name : %s \n\t\t Qualification : %d \n\t\t Contact : %s \n\t\t Address : %s ",srno,name,father,mother,clas,contactstu,addr);


    printf(YELLOW "\n\n\t\t Generated User ID :  "RESET);
    printf("%d\n",usrid);

    printf("\n\t\t Set a Password : ");
    scanf("%s",stupass);
    fprintf(ns,"%s\n",stupass);
    fprintf(ns,"******************************************************************************* \n");
