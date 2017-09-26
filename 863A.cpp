#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

int num;

int main(){

  scanf("%d", &num);
  string str= to_string(num);
  string str_cpy= str;

  for(int i = 0; i < 10; i++){
    str= str_cpy;
    reverse(str.begin(), str.end());
    if(!str_cpy.compare(str)){
      printf("%s", "YES\n");
      return 0;
    }else{
      str_cpy = "0" + str_cpy;
    }
  }
  printf("%s", "NO\n");

  return 0;
}
