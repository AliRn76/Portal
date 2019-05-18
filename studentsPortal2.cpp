#include <iostream>
#include <string>
#include <windows.h>
#include <string>
#include <fstream>
//#include <iomanip>


using namespace std;

#define SLEEPTIME 4000 


class Students
{
public:
    int studentInput;
    int studentmenu(){
        system("cls");
        cout<<"\n\n"
              "\n                                    1) Add Student       "
              "\n                                    2) Remove Student    "
              "\n                                    3) Search Student    "
              "\n                                    4) Back              "
              "\n\n                                    Enter your choice:      ";
       	cin>> studentInput;
       	return studentInput;
        
    }
	
	
    void selectstudentpage(int studentInput)
	{

        switch(studentInput)
		{
            case 1:
                addStudent();
                break;
            case 2:
            	removeStudent();
                break;
            case 3:
            	searchStudent();
                break;
            case 4:
            	//mainpage();
            	
                break;
        }
    }
	
	
	
    void addStudent()
	{
    	fstream file;
    	file.open("student.txt" , ios::in|ios::out|ios::app);
    	if(!file)
    	{
    		cout << "can not open file." ;
    		cin.get();
    		exit(0);
    	}
        else
        {
	        string firstName;
	        string lastName;
	        string fullName;
			string studentCode;
	        string studentField;
	        system("cls");
	        

				
	        cout<<"Enter First Name: ";
	        cin>>firstName;
	        
	        cout<<"Enter Last Name: ";
	        cin>>lastName;
	        
	        cout<<"Enter Student Code: ";
	        cin>>studentCode;
	        
	        cout<<"Enter Field: ";
	        cin>>studentField;
	        
	        fullName = firstName+" "+lastName;
	        cout<< studentCode <<" / "<< fullName <<" / "<< studentField << " Added !" <<endl;
	        
	        file << studentCode <<" / "<< fullName <<" / "<< studentField << "  "<<endl;
	        	        
	        file.close();
	        Sleep(SLEEPTIME);
		}
         
        
        
    }
    void removeStudent()
	{
		system("cls");
		fstream file;
		file.open("student.txt", ios::in|ios::out);
		fstream temp;
		temp.open("temp.txt", ios::in|ios::out|ios::app);
		
		string studentCode;
		string line;
		bool checkinput = false ;
    
	
		cout << "Enter Your StudentCode:" <<endl;
		
		cin >> studentCode;
				
		while (getline(file,line))
		{
			if(line.find(studentCode) != 0 ){	
				temp << line << endl ;
			}
			else{
				checkinput = true;
			} 
		}
		
		file.close();
		temp.close();
		remove("student.txt");
		rename("temp.txt","student.txt");
  		
  		if(checkinput == true) {
    		cout << "Deleted Successfully !" << endl;  			
		  }
		else{
			cout <<"Not Found !" ;
		}

		Sleep(SLEEPTIME);
		
			
	}
	void searchStudent()
	{
		system("cls");
		string line;
		string studentCode ;
		fstream file;
		file.open("student.txt", ios::in|ios::out);
		bool checkinput = false;
		
		cout << "Enter Your StudentCode:" <<endl;
		cin >> studentCode;
		
		
		while (getline(file,line))
		{
			if(line.find(studentCode) == 0 )
			{	
				cout <<line<< endl ;
				checkinput = true;
			}	
		}
		
		
		if(checkinput == false){
			cout<<"* Not Found !!! " ;
		}
		
		Sleep(SLEEPTIME);
		file.close();
	}
	
};

class Course 
{
	public:
		string coursename;
		int coursnumber;
		
		
	static int inputmenu() {
			int inputfield ;
			system("cls");
	        cout<<"\n\n"
		              "\n                                    1) Theoretical       "
		              "\n                                    2) Practical    "
		              "\n\n                                    Enter your choice:      ";
		              
	       	cin>> inputfield;
	       	return inputfield;
	}
		virtual int coursemenu() = 0;
		virtual void selectcoursepage(int a) = 0;
};


class TheoreticalCourse : public Course
{
	
	public:
    int courseInput;
    string tarhdars ;
    
//  string courseName;
//	int courseNumber;

    virtual int coursemenu()
	{
        system("cls");
        cout<<"\n\n"
              "\n                                    1) Add Theoretical course      "
              "\n                                    2) Remove Theoretical course    "
              "\n                                    3) Search Theoretical course    "
              "\n                                    4) Back              "
              "\n\n                                    Enter your choice:      ";
       	cin>> courseInput;
       	return courseInput;
        
    }
	
	
    virtual void selectcoursepage(int courseInput)
	{

        switch(courseInput)
		{
            case 1:
                AddtCourse();
                break;
            case 2:
            	removetCourse();
                break;
            case 3:
            	searchtCourse();
                break;
            case 4:
            
            	
                break;
        }
    }
    
    void AddtCourse(){
    	fstream file ;
    	file.open("course.txt" , ios::in|ios::out|ios::app);
    	
    	system("cls");
    	cout << "Enter Your Course Name : " << endl;
    	cin >> coursename ;
    	cout << "Enter Coursenumber : " << endl;
    	cin >> coursnumber ;
    	cout << "Enter Explanation : " << endl;
    	
    	getline(cin , tarhdars);
    	
    	file << coursename <<" / "<< coursnumber <<" / "<< tarhdars << "  "<<endl;
    	cout<< coursename <<" / "<< coursnumber<<" / "<< tarhdars << " Added !" <<endl;	   	        	        
	    file.close();
	    Sleep(SLEEPTIME);
    	
    	
    	
	}
	
	void removetCourse(){
    	
	}
	
	void searchtCourse(){
    	
	}
		
};

class PracticalCourse : public Course
{
	public:
	string project;
    int courseInput;
//  string courseName;
//	int courseNumber;

virtual int coursemenu()
	{
        system("cls");
        
        cout<<"\n\n"
              "\n                                    1) Add Practical course      "
              "\n                                    2) Remove Practical course    "
              "\n                                    3) Search Practical course    "
              "\n                                    4) Back              "
              "\n\n                                    Enter your choice:      ";
       	cin>> courseInput;
       	
       	return courseInput;
        
    }
	
	
    virtual void selectcoursepage(int courseInput)
	{

        switch(courseInput)
		{
            case 1:
                AddpCourse();
                break;
            case 2:
            	removepCourse();
                break;
            case 3:
            	searchpCourse();
                break;
            case 4:
			        	
                break;
        }
    }
    
    void AddpCourse(){
    	system("cls");
    	cout << "Enter Your Course Name : " << endl;
    	cin >> coursename ;
    	cout << "Enter Coursenumber : " << endl;
    	cin >> coursnumber ;
    	cout << "Enter needed project : " << endl;
    	cin >> project ;
    	    	
	}
	
	void removepCourse(){
    	
	}
	
	void searchpCourse(){
    	
	}	
}; 

class report{
	public:
		int reportinput;
	    int reportmenu(){
	    	
	        system("cls");
	        cout<<"\n\n"
	              "\n                                    1) Show All Student       "
	              "\n                                    2) Show All Course   "
	              "\n                                    3) Search Student    "
	              "\n                                    4) Back              "
	              "\n\n                                    Enter your choice:      ";
	       	cin>> reportinput;
	       	return reportinput;	        
	    }
	    
	    void selectreportpage(int reportinput){
	    	
	    	switch(reportinput){
	    		case 1:
	    			showalls();
	    			break;
	    		case 2:
	    			showallc();
	    			break;
	    		case 3 :
	    			break;
	    		default:
	    			break;
			}	    	
		}
		
		void showalls(){
						
			fstream file ;
			file.open("student.txt" , ios::out | ios::in);
			string str ;
			
			
									
			while(getline(file , str)){				
				cout << str <<endl;			
			}
						
			file.close();
		}
		
		
				
		void showallc(){
			
		}
	
	
};

int main(){
	
    Students studentPage;
    int n , m, k , r;
    
    
    while(true){	
	    int input_number;
		system("cls");
		cout<<"\n \n "
	          "\n                                    1) Students                       "
	          "\n                                    2) Courses                         "
	          "\n                                    3) couse Registration             "
	          "\n                                    4) Reports                        "
	          "\n                                    5) Exit                           "
	          "\n\n                                    Enter your choice: ";
	          
	    cin>>input_number;  
//	    int input_number = mainpage();	    
	    switch(input_number){
	        case 1:
	            n = studentPage.studentmenu();
	            studentPage.selectstudentpage(n);
	            break;
	        case 2:
				m = Course::inputmenu();
				if(m==1){
					TheoreticalCourse theory ;
					k = theory.coursemenu();
					theory.selectcoursepage(k);
				} 	
				else if(m==2){
					PracticalCourse p ;
					k = p.coursemenu();
					p.selectcoursepage(k);
				}
	            break;
	        case 3:
	        	
	            break;
	        case 4:
				report rep ;
				r = rep.reportmenu();
				rep.selectreportpage(r);
				break;			
			case 5:
				exit(0);
	            break;
	    }
    }
    return 0;
}
