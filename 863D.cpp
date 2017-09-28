#include<cstdio>

using namespace std;

int n, q, m, b;

int main(){
  scanf("%d %d %d", &n, &q, &m);

  int op[q], l[q], r[q], a[n];

  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  for(int i = 0; i < q; i++){
    scanf("%d %d %d", &op[i], &l[i], &r[i]);
  }

  for(int i = 0; i < m; i++){
    scanf("%d", &b);

    for(int j = q - 1; j >= 0; j--){
      if(b >= l[j] && b <= r[j]){
        if(op[j] == 2){
          b = l[j] + r[j] - b;
        }else{
          if(b == l[j]){
            b = r[j];
          }else{
            b--;
          }
        }
      }
    }
    printf("%d ", a[b - 1]);
  }
  printf("%c", '\n');
}
