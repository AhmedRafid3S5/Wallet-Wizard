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
	TRichEdit *RichEdit1;
	TButton *Button1;
	TPageControl *PageControl1;
	TTabSheet *Waqt;
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
	TButton *Button4;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ZakatPageContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled);
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








private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
        void drawCharts(int year ,int month);


};
//---------------------------------------------------------------------------
//My custom class

//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
