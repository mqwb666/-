#include <stdio.h>
#include <stdlib.h>
#define MAXInt 32767
#define MVNum 100
int visited[MAXInt]={0}; 
typedef struct{
	char vexs[MVNum];
	int arcs[MVNum][MVNum];
	int vexnum,arcnum;
}AMGraph;

void init(){
	int i;
	for(i=0;i<MAXInt;i++){
		visited[i]=0;
	}
}

int Search(AMGraph G,char s){
	int i;
	for(i=G.vexnum;i>=0;i--)
		if(G.vexs[i]==s)	return i;
	printf("顶点不存在");
	exit(0);
}


AMGraph CreateUDN(){
	int i,j,k,w;
	char s1,s2;
	AMGraph G;
	printf("请输入顶点数：");
	scanf("%d",&G.vexnum);
	printf("请输入边数：");
	scanf("%d",&G.arcnum);
	printf("请输入顶点信息：");
	for(i=0;i<G.vexnum;i++){
		scanf("%c",&G.vexs[i]);
		if(G.vexs[i]=='\n'||G.vexs[i]==' ')
			i--;
	}
	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++)
			G.arcs[i][j]=MAXInt;
			
	for(k=0;k<G.arcnum;k++){
		printf("请输入一条边对应的两个顶点及权值：\n");
		do{
			s1=getchar();
		}while(s1=='\n');
		do{
			s2=getchar();
		}while(s2=='\n');
		s2=getchar();
		i=Search(G,s1);
		j=Search(G,s2);
		scanf("%d",&w); 
		G.arcs[i][j]=w;
		G.arcs[j][i]=G.arcs[i][j];
	}
	return G;
}

void AdjTraverse(AMGraph G){
	int i,j;
	for(i=0;i<G.vexnum;i++){
		for(j=0;j<G.vexnum;j++)
			if(G.arcs[i][j]!=MAXInt)
				printf("%d",G.arcs[i][j]);
			else
				printf("0");
		printf("\n");
	}
}

void DFS(AMGraph G,int v){
	int i,j;
	printf("%c->",G.vexs[v]);
	visited[v]=1;
	for(i=0;i<G.vexnum;i++){
		j=G.arcs[v][i];
		if(j!=MAXInt&&!visited[i]&&i!=G.vexnum)
		DFS(G,i);
	}
}

void DFSTraverse(AMGraph G){
	int i;
	for(i=0;i<G.vexnum;i++)
		if(!visited[i]) {
			DFS(G,i);
			printf("\n");
		}
} 

int main(){
	AMGraph G;
	G=CreateUDN();
	AdjTraverse(G);
	printf("深度优先搜索：\n");
	init();
	DFSTraverse(G);
	return 0;
}
 
