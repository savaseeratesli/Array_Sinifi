#include <iostream>

using namespace std;

class Array
{
	int* data, size, capacity;
	int findIndex(int number, int b = 0);

public:
	Array(int user_capacity = 5);
	~Array();
	Array(const Array& copyArray);

	int getSize() const//inputtan ba��ms�z conts
	{
		return size;
	}
	int getCapacity() const
	{
		return capacity;
	}
	void AddItem(int number);
	void printItems();
	void removeIndexItem(int index);//Belirli indexteki de�eri sil
	void removeItem(int number);//G�nderilen elemande�erine g�re sil
	void findElement(int number, int b = 0);
};

Array::Array(int user_capacity)
{
	capacity = user_capacity;//Kullan�c� g�ndermezse 5
	size = 0;
	data = new int[capacity];

	cout << "Array Kapasitesi Belirlendi ->" << capacity << endl;
}

Array::~Array()
{
	//Structerda yer ay�rd�k destructerda sildik
	delete[] data;

	cout << "Array Silindi" << endl;
}

Array::Array(const Array& copyArray)
{
	capacity = copyArray.capacity;
	size = copyArray.size;
	data = new int[capacity];

	//Elemanlar� kopyalama
	for (int i = 0; i < copyArray.size; i++)
	{
		data[i] = copyArray.data[i];
	}

	cout << "Array Kopyalandi" << endl;

}


void Array::AddItem(int number)
{
	if (size == capacity)
	{
		int* temp_data = new int[capacity * 2];//Ayr�lan yeride 2 kat�na ��kar,ekli verileri ge�ici arrayde ekle
		//�nemliiiiii
		for (int i = 0; i < size; i++)
		{
			temp_data[i] = data[i];
		}
		delete[] data;
		data = temp_data;//data pointer adrestutar

		capacity *= 2;//2 kat�na ��kard�k kapasiteyi

	}

	data[size] = number;//Say�y� dizimize ekledik
	size++;

}

void Array::printItems()
{
	if (size != 0)//Eleman say�
	{
		for (int i = 0; i < size; i++)
		{
			cout << data[i] << "-";
		}
	}
	cout << "\n" << "Kapasite: " << capacity << "\n" << "Size: " << size << endl;
}

void Array::removeIndexItem(int index)
{
	if (index < 0 || index >= size)
	{
		cout << "Hata Eleman Yok!" << endl;
		return;
	}

	int removeItem = data[index];
	// 5 4 5 3 2
	// 5 5 3 2
	for (int i = index; i < size; i++)
	{
		data[i] = data[i + 1];
	}
	size--;
	
	cout << "Item" << removeItem << "Silindi" << endl;

}


void Array::removeItem(int number)
{
	// 7 8 9 6 7 0 4
	// 8 9 6 7 0 4
	// 8 9 6 0 4
	//Silincek eleman� bul
	int counter = 0;//ka� eleman sildik

	for (int i = 0; i <= size; i++)//elemanlar� arad�k
	{
		if (data[i] == number)
		{
			for (int j = i; j < size; j++)
			{
				data[j] = data[j + 1];
			}
			counter++;
			i--;//Kayan de�eride kontrol etmesi i�in 5 5 13 4 3 5in birini atlamamas� i�in
		}
	}
	cout << counter << "items(" << number << ")" << "Silindi" << endl;
	size -= counter;


}

int Array::findIndex(int number, int index)//Private fonk
{
	for (int i = index; i < size; i++)
	{
		if (data[i] == number)//number kullan�c� g�nderdi
		{
			return i;
		}
	}
	return -1;//Arrayde yok
}

void Array::findElement(int number, int index)
{
	int result = findIndex(number, index);

	if (result != -1)
	{
		cout << number << " indexte bulundu" << result << endl;
	}
	else
	{
		cout << number << "Bulunamadi" << endl;
	}
}















