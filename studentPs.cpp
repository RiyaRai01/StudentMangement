#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<string>
#include<conio.h>
#include<stdio.h>

using namespace std;
class student{
private:
  string name,roll_no,course,address,email_id,contact_no;
public:
  void menu();
  void insert();
  void display();
  void modify();
  void search();
  void deleteRecord();
  
};
void student::menu(){
    menustart:
int choice;
char x;
system("cls");
cout<<"\t\t\t\t............................................."<<endl;
cout<<"\t\t\t\t........| STUDENT MANAGEMENT SYSTEM |........"<<endl;
cout<<"\t\t\t\t............................................."<<endl;
cout<<"\t\t\t\t 1.Enter New Record"<<endl;
cout<<"\t\t\t\t 2.Display Record"<<endl;
cout<<"\t\t\t\t 3.Modify Record"<<endl;
cout<<"\t\t\t\t 4.Search Record"<<endl;
cout<<"\t\t\t\t 5.Delete Record"<<endl;
cout<<"\t\t\t\t 6.Exit "<<endl;

cout<<"\t\t\t\t............................................."<<endl;
cout<<"\t\t\t\t.......Choose option [1/2/3/4/5]............"<<endl;
cout<<"\t\t\t\t............................................"<<endl;
cout<<"Enter your choice :: ";
cin>>choice;
switch(choice){
    case 1:
    do{
    insert();
        cout<<"\t\t\t\t Add another student Record(Y,N)";
        cin>>x;
    }
    while(x=='y'||x=='Y');
    break;
    case 2:
    display();
    break;
    case 3:
    modify();
    break;
    case 4:
    search();
    break;
    case 5:
    deleteRecord();
    break;
    case 6:
       exit(0);
    default:
    cout<<"\t\t\t\t Invalid choice...Please try again";
    break;
    getch();
    goto menustart;
}
}
void student :: insert(){
    system("cls");
    fstream file;
    cout<<"......................................................................................................"<<endl;
    cout<<"......................................ADD STUDENT DETAILS............................................."<<endl;
    cout<<"......................................................................................................"<<endl;
    cout<<"\t\t\t\t Enter the Name: ";
    cin>>name;
    cout<<"\t\t\t\t Enter the Roll No: ";
    cin>>roll_no;
    cout<<"\t\t\t\t Enter the Course: ";
    cin>>course;
    cout<<"\t\t\t\t Enter the Address: ";
    cin>>address;
    cout<<"\t\t\t\t Enter the Email:";
    cin>>email_id;
    cout<<"\t\t\t\t Enter the Contact No: ";
    cin>>contact_no;
    file.open("studentRecord.txt",ios::app | ios::out);
    file<<" "<<name<<" "<<roll_no<<" "<<course<<" "<<address<<" "<<email_id<<" "<<contact_no<<"\n";
    file.close();

}
void student::display(){
  system("cls");
  fstream file;
  int total = 0;
   cout<<"......................................................................................................"<<endl;
   cout<<"...................................... STUDENT RECORD TABLE............................................."<<endl;
   cout<<"......................................................................................................"<<endl;
   file.open ("studentRecord.txt",ios::in);
   if(!file){
     cout<<"\t\t\t\t No Data Is Present....";
     file.close();
   }
   else{
     file>>name>>roll_no>>course>>email_id>>contact_no>>address;
     while(!file.eof()){
       cout<<"\t\t Student No." << total++<<endl;
       cout<<"\t\t\t Student Name." <<name<<endl;
       cout<<"\t\t\t Student Roll No." <<roll_no<<endl;
       cout<<"\t\t\t Student Course" << course<<endl;
       cout<<"\t\t\t Student Email Id" <<email_id<<endl;
       cout<<"\t\t\t Student Contact No" <<contact_no<<endl;
       cout<<"\t\t\t Student Address" <<address<<endl;
       file>>name>>roll_no>>course>>email_id>>contact_no>>address;
      }
      if(total == 0){
         cout<<"\t\t\t\t No Data Is Present....";
      }
   }
      file.close();
}
void student :: modify(){
  system("cls");
  fstream file,file1;
  string rollno;
  int found = 0;
  cout<<"..........................................................................."<<endl;
  cout<<".............................Student Modify Details........................"<<endl;
  cout<<"............................................................................"<<endl;
  file.open("studentRecord.txt",ios::in);
  if(!file){
    cout<<"\n\t\t\t No Data is Present...";
    
  }
  else{
    cout<<" Enter the Roll No. of student which you want to  modify"<<endl;
    cin>>rollno;
    file1.open("Record.txt",ios::app | ios::out);
     file>>name>>roll_no>>course>>address>>email_id>>contact_no;
     while(!file.eof()){
       if(rollno != roll_no){
      file<<" "<<name<<" "<<roll_no<<" "<<course<<" "<<address<<" "<<email_id<<" "<<contact_no<<"\n";

       }
       else
       {
        cout<<"\t\t\t\t Enter the Name: ";
        cin>>name;
        cout<<"\t\t\t\t Enter the Roll No: ";
        cin>>roll_no;
        cout<<"\t\t\t\t Enter the Course: ";
        cin>>course;
        cout<<"\t\t\t\t Enter the Address: ";
        cin>>address;
        cout<<"\t\t\t\t Enter the Email:";
        cin>>email_id;
        cout<<"\t\t\t\t Enter the Contact No: ";
        cin>>contact_no;
        file<<" "<<name<<" "<<roll_no<<" "<<course<<" "<<address<<" "<<email_id<<" "<<contact_no<<"\n";
        found++;
       }
       file>>name>>roll_no>>course>>email_id>>contact_no>>address;
       if(found == 0)
       {
         cout<<"\t\t\t Student Roll No Not Found..";
         
       }
     }
     file1.close();
     file.close();
     remove("studentRecorsd.txt");
     rename("Record.txt","studentRecord.txt");
  }
}
void student :: search(){
  system("cls");
  fstream file;
  int found = 0;
  file.open("studentRecord.txt");
  if(!file){
    cout<<".........................................................................................."<<endl;
    cout<<"..........................................Search Student Details.........................."<<endl;
    cout<<".........................................................................................."<<endl;
    cout<<"\t\t\t No data is present..."<<endl;
  }
  else{
    string rollno;
     cout<<".........................................................................................."<<endl;
    cout<<"..........................................Search Student Details.........................."<<endl;
    cout<<".........................................................................................."<<endl;
    cout<<" Enter the roll no of student which you want to search...";
    cin>>rollno;
    file>>name>>roll_no>>course>>email_id>>contact_no>>address;
    while(!file.eof()){
      if(rollno == roll_no){
        cout<<"\t\t\t Student Name." <<name<<endl;
       cout<<"\t\t\t Student Roll No." <<roll_no<<endl;
       cout<<"\t\t\t Student Course" << course<<endl;
       cout<<"\t\t\t Student Email Id" <<email_id<<endl;
       cout<<"\t\t\t Student Contact No" <<contact_no<<endl;
       cout<<"\t\t\t Student Address" <<address<<endl;
       found++;
      }
      
    file>>name>>roll_no>>course>>email_id>>contact_no>>address;
    }
    if(found == 0){
      cout<<"\n\t\t\t Student Roll No not found...";
    }
    file.close();
  }
}
void student ::deleteRecord(){
  system("cls");
  fstream file,file1;
  string rollno;
  int found ;
  cout<<"......................................................................................"<<endl;
  cout<<"......................................Delet Student Record............................"<<endl;
  cout<<"......................................................................................"<<endl;
  file.open("studentRecord.txt",ios::in);
  if(!file){
    cout<<"\n\t\t\t No Data is present...";

  }
  else{
    cout<<"\n Enter the roll no of student which you want to delete ::";
    cin>>rollno;
    file1.open("Record.txt",ios::app|ios::in);
      
    file>>name>>roll_no>>course>>email_id>>contact_no>>address;
    while(!file.eof()){
      if(rollno != roll_no){
        file<<" "<<name<<" "<<roll_no<<" "<<course<<" "<<address<<" "<<email_id<<" "<<contact_no<<"\n";

      }
      if(found == 0){
       cout<<"\n\t\t\t Student Roll no is not found....";
      }
      file1.close();
      file.close();
      remove("studentRecord.txt");
      rename("Record.txt","studentRecord.txt");
    }
  }

}
int main(){
student project;
project.menu();
return 0;
}
 