#include<cstdio>
#include<vector>

using namespace std;

int n, temp;
vector<int> ivan, miss;
int exist [200010], visited[200010];

void reorder(){
  int j = 0;

  for(int i = 0; i < n; i++){
    if(!visited[ivan[i]] && (exist[ivan[i]] == 1 || miss[j] > ivan[i])){
      visited[ivan[i]] = 1;
      exist[ivan[i]]--;
    }else{
      exist[ivan[i]]--;
      ivan[i] = miss[j++];
    }
  }
}

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &temp);
    ivan.push_back(temp);
    exist[ivan[i]]++;
  }

  for(int i = 1; i <= n; i++)
    if(exist[i] == 0)
      miss.push_back(i);

  if(miss.size())
    reorder();

  printf("%lu\n", miss.size());
  for(int i = 0; i < n; i++)
    printf("%d ", ivan[i]);
  printf("%c", '\n');
}
