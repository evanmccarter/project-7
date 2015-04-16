
// Author:			Evan McCarter
// Source file:		checkRegister.cpp
// Description:		
// Compiler used:	g++ (linux command-line compiler)

#include <iostream>
#include <iomanip>

using namespace std; 


// Function Prototypes
	void displayTitle();
	double getBegBal();
	void displayBal(double);
	void getData(int& , double&);
	double processCheck(double, double);
	double processDeposit(double, double);
	double processATM(double, double);
	double processSvcChg(double);


//Global Constants
const double	CHARGE = 10,
				ATMFEE =  2;

int main()
{
	//Variable Declarations
	int transCode;
	double 	balance,
			transAmt;
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	displayTitle();
	balance = getBegBal();
	getData(transCode, transAmt);
	
	while(transCode != 0)
	{
		switch(transCode)
		{
			case 1: balance = processCheck(balance, transAmt); break;
			case 2: balance = processDeposit(balance, transAmt); break;
			case 3: balance = processATM(balance, transAmt); break;
		}
		displayBal(balance);
		if(balance < 0)
			balance = processSvcChg(balance);
		getData(transCode, transAmt);
	}
	
	return 0;
}


void displayTitle()
{
	cout << "\n       Check Register\n\n";
}

double getBegBal()
{
	double bal;
	cout << "  Enter beginning balance ";
	cin >> bal;
	return bal;
}

void displayBal(double x)
{
	cout << "\t\tBalance = $" << setw(10) << x;
}

void getData(int& code, double& amt)
{
		cout << "\n\n  Enter transaction code (0 to exit) ";
	cin >> code;
	if(code > 0)
	{
		cout << "\n  Enter transaction amount ";
		cin >> amt;
	}
}

double processCheck(double bal, double amt)
{
	cout << "\n  Check =    " << setw(10) << amt;
	return (bal - amt);
}

double processDeposit(double bal, double amt)
{
	cout << "\n  Deposit =  " << setw(10) << amt;
	return (bal + amt);
}

double processATM(double bal, double amt)
{
	cout << "\n  ATM     =  " << setw(10) << amt;
	bal = bal - amt;
	displayBal(bal);
	bal = bal - ATMFEE;
		cout << "\n  ATM Fee =  " << setw(10) << ATMFEE;
	return (bal);
}

double processSvcChg(double bal)
{
	cout << "\n  Service chg =" << setw(8) << CHARGE;
	bal = bal - CHARGE;
	displayBal(bal);
	return (bal);
}
