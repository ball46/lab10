#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){	
	double loan , rate , ppy  , PrevBalance , Interest , Total , Payment , NewBalance = 0; //ppy = pay per year
	int End = 1;
	cout << "Enter initial loan: " ;
	cin >> loan;
	cout << "Enter interest rate per year (%): " ;
	cin >> rate;
	cout << "Enter amount you can pay per year: " ;
	cin >> ppy;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";

	PrevBalance = loan;
	Interest = (PrevBalance*rate)/100;
	Total = PrevBalance + Interest;
	Payment = ppy;

	
	for( ;; ){
		if(Total <= Payment && End ==1){
			Payment = Total;
			NewBalance = Total - Payment;
			cout << fixed << setprecision(2); 
			cout << setw(13) << left << End; 
			cout << setw(13) << left << PrevBalance;
			cout << setw(13) << left << Interest;
			cout << setw(13) << left << Total;
			cout << setw(13) << left << Payment;
			cout << setw(13) << left << NewBalance;
			cout << "\n";
			break;
		}


		if ( End == 1 && Total > Payment ){
			NewBalance = Total - Payment;
			cout << fixed << setprecision(2); 
			cout << setw(13) << left << End; 
			cout << setw(13) << left << PrevBalance;
			cout << setw(13) << left << Interest;
			cout << setw(13) << left << Total;
			cout << setw(13) << left << Payment;
			cout << setw(13) << left << NewBalance;
			cout << "\n";
			End++;
		}

		if(Total > Payment ){
			PrevBalance = NewBalance;
			Interest = (PrevBalance*rate)/100;
			Total = PrevBalance + Interest;
			Payment = ppy;
			NewBalance = Total - Payment;
			cout << fixed << setprecision(2); 
			cout << setw(13) << left << End; 
			cout << setw(13) << left << PrevBalance;
			cout << setw(13) << left << Interest;
			cout << setw(13) << left << Total;
			cout << setw(13) << left << Payment;
			cout << setw(13) << left << NewBalance;
			cout << "\n";
			End++;
		}

		if(NewBalance <= Payment){
			PrevBalance = NewBalance;
			Interest = (PrevBalance*rate)/100;
			Total = PrevBalance + Interest;
			Payment = Total;
			NewBalance = Total - Payment;
			cout << fixed << setprecision(2); 
			cout << setw(13) << left << End; 
			cout << setw(13) << left << PrevBalance;
			cout << setw(13) << left << Interest;
			cout << setw(13) << left << Total;
			cout << setw(13) << left << Payment;
			cout << setw(13) << left << NewBalance;
			cout << "\n";
			break;
		}

		if(NewBalance == 0){
			break;
		}
	}
	
	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect
	return 0;
}
