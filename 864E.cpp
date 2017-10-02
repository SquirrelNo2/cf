#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

int n, t, d, p, start_id;
int dest[100], savt[100], pri[100];
int val[100][2000], cnt[100][2000];
vector<int> id;
pair<int, int> nex[100][2000];

int cmp(int &i, int &j){
  return dest[i] < dest[j];
}

int dp(int n, int t){
  if(t > 2000 || n + 1 > id.size()) return 0;
  if(val[n][t]) return val[n][t];
  int ans1 = dp(n + 1, t);
  int ans2 = 0;
  if(dest[id[n]] > t + savt[id[n]]){
    ans2= dp(n + 1, t + savt[id[n]]) + pri[id[n]];
  }
  if(ans2 > ans1 && t == 0) start_id = id[n];
  cnt[n][t] = (ans2 > ans1) ? cnt[n + 1][t + savt[id[n]]] + 1 : cnt[n+1][t];
  nex[n][t] = (ans2 > ans1) ? make_pair(n + 1, t + savt[id[n]]) : make_pair(n+1, t);
  return val[n][t] = max(ans1, ans2);
}

int main(){
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%d %d %d", &t, &d, &p);
    if(t < d){
      dest[i] = d;
      savt[i] = t;
      pri[i] = p;
      id.push_back(i);
    }
  }
  sort(id.begin(), id.end(), cmp);
  memset(cnt, 0, sizeof(cnt));

  printf("%d\n", dp(0, 0));
  printf("%d\n", cnt[0][0]);

  vector<int> ans;
  int l = 0;
  int r = 0;
  ans.push_back(start_id);

  for(int i = 0; i < cnt[0][0] - 1; i++){
    int temp_l = l;
    l = nex[temp_l][r].first;
    r = nex[temp_l][r].second;
    while(nex[l][r].second == r || r == 0){
      temp_l++;
      l = nex[temp_l][r].first;
      r = nex[temp_l][r].second;
    }
    ans.push_back(id[l]);
  }

  for(int i = 0; i < cnt[0][0]; i++){
    printf("%d", ans[i] + 1);
    if(i + 1 != cnt[0][0]) printf(" ");
  }
  printf("\n");
}
