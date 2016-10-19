#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
#include<conio.h>
struct match
	{
		int date,score_home,score_away;
		char home[30];
		char away[30];
	};
	struct match m[1000],temp;
	int n=0;
	int flag=0;
	char filename[30];
	
void register_match();
void print_match();
void sort_match();
void search_match();
void deregister();
void statistics();
int main()
{
	int opt;
	FILE *fptr;
	printf("Enter File Name: ");
	scanf("%s",&filename);
	
	fptr=fopen(filename,"r");
	if(fptr==NULL)
    {
        printf("New File Created.\n");
		getch();

    }
	if(fptr!=NULL)
	{
    while(fscanf(fptr,"%d%s%s%d-%d",&m[n].date,m[n].home,m[n].away,&m[n].score_home,&m[n].score_away)!=EOF)
        n++;
	}


	do{
		system("cls");
	printf("Press 1 To Register New Matches.\n");
	printf("Press 2 To Print All Matches.\n");
	printf("Press 3 To Sort Matches.\n");
	printf("Press 4 To Search For Matches.\n");
	printf("Press 5 To De-Register A Match.\n");
	printf("Press 6 To Presenting Statistics.\n");
	printf("Press 7 To Quit.\n");
	if(n>=999)
	{
		printf("Memory Full.\a\n");
		printf("Please De-Register Match To Clear Some Memory [PRESS 5].\a\n");
	}
	printf("Enter Your Option: ");
	scanf("%d",&opt);
	system("cls");
	switch(opt)
	{
	case 1:
		register_match();
		break;
	case 2:
		print_match();
		break;
	case 3:
		sort_match();
		break;
	case 4:
		search_match();
		break;
	case 5:
		deregister();
		break;
	case 6:
		statistics();
		break;
	case 7:
		break; 
	default:
		printf("Wrong Input.\n");
		break;
	}
	}while(opt!=7);
	print_match();

	return 0;
}

void register_match()
{
	char date[10],cmp;
	printf("Match Registration:\n");
	printf("Date\t\tHome\t\tAway\t\tScore\n");
	while(1)
	{
	getchar();
	if(n<1000)
	{	
	if (fgets (date, sizeof (date), stdin) == NULL)
            break;
            
	cmp=strcmp(date,"\n");
	if(cmp==0)
	{
		printf("Registration Completed\n");
		getch();
		break;
	}
	else 
	{
		sscanf (date, "%d", &m[n].date);
	}
		
	scanf("%s%s%d-%d",&m[n].home,&m[n].away,&m[n].score_home,&m[n].score_away);
	n=n+1;
	}
	else
	{
		
		printf("Error: Memory Full.\a");
		getch();
		break;
	}
	}
}

void print_match()
{
	int i;
	FILE *fptr;
	fptr=fopen(filename,"w");
	if(fptr==NULL)
	{
		printf("Error!");
		exit(1);
	}
	for(i=0;i<n;i++)
	{
		printf("Date:%d\tHome:%s\tAway:%s\tResult:%d-%d\n",m[i].date,m[i].home,m[i].away,m[i].score_home,m[i].score_away);
		fprintf(fptr,"%d\t%s\t%s\t%d-%d\n",m[i].date,m[i].home,m[i].away,m[i].score_home,m[i].score_away);
	}
	fclose(fptr);
	getch();
}

void sort_match()
{
	int opt,i,j,k=0;
	printf("Choose To Sort The Matches By Date Or Home Team/Player Name.\n");
	printf("Press 1 To Sort By Date.\n");
	printf("Press 2 To Sort By Home Team/Player Name.\n");
	printf("Enter Your Option: ");
	scanf("%d",&opt);
	switch(opt)
	{
	case 1:
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(m[i].date>m[j].date)
				{
					temp=m[i];
					m[i]=m[j];
					m[j]=temp;

				}
			}


		}
		break;
	case 2:
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				while(m[i].home[k]==m[j].home[k]&&k<30)
				{
					k++;
				}
				if(m[i].home[k]>=m[j].home[k])
				{
					temp=m[i];
					m[i]=m[j];
					m[j]=temp;
					

				}
				k=0;
				
			}


		}
		break;

		default:
		printf("Wrong Input.\n");
		break;
	}

}
void search_match()
{
	int opt,i,date;
	char name[30];
	flag=0;
	printf("Choose To Search The Matches By Date Or Team/Player Name.\n");
	printf("Press 1 To Search By Date.\n");
	printf("Press 2 To Search By Team/Player Name.\n");
	printf("Enter Your Option: ");
	scanf("%d",&opt);
	switch(opt)
	{
	case 1:
		printf("Enter Match Date: ");
		scanf("%d",&date);
		for(i=0;i<n;i++)
		{
			if(m[i].date==date)
			{
				printf("#%d. Date:%d\tHome:%s\tAway:%s\tResult:%d-%d\n",i+1,m[i].date,m[i].home,m[i].away,m[i].score_home,m[i].score_away);
				flag=1;
			}
		}
		if(flag==0)
		{
			printf("Not Found.\n");
		}
		break;
	case 2:
		printf("Enter Team/Player Name: ");
		scanf("%s",&name);
		
		for(i=0;i<n;i++)
		{
		   if(strstr(m[i].home,name)|| strstr(m[i].away,name))
		   {
			   printf("#%d. Date:%d\tHome:%s\tAway:%s\tResult:%d-%d\n",i+1,m[i].date,m[i].home,m[i].away,m[i].score_home,m[i].score_away);

			   flag=1;
		   }
		}
		if(flag==0)
		{
			printf("Not Found.\n");
		}
		break;

		default:
		printf("Wrong Input.\n");
		break;

	}
	getch();
}


void deregister()
{
	int num,i;
	printf("***Search The Match To De-Register.***\n");
	search_match();
	if(flag==1)
	{
	printf("Enter The Match Number Which You Want To Delete.\n");
	printf("Or Press 0 To Skip.\n");
	printf("Enter Number: ");
	scanf("%d",&num);
	num--;
	if(num<n-1&&num>-1)
	{
		for(i=num;i<n-1;i++)
		{
			m[i]=m[i+1];
		}
		n--;

	}
	else
	{
		if(num==n-1)
		{
			n--;
		}
	}
	}
}


void statistics()
{
	int i,found_1,found_2,flag=0,win=0,loss=0,draw=0;
	char name[100];
	    printf("Enter Team/Player Name: ");
		scanf("%s",&name);
		
		for(i=0;i<n;i++)
		{
           found_1=strcmp(name,m[i].home);
		   found_2=strcmp(name,m[i].away);
		   if(found_1==0)
		   {
			  if(m[i].score_home>m[i].score_away)
			  {
				  win++;
			  }
			  if(m[i].score_home<m[i].score_away)
			  {
				  loss++;
			  }
			  if(m[i].score_home==m[i].score_away)
			  {
				  draw++;
			  }
			  flag=1;
		   }
		   if(found_2==0)
		   {
			  if(m[i].score_home<m[i].score_away)
			  {
				  win++;
			  }
			  if(m[i].score_home>m[i].score_away)
			  {
				  loss++;
			  }
			  if(m[i].score_home==m[i].score_away)
			  {
				  draw++;
			  }
			  flag=1;
		   }

		}
		if(flag==1)
		{
			printf("%s's Present Statistics: Win:%d Loss:%d Draw:%d.\n",name,win,loss,draw);
		}
		if(flag==0)
		{
			printf("Not Found.\n");          
		}	
		getch();
}

