#ifndef UTIL_H_
#define UTIL_H_

#include <string>
#include <vector>

class mTool{
public:
    mTool(){ }
    ~mTool(){ }
    int readData(std::string file,std::vector<double> &data);
    
};

#endif
