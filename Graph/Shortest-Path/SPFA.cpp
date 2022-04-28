const int maxn = 1e4 + 3;

struct Node {
  int v, w;
};
vector<Node> v[maxn]; //邻接表存图

int dis[maxn]; // 距离
int vis[maxn]; // 访问标记
int neg[maxn]; // 负圈判断

int spfa(int n, int s) { // SPFA
  
  for (int i = 1; i <= n; i++) dis[i] = inf, vis[i] = 0, neg[i] = 0;
  dis[s] = 0, vis[s] = 1, neg[s] = 1;

  queue<int> q;
  q.push(s);
  
  while (q.size()) {
    int x = q.front();
    
    q.pop();
    vis[x] = 0;// 出队列，清除访问标记
    
    for (int i = 0; i < v[x].size(); i++) {
      int y = v[x][i].v;
      int w = v[x][i].w;

      if (dis[y] > dis[x] + w) {
        dis[y] = dis[x] + w;
        if (!vis[y]) { //没有被标记
          vis[y] = 1, neg[y]++;
          q.push(y);
          if (neg[y] > n) return -1;
        }
      }
    }
  }
  return 0;
}
