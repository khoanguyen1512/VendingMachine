#include <iostream>
#include<windows.h>
#include <unistd.h>
#include <String>
using namespace std;

class Product {
	private:
		string Name[20];
		int id, price, quantity;
	public:
		void Welcom();
		int docFile(Product *pd,char fileName[]);
		void ghiFile(Product *pd,int n, char fileName[]);
		void showProduct(Product *pd, int n);
		
};
