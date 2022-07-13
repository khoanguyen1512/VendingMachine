#include "header1.h"

void food::ghiFile(food *fd,int n, char fileName[]){
	FILE  *fp;
    fp = fopen (fileName,"w");
    for(int i = 1;i < n;i++){
        fprintf(fp, "%5d%30s%10d%10d\n",  fd[i].id, fd[i].Name, fd[i].price, fd[i].quantity);
    }
    fclose (fp);	
}
int food::docFile(food *fd,char fileName[]){
	FILE * fp;
    int i = 1;    
    fp = fopen (fileName, "r");
    while (fscanf(fp, "%5d%30s%10d%10d\n", &fd[i].id, &fd[i].Name, &fd[i].price, &fd[i].quantity) != EOF) 
	{
       i++;      
    }        
    
    return i;
    fclose (fp);
}
void food::showProduct(food *fd,int n) {
    
    cout <<"STT\tID\tName\t\tPrice\t\tQuantity\t";
    printLine(58);
    for(int i = 1; i < n; i++) {
        cout<<" "<< i ;
        cout<<"\t"<< fd[i].id;
        cout<<"\t"<< fd[i].Name;
        cout<<"\t\t"<< fd[i].price;
        cout<<"\t\t   "<< fd[i].quantity; 
		printLine(58);
    }   
}
int food::buy(food *fd, int n){
int money;
	int money_ctn = 0;
	nhap:
	system("cls");
	label();
    cout << "	          [2]. Mua san pham.";
    printLine(58);
	fd->showProduct(fd,n);
	cout << "Nhap so tien: "; cin >> money;
	money += money_ctn;
	if(money < 5000){
		cout<<"      So tien nhap phai chia het cho 5000d!"<<endl;
		sleep(2);
		goto nhap;
	}
	cout<<"So tai khoan: "<<money<<endl;
	nhapid:
		int found = 0;
		int dem = 0;
    cout<<" Nhap id: ";
    cin >>id; 
    for(int i = 0; i < n; i++) {
        if (id == fd[i].id ) {
            found = 1;
            dem = i;           
		}
	}
		if(found == 0)
		{
			cout<<" San pham co ID "<< id <<" khong ton tai vui long nhap lai."<< endl;
			sleep(2);
			goto nhapid;		
		}
				
        if(fd[dem].quantity == 0)
			{
				cout<<" San pham da het hang!"<<endl;
				cout<<"  Vui long chon lai!"<<endl;
				sleep(2);
				goto nhapid;
			}
			nhapsoluong:
				int soluong = 0;
            cout<<" Nhap so luong mua: ";
    		cin >> soluong;
        
		if(soluong > fd[dem].quantity)
            {
            	cout <<" So luong san pham khong du!"<<endl;
            	cout<<"  Vui long chon lai!"<<endl;
            	sleep(2);
            	goto nhapsoluong;
			}				
		int tienthoi;
		int j = 0;
		tienthoi = money - fd[dem].price * soluong;
		if(tienthoi < 0)
            {
            	tienthoi = money;
            	printLine(58);
            	cout<<"So tien ban nhap khong du de mua!"<<endl;
            	cout<<"Ban co muon nap them ?";
            	if(j != 1){
            		if(yesno()==true){
    						money_ctn = money;
    						goto nhap;
						}else{
							printLine(58);
							cout << "         Cam on ban da mua hang!";
							sleep(2);
							goto thoitien;
						}
				}
            	
			}
		fd[dem].quantity -= soluong ;
		printLine(58);
		cout<<"                Mua them san pham ?";		
    		if(yesno()==true){
    				system("cls");
    				fd->showProduct(fd,n);
    				j++;
    				money = tienthoi;
    				cout<<"San pham da mua truoc do: "<<fd[dem].Name<<endl;
    				cout<<"So tien con lai: "<<money;
    				printLine(58);
    				int flag = fd->minprice(fd,n);
    				if(money < fd[flag].price ){
    				cout<<"So tien ban nhap nho hon gia san pham re nhat!"<<endl;
    				cout<<"          Vui long nap them tien!";			
						if(yesno()==true){
    						money_ctn = money;
    						goto nhap;
						}else{
							printLine(58);
							cout << "         Cam on ban da mua hang!";
							sleep(2);
							goto thoitien;
						}
					}
    				goto nhapid;
    		}else{
    				pressAnyKey();
				}
		thoitien:	
		system("cls");
		label();
		fd->showProduct(fd,n);
		printLine(58);           
            cout << "             So tien thoi lai la: "<< tienthoi <<endl;
            cout << "             Cam on ban da mua hang!";
        printLine(58);      
	}
void food::nhapThongTinSP(food &fd, int id) {
    cout<<endl;
	cout << " Nhap ten: ";
	fflush(stdin); gets(fd.Name);
    cout << " Nhap gia: "; cin >> fd.price;
    cout << " Nhap soluong: "; cin >> fd.quantity;
    fd.id = id;
    
}
void food::nhapSP(food *fd, int n) {
    printLine(58);
    cout<<"              Nhap san pham thu: "<< n;
    nhapThongTinSP( fd[n], n);
    printLine(58);
}
void food::xoa(food *fd, int n) {
	int id;
	nhapid:
		label();
    cout << "	          [4]. Xoa san pham.";
    printLine(58);
	fd->showProduct(fd,n);
	cout << " Nhap ID can xoa: "; cin >> id;
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (fd[i].id == id) {
            found = 1;
            printLine(58);
            for (int j = i; j < n; j++) {
                int k=0;
				fd[j] = fd[j+1];
				fd[j].id --;
				
            }
            cout << "                       Da xoa SP!";
            printLine(58);
            sleep(2);
            break;
        }
    }
    if (found == 0) {
        cout<<" San pham co ID = "<<id<<" khong ton tai!"<<endl;
        sleep(2);
        system("cls");
        goto nhapid;
	}
}
void food::capnhatthongtinSP(food &fd) {		
    cout << "Vui long chon thong tin ban muon cap nhat!";
    printLine(40);
    cout << "****************************************"<<endl;
    cout << "**  [1]. Ten san pham.                **"<<endl;
    cout << "**  [2]. Gia san pham.                **"<<endl;
    cout << "**  [3]. So luong san pham.           **"<<endl;
    cout << "**  [4]. Tat ca                       **"<<endl;
	cout << "****************************************";
	printLine(40);
	int k;
	cout << "Nhap lua chon cua ban :";
	cin >> k;
	system("cls");	
	printLine(40);
	cout << " Ten san pham hien tai: "<< fd.Name<<endl;
    cout << " Gia hien tai: "<< fd.price<<endl;
    cout << " Ton kho: "<< fd.quantity;
    printLine(40);   
    switch(k)
    {
    	case 1:
    		cout << " Nhap ten moi: "; fflush(stdin); gets(fd.Name);
    			printLine(40);
				cout << "      Da cap nhat thanh cong! ";
    			printLine(40); 
    			sleep(2);
    		break;
    	case 2:
    		cout << " Nhap gia moi: "; cin >> fd.price;
    			printLine(40);
				cout << "      Da cap nhat thanh cong! ";
    			printLine(40); 
    			sleep(2);
    		break;
    	case 3:
    		cout << " Nhap soluong: "; cin >> fd.quantity;
    			printLine(40);
				cout << "      Da cap nhat thanh cong! ";
    			printLine(40); 
    			sleep(2);
    		break;
    	default:
    		cout << " Nhap ten moi: "; fflush(stdin); gets(fd.Name);
    		cout << " Nhap gia moi: "; cin >> fd.price;
    		cout << " Nhap soluong: "; cin >> fd.quantity;
    			printLine(40);
				cout << "      Da cap nhat thanh cong! ";
    			printLine(40); 
    			sleep(2);
			break;	
	} 
 
}
void food::capnhatSP(food *fd, int n) {
    int found = 0;
    int id = 0;
    nhapid:
    	label();
    	fd->showProduct(fd,n);
    cout<<"Nhap id can chinh sua: ";
    cin>>id;
    for(int i = 0; i < n; i++) {
        if (fd[i].id == id) {
            found = 1;
            system("cls");
            printLine(40);
            cout << "Cap nhat thong tin san pham co ID = " << id;
            printLine(40);
            capnhatthongtinSP(fd[i]);
            printLine(40);
            break;
        }
    }
    if(found == 0){
    	cout<<"id khong ton tai!"<<endl;
    	sleep(1);
    	system("cls");
    	goto nhapid;
	}
}
