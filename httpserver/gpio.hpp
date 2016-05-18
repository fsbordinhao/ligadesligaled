#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>

class Gpio{
	int portNumber;

	public:
	Gpio(int port){
		portNumber = port;
		GPIOexport();
	}

	~Gpio(){
		GPIOunexport();
	}
	
	int getStatus(){
		int status=0;
		std::stringstream ss;
		ss << "/sys/class/gpio/gpio" << portNumber << "/value"; 

		std::fstream fileStatus;
		fileStatus.open(ss.str().c_str(), std::fstream::in);
		if(fileStatus.is_open()){
			fileStatus >> status;		
		}
		fileStatus.close();
		return status;
	}

	void setStatus(int status){
	
		std::stringstream ss;
		ss << "/sys/class/gpio/gpio" << portNumber << "/value"; 

		std::fstream fileStatus;
		fileStatus.open(ss.str().c_str(), std::fstream::out);
		if(fileStatus.is_open()){
			fileStatus << status ;		
		}
		fileStatus.close();
	}
	
	void setMode(const std::string &mode){

		std::stringstream ss;
		ss << "/sys/class/gpio/gpio" << portNumber << "/direction";	
		std::fstream fileDirection;
		fileDirection.open(ss.str().c_str(), std::fstream::out);
		if(fileDirection.is_open()){
			fileDirection << mode;
		}
		fileDirection.close();
	}

	private:
	void GPIOunexport() {
		std::fstream fileUnexport;
		fileUnexport.open("/sys/class/gpio/unexport", std::fstream::out);
		if(fileUnexport.is_open()){
			fileUnexport << portNumber;		
		}
		fileUnexport.close();
	}

	void GPIOexport() {
		std::fstream fileExport;
		fileExport.open("/sys/class/gpio/export", std::fstream::out);
		if(fileExport.is_open()){
			fileExport << portNumber;
		}
		fileExport.close();
	}

};

/*int main(){
	Gpio gpio(25);
	gpio.setMode(std::string("out"));
	gpio.setStatus(1);
	std::cin.get();
	gpio.setStatus(0);
	return 0;
}*/
