#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
using namespace std;

struct Person
{
	string name;
	string surname; 
	short age;
	string telephone;
};

Person people[20];

short peopleInDataBase;

void requireEnter(); //require to continue the program
void addPerson();
void showPeople();
void savePeopeleToFile();
void loadPeopleFromFile();
void searchDatabase();
void removePersonFromDAta();
 
int main()
{
	char test;
	do {
		cout << "Number of people in DataBase: " <<peopleInDataBase<<endl;
		cout << "MENU: " << endl;
		cout << "1. Add Person " << endl;

		cout << "2. Show All People " << endl;
		
		cout <<"3. save Peopele To File"<<endl;
		cout<<"4. Load People From file"<<endl;
		cout<<"5. Search for a person"<<endl;
		cout<<"6. Remove Person From DataBase"<<endl;
		test = _getch();
		switch (test)
		{
		case '1':
			addPerson();
			break;
		case '2':
		showPeople();
		cout<<endl;
			break;
		case '3':
		savePeopeleToFile();
			break;
			
		case '4':
		loadPeopleFromFile();
		break;
			case '5':
              searchDatabase();
 		break;
 		case '6':
 			removePersonFromDAta();
 			break;
		default:
			cout << "choice not available";
			break;
		}
		requireEnter();
			system("cls"); // clear the screen
		
	} while (test != 27); // passing key strock  code 27 for escape 
	cin.get();
	return 0;
}

void requireEnter() {
	cout << "press Enter to continue..."<<endl;
	while (_getch() != 13);
}
void addPerson() {
	cout << "Enter Name: ";
	cin >> people[peopleInDataBase].name;
	cout << "Enter surname: ";
	cin >> people[peopleInDataBase].surname;
	cout << "Enter age: ";
	cin >> people[peopleInDataBase].age;
	cout << "Enter telephone: ";
	cin >> people[peopleInDataBase].telephone;
	peopleInDataBase++;

 }
 
 void showPeople(){
 	   if(peopleInDataBase > 0)
 	   {  for (int i = 0;i<peopleInDataBase;i++){
 	   	cout<<"Person index: "<< (i+1)<<endl; 
 	   	cout<<"Name: "<<people[i].name<<endl;
 	   	cout<<"Surname: "<<people[i].surname<<endl;
 	   	cout<<"Age: "<<people[i].age<<endl;
 	   	cout<<"Telephone: "<<people[i].telephone<<endl<<endl;
		}
 	   	
		}
		else {
			cout<<"There is nobody in database."<<endl;
		}
 	   
 	   
 }  
 void savePeopeleToFile()
 {
 	
 	ofstream file("database.txt");
 	if (file.is_open()){
 		
 			file<<peopleInDataBase<<endl; 
 			
 		 for (int i = 0;i<peopleInDataBase;i++){
 	   
 	   	file<<people[i].name<<endl;
 	   	file<<people[i].surname<<endl;
 	   	file<<people[i].age<<endl;
 	   	file<<people[i].telephone<<endl;
 	   }
 		
 		file.close();
	 }
	 else cout<<"I couldnt save data. "<<endl;
 }
 
 
void loadPeopleFromFile()
{
	
	ifstream file("database.txt");
	
	
	if(file.is_open())
	{
		file >> peopleInDataBase;
		
		if(peopleInDataBase > 0){
			
//			for(int i = 0 ;i< peopleInDataBase;i++){
//				
//		file>>people[i].name;
// 	   	file>>people[i].surname;
// 	   	file>>people[i].age;
// 	   	file>>people[i].telephone;	
//				
//			}
int i = 0;
do
{
				
	file>>people[i].name;
   	file>>people[i].surname;
  	file>>people[i].age;
   	file>>people[i].telephone;
   	i++;
		}while(!file.eof());
					cout<<"People were loaded properly. "<<endl;
}
		else cout<<"DataBase is Empty"<<endl;
	}
	else{
		cout<<"The file database.txt doen't exist"<<endl;
	}
}
 
 void searchDatabase(){
 	if (peopleInDataBase > 0){
 		  string name;
 		  cout<<"Type a name of person you want to look for:  ";
 		  cin>>name;
 		  for(int i = 0;i< peopleInDataBase; i++){
 		  	if (name == people[i].name){
 		  		
 		  		 	cout<<"Person index: "<< (i+1)<<endl; 
 	   	cout<<"Name: "<<people[i].name<<endl;
 	   	cout<<"Surname: "<<people[i].surname<<endl;
 	   	cout<<"Age: "<<people[i].age<<endl;
 	   	cout<<"Telephone: "<<people[i].telephone<<endl<<endl;
		}
			   }
		   }
	 
	 else cout<<"Database is empty what do you want to look for?" <<endl;
 }
 
 
 
 void removePersonFromDAta(){
 	if (peopleInDataBase > 0 ){
 		short index;
 		cout<< "Who do you want to remove? Type index: ";
 		cin>> index;
 		if(peopleInDataBase >= index){
 			for(short k = index; k < peopleInDataBase ; k++){
 				
 				people[k-1].name = people[k].name;
 				people[k-1].surname = people[k].surname;
 				people[k-1].age = people[k].age;
 				people[k-1].telephone = people[k].telephone;
			 }
			 peopleInDataBase--;
			 savePeopeleToFile();
		 }
		 else cout<<"There is nobody with that index"<<endl;
	 }
	 else cout<<"There is nothing to remove"<<endl;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
