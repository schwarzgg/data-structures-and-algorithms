const int maxn = 1e4 + 3;
const int inf = 0x7fffffff;

struct Node {
  int u, v, w;
};
vector<Node> v;

int f[maxn];
int vis[maxn];

void init(int n) {
  for (int i = 1; i <= n; i++) f[i] = i, vis[i] = 0;
}

int find(int x) {
  if (x == f[x]) return f[x];
  return f[x] = find(f[x]);
}

void create(int x, int y) {
  int dx = find(x);
  int dy = find(y);

  if (vis[dx] == vis[dy])
    vis[dx]++, f[dy] = dx;
  else
    vis[dx] < vis[dy] ? f[dx] = dy : f[dy] = dx;
}

int kruskal(int n) {
  int ans = 0;
  int cnt = 0;
  
  sort(v.begin(), v.end(), [](Node x, Node y) { return x.w < y.w; });
  init(n);

  for (int i = 0; i < v.size(); i++) {
    if (cnt == n - 1) break;
    int x = v[i].u;
    int y = v[i].v;

    if (find(x) != find(y)) {
      ans += v[i].w;
      create(x, y);
      cnt++;
    }
  }
  return ans;
}
