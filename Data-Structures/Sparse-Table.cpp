// ST 表
// WARNING：ST 表能维护的信息非常有限，不能较好地扩展，并且不支持修改操作。

const int maxn = 1e4 + 3;
const int inf = 0x7fffffff;
const int lg = 31;

int st[maxn][lg];  // ST 表
int L[maxn];       // 以2为底的对数表（下取整）

int num[maxn];

void pre() {  // 打表(L的初始化)
  L[0] = 1;
  for (int i = 1; i < maxn; i++) L[i] = L[i / 2] + 1;
}

void init(int n)  { // ST表的建立
  for (int i = 1; i <= n; i++) st[i][0] = num[i];

  for (int j = 1; j <= lg; j++)
    for (int i = 0; i + (1 << j) - 1 <= n; i++)
            st[i][j] = std::max ( st[i][j-1], st[i + (1 << (j - 1)][j - 1]);
}

int query(int l, int r) { // 查询区间[l,r]的最大值（可通过修改库函数达到查询其他需要的值）
  int s = L[r - l + 1];

  return std::max(st[l][s], st[r - (1 << s) + 1][s]);
}
