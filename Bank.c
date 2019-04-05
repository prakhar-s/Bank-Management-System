#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int pos;
FILE *pa; char d[12];//d stands for date of withdrawl or deposit.
char date1[10];char date2[10];
int max[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
     int max1[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
     int max2[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

void create()
{
    fflush(stdin);
    char name[50];char str[50];char age[3];char ac[10];float ammount;
    char add[200];
    char phone[10];
    char email[500];
    char dob[10];
    FILE *fp;
    printf("enter name :");
    fflush(stdin);
    gets(name);
    fflush(stdin);
    strcpy(str,name);
    fp=fopen(name,"w");
    printf("enter some initial ammount to deposit:");
    scanf("%f",&ammount);
    fprintf(fp,"%0.2f\n",ammount);
    fprintf(fp,"%s\n",str);
    fflush(stdin);
    printf("enter account number\n");
    scanf("%s",ac);
    fflush(stdin);
    fprintf(fp,"%s\n",ac);
    printf("enter age :");
    scanf("%s",age);
    fprintf(fp,"%s\n",age);

    printf("enter phone :");
    scanf("%s",phone);
    fprintf(fp,"%s\n",phone);

    fflush(stdin);

    printf("enter address :");
    //scanf("%s[^]",add);
    gets(add);
    fflush(stdin);
    fprintf(fp,"%s\n",add);


    printf("enter D.O.B :");
    scanf("%s",dob);
    fprintf(fp,"%s\n",dob);

    printf("enter e mail :");
    scanf("%s",email);
    fprintf(fp,"%s\n",email);
    fclose(fp);

}

void edit()
{
   fflush(stdin);
   char name[50];char str[50];char age[3];char ac[10];char a[1000];
    char add[200];
    char phone[10];
    char email[500];
    char dob[10];
    FILE *pf1;

    printf("enter the name :");
    fflush(stdin);
    //scanf("%s",name);
    gets(name);
    pf1=fopen(name,"r");char c;
    int i=0;
    while((c=getc(pf1))!=EOF)
          {
              a[i]=c;
              i++;
          }
    fclose(pf1);
    for(i=0;i<strlen(a);i++)
        {
            if(a[i]=='\n')
            {
              pos=i;
              break;
            }
        }
    char x[10];
    for(i=0;i<=pos;i++)
    {
        x[i]=a[i];
    }


    fflush(stdin);
    strcpy(str,name);
    pf1=fopen(name,"w");
    fprintf(pf1,"%s",x);
    fprintf(pf1,"%s\n",str);
    fflush(stdin);
    printf("enter account number\n");
    scanf("%s",ac);
    fflush(stdin);
    fprintf(pf1,"%s\n",ac);
    printf("enter age :");
    scanf("%s",age);
    fprintf(pf1,"%s\n",age);

    printf("enter updated(if any updation required) phone number :");
    scanf("%s",phone);
    fprintf(pf1,"%s\n",phone);

    fflush(stdin);

    printf("enter updated(if any updation required)address :");
    //scanf("%s[^]",add);
    gets(add);
    fflush(stdin);
    fprintf(pf1,"%s\n",add);


    printf("enter D.O.B :");
    scanf("%s",dob);
    fprintf(pf1,"%s\n",dob);

    printf("enter updated(if any updation required)e mail address :");
    scanf("%s",email);
    fprintf(pf1,"%s\n",email);
    fclose(pf1);
}
void deposit()
{
    fflush(stdin);
    FILE *pf;char name[50];
    printf("enter your name:");
    fflush(stdin);
    gets(name);
    fflush(stdin);
    printf("enter date:");

    fflush(stdin);
    gets(d);
    fflush(stdin);

    pf=fopen(name,"r");
    char c;
    char ammount[10];int i=0;char a[1000];
    while((c=getc(pf))!=EOF)
    {
        a[i]=c;
        i++;
    }
    fclose(pf);
    i=0;int m;
   for(i=0;i<strlen(a);i++)
   {
      if(a[i]=='\n')
      {
          m=i;
          break;
      }
   }
   char temp[m];
  for(i=0;i<=m;i++)
  {
     temp[i]=a[i];
  }
  int r;float num=0;;
 /*for(i=0;i<m;i++)
 {
     r=temp[i]-'0';
     num=(num*10)+r;

 }*/
  num=atof(temp);
 //printf("%d",num);
  printf("enter the ammount to be deposited:");
  float x;
  scanf("%f",&x);
  num=num+x;
  pf=fopen(name,"w");
  fprintf(pf,"%0.2f\n",num);

   int y;
   for(i=0;i<strlen(a);i++)
   {
       if(a[i]=='\n')
       {
         y=i;
       }
   }
  for(i=m+1;i<=y;i++)
  {
      fflush(stdin);
      fprintf(pf,"%c",a[i]);
      fflush(stdin);
  }
  strcat(name,"_passbook");
  pa=fopen(name,"a");
  fprintf(pa,"%s: deposited Rs %0.2f\n",d,x);
  fclose(pa);



 }

 void withdraw()
{
    fflush(stdin);
    FILE *pf2;char name[50];
    printf("enter your name:");
    fflush(stdin);
    gets(name);
    fflush(stdin);

    printf("enter date:");
    fflush(stdin);
    gets(d);
    fflush(stdin);

    pf2=fopen(name,"r");
    char c;
    char ammount[10];int i=0;char a[1000];
    while((c=getc(pf2))!=EOF)
    {
        a[i]=c;
        i++;
    }
    fclose(pf2);
    i=0;int m;
   for(i=0;i<strlen(a);i++)
   {
      if(a[i]=='\n')
      {
          m=i;
          break;
      }
   }
   char temp[m];
  for(i=0;i<=m;i++)
  {
     temp[i]=a[i];
  }
  int r;float num=0;;
 /*for(i=0;i<m;i++)
 {
     r=temp[i]-'0';
     num=(num*10)+r;

 }*/
 num=atof(temp);
  float x;
  int j;
  for(j=0;j<1;j++)
  {
      printf("enter the ammount to be withdrwan:");
      scanf("%f",&x);
      if(x>num)
      {
          printf("insufficient balance in your account. An ammount less than %d can only be withdrawn\n",num);
          j--;
      }
  }
  num=num-x;
  pf2=fopen(name,"w");
  fprintf(pf2,"%0.2f\n",num);

   int y;
   for(i=0;i<strlen(a);i++)
   {
       if(a[i]=='\n')
       {
         y=i;
       }
   }
  for(i=m+1;i<=y;i++)
  {
      fflush(stdin);
      fprintf(pf2,"%c",a[i]);
      fflush(stdin);
  }

  strcat(name,"_passbook");
  pa=fopen(name,"a");
  fprintf(pa,"%s: withdrawl of Rs %0.2f\n",d,x);
  fclose(pa);


 }

 void passbook()
 {
      fflush(stdin);

     printf("\n");
    // char name[50];
      printf("enter your name:");

     char name[50];
     fflush(stdin);
     gets(name);
     fflush(stdin);
     printf("\n\n");
     FILE *x;
     x=fopen(name,"r");
     char c;char a[1000];int i=0;
     while((c=getc(x))!=EOF)
           {
              a[i]=c;
              i++;
           }
    fclose(x);int k=0;
        printf("\n\n");
        printf("Current available balance:");
     for(i=0;a[i]!='\n';i++)
        {
            printf("%c",a[i]);
        }

      k=i+1;
      printf("\n");
      printf("Name:");
      for(i=k;a[i]!='\n';i++)
      {
          printf("%c",a[i]);
      }

      k=i+1;
      printf("\n");
      printf("Account number:");
       for(i=k;a[i]!='\n';i++)
      {
          printf("%c",a[i]);
      }

       k=i+1;
      printf("\n");
      printf("Age:");
       for(i=k;a[i]!='\n';i++)
      {
          printf("%c",a[i]);
      }

       k=i+1;
      printf("\n");
      printf("Phone number:");
       for(i=k;a[i]!='\n';i++)
      {
          printf("%c",a[i]);
      }

       k=i+1;
      printf("\n");
      printf("Permannt Residential Address:");
       for(i=k;a[i]!='\n';i++)
      {
          printf("%c",a[i]);
      }

       k=i+1;
      printf("\n");
      printf("Date of Birth:");
       for(i=k;a[i]!='\n';i++)
      {
          printf("%c",a[i]);
      }

       k=i+1;
      printf("\n");
      printf("E-Mail Address:");
       for(i=k;a[i]!='\n';i++)
      {
          printf("%c",a[i]);
      }
      printf("\n");


     strcat(name,"_passbook");
     pa=fopen(name,"r");

     while((c=getc(pa))!=EOF)
     {
         printf("%c",c);
     }
     fclose(pa);
 }

  void transfer()
  {
       fflush(stdin);
      char name1[50];char name2[50];char da[12];char str[50];
      printf("enter your name:");
      fflush(stdin);
      gets(name1);
      fflush(stdin);
      strcpy(str,name1);

      printf("enter the name of the person into whose account the money has to be transferred:");
      fflush(stdin);
      gets(name2);
      fflush(stdin);

      printf("enter date:");
      fflush(stdin);
      gets(da);
      fflush(stdin);

      FILE *p1;FILE *p2;

       p1=fopen(name1,"r");
    char c;
    char ammount[10];int i=0;char a[1000];
    while((c=getc(p1))!=EOF)
    {
        a[i]=c;
        i++;
    }
    fclose(p1);
    i=0;int m;
   for(i=0;i<strlen(a);i++)
   {
      if(a[i]=='\n')
      {
          m=i;
          break;
      }
   }
   char temp[m];
  for(i=0;i<=m;i++)
  {
     temp[i]=a[i];
  }
  int r;float num=0;;
 /*for(i=0;i<m;i++)
 {
     r=temp[i]-'0';
     num=(num*10)+r;

 }*/
 num=atof(temp);
  float x;
  int j;
  for(j=0;j<1;j++)
  {
      printf("enter the ammount to be transferred:");
      scanf("%f",&x);
      if(x>num)
      {
          printf("insufficient balance in your account. An ammount less than %d can only be transferred\n",num);
          j--;
      }
  }
  num=num-x;
  p1=fopen(name1,"w");
  fprintf(p1,"%0.2f\n",num);

   int y;
   for(i=0;i<strlen(a);i++)
   {
       if(a[i]=='\n')
       {
         y=i;
       }
   }
  for(i=m+1;i<=y;i++)
  {
      fflush(stdin);
      fprintf(p1,"%c",a[i]);
      fflush(stdin);
  }
  fclose(p1);

  char st[50];strcpy(st,name1);
  strcat(name1,"_passbook");
  pa=fopen(name1,"a");
  fprintf(pa,"%s: transfer of Rs %0.2f by %s to %s\n",da,x,st,name2);
  fclose(pa);

  //deposit process begins here

   p2=fopen(name2,"r");
    //char c;
    //char ammount[10];int i=0;char a[1000];
    i=0;char b[50];
    while((c=getc(p2))!=EOF)
    {
        b[i]=c;
        i++;
    }
    fclose(p2);
    i=0;//int m;
   for(i=0;i<strlen(b);i++)
   {
      if(b[i]=='\n')
      {
          m=i;
          break;
      }
   }
   //char temp[m];
   char temp2[m];
  for(i=0;i<=m;i++)
  {
     temp2[i]=b[i];
  }
   num=0;
 /*for(i=0;i<m;i++)
 {
     r=temp[i]-'0';
     num=(num*10)+r;

 }*/
  num=atof(temp2);
 //printf("%d",num);
 // printf("enter the ammount to be deposited:");
  //float x;
  //scanf("%f",&x);
  num=num+x;
  p2=fopen(name2,"w");
  fprintf(p2,"%0.2f\n",num);

   //int y;
   for(i=0;i<strlen(b);i++)
   {
       if(b[i]=='\n')
       {
         y=i;
       }
   }
  for(i=m+1;i<=y;i++)
  {
      fflush(stdin);
      fprintf(p2,"%c",b[i]);
      fflush(stdin);
  }
  fclose(p2);

  FILE *paa;
  strcat(name2,"_passbook");
  paa=fopen(name2,"a");
  fflush(stdin);
  fprintf(paa,"%s: deposited Rs %0.2f  via money transfer by %s \n",da,x,str);
  fflush(stdin);
  fclose(paa);





  }

  void loan()
  {
    fflush(stdin);
    float bp;float n;float si;float ammount;float t;float emi;
    printf("For a basic pay of Rs. 4 lakhs(p.a) to Rs. 8 lakhs(pa)\n a loan upto Rs. 6lakhs can be granted.\n\n");
    printf("For a basic pay of Rs. 8 lakhs(p.a) to Rs. 16 lakhs(pa)\n a loan upto Rs. 12lakhs can be granted.\n\n");
    printf("For a basic pay of Rs. 16 lakhs(p.a) to Rs. 20 lakhs(pa)\n a loan upto Rs. 18lakhs can be granted.\n\n");
    printf("enter basic pay salary:");
    scanf("%f",&bp);
    printf("enter the number of years for which period loan amount is requested:");
    scanf("%f",&t);

    if(bp>=400000 && bp<800000)
    {
        printf("enter requested loan ammount:");
        scanf("%f",&n);
        if(n>=600000)
        {
            printf("considering the basic pay\nit is in the incapability of the manager to grant requested ammount of loan");
        }
        else
        {
            printf("\n\n");
           si=(n*9*t)/100;
           ammount=n+si;
           emi=((ammount)/t)/12;
           printf("total ammount to be payed to the bank:Rs %0.2f",ammount);
           printf("\n\n");
           printf("equated monthly installment to be payed to the bank:Rs %0.2f",emi);
        }

    }

     if(bp>=800000 && bp<1600000)
    {
        printf("enter requested loan ammount:");
        scanf("%f",&n);
        if(n>=1200000)
        {
            printf("considering the basic pay\nit is in the incapability of the manager to grant requested ammount of loan");
        }
        else
        {
            printf("\n\n");
           si=(n*9*t)/100;
           ammount=n+si;
           emi=((ammount)/t)/12;
           printf("total ammount to be payed to the bank:Rs %0.2f",ammount);
           printf("\n\n");
           printf("equated monthly installment to be payed to the bank:Rs %0.2f",emi);
        }

    }

     if(bp>=1600000 && bp<2000000)
    {
        printf("enter requested loan ammount:");
        scanf("%f",&n);
        if(n>=1800000)
        {
            printf("considering the basic pay\nit is in the incapability of the manager to grant requested ammount of loan");
        }
        else
        {
            printf("\n\n");
           si=(n*9*t)/100;
           ammount=n+si;
           emi=((ammount)/t)/12;
           printf("total ammount to be payed to the bank:Rs %0.2f",ammount);
           printf("\n\n");
           printf("equated monthly installment to be payed to the bank:Rs %0.2f",emi);
        }

    }



  }

  void fix()
  {
       fflush(stdin);
    char ar[50];
    printf("NOTE:fixed deposit account can only be opened\nif a running savings or current bank account\nalready exists in the bank.\n\n");
    printf("enter the name:");
    fflush(stdin);
    gets(ar);
    fflush(stdin);

    FILE *x;FILE *y;float pr;
    x=fopen(ar,"r");
    fclose(x);
    if(x==NULL)
    {
        printf("Sorry,the given savings bank account doesn't exist,\nNot authorised to open a FIXED DEPOSIT ACCOUNT..\n");
    }
    else
    {
        strcat(ar,"_fd");
        y=fopen(ar,"a");
        printf("enter the principal ammount:");
        scanf("%f",&pr);
        printf("enter date of opening the account:");
        fflush(stdin);
        gets(date1);
        fflush(stdin);
        fprintf(y,"%0.2f\n",pr);
        fprintf(y,"%s\n",date1);
        fclose(y);

    }
}
void mat()
{
     fflush(stdin);
  char name[50];
  printf("enter name:");
  fflush(stdin);
  gets(name);
  fflush(stdin);
  strcat(name,"_fd");

  FILE *p;
  p=fopen(name,"r");
    char c;
    char ammount[10];int i=0;char a[1000];
    while((c=getc(p))!=EOF)
    {
        a[i]=c;
        i++;
    }
    fclose(p);
    i=0;int m;
   for(i=0;i<strlen(a);i++)
   {
      if(a[i]=='\n')
      {
          m=i;
          break;
      }
   }
   char temp[m];
  for(i=0;i<=m;i++)
  {
     temp[i]=a[i];
  }
  int r;float num=0;
  num=atof(temp);
  printf("%0.2f",num);

  int y;
   for(i=0;i<strlen(a);i++)
   {
       if(a[i]=='\n')
       {
         y=i;
       }
   }
   printf("\n");int h=0;
  for(i=m+1;i<=y;i++)
  {
     date1[h]=a[i];
     h++;
  }

 printf("enter today's date:");
 fflush(stdin);
 gets(date2);
 fflush(stdin);
 int d1,m1,y1,d2,m2,y2;
 printf("\n");

d1=(date1[0]-'0')*10 + (date1[1]-'0');
m1=(date1[3]-'0')*10 + (date1[4]-'0');
y1=(date1[6]-'0')*1000 + (date1[7]-'0')*100 + (date1[8]-'0')*10 + (date1[9]-'0');


d2=(date2[0]-'0')*10 + (date2[1]-'0');
m2=(date2[3]-'0')*10 + (date2[4]-'0');
y2=(date2[6]-'0')*1000 + (date2[7]-'0')*100 + (date2[8]-'0')*10 + (date2[9]-'0');
if(y1%4==0)
     {
         max1[2]=29;
     }
     else
     {
         max1[2]=28;
     }

   if(y2%4==0)
     {
         max2[2]=29;
     }
   else
    {
       max2[2]=28;
    }

   int day1;int day2;int diff;
   day1=day_calc(d1,m1,y1);
   day2=day_calc(d2,m2,y2);
   if(day1>day2)
   {
   diff=day1-day2;
}
else
{
   diff=day2-day1;
}

float si;
float amm;
float t;
t=(diff)/365;

si=(num*6*t)/100;
amm=num+si;
printf("maturity value is:%f",amm);
}

int day_calc(int d,int m,int y)
{
  int ctr=0;int i;
   if(y%4==0)
      {
          max[2]=29;
        }
        else
        {
            max[2]=28;
        }

  for( i=1;i<m;i++)
  {

      ctr=ctr+max[i];
    }

    ctr=ctr+d;
  for( i=1;i<y;i++)
  {
     if(i%4==0)
     {
       ctr=ctr+366;
    }
    else
    {
        ctr=ctr+365;
    }
}

    return(ctr);

}
void display()
{
     fflush(stdin);
    printf("\n\n");
    FILE *pf3;char name[50];
    printf("enter your name:");
    fflush(stdin);
    gets(name);
    fflush(stdin);


    pf3=fopen(name,"r");
    char c;
    char ammount[10];int i=0;char a[1000];
    while((c=getc(pf3))!=EOF)
    {
        a[i]=c;
        i++;
    }
    fclose(pf3);
    i=0;int m;
   for(i=0;i<strlen(a);i++)
   {
      if(a[i]=='\n')
      {
          m=i;
          break;
      }
   }
   char temp[m];
  for(i=0;i<=m;i++)
  {
     temp[i]=a[i];
  }
  int r;float num=0;;

  num=atof(temp);
  printf("\n");
  printf("Current Bank Balance:%0.2f",num);
}



void main()
{  fflush(stdin);
    char c='y';
 while(c=='y')
  {
    printf("Enter 1 to open a new savings bank account\n");
    printf("Enter 2 to change your account details\n");
    printf("Enter 3 to deposit an ammount in your account\n");
    printf("Enter 4 to withdraw an ammount from your account\n");
    printf("Enter 5 to display your digital passbook\n");
    printf("Enter 6 for account to account money transfer\n");
    printf("Enter 7 to check for loan eligibility\n");
    printf("Enter 8 to open a fixed deposit acccount\n");
    printf("Enter 9 to claim your fixed deposit final maturity ammount\n");
    printf("Enter 10 to display cuurent bank balance in savings bank account\n");
    int n;
    printf("\n\n");

    printf("enter your choice\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:create();
               break;
        case 2:edit();
               break;
        case 3:deposit();
               break;
        case 4:withdraw();
               break;
        case 5:passbook();
               break;
        case 6:transfer();
               break;
        case 7:loan();
               break;
        case 8:fix();
               break;
        case 9:mat();
               break;
        case 10:display();
                break;

}
    printf("\n\n");
    printf("Do you wish to continue?\nenter y to continue and n to exit.");
    fflush(stdin);
    scanf("%c",&c);
    fflush(stdin);
    printf("****************************************************************************************************************************************************************\n");

}

}
