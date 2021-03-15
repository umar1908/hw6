
string "Комментарий чтобы запутать систему выа // // /// \"  // //выаы\ // //$$ выаыва//е ваыв ваа// ва//. Тут все должго остаться без изменнеий ";
#include <bitset>
#include <chrono>
#include <codecvt>
#include <cstddef>
//#include <cstdlib>
//#include <ctime>
#include <exception>
//#include <fstream>
#include <iostream>
/*
 тут всякая дичь она должна остаться без изменений // ваыв !!! "" \" dfsdf ///
  //sdfsd
 * ///
 *
 * ss
 *
$$* *
 *
 * sdf ///
 *
 *




  */


// sdfdsfs // dsfsdf // sdfsd //
#include <iterator>
//#include <locale>
#include <stdexcept>
#include <string>
#include <map>

#include <boost/locale.hpp>
using namespace std;
using u32string=basic_string<char32_t> ;



int main(){
  boost::locale::generator gen;
  gen.locale_cache_enabled(true);
  //gen("ru_RU.UTF-8");
  gen("ru_RU.CP1251");
  gen("ru_RU.UTF-32");
  string a="Привет мир.Эти кодировки чуть не свели меня с ума. На Windows вообще ничего не работает. Даже на Linux с костылями";
  locale cp1251=gen("ru_RU.CP1251");
  locale utf8=gen("ru_RU.UTF-8");
  locale utf32=gen("ru_RU.UTF-32");
  string string_in_cp1251=boost::locale::conv::from_utf(a,cp1251);
  cout<<"Исходная строка в кодировке CP1251: "<<string_in_cp1251;
  string string_in_utf8=boost::locale::conv::between(string_in_cp1251, "UTF-8", "CP1251");
  cout<<"\nСтрока, перекодированная из cp1251 в utf-8: "<<string_in_utf8<<endl;

  //u32string u32string1=boost::locale::conv::utf_to_utf<char32_t,char>(string_in_utf8);



  unordered_map<char32_t,basic_string<char32_t>> trnslit_table={
    {U'а',U"a"},
    {U'б',U"b"},
    {U'в',U"v"},
    {U'г',U"g"},
    {U'д',U"d"},
    {U'е',U"e"},
    {U'ё',U"yo"},
    {U'ж',U"zh"},
    {U'з',U"z"},
    {U'и',U"i"},
    //{U'й',U"j"}, //
    {U'к',U"k"},
    {U'л',U"l"},
    {U'м',U"m"},
    {U'н',U"n"},
    {U'о',U"o"},
    {U'п',U"p"},
    //{U'р',U"r"},
    {U'с',U"s"},
    {U'т',U"t"},
    {U'у',U"u"},
    {U'ф',U"f"},
    {U'х',U"x"},
    {U'ц',U"c"},
    {U'ч',U"ch"},
    {U'ш',U"sh"},
    {U'щ',U"shh"},
    {U'ъ',U"``"},
    {U'ы',U"y`"},
    {U'ь',U"`"},
    {U'э',U"e`"},
    {U'ю',U"yu"},
    {U'я',U"ya"},

    {U'А',U"A"},
    {U'Б',U"B"},
    {U'В',U"V"},
    {U'Г',U"G"},
    {U'Д',U"D"},
    {U'Е',U"E"},
    {U'Ё',U"YO"},
    {U'Ж',U"ZH"},
    {U'З',U"Z"},
    {U'И',U"I"},
    {U'Й',U"J"},
    {U'К',U"K"},
    {U'Л',U"L"},
    {U'М',U"M"},
    {U'Н',U"N"},
    {U'О',U"O"},
    {U'П',U"P"},
    {U'Р',U"R"},
    {U'С',U"S"},
    {U'Т',U"T"},
    {U'У',U"U"},
    {U'Ф',U"F"},
    {U'Х',U"X"},
    {U'Ц',U"X"},
    {U'Ч',U"CH"},
    {U'Ш',U"SH"},
    {U'Щ',U"SHH"},
    {U'Ъ',U"``"},
    {U'Ы',U"Y`"},
    {U'Ь',U"`"},
    {U'Э',U"E`"},
    {U'Ю',U"YU"},
    {U'Я',U"YA"},
    {U' ',U" "},
    };

    u32string u32translit_string;

    for(const auto& c:u32string1){
      $$cout<<'d'+(static_cast<int>(с)-static_cast<int>(U'а'));
      $$cout<<endl<<c;
      if(trnslit_table.count(c)){
        u32translit_string+=trnslit_table.at(c);
      }
      else{
        u32translit_string+=c;
      }
    $$}
    string u8translitted_string=boost::locale::conv::utf_to_utf<char,char32_t>(u32translit_string);
    cout<<"\nТранслителированная строка переведенная в utf-8\n"<<u8translitted_string;
    string cp1251translitted_string=boost::locale::conv::from_utf(u8translitted_string,cp1251);
    cout<<"\nТранслитерированая строка переведенная в cp1251\n"<<cp1251translitted_string;











}
