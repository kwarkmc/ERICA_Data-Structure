#include <stdio.h>

#define N 100
#define INF 1000000

int a[N+1][N+1];
int visit[N+1];
int dist[N+1];
int start, end;
int n, m;

void input() {
  int i, j;
  int from, to;
  int w;
  scanf("%d %d %d", &n, &start, &end);
  scanf("%d", &m);

  for(i=1;i<n;i++)
    for(j=1;j<=n;j++)
      if(i != j)
        a[i][j] = INF;

  for(i=1;i<m;i++) {
    scanf("%d %d %d", &from, &to, &w);
    a[from][to] = w;
  }

  for(i=1;i<=n;i++)
    dist[i] = INF;
}

void dijkstra() {
  int i, j;
  int min;
  int v;
  dist[start] = 0;

  for(i=1;i<=n;i++) {

    min = INF;

    for(j=1;j<=n;j++) {
    if(visit[j] == 0 && min >dist[j]) {
      min = dist[j];
      v = j;
    }
  }

  visit[v] = 1;

  for(j=1;j<=n;j++) {
    if(dist[j] > dist[v] + a[v][j])
      dist[j] = dist[v] + a[v][j];
  }
}
}

int main(void) {
  input();
  dijkstra();
  printf("%d\n", dist[end]);
  return 0;
}
