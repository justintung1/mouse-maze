#include<stdio.h>
#include<stdlib.h>

int main(){
	int i,j;
	int x=1,y=1,cx,cy;
	typedef struct link{
		int data;
		struct link *next;
	} walk;
	walk *go;
	walk *top=NULL;
	walk *head;
	walk *del;
	int mouse[10][12]={
		{1,1,1,1,1,0,0,0,1,1,1,1},
		{1,2,0,0,1,1,1,1,1,1,1,1},
		{1,1,1,0,1,1,0,0,0,0,1,1},
		{1,1,1,0,1,1,0,1,1,0,1,1},
		{1,1,1,0,0,0,0,1,1,0,1,1},
		{1,1,1,0,1,1,0,1,1,0,1,1},
		{1,1,1,0,1,1,0,1,1,0,1,1},
		{1,1,1,0,1,1,0,0,1,0,1,1},
		{1,1,0,0,0,0,0,0,1,0,3,1},
		{1,1,1,1,1,1,1,1,1,1,1,1}
	};
	
	go=(walk*)malloc(sizeof(walk));
	go->data=mouse[1][1];
	go->next=top;
	top=go;
	printf("maze simulate map<1 represent wall, 2 represent entrence, 3 represent exit>\n");
	for(i=0;i<10;i++){
		for(j=0;j<12;j++){
			printf("%d ",mouse[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");
	while(top->data!=3){
		go=(walk*)malloc(sizeof(walk));
		if(mouse[y-1][x]!=1&&mouse[y-1][x]!=6){
			go->data=mouse[y-1][x];
			go->next=top;
			top=go;
			cy=y;
			cx=x;
			mouse[y-1][x]=6;
			y=y-1;
		}
		else if(mouse[y+1][x]!=1&&mouse[y+1][x]!=6){
			go->data=mouse[y+1][x];
			go->next=top;
			top=go;
			cy=y;
			cx=x;
			mouse[y+1][x]=6;
			y=y+1;
		}
		else if(mouse[y][x-1]!=1&&mouse[y][x-1]!=6){
			go->data=mouse[y][x-1];
			go->next=top;
			top=go;
			cy=y;
			cx=x;
			mouse[y][x-1]=6;
			x=x-1;
		}
		else if(mouse[y][x+1]!=1&&mouse[y][x+1]!=6){
			go->data=mouse[y][x+1];
			go->next=top;
			top=go;
			cy=y;
			cx=x;
			mouse[y][x+1]=6;
			x=x+1;
		}
		else{
			x=cx;
			y=cy;
			del=top;
			top=top->next;
			free(del); 
		}
	}
	for(i=0;i<10;i++){
		for(j=0;j<12;j++){
			printf("%d ",mouse[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	system("pause");
}
