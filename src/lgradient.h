#ifndef LGRAIDENT_H_
#define LGRAIDENT_H_
#include <iostream>
#include <vector>

#include "mdata.h"

class lgradient{

public:
	lgradient():
    error(0.0000001),
    lspeed(0.000001)
  {  }
    
  lgradient(double e,double s):
    error(e),
    lspeed(s)
  {  }

	~lgradient(){
	}

	void setError( double _error){
		this->error=_error;
	}
	
	double getError(void)const{
		return this->error;
	}

	void setSpeed(double _speed){
		this->lspeed=_speed;
	}

	double getSpeed(void)const{
		return this->lspeed;
	}

   std::vector<double> solve(const mdata<double> &data);
private:
	double error;	 //learning error of the method
	double lspeed;   // learning speed of the method
	void dscent(void) const;	
	void hw(std::vector<double> &h,const std::vector<double> &weight,const mdata<double> &data) const;
	void grad(std::vector<double> &g,std::vector<double> &weight,const mdata<double> &data, std::vector<double> &h) const;
  void descent(std::vector<double> &weight,const mdata<double> &data) const;
 
};



#endif
