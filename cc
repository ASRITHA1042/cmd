1.LEFT RECURSION
#include<stdio.h>
#include<string.h>
int main(){
	char g[100],temp[100], alpha[100], beta[100];
	int i, j,c;
	printf("Enter the production: ");
	scanf("%s", &g);
	printf("\n");
	int len = strlen(g);
	int count=0;
	if(g[0]==g[3])
	{
		for ( i = 0; i < len; i++) {
        if (g[i] == '|') {
            count = 1;
        }
        else if (count) {
            printf("%c -> %c%c'",g[0], g[i], g[0]);
        }
    }
    printf("\n");
    printf("%c'->",g[0]);
    for ( i = 4; i < len; i++) 
	{	
        if (g[i] == '|') {
            break;
        }
        else
        printf("%c", g[i]);
    }
    printf("%c'",g[0]);
    printf("\n%c'->epsilon",g[0]);
	}
	printf("CORRECT GRAMMER");
	return 0;
}
2.LEFT FACTORIAL
#include<stdio.h>
#include<string.h>
int main()
{
    char gram[20],p1[20],p2[20],mod[20],ne[20],temp[20];
    int i,j=0,k=0,l=0,pos;
    printf("enter production : A->");
    gets(gram);
    for(i=0;gram[i]!='|';i++,j++)
        p1[j]=gram[i];
    p1[j]='\0';
    for(j=++i,i=0;gram[j]!='\0';j++,i++)
        p2[i]=gram[j];
    p2[i]='\0';
    for(i=0;i<strlen(p1)||i<strlen(p2);i++){
        if(p1[i]==p2[i]){
            mod[k]=p1[i];
            k++;
            pos=i+1;
        }
    }
    for(i=pos,j=0;p1[i]!='\0';i++,j++){
        ne[j]=p1[i];
    }
    ne[j++]='|';
    for(i=pos;p2[i]!='\0';i++,j++){
        ne[j]=p2[i];
    }
    mod[k]='X';
    mod[++k]='\0';
    ne[j]='\0';
    printf("\nGrammar without left factoring  \n");
    printf(" A->%s",mod);
    printf("\n X->%s\n",ne);
}
3.RDP
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char input[10];
int i,error;
void E();
void T();
void Eprime();
void Tprime();
void F(); 
          main()
          {
i=0;
error=0;
                printf("Enter an arithmetic expression   :  "); 
                gets(input);
                E();
                if(strlen(input)==i&&error==0)
                        printf("\nAccepted\n");
                else printf("\nRejected\n");
                          }
void E()
{
     T();
     Eprime();
}
void Eprime()
{
     if(input[i]=='+')
     {
     i++;
     T();
     Eprime();
     }
     }
void T()
{
     F();
     Tprime();
}
void Tprime()
{
     if(input[i]=='*')
     {
                      i++;
                      F();
                      Tprime();
     }
}
     void F()
     {
          if(isalnum(input[i]))i++;
          else if(input[i]=='(')
          {
          i++;
          E();
          if(input[i]==')')
          i++;

          else error=1;
            }
        
          else error=1;
     }
     4.COMMENT OR NOT
     #include<stdio.h> 
#include<conio.h> 
int main()
{
	char com[30]; 
	int i,a=0; 
	printf("\n Enter comment:");
	gets(com); 
	if(com[0]=='/') 
	{
		if(com[1]=='/')
			printf("\n It is a comment"); 
		else if(com[1]=='*') 
		{		
			for(i=2;i<=30;i++)
			{
				if(com[i]=='*'&&com[i+1]=='/')
				{
					printf("\n It is a comment"); 
					a=1; 
					break;	
				}
				else 
					continue; 
			} 
			if(a==0)
				printf("\n It is not a comment");
		}
		else
			printf("\n It is not a comment");
	}
	else 
		printf("\n It is not a comment");
}
5.LEX TOKEN
#include<stdio.h>
#include<ctype.h>
int main()
{
	int i,idpointer=0,oppointer=0,dipointer=0;
	char a[100],id[100],op[100],di[100];
	printf("Entre a string");
	gets(a);
	for(i=0;a[i]!='\0';i++)
	{
		if(isdigit(a[i]))
		{
			di[dipointer]=a[i];
			dipointer++;
		}
		else if(isalpha(a[i]))
		{
			id[idpointer]=a[i];
			idpointer++;
		}
		else
		{
			op[oppointer]=a[i];
			oppointer++;
		}
	}
	printf(" identifiers : ");
     for(i=0;i<idpointer;i++)
	 {
        printf("%c ",id[i]);
     }
    printf("\n constants : ");
     for(i=0;i<dipointer;i++)
	 {
        printf("%c ",di[i]);
     }
    printf("\n operators : ");
      for(i=0;i<oppointer;i++)
	  {
        printf("%c ",op[i]);
      }
}
6.FIRST
#include<stdio.h>
#include<ctype.h>
void FIRST(char );
int count,n=0;
char prodn[10][10], first[10];
main()
{
int i,choice;
char c,ch;
printf("How many productions ? :");
scanf("%d",&count);
printf("Enter %d productions epsilon= $ :\n\n",count);
for(i=0;i<count;i++)
scanf("%s%c",prodn[i],&ch);
do
{
n=0;
printf("Element :");
scanf("%c",&c);
FIRST(c);
printf("\n FIRST(%c)= { ",c);
for(i=0;i<n;i++)
printf("%c ",first[i]);
printf("}\n");
printf("press 1 to continue : ");
scanf("%d%c",&choice,&ch);
}
while(choice==1);
}
void FIRST(char c)
{
int j;
if(!(isupper(c)))first[n++]=c;
for(j=0;j<count;j++)
{
if(prodn[j][0]==c)
{
if(prodn[j][2]=='$') first[n++]='$';
else if(islower(prodn[j][2]))first[n++]=prodn[j][2];
else FIRST(prodn[j][2]);
}
}
}
7.FOLLOW
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int n,p,i=0,j=0;
char a[10][10],Result[10];
char subResult[20];
void follow(char* Result,char c);
void first(char* Result,char c);
void addToResultSet(char[],char);
int main()
{
int i;
int choice;
char c,ch;
printf("Enter the no.of productions: ");
scanf("%d", &n);
for(i=0;i<n;i++)
 scanf("%s",a[i]);
do
 {
 printf("Find FOLLOW of -->");
 scanf(" %c",&c);
 follow(Result,c);
 printf("FOLLOW(%c) = { ",c);
 for(i=0;Result[i]!='\0';i++)
  printf(" %c ",Result[i]);
 printf(" }\n");
 printf("Do you want to continue(Press 1 to continue....)?");
 scanf("%d",&choice);
 }while(choice==1);
}

void follow(char* Result,char c)
{
int k;
subResult[0]='\0';
Result[0]='\0';
if(a[0][0]==c)addToResultSet(Result,'$');
for(i=0;i<n;i++)
 {
 for(j=2;j<strlen(a[i]);j++)
   {
  if(a[i][j]==c)
     {
   if(a[i][j+1]!='\0')first(subResult,a[i][j+1]);
   if(a[i][j+1]=='\0'&&c!=a[i][0])
    follow(subResult,a[i][0]);
   for(k=0;subResult[k]!='\0';k++)
    addToResultSet(Result,subResult[k]);
     }
   }
 }
}

void first(char* R,char c)
{
int k,m;
if(!(isupper(c))&&c!='#')
 addToResultSet(R,c);
 for(k=0;k<n;k++)
 {
  if(a[k][0]==c)
   {
   if(a[k][2]=='#'&&c!=a[i][0])follow(R,a[i][0]);

   else if((!(isupper(a[k][2])))&&a[k][2]!='#')
    addToResultSet(R,a[k][2]);
   else first(R,a[k][2]);
   for(m=0;R[m]!='\0';m++)
   addToResultSet(Result,R[m]);
   }
 }
}

void addToResultSet(char Result[],char val)
{
int k;
for(k=0 ;Result[k]!='\0';k++)
 if(Result[k]==val)
  return;
Result[k]=val;
Result[k+1]='\0';
}
