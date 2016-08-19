int main()
{
	struct timeval t1,t2;
	double elapsedTime;

	BlackGPIO speedSensor(GPIO_48,input);
	speedSensor.setValue(high);
	int newValue;
	int i;

	gettimeofday(&t1,NULL);

	for(i=0; i<100000; i++){

	 newValue = speedSensor.getNumericValue();

	}
	//sleep(2);
	gettimeofday(&t2,NULL);

		elapsedTime=((t2.tv_sec-t1.tv_sec)*1000000.0)/100000;

		cout << "time interval:" << elapsedTime << endl;
}






