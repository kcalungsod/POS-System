//POS-System
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <conio.h>


using namespace std;

int main ()
{
	//Asks for the username and password of the user. 
	//Password and username are predefined. If incorrect, the 
	//screen would display that there's an error and would 
	//ask the user the question again.
	
	ofstream receipts_business;
	ofstream receipts_clients;
	ofstream return_list;
	ofstream summary, sumtxt;
	
	time_t now = time(0);
	char* dt = ctime(&now);
	string username = "admin"; 
	string password = "12345";
	string u_name;
	string pw;
	string staff;
	string order_name[20];
	string finalorders[20];
	float finalprices[20];
	string staffs[5] = {"Kaye", "Jeremie", "Annie", "Hazel", "Kevin"};
	string staffcheck;
	char yesorno;
	        	            
	float price[20] = {85,15,11,63,23,48,11,20,25,152,40,66,157,423,62,40,659,37,2, 56};
	float total[20] = {0}, cash=0, change=0;
	float vatsale=0; 
	float totalsale_vat=0;
	float vat=0;
	float vatsale_store[1000]={0}, vat_store[1000]={0}, totcash_store[1000]={0};
	float total_amount=0;
	float cashearned_novat=0, cashearned_vat=0,totalvat=0;
	int options_number,on_supplies, on_additionaloptions,on_staff, on_supply1, on_transac1, on_return, on_staff1, staffstart, return_or,return_or1, on_summary;
	int on_return_cashier;
	int input_item[20]={0};
	int x=0,y=0,z=1, a=0, b=0, d=1, e=0, f=0, g=0, h=0, i=1, j=1, k=1, l=1, n=1, q=0;
	int order;
	int quantity[20]={1};
	int finalquantity[20];
	int check_order=0;
	float totalamount=0;
	int transactnumber=0;
	int returnnumber=0;
	
	float returncash[20];
	string itemsreturned[20];
	float sum=0;
	
	int check[20], check1[20];
	
	uspw:
	cout << "Username: ";
	cin >> u_name;
	cout << endl;
	cout << "Password: ";
	
	char w;
	
	for (h=0;;)
	{
		w=getch();
	
		pw[h]=w;
		++h;
		cout << "*";
		
		if (w=='\b'&&h>=1)
		{
			cout << "\b \b";
			--h;
		}
		if (w=='\r')
		{
			pw[h]='\0';
			break;
		}
	}
	
	
	if (pw==password)
	{
		goto check_username;
	}
					
	check_username:	
		if (u_name==username)
		{
		  system ("cls");
		  goto staff;
		}
	
	if (u_name!=username&&pw!=password)
	{
		system("cls");
		cout << "Wrong username or password. Try again." << endl;
		goto uspw;	
	}
	
	system ("cls");
	staff: 
	cout << "Time in: " << dt << endl;
	cout << "Staff: ";
	cin >> staffcheck;
	cout << endl;
	Sleep(200);
	
	if (staffcheck == staffs[0] || staffcheck == staffs[1] || staffcheck == staffs[2] || staffcheck == staffs[3] || staffcheck == staffs[4])
		{
			system ("cls");
			cout << "Welcome to Green Eight Pharmacy's POS System!" << endl << endl;
			goto listofoptions;
			system("cls");
		}
	else
		{
			cout << "Error. You're not included in the list of authorized staff." << endl << endl;
			stafffirst:
			cout << "Will you quit or try again?" << endl;
			cout << "[1] - Quit" << endl;
			cout << "[2] - Try Again" << endl;
			cout << endl << "Enter the number corresponding to the option of your choice: ";
			cin >> staffstart;
					switch (staffstart)
					{
						case 1:
							{
							system ("cls");
							return 0;	
							}
						case 2:
							{
							system ("cls");
							goto staff;
							}
						default:
							{
							cout << "Invalid. Please follow instructions.";
							goto stafffirst;
							system ("cls");
							}
					}
		}
		
	cout << endl;
	
	listofoptions:
	cout << "MAIN MENU: " << endl << endl;
	cout << "[1] - Supplies" << endl;
	cout << "[2] - Transaction" << endl;
	cout << "[3] - Returns" << endl;
	cout << "[4] - Summary" << endl;
	cout << "[5] - Additional Options" << endl;
	
	cout << endl << "Enter the number corresponding to the option of your choice: ";
	cin >> options_number;

	
	
	switch (options_number)
	{
		case 1://supplies
		{
		supplies:
		system ("cls");
		cout << "SUPPLIES" << endl << endl;
		cout << "[1] - Input supply of items" << endl; 	
		cout << "[2] - List of items" << endl;
		cout << "[3] - Return" << endl;
		
		cout << endl << "Enter the number corresponding to the option of your choice: ";
		cin >> on_supplies;
		
			switch (on_supplies)
			{
				case 1://input supply of items
					{
					edit_input:
					system ("cls");
					
					cout << "Input supply of items. Please enter a number only." << endl << endl;
					cout << "\t\t\t List of Supplies" << endl;
					cout << "Items 					      Price      Supply" << endl;
					cout << setprecision (2) << fixed;
					cout << endl << "Absolute Distilled Water 6.0L                P " << price[0] << " \t  ";
					cin >> input_item[0];
					cout << endl << "Acetone 60 ML                                P " << price[1] << " \t  ";
					cin >> input_item[1];
					cout << endl << "Advil 200MG CAP (IBUPROFEN)                  P " << price[2] << " \t  ";
					cin >> input_item[2];
					cout << endl << "Aerius 5MG TAB (DESLORATADINE)               P " << price[3] << " \t  ";
					cin >> input_item[3];
					cout << endl << "Aerovent NEB 2.5MG/2.5ML (SALBUTAMOL - GEN)  P " << price[4] << " \t  ";
					cin >> input_item[4];
					cout << endl << "Alaska Powdered Milk 150G                    P " << price[5] << " \t  ";
					cin >> input_item[5];
					cout << endl << "Alaxan FR CAP (IBUPROFEN+PARACETAMOL)        P " << price[6] << " \t  ";
					cin >> input_item[6];
					cout << endl << "Aldactone 25MG TAB (SPIRONOLACTONE)          P " << price[7] << " \t  ";
					cin >> input_item[7];
					cout << endl << "Aleva 10MG TAB (EBASTINE)                    P " << price[8] << " \t  ";
					cin >> input_item[8];
					cout << endl << "Allerkid 30ML (CETIRIZINE)                   P " << price[9] << " \t  ";
					cin >> input_item[9];
					cout << endl << "Baby Flo Silicone Nipple Wide Neck (LARG)    P " << price[10] << " \t  ";
					cin >> input_item[10];
					cout << endl << "Baby Flo Silicone Nipple X-Cut 35            P " << price[11]<< " \t  ";
					cin >> input_item[11];
					cout << endl << "Bactidol Solution Oral 120ML (HEXITIDINE)    P " << price[12] << " \t  ";
					cin >> input_item[12];
					cout << endl << "Bactifree 20MG 10G Ointment (MUPIROCIN)      P " << price[13] << " \t  ";
					cin >> input_item[13];
					cout << endl << "Bactiv 1G (CO-AMOXICLAV)                     P " << price[14] << " \t  ";
					cin >> input_item[14];
					cout << endl << "Bactoclav 625MG TAB (CO-AMOXICLAV)           P " << price[15] << " \t  ";
					cin >> input_item[15];
					cout << endl << "Bactroban 2% Ointment 15G (MUPIROCIN)        P " << price[16] << " \t  ";
					cin >> input_item[16];
					cout << endl << "Band-aid 75% Alcohol 150ML                   P " << price[17] << " \t  ";
					cin >> input_item[17];
					cout << endl << "Band-aid strips                              P " << price[18] << " \t  ";
					cin >> input_item[18];
					cout << endl << "Bear Brand 150G                              P " << price[19] << " \t  ";
					cin >> input_item[19];
					
					yn1:
					cout << endl << "Are you sure? (Y/N) ";cin >>yesorno;
					if (yesorno=='Y'||yesorno=='y')
					{
						Sleep (2000); 
						goto supplies;
					}
					else if (yesorno=='N'||yesorno=='n')
					{
						system("cls"); 
						goto edit_input;
					}
					else 
					{
						cout << "Enter Y or N only."; 
						goto yn1;
					}
				}
				case 2://listofsupplies	
				{
					system ("cls");
					cout << "\t\t\t List of Supplies" << endl;
					cout << "Items 					      Price      Supply" << endl;
					cout << setprecision (2) << fixed;
					cout << endl << "Absolute Distilled Water 6.0L                P " << price[0] << " \t  ";
					cout << input_item[0];
					cout << endl << "Acetone 60 ML                                P " << price[1] << " \t  ";
					cout << input_item[1];
					cout << endl << "Advil 200MG CAP (IBUPROFEN)                  P " << price[2] << " \t  ";
					cout << input_item[2];
					cout << endl << "Aerius 5MG TAB (DESLORATADINE)               P " << price[3] << " \t  ";
					cout << input_item[3];
					cout << endl << "Aerovent NEB 2.5MG/2.5ML (SALBUTAMOL - GEN)  P " << price[4] << " \t  ";
					cout << input_item[4];
					cout << endl << "Alaska Powdered Milk 150G                    P " << price[5] << " \t  ";
					cout << input_item[5];
					cout << endl << "Alaxan FR CAP (IBUPROFEN+PARACETAMOL)        P " << price[6] << " \t  ";
					cout << input_item[6];
					cout << endl << "Aldactone 25MG TAB (SPIRONOLACTONE)          P " << price[7] << " \t  ";
					cout << input_item[7];
					cout << endl << "Aleva 10MG TAB (EBASTINE)                    P " << price[8] << " \t  ";
					cout << input_item[8];
					cout << endl << "Allerkid 30ML (CETIRIZINE)                   P " << price[9] << " \t  ";
					cout << input_item[9];
					cout << endl << "Baby Flo Silicone Nipple Wide Neck (LARG)    P " << price[10] << " \t  ";
					cout << input_item[10];
					cout << endl << "Baby Flo Silicone Nipple X-Cut 35            P " << price[11]<< " \t  ";
					cout << input_item[11];
					cout << endl << "Bactidol Solution Oral 120ML (HEXITIDINE)    P " << price[12] << " \t  ";
					cout << input_item[12];
					cout << endl << "Bactifree 20MG 10G Ointment (MUPIROCIN)      P " << price[13] << " \t  ";
					cout << input_item[13];
					cout << endl << "Bactiv 1G (CO-AMOXICLAV)                     P " << price[14] << " \t  ";
					cout << input_item[14];
					cout << endl << "Bactoclav 625MG TAB (CO-AMOXICLAV)           P " << price[15] << " \t  ";
					cout << input_item[15];
					cout << endl << "Bactroban 2% Ointment 15G (MUPIROCIN)        P " << price[16] << " \t  ";
					cout << input_item[16];
					cout << endl << "Band-aid 75% Alcohol 150ML                   P " << price[17] << " \t  ";
					cout << input_item[17];
					cout << endl << "Band-aid strips                              P " << price[18] << " \t  ";
					cout << input_item[18];
					cout << endl << "Bear Brand 150G                              P " << price[19] << " \t  ";
					cout << input_item[19];

					return1:
					cout << endl << endl <<"Return to:" << endl << endl;
		            cout << "[1] - Supplies" << endl;
		            cout << "[2] - Print" << endl;
		            cout << "[3] - Main Menu" << endl; 
		            cout << endl << "Enter the number corresponding to the option of your choice: ";
	        	    cin >> on_supply1;
	        	          
	        	          switch (on_supply1)
	        	          {
	        	              case 1:
	        	              {
	        	              	system ("cls");
							  	goto supplies;
	        	              }
	        	              case 2:
	        	              {
	    					  	yn0:	
	        	              	cout << "Print? (Y/N) ";
	        	              	cin >>yesorno;
									if (yesorno=='Y'||yesorno=='y')
									{
									ofstream inventory;
									inventory.open("inventory.txt");
										{ 
											if (inventory.is_open())
          									{
          										inventory << dt << endl;
          										inventory << "Cashier:" << staff << endl;
												inventory << "\t\t\t List of Supplies" << endl;
                    							inventory << "Items 					      Price      Supply" << endl;
                    							inventory << setprecision (2) << fixed;
												inventory << endl << "Absolute Distilled Water 6.0L                P " << price[0] << " \t  ";
                    							inventory << input_item[0];
                    							inventory << endl << "Acetone 60 ML                                P " << price[1] << " \t  ";
                    							inventory << input_item[1];
                    							inventory << endl << "Advil 200MG CAP (IBUPROFEN)                  P " << price[2] << " \t  ";
                    							inventory << input_item[2];
                    							inventory << endl << "Aerius 5MG TAB (DESLORATADINE)               P " << price[3] << " \t  ";
                    							inventory << input_item[3];
		                    					inventory << endl << "Aerovent NEB 2.5MG/2.5ML (SALBUTAMOL - GEN)  P " << price[4] << " \t  ";
		                    					inventory << input_item[4];
		                    					inventory << endl << "Alaska Powdered Milk 150G                    P " << price[5] << " \t  ";
		                    					inventory << input_item[5];
		                    					inventory << endl << "Alaxan FR CAP (IBUPROFEN+PARACETAMOL)        P " << price[6] << " \t  ";
		                    					inventory << input_item[6];
		                    					inventory << endl << "Aldactone 25MG TAB (SPIRONOLACTONE)          P " << price[7] << " \t  ";
		                    					inventory << input_item[7];
		                    					inventory << endl << "Aleva 10MG TAB (EBASTINE)                    P " << price[8] << " \t  ";
		                    					inventory << input_item[8];
		                    					inventory << endl << "Allerkid 30ML (CETIRIZINE)                   P " << price[9] << " \t  ";
		                    					inventory << input_item[9];
		                    					inventory << endl << "Baby Flo Silicone Nipple Wide Neck (LARG)    P " << price[10] << " \t  ";
		                    					inventory << input_item[10];
		                    					inventory << endl << "Baby Flo Silicone Nipple X-Cut 35            P " << price[11]<< " \t  ";
		                    					inventory << input_item[11];
		                    					inventory << endl << "Bactidol Solution Oral 120ML (HEXITIDINE)    P " << price[12] << " \t  ";
		                    					inventory << input_item[12];
		                    					inventory << endl << "Bactifree 20MG 10G Ointment (MUPIROCIN)      P " << price[13] << " \t  ";
		                    					inventory << input_item[13];
		                    					inventory << endl << "Bactiv 1G (CO-AMOXICLAV)                     P " << price[14] << " \t  ";
		                    					inventory << input_item[14];
		                    					inventory << endl << "Bactoclav 625MG TAB (CO-AMOXICLAV)           P " << price[15] << " \t  ";
		                    					inventory << input_item[15];
		                    					inventory << endl << "Bactroban 2% Ointment 15G (MUPIROCIN)        P " << price[16] << " \t  ";
		                    					inventory << input_item[16];
		                    					inventory << endl << "Band-aid 75% Alcohol 150ML                   P " << price[17] << " \t  ";
		                    					inventory << input_item[17];
		                    					inventory << endl << "Band-aid strips                              P " << price[18] << " \t  ";
		                    					inventory << input_item[18];
		                    					inventory << endl << "Bear Brand 150G                              P " << price[19] << " \t  ";
		                    					inventory << input_item[19];
												
												inventory.close();
												cout << "Stored! Redirected to main menu." << endl;
												system ("pause");
												system ("cls");
												goto listofoptions;
											}
								
										else
											{
											   cout << "Unable to open file!";
											   system ("cls");
											   goto supplies;
											}
									}
								}
								else if (yesorno=='N'||yesorno=='n')
									{
										system("cls"); 
										goto supplies;
									}	
								else 
									{
										cout << "Enter Y or N only."; 
										goto yn0;
									}
	        	              
	        	              }
	        	              case 3:
	        	              {
	        	              system ("cls");
	        	              goto listofoptions; 	
							  }
	        	              default:
	        	    		  {
	        	    		  cout << "Invalid!" << endl;
							  goto return1; 
							  }
	        	          }
					
				case 3://return
					{
						system("cls");
						goto listofoptions;
					}
				default:
				    {
						cout << "Invalid. Please follow instructions.";
						goto supplies;	
				    }
				}
			}
		}
		case 2://transactions
		{   
			summary.open("summaryofalltransactions.xls");
			if (summary.is_open())
			summary << "\t\tTransactions"<<endl;
			summary << "Items\tPrice\tQuantity\tTotal"<<endl;
			receipts_business.open ("receipts_business.doc");
		    receipts_clients.open("receipts_clients.doc");
			system ("cls");	
		    anothertransaction:
		    cout << dt << endl;
		    cout << "Cashier: " << staffcheck << endl;		
		    cout << "\t _________________________________________________ "<<endl;
		    cout << "\t|                                                 |"<<endl;
		    cout << "\t| [1] Absolute Distilled Water 6.0L               |"<<endl;
		    cout << "\t| [2] Acetone 60 ML                               |"<<endl;
		    cout << "\t| [3] Advil 200MG CAP (IBUPROFEN)                 |"<<endl;
		    cout << "\t| [4] Aerius 5MG TAB (DESLORATADINE)              |"<<endl;      
		    cout << "\t| [5] Aerovent NEB 2.5MG/2.5ML (SALBUTAMOL - GEN) |"<<endl;
		    cout << "\t| [6] Alaska Powdered Milk 150G                   |"<<endl;
		    cout << "\t| [7] Alaxan FR CAP (IBUPROFEN+PARACETAMOL)       |"<<endl; 
		    cout << "\t| [8] Aldactone 25MG TAB (SPIRONOLACTONE)         |"<<endl;
		    cout << "\t| [9] Aleva 10MG TAB (EBASTINE)                   |"<<endl;
		    cout << "\t| [10] Allerkid 30ML (CETIRIZINE)                 |"<<endl;
			cout << "\t| [11] Baby Flo Silicone Nipple Wide Neck (LARG)  |"<<endl;
		    cout << "\t| [12] Baby Flo Silicone Nipple X-Cut 35          |"<<endl;
		    cout << "\t| [13] Bactidol Solution Oral 120ML (HEXITIDINE)  |"<<endl;
		    cout << "\t| [14] Bactifree 20MG 10G Ointment (MUPIROCIN)    |"<<endl;      
		    cout << "\t| [15] Bactiv 1G (CO-AMOXICLAV)                   |"<<endl;
		    cout << "\t| [16] Bactoclav 625MG TAB (CO-AMOXICLAV)         |"<<endl;
		    cout << "\t| [17] Bactroban 2% Ointment 15G (MUPIROCIN)      |"<<endl; 
		    cout << "\t| [18] Band-aid 75% Alcohol 150ML                 |"<<endl;
		    cout << "\t| [19] Band-aid strips                            |"<<endl;
		    cout << "\t| [20] Bear Brand 150G                            |"<<endl;
		    cout << "\t|_________________________________________________|"<<endl;
		    
			cout << endl << "[21] Checkout" ;
			cout << endl << "[22] Item Void" ;          
			cout << endl << "[23] Return to Main Menu"; 
					    			    
			do
		    {    
			x++;
			again:
		    cout << endl << endl << "Enter item number: "; cin >> order;   
			check[x-1]=order;
		    if (x==1 && order==21)
		    {
		    	cout << "This option wouldn't work without an item. Please follow instructions." << endl;
		        x-1;
		    	goto again;
			}
			if (order==21)
			{
			    x-1;
			    goto checkout;
			}
			if (order==22)
			{
				if (x==1)
				{
					cout << "This option wouldn't work without an item. Please follow instructions." << endl;
					goto again;
				}
				else if (x>1)
				{
					system ("cls");
					cout << "Item successfully voided. Input transaction again." << endl;
					for (int o=0; o<x;o++)
					{
					input_item[check[o]-1] = input_item[check[o]-1] + quantity[o-1];
					}
					x=0;
	        		totalamount=0;
	        		check[20]=0;
					goto anothertransaction;
				}
			}
			if (order==23)
			{
			    if (x>1)
			    {
			    cout << "You can't exit after entering an item!";
			    x-1;
			    goto again;
			    }
			    else
			    {
			    x=0;
			    system ("cls");
			    goto listofoptions;
			    }
			}
			if (order>23)
			{
				cout << "There is no such option. Please follow instructions." << endl;
				x-1;
				goto again;
			}
			if (x>1)
			{
			if (order==check[x-2])
			{
				cout << "You have already entered this item. Please enter another item instead." << endl;
				x-1;
				goto again;
			}
			}
			
			qty:
		    cout << "Quantity: "; cin>>quantity[x-1];
		    input_item[order-1] = input_item[order-1] - quantity[x-1];		
			
			if (quantity[x-1]==0)
			{
			    cout << "Invalid. You can't enter 0. Please follow instructions." << endl;
			    x-1;
			    goto qty;
			}
			
			if (quantity[x-1]>1)
		    {	
		    if (quantity[x-1]>input_item[order-1])
		    {
		        cout << "Invalid! Quantity ordered is more than item's supply." << endl;
		       	input_item[order-1] = input_item[order-1] + quantity[x-1];
		        x-1;
		        goto qty;
		    }
			}
			
			if (input_item[order-1]<0)
		    {
		        cout << "There are no more supply of this item. Please pick another item instead." <<endl;
		        x-1;
		        input_item[order-1]=0;
		        goto again;
		    }	

	
		            switch (order)
		            {
		                case 1:
		                {
		        	price [0];
		            order_name[0]="Absolute Distilled Water 6.0L"; 
					goto compute;
		                }		  
					     case 2:
		                {
		            price [1];
		            order_name[1]="Acetone 60 ML";
					goto compute;
		                }
		                case 3:
		                {
		            price [2];
		            order_name[2]="Advil 200MG CAP (IBUPROFEN)";
		            goto compute;
		                }
		                case 4:
		                {
		            price [3];
		            order_name[3]="Aerius 5MG TAB (DESLORATADINE)";
		            goto compute;
		                }
		                case 5:
		                {   
		            price [4];
		            order_name[4]="Aerovent NEB 2.5MG/2.5ML (SALBUTAMOL - GEN)";
		            goto compute;
		                }
		                case 6:
		                {
		            price [5];
		            order_name[5]="Alaska Powdered Milk 150G";
		            goto compute;
		                }
		               case 7:
		                {
		            price [6];
		            order_name[6]="Alaxan FR CAP (IBUPROFEN+PARACETAMOL)";
		            goto compute;
		                }
		               case 8:
		                {
		            price [7];
		            order_name[7]="Aldactone 25MG TAB (SPIRONOLACTONE)";
		            goto compute;    
						}
		               case 9:
		                {
		            price [8];
		            order_name[8]="Aleva 10MG TAB (EBASTINE)";
		            goto compute;
					    }
		                case 10:
		                {
		            price [9];
		            order_name[9]="Allerkid 30ML (CETIRIZINE)";
		            goto compute;
					    }
		                case 11:
		                {
		            price [10];
		            order_name[10]="Baby Flo Silicone Nipple Wide Neck (LARG)";
					goto compute;
						}
		                case 12:
		                {
		            price [11];
		            order_name[11]="Baby Flo Silicone Nipple X-Cut 35";
					goto compute;    
						}
		                case 13:
		                {
		            price [12];
		            order_name[12]="Bactidol Solution Oral 120ML (HEXITIDINE)";
					goto compute;    
						}
		                case 14:
		                {
		            price [13];
		            order_name[13]="Bactifree 20MG 10G Ointment (MUPIROCIN)";
					goto compute;    
						}
		                case 15:
		                {
		            price [14];
		            order_name[14]="Bactiv 1G (CO-AMOXICLAV)";
					goto compute;    
						}
		                case 16:
		                {
		            price [15];
		            order_name[15]="Bactoclav 625MG TAB (CO-AMOXICLAV)";
					goto compute;    
						}
		                case 17:
		                {
		            price [16];
		            order_name[16]="Bactroban 2% Ointment 15G (MUPIROCIN)";
					goto compute;
						}
		                case 18:
		                {
		            price [17];
		            order_name[17]="Band-aid 75% Alcohol 150ML";
		            goto compute;    
						}
		                case 19:
		                {
		            price [18];
		            order_name[18]="Band-aid strips";
		            goto compute;    
						}
		                case 20:
		                {
		            price [19];
		            order_name[19]="Bear Brand 150G";
		            goto compute;
					    }
		                default:
		                {
		            cout << "Invalid!";
		            system ("cls");
		            goto again;
		                }
		        	}     
		  	
			compute:
			finalorders[x] = order_name[order-1];
			finalprices[x] = price[order-1];  
			total[x] = price[order-1]*quantity[x-1];
		    cout << "Total: P " << setprecision(2)<<fixed << total[x] << endl;
		    totalamount+=total[x];
		    cout << "\t\t\t Total amount: P " << setprecision(2)<<fixed << totalamount;
			}
			while (x>0); 
		  
		  checkout:
		  system ("cls");
		  transactnumber++;
		  cout << "___________________________________________"<<endl<<endl;
		  cout << "CHECKOUT:" << endl << endl;
		  cout << "Transaction Number: "<< transactnumber<< endl;
		  cout << "Cashier: " << staffcheck << endl;
		  cout << "Date: " <<dt<< endl;//Date and time
		  cout << "_____________________" << endl;
		  cout << "Item (s) = "<< x-1 << endl;
		  cout << "_____________________" << endl;
		  cout << "Item" << endl;
		  while (z<x) 
		  {
		  	cout << finalorders[z] << endl;
			cout <<"             P " << setprecision(2)<<fixed<<finalprices[z] << "\t"<< quantity[z-1] << "\t P " <<setprecision(2)<<fixed<< total[z] << "\t" << endl;
			summary << finalorders[z];
		 	summary <<"\t P " << setprecision(2) << fixed << finalprices[z] << "\t"<< quantity[l-1] << "\t P " << setprecision(2)<<fixed<<total[z] << "\t" << endl << endl;
		  	z++;
		  }
		  cout << "____________________________" << endl;
		  cout <<"Total: P "<<setprecision(2)<<fixed<<totalamount << endl;
		  cashagain:
		  cout <<"Amount Tendered: P "; cin>>cash;
		  
		  if (cash<totalamount)
		  {
		      cout << "Amount paid is deficient. Please enter it again properly."<< endl;
		      goto cashagain;
		  }
		  
		  change=cash-totalamount;
		  vatsale = totalamount*.88;
		  vat=totalamount*.12;
		  totalsale_vat=totalamount;
		  
		  vatsale_store[transactnumber-1]=vatsale;
		  vat_store[transactnumber-1]=vat;
		  totcash_store[transactnumber-1]=totalamount;
		  
	      cout << "Change: P "<<setprecision(2)<<fixed<<change<<endl;
	      cout << "____________________________" << endl;
		  cout << "VAT SALE: P "<< setprecision(2) << fixed << vatsale<<endl;
		  cout << "12% VAT: P "<<setprecision(2) << fixed <<vat<<endl;
		  cout << "TOTAL SALE:P "<<setprecision(2)<<fixed<<totalsale_vat<< endl;     
		  cout << "___________________________________________"<<endl<<endl;
		  system ("pause");
		  system ("cls");	
  
		  cout << endl << "The receipt of this transaction will be automatically stored." << endl << endl;
		  
		  
		  //receipts_business
          if (receipts_business.is_open())
          {
          receipts_business << "\t _______________________________________________"<< endl; 
		  receipts_business << "\t Transaction Number: "<< transactnumber <<endl;
		  receipts_business << "\t Cashier: " << staffcheck <<endl;
		  receipts_business << "\t Date: " << dt <<endl;//Date and time
		  receipts_business << "\t__________________"<<x-1<<"Item (s)____________________"<< endl << endl;
		  while (l<x) 
		  {
		  receipts_business << " \t" << finalorders[l] << endl;
          receipts_business <<"             P " << setprecision(2) << fixed << finalprices[l] << "\t"<< quantity[l-1] << "\t P " << setprecision(2)<<fixed<<total[l] << "\t" << endl;		  	
		  l++;
		  }
		  receipts_business << "\t _______________________________________________"<< endl;
		  receipts_business << "\t Total: P "<<setprecision(2)<<fixed<<totalamount<< endl;
		  receipts_business << "\t Cash: P "<<setprecision(2)<<fixed<<cash<<endl;
	      receipts_business << "\t Change: P "<<setprecision(2)<<fixed<<change<<endl;
	      receipts_business << "\t _______________________________________________"<< endl;
		  receipts_business << "\t VAT SALE: P "<<setprecision(2)<<fixed<<vatsale<<endl;
		  receipts_business << "\t 12% VAT: P "<<setprecision(2)<<fixed<<vat<<endl;
		  receipts_business << "\t TOTAL SALE: P "<<setprecision(2)<<fixed<<totalsale_vat<<endl;
		  receipts_business << "\t________________________________________________"<<endl<<endl;     
		  receipts_business << "\t________________________________________________"<<endl<<endl<<endl<<endl;
		  }
		  
		 
		  
		  
		  yn5:
		  cout << "Would you like to print the client's copy? [Y/N] "; cin>>yesorno;
		  if (yesorno=='Y'||yesorno=='y')
		    {
		        goto printreceipts;
		    }    
		  if (yesorno=='N'||yesorno=='n')
		    {
		        goto return2;
		    }
		  else
			{
			cout << "Enter Y or N only."; 
			goto yn5;
			}
		      
		  printreceipts://receipts_clients
		  
		  cout <<"\t ________________________________________________"<<endl <<endl;
          cout <<"\t              Green Eight Pharmacy              "<< endl;
          cout <<"\t           3556 Lubiran St. Bacood Zone         "<< endl;
          cout <<"\t          062 Brgy. 619 Sta. Mesa, Manila       "<< endl;
          cout <<"\t              TIN: 916-944703-000VAT            "<< endl;
          cout <<"\t               Serial  #: TS09GE01              "<< endl;
          cout <<"\t              MIN: 15092210432323689            "<< endl;
          cout <<"\t________________________________________________"<<endl;
          cout <<"\t OR#:"<< transactnumber <<endl; 
          cout <<"\t Cashier: "<< staffcheck <<endl;
          cout <<"\t Date: " << dt << endl;
          cout <<"\t________________________________________________"<<endl;
          cout <<"\t                                                " <<endl;
          while (j<x) 
                {
                cout << "\t" << finalorders[j] << endl;
                cout <<"             P " << setprecision(2) << fixed << finalprices[j] << "\t"<< quantity[j-1] << "\t P "<< setprecision(2)<<fixed<< total[j] << endl;
                j++;
                }
          cout <<"\t___________________"<<x-1<<"Item (s)__________________"<<endl;
          cout <<"\t Total: P "<< setprecision(2)<<fixed<<totalamount<<endl;
          cout <<"\t   Cash: P "<<setprecision(2)<<fixed<<cash<<endl;
          cout <<"\t Change: P "<<setprecision(2)<<fixed<<change<<endl;
          cout <<"\t________________________________________________"<< endl;
          cout <<"\t VAT SALE: P "<<setprecision(2)<<fixed<< vatsale<<endl;
          cout <<"\t 12% VAT: P "<<setprecision(2)<<fixed << vat<<endl;
          cout <<"\t TOTAL SALE: P "<<setprecision(2)<<fixed<<totalsale_vat<<endl;     
          cout <<"\t________________________________________________"<<endl;
          cout <<"\t   This receipt shall be valid for five years   " <<endl;
          cout <<"\t        from the date of the permit use.        "<< endl;
          cout <<"\t     Permit No.: FP092015-032-0055182-00000     "<<endl;
    	  cout <<"\t       This serves as an official receipt.      " <<endl;
          cout <<"\t           Thank you. Come again!               "<<endl;
          cout <<"\t________________________________________________"<<endl<<endl;
		  
		  
		  yn4:
		  cout << endl << "Are you sure? (Y/N) ";cin >>yesorno;
					if (yesorno=='Y'||yesorno=='y')
					{
                        cout << "Done!" << endl;//client's copy
		  					if (receipts_clients.is_open())
    	  						{
                    		  receipts_clients <<"\t ________________________________________________"<<endl;
                    		  receipts_clients <<"\t                                                "<<endl;
                    		  receipts_clients <<"\t              Green Eight Pharmacy              "<< endl;
                    		  receipts_clients <<"\t           3556 Lubiran St. Bacood Zone         "<< endl;
                    		  receipts_clients <<"\t          062 Brgy. 619 Sta. Mesa, Manila       "<< endl;
                    		  receipts_clients <<"\t              TIN: 916-944703-000VAT            "<< endl;
                    		  receipts_clients <<"\t               Serial  #: TS09GE01              "<< endl;
                    		  receipts_clients <<"\t              MIN: 15092210432323689            "<< endl;
                    		  receipts_clients <<"\t________________________________________________"<<endl;
                    		  receipts_clients <<"\t OR#:"<< transactnumber <<"                                          "<<endl; 
                    		  receipts_clients <<"\t Cashier: "<< staffcheck <<"                                  "<<endl;
                    		  receipts_clients <<"\t Date: " << dt << endl;
                    		  receipts_clients <<"\t________________________________________________"<<endl;
                    		  receipts_clients <<"\t                                                " <<endl;
                    		  while (k<x) 
                    		  {
                    		  	receipts_clients << "\t" << finalorders[k] << endl;
                    			receipts_clients <<"             P " << setprecision(2) << fixed << finalprices[k] << "\t"<< quantity[k-1] << "\t P " << setprecision(2)<<fixed<<total[k] << "\t" << endl;
                    		  	k++;
                    		  }
                    		  receipts_clients <<"\t___________________"<<x-1<<"Item (s)__________________"<<endl;
                    		  receipts_clients <<"\t Total: P "<<setprecision(2)<<fixed<<totalamount<<endl;
                    		  receipts_clients <<"\t   Cash: P "<<setprecision(2)<<fixed<<cash<<endl;
                    	      receipts_clients <<"\t Change: P "<<setprecision(2)<<fixed<<change<<endl;
                    	      receipts_clients <<"\t________________________________________________"<< endl;
                    		  receipts_clients <<"\t VAT SALE: P "<<setprecision(2)<< fixed << vatsale<< endl;
                    		  receipts_clients <<"\t 12% VAT: P "<<setprecision(2) << fixed << vat<<endl;
                    		  receipts_clients <<"\t TOTAL SALE: P "<<setprecision(2)<<fixed<<totalsale_vat<<endl;     
                    		  receipts_clients <<"\t________________________________________________"<<endl;
                    		  receipts_clients <<"\t   This receipt shall be valid for five years   " <<endl;
                    		  receipts_clients <<"\t        from the date of the permit use.        "<< endl;
                    		  receipts_clients <<"\t     Permit No.: FP092015-032-0055182-00000     "<<endl;
                    		  receipts_clients <<"\t       This serves as an official receipt.      " <<endl;
                    		  receipts_clients <<"\t           Thank you. Come again!               "<<endl;
         	          		  receipts_clients <<"\t________________________________________________"<<endl<<endl<<endl<<endl;                       
								}
					}
					else if (yesorno=='N'|| yesorno=='n')
					{
						system("cls"); 
						goto return2;
					}
					else 
					{
						cout << "Enter Y or N only."; 
						goto yn4;
					}
		  
		  
		  return2:
		  cout << "Proceed to: " << endl<< endl;
		  cout << "[1] - Another transaction" << endl;
		  cout << "[2] - Main Menu" << endl;
		  cout << endl << "Enter the number corresponding to the option of your choice: ";
	      cin >> on_transac1;
	        	          
	        switch (on_transac1)
	        {
	        	case 1:
	        	{
	        	system ("cls");
	            x=0;
	        	total[20]={0};
	        	totalamount=0;
	        	z=1;
	        	j=1;
	        	k=1;
	        	l=1;
	        	check[20]=0;
	        	goto anothertransaction;
	        	}
	        	case 2:
	        	{
	        	system("cls"); 	
	        	x=0;
	        	total[20]={0};
	        	totalamount=0;
	        	z=1;
	        	j=1;
	        	k=1;
	        	l=1;
	        	check[20]=0;
				goto listofoptions;
	        	}
				default:
				{
				cout << "Invalid!" << endl;
				system("cls"); 
				goto return2;
				}
				
	   		}
	   	}
		case 3://returns
		{
		returns:
		system ("cls");
		yn3:
		cout << "Only the administrator can access this option. Are you the administrator? [Y/N] "; cin>>yesorno;
			if (yesorno=='Y'||yesorno=='y')
		    	{
		    	system ("cls");
		    	uspw2:
				cout << endl<< "Username: ";
				cin >> u_name;
				cout << endl;
				cout << "Password: ";
				for (h=0;;)
				{
					w=getch();
					if ((w>='a'&&w<='z')||(w>='A'&&w<='Z')||(w>='0'&&w<='9'))
					{
						pw[h]=w;
						h++;
						cout << "*";
					}
					if (w=='\b'&&h>=1)
					{
						cout << "\b \b";
						h--;
					}
					if (w=='\r')
					{
						pw[h]='\0';
						break;
					}
				}
				
				if (pw==password)
				{
					goto check_username1;
				}
					
				check_username1:	
				if (u_name==username)
				{
				    system ("cls");
				    goto return_forward;
				
				}
				else if (u_name!=username&&pw!=password)
				{
					system("cls");
					cout << "Wrong username or password. Try again." << endl;
					goto uspw2;	
				}
			}
		  	else if (yesorno=='N'||yesorno=='n')
				{
				yn8:
				system ("cls");
				cout << "Please call the administrator first. This option could not be accessed without them." << endl;
				cout << endl << "Would you like to: " << endl;
				cout << "[1] - Try Again" << endl;
				cout << "[2] - Main Menu" <<endl;
		
				cout << endl << "Enter the number corresponding to the option of your choice: ";
				cin >> on_return_cashier;
		
						switch (on_return_cashier)
						{
							case 1:
								{
									system ("cls");
									goto yn3;
								}
							case 2:
								{
									system ("cls");
									goto listofoptions;
								}
							default:
								{
									system ("cls");
									cout << "Invalid. Please follow instructions." << endl;
									goto yn8;
								}
						}
				}
			else 
				{
				cout << "Enter Y or N only.";
				system("cls"); 
				goto yn3;
				}	
		
		return_forward:
		cout << "RETURNS" << endl << endl;
		cout << "[1] - Returns" << endl;
		cout << "[2] - Main Menu" <<endl;
		
		cout << endl << "Enter the number corresponding to the option of your choice: ";
		cin >> on_return;
		
			switch (on_return)
			{
				case 1:
				{
				system("cls");	
				return_list.open("return_list.doc");	
				returns1:
				cout << "If you want to quit and return to the main menu immediately. Please input 0 OR # line." << endl;
				cout << "OR #: ";
				cin>>return_or;
				if (return_or>transactnumber || return_or<0)
				{
					system ("cls");
					cout << "There are no transactions with this OR #. Please input an order again." << endl;
					goto returns1;
				}
				if (return_or==0)
				{
					system ("cls");
					goto listofoptions;
				}
			
		    cout << "\t _________________________________________________ "<<endl;
		    cout << "\t|                                                 |"<<endl;
		    cout << "\t| [1] Absolute Distilled Water 6.0L               |"<<endl;
		    cout << "\t| [2] Acetone 60 ML                               |"<<endl;
		    cout << "\t| [3] Advil 200MG CAP (IBUPROFEN)                 |"<<endl;
		    cout << "\t| [4] Aerius 5MG TAB (DESLORATADINE)              |"<<endl;      
		    cout << "\t| [5] Aerovent NEB 2.5MG/2.5ML (SALBUTAMOL - GEN) |"<<endl;
		    cout << "\t| [6] Alaska Powdered Milk 150G                   |"<<endl;
		    cout << "\t| [7] Alaxan FR CAP (IBUPROFEN+PARACETAMOL)       |"<<endl; 
		    cout << "\t| [8] Aldactone 25MG TAB (SPIRONOLACTONE)         |"<<endl;
		    cout << "\t| [9] Aleva 10MG TAB (EBASTINE)                   |"<<endl;
		    cout << "\t| [10] Allerkid 30ML (CETIRIZINE)                 |"<<endl;
			cout << "\t| [11] Baby Flo Silicone Nipple Wide Neck (LARG)  |"<<endl;
		    cout << "\t| [12] Baby Flo Silicone Nipple X-Cut 35          |"<<endl;
		    cout << "\t| [13] Bactidol Solution Oral 120ML (HEXITIDINE)  |"<<endl;
		    cout << "\t| [14] Bactifree 20MG 10G Ointment (MUPIROCIN)    |"<<endl;      
		    cout << "\t| [15] Bactiv 1G (CO-AMOXICLAV)                   |"<<endl;
		    cout << "\t| [16] Bactoclav 625MG TAB (CO-AMOXICLAV)         |"<<endl;
		    cout << "\t| [17] Bactroban 2% Ointment 15G (MUPIROCIN)      |"<<endl; 
		    cout << "\t| [18] Band-aid 75% Alcohol 150ML                 |"<<endl;
		    cout << "\t| [19] Band-aid strips                            |"<<endl;
		    cout << "\t| [20] Bear Brand 150G                            |"<<endl;
		    cout << "\t|_________________________________________________|"<<endl;
			
			cout << endl << "[21] Checkout"; 
			cout << endl << "[22] Return to Main Menu"; 
			
				do
		    {
		    again1:	
		    b++;
		    cout << endl << endl << "Enter item number: "; cin >> order;
			check1[b-1]=order;
			if (order==21)
		    {
		    	if (b==1)
		    	{
		    	cout << "This option wouldn't work without an item. Please follow instructions." << endl;
		    	goto again1;
		    	}
		    	else
		    	{	
		    	system ("cls");
		    	b-1;
		    	goto checkout1;
				}
			}
		    if (order==22)
		    {
			    if (b>1)
			    {
			    cout << "You can't exit after entering an item!";
			    b-1;
			    goto again1;
			    }
			    else
			    {
			    b=0;
			    check1[20]=0;
			    system ("cls");
			    goto listofoptions;
			    }
			}
			if (order>22)
			{
				cout << "There is no such option. Please follow instructions." << endl;
				b-1;
				goto again;
			}
			if (b>1)
			{
			if (order==check1[b-2])
			{
				cout << "You have already entered this item. Please enter another item instead." << endl;
				b-1;
				goto again;
			}
			}
		    
		    qty1:
		    cout << "Quantity Returned: "; cin>>quantity[b-1];
		
		    input_item[order-1]=input_item[order-1]+quantity[b-1];
	
	        if (quantity[b-1]==0)
			{
			    cout << "Invalid. You can't enter 0. Please follow instructions." << endl;
			    b-1;
			    goto qty1;
			}
			
		            switch (order)
		            {
		                case 1:
		                {
		        	price [0];
		            order_name[0]="Absolute Distilled Water 6.0L"; 
					goto compute1;
		                }		  
					     case 2:
		                {
		            price [1];
		            order_name[1]="Acetone 60 ML";
					goto compute1;
		                }
		                case 3:
		                {
		            price [2];
		            order_name[2]="Advil 200MG CAP (IBUPROFEN)";
		            goto compute1;
		                }
		                case 4:
		                {
		            price [3];
		            order_name[3]="Aerius 5MG TAB (DESLORATADINE)";
		            goto compute1;
		                }
		                case 5:
		                {   
		            price [4];
		            order_name[4]="Aerovent NEB 2.5MG/2.5ML (SALBUTAMOL - GEN)";
		            goto compute1;
		                }
		                case 6:
		                {
		            price [5];
		            order_name[5]="Alaska Powdered Milk 150G";
		            goto compute1;
		                }
		               case 7:
		                {
		            price [6];
		            order_name[6]="Alaxan FR CAP (IBUPROFEN+PARACETAMOL)";
		            goto compute1;
		                }
		               case 8:
		                {
		            price [7];
		            order_name[7]="Aldactone 25MG TAB (SPIRONOLACTONE)";
		            goto compute1;    
						}
		               case 9:
		                {
		            price [8];
		            order_name[8]="Aleva 10MG TAB (EBASTINE)";
		            goto compute1;
					    }
		                case 10:
		                {
		            price [9];
		            order_name[9]="Allerkid 30ML (CETIRIZINE)";
		            goto compute1;
					    }
		                case 11:
		                {
		            price [10];
		            order_name[10]="Baby Flo Silicone Nipple Wide Neck (LARG)";
					goto compute1;
						}
		                case 12:
		                {
		            price [11];
		            order_name[11]="Baby Flo Silicone Nipple X-Cut 35";
					goto compute1;    
						}
		                case 13:
		                {
		            price [12];
		            order_name[12]="Bactidol Solution Oral 120ML (HEXITIDINE)";
					goto compute1;    
						}
		                case 14:
		                {
		            price [13];
		            order_name[13]="Bactifree 20MG 10G Ointment (MUPIROCIN)";
					goto compute1;    
						}
		                case 15:
		                {
		            price [14];
		            order_name[14]="Bactiv 1G (CO-AMOXICLAV)";
					goto compute1;    
						}
		                case 16:
		                {
		            price [15];
		            order_name[15]="Bactoclav 625MG TAB (CO-AMOXICLAV)";
					goto compute1;    
						}
		                case 17:
		                {
		            price [16];
		            order_name[16]="Bactroban 2% Ointment 15G (MUPIROCIN)";
					goto compute1;
						}
		                case 18:
		                {
		            price [17];
		            order_name[17]="Band-aid 75% Alcohol 150ML";
		            goto compute1;    
						}
		                case 19:
		                {
		            price [18];
		            order_name[18]="Band-aid strips";
		            goto compute1;    
						}
		                case 20:
		                {
		            price [19];
		            order_name[19]="Bear Brand 150G";
		            goto compute1;
					    }
		                case 21:
		                {
		            system ("cls");
		            goto checkout1;
		            break;
		                }
		                default:
		                {
		            cout << "Invalid!" << endl;
		                }
		        	}     
			
			compute1:
			returncash[b] = price[order-1]*quantity[b-1];
			cout << "Cash Returned: P " <<setprecision(2)<<fixed<< returncash[b]<< endl;
			itemsreturned[b]= order_name[order-1];
			sum+=returncash[b];
			cout << "\t\t\t Total amount returned: P " << setprecision(2)<<fixed << sum;
			}
			while (b>0); 
			
		  
		  checkout1://stored
		  returnnumber++;
		  cout << "___________________________________________"<<endl;
		  cout << "OR#: " << return_or << endl;
		  cout << "Return Number: "<< returnnumber<< endl;
		  cout << "Cashier: " << staffcheck << endl;
		  cout << "Date: " << dt << endl<<endl;
		  cout << "Item (s) = "<< b-1 << endl;
		  cout << "Items Returned: " << endl;
		  cout << "____________________________________________" << endl;
		  while (d<b) 
		  {
		      cout<< itemsreturned[d] << "P "<< setprecision(2) << fixed << returncash[d] <<  endl;
		      d++;
		  }
		  cout << "____________________________________________" << endl;
		  cout << "Total Amount Returned: P " << setprecision (2) << fixed << sum << endl;
		  cout << "____________________________________________" << endl;
			
			cout<< endl;
			cout << "Are you sure? This record would be stored and can't be changed. [Y/N] "; cin>>yesorno;
			yn9:
			if (yesorno=='Y'||yesorno=='y')
					{
                        cout << "Done!" << endl;//stored
		  					if (return_list.is_open())
					          {
					              return_list << "____________________________________________" << endl;
					              return_list << "OR#: " << return_or << endl;
					              return_list << "Return Number: "<< returnnumber<< endl;
							      return_list << "Cashier: " << staffcheck << endl;
							      return_list << "Date: " << dt <<endl<<endl;
							      return_list << "Item (s) = "<< b-1 << endl;
							      return_list << "____________________________________________" << endl;
							      return_list << "Items Returned: " << endl;
							      while (i<b) 
							  {
							      return_list << itemsreturned[i] << setprecision(2) << fixed << returncash[i] << endl;
							      i++;
							  }
							  	  return_list << "____________________________________________" << endl;
							      return_list << "Total Amount Returned: P " << setprecision (2) << fixed << sum << endl;
							      return_list << "____________________________________________" << endl <<endl <<endl<<endl;
							  }
						goto yn7;	  
					}
			
			else if (yesorno=='N'|| yesorno=='n')
					{
						for (int o=0; o<b;o++)
						{
						input_item[check1[o]-1] = input_item[check1[o]-1] + quantity[o-1];
						}
									
						b=0;
	        			f=0;
	        			returncash[20]={0};
	        			order=0;
	        			sum=0;
	        			d=1;
	        			i=1;
						check1[20]=0;
						
						cout << "You will be redirected to the returns menu after several seconds";
						Sleep (1000);
						cout << ". ";
						Sleep (1000);
						cout << ". ";
						Sleep (1000);
						cout << ". ";
						Sleep (1000);
						system("cls"); 
						goto return_forward;
					}
			else 
					{
						cout << "Enter Y or N only."; 
						goto yn8;
					}
		  
		  yn7:
		  cout << "Do you want to do another return? ";
		  cin >>yesorno;
					if (yesorno=='Y'||yesorno=='y')
					{
						system("cls"); 
						b=0;
	        			f=0;
	        			order=0;
	        			returncash[20]={0};
	        			sum=0;
	        			d=1;
	        			i=1;
	        			check1[20]=0;
						goto returns1;
					}
					else if (yesorno=='N'||yesorno=='n')
					{
						system("cls"); 
						b=0;
	        			f=0;
	        			returncash[20]={0};
	        			order=0;
	        			sum=0;
	        			d=1;
	        			i=1;
	        			check1[20]=0;
						goto listofoptions;
					}
					else 
					{
						cout << "Enter Y or N only.";
						system("cls"); 
						goto yn7;
					} 
			}
				case 2:
				{
				    system ("cls");
				    goto listofoptions;
				}
				default:
	            {
	                 cout << "Invalid. Please follow instructions." << endl;
		             goto return_forward;
	            }
		 	}
		}
		case 4:// summary
		{
			summary1:
			system ("cls");
			cout << "SUMMARY:" << endl <<endl;
			cout << dt <<endl << endl;
			cout << "Cashier: " << staffcheck << endl<<endl;
			cout << "Total amount of transactions: " << transactnumber << endl;
			cout << "Total amount of returns: " << returnnumber << endl << endl;
			
			cout << "Note: The cash earned (VAT and NO VAT) as well as the total VAT collected doesn't take into account the cash returned from the refunds. " << endl;
			cout << "The bookkeeper of the business would be the one to take care of this matter." << endl << endl << endl;
		
			for (int m=0;m<transactnumber;m++)	
		  		{
					cashearned_novat+=vatsale_store[m];
		  			cashearned_vat+=totcash_store[m];
		  			totalvat+=vat_store[m];
		  		}
			
			cout << "Cash earned (NO VAT): P " << setprecision(2) << fixed << cashearned_novat <<endl;
			cout << "Cash earned (VAT): P " << setprecision(2) << fixed <<cashearned_vat <<endl;
			cout << "Total VAT collected: P " << setprecision(2) << fixed << totalvat << endl << endl;
			system ("pause");
			
			cout << endl << "Proceed to:" << endl;
			cout << "[1] - Summary of all transactions (Excel)" << endl;
			cout << "[2] - Save overall summary as txt file." << endl;
			cout << "[3] - Main Menu" << endl; 
			
			cout << endl << "Enter the number corresponding to the option of your choice: ";
			cin >> on_summary;
			
				switch (on_summary)
				{
					case 1: 
					{
						system ("cls");
						cout << "Open the file named summaryofalltransactions.xls in your file explorer." << endl << endl; 
						cout << "The file is stored there automatically." << endl;
						system ("pause");
						cout << endl << "You will be redirected to the main menu after several seconds";
						Sleep (1000);
						cout << ". ";
						Sleep (1000);
						cout << ". ";
						Sleep (1000);
						cout << ". ";
						Sleep (1000);
						system ("cls");
						goto listofoptions;
					}
					case 2:
					{
						sumtxt.open("summary.txt");
						if (sumtxt.is_open())
						{
						
						sumtxt << "SUMMARY:" << endl <<endl;
						sumtxt << dt <<endl << endl;
						sumtxt << "Cashier: " << staffcheck << endl<<endl;
						sumtxt << "Total amount of transactions: " << transactnumber << endl;
						sumtxt << "Total amount of returns: " << returnnumber << endl;
					
						for (int m=0;m<transactnumber;m++)	
					  		{
								cashearned_novat+=vatsale_store[m];
					  			cashearned_vat+=totcash_store[m];
					  			totalvat+=vat_store[m];
					  		}
						
						sumtxt << "Cash earned (NO VAT): P " << setprecision(2) << fixed << cashearned_novat <<endl;
						sumtxt << "Cash earned (VAT): P " << setprecision(2) << fixed <<cashearned_vat <<endl;
						sumtxt << "Total VAT collected: P " << setprecision(2) << fixed << totalvat << endl << endl;
						sumtxt.close();
						}
						
						cout << "Stored! File name: summary.txt." << endl;
						cout << endl << "You will be redirected to the main menu after several seconds";
						Sleep (1000);
						cout << ". ";
						Sleep (1000);
						cout << ". ";
						Sleep (1000);
						cout << ". ";
						Sleep (1000);
						system ("cls");
						goto listofoptions;
												
					}
					case 3:
					{
						system ("cls");
						goto listofoptions;
					}
					default:
					{
						system ("cls");
						cout << "Invalid. Please follow instructions." << endl;
						goto summary1; 
					}
				}
			
		}
		case 5://additional options
		{
		addoptions:
		system ("cls");
		cout << "ADDITIONAL OPTIONS" << endl << endl;
		cout << "[1] - Staff" << endl;
		cout << "[2] - Main Menu" << endl;
		cout << "[3] - Quit Program" << endl; 	
		
		cout << endl << "Enter the number corresponding to the option of your choice: ";
		cin >> on_additionaloptions;
		
			switch (on_additionaloptions)
			{
				case 1://staff
				{
	        	  cout << endl << endl << "List of authorized staff:" << endl;
	        	  for (int x=0;x<5;x++)
	        	  {
	        	      cout << "*" << staffs [x] << endl;
	        	  }  
	        	  system ("pause");
	        	  goto addoptions;
	        	 }
		        case 2:
		      	{
		          system ("cls");
		          goto listofoptions;
		      	}
			  	case 3://quit program
				{
				yn6:
				cout << "Are you sure? (Y/N) ";
				cin >>yesorno;
					if (yesorno=='Y'||yesorno=='y')
					{
						system("cls"); 
						goto endprogram;
					}
					else if (yesorno=='N'||yesorno=='n')
					{
						system("cls"); 
						goto addoptions;
					}
					else 
					{
						cout << "Enter Y or N only.";
						system("cls"); 
						goto yn6;
					}
			    }
			  	default:
	                {
	                cout << "Invalid. Please follow instructions." << endl;
		            goto addoptions;
	                } 
			}
		}
	    default:
	    {
	   	   system("cls");
	       cout << "Invalid. Please follow instructions."<<endl;
		   goto listofoptions;
	    }
	}
	
	
	receipts_clients.close();
	receipts_business.close();
	return_list.close();
	summary.close();
	
	endprogram:
	cout << "Time out: " << dt << endl;
	cout << endl << "Have a good day " << staffcheck << "!\n";
	system ("pause");
	return 0;

}


