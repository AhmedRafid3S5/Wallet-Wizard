﻿//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Data.DB.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.DBChart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <VCLTee.TeeSpline.hpp>
#include <VCLTee.TeeFunci.hpp>
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
#include<numeric>

using namespace std;

//Extracts unique category and total amount for each category
template <class type,class typeVal>
class Transaction_Summary
{
  /*public:
   enum Month
   {
	Jan,Feb,Mar,Apr,May,Jun,July,Aug,Sep,Oct,Nov,Dec
   };
   */

  private:
	int month;
	int year;
	bool map_complete;

	std::vector<typeVal> amount;
	std::vector<type> category;

	std::map<type,typeVal> categoryAmount;
	typename std::map<type,typeVal>::const_iterator itr;

  public:
	Transaction_Summary():map_complete(false)
	{
	   //ShowMessage("Object created successfully");
	}

	//return the vector that stores the category
	std::vector<type> returnCategories()
	{
      return category;
	}

    //return the vector that stores the amount
	std::vector<int> returnAmounts()
    {
      return amount;
	}

    //return entry list month
	int getMonth()
    {
      return month;
	}

	//return entry list year
	int getYear()
    {
      return year;
	}

    //set entry list year
	void setYear(int Y)
    {
      year = Y;
	}

    //set entry list month
	void setMonth(int m)
	{
      month = m;
	}

    //add amount to respective category
	void updateCategory(type c,typeVal a)
    {
	  categoryAmount[c] += a;
	}
    //only set to true when 'end' marker is found
	void setMapCompletion_true()
	{
	  map_complete = true;
	}

	void setMapCompletion_false()
	{
	  map_complete = false;
	}

	//Initialize the private member arrays
	void populateArrays()
	{
	   if(map_complete){
	   for(itr = categoryAmount.begin();itr != categoryAmount.end();itr++)
	   {
		  category.push_back(itr->first);
		  amount.push_back(itr->second);
	   }
	   }
	   else
	   {
		  //ShowMessage("Warning map not fully populated yet !!");
		  std::cout<<"Warning map not fully populated yet !"<<std::endl;
	   }
	}

	//Copy member arrays to pie arrays
	void returnArrays(std::vector<type>& i_category,std::vector<typeVal>& i_amounts)
	{
	   //do necessary UnicodeString Conversions here if necessary
	   i_amounts.assign(amount.begin(),amount.end());
	   i_category.assign(category.begin(),category.end());
	}

	//return average expense or income of the month
	double return_avg()
	{
		double avg =  std::accumulate(amount.begin(),amount.end(),0)/amount.size();
		return avg;
	}

	//return total expense or income of the month
	double return_total()
	{
		double total =    std::accumulate(amount.begin(),amount.end(),0);
		return total;
    }

};





//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *Analytics;
	TTabSheet *ZakatPage;
	TStaticText *StaticText1;
	TRichEdit *RichEdit2;
	TEdit *Edit1;
	TStaticText *StaticText2;
	TButton *Button2;
	TButton *Button3;
	TChart *Chart1;
	TPieSeries *Series1;
	TChart *Chart2;
	TChart *Chart3;
	TScrollBox *ScrollBox1;
	TStaticText *StaticText4;
	TComboBox *ComboBox1;
	TEdit *Edit3;
	TPieSeries *Series2;
	TLineSeries *Series3;
	TLineSeries *Series4;
	TComboBox *ComboBox2;
	TChart *Chart4;
	TPointSeries *Series5;
	TFastLineSeries *Series6;
	TCustomTeeFunction *TeeFunction1;
	TTabSheet *Income;
	TButton *Button5;
	TRichEdit *RichEdit3;
	TButton *MoreInfo;
	TTabSheet *Expense;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Edit2;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TEdit *Edit8;
	TEdit *Edit9;
	TEdit *Edit10;
	TEdit *Edit11;
	TEdit *Edit12;
	TButton *Button1;
	TButton *Button4;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TButton *Button6;
	TLabel *Label12;
	TButton *Button7;
	TButton *Button8;
	TLabel *Label8;
	TListBox *ListBox1;
	TEdit *Edit13;
	TLabel *Label13;
	TButton *Button9;
	TEdit *Edit14;
	TEdit *Edit15;
	TLabel *Label14;
	TLabel *Label15;
	TEdit *Edit16;
	TLabel *Label16;
	TListBox *ListBox2;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TEdit *Edit17;
	TEdit *Edit18;
	TButton *Search;
	TScrollBox *ScrollBox2;
	TStaticText *StaticText3;
	TComboBox *ComboBox3;
	TButton *ByWeightInfo;
	TButton *ManualBTInfo;
	TStaticText *StaticText5;
	TButton *LoadFromSavings;
	TButton *Button10;
	TLabel *Label21;
	TComboBox *ComboBox5;
	TButton *Button11;
	TLabel *Label22;
	TComboBox *ComboBox4;
	TButton *Button12;
	TButton *Button13;
	void __fastcall PageControl1Change(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall ScrollBox1MouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
		  bool &Handled);
	void __fastcall ScrollBox1MouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
		  bool &Handled);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall Series3ClickPointer(TCustomSeries *Sender, int ValueIndex, int X,
          int Y);
	void __fastcall Series4ClickPointer(TCustomSeries *Sender, int ValueIndex, int X,
          int Y);
	void __fastcall ComboBox2Change(TObject *Sender);
	void __fastcall Chart4Scroll(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall MoreInfoClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	//void __fastcall Label8Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall SearchClick(TObject *Sender);
	void __fastcall ByWeightInfoClick(TObject *Sender);
	void __fastcall ManualBTInfoClick(TObject *Sender);
	void __fastcall ComboBox3Change(TObject *Sender);
	void __fastcall LoadFromSavingsClick(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);










private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
		void drawCharts(int year ,int month);


};
//---------------------------------------------------------------------------
//My custom class


//Base class for the income and expense tab
//---------------------------
class Transaction
{
	public:
		Transaction(){} ;
		virtual ~Transaction(){};

		int Getmonth() { return month; }
		void Setmonth(int val) { month = val; }
		int Getyear() { return year; }
		void Setyear(int val) { year = val; }
		vector<int> Getamount() { return amount; }
		void Addamount(int val) { amount.push_back(val); }
		vector<UnicodeString> Getcategory() { return category; }
		void Addcategory(UnicodeString val) { category.push_back(val); }
		void Addnotes(UnicodeString val) { notes.push_back(val); }   //For short notes
		map<UnicodeString,int> GetTypeToCat() { return TypeToCat; }
		void SetTypeToCat(map<UnicodeString,int> val) { TypeToCat = val; }
		vector<int> Getdate() { return date; }
		void Adddate(int val) { date.push_back(val); }

  //	private:
		int month;
		int year;
		vector<int> amount;
		vector<UnicodeString> category;
		map<UnicodeString,int> TypeToCat;
		vector<int> date;
		vector<UnicodeString> notes;  //Will keep the notes
};

 class IncomeClass : public Transaction
{
	public:
		IncomeClass(){};
		virtual ~IncomeClass(){};
		static int TotalIncome;

	protected:

	private:
};
class ExpenseClass : public Transaction
{
	public:
		ExpenseClass(){};
		virtual ~ExpenseClass(){};
		static int TotalExpense;

	protected:

	private:
};

//The Budget Class
class Budget {
private:
    std::vector<std::string> categories;
    std::vector<int> amounts;

public:
    // Default constructor
    Budget() {}

    // Getter for categories
    std::vector<std::string> getCategories() const {
        return categories;
    }

    // Getter for amounts
    std::vector<int> getAmounts() const {
        return amounts;
    }

    // Setter for categories
    void setCategories(const std::vector<std::string>& cats) {
        categories = cats;
    }

    // Setter for amounts
    void setAmounts(const std::vector<int>& amts) {
        amounts = amts;
    }

    // Add a new category and its corresponding amount
    void addEntry(const std::string& category, int amount) {
        categories.push_back(category);
        amounts.push_back(amount);
    }

    // Delete a category and its corresponding amount by index
    void deleteCategory(int index) {
        if (index >= 0 && index < categories.size()) {
            categories.erase(categories.begin() + index);
            amounts.erase(amounts.begin() + index);
        }
    }

    // Edit the amount at a given index
    void editAmount(int index, int newAmount) {
        if (index >= 0 && index < amounts.size()) {
            amounts[index] = newAmount;
        }
    }

};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
