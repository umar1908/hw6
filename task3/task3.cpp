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
#include<filesystem>

template <typename TP>
std::time_t to_time_t(TP tp)
{
    using namespace std::chrono;
    auto sctp = time_point_cast<system_clock::duration>(tp - TP::clock::now()
              + system_clock::now());
    return system_clock::to_time_t(sctp);
}

int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  cout<<endl;
  filesystem::path path ="./";
  cout<<"Введите путь до директории\n";
  string pathstr;
  cin>>pathstr;
  path=pathstr;
  if (!filesystem::is_directory(path)){
    cout<<"Неверный путь";
    return EXIT_FAILURE;
  }
  for(const auto& elem:filesystem::recursive_directory_iterator(path) ){
    if(filesystem::is_regular_file(elem)||filesystem::is_symlink(elem)){
    std::time_t cftime;
    cftime = to_time_t(elem.last_write_time());

    cout<<"name: "<<elem.path().stem()<<"\nextension:"<<elem.path().extension()<<"\nlast write time:"<< std::asctime(std::localtime(&cftime))<<endl;
    }
  }


}
