//RAT IN A MAZE using Recursion and BackTracking
#include <bits/stdc++.h>
using namespace std;

bool ratinmaze(char maze[100][100],int soln[100][100],int i,int j,int m,int n){
    if(i==m&&j==n){
        soln[i][j]=1;
        for(int i=0;i<=m;i++){for(int j=0;j<=n;j++){cout<<soln[i][j]<<" ";}cout<<endl;}
        cout<<endl;
        return true;
    }
    if(i>m||j>n)return false;
    if(maze[i][j]=='X')return true;
    soln[i][j]=1;
    bool rightpath=ratinmaze(maze,soln,i,j+1,m,n);
    bool downpath=ratinmaze(maze,soln,i+1,j,m,n);
    soln[i][j]=0;
    if(rightpath||downpath){return true;}
    return false;
}
int main() {
    int m,n;
    cin>>m>>n;
    char maze[100][100];
    for(int i=0;i<m;i++)for(int j=0;j<n;j++)cin>>maze[i][j];
    int soln[100][100];
    memset(soln,0,sizeof(soln));
    bool res=ratinmaze(maze,soln,0,0,m-1,n-1);
    if(res)cout<<"Rat can cross maze"<<endl;
    else cout<<"Rat cannot cross maze"<<endl;
    

}
