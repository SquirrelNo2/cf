#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#include<string>
#include<utility>

using namespace std;

#define MAX_VAL 100000
#define MIN_VAL -100000

int k;
int low = MAX_VAL;
int upp = MIN_VAL;
pair<int, int> ans;
vector< vector<int> > nums;
typedef vector<int>::iterator ptr;

class comp
{
public:
    bool operator()(pair<ptr, ptr> p1, pair<ptr, ptr> p2) {
        return *p1.first > *p2.first;
    }
};

int main(){
  scanf("%d", &k);

  std::priority_queue< pair<ptr, ptr>, vector< pair<ptr, ptr> >, comp> pq;

  for(auto row : nums){
    low = min(low, *row.begin());
    upp = max(upp, *row.begin());
    pq.push(make_pair(row.begin(), row.end()));
  }

  ans = make_pair(low, upp);

  if(pq.size() != k){
    auto ptrow = pq.top();
    ++ptrow.first;
    pq.pop();

    if(ptrow.first != ptrow.second){
      pq.push(ptrow);
      low = min(low, *pq.top().first);
      upp = max(upp, *ptrow.first);
    }

    if(upp - low < ans.first - ans.second){
      ans = make_pair(low, upp);
    }
  }
  printf("%d %d", ans.first, ans.second);
}
