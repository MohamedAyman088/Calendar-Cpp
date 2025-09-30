#include <iostream>
#include <string>
#include <limits>
#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif
using namespace std;

void ClearScreen()
{
#ifdef _WIN32
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD count;
  DWORD cellCount;
  COORD homeCoords = { 0, 0 };

  if (hConsole == INVALID_HANDLE_VALUE) return;
  if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;

  cellCount = csbi.dwSize.X * csbi.dwSize.Y;

  if (!FillConsoleOutputCharacter(hConsole, (TCHAR)' ', cellCount, homeCoords, &count)) return;
  if (!FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellCount, homeCoords, &count)) return;

  SetConsoleCursorPosition(hConsole, homeCoords);
#else
  system("clear");
#endif
}

void Pause(bool Print = true)
{
  if (Print)
    cout << "\nPress Enter to continue...";
  cin.ignore();
  cin.get();
}

void ShowMainMenue();

bool isLeapYear(short Year)
{
  // if year is divisible by 4 AND not divisible by 100
  // OR if year is divisible by 400
  // then it is a leap year
  return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short DayOfWeekOrder(short Year, short Month, short Day)
{
  short a, y, m;
  a = (14 - Month) / 12;
  y = Year - a;
  m = Month + (12 * a) - 2;

  return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(short DayOrder)
{
  string arrDaysShortName[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
  return arrDaysShortName[DayOrder];
}

short ReadYear()
{
  short Year = 0;
  cout << "\nPlease Enter a Year? ";
  cin >> Year;
  return Year;
}

short ReadMonth()
{
  short Month = 0;
  cout << "\nPlease Enter a Month? ";
  cin >> Month;
  return Month;
}

string MonthNumberToName(short Month)
{
  string arrMonthNames[] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
  };

  return arrMonthNames[Month - 1];
}

short NumberOfDaysInAMonth(short Year, short Month)
{
  if (Month == 2)
  {
    return isLeapYear(Year) ? 29 : 28;
  }

  short arr30Day[] = { 4,6,9,11 };
  for (int i : arr30Day)
  {
    if (Month == i)
      return 30;
  }
  return 31;
}

void PrintMonthCalendar(short Year, short Month)
{
  short NumberOfDays = NumberOfDaysInAMonth(Year, Month);
  short FirstDayOfMonth = DayOfWeekOrder(Year, Month, 1);
  printf("\n   __________________%s__________________\n\n", MonthNumberToName(Month).c_str());
  cout << "   Sun   Mon   Tuh   Wed   Thu   Fri   Set\n";


  short i;
  for (i = 0; i < FirstDayOfMonth; i++)
    cout << "      ";

  for (int j = 1; j <= NumberOfDays; j++)
  {
    printf("%6d", j);
    if (++i == 7)
    {
      i = 0;
      cout << "\n";
    }
  }
  cout << "\n   _______________________________________\n";
}

void PrintYearCalendar(short Year)
{
  cout << "\n   _______________________________________\n";
  cout << "\n           Calendar - " << Year;
  cout << "\n   _______________________________________\n\n";

  for (int Month = 1; Month <= 12; Month++)
  {
    PrintMonthCalendar(Year, Month);
  }
}

void MonthCalendar()
{
  short Year = ReadYear();
  short Month = ReadMonth();
  PrintMonthCalendar(Year, Month);
}

void YearCalendar()
{
  short Year = ReadYear();
  PrintYearCalendar(Year);
}

void ShowEndScreen()
{
  cout << "\n-----------------------------------\n";
  cout << "\tProgram Ends :-)";
  cout << "\n-----------------------------------\n";
}

void GoBackToMainMenue()
{
  cout << "\n\nPress Enter to go back to Main Menue...";
  Pause(false);
  ShowMainMenue();
}

enum enMainMenueOptions
{
  enMonthCalendar = 1, enYearCalendar = 2, enExit = 3
};

short ReadMainMenueOption()
{
  cout << "\nChoose what do you want to do? [1 to 3]? ";
  short option;
  cin >> option;
  while (option > 3 || option < 1)
  {
    cout << "Invalid input. Please try again.\n";
    cout << "\nChoose what do you want to do? [1 to 3]? ";
    cin >> option;
  }
  return option;
}

void PerfromMainMenueOption(short option)
{
  switch (option)
  {
  case enMainMenueOptions::enMonthCalendar:
    ClearScreen();
    MonthCalendar();
    GoBackToMainMenue();
    break;

  case enMainMenueOptions::enYearCalendar:
    ClearScreen();
    YearCalendar();
    GoBackToMainMenue();
    break;

  case enMainMenueOptions::enExit:
    ClearScreen();
    ShowEndScreen();
    break;
  }
}

void ShowMainMenue()
{
  ClearScreen();
  cout << "===========================================\n";
  cout << "\t\tMain Menue Screen\n";
  cout << "===========================================\n";
  cout << "[1] Month Calendar\n";
  cout << "[2] Year Calendar\n";
  cout << "[3] Exit\n";
  cout << "===========================================\n";

  enMainMenueOptions option = (enMainMenueOptions)ReadMainMenueOption();
  PerfromMainMenueOption(option);
}

int main()
{
  ShowMainMenue();

  Pause();
  return 0;
}
