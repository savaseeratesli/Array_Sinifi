#include <iostream>
#include "array.h"

using namespace std;

int main()
{
	Array mainArray(10);
	Array mainArray2(mainArray);

	cout << "Kapasite:" << mainArray.getCapacity() << endl;
	cout << "Size:" << mainArray.getSize() << endl;

	cout << "Kapasite2:" << mainArray2.getCapacity() << endl;
	cout << "Size2:" << mainArray2.getSize() << endl;

	mainArray.AddItem(19);
	mainArray.AddItem(4);
	mainArray.AddItem(35);
	mainArray.AddItem(35);
	mainArray.AddItem(10);
	mainArray.AddItem(5);
	mainArray.AddItem(19);
	mainArray.AddItem(24);
	mainArray.AddItem(1);
	mainArray.AddItem(19);
	mainArray.printItems();
	mainArray.AddItem(60);
	mainArray.AddItem(35);
	mainArray.printItems();

	Array mainArray3 = mainArray;
	mainArray3.printItems();

	mainArray3.AddItem(7);
	mainArray3.AddItem(9);
	mainArray3.printItems();

	mainArray3.removeIndexItem(2);
	mainArray3.printItems();

	mainArray3.removeItem(19);
	mainArray3.printItems();

	mainArray3.findElement(35,7);


	return 0;
   
}

