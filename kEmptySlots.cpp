#include<vector>
#include<algorithm>
#include<cstdio>
#include<sstream>
#include<iostream>

using namespace std;

int k;
vector<int> flower;

int kEmptySlots(vector<int>& flowers, int k) {
  vector<int> days (flowers.size());

  for(int i = 0; i < (int)flowers.size(); i++){
    days[flowers[i] - 1]= i + 1;
  }

  int ans = (int)flowers.size();
  int left = 0;
  int right= k + 1;

  for(int j = 1; j < (int)days.size(); j++){
    if(right == j){
      ans = min(ans, max(days[left], days[right]));
      right = k + j;
      left = j - 1;
    }else if(days[right] > days[j] || days[j] < days[left]){
      right++;
      left++;
    }
  }
  return (ans == flowers.size()) ? -1 : ans;
}

vector<int> getFlower(){
  char c;
  std::string line;
  std::getline(cin, line);
  std::istringstream iss(line);
  while(iss >> c){
    flower.push_back(c - '0');
  }
  return flower;
}

int main(){
  flower = getFlower();
  scanf("%d", &k);
  printf("%d\n", kEmptySlots(flower, k));
}
