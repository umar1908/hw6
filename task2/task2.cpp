#include <iostream>
#include <iomanip>
using namespace std;
// #include <functional>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <cmath>
// #include <cstdlib>
// #include<utility>
// #include <exception>
// #include <bitset>
// #include<random>
#include<fstream>

int main(){
  system("chcp 1251"); //дл€ корректного отображени€ кирилицы
  cout<<endl;
  ifstream file("example.txt", ios::in|ios::binary);
  if (!file) {
    cout<<"read error";
    return EXIT_FAILURE;
  }
  string out_str;
  getline(file,out_str);
  auto length=file.tellg();
  size_t num;
  cout<<"¬ведите номер строки которую нужно вывести\n";
  cin>>num;
  file.seekg((num-1)*length);
  getline(file,out_str);
  cout<<out_str<<endl;
}
