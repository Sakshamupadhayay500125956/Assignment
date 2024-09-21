#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define INF INT_MAX
int minkey(int key[], bool mst[], int n){
    int min = INF;
    int minind = -1;
    for(int i=0; i<n;i++){
        if(mst[i]== false && key[i] < min){
            min = key[i];
            minind = i; }
    }
return minind; }
int primsalg(int cost[][100], int n){
    int parent[n];
    int key[n];
    int mst[n];
    for(int i=0; i<n;i++){
        key[i] = INF;
        mst[i] = false; }
    key[0] =0;
    parent[0] = -1;
    for(int j = 0; j<n-1;j++){
        int node = minkey(key, mst, n);
        mst[node] = true;
        for(int k=0; k<n; k++){
            if(cost[node][k] && mst[k] == false && cost[node][k] <key[j]){
                parent[k] = node;
                key[k] = cost[node][k];  }
                 }
        }
    int totalcost = 0;
    for(int i=0; i<n;i++){
        totalcost += cost[i][parent[i]]; }
    return totalcost; }
int main(){
    int n;
    printf("Enter the number of villages: ");
    scanf("%d", &n);
    int cost[100][100];
    printf("Enter the build cost matrix (%d x %d):\n", n,n);
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            scanf("%d", &cost[i][j]);  }
    }
    int mincost = primsalg(cost, n);
    printf("Minimum cost to reconnect all villages: %d\n", mincost);
return 0; }