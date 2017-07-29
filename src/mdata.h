#ifndef MDATA_H_
#define MDATA_H_

#include <vector>
#include <cstdlib>
template <typename T>
class mdata{

public:
    mdata()=delete;

    mdata(const T* _data,size_t r,size_t c){
      for(int i=0; i<r;i++){
        std::vector<T> raw(r,static_cast<T>(0));
        for(int j=0; j<c; i++){
          raw[j]=_data[i*c+j];
        }
        data.push_back(raw);
      }
      raw_num=r;
      col_num=c;
    }

    mdata(const std::vector<T> &_data,size_t r,size_t c){
      raw_num=r;
      col_num=c;
      for(int i=0; i<r; i++){
        std::vector<T> raw(c,static_cast<T>(0));
        for(int j=0;j<c;j++){
          raw[j]=_data[i*c+j];
        }
        data.push_back(raw);
      }
    }

    mdata(std::vector< std::vector<T> > _data){
      col_num=_data.col_num;
      raw_num=_data.raw_num;
      for(int i=0; i<_data.size(); i++){
        std::vector<T> raw(_data[i]);
        data.push_back(raw);
      }
    }

    mdata(const mdata &_mdata){
        for(int i=0; i<_mdata.getRawNum();i++){
            std::vector<T> raw(_mdata.data[i]);
            data.push_back(raw);
        }
    }

    ~mdata(){ }
    
   size_t getRawNum()const{
        return raw_num;
    }
   
   size_t getColNum()const{
        return  col_num;
   }

    const std::vector<std::vector<T> >& getData() const{
        return data;
    }

    const std::vector<T>& operator[](int i) const{
        return data.at(i); 
    }

private:
    std::vector<std::vector<T> > data;
    size_t col_num;
    size_t raw_num;

};
#endif
