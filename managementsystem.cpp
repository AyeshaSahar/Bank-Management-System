#include <iostream>
#include <fstream>
#include <cstdlib>
#include<iomanip>
#include<string>

using namespace std;

/************************* struct ******************************/

struct BankAccount{
	char fname[50];
	char lname[50];
	char address[100];
	char bname[50]; 
	int code,acc_num,acc_bal;
	
	void WriteToFile()
	{
		ofstream f1("BankAccount.txt",ios::app); 
		f1<<fname<<setw(5)<<lname<<setw(18)<<address<<setw(20)<<bname<<setw(15)<<code<<setw(17)<<acc_num<<setw(20)<<acc_bal<<setw(20)<<endl;
		f1.close();	
	}
}b2;

/*******************************************************************/

void customer(BankAccount);
void deposit();
void withdraw();
void transfer_cash();
void help();
void display_all();
float calculateInterest(float *p, float *t, float *r);
void del_records();
void apply_loan();

/************************ Customer *********************/
void customer(BankAccount b2)
{
	
	cout << "\n\tEnter First Name: ";
    cin>>b2.fname;
    cout << "\tEnter Last Name: ";
    cin>>b2.lname;
    cout << "\tEnter Email Address: ";
    cin>>b2.address;
    cout << "\tEnter Branch Name: ";
    cin>>b2.bname;
    cout << "\tEnter Bank Code: ";
    cin>>b2.code;
    cout << "\tEnter Account Number: ";
    cin>> b2.acc_num;
    cout << "\tEnter Account Balance: ";
    cin>>b2.acc_bal;

    
    b2.WriteToFile();

    cout << "\n\tDisplaying Information..............." << endl;
    
    cout << "\n\tFirst Name: " << b2.fname << endl;
    cout << "\tLast Name: " << b2.lname << endl;
    cout <<"\tEmail Address: " << b2.address << endl;
    cout << "\tBranch Name: " << b2.bname << endl;
    cout << "\tBank Code: " << b2.code << endl;
    cout << "\tAccount Number: " << b2.acc_num << endl;
    cout << "\tAccount Balance: " << b2.acc_bal << endl;
}
/**********************************************************************/

void display_all()
{
	int pin;
	cout<<"\n\tEnter the pin: ";
	while(!(cin>> pin)) {
		cout<<"\n\tInvalid input. Only integers allowed!";
		cout<<"\n\n\tEnter the pin: ";
		cin.clear(); //clearing wrong input
		cin.ignore(100,'\n'); //discarding the wrong input
		cin>>pin;
		break;}
	if(pin == 1234){
		cout<<"\n\tDisplaying records...............";
		string line;
		ifstream f1 ("BankAccount.txt");
		if (f1.is_open()){    
			cout<<"\n\n\t\t\t\t\tACCOUNT HOLDERS LIST\n\n";
			cout<<"======================================================================================================\n";
			cout<<"     Name             Address          Bank Name        Bank Code         A/c no.             Balance\n";
			cout<<"======================================================================================================\n";
			while ( getline (f1,line) ){
				cout << line << '\n';	}
			f1.close();}
		else{
			cout << "Error!!!!! Unable to open file"; } 	
	}
	else{
		cout<<"\n\tError!!!Incorrect pin, try again!";	}
		
}
/******************************************************************************************/

void deposit()
{
	cout << "\n\n\t\t\t\t\t***********************************" << endl;
	cout << "\t\t\t\t\t\t       Deposit         " << endl;
	cout << "\t\t\t\t\t***********************************" << endl;

	string line;
    string acc;
    ifstream f1;
    
    cout<<"\n\tIf you input incorrect account number, system will not repsond you.\n\tJust press enter to reselect the option.";
    cout<<"\n\tEnter account number: ";
    cin>>acc;
    f1.open("BankAccount.txt");
    if(f1.is_open()){
    	while (getline(f1, line)) {
	        if (line.find(acc)!=string::npos) {
	            cout<<"\n\tUser has been successfuly found!";
				int amt;
				cout<<"\n\tEnter the amount you want to deposit(in Rs): ";
				while(!(cin>> amt)) {
					cout<<"\n\tInvalid input. Only integers allowed!";
					cout<<"\n\n\tEnter the amount you want to deposit(in Rs): ";
					cin.clear(); //clearing wrong input
					cin.ignore(100,'\n'); //discarding the wrong input
					cin>>amt;
					break;}
				cout<<"\n\tAmount has been deposited!!!";}}
	f1.close();
	}
    else {
    	cout << "Error!!!!! File does not exist!"; }
}

/*****************************************************************/

void withdraw()
{
	cout << "\n\n\t\t\t\t\t***********************************" << endl;
	cout << "\t\t\t\t\t\t       Withdraw         " << endl;
	cout << "\t\t\t\t\t***********************************" << endl;
	
	string line;
    string acc;
    ifstream f1;
    
    cout<<"\n\tIf you input incorrect account number, system will not repsond you.\n\tJust press enter to reselect the option.";
    cout<<"\n\tEnter account number: ";
    cin>>acc;
    f1.open("BankAccount.txt");
    if(f1.is_open()){
    	while (getline(f1, line)) {
	        if (line.find(acc)!=string::npos) {
	            int z;
				cout<<"\n\tEnter the amount you want to withdraw(in Rs): ";
				while(!(cin>> z)) {
					cout<<"\n\tInvalid input. Only integers allowed!";
					cout<<"\n\n\tEnter the amount you want to withdraw(in Rs): ";
					cin.clear(); //clearing wrong input
					cin.ignore(100,'\n'); //discarding the wrong input
					cin>>z;
					break;}
				if (z < 25000 && z > 500){
					cout<< "\n\tWithdrawing cash............"<<endl;
					cout<< "\n\tWithdraw successful!!!";}
				else{
					cout<<"\n\tTransaction not successful!!!"<<endl;
					cout<<"\n\tYou can only withdraw amount greater than Rs 500 and upto or equal to 25000 in 1 day!!!!";}
			}
    	}
    f1.close();
    }
    else {
    	cout << "Error!!!!! File does not exist!"; 
    }
}   

/*****************************************************************/

void transfer_cash()
{
	cout << "\n\n\t\t\t\t\t****************************************" << endl;
	cout << "\t\t\t\t\t\t       Transfer Cash         " << endl;
	cout << "\t\t\t\t\t****************************************" << endl;

	string line;
    string acc;
    ifstream f1;
    
    cout<<"\n\tIf you input incorrect account number, system will not repsond you.\n\tJust press enter to reselect the option.";
    cout<<"\n\tEnter account number: ";
    cin>>acc;
    f1.open("BankAccount.txt");
    if(f1.is_open()){
    	while (getline(f1, line)) {
	        if (line.find(acc)!=string::npos) {
	        	int a, m;
				cout<<"\n\tEnter the account number to which you want to transfer money: ";
				while(!(cin>> a)){
					cout<<"\n\tInvalid input. Only integers allowed!";
					cout<<"\n\tEnter the account number to which you want to transfer money: ";
					cin.clear(); //clearing wrong input
					cin.ignore(100,'\n'); //discarding the wrong input
					cin>> a;
					break;}
				cout<< "\n\tEnter the amount you want to transfer(in Rs): ";
				while(!(cin>> m)) {
					cout<<"\n\tInvalid input. Only integers allowed!";
					cout<<"\n\tEnter the amount you want to transfer(in Rs): ";
					cin.clear(); //clearing wrong input
					cin.ignore(100,'\n'); //discarding the wrong input
					cin>> m;
					break;}
				if (m>500){
					cout<< "\n\tTransfering cash.............................."<<endl;
					cout<< "\n\tTransfer successful";}
				else{
					cout<< "\n\tBalance not sufficient enough!"; }
		    }
		}
	f1.close();
	}
    else {
    	cout << "Error!!!!! File does not exist!"; }

}

/*****************************************************************/

void help()
{
	cout << "\n\n\t\t\t\t\t***********************************" << endl;
	cout << "\t\t\t\t\t\t       Help         " << endl;
	cout << "\t\t\t\t\t***********************************" << endl;
	cout<<"\n\tFollow the given instructions to make the transactions. \n\n\tSoon we will add more options and your trust in our bank is much appreciated.";
	cout<< "\n\n\tTo apply for a loan, you must have an account,\n\n\tIn order to create an account, press 1 and Enter.";
	cout<<"\n\n\tFor more information, contact our head office. \n\n\tContact information is given below:";
	cout<<" \n\n\tPhone Number: 000-0000-0000 \n\tEmail: banklimited@email.com \n\tAddress: Near to PIMS,Islamabad"; 
}	

/*****************************************************************/

float calculateInterest(float *d, float *e, float *f)
{
    return ((*d)*(*e)*(*f))/100; 
}

void apply_loan()
{
	cout << "\n\n\t\t\t\t\t****************************************" << endl;
	cout << "\t\t\t\t\t\t       Apply for loan         " << endl;
	cout << "\t\t\t\t\t****************************************" << endl;

		string line;
	    string acc;
	    ifstream f1;
	    
        cout<<"\n\tIf you input incorrect account number, system will not respond you.\n\tJust press enter to reselect the option.";
	    cout<<"\n\tEnter account number: ";
	    cin>>acc;
	    f1.open("BankAccount.txt");
	    if(f1.is_open()){
	    	while (getline(f1, line)) {
		        if (line.find(acc)!=string::npos) {
			        cout<<"\n\tUser has been successfuly found!";
					float p, t, r, interest,total;
					cout << "\n\n\tEnter principal amount of loan(in Rs): ";
					while(!(cin>> p)){
						cout<<"\n\tInvalid input. Only integers allowed!";
						cout<<"\n\tEnter again: ";
						cin.clear(); //clearing wrong input
						cin.ignore(100,'\n'); //discarding the wrong input
						cin>> p;
						break;	}
					cout<< "\n\tEnter the time in which you will pay the loan(in years): ";
					while(!(cin>> t)) {
						cout<<"\n\tInvalid input. Only integers allowed!";
						cout<<"\n\tEnter again: ";
						cin.clear(); //clearing wrong input
						cin.ignore(100,'\n'); //discarding the wrong input
						cin >> t;
						break;}
					cout<< "\n\tEnter the annual interest rate: ";
					while(!(cin>> r)) 	{
						cout<<"\n\tInvalid input. Only integers allowed!";
						cout<<"\n\tEnter again: ";
						cin.clear(); //clearing wrong input
						cin.ignore(100,'\n'); //discarding the wrong input
						cin >> r;
						break;}
					interest = calculateInterest(&p, &t, &r);
					total = interest+p;
					cout << "\n\tSimple Interest = " << interest << endl;
					cout<<"\n\tTotal amount to pay back the bank(in Rs): "<<total; }
	    	}
	    f1.close();
	    }
	    else {
	    	cout << "Error!!!!! File does not exist!"; }
}

/*****************************************************************/

void del_records()
{
	cout << "\n\n\t\t\t\t\t*********************************************" << endl;
	cout << "\t\t\t\t\t\t       Delete all records         " << endl;
	cout << "\t\t\t\t\t*********************************************" << endl;
	int g;
	int pin;
	cout<<"\n\tEnter the pin: ";
	while(!(cin>> pin)){
		cout<<"\n\tInvalid input. Only integers allowed!";
		cout<<"\n\n\tEnter the pin: ";
		cin.clear(); //clearing wrong input
		cin.ignore(100,'\n'); //discarding the wrong input
		cin>>pin;
		break;}	
	if(pin == 1234){
		cout<<"\n\tAre you sure you want to proceed? \n\tIf yes, then press 1 to delete all records, if no, press 2: ";
		while(!(cin>> g)){
			cout<<"\n\tInvalid input. Only integers allowed!";
			cout<<"\n\tEnter again: ";
			cin.clear(); //clearing wrong input
			cin.ignore(100,'\n'); //discarding the wrong input
			cin >> g;
			break;}
		
		if (g == 1){
			cout<<"\n\tAll records successfully deleted!";
			ofstream f1("BankAccount.txt",ios::trunc);
	    	f1.close();	}
		else {
			int main();}
    }
	else{
		cout<<"\n\tError!!!Incorrect pin, try again!";}
}
/*********************** Main Function ************************/

int main()
{
	char choice;
	do{
		system("cls");
		cout << endl << endl << endl;
		cout << "\t\t\t\t\t   Bank Management System    " << endl;
		cout << endl << endl << endl;
		cout << "\t\t\t\t\t****************************" << endl;
		cout << "\t\t\t\t\t         MAIN MENU         " << endl;
		cout << "\t\t\t\t\t****************************" << endl;
		cout << "\t\t\t\t\t     1 -- Create Account" << endl;
		cout << "\t\t\t\t\t     2 -- Deposit" << endl;
		cout << "\t\t\t\t\t     3 -- Withdraw" << endl;
		cout << "\t\t\t\t\t     4 -- View All Accounts" << endl;
		cout << "\t\t\t\t\t     5 -- Transfer Cash" << endl;
		cout << "\t\t\t\t\t     6 -- Apply for a loan" << endl;
		cout << "\t\t\t\t\t     7 -- Delete all records" << endl;
		cout << "\t\t\t\t\t     8 -- Help" << endl;
		cout << "\t\t\t\t\t     9 -- Exit" << endl;
		cout << endl << "\t\t\t\t\tEnter your selection(1-9): ";
	    cin>> choice;		
		system("cls");
		switch(choice)
		{
			case '1':
				cout << "\n\n\t\t\t\t\t****************************************" << endl;
				cout << "\t\t\t\t\t\t       Create Account         " << endl;
				cout << "\t\t\t\t\t****************************************" << endl;
				int n;
				cout<<"\n\tHow many customers do you want to add? ";
				while(!(cin>> n)) {   
					cout<<"\n\tInvalid input. Only integers allowed!";
					cout<<"\n\n\tHow many customers do you want to add? ";
					cin.clear(); //clearing wrong input
					cin.ignore(100,'\n'); //discarding the wrong input
					cin>>n;
					break;}
				for(int i; i<n ; i++){
					cout<<"\n\tEnter customer "<<i+1<<" details"<<endl;
					customer(b2);}
				break;
			case '2':
				deposit();
				break;
			case '3':
				withdraw();
				break;
			case '4':
				display_all();
			    break;
			case '5':
				transfer_cash();
				break;
			case '6':
			    apply_loan();
				break;
			case '7':
				del_records();
				break;
			case '8':
				help();
				break;
			case '9':
				cout<<"\n\n\n\n\n\n\n\n\t\t\t\tThanks for using our BANK MANAGEMENT SYSTEM!";
				break;
			default :cout<<"\a";	
		}
		cin.ignore();
		cin.get();
	}
	while(choice!='9');
	return 0;
}

