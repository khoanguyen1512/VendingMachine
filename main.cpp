#include "header1.h"

int main(void){
	Product pd[20];
	Employee emp[10];
	food fd[20];	
	char fileName[] = "product.txt";
	char fileName1[] = "employee.txt";
	char fileName2[] = "food.txt";
	
    	int inventory,inventory2 = 0; 
	int nhanvien = 0;
	int lgn = 0;  
	nhanvien = emp->docFile(emp, fileName1);  
   	inventory = pd->docFile(pd, fileName);
    	inventory2 = fd->docFile(fd,fileName2);
	welcom:
	welcom();        //phan welcom
	int key = 0; 
	login:  	
	lgn = login(emp,pd,nhanvien);    
	if(lgn == -1)
	{
		system("cls");	
		while(1){
		system("color 0B");
		menu1:
		menu1();
		cout<<"Nhap lua chon: ";
		cin>>key;
		switch(key)
		{
			case 1:                         //menu
				system("cls");
				if(inventory > 0){
					chon:
                	label2();
                	int h = 0;
                	cout <<"Chon danh sach ban muon xem :";
                    cin>>h;
                    system("cls");
                    switch(h){
                    	case 1:
                    		label();
	                    	cout << "	   [1]. Hien thi danh sach san pham nuoc.";
	                    	printLine(58);                   
	                    	pd->showProduct(pd,inventory);
	                    	pressAnyKey();
	                    	goto chon;
							break;
						case 2:
							label();
	                    	cout << "	   [1]. Hien thi danh sach san pham do an.";
	                    	printLine(58);                   
	                    	fd->showProduct(fd,inventory2);
	                    	pressAnyKey();
	                    	goto chon;
							break;
						case 0:
							goto menu1;
							break;
						default:
							printLine(58);
							cout<<"                Lua chon khong hop le!";
							printLine(58);
							pressAnyKey();
							goto chon;
							break;	
					}                   
                    break;                   
                }else{
                	label();
                    cout << "     Danh sach san pham trong!";
                }
                system("cls");
				break;
			case 2:                            // Mua hang
				system("cls");
                	if(inventory > 0) {                	
                    pd->buy(pd,inventory);             
                    pd->ghiFile(pd,inventory,fileName);  
                    pressAnyKey();
				}
			break;
			case 3:
				system("cls");
                	if(inventory2 > 0) {               		
                	fd->buy(fd,inventory2);
                	fd->ghiFile(fd,inventory2,fileName2);
                	pressAnyKey();
            		}
            	break;
			case 4:
				system("cls");			
				goto login;
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
				pressAnyKey();
				break;
		}
}
	}else if(lgn == -2){
		goto welcom;
	}else if(lgn == 0){
		return 0;	
	}else{
		while(1){
		system("cls");
		system("color 0F");
		menu2:
		menu2();
		cout<<"Nhap lua chon: ";
		cin>>key;
		switch(key)
		{
			case 1:                    
				system("cls");
				if(inventory > 0){
					chon1:
                	label2();
                	int h = 0;
                	cout <<"Chon danh sach ban muon xem :";
                    cin>>h;
                    system("cls");
                    switch(h){
                    	case 1:
                    		label();
	                    	cout << "	   [1]. Hien thi danh sach san pham nuoc.";
	                    	printLine(58);                   
	                    	pd->showProduct(pd,inventory);
	                    	pressAnyKey();
	                    	goto chon1;
						break;
					case 2:
						label();
		                   	cout << "	   [1]. Hien thi danh sach san pham do an.";
		                   	printLine(58);                   
		                   	fd->showProduct(fd,inventory2);
		                   	pressAnyKey();
		                   	goto chon1;
						break;
					case 0:
						break;
					default:
						printLine(58);
						cout<<"                Lua chon khong hop le!";
						printLine(58);
						pressAnyKey();
						goto chon2;
						break;	
					}                   
                    break;                   
                }else{
                	label();
                    cout << "     Danh sach san pham trong!";
                }
                system("cls");
				break;
			case 2:
				system("cls");
				if(inventory > 0){
					label();
	                emp->printinfo(emp,lgn);
	                printLine(58);
	                pressAnyKey();
            	}else{
            		label();
                    cout << "		Danh sach san pham trong!";
				}
				break;
			case 3:
				chon2:
				system("cls");
				if(inventory > 0) {			
                	label2();
                	int h = 0;
                	cout <<"Chon danh sach ban muon nhap :";
                    cin>>h;
                    system("cls");
                    switch(h){
					case 1:	
						label();
						pd->showProduct(pd,inventory);
		                	pd->nhapSP(pd,inventory);
		                	inventory++;
						pd->ghiFile(pd,inventory,fileName);
						goto chon2;
						break;
					case 2:
						label();
						fd->showProduct(fd,inventory2);
		                	fd->nhapSP(fd,inventory2);
		          		inventory2++;
						fd->ghiFile(fd,inventory2,fileName2);
						goto chon2;
						break;
					case 0:
						break;
					default:
						printLine(58);
						cout<<"                Lua chon khong hop le!";
						printLine(58);
						pressAnyKey();
						goto chon2;
						break;
					}
				}else{
            		label();
                    cout << "		Danh sach san pham trong!";
				}				
				break;
			case 4:
				chon3:
				system("cls");
				if(inventory > 0) {		
                	label2();
                	int h = 0;
                	cout <<"Chon danh sach ban muon nhap :";
                    cin>>h;
                    system("cls");
                    switch(h){
                    	case 1:
                			pd->xoa(pd,inventory);
                			inventory--;
                			goto chon3;
                			break;
                		case 2:
                			fd->xoa(fd,inventory2);
                			inventory2--;
                			goto chon3;
                			break;
                		case 0:
						break;
					default:
						printLine(58);
						cout<<"                Lua chon khong hop le!";
						printLine(58);
						pressAnyKey();
						goto chon3;
						break;
				}
				}else{
            		label();
                    cout << "		Danh sach san pham trong!";
				}							
				break;
			case 5:
				chon4:
				system("cls");
				if(inventory > 0) {
                	label2();
                	int h = 0;
                	cout <<"Chon danh sach ban muon nhap :";
                    cin>>h;
                    system("cls");
                    switch(h){
                    	case 1:
                			pd->capnhatSP(pd,inventory);
                			goto chon4;
                			break;
                		case 2:
                			fd->capnhatSP(fd,inventory2);
                			goto chon4;
                			break;
                		case 0:
						break;
					default:
						printLine(58);
						cout<<"                Lua chon khong hop le!";
						printLine(58);
						pressAnyKey();
						goto chon3;
						break;
				}
				}else{
            		label();
                    cout << "		Danh sach san pham trong!";
				}							
				break;
			case 6:
				system("cls");
				pd->ghiFile(pd,inventory,fileName);
				fd->ghiFile(fd,inventory2,fileName2);				
				goto login;
				break;
			case 0:
				system("cls");
				pd->ghiFile(pd,inventory,fileName);
				fd->ghiFile(fd,inventory2,fileName2);	
				bye();
				return 0;
				break;
			default:
				printLine(58);
				cout<<"                Lua chon khong hop le!";
				printLine(58);
				pressAnyKey();
				break;							
		}	
	}}	
	
	return 0;
}
