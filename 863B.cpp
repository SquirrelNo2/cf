#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int ans= 1000;
int weight[100];

int comp(const void * i, const void * j){
  if(*(int *)i < *(int *)j) return -1;
  if(*(int *)i > *(int *)j) return 1;
  return 0;
}

int main(){
  scanf("%d", &n);
  for(int i = 0; i < 2*n; i++){
    scanf("%d", &weight[i]);
  }
  qsort(weight, 2*n, sizeof(int), comp);

  for(int i = 0; i < 2*n; i++){
    for(int j = i + 1; j < 2*n; j++){
      vector<int> v;
      for(int k = 0; k < 2*n; k++){
        if(k != i && k != j){
          v.push_back(weight[k]);
        }
      }
      int total= 0;
      for(int l = 1; l < v.size(); l += 2){
        total += v[l] - v[l-1];
      }

      ans= min(ans, total);
    }
  }

  printf("%d\n", ans);

  return 0;
}
