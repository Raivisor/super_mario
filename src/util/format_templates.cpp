/**
	- Зачем нужен этот файл? 
	- Какие есть варианты реализации без такого подхода?
	- В чём + и - всех подходов?
*/

#include "format.hpp"
#include "format.cpp"

template std::string sea::format_string<int>(const std::string&, int);
template std::string sea::format_string<std::string>(const std::string&, std::string);
