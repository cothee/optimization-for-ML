#include <fstream>
#include <iostream>
#include "util.h"
int  mTool::readData(std::string file,std::vector<double> &data){
  data.clear();

  std::ifstream fin(file.c_str());
  if(!fin.is_open()){
    std::cerr<<"couldn not open the file:"<<file<<std::endl;
    return -1;
  }

  double num;
  char ch;
  while(fin.get(ch)){
    if(ch<='9'&&ch>='0'){
      fin.putback(ch);
      fin>>num;
      data.push_back(num);
    }
  }
  return 1;
}
