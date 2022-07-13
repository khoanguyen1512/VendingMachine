#include "header1.h"

void Product::ghiFile(Product *pd,int n, char fileName[]){
    FILE  *fp;
    fp = fopen (fileName,"w");
    for(int i = 1;i < n;i++){
        fprintf(fp, "%5d%30s%10d%10d\n",  pd[i].id, pd[i].Name, pd[i].price, pd[i].quantity);
    }
    fclose (fp);
}
int Product::docFile(Product *pd,char fileName[]) {
    FILE * fp;
    int i = 1;    
    fp = fopen (fileName, "r");
    while (fscanf(fp, "%5d%30s%10d%10d\n", &pd[i].id, &pd[i].Name, &pd[i].price, &pd[i].quantity) != EOF) 
	{
       i++;      
    }           
    return i;
    fclose (fp);
}
void Product::showProduct(Product *pd,int n) {
    
    cout <<"STT\tID\tName\t\tPrice\t\tQuantity\t";
    printLine(58);
    for(int i = 1; i < n; i++) {
        cout<<" "<< i ;
        cout<<"\t"<< pd[i].id;
        cout<<"\t"<< pd[i].Name;
        cout<<"\t\t"<< pd[i].price;
        cout<<"\t\t   "<< pd[i].quantity; 
		printLine(58);
    }
    
}
int Product::minprice(Product *pd, int n){
	int min = 1;	
	for(int i = 1;i < n;++i)
	{       	
    	if(pd[min].price > pd[i].price)
            {
            	min = i;
			}				
	}
			return min;
}
int Product::buy(Product *pd, int n){
	int money;
	int money_ctn = 0;
	nhap:
	system("cls");
	label();
    cout << "	          [2]. Mua san pham.";
    printLine(58);
	pd->showProduct(pd,n);
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
        if (id == pd[i].id ) {
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
				
        if(pd[dem].quantity == 0)
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
        
		if(soluong > pd[dem].quantity)
            {
            	cout <<" So luong san pham khong du!"<<endl;
            	cout<<"  Vui long chon lai!"<<endl;
            	sleep(2);
            	goto nhapsoluong;
			}				
		int tienthoi;
		int j = 0;
		tienthoi = money - pd[dem].price * soluong;
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
		pd[dem].quantity -= soluong ;
		printLine(58);
		cout<<"                Mua them san pham ?";		
    		if(yesno()==true){
    				system("cls");
    				pd->showProduct(pd,n);
    				j++;
    				money = tienthoi;
    				cout<<"San pham da mua truoc do: "<<pd[dem].Name<<endl;
    				cout<<"So tien con lai: "<<money;
    				printLine(58);
    				int flag = pd->minprice(pd,n);
    				if(money < pd[flag].price ){
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
		pd->showProduct(pd,n);
		printLine(58);           
            cout << "             So tien thoi lai la: "<< tienthoi <<endl;
            cout << "             Cam on ban da mua hang!";
        printLine(58);      
	}		
void Product::nhapThongTinSP(Product &pd, int id) {
    cout<<endl;
	cout << " Nhap ten: ";
	fflush(stdin); gets(pd.Name);
    cout << " Nhap gia: "; cin >> pd.price;
    cout << " Nhap soluong: "; cin >> pd.quantity;
    pd.id = id;
    
}
void Product::nhapSP(Product *pd, int n) {
    printLine(58);
    cout<<"              Nhap san pham thu: "<< n;
    nhapThongTinSP( pd[n], n);
    printLine(58);
}
void Product::xoa(Product *pd, int n) {
	int id;
	nhapid:
		label();
    cout << "	          [4]. Xoa san pham.";
    printLine(58);
	pd->showProduct(pd,n);
	cout << " Nhap ID can xoa: "; cin >> id;
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (pd[i].id == id) {
            found = 1;
            printLine(58);
            for (int j = i; j < n; j++) {
                int k=0;
				pd[j] = pd[j+1];
				pd[j].id --;
				
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
void Product::capnhatthongtinSP(Product &pd) {		
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
	cout << " Ten san pham hien tai: "<< pd.Name<<endl;
    cout << " Gia hien tai: "<< pd.price<<endl;
    cout << " Ton kho: "<< pd.quantity;
    printLine(40);   
    switch(k)
    {
    	case 1:
    		cout << " Nhap ten moi: "; fflush(stdin); gets(pd.Name);
    			printLine(40);
				cout << "      Da cap nhat thanh cong! ";
    			printLine(40); 
    			sleep(2);
    		break;
    	case 2:
    		cout << " Nhap gia moi: "; cin >> pd.price;
    			printLine(40);
				cout << "      Da cap nhat thanh cong! ";
    			printLine(40); 
    			sleep(2);
    		break;
    	case 3:
    		cout << " Nhap soluong: "; cin >> pd.quantity;
    			printLine(40);
				cout << "      Da cap nhat thanh cong! ";
    			printLine(40); 
    			sleep(2);
    		break;
    	default:
    		cout << " Nhap ten moi: "; fflush(stdin); gets(pd.Name);
    		cout << " Nhap gia moi: "; cin >> pd.price;
    		cout << " Nhap soluong: "; cin >> pd.quantity;
    			printLine(40);
				cout << "      Da cap nhat thanh cong! ";
    			printLine(40); 
    			sleep(2);
			break;	
	} 
 
}
void Product::capnhatSP(Product *pd, int n) {
    int found = 0;
    int id = 0;
    nhapid:
    	label();
    	pd->showProduct(pd,n);
    cout<<"Nhap id can chinh sua: ";
    cin>>id;
    for(int i = 0; i < n; i++) {
        if (pd[i].id == id) {
            found = 1;
            system("cls");
            printLine(40);
            cout << "Cap nhat thong tin san pham co ID = " << id;
            printLine(40);
            capnhatthongtinSP(pd[i]);
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
