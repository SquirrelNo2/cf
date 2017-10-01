#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

#define MAX_SIZE 105
int cnt[MAX_SIZE][MAX_SIZE];

int dp(const std::string& s, int l, int r){
  if(l > r) return 0; // invalid range
  if(l == r) return 1; // one cost to print a single character
  if(cnt[l][r] != s.size() + 1) return cnt[l][r]; // solved subproblem

  for(int i = l + 1; i <= r; i++){
    if(s[i] == s[l]){
      // s[i] is already covered in the string starting from s[l]
      cnt[l][r] = min(cnt[l][r], dp(s, l + 1, i - 1) + dp(s, i, r));
    }else{
      // s[i] is not in the string, so we need one more print to cover the
      // rest of the string
      cnt[l][r] = min(cnt[l][r], dp(s, l + 1, i - 1) + dp(s, i, r) + 1);
    }
  }
  return cnt[l][r];
}

int main(){
  std::string s;
  std::getline(cin, s);
  for(int i = 0; i < MAX_SIZE; i++){
    for(int j = 0; j < MAX_SIZE; j++){
      cnt[i][j] = s.size() + 1;
    }
  }
  printf("%d\n", dp(s, 0, s.size() - 1));
}
