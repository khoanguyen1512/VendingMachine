#ifndef __HEADER_H__
#define __HEADER_H__
#include <iostream>
#include <unistd.h>		//sleep
#include <conio.h>		//getch

using namespace std;
class Employee;
class Product {
	public:
		char Name[20];
		int id, price, quantity;
		
		void showProduct(Product *pd, int n);
		void capnhatthongtinSP(Product &pd);
		void capnhatSP(Product *pd, int n);
		void nhapThongTinSP(Product &pd, int id);
		void nhapSP(Product *pd, int n); 		
		void ghiFile(Product *pd,int n, char fileName[]);
		int docFile(Product *pd,char fileName[]);
		int buy(Product *pd, int n);
		int minprice(Product *pd, int n);
		void xoa(Product *pd, int n);
		friend int login(Employee *emp,Product *pd,int n);	
};
class food : public Product{
	public:
		void ghiFile(food *fd,int n, char fileName[]);
		int docFile(food *fd,char fileName[]);
		void showProduct(food *fd, int n);
		int buy(food *fd, int n);
		void nhapThongTinSP(food &fd, int id);
		void nhapSP(food *fd, int n);
		void xoa(food *fd, int n);
		void capnhatthongtinSP(food &fd);
		void capnhatSP(food *fd, int n);
};
class Employee{
	private:
		char Name[10];
		int Pass;
		int id;
	public:
		string getName(void);
		int getPass(void);
		int getid(void);
		int docFile(Employee *,char fileName[]);
		int login_emp(Employee *emp, int n);
		void printinfo(Employee *emp,int n);
		friend int login(Employee *emp,Product *pd,int n);	
};
void pressAnyKey();
void welcom();
void bye();
void printLine(int n);	
void menu1();
void menu2();
void label();
void label1();
void label2();
bool yesno();
#endif
