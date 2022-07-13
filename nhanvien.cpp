#include "nhanvien.h"

int Employee::docFile(Employee *emp,char fileName[]) 
{
    FILE * fp;
    int i = 0;    
    fp = fopen (fileName, "r");
    while (fscanf(fp, "%5d%30s%10d\n", &emp[i].id, &emp[i].Name, &emp[i].Pass) != EOF) 
	{
       i++;      
    }    
    cout << endl;    
    return i;
    fclose (fp);
}
int Employee::login(Employee *emp, int n)
{
	int a = 0;
	login:
	int pass;	
	cout <<"Nhap pass: ";
	cin >> pass;
	for(int i = 0 ; i<n ; i++)
	{
		if(pass == emp[i].Pass)
			{
				cout<<"\nDang nhap thanh cong!"<<endl;
				cout<<"Chao mung den voi Vending machine"<<endl;		
				return 0;
			}	
		else
			{
				cout<<"Pass sai"<<endl;	
				a++;
				if(a = 3)
				system("pause");
				goto login;			
			}
	}
}


