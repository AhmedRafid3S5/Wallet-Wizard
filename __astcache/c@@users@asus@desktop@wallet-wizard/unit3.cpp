//---------------------------------------------------------------------------

#include <vcl.h>
#include <IdHTTP.hpp>
#include <SysUtils.hpp>
#include <System.SysUtils.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>
#include <VclTee.TeeProcs.hpp> // Include TeeChart headers
#include <Vcl.ComCtrls.hpp> //added for pop up richedit
#include <VCLTee.Series.hpp>
#pragma hdrstop
#include <iomanip>     //for the setw setfill flags during fileprint

#define userledger "ledger.txt"
#define incomeledger "incomes.txt"
#define Total_Tabs 5

#include "Unit3.h"
#include "Regression.h"
using namespace std;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
TPieSeries  *Series1;
TPieSeries  *Series2;
TLineSeries *Series3;
TLineSeries *Series4;
TLineSeries *Series5;
TLineSeries *Series6;

std::string content;
int inputValue = 0;
int year, month, day;
float totalZakat = 0;
std::vector<Transaction_Summary<UnicodeString,int>> ExpenseList;
std::vector<Transaction_Summary<UnicodeString,int>> IncomeList;

//These vectors load up with the requested month and year data
std::vector<UnicodeString> e_category;
std::vector<int> e_amount;

std::vector<UnicodeString> i_category;
std::vector<int> i_amount;
//-------------------------------------------------------------


//Variables for income tab

int IncomeClass::TotalIncome=0;
vector<IncomeClass> IncomeRead;
vector<ExpenseClass> ExpenseRead;

void loadGoldFile()
{
      // URL of the webpage
	std::string url = "https://www.livepriceofgold.com/bangladesh-gold-price.html"; //chnange url here with your location's url

	// Create a file stream to store the webpage content
	std::ofstream webpageFile("goldwebpage.html");

	if (!webpageFile.is_open()) {
		ShowMessage( "Failed to open the file for writing.");
		return;

	}

	// Use system command to fetch the webpage content and write it to the file
	std::string command = "curl -s -o goldwebpage.html " + url;
	if (system(command.c_str()) != 0) {
		ShowMessage("Failed to fetch the webpage.");
		webpageFile.close();
		return;
	}

	webpageFile.close();

	// Open the downloaded file for parsing
	std::ifstream file("goldwebpage.html");
	if (!file.is_open()) {
		ShowMessage("Failed to open the file for reading.");
		return;
	}

	std::string line;

	while (std::getline(file, line)) {
		content += line;
	}
	file.close();

}
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
//All Initializations
   //Get present date
	TDateTime currentDate = Now();
	year = YearOf(currentDate);
	month = MonthOf(currentDate);
	day = DayOf(currentDate);

   //Analytics Edit3
   Edit3->Text = IntToStr(year);
//-----------------------------------------------------------------------------
   //Combo box elements
	ComboBox1->Style = csDropDownList;
	for (int i = 0; i < 12; ++i) {
		ComboBox1->Items->Add(FormatSettings.LongMonthNames[i]);
	}

	ComboBox2->Style = csDropDownList;
	ComboBox2->Items->Add("Average");
	ComboBox2->Items->Add("Cumilative");
//-----------------------------------------------------------------------------

	Chart1->Top = 75;
	Chart2->Top = Chart1->Top + Chart1->Height;
	Chart3->Top = Chart2->Top + Chart2->Height;
	Chart4->Top = Chart3->Top + Chart3->Height;
	RichEdit3->Top = Chart4->Top + Chart4->Height;
	RichEdit3->Width = Chart4->Width;
   //Set Tab size (Initializer)
	 PageControl1->TabWidth = PageControl1->ClientWidth/Total_Tabs - 1;
   //Set ScrollBar Limit (Initializer)

   //Load File function calls
   loadGoldFile();

   //This is to clear the input boxes
	Edit2->Text = "";
	Edit6->Text = "";
	Edit4->Text = "";
	Edit5->Text = "";
	Edit7->Text = "";
	Edit8->Text = "";
	Edit9->Text = "";
	Edit10->Text = "";
	Edit11->Text = "";
	Edit12->Text = "";




}
//---------------------------------------------------------------------------

 //Sorts entries according to date
void SortIncome()
{
   for(int i=0;i<IncomeRead.size();i++)
   {
	   for(int j=0;j<IncomeRead[i].category.size();j++)
	   {
		   for(int k=0;k<  IncomeRead[i].category.size()-j-1;k++)
		   {
			   if( IncomeRead[i].date[k]>IncomeRead[i].date[k+1] )
			   {
				   swap(IncomeRead[i].date[k],IncomeRead[i].date[k+1]);
				   swap(IncomeRead[i].amount[k],IncomeRead[i].amount[k+1]);
				   swap(IncomeRead[i].category[k],IncomeRead[i].category[k+1]);
			   }
		   }
       }

   }

}

//---------------------------------------------------------------------------


void __fastcall TForm3::ZakatPageContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled)
{

	//convert string to float value
	//multiply per gram price with 85.
	//If eligible, zakat = 2.5 % of available money
}
//---------------------------------------------------------------------------

  float nisab=0;

//create a linear expense model to predict total expense for a required savings
void update_regression_model(regression& r)
{
   std::vector<float> expenses; //dependent
   std::vector<float> savings;  // independent

   for(int i=0;i<ExpenseList.size();i++)
   {
	   expenses.push_back(ExpenseList[i].return_total());
   }

   for(int i=0;i<IncomeList.size();i++)
   {
	   savings.push_back(IncomeList[i].return_total() - ExpenseList[i].return_total());
   }

   r.takeInput(expenses,savings);

}

//drawCharts takes parameters year and month for which we want to see the analytics
void TForm3::drawCharts(int year,int month )
  {

   String footerTitleMonth = FormatSettings.ShortMonthNames[month-1];
   String footerTitleYear = IntToStr(year);

   //Series1
		//Chart1->ClearChart();
		Series1->Clear();
	   //	ShowMessage("Vector Size: " +  IntToStr(static_cast<int>(e_amount.size())));

   for(int i=0;i<e_amount.size();i++)
   {
	  TColor myCustomColor = TColor(RGB((50 + 45 * i * i)%256, (100 + 50 * i)%256, 150 + 5 * i));
	  Series1->Add(e_amount[i],e_category[i]);

   }

   // Enable labels to show percentages
   Series1->Marks->Style = smsPercent;
   Chart1->Foot->Clear();
   Chart1->Foot->Text->Add(footerTitleMonth + " " + footerTitleYear);
   //-------------------------------------------------------------------------------------

    //Series2
		//Chart1->ClearChart();
		Series2->Clear();

	   //	ShowMessage("Vector Size: " +  IntToStr(static_cast<int>(e_amount.size())));

   for(int i=0;i<i_amount.size();i++)
   {
	  TColor myCustomColor = TColor(RGB(50 + 45 * i, (100 + 50 * i)%256, 150 + 15 * i));
	  Series2->Add(i_amount[i],i_category[i]);

   }

   // Enable labels to show percentages
   Series2->Marks->Style = smsPercent;
   Chart2->Foot->Clear();
   Chart2->Foot->Text->Add(footerTitleMonth + " " + footerTitleYear);
   //-------------------------------------------------------------------------------------

   //Avg_Income and Avg_Expense

	Series3->Clear();
	Series4->Clear();
    Series4->LinePen->Color = clRed;

	if(ComboBox2->ItemIndex == 0){
	// Add data points for average income

	Chart3->Title->Caption="Transaction averages over the months";
	Series3->LegendTitle = "Avg_Income";
	Series4->LegendTitle = "Avg_Expense";

	for(int i=ExpenseList.size()-12;i<ExpenseList.size();i++)
	{
	   Transaction_Summary<UnicodeString,int> entry = IncomeList[i];
	   double monthAvg =  entry.return_avg();
	   int month = entry.getMonth();
	    UnicodeString m = FormatSettings.ShortMonthNames[month-1]+ IntToStr(entry.getYear()%1000) ;
	   Series3->AddXY(i+1,monthAvg,m);
	}

	// Add data points for average expense

	for(int i=ExpenseList.size()-12;i<ExpenseList.size();i++)
	{
	   Transaction_Summary<UnicodeString,int> entry = ExpenseList[i];
	   double monthAvg =  entry.return_avg();
	   int month = entry.getMonth();
		UnicodeString m = FormatSettings.ShortMonthNames[month-1]+ IntToStr(entry.getYear()%1000) ;
	   Series4->AddXY(i+1,monthAvg,m);
	}

	}

	else if(ComboBox2->ItemIndex == 1)
	{
	    Chart3->Title->Caption="Transaction summations over the months";
		Series3->LegendTitle = "Total_Income";
		Series4->LegendTitle = "Total_Expense";

	for(int i=ExpenseList.size()-12;i<ExpenseList.size();i++)
	{
	   Transaction_Summary<UnicodeString,int> entry = IncomeList[i];
	   double monthTotal =  entry.return_total();
	   int month = entry.getMonth();
	   UnicodeString m = FormatSettings.ShortMonthNames[month-1]+ IntToStr(entry.getYear()%1000) ;
	   Series3->AddXY(i+1,monthTotal,m);
	}

	// Add data points for average expense

	for(int i=ExpenseList.size()-12;i<ExpenseList.size();i++)
	{
	   Transaction_Summary<UnicodeString,int> entry = ExpenseList[i];
	   double monthTotal =  entry.return_total();
	   int month = entry.getMonth();
	   UnicodeString m = FormatSettings.ShortMonthNames[month-1] + IntToStr(year%1000);
	   Series4->AddXY(i+1,monthTotal,m);
	}
	}

	//Linear regression model

	Chart4->Title->Caption = "Expense V Savings Forecasting";
	Series5->Clear();
	Series6->Clear();

    	regression r;
	update_regression_model(r);

	float m = r.coefficient();
	float c = r.constant();

	for(int i=0;i<ExpenseList.size();i++)
	{
		float y = ExpenseList[i].return_total();
		float x = IncomeList[i].return_total() - y;

		Series5->AddXY(x,y);
	}

	Series5->AddXY(0,c);
	Series5->AddXY(-c/m,0) ;



   // Add points to the series based on the equation y = ax + b
   for (double x =r.get_min_X()-1000; x <r.get_max_X()+10000; x += 1000) {
	double y = m * x + c;
	Series6->AddXY(x, y);

   }

   UnicodeString BaseExp = FloatToStr((int)c);
   UnicodeString BaseIncome = FloatToStr((int)(-c/m));

   float totalIncome = std::accumulate(i_amount.begin(),i_amount.end(),0);
   float totalExpense = std::accumulate(e_amount.begin(),e_amount.end(),0);
   int savings_rate = ( (totalIncome - totalExpense) / totalIncome)*100;

    RichEdit3->Clear();
RichEdit3->ReadOnly = true;

// Add empty line
RichEdit3->Lines->Add("");

// Estimated Base Expense with red font


RichEdit3->Lines->Add("  Estimated Base Expense " + BaseExp + " Tk");
RichEdit3->SelStart = 26;
RichEdit3->SelLength = BaseExp.Length()+1;
RichEdit3->SelAttributes->Color = clRed;

// Estimated Base Income with green font
RichEdit3->Lines->Add("  Estimated Base Income " + BaseIncome + " TK");
RichEdit3->SelStart = RichEdit3->Text.Length() - 13;
RichEdit3->SelLength = BaseIncome.Length()+1;
RichEdit3->SelAttributes->Color = clGreen;
// Savings rate with month and year in bold
RichEdit3->SelStart = RichEdit3->Text.Length();
RichEdit3->SelLength = 0;
RichEdit3->SelAttributes->Style = RichEdit3->SelAttributes->Style << fsBold;
RichEdit3->SelAttributes->Color = clBlack;  // Reset color
RichEdit3->Lines->Add(" Savings rate for " + FormatSettings.LongMonthNames[month - 1] +
    " " + IntToStr(year) + " : " + FloatToStr(savings_rate) + "%");

// Reset style
RichEdit3->SelAttributes->Style = TFontStyles();

// Advice sentence in light blue font
RichEdit3->SelStart = RichEdit3->Text.Length();
RichEdit3->SelLength = 0;
RichEdit3->SelAttributes->Color = clMenuHighlight;
RichEdit3->Lines->Add("  Advice: To maintain good financial health, your savings rate should be at least 20%");


}

void loadPieData(std::vector<Transaction_Summary<UnicodeString,int>>& List,
				 std::string ledger,
				 std::vector<UnicodeString>& f_category,std::vector<int>&  amount,
				 int month,int year)
{
	 //Init with a cleared List
	 List.clear();

	 std::ifstream inputFile(ledger);

	if (!inputFile.is_open()) {
		ShowMessage("Failed to open the file.");
		return;
	}

  std::string line;
  while(std::getline(inputFile,line))
  {
	 Transaction_Summary<UnicodeString,int> entry;
	if(line == "Start")
	{
	  std::getline(inputFile,line);
	  //Read year and month
	  int year = std::stoi(line);
	  std::getline(inputFile,line);
	  int month = std::stoi(line);

	  //Set year and month for (class) entry
	  entry.setYear(year);
	  entry.setMonth(month);

	  //Read entries until 'End' marker is found
	  while (std::getline(inputFile, line) && line != "End") {
				std::istringstream iss(line);
				int day, amount;
				std::string category;

				if (iss >> day >> category >> amount) {
					UnicodeString c = UnicodeString(category.c_str());
					entry.updateCategory(c,amount);
				}
			}
	  entry.setMapCompletion_true();
	  entry.populateArrays();
	  //push to the vector of ExpenseSummary
	  List.push_back(entry);
	}

  }


  //Temporary fix for now
  for(int i=0;i<List.size();i++)
  {
	 if(List[i].getMonth() == month && List[i].getYear() == year)
		{
			List[i].returnArrays(f_category,amount);
			return;
		}
  }

  //else when the month is not found
  ShowMessage("Requested month data non-existent");
  //clear the vectors passed
  f_category.clear();
  amount.clear();
  //ExpenseList[1].returnArrays(f_category,amount);
}

void __fastcall TForm3::PageControl1Change(TObject *Sender)
{
   TTabSheet *activePage = PageControl1->ActivePage;

	// Update the TStaticText with information based on the active page
	if( activePage == Analytics)
	{   ComboBox1->ItemIndex = month - 1;
		ComboBox2->ItemIndex = 0;
		Edit3->Text = IntToStr(year);
		//Display the charts for month and year of present time
		loadPieData(ExpenseList,userledger,e_category,e_amount,month,year);
		loadPieData(IncomeList,incomeledger,i_category,i_amount,month,year);
		drawCharts(year,month);
		//Set line graph (by default) to average income and expense

	}
	if (activePage == ZakatPage) {

	size_t GoldPricePos = content.find("1 GRAM GOLD 24K");
	std::string pureGoldPrice;
	UnicodeString goldPrice;

	if(GoldPricePos != std::string::npos)
	{
		pureGoldPrice = content.substr(GoldPricePos+45,8); // substr(beginPOs,append how many char?)
		goldPrice =  content.substr(GoldPricePos+45,8);
	}

	//std::cout<<pureGoldPrice<<"\n";
	//Conversion to float then to string for display

	//RichEdit2->Lines->Add(goldPrice) ;

	goldPrice = goldPrice.Delete(goldPrice.Pos(","),1);

	float unitGoldPrice =  StrToFloat(goldPrice);

	 nisab = 85*unitGoldPrice;


	 UnicodeString moneyThreshold = FloatToStr(nisab);


	 //Testing with Static Text
	 UnicodeString youMustHave = " You must have " ;
	 UnicodeString Tk = " Tk";
	 StaticText1->Caption = "To be able to give zakat" + youMustHave + moneyThreshold + Tk;

	  //Testing with Richedit (Can have more control over text color and fonts)
	  RichEdit2->ReadOnly = true;
	  RichEdit2->Clear();
	  RichEdit2->SelStart = 0; // Starting position
	  RichEdit2->SelLength = 37; // Length of the text to format
	  RichEdit2->SelAttributes->Name = L"Arial"; // Font name
	  RichEdit2->SelAttributes->Size = 12; // Font size
	  RichEdit2->SelAttributes->Style = TFontStyles() << fsBold; // Font style (e.g., bold)
	  RichEdit2->Lines->Add("Eligibility Criteria for giving Zakat");
	  RichEdit2->SelStart = 80; // Starting position
	  RichEdit2->SelLength = moneyThreshold.Length(); // Length of the text to format
	  //RichEdit2->SelAttributes->Color = clGreen;
	  RichEdit2->Lines->Add("Annual saving >= " + moneyThreshold);
	}
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------



//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
   // Get the user input from the Edit1 component
    UnicodeString userInput = Edit1->Text;


    try {
        // Convert the user input to an integer
		 inputValue = StrToInt(userInput);

        // Now 'inputValue' contains the numeric user input
        // You can use 'inputValue' in your application
    } catch (EConvertError &e) {
		ShowMessage("Invalid input. Please enter a valid number.");
	}
  std::cout<<inputValue;
  Edit1->Clear();
  RichEdit2->Lines->Add("Current Balance:" + IntToStr(inputValue));
  RichEdit2->Lines->Add("");

  if(inputValue >= nisab)
  {
	  totalZakat = inputValue*0.025;
	  RichEdit2->Lines->Add("You are eligible to give Zakat !");
	  RichEdit2->Lines->Add("Zakat: " + FloatToStr(totalZakat));
  }

  else
  {
	  RichEdit2->Lines->Add("You are not eligible to give Zakat.");
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button3Click(TObject *Sender)
{

   //Call the load function and populate the vectors
	UnicodeString year = Edit3->Text;
	loadPieData(ExpenseList,userledger,e_category,e_amount,1+ComboBox1->ItemIndex,StrToInt(year));
	loadPieData(IncomeList,incomeledger,i_category,i_amount,1+ComboBox1->ItemIndex,StrToInt(year));
	drawCharts(StrToInt(year),1+ComboBox1->ItemIndex);

	ShowMessage("List size" + IntToStr(static_cast<int>(ExpenseList.size())));
}


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm3::ScrollBox1MouseWheelDown(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled)
{
  ScrollBox1->VertScrollBar->Position += 50;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::ScrollBox1MouseWheelUp(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled)
{
  ScrollBox1->VertScrollBar->Position -= 50;

}
//---------------------------------------------------------------------------



void __fastcall TForm3::ComboBox1Change(TObject *Sender)
{

   //Call the load function and populate the vectors
	 UnicodeString year = Edit3->Text;
	 loadPieData(ExpenseList,userledger,e_category,e_amount,1+ComboBox1->ItemIndex,StrToInt(year));
	 loadPieData(IncomeList,incomeledger,i_category,i_amount,1+ComboBox1->ItemIndex,StrToInt(year));
	 drawCharts(StrToInt(year),1+ComboBox1->ItemIndex);

}
void __fastcall TForm3::ComboBox2Change(TObject *Sender)
{
	 //Call the load function and populate the vectors
	 UnicodeString year = Edit3->Text;
	 loadPieData(ExpenseList,userledger,e_category,e_amount,1+ComboBox1->ItemIndex,StrToInt(year));
	 loadPieData(IncomeList,incomeledger,i_category,i_amount,1+ComboBox1->ItemIndex,StrToInt(year));
	 drawCharts(StrToInt(year),1+ComboBox1->ItemIndex);
}
//---------------------------------------------------------------------------
//For creating custom dialogue boxes
void ShowFormattedText(TCustomSeries *Sender,UnicodeString L1,UnicodeString L2,TColor cl)
{
	// Create a new form
	TForm *MyForm = new TForm(Sender);

	// Create a TRichEdit component
	TRichEdit *RichEdit1 = new TRichEdit(MyForm);
	RichEdit1->Parent = MyForm;
	RichEdit1->Align = alClient;

	// Set formatted text
	RichEdit1->ReadOnly = True;
	RichEdit1->SelStart = 0;
	RichEdit1->SelLength = RichEdit1->Lines->Text.Length();
	RichEdit1->SelAttributes->Style = TFontStyles() << fsBold; // Set bold style
	RichEdit1->Lines->Add(L1);
	RichEdit1->SelAttributes->Style = TFontStyles() << fsBold;
	RichEdit1->SelAttributes->Color = cl;
	RichEdit1->Lines->Add(L2);
	// Show the form
	MyForm->Width  =  Form3->Width / 2;
	MyForm->Height = Form3->Height / 4;
	MyForm->Top = Form3->Chart3->Top + 50;
	MyForm->Left = Form3->Left + Form3->Left/3;
	MyForm->ShowModal();

	// Clean up
	delete MyForm;
}

void __fastcall TForm3::Series3ClickPointer(TCustomSeries *Sender, int ValueIndex,
          int X, int Y)
{
   if(ValueIndex == 0)
	 return;
   double xValue = Sender->XValues->Value[ValueIndex];
   double yValue = Sender->YValues->Value[ValueIndex];
   double xValue_prevMonth = Sender->XValues->Value[ValueIndex-1] -1;
   double yValue_prevMonth = Sender->YValues->Value[ValueIndex-1];

   double chng = yValue - yValue_prevMonth;

   UnicodeString info_cmp = "";
   if(ComboBox2->ItemIndex == 0){
   UnicodeString info_avg = " Month = " + FormatSettings.LongMonthNames[xValue] + ", Average Income = " + FloatToStr(yValue) + " TK";


   if(chng < 0)
   {
	  info_cmp = "Average income has decreased by " + FloatToStr(abs(chng)) + " Tk since last month";
	  ShowFormattedText(Sender,info_avg,info_cmp,clRed);
   }
   else if (chng == 0)
   {
	  info_cmp = "Average income has remained unchanged";
	   ShowFormattedText(Sender,info_avg,info_cmp,clGreen);
   }
   else
   {
	  info_cmp = "Average income has increased by " + FloatToStr(abs(chng)) + " Tk since last month";
	   ShowFormattedText(Sender,info_avg,info_cmp,clGreen);
   }

   }

   else if(ComboBox2->ItemIndex == 1){
   UnicodeString info_avg = " Month = " + FormatSettings.LongMonthNames[xValue] + ", Total Income = " + FloatToStr(yValue) + " TK";


   if(chng < 0)
   {
	  info_cmp = "Total income has decreased by " + FloatToStr(abs(chng)) + " Tk since last month";
	  ShowFormattedText(Sender,info_avg,info_cmp,clRed);
   }
   else if (chng == 0)
   {
	  info_cmp = "Total income has remained unchanged";
	   ShowFormattedText(Sender,info_avg,info_cmp,clGreen);
   }
   else
   {
	  info_cmp = "Total income has increased by " + FloatToStr(abs(chng)) + " Tk since last month";
	   ShowFormattedText(Sender,info_avg,info_cmp,clGreen);
   }

   }


}
//---------------------------------------------------------------------------

void __fastcall TForm3::Series4ClickPointer(TCustomSeries *Sender, int ValueIndex,
          int X, int Y)
{

   if(ValueIndex == 0)
	 return;

   double xValue = Sender->XValues->Value[ValueIndex] - 1;
   double yValue = Sender->YValues->Value[ValueIndex];

   double xValue_prevMonth = Sender->XValues->Value[ValueIndex-1] -1;
   double yValue_prevMonth = Sender->YValues->Value[ValueIndex-1];

   double chng = yValue - yValue_prevMonth;

   UnicodeString info_cmp = "";

   if(ComboBox2->ItemIndex == 0){
   UnicodeString info_avg = " Month = " + FormatSettings.LongMonthNames[xValue] + ", Average Expense = " + FloatToStr(yValue) + " TK";

   if(chng < 0)
   {
	  info_cmp = "Average expense has decreased by " + FloatToStr(abs(chng)) + " Tk since last month";
	  ShowFormattedText(Sender,info_avg,info_cmp,clGreen);
   }
   else if (chng == 0)
   {
	  info_cmp = "Average expense has remained unchanged";
	   ShowFormattedText(Sender,info_avg,info_cmp,clGreen);
   }
   else
   {
	  info_cmp = "Average expense has increased by " + FloatToStr(abs(chng)) + " Tk since last month";
	   ShowFormattedText(Sender,info_avg,info_cmp,clRed);
   }

   }

   else if(ComboBox2->ItemIndex == 1){
   UnicodeString info_avg = " Month = " + FormatSettings.LongMonthNames[xValue] + ", Total Expense = " + FloatToStr(yValue) + " TK";

   if(chng < 0)
   {
	  info_cmp = "Total expense has decreased by " + FloatToStr(abs(chng)) + " Tk since last month";
	  ShowFormattedText(Sender,info_avg,info_cmp,clGreen);
   }
   else if (chng == 0)
   {
	  info_cmp = "Total expense has remained unchanged";
	   ShowFormattedText(Sender,info_avg,info_cmp,clGreen);
   }
   else
   {
	  info_cmp = "Total expense has increased by " + FloatToStr(abs(chng)) + " Tk since last month";
	   ShowFormattedText(Sender,info_avg,info_cmp,clRed);
   }

   }


	// Display a popup or perform any other action with xValue and yValue
	//ShowMessage(" Month = " + FormatSettings.LongMonthNames[xValue] + ", Average Expense = " + FloatToStr(yValue) + " TK");
}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------



void __fastcall TForm3::Chart4Scroll(TObject *Sender)
{
   regression r;
	update_regression_model(r);

	float m = r.coefficient();
	float c = r.constant();

		// Get the current drag position
		double dragX = Chart4->BottomAxis->CalcPosPoint(Mouse->CursorPos.x);
		double dragY = Chart4->LeftAxis->CalcPosPoint(Mouse->CursorPos.y);

		// Add a point to the series at the drag position
	   //	Series6->AddXY(dragX, dragY);

		// Optionally, add more points based on your logic
		for (double x = dragX - 1000; x < dragX + 10000; x += 1000)
		{
			double y = m * x + c;
			Series6->AddXY(x, y);
		}
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


void AddIncomeOperations()
{
	 IncomeRead.clear() ;

	 ifstream inputFile(incomeledger);

	if (!inputFile.is_open()) {
		ShowMessage("Failed to open the file.");
		return;
	}
	string line;
	 while(getline(inputFile,line))
	 {
	   if(line == "Start")
	   {
		   IncomeClass fileinput;

		   std::getline(inputFile,line);
		   //Read year and month
		   int year = std::stoi(line);
		   getline(inputFile,line);
		   int month = std::stoi(line);

		   //Set year and month for (class) entry
		   fileinput.Setyear(year);
		   fileinput.Setmonth(month);


		   while (std::getline(inputFile, line) && line != "End") {
				istringstream iss(line);
				int day, amount;
				std::string category;

				if (iss >> day >> category >> amount) {
					fileinput.Adddate(day);
					UnicodeString c = UnicodeString(category.c_str());
					fileinput.Addcategory(c);
					fileinput.Addamount(amount);
					IncomeClass::TotalIncome+=amount;
				}
			}
			IncomeRead.push_back(fileinput);
		   //	cout<<IncomeRead.size()<<endl;
		  // string p="This month has income sources : ";
		   //string s= to_string(IncomeRead.size());
			// p=p+s;
			// Memo1->Lines->Add("Hello");

	   }
	 }
	 inputFile.close();

}
   void AddNewIncomeEntry(UnicodeString Amount ,UnicodeString Source,UnicodeString Date,UnicodeString Month,UnicodeString Year)
   {
	   //ShowMessage("Function is being called");
	   int A =StrToInt(Amount);
	   int D =StrToInt(Date);
	   int M =StrToInt(Month);
	   int Y =StrToInt(Year);
	   for(int i=0;i<IncomeRead.size();i++)
		 {
			if(IncomeRead[i].Getmonth() == M && IncomeRead[i].Getyear() == Y)
			{
			 IncomeRead[i].Adddate(D);
			 IncomeRead[i].Addamount(A);
			 IncomeRead[i].Addcategory(Source);
			 break;
			}
		 }
		 SortIncome();
		 //ShowMessage("Received data " + Amount );
		 std::ofstream outFile(incomeledger);

	if (!outFile.is_open()) {
		ShowMessage("Cannot open file");
		return;
	}


	for ( auto& income : IncomeRead) {
		std::stringstream ss;

		// Start tag
		ss << "Start" << std::endl;

		// Year and Month
		ss << income.Getyear() << std::endl;
		ss << std::setfill('0') << std::setw(2) << income.Getmonth() << std::endl;

		// Data entries
		for (size_t i = 0; i < income.date.size(); ++i) {

			wstring wstr = income.category[i].c_str();
			string cat= string(wstr.begin(), wstr.end());
			ss << std::setw(2) << income.date[i] << " "
			   << cat << " "
			   << income.amount[i] << std::endl;
		}
		 //string(income.category[i].c_str())
		// End tag
		ss << "End" << std::endl;

		outFile << ss.str();
		if (outFile.fail())
		{
			std::cerr << "Error writing to the output file!" << std::endl;
			ShowMessage("Error writing to the output file.");
			outFile.close();  // Close the file before returning
			return;
		}
	}

	outFile.close();
	return;
   }
void __fastcall TForm3::Button5Click(TObject *Sender)
{

  if( Edit2->Text == ""||Edit4->Text == "" ||Edit5->Text == ""||Edit6->Text == "" || Edit5->Text == "")
  {
	  ShowMessage("Please Provide Valid Input In All Fields.");
  }
  else
  {
		AddIncomeOperations() ;
		UnicodeString Amount=Edit2->Text;
		UnicodeString Source=Edit7->Text;
		UnicodeString Date=Edit4->Text;
		UnicodeString Month=Edit5->Text;
		UnicodeString Year=Edit6->Text;
		AddNewIncomeEntry(Amount,Source,Date,Month,Year);
		ShowMessage("New entry added to your income");
  }
}
//---------------------------------------------------------------------------

void pop_up(TObject *Sender)
{

		// Create a new form
	TForm *MyForm = new TForm(Form3);
	MyForm->Caption = "Help";
	// Create a TRichEdit component
	TRichEdit *RichEdit1 = new TRichEdit(MyForm);
	RichEdit1->Parent = MyForm;
	RichEdit1->Align = alClient;

	// Set formatted text

	RichEdit1->ReadOnly = True;
	RichEdit1->SelStart = 0;
	RichEdit1->SelLength = RichEdit1->Lines->Text.Length();
	RichEdit1->SelAttributes->Style = TFontStyles() << fsBold; // Set bold style
	RichEdit1->Lines->Add("This is a prediction model based on your savings and expense record.");
	RichEdit1->SelAttributes->Style = TFontStyles() << fsBold;
	RichEdit1->SelAttributes->Color = clBlack;
	RichEdit1->Lines->Add("You can use this prediction model to estimate how much you must cut on your expenses to reach a targeted savings amount.");
    RichEdit1->SelAttributes->Style = TFontStyles() << fsBold;
	RichEdit1->SelAttributes->Color = clBlack;
	RichEdit1->Lines->Add("Estimated expense and income are based on this linear model.")   ;
	// Show the form
	MyForm->Width  =  Form3->Width / 2;
	MyForm->Height = Form3->Height / 4;
	MyForm->Top = Form3->Chart4->Top + 50;
	MyForm->Left = Form3->Left + Form3->Left/3;
	MyForm->ShowModal();

	// Clean up
	delete MyForm;
}

void __fastcall TForm3::MoreInfoClick(TObject *Sender)
{

		pop_up(Sender);

}
//---------------------------------------------------------------------------


void AddExpenseOperations()
{
	 ExpenseRead.clear() ;

	 ifstream inputExpenseFile(userledger);

	if (!inputExpenseFile.is_open()) {
		ShowMessage("Failed to open Ledger the file.");
		return;
	}
	string line;
	 while(getline(inputExpenseFile,line))
	 {
	   if(line == "Start")
	   {
		   ExpenseClass fileExpenseinput;

		   std::getline(inputExpenseFile,line);
		   //Read year and month
		   int year = std::stoi(line);
		   getline(inputExpenseFile,line);
		   int month = std::stoi(line);

		   //Set year and month for (class) entry
		   fileExpenseinput.Setyear(year);
		   fileExpenseinput.Setmonth(month);


		   while (std::getline(inputExpenseFile, line) && line != "End") {
				istringstream iss(line);
				int day, amount;
				std::string category;

				if (iss >> day >> category >> amount) {
					fileExpenseinput.Adddate(day);
					UnicodeString c = UnicodeString(category.c_str());
					fileExpenseinput.Addcategory(c);
					fileExpenseinput.Addamount(amount);
					//IncomeClass::TotalIncome+=amount;
				}
			}
			ExpenseRead.push_back(fileExpenseinput);
		   //	cout<<IncomeRead.size()<<endl;
		  // string p="This month has income sources : ";
		   //string s= to_string(IncomeRead.size());
			// p=p+s;
			// Memo1->Lines->Add("Hello");

	   }
	 }
	 inputExpenseFile.close();

}

 void AddNewExpenseEntry(UnicodeString exAmnt ,UnicodeString exCat,UnicodeString exDate,UnicodeString exMonth,UnicodeString exYear)
   {
	   //ShowMessage("Function is being called");
	   int A =StrToInt(exAmnt);
	   int D =StrToInt(exDate);
	   int M =StrToInt(exMonth);
	   int Y =StrToInt(exYear);
	   for(int i=0;i<ExpenseRead.size();i++)
		 {
			if(ExpenseRead[i].Getmonth() == M && ExpenseRead[i].Getyear() == Y)
			{
			 ExpenseRead[i].Adddate(D);
			 ExpenseRead[i].Addamount(A);
			 ExpenseRead[i].Addcategory(exCat);
			 break;
			}
		 }
		 //ShowMessage("Received data " + Amount );
		 std::ofstream outExpenseFile(userledger);

	if (!outExpenseFile.is_open()) {
		ShowMessage("Cannot open Ledger file");
		return;
	}


	for ( auto& exp : ExpenseRead) {
		std::stringstream ss;

		// Start tag
		ss << "Start" << std::endl;

		// Year and Month
		ss << exp.Getyear() << std::endl;
		ss << std::setfill('0') << std::setw(2) << exp.Getmonth() << std::endl;

		// Data entries
		for (size_t i = 0; i < exp.date.size(); ++i) {

			wstring wstr = exp.category[i].c_str();
			string cat= string(wstr.begin(), wstr.end());
			ss << std::setw(2) << exp.date[i] << " "
			   << cat << " "
			   << exp.amount[i] << std::endl;
		}
		 //string(income.category[i].c_str())
		// End tag
		ss << "End" << std::endl;

		outExpenseFile << ss.str();
		if (outExpenseFile.fail())
		{
			std::cerr << "Error writing to the output file!" << std::endl;
			ShowMessage("Error writing to the output file.");
			outExpenseFile.close();  // Close the file before returning
			return;
		}
	}

	outExpenseFile.close();
	return;
   }

void __fastcall TForm3::Button1Click(TObject *Sender)
{
 if( Edit8->Text == ""||Edit9->Text == "" ||Edit10->Text == ""||Edit11->Text == "" || Edit12->Text == "")
  {
	  ShowMessage("Please Provide Valid Input In All Fields.");
  }
  else
  {
		AddExpenseOperations() ;
		UnicodeString expenseAmnt=Edit8->Text;
		UnicodeString expenseCat=Edit9->Text;
		UnicodeString expenseDate=Edit10->Text;
		UnicodeString expenseMonth=Edit11->Text;
		UnicodeString expenseYear=Edit12->Text;
		AddNewExpenseEntry(expenseAmnt,expenseCat, expenseDate, expenseMonth, expenseYear);
		ShowMessage("New entry added to your Expense");
  }
}

  void EditIncomeEntry(UnicodeString Amount ,UnicodeString Source,UnicodeString Date,UnicodeString Month,UnicodeString Year)
   {
	   //ShowMessage("Function is being called");
	   int A =StrToInt(Amount);
	   int D =StrToInt(Date);
	   int M =StrToInt(Month);
	   int Y =StrToInt(Year);
	   int flag=0;
	   for(int i=0;i<IncomeRead.size();i++)
		 {
			if(IncomeRead[i].Getmonth() == M && IncomeRead[i].Getyear() == Y)
			{
			  for(int j=0;j< IncomeRead[i].category.size();j++)
			  {
				  if(IncomeRead[i].category[j]== Source && IncomeRead[i].date[j]== D)
				  {
					   flag++;
					   IncomeRead[i].amount[j]=A;
					   break;
				  }
			  }
			  break;
			}
		 }
		 if(flag==0)
		 {
			 ShowMessage("Record does not exist" );
			 return;
         }
		 //ShowMessage("Received data " + Amount );

		 std::ofstream outFile(incomeledger);

	if (!outFile.is_open()) {
		ShowMessage("Cannot open file");
		return;
	}


	for ( auto& income : IncomeRead) {
		std::stringstream ss;

		// Start tag
		ss << "Start" << std::endl;

		// Year and Month
		ss << income.Getyear() << std::endl;
		ss << std::setfill('0') << std::setw(2) << income.Getmonth() << std::endl;

		// Data entries
		for (size_t i = 0; i < income.date.size(); ++i) {

			wstring wstr = income.category[i].c_str();
			string cat= string(wstr.begin(), wstr.end());
			ss << std::setw(2) << income.date[i] << " "
			   << cat << " "
			   << income.amount[i] << std::endl;
		}
		 //string(income.category[i].c_str())
		// End tag
		ss << "End" << std::endl;

		outFile << ss.str();
		if (outFile.fail())
		{
			std::cerr << "Error writing to the output file!" << std::endl;
			ShowMessage("Error writing to the output file.");
			outFile.close();  // Close the file before returning
			return;
		}
	}

	outFile.close();
	return;
   }
//---------------------------------------------------------------------------
void __fastcall TForm3::Button4Click(TObject *Sender)
{
 if( Edit2->Text == ""||Edit4->Text == "" ||Edit5->Text == ""||Edit6->Text == "" || Edit5->Text == "")
  {
	  ShowMessage("Please Provide Valid Input In All Fields.");
  }
  else
  {
		AddIncomeOperations() ;
		UnicodeString Amount=Edit2->Text;
		UnicodeString Source=Edit7->Text;
		UnicodeString Date=Edit4->Text;
		UnicodeString Month=Edit5->Text;
		UnicodeString Year=Edit6->Text;
		EditIncomeEntry(Amount,Source,Date,Month,Year);
		ShowMessage("Requested Edit Completed");
  }

}

void __fastcall TForm3::Button6Click(TObject *Sender)
{
    TDateTime currentDate = Now();
	year = YearOf(currentDate);
	month = MonthOf(currentDate);
	day = DayOf(currentDate);
		Edit4->Text =day;
		Edit5->Text=month;
		Edit6->Text=year;
}
//---------------------------------------------------------------------------

