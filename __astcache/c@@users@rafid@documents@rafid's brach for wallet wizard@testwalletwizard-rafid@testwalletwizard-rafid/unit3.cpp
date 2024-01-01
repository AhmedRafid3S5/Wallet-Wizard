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

#define userledger "ledger.txt"
#define incomeledger "incomes.txt"
#define Total_Tabs 4

#include "Unit3.h"
#include "Regression.h"

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

std::vector<UnicodeString> e_category;
std::vector<int> e_amount;

std::vector<UnicodeString> i_category;
std::vector<int> i_amount;

int randomGlobalVar;

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
	Chart2->Top = 50 + Chart1->Top + Chart1->Height;
	Chart3->Top = Chart2->Top + Chart2->Height;
	Chart4->Top = Chart3->Top + Chart3->Height;
   //Set Tab size (Initializer)
	 PageControl1->TabWidth = PageControl1->ClientWidth/Total_Tabs - 1;
   //Set ScrollBar Limit (Initializer)

   //Load File function calls
   loadGoldFile();


}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	ShowMessage("Button Clicked");

	   // URL of the webpage
	std::string url = "https://www.islamicfinder.org/world/bangladesh/1185241/dhaka-prayer-times/";

	// Create a file stream to store the webpage content
	std::ofstream webpageFile("webpage.html");

	if (!webpageFile.is_open()) {
		std::cerr << "Failed to open the file for writing." << std::endl;

	}

	// Use system command to fetch the webpage content and write it to the file
	std::string command = "curl -s -o webpage.html " + url;
	if (system(command.c_str()) != 0) {
		std::cerr << "Failed to fetch the webpage." << std::endl;
		webpageFile.close();

	}

    webpageFile.close();

    // Open the downloaded file for parsing
	std::ifstream file("webpage.html");
    if (!file.is_open()) {
		std::cerr << "Failed to open the file for reading." << std::endl;

    }

    std::string line;
    std::string content;
    while (std::getline(file, line)) {
		content += line;
	}
    file.close();

    // Find the positions of "Fajar Prayer Time" and "Maghrib Prayer Time"
    size_t fajarPos = content.find("Fajar Prayer Time");
	size_t maghribPos = content.find("Maghrib Prayer Time");
	UnicodeString fajarTime;
	UnicodeString maghribTime;
	std::string fT;
	std::string mT;
    if (fajarPos != std::string::npos && maghribPos != std::string::npos) {
        // Extract the Fajar and Maghrib times
		fT = content.substr(fajarPos + 17, 9); // Assuming the time format is HH:MM AM/PM
		mT = content.substr(maghribPos + 19, 9);

		fajarTime = content.substr(fajarPos + 17, 9); // Assuming the time format is HH:MM AM/PM
		 maghribTime = content.substr(maghribPos + 19, 9);


		//std::cout << "Fajar Prayer Time: " << fajarTime << std::endl;
		//std::cout << "Maghrib Prayer Time: " << maghribTime << std::endl;


    } else {
        std::cerr << "Fajar and Maghrib times not found in the webpage content." << std::endl;
	}

	RichEdit1->PlainText = true;
		RichEdit1->Lines->Text =  "Fajar Time:" + fajarTime+"\n";
		RichEdit1->Lines->Add( "Maghrib Time:" + maghribTime +"\n");

	int mh,mm,fh,fm; //mh = maghrib hour mm = maghrib minute fh = fajr hour fm = fajr minute

	 fh = (fT[1]-'0')*10 + (fT[2]-'0');
	 fm = (fT[4]-'0')*10 + (fT[5]-'0');

	 mh = (((mT[1]-'0')*10 + (mT[2]-'0'))+12)%24;
	 mm = (mT[4]-'0')*10 + (mT[5]-'0');

    int last_time= ((60*mh+mm)+(60*fh+fm))/2;
	int ih= last_time/60;
	int im= last_time%60;

    // Convert ih and im to strings
UnicodeString ihStr = IntToStr(ih);
UnicodeString imStr = IntToStr(im);


	if(ih>=12 && im<10)
		//printf("Isha last time is : %d:0%d am",ih,im);
		RichEdit1->Lines->Add(  "Last Time:" + ihStr +":0" + imStr + "am") ;

	else if (ih>=12 && im>10)
		//printf("Isha last time is : %d:%d am",ih,im);
		RichEdit1->Lines->Add ( "Last Time:" + ihStr +":" + imStr + "am") ;

	else if(ih<12 && im<10)
		//printf("Isha last time is : %d:0%d pm",ih,im);
		RichEdit1->Lines->Add( "Last Time:" + ihStr +":0" + imStr + "pm" );

    else
		//printf("Isha last time is : %d:%d pm",ih,im);
		RichEdit1->Lines->Add("Last Time:" + ihStr +":" + imStr + "pm") ;
}

//---------------------------------------------------------------------------




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

	for(int i=0;i<ExpenseList.size();i++)
	{
	   Transaction_Summary<UnicodeString,int> entry = IncomeList[i];
	   double monthAvg =  entry.return_avg();
	   int month = entry.getMonth();
	   UnicodeString m = FormatSettings.ShortMonthNames[month-1] ;
	   Series3->AddXY(i+1,monthAvg,m);
	}

	// Add data points for average expense

	for(int i=0;i<ExpenseList.size();i++)
	{
	   Transaction_Summary<UnicodeString,int> entry = ExpenseList[i];
	   double monthAvg =  entry.return_avg();
	   int month = entry.getMonth();
	   UnicodeString m = FormatSettings.ShortMonthNames[month-1] ;
	   Series4->AddXY(i+1,monthAvg,m);
	}

	}

	else if(ComboBox2->ItemIndex == 1)
	{
	    Chart3->Title->Caption="Transaction summations over the months";
		Series3->LegendTitle = "Total_Income";
		Series4->LegendTitle = "Total_Expense";

	for(int i=0;i<ExpenseList.size();i++)
	{
	   Transaction_Summary<UnicodeString,int> entry = IncomeList[i];
	   double monthTotal =  entry.return_total();
	   int month = entry.getMonth();
	   UnicodeString m = FormatSettings.ShortMonthNames[month-1] ;
	   Series3->AddXY(i+1,monthTotal,m);
	}

	// Add data points for average expense

	for(int i=0;i<ExpenseList.size();i++)
	{
	   Transaction_Summary<UnicodeString,int> entry = ExpenseList[i];
	   double monthTotal =  entry.return_total();
	   int month = entry.getMonth();
	   UnicodeString m = FormatSettings.ShortMonthNames[month-1] ;
	   Series4->AddXY(i+1,monthTotal,m);
	}
	}

	//Linear regression model

	Chart4->Title->Caption = "Expense V Savings Forecasting";
	Series5->Clear();
	Series6->Clear();

	for(int i=0;i<ExpenseList.size();i++)
	{
		float y = ExpenseList[i].return_total();
		float x = IncomeList[i].return_total() - y;

		Series5->AddXY(x,y);
    }

	regression r;
	update_regression_model(r);

	float m = r.coefficient();
	float c = r.constant();


   // Add points to the series based on the equation y = ax + b
   for (double x =r.get_min_X()-1000; x <r.get_max_X()+10000; x += 1000) {
	double y = m * x + c;
	Series6->AddXY(x, y);

   }




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

	 //Testing with Memo  (Can have more multiline texts)
	 /* Memo1->Clear();
	  Memo1->SelStart = 0;
	  Memo1->SelLength = 37;
	  //Memo1->SetColor();
	  Memo1->Lines->Add( "Eligibility Criteria for giving Zakat");
	  Memo1->Lines->Add("Annual saving >= " + moneyThreshold);
	  //Memo1->Left = 10;
	  //Memo1->Top = 100;
	  Memo1->ReadOnly = true;  */

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

/*void __fastcall TForm3::ScrollBar1Change(TObject *Sender)
{
  Chart1->Top = -50* ScrollBar1->Position;
  Chart2->Top = -50* ScrollBar1->Position + 500;
  Chart3->Top = Chart2->Top + Chart2->Height;

}*/
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

void __fastcall TForm3::Button4Click(TObject *Sender)
{
 ShowMessage("2nd Button Pressed");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button5Click(TObject *Sender)
{
 ShowMessage("Tracker Button pressed");
}
//---------------------------------------------------------------------------

