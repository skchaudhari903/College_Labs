  #include<iostream>
  #include<string.h>  //to include string library function (here...,copy)
  
  using namespace std;
  class set
  {
  	int roll;
  	char name[20];
  	public:
  	int game;
  	static int m; 
  	void get();
  	void display();
  	set()  //constructor
  	{
  		roll=0;
  		strcpy(name,"aaa");  //copies 'aaa' to name
  		game=0;
  	}
  };

  int set::m;

  void set::get()  //accepts data from the user
  {
  	cout<<"\n\tEnter your Roll Number :\t";
  	cin>>roll;
  	cout<<"\tEnter your Name :\t";
  	cin>>name;
  	cout<<"\n\tEnter the game you play :\n";
  	cout<<"\t1.Cricket\n";
  	cout<<"\t2.Badmintion\n";
  	cout<<"\t3.Cricket and Badminton\n";
  	cout<<"\t4.Other\n\t";
  	cin>>game;
  }

  void set::display()
  {
  	cout<<roll<<"\t\t";
  	cout<<name<<"\t\t";
  	if(game==1)
  	{
  		cout<<"Cricket"<<"\t"<<endl;
  	}
  	else if (game==2)
  	{
  		cout<<"Badminton"<<"\t"<<endl;
  	}
  	else if(game==3)
  	{
  		cout<<"Cricket and Badminton"<<"\t"<<endl;
  	}
  	else if(game==4)
  	{
  		cout<<"Other\t"<<endl;
  	}	
  }

  int main()
  {
  	int a;
  	char abc;
  	int count=0;
  	int j;
  	set s[50]; //array of objects to store data of 50 students
  do
  {
  	cout<<"\t-------------MENU-------------------\n\t";
  	cout<<"1.Enter Student Data\n\t";
  	cout<<"2.Display\n\t";
  	cout<<"3.Set of students who play either cricket or badminton or both\n\t";
  	cout<<"4.Set of students who play both cricket and badminton\n\t";
  	cout<<"5.Set of students who play only cricket\n\t";
  	cout<<"6.Set of students who play only badminton\n\t";
  	cout<<"7.Set of students who play neither cricket nor badminton\n";
  	cout<<"\tEnter your choice\t\t";
  	cin>>a;
  	
  	switch(a)	
  	{
  		case 1:
  		s[set::m].get();
  		set::m=set::m+1;
  			break;	
  	
  		case 2:
  		cout<<"\n\tROLL NO\t\tNAME\t\tGAME\n\t";
  		for(int i=0;i<set::m;i++)
  		{
  		s[i].display();
  		cout<<"\t";
  		}
  			break;
  	
  		case 3:
  		j=0;
  		for(int i=0;i<set::m;i++)
  		{
  			if(s[i].game==1||s[i].game==2||s[i].game==3)
  			{
  				s[i].display();
  				j++;
  			}
  		}
  		cout<<"\n\tNo. of students who play either cricket or badminton or both :"<<j<<endl;
  			break;
  	
  		case 4:
  		j=0;
  		for(int i=0;i<set::m;i++)
  		{
  			if (s[i].game==3)
  			{
  				s[i].display();
  				j++;
  			}
  		}
  		cout<<"\n\tNo of students who play both cricket and badminton :"<<j<<endl;
  			break;
  	
  		case 5:	
  		j=0;
  		for(int i=0;i<set::m;i++)
  		{
  			if (s[i].game==1)
  			{
  				s[i].display();
  				j++;
  			}
  		} 
  		cout<<"\n\tNo. of students who play only cricket :"<<j<<endl;
  		break;

  		case 6:
  		j=0;
  		for(int i=0;i<set::m;i++)
  		{
  			if (s[i].game==2)
  			{
  				s[i].display();
  				j++;
  			}
  		}
  		cout<<"\n\tNo. of students who play only badminton :"<<j<<endl;
  				break;	
  		
  		case 7:
  		j=0;
  		for(int i=0;i<set::m;i++)
  		{
  			if(s[i].game==4)
  			{
  				s[i].display();
  				count++;
  			}
  		}
  		cout<<"Number of Student who neither play cricket nor badminton :"<<count<<endl;
  				break;

  		default:
  		cout<<"\n\tInvalid choice";
  	}
  	
  	cout<<"\n\tDo you want to continue ? press y or Y to continue\t";
  	cin>>abc;
  	
  }while(abc=='y' || abc=='Y');
  return 0;
  }