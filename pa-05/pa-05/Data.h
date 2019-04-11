class Data {

public:

	// CTORS:
	// Data();
	Data(int customerNumber, int serviceTime, int totalTime);

	Data(Data &src);

	// Getters:
	int getCustomerNumber(void);
	int getServiceTime(void);
	int getTotalTime(void);


	// Setters
	void setCustomerNumber(int newCustomerNumber);
	void setServiceTime(int newServiceTime);
	void setTotalTime(int newTotalTime);


private:
	int customerNumber; 
	int serviceTime;   
	int totalTime;     
}; 