#include "header1.h"

int Employee::docFile(Employee *emp,char fileName[]) {
    FILE * fp;
    int i = 1;    
    fp = fopen (fileName, "r");
    while (fscanf(fp, "%5d%30s%10d\n", &emp[i].id, &emp[i].Name, &emp[i].Pass) != EOF) 
	{
       i++;      
    } 
	   
    return i;
    fclose (fp);
}
int Employee::login_emp(Employee *emp, int n){
	int a = 2;
	login_:
	int pass;
	printLine(58);	
	cout <<"              Nhap pass de dang nhap: "; cin >> pass;
	for(int i = 1 ; i<n ; i++)
	{
		if(pass == emp[i].Pass)
			{
				printLine(58);
			cout<<"                 Dang nhap thanh cong!"<<endl;
			cout<<"           Chao mung den voi Vending machine";
			printLine(58);
				sleep(2);	
				system("cls");	
				return i;
			}	
	}
		printLine(58);
		cout<<"                        Pass sai"<<endl;	
		cout<<"                   Ban con "<<a<<" luot nhap";	
		printLine(58);
		sleep(2);
				
		a--;
		if(a == -1){
			printLine(58);
			cout<<"               Ban da het luot dang nhap!"<<endl;
			cout<<"                 Chuong trinh se thoat!";
			printLine(58);
			sleep(2);
			system("cls");
			return -2;
		}
		system("cls");
		label();
		label1();
		goto login_;			

}
void Employee::printinfo(Employee *emp,int n){
	cout << "	   [2]. Hien thi thong tin nhan vien.";
	printLine(58);
	cout<<"                Ten nhan vien: "<<emp[n].getName()<<endl;
	cout<<"                     Password: "<<emp[n].getPass();	
}
string Employee::getName(void)	{
		return this->Name;
	}
int Employee::getPass(void)	{
		return this->Pass;
	}
int Employee::getid(void)	{
		return this->id;
	}



