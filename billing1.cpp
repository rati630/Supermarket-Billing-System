#include<iostream>
#include<fstream>

using namespace std;

class shopping{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
		
		public:
			void menu();
			void administrator();
			void buyer();
			void add();
			void edit();
			void rem();
			void list();
			void receipt();
};

void shopping :: menu()
{
	m:
	int choice;
	string email;
	string password;
	cout<<"\t\t\t\t\t\t__________________________________________________________________\n";
	cout<<"\t\t\t\t\t\t                                                                  \n";
	cout<<"\t\t\t\t\t\t                    supermarket Main Menu                         \n";
	cout<<"\t\t\t\t\t\t                                                                  \n";
	cout<<"\t\t\t\t\t\t__________________________________________________________________\n";
	cout<<"\t\t\t\t\t\t                                                                  \n";
	cout<<"\t\t\t\t\t\t |   1)Administrator     |\n";
	cout<<"\t\t\t\t\t\t |                       |\n";
	cout<<"\t\t\t\t\t\t |   2)Buyer             |\n";
	cout<<"\t\t\t\t\t\t |                       |\n";
	cout<<"\t\t\t\t\t\t |   3)Exit              |\n";
	cout<<"\n\t\t\t   Please Select!";
	cin>>choice;
	switch(choice)
	{
		case 1:
			cout<<"\t\t\t\t  Please Login   \n";
			cout<<"\t\t\t\t  Enter Email     \n";
			cin>>email;
			cout<<"\t\t\t\t  Password       \n";
			cin>>password;
			
			if(email=="rati@gmail.com" && password=="rati@123")
			{
				administrator();
			}
			else{
				cout<<"Invalid email/password";
			}
			break;
	
	case 2:
		{
			buyer();
		}
		case 3:
			{
				exit(0);
			}
			default:
				{
					cout<<"Please select from the given options";
				}
}
goto m;
}

void shopping:: administrator()
{
	m:
	int choice;
	cout<<"\n\n\n\t\t\t   Administrator Menu";
	cout<<"\n\n\n\t\t\t______1)Add the Product______";
	cout<<"\n\n\n\t\t\t                             ";
	cout<<"\n\n\n\t\t\t______2)Modify the Product___";
	cout<<"\n\n\n\t\t\t                             ";
	cout<<"\n\n\n\t\t\t______3)Delete the Product___";
	cout<<"\n\n\n\t\t\t                             ";
	cout<<"\n\n\n\t\t\t______4)Back to Main Menu___ ";
	
	cout<<"\n\t\t Please enter Your Choice";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			add();
			break;
			
		case 2:
			edit();
			break;
			
		case 3:
			rem();
			break;
			
		case 4:
			menu();
			break;
			
		default:
		cout<<"Invalid Choice";	
				
	}
	goto m;
}

void shopping:: buyer()
{
	m:
	int choice;
	cout<<"\t\t\t\t\t  Buyer           \n";
	cout<<"____________________________\n";
	cout<<"\t\t\t\t\t 1) Buy Product   \n";
	cout<<"                            \n";
	cout<<"\t\t\t\t    2) Go back      \n";
	
	cout<<"\t\t\t Enter your choice:";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
			
		case 2:
			menu();
			break;
			
		default:
		cout<<"Invalid choice";	
	}
	
	goto m;
}

void shopping::add() 
{   
    m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	
	cout<<"\t\t\t\t Add New Product ";
	cout<<"\n\t\t Product Code";
	cin>>pcode;
	cout<<"\n\t\t  Name of the Product";
	cin>>pname;
	cout<<"\n\n\t Price of the Product";
	cin>>price;
	cout<<"\n\n\t Discount on the Product";
	cin>>dis;
	
	data.open("database.txt",ios::in);
	if(!data)
	{
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	else
	{
		data>>c>>n>>p>>d;
		while(!data.eof())
		{
			if(c==pcode)
			{
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	
	
	if(token==1)
	goto m;
	else{
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
		
	}
}
  cout<<"\n\n\t\t\t Record Inserted!";
}

void shopping::edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\t Modify the Product";
	cout<<"\n\n\t\t Product Code:";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n\t\t File doesn't exist!";
	}
	else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n\n\t\t\t Product New Code:";
				cin>>c;
				cout<<"\n\t\t Name of the Product:";
				cin>>n;
				cout<<"\n\t\t Price of the Product:";
				cin>>p;
				cout<<"\n\t\t Discount:";
				cin>>d;
				data1<<" "<<c<<" "<<d<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\t\t Record Edited!";
				token++;
				
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";			
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		if(token==0)
		{
			cout<<"\n\t\t Record Not Found sorry!";
		}
	}
}

void shopping::rem()
{
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\t\t Delete Product";
	cout<<"\n\t\t Product Code";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\t File doesn't Exist";
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n\t\t Product Deleted succesfully";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
	    	data>>pcode>>pname>>price>>dis;	
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\t\t Record Not Found";
		}
	}
}

void shopping:: list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n\t____________________________\n";
	cout<<"ProNo\t\tName\t\tPrice\n";
	cout<<"\n\n\t____________________________\n";
	data>>pcode>>pname>>price>>dis;	
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
	
}

void shopping::receipt()
{
	m:
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float amount=0;
	float dis=0;
	float total=0;
	
	cout<<"\n\n\t\t\t RECEIPT";
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\t\t Empty Database";
	}
	else
	{
		data.close();
		list();
		cout<<"\n__________________________________________\n";
		cout<<"\n                                          \n";
		cout<<"\n           Please Place the order         \n";
		cout<<"\n__________________________________________\n";
		cout<<"\n                                          \n";
		
		do{
			cout<<"\n\t\t Enter Product code:";
			cin>>arrc[c];
			cout<<"\n\t\t\t Enter the product Quantity";
			cin>>arrq[c];
			for(int i=0;i<c;i++)
			{
				if(arrc[c]==arrc[i])
				{
					cout<<"\n\n\t Duplicate Product code,Please try Again!";
					goto m;
				}
			}
			c++;
			cout<<"\n\n\t Do you want to buy another product?If yes then press y else no";
			cin>>choice;
		}
		while(choice=='y');
		cout<<"\n\t\t\t          RECEIPT         \n";
		cout<<"\nProduct no.\t Product Name \t Product Quantity \tPrice\tAmount\t Amount with discount\n";
		for(int i=0;i<c;i++)
		{
			data.open("database.txt",ios::in);
			data>>pcode>>pname>>price>>dis;
			while(!data.eof())
			{
				if(pcode==arrc[i])
				{
					amount=price*arrq[i];
					dis=amount-(amount*dis/100);
					total=total+dis;
					cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
				}
				data>>pcode>>pname>>price>>dis;
			}
		}
		data.close();
	
	}
	cout<<"\n\n_________________________________________________\n";
	cout<<"\n Total Amount: "<<total;
	
	
}

int main()
{
	shopping s;
	s.menu();
}















