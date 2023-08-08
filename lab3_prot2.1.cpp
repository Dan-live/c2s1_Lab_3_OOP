#include <iostream>
#include "Vector.h"

int main()
{
	Vector<int, 7> c(8.1);
	c.Print();
	
	Vector<float, 7> b(9.1);
	Vector<float, 7> d(10.1);
	b.Print();
	////b[0] = 5.8;
	//b[-2] = 0.02;
	//b.Print();

	//Vector<float, 7> fsum(0);
	////fsum = b + c;
	//// fsum = b + c; //error
	//fsum.Print();

	//Vector<float, 7> isum = c + 4;
	//isum.Print();


	//
	//b.resize<6>().Print();
	//b.convert<int>().Print();

	cout << "-----------------------------" << endl;
	//c[0] = 1;
	//c[1] = 2;
	//c[2] = 3;
	//c[3] = 4;
	//c[4] = 5;
	//c[5] = 6;
	//c[6] = 7;
	//c[7] = 8;
	c.Print();


	c.slice<-2, 2>().Print();

	c.weighted_sum(c, 0.7, b, 3.2).Print();

	
	c.concat(c, d).Print();
	return 0;
}

