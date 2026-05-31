#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


string getCurrencyName(int choice) {
    switch (choice) {
        case 1: return "INR (Indian Rupee)";
        case 2: return "CNY (Chinese Yuan)";
        case 3: return "RUB (Russian Ruble)";
        case 4: return "GBP (British Pound)";
        case 5: return "USD (US Dollar)";
        case 6: return "ILS (Israeli New Shekel)";
        default: return "Unknown";
    }
}

int main() {
    int sourceChoice, targetChoice;
    double amount, convertedAmount;

    
    const double USD_TO_INR = 96.01;
    const double USD_TO_CNY = 6.77;
    const double USD_TO_RUB = 71.15 ;
    const double USD_TO_GBP = 0.74;
    const double USD_TO_USD = 1.00;
    const double USD_TO_ILS = 2.80;

    cout << "=========================================\n";
    cout << "       WELCOME TO THE CURRENCY CONVERTER \n";
    cout << "=========================================\n\n";

    
    cout << "Supported Currencies:\n";
    cout << "1. India (INR)\n";
    cout << "2. China (CNY)\n";
    cout << "3. Russia (RUB)\n";
    cout << "4. UK (GBP)\n";
    cout << "5. USA (USD)\n";
    cout << "6. Israel (ILS)\n\n";

   
    cout << "Select your source currency (1-6): ";
    cin >> sourceChoice;

    if (sourceChoice < 1 || sourceChoice > 6) {
        cout << "Invalid selection. Exiting program.\n";
        return 1;
    }

   
    cout << "Enter the amount to convert: ";
    cin >> amount;

    if (amount < 0) {
        cout << "Amount cannot be negative. Exiting program.\n";
        return 1;
    }

    
    cout << "Select the target currency to convert to (1-6): ";
    cin >> targetChoice;

    if (targetChoice < 1 || targetChoice > 6) {
        cout << "Invalid selection. Exiting program.\n";
        return 1;
    }

    
    double amountInUSD = 0.0;
    switch (sourceChoice) {
        case 1: amountInUSD = amount / USD_TO_INR; break;
        case 2: amountInUSD = amount / USD_TO_CNY; break;
        case 3: amountInUSD = amount / USD_TO_RUB; break;
        case 4: amountInUSD = amount / USD_TO_GBP; break;
        case 5: amountInUSD = amount / USD_TO_USD; break;
        case 6: amountInUSD = amount / USD_TO_ILS; break;
    }

    
    switch (targetChoice) {
        case 1: convertedAmount = amountInUSD * USD_TO_INR; break;
        case 2: convertedAmount = amountInUSD * USD_TO_CNY; break;
        case 3: convertedAmount = amountInUSD * USD_TO_RUB; break;
        case 4: convertedAmount = amountInUSD * USD_TO_GBP; break;
        case 5: convertedAmount = amountInUSD * USD_TO_USD; break;
        case 6: convertedAmount = amountInUSD * USD_TO_ILS; break;
    }

    
    cout << fixed << setprecision(2);
    cout << "\n-----------------------------------------\n";
    cout << "Conversion Result:\n";
    cout << amount << " " << getCurrencyName(sourceChoice) << " = " 
         << convertedAmount << " " << getCurrencyName(targetChoice) << endl;
    cout << "-----------------------------------------\n";

    return 0;
}
