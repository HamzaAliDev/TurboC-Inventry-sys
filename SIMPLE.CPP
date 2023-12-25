#include <iostream.h>
#include <conio.h>
#include <string.h>

void esteric(int r);

//global variable use in display product.
long inc = 01;
int addrow = 8;

class Product {
	private:
		char name[50];
	int id ;
	double price ;
	int quantity ;
    public:
		Product() {
  //	name[0] = " ";
			 id = 0;
			price = 0.0;
			quantity = 0;
		}

		Product(char N[50],int I,double P,int Q){
		     strcpy(name,N);
			id = I;
			price = P;
			quantity = Q;
		}

		void displayProduct(){
		
		//		values shows.
			gotoxy(2,addrow);
			cout<<id;
			gotoxy(12,addrow);
			cout<<"000"<<inc;
			gotoxy(28,addrow);
			cout<<name;
			gotoxy(52,addrow);
			cout<<price;
			gotoxy(68,addrow);
			cout<<quantity<<endl;
		
			inc++;
			addrow++;
		}	
};
class Inventory {
	private:
		int maxProducts ;
		int productCount ;
		Product products[100];
	public:
		Inventory(){
		 maxProducts = 100;
		 productCount = 0;
		}
		void addProduct(char name[50],double price,int quantity){
				if (productCount < maxProducts) {
            			products[productCount++] = Product(name, productCount , price, quantity);
            			//  gotoxy(2,50);
            			cout << "Product added successfully." << endl;

				clrscr();
        		}
				else {
            		cout << "Error: Maximum products reached." << endl;
        		}
    	}
    	
    	void displayInventory() {
        	if (productCount == 0) {
        		gotoxy(26,20);
            	cout << "Inventory is empty." << endl;
        	} 
		else {
			//  styling row.
			esteric(3);
				
			gotoxy(31,5);
            		cout << "Current Inventory" << endl;
            	
				//     	headings.
					gotoxy(2,7);
					cout<<"No.";
            				gotoxy(12,7);
					cout<<"product ID";
					gotoxy(28,7);
					cout<<"Name";
					gotoxy(52,7);
					cout<<"Price";
					gotoxy(68,7);
					cout<<"Quantity";
            	
			for (int i = 0; i < productCount; ++i) {
                		products[i].displayProduct();
            		}
			
        	}
    	}
		
};

// function initialize.

void styling (int);
void mainBorder();
void innerBox();


int main (){
	
	Inventory inventory;
	int choice;
	 
	while(2<3){
		clrscr();
		mainBorder();
	// border inner working.
	   
		gotoxy(35,7);
		cout<<"WELLCOME"<<endl;
		gotoxy(20,10);
		cout<<"=> Enter 1 for Add Product."<<endl;
		gotoxy(20,12);
		cout<<"=> Enter 2 for Display Inventry."<<endl;
		gotoxy(20,14);
		cout<<"=> Enter 3 for Quit.";
		innerBox();          //  inner box style.
		gotoxy(22,16);
		cin>>choice;
	
		switch (choice){
			case 1:
				{
					//  styling row.
						esteric(24);
					// add product.
			 		char name1[50];
            				double price;
                			int quantity;
                
					gotoxy(30,25);
					cout<< " Add New Product"<<endl;
				//	gotoxy(5,45);
        	        		cout << "Enter product name: ";
					cin >> name1;
				//	gotoxy(5,46);
					cout << "Enter product price: $";
            	    			cin >> price;
        	        	//	gotoxy(5,47);
    	            			cout << "Enter product quantity: ";
        	        		cin >> quantity;
					//add product in array.
					inventory.addProduct(name1, price, quantity);
					
					
				}
				break;
			case 2:
				{
					//function calling.
					clrscr();
					inventory.displayInventory();
					cout << "Do you want to add more products? (y/n): ";
               				char response;
           				cin >> response;
           				if (response == 'y' || response == 'Y') {
                			    	continue;       // Restart the loop
            				} 
					else {
               				     cout << "Exiting program. GOODBYE!" << endl;
               				     return 0;
					}
				}
				break;
			case 3:
				gotoxy(26,20);
				cout<<"Exiting program.  GOODBYE!";
				break;
			default:
				gotoxy(24,20);
				cout<<"Invalid Choice.Please try again.";
		}

	}
	return 0;
}

// function for ASCII code.

void styling (int sym)
{
	char symbol = sym;
	cout<<symbol;
}

void innerBox()
{
	gotoxy(20,16);
	styling(179);        //  left side |
	gotoxy(20,15);      
	styling(218);        //  upper left corner.
	gotoxy(20,17);
	styling(192);        //  lower left corner.
	gotoxy(59, 16);
	styling(179);        //    right side |.
	gotoxy(59,15);
	styling(191);        //    upper right corner.	
	gotoxy(59,17);
	styling(217);       //   lower right corner.
	for(int e=21; e<=58; e++)
	{
		int row = 15;
		gotoxy(e,row);
		styling(196);     //   upper row.
	}
	for(int f=21; f<=58; f++)
	{
		int row = 17;
		gotoxy(f,row);
		styling(196);     //   lower row.
	}
     	
}

void mainBorder()
{
	
// main heading.	
	
	gotoxy(25,5);
	cout << " Inventory Management System " << endl;

//  upper left corner.

	gotoxy(18,3);
	styling(201);

// upper straight row.
	
for(int b=19;b<=60;b++)
	{
		int row = 3;
		gotoxy(b,row);
		styling(205);
	}

// upper right corner.
	
	gotoxy(61,3);
	styling(187);

// left column.

	for(int a=4;a<=22;a++)
	{
		int coln = 18 ;
		gotoxy(coln,a);
		styling(186);
		
	}  

// right column.
	
	for(int c=4;c<=22;c++)
	{
		int coln =61;
		gotoxy(coln,c);
		styling(186);
	}
	
// left lower corner.

	gotoxy(18,23);
	styling(200);
	
// right lower corner.

	gotoxy(61,23);
	styling(188);  
	
// lower straight row.

for(int d=19;d<=60;d++)
	{
		int row = 23;
		gotoxy(d,row);
		styling(205);
	} 
	
	
}
void esteric(int r){
	for(int g=1;g<=80;g++)
	{
		int row = r;
		gotoxy(g,row);
		cout<<'*';
	} 
}