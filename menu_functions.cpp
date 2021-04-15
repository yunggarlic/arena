#include <iostream>

using namespace std;

void about()
{
  char choice;
  cout << "==========================" << endl;
  cout << "========Created by========" << endl;
  cout << "==========================" << endl;
  cout << "========Tim Ferrari=======" << endl;
  cout << "==========2021============" << endl;
  cout << "==========================" << endl;
  cout << "==Type Any Key To Return==" << endl;
  cout << "==========================" << endl;
  cin >> choice;
}

int main_menu()
{
  char choice;
  while (choice != '3')
  {
    cout << "==========================" << endl;
    cout << "===Welcome to the Arena===" << endl;
    cout << "==========================" << endl;
    cout << "====------------------====" << endl;
    cout << "====-----1) Play------====" << endl;
    cout << "====-----2) About-----====" << endl;
    cout << "====-----3) Quit------====" << endl;
    cout << "==========================" << endl;
    cout << "==========================" << endl;

    cin >> choice;
    switch (choice)
    {
    case '1':
      return 1;
      break;
    case '2':
      about();
      continue;
    case '3':
      return 3;
      break;
    default:
      cout << "Invalid selection";
      continue;
    }
  }
  return 0;
}
