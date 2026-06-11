#include<stdio.h>
#include<stdlib.h>
//zero checks the infinity case
//need to add filehandling as the loop runs as when loop ends pointers are initialized
//structure creates datatype for each vertex
struct Vertices
{
	int adjCount;
	int *adj;
	int *edgwt;
	int minwt;
	int curwt;
	char visited;
};

/*void Calculate(struct Vertices Calc,int N1)
{
	FILE *ptr=fopen("E:\\codes\\databin.bin","r");

}*/
int main()
{
	FILE *ptr=fopen("C:\\codes\\nodeRepo.bin","w");
	if (ptr==NULL)
	{
		printf("file not created");
		exit(0);
	}
	int N,i,j,count=0,Nadj,source,destination,temp,min,iteration=1;
	char flgAdj;
	printf("\n\n\t\t\t\t\t\t\tDijkstra's Algorithm\n\n");
	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	printf("\nEnter the number of vertices/points you wish to compare from:\n");
	scanf("%d",&N);
	struct Vertices data[N];
	for (i=0; i<N; i++) //for total vertices examination
	{
		data[i].visited='n';
		data[i].minwt=0;
		printf("\nHow many adjacent/joint vertices/points does %d have?\n",i);
NadjErr://adjacent vertices is equal or more than total vertices or isnt equal to provided no. of adjacent vertices
		scanf("%d",&Nadj);
		data[i].adjCount=Nadj;
		if (Nadj>=N)
		{
			printf("\nError in no. of joint points please re-enter your choice:");
			goto NadjErr;
		}
		data[i].adj=(int*)calloc(sizeof(int),Nadj);
		if (data[i].adj==NULL)
		{
			printf("DMA for adjacent vertices couldn't be created.");
			exit(0);
		}
		data[i].edgwt=(int*)calloc(sizeof(int),Nadj);
		if (data[i].edgwt==NULL)
		{
			printf("DMA for edge weight couldn't be created.");
			exit(0);
		}
		count=0;
		for (j=0; j<N; j++) //controls checking of adjacent vertices and data enty
		{
wtErr://when there are more vertices left than what needs to be filled
			if(i==j)
			{
				continue;
			}
			if (Nadj==(N-1))
			{
				printf("\nWhat is the weightage/distance of %d to %d?\n",j,i);
				scanf("%d",&data[i].edgwt[count]);
				data[i].adj[count]=j;
				count++;
				if (count==Nadj)
				{
					break;
				}
			}
			else
			{
				printf("\nIs %d adjacent/joins to %d?\n",j,i);
FlgAdjErr://when user inputs any other input than y or n
				fflush(stdin);
				scanf("%c",&flgAdj);
				if(flgAdj=='y'||flgAdj=='Y')
				{
					printf("\nWhat is the weightage/distance of %d to %d?\n",j,i);
					scanf("%d",&data[i].edgwt[count]);
					data[i].adj[count]=j;
					count++;
					if (count==Nadj)
					{
						break;
					}
				}
				else if(flgAdj=='N'||flgAdj=='n')
				{
					printf("\nNoted");
				}
				else
				{
					printf("\nOption is out of range please re-enter your choice?\n");
					goto FlgAdjErr;
				}
				if (count!=Nadj && count>(N-1-j))//since loops are started from 0 which makes using N unsuitable by 1
            	{
                	printf("\nError in value assignment, not enough vertices left.");
                	goto wtErr;
            	}
			}
		}
	}
	fwrite(data,sizeof(struct Vertices),N,ptr);
	//calculate(data,N);
	for (i = 0; i < N; i++)//removing pointer
    {
        free(data[i].adj);
        free(data[i].edgwt);
    }
	return 0;
}