const int maxn=1e4+3;

struct Node {
  int u, v, w;
} e[maxn]; // 结构体存边

int dis[maxn]; // 单源距离数组

void bell(int n, int m, int s) {
  for (int i = 1; i <= n; i++) dis[i] = inf;
  dis[s] = 0;
  int f = 0;
  bool ud = 1; // 判断负圈标志
  while (ud) {
    f++, ud = 0;

    if (f > n) return; // 在n次更新之后,如果还能更新最短路，则该图中有负环
    for (int i = 0; i < m; i++) {
      int x = e[i].u;
      int y = e[i].v;

      if (dis[x] > dis[y] + e[i].w) dis[x] = dis[y] + e[i].w, ud = 1;
    }
  }
}
