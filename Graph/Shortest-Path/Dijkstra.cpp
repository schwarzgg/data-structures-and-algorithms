const int maxn = 1e4 + 3;
const int inf = 0x7fffffff;

struct Node {
  int v, w;
};
vector<Node> v[maxn]; // 邻接表存图

struct node {
  int dis, pos;
  bool operator>(const node& x) const { return this->dis > x.dis; }  // 重载>运算符,用于堆优化算法
};

int dis[maxn]; // 对于单个点到全图点的最短路
int vis[maxn]; // 标记数组,避免多次访问

void init(int n) { //初始化距离数组和数组(在slv中使用)
  for (int i = 1; i <= n; i++) dis[i] = inf, vis[i] = 0;
}

void dij(int s) { // Dijkstra,s为起点
  priority_queue<node, vector<node>, greater<node> > q;

  dis[s] = 0; //起点到自身距离为0
  q.push({dis[s], s});

  while (q.size()) {
    int x = q.top().pos;
    q.pop(); // 没有pop会使得程序很长时间没有出现结果
    
    if (vis[x]) continue;
    vis[x] = 1;

    for (int i = 0; i < v[x].size(); i++) {  // 遍历邻接表
      int y = v[x][i].v;
      int w = v[x][i].w;

      if (dis[y] > dis[x] + w) { // 满足条件,则push进堆中,进行下一个操作
        dis[y] = dis[x] + w;
        q.push({dis[y], y});
      }
    }
  }
}
