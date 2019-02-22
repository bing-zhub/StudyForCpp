#include<bits/stdc++.h>
using namespace std;
int graph[505][505];//ͼ
int city[505],dis[505],pathNum[505],teamNum[505];//ÿ�����оȻ��ӵ�����������ÿ�����е���̾��롢����ÿ�����е����·��������������ÿ�����еľȻ�������
bool visit[505];//ÿ�������Ƿ񱻷��ʹ�
int N,M,C1,C2;
void Dijkstra(){
    while(!visit[C2]){//����յ���л�û�б����ʣ�����ѭ��
        int MIN=INT_MAX,v=-1;//�ҳ�Ŀǰ������̵Ļ�û�б����ʵĳ���
        for(int i=0;i<N;++i)
            if(!visit[i]&&MIN>dis[i]){
                MIN=dis[i];
                v=i;
            }
        visit[v]=true;//���Ϊ�ѷ���
        for(int i=0;i<N;++i)
            if(!visit[i]&&graph[v][i]!=0&&dis[v]+graph[v][i]<dis[i]){
                dis[i]=dis[v]+graph[v][i];//�������·������
                pathNum[i]=pathNum[v];//�������·������
                teamNum[i]=teamNum[v]+city[i];//���³��еľȻ�������
            }else if(graph[v][i]!=0&&dis[v]+graph[v][i]==dis[i]){
                pathNum[i]+=pathNum[v];//�������·������
                teamNum[i]=max(teamNum[i],teamNum[v]+city[i]);//�ҳ��ܹ��ټ����ĳ��оȻ�������
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
    fill(dis,dis+N,INT_MAX);//�����·��������Ϊ���ֵ
    dis[C1]=0;//C1��������㣬���·��Ϊ0
    teamNum[C1]=city[C1];//C1��������㣬���·������Ϊ1
    pathNum[C1]=1;//C1��������㣬�ܹ��ټ��ľȻ�������Ϊ�����е�����
    Dijkstra();
    printf("%d %d",pathNum[C2],teamNum[C2]);//���
    return 0;
}
