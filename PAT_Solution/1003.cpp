#include<bits/stdc++.h>
using namespace std;
int graph[505][505];//ͼ

//ÿ�����оȻ��ӵ�����������ÿ�����е���̾��롢����ÿ�����е����·��������������ÿ�����еľȻ�������
int city[505],dis[505],pathNum[505],teamNum[505];

//ÿ�������Ƿ񱻷��ʹ�
bool visit[505];
int N,M,C1,C2;

void Dijkstra(){
	//����յ���л�û�б����ʣ�����ѭ��
    while(!visit[C2]){
    	//�ҳ�Ŀǰ������̵Ļ�û�б����ʵĳ���
        int MIN=INT_MAX,v=-1;
        
        for(int i=0;i<N;++i)
            if(!visit[i] && dis[i]<MIN){
                MIN=dis[i];
                v=i;
            }
            
        //���Ϊ�ѷ���
        visit[v]=true;
        for(int i=0;i<N;++i)
            if(!visit[i] && 
				graph[v][i]!=0 &&
				dis[v]+graph[v][i]<dis[i]){
					
                //�������·������
				dis[i] = dis[v] + graph[v][i];
				
				//�������·������
                pathNum[i]=pathNum[v];
                
                //���³��еľȻ�������
                teamNum[i]=teamNum[v]+city[i];
            }else if(graph[v][i]!=0 &&
					 dis[v]+graph[v][i] == dis[i]) {
            	//�������·������
                pathNum[i]+=pathNum[v];
                
                //�ҳ��ܹ��ټ����ĳ��оȻ�������
                teamNum[i]=max(teamNum[i],teamNum[v]+city[i]);
            }
    }
}
int main(){
    scanf("%d%d%d%d",&N,&M,&C1,&C2);
    for(int i=0;i<N;++i)
        scanf("%d",&city[i]);
    while(M--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        graph[a][b]=c;
        graph[b][a]=c;
    }
    
    //�����·��������Ϊ���ֵ
    fill(dis,dis+N,INT_MAX);

	//C1��������㣬���·��Ϊ0
    dis[C1]=0;
	
	//C1��������㣬�ܹ��ټ��ľȻ�������Ϊ�����е�����
    teamNum[C1]=city[C1];

	//C1��������㣬���·������Ϊ1
    pathNum[C1]=1;
    

    Dijkstra();
    printf("%d %d",pathNum[C2],teamNum[C2]);//���
    return 0;
}
