void preventry()
{
    FILE *fp;
    char ch;
    fp=fopen("newstu.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%c",&ch);
        printf("%c",ch);
    }
}
