#include<iostream>
#include<fstream>
#include<vector>
#include<sstream> //needed for istringstream
#define userledger "ledger.txt"
using namespace std;

int main()
{
    int month = 12,year = 2024 ; // just a demo variable to hold how many month's entry you have
    int sys_date = 7; // demo variable
    ofstream ledger(userledger);
    
    //some demo catagories and expenses to write to the file
    string cat[] = {"Car_Maintanence","Leisure","Transport",    // remember : a category name should not have any white space, use underscore for
                    "Groceries", "Rent", "Clothing",            // separating two words
                    "Remitance","Food","Games",
                    "Fuel_Expenses"};
    int expenses[] = {5000,3000,1500,
                      2000,7000,800,
                      5000,1500,3500,
                      2400};
    //writing to file
    for(int j = 1;j<= month; j++){
      ledger << "Start" << endl;
      ledger << year << endl; //year
      ledger <<j << endl;     //month
    for(int i=0;i<10;i++)
    {
      ledger << sys_date<<' '<<cat[i] <<' '<<expenses[i] <<endl;
    }
      ledger << "End" << endl;
    }

/*
//@reading from file into array, ignore, refer to the function for "loadPieData" in the main c++ builder files
    vector<string> fcategory;
    vector<int> amount;

    ifstream f_ledger(userledger);

    //handle exceptions
    if(!f_ledger.is_open())
    {
        cerr<<"File not found or corrupted"<<endl;
        return 1;
    }

    string line;
    while(getline(f_ledger,line))
    {
        string cat;
        int expense;
         
        std::istringstream iss(line);
        if(iss >>sys_date>>cat >> expense)
        {
            fcategory.push_back(cat);
            amount.push_back(expense);
        }
        else
          cerr<<"Failed to parse line: "<<line<<endl;

    }

    //print file data to console
    for(int i=0;i<fcategory.size();i++)
    {
        cout<<"Category: "<<fcategory[i]<<" Expense: "<<amount[i]<<endl;
    }

    //Manually close file
    f_ledger.close();
    */
}