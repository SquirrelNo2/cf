#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

const int max_size = 200010;
int n, k, u, x, y;
long long result;

/* the number of universities along the traversal path starting from a university
 */
int uni_num[max_size];
vector<int> node[max_size];

void dfs(int now, int pre){

  for(int i = 0; i < node[now].size(); i++){

    if(node[now][i] == pre) continue;
    dfs(node[now][i], now);
    uni_num[now] += uni_num[ node[now][i] ];
    result += min( uni_num[ node[now][i] ], 2*k - uni_num[ node[now][i] ] );
  }
}

int main() {

  scanf("%d %d", &n, &k);

  for(int i = 0; i < 2 * k; i++){

    scanf("%d", &u);
    uni_num[u] = 1;
  }

  for(int i = 1; i < n; i++){

    scanf("%d %d", &x, &y);
    node[x].push_back(y);
    node[y].push_back(x);
  }

  dfs(1, 0);

  cout << result << '\n';

  return 0;
}
