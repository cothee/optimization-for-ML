#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include "lgradient.h"
#include "mdata.h"
#include "util.h"

using namespace std;


int main(int argc, char* argv[]){
  std::string file;
  int c,r;

  if(argc!=7){
    std::cerr<<"argument list error!\n ";
    exit(0);
  }

  for(int i=1;i<argc;i+=2){
    std::string para1=argv[i];
    std::string para2=argv[i+1];
    if(para1[0]=='-'){
      switch(para1[1]){
        case 'f': file=para2; break;
        case 'c': c=std::atoi(para2.c_str()); break;
        case 'r': r=std::atoi(para2.c_str()); break;
      }
    }
  }

  mTool t;
  std::vector<double> from;
  t.readData(file,from);    
  mdata<double> data(from,r,c);
  lgradient lg;

  std::cout<<"===start to solve the problem...."<<std::endl;
  std::vector<double> result=lg.solve(data);
  std::cout<<"the coefficient of each variable in the solution are:"<<std::endl;
  for(int i=0;i<result.size();i++){
    std::cout<<result[i]<<std::endl;
  }

}


