#include<iostream>
#include<limits.h>
#define SIZE 15
using namespace std;

class OBST
{
    private:
    int keys[SIZE]={};
    int prob[SIZE]={};
    int root[SIZE][SIZE]={};
    int weight[SIZE][SIZE]={};
    int cost[SIZE][SIZE]={};
    int n;

    public:
    void getData();
    int Min_Value(int i,int j);
    void bulid_OBST();
    void build_Tree();
    void print(int arr[][SIZE],int n);
};
void OBST::getData()
{
    cout<<"\nEnter the number of keys to be inserted-->";
    cin>>n;
    cout<<"\nEnter the all keys";
    for(int i=1;i<=n;i++)
    {
        cin>>keys[i];
    }
    cout<<"\nEnter there corrrsponding probalbilities";
    for(int i=1;i<=n;i++)
    {
        cin>>prob[i];
    }
}
int OBST::Min_Value(int i,int j)
{
    int k,l;
    int minimum=INT_MAX;
    for(l=root[i][j-1];l<=root[i+1][j];l++)
    {
        if(cost[i][l-1]+cost[l][j]<minimum)
        {
            minimum=cost[i][l-1]+cost[l][j];
            k=l;
        }
    }
    return k;
}
void OBST::bulid_OBST()
{
    int i,j,k,l;
    for(int i=0;i<n;i++)
    {
        cost[i][i]=weight[i][i]=root[i][i]=0;
        cost[i][i+1]=weight[i][i+1]=prob[i+1];
        root[i][i+1]=i+1;
    }
    cost[n][n]=weight[n][n]=root[n][n]=0;
    for(int l=2;l<=n;l++)
    {
        for(int i=0;i<=n-1;i++)
        {
            j=i+l;
            weight[i][j]=weight[i][j-1]+prob[j];
            k=Min_Value(i,j);
            cost[i][j]=weight[i][j]+cost[i][k-1]+cost[k][j];
            root[i][j]=k;
        }
    }
    cout<<"\nCost are\n";
    print(cost,n);
    cout<<"\nRoot are\n";
    print(root,n);
}
void OBST::build_Tree()
{
    int i,j,k;
    int queue[20],front=-1,rear=-1;
    cout<<"\n************OPTIMAL BINARY SEARCH TREE**************\n";
    cout<<"The root of tree is -->"<<keys[root[0][n]];
    cout<<"\nThe cost of root is -->"<<cost[0][n];
    cout<<"\n\n\tRoot\tLEFT child\tRIGHT child\n";
    queue[++rear]=0;
    queue[++rear]=n;
    while(front!=rear)
    {
        i=queue[++front];
        j=queue[++front];
        k=root[i][j];
        cout<<"\n\t"<<keys[k];
        if(root[i][k-1]!=0)
        {
            cout<<"\t\t"<<keys[root[i][k-1]];
            queue[++rear]=i;
            queue[++rear]=k-1;
        }
        else
            cout<<"\t\t";
        if(root[k][j]!=0)
        {
            cout<<"\t"<<keys[root[k][j]];
            queue[++rear]=k;
            queue[++rear]=j;
        }
        else
        {
            cout<<"\t";
        }
    }
    cout<<"\n";
}
void OBST::print(int arr[][SIZE],int n)
{
    for(int i=0;i<=n;i++)
    {
        cout<<"\n";
        for(int j=0;j<=n;j++)
        {
            cout<<"\t"<<arr[i][j];
        }
    }
}

int main()
{
    OBST t;
    t.getData();
    t.bulid_OBST();
    t.build_Tree();
    return 0;
}