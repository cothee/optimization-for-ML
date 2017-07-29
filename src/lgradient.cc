#include <cmath>
#include "lgradient.h"

	void lgradient::hw(std::vector<double> &h,const std::vector<double> &weight,const mdata<double> &data)const{
		for(int i=0; i<h.size(); i++){
			double value=0.0;
			for(int j=0; j<weight.size(); j++){
				value += data[i][j]*weight[j];
			}
      value -= data[i][weight.size()];
			h[i]=value;
		}
	}

	void lgradient::grad(std::vector<double> &grad_value, std::vector<double> &weight,const mdata<double> &data, std::vector<double> &h)const{
		hw(h,weight,data);
		for(int i=0; i<weight.size();i++){
			double value = 0;
			for(int j=0; j<data.getRawNum();j++){
				value += h[j]*data[j][i];
			}
			grad_value[i]=value;
			weight[i] -= lspeed*value; //gradient descent
		}
	}

	void lgradient::descent(std::vector<double> &weight,const mdata<double> &data) const{
		std::vector<double> grad_value=std::vector<double>(weight.size(),0.0);
    std::vector<double> h=std::vector<double>(data.getRawNum(),0.0);
		double y1=0.0;
		while(true){
			grad(grad_value,weight,data,h);
			double y2=0.0;
		
			for(int i=0;i<data.getRawNum();i++){
				y2 += (h[i]*h[i]);
			}
			y2 /=2;
			if(std::abs(y1-y2)<=this->error){
				break;
			}
			y1=y2;
		}	
}

std::vector<double> lgradient::solve(const mdata<double> &data){                                     
     std::vector<double> weight=std::vector<double>(data.getColNum()-1,0.0); 
     descent(weight,data);
     return weight;
}

