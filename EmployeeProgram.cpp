//Ahmed al-Mogeet
//employee Program
//comp150
//winter2015

#include <cstdlib>	//includes dynamic memory management, integer sorting, and searching
#include <iostream>	//used from cin&cout
#include <iomanip>	//design purposes.
#include <fstream>	//stream class to both read and write from/to files.
#include <string>	  
#include <sstream>

using namespace std;


struct EmployeeRes		//define a data structure
{
  string name, address, phoneNum, dep;
  
};


const int MAX_SIZE = 25;	//const for the max size of the record array


void Employee(EmployeeRes list[], int& size);
void dispData(const EmployeeRes list[], int size);
void openData(EmployeeRes list[], int& size);
void saveFile(const EmployeeRes list[], int size);
int binaryIndexOf(string target, EmployeeRes list[], int size);			// function prototypes
void sortEmp (EmployeeRes list[], int& size);
void deleteEmp(EmployeeRes list[], int& size);


char getMenuResponse();


int main(int argc, char *argv[])
{
  EmployeeRes recList[MAX_SIZE];
  int numOfRecs = 0;
  bool run = true;
  do
  {
     
       cout<<"*"<<" This is an inventory program to store employee information"<<" *"<<endl;
      
     
       cout<<"*                   "<< numOfRecs <<" number of employee"<<"                     "<<"*"<<endl;
      	
      switch ( getMenuResponse() ) 
  	{
  		case 'A': Employee(recList, numOfRecs); break;
  		case 'D': dispData(recList, numOfRecs); break;
  		case 'S': saveFile(recList, numOfRecs); break;
  		case 'O': openData(recList, numOfRecs); break;
  		case 'X': sortEmp (recList, numOfRecs); break;
  		case 'R': deleteEmp(recList, numOfRecs);break;
  		case 'Q': run = false; break;
  		default : cout << "That is NOT a valid choice" << endl;
  	}
  } while (run);
  cout << endl << "Program Terminated" << endl;
  
  
  return EXIT_SUCCESS; // Program exits immediatly upon "Quit" if commented out
}
char getMenuResponse()
// Task:     Put the menu on screen and get a response
// Accepts:  Nothing
// Returns:  The users response
// Modifies: Nothing

{
	char response;
         cout << endl << "Make your selection by choosing one letter" << endl;
	     cout<<""<<endl;
		 cout <<"(A)dd Employee"<<endl;
		 cout<<"---------------"<<endl;
         cout<<"(D)isplay List of Employee"<<endl;
         cout<<"--------------------------"<<endl;
         cout<<"(X)Sort Employee"<<endl;
         cout<<"----------------"<<endl;
         cout<<"(S)ave list"<<endl;
         cout<<"-----------"<<endl;
         cout<<"(O)pen Data"<<endl;
         cout<<"-----------"<<endl;
         cout<<"(R)emove Employee"<<endl;
         cout<<"-----------"<<endl;
         cout<<"(Q)uit" << endl;
         cout<<"------"<<endl
		 << "> ";
	cin >> response;
	cin.ignore(256, '\n');	
	// clean-up up to 256 chars including the delimiter specified (\n, the endl) 
	// OR stop when the \n is encountered after removing it.
	return toupper(response);

}

// Task:     Allow data entry of one inventory item
// Accepts:  References to the inventory array and its size
// Returns:  Nothing
// Modifies: The array and size 'actual parameter'
// NOTE:     Could be modified to allow entry of more than one item
void Employee(EmployeeRes list[], int& size)
{
  EmployeeRes tmp; // declare a temp item that we will load before putting in the array
  char response;
  char str[256];// needed for cin.getline; we are going to use a char array

  if (size < MAX_SIZE) {
    system("cls");
    cout<<"****************************************"<<endl;
    cout<<"*"<<"       Enter Employee information"<<"     *"<<endl;
    cout<<"****************************************"<<endl;
    //prompt user for Name
    cout<<" -Name:           ";
    cin.getline(str,256, '\n'); // To avoid buffer overflow 
    tmp.name = str;
    //prompt user for Address
    cout<<" -Address:        ";
    cin.getline(str,256, '\n'); 
    tmp.address = str;
    //prompt user for Number
    cout<<" -Phone number:   ";
    cin.getline(str,256, '\n');
    tmp.phoneNum = str;
    //prompt user for Department
    cout<<" -Department:     ";
    cin.getline(str,256, '\n');
    tmp.dep = str;
    cout << endl;
    cout<<"****************************************"<<endl;
    cout << "Add the record to inventory? (y/n) ";
    cin >> response;cout;
    if (toupper(response) == 'Y')
      list[size++] = tmp;
  } else {
    cout << "Phonebook at max; cannot enter more contacts." << endl;
    system("pause");
  }
  system("cls");
}

const int COLS = 4;

void dispData(const EmployeeRes list[], int size)
{
  system("cls");
  double cost = 0;
  
  if(size < 1) {
    cout << "Nothing to display" << endl;
  } else {
    cout << "Listing Contacts" << endl << endl;
    cout << fixed << setprecision(2);   
    cout << "# Name                Address             Phone Number         Departmen" << endl;
    cout << "_____________________________________________________________________________" << endl; 
    cout << left;     
    for (int i = 0; i < size; i++)
     {    
          cout  << setw(2)<< i+1 << right
                << setw(5)<< list[i].name<<setw(10)
                << setw(19)<< list[i].address<< setw(10)
                << setw(19)<< list[i].phoneNum
                << setw(19)<< list[i].dep
                << left << endl;                     }
    cout << "_____________________________________________________________________________" << endl;
    cout << right << setw(3)<<"There is "<< size<<" employee in this list"<<endl;
  }
  
  system("PAUSE");
  system("cls");
}

int binaryIndexOf(string target, EmployeeRes list[], int size) {
 
  int lo = 0, hi = size - 1, mid;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (list[mid].name == target) return mid; // found it
    if (list[mid].name <  target) lo = mid+1; // continue in arr[mid+1..hi]
    else hi = mid-1;                    // continue in arr[lo..mid-1]
  }
  return -1;  // target was not found in arr[0..size-1]
}

void sortEmp (EmployeeRes list[], int& size)
{
     if ( size == 0) cout << "empty";
     else 
     {
         for (int i = 1; i < size; i++){
           for (int j = 0; j < size - i; j++) {
             if (list[j].name > list[j+1].name)
			 {
			 swap(list[j].name, list[j+1].name);
			 swap(list[j].address, list[j+1].address);
			 swap(list[j].phoneNum, list[j+1].phoneNum);
			 swap(list[j].dep, list[j+1].dep);
           }
         }
     }
}
}

// Save records to disc
void saveFile(const EmployeeRes list[], int size) {
  ofstream outfi("EmployeeList.dat");
  
  // make sure the file stream is open before doing IO
  if (!outfi.fail()) { 
    system("cls");  
    cout << "Saving inventory to the disc ";
    
    for(int i = 0; i < size; i++) {
      outfi << list[i].name     << ';' 
            << list[i].address  << ';'
            << list[i].phoneNum << ';'
            << list[i].dep;
      // Start a new line after all but the last record
      // Simplifies reading the file as EOF is at end of last line
      if (i < size-1) outfi << endl;
    }
    cout << endl << size << " records writen to the disc." << endl;
    outfi.close();
    system("PAUSE");
    system("cls");
  } 
  else {
    cout << "ERROR: problem with file" << endl;
    cout<<"Please Save File before attempting to open"<<endl;
    system("PAUSE");
    system("cls");
  }
}
void openData(EmployeeRes list[], int& size)
{
	string filename;
	{
		cout << "enter the file name you want to open:";
		cin >> filename;
  		ifstream fin(filename.c_str()); // declare an if stream object that creates a connection with an ev=xternal file so we can read from the file
		string str;						// - variable used to hold a string data type
 	 	stringstream ss;		
 	 	
	     
  
  // make sure the file stream is open before doing IO
  if (!fin.fail())
   { 
   
      system("cls");
      
      cout << "Getting data from the record ";
    
      size = 0; // overwrite any existing records
      while(!fin.eof() && size < MAX_SIZE) {
      // get and store the name
      getline(fin, str, ';'); 
      list[size].name = str;
      
      // get, convert and store the quantity
      getline(fin, str, ';');
      ss.str(""); ss.clear(); // empty and clear the stringstream
      ss << str; 
      ss >> list[size].address;
      
      // get, convert and store the cost
      getline(fin, str); 
      ss.str(""); ss.clear(); // empty and clear the stringstream
      ss << str; 
      ss >> list[size++].phoneNum;
    }
        cout << endl << size << " records read from the disc." << endl;
  
       
  }
  else 
      { // something went wrong with opening the file
        cout << "ERROr: File does not exist" << endl;
       
      }
}
}


void deleteEmp(EmployeeRes list[], int& size){
	dispData(list, size);
	int num = 0;
	string input = "";
	cout << "Choose an employee by number: ";
	cin >> input;
 	stringstream ss;
 	ss >> input;
	ss << num; 	
	
	for (int i = num; i < size; i++)
		list[num] = list[num+1];
	size--;	
}
