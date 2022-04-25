const int maxn=1e4+3;

int f[maxn];
int vis[maxn];

void init(int n) {
  for (int i=1;i<=n;i++) f[i] = 1,vis[i] = 0;
}

int find(int x) {
  if (x == f[x]) return f[x];
  return f[x] = find(f[x]);
}

void create(int x,int y) {
  int dx = find(x);
  int dy = find(y);
  
  if (vis[dx] == vis[dy])
    vis[dx]++,f[dy]=dx;
    else
    vis[dx] < vis[dy] ? f[dx] = dy : f[dy] = dx;
}
