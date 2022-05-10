struct dsu{
  vector<int>par,rk,size;
  int c;
  dsu(int n):par(n+1),rk(n+1,0),size(n+1,1),c(n){
    for (int i=1;i<=n;i++) par[i] = i;
  }
  int find(int x) {
    if (x == par[x]) return par[x];
    return par[x] = find(par[x]);
  }
  bool same(int x,int y){
    return find(x) == find(y);
  }
  int count(){
    return c;
  }
  int get_size(int x){
    return size[find(x)];
  }
  int merge(int x,int y){
    if ((x = find(x)) == (y = find(y))) return -1;
    else c--;
    
    if (rk[x] > rk[y]) swap(x,y);
    par[x] = par[y],size[y]+=size[x];
    if (rk[x] == rk[y]) rk[y]++;
    return j;
  }
}

// if you want to use it ,you can create a struct called "dsu d(n)"
// sometimes maybe this code will be better than that pre-version.
