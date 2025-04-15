#include <iostream>


void showBalance(double Balance);
double Depo(double Deposit, double Balance);
double Draw(double Withdraw, double Balance);
void Exit();

int main(){
    double Balance = 0;
    double Deposit;
    double Withdraw;
    int option;

    do{
        
    std::cout << "*********************************\n";
    std::cout << "         Enter your choice       \n";
    std::cout << "*********************************\n";
    std::cout << "Options\n";
    std::cout << " 1. Show Balance\n ";                                            
    std::cout << "2. Deposit Money\n ";
    std::cout << "3. Withdraw Money\n ";
    std::cout << "4. Exit\n ";

    std::cin >> option;

    
    switch(option){
        case 1: 
            showBalance(Balance);
            break;
        case 2: 
            Balance = Depo(Deposit, Balance);
            break;
        case 3: 
            Balance = Draw(Withdraw, Balance);
            break;
        case 4: 
            Exit();
            break;
        default:
            std::cout << "Not a valid input! ";

    }

    }while(option != 4);

    
    

    return 0;
}

void showBalance(double Balance){
    std::cout << "your balance is " << Balance << '\n';
}

double Depo(double Balance, double Deposit){
    std::cout << "Please write down how much you would like to deposit: " << '\n';
    std::cin >> Deposit;
    Balance = Balance + Deposit;
    std::cout << "Thanks for Depositing, you deposited " << Deposit << " And your new Balance is " << Balance << '\n';
    
    return Balance;
}

double Draw(double Balance, double Withdraw){
    std::cout << "Please write down how much you would like to withdraw: " << '\n';
    std::cin >> Withdraw;
    Balance = Balance - Withdraw;
    std::cout << "Thanks for Withdrawing, you Withdrawed " << Withdraw << " And your new Balance is " << Balance << '\n';

    return Balance;
}

void Exit(){
    std::cout << "Thanks for visiting us! ";
}
