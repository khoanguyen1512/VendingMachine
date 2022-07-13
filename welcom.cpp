#include "header.h"

void printLine(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "=";
    }
    cout << endl;
}
void pressAnyKey() {
    cout << "            Bam phim bat ky de tiep tuc...";
    getch();
    system("cls");
}
void welcom(){
	system("color 0E");	
	
	cout << "  =============================================    "<<endl;sleep(1);
	cout << "  *********************************************    "<<endl;sleep(1);
	cout << "                   WELCOME TO                      "<<endl;sleep(1);
	cout << "                VENDING MACHINE                    "<<endl;sleep(1);	
	cout << "  *********************************************    "<<endl;sleep(1);
	cout << "  =============================================    "<<endl;					
	sleep(1);
	system("cls");
	for (int i = 0 ;i<3 ;i++)
	{
		
	cout << "  =============================================    "<<endl;
	cout << "   Dang khoi dong vui long cho trong giay lat!     "<<endl;
	cout << "  =============================================    "<<endl;
	system("color 0E");					
	cout << "    *****************************************    "<<endl;	
	cout << "  *********************************************  "<<endl;
	cout << "***********  ***********************  ***********"<<endl;
	cout << "*********  **  *******************  **  *********"<<endl;
	cout << "*******  ******  ***************  ******  *******"<<endl;
	cout << "*************************************************"<<endl;
	cout << "*************************************************"<<endl;
	cout << "***************  ***************  ***************"<<endl;
	cout << "*****************  ***********  *****************"<<endl;
	cout << "*******************           *******************"<<endl;
	cout << "  *********************************************  "<<endl;
	cout << "    *****************************************    "<<endl;
	sleep (1);		
	system("cls");				
	}	
	cout << "  =============================================    "<<endl;
	cout << "                 Khoi dong xong!                   "<<endl;
	cout << "  =============================================    "<<endl;
	sleep (2);
	system("cls");
}
void bye(){
	system("color 0E");	
	
	cout << "  =============================================    "<<endl;sleep(1);
	cout << "  *********************************************    "<<endl;sleep(1);
	cout << "                   GOOD BYE                        "<<endl;sleep(1);
	cout << "                 SEE YOU AGAIN                     "<<endl;sleep(1);
	cout << "  *********************************************    "<<endl;sleep(1);
	cout << "  =============================================    "<<endl;					
	sleep(1);
	system("cls");
}
int login(Employee *emp,Product *pd,int n){
	system("color 0C");
	int idnv = 0;
	dangnhap:
    label();
	int k;	
	label1();
	cout << "            Vui long nhap tuy chon cua ban: ";cin >> k;
		switch(k)
	{
		case 1:
            printLine(58);
			cout<<"                 Dang nhap thanh cong!"<<endl;
			cout<<"           Chao mung den voi Vending machine";
			printLine(58);
			sleep (2);		
			system("cls");
			return -1;
			break;
		case 2:
			idnv = emp->login_emp(emp,n);
			return idnv;		
			break;
		case 0:
			system("cls");
			bye();
			return 0;
			break;	
		default:
			printLine(58);
				cout<<"                Lua chon khong hop le!";
			printLine(58);
			sleep (2);
			system("cls");
			goto dangnhap;
			break;
	}
}
void menu1(){
		label();
	    cout << "**********************************************************"<<endl;
        cout << "**     [1]. MENU san pham                               **"<<endl;
        cout << "**     [2]. Mua nuoc                                    **"<<endl;
        cout << "**     [3]. Mua do an                                   **"<<endl;
        cout << "**     [4]. Quay lai                                    **"<<endl;
        cout << "**     [0]. Thoat                                       **"<<endl;
		cout << "**********************************************************";
		printLine(58);	
}
void menu2(){
	label();
		cout << "**********************************************************"<<endl;
		cout << "**     [1]. MENU san pham                               **"<<endl;
		cout << "**     [2]. Thong tin nhan vien                         **"<<endl;
		cout << "**     [3]. Them san pham                               **"<<endl;
		cout << "**     [4]. Xoa san pham                                **"<<endl;
		cout << "**     [5]. Quan ly kho                                 **"<<endl;
    	cout << "**     [6]. Quay lai                                    **"<<endl;
    	cout << "**     [0]. Thoat                                       **"<<endl;
    	cout << "**********************************************************";
    	printLine(58);
}
void label(){
	printLine(58);
	cout << "         	    VENDING MACHINE  ";
	printLine(58);
}
void label1(){
	cout << "******              [1].Khach hang                  ******"<<endl;
	cout << "******              [2].Nhan vien                   ******"<<endl;
	cout << "******              [0].Thoat                       ******";
	printLine(58);
}
void label2(){
		label();
	    cout << "**          [1]. Danh sach do nuoc                      **"<<endl;
        cout << "**          [2]. Danh sach do an                        **"<<endl;
        cout << "**          [0]. Quay lai                               **";
        printLine(58);
}
bool yesno(){
	printLine(58);
	cout << "**                  [1]. Yes                        **"<<endl;
    cout << "**                  [2]. No                         **";
    printLine(58);        
    int d;
    cout<<" Nhap lua chon: ";
    cin >>d;
    if(d == 1)
    	return true;
    else
    	return false;
}
