#include<iostream>
#include<string.h>
using namespace std;
class mstring
{
 int l1,l2;
 char s1[100],s2[100];
 public:
    void length();
    void copy();
    void concat();
    int substring();
    void reverse();
    void  equal();
    
};

 
 void mstring::length()                                   
{
    int i; 

      cout<<"\n\tEnter the First String\t";
      cin>>s1;
      cout<<"\n\tEnter the Second String";
      cin>>s2;
        l1=0,l2=0; 
        for(i=0;s1[i]!='\0';i++) 
            l1++; 
        for(i=0;s2[i]!='\0';i++) 
            l2++; 
        cout<<"\n\tLength of First String  is:  "<<l1; 
        cout<<"\n\tLength of Second String is:  "<<l2; 
 }
 
 
 void mstring :: copy()                                     // function to copy the string
 {

      cout<<"\n\tEnter the First String\t";
      cin>>s1;
      cout<<"\n\tEnter the Second String";
      cin>>s2;
 
    int i;
    for(i=0;s2[i]!='\0';i++)
       
          s1[i]=s2[i];
          s1[i]='\0';
 
    cout<<"\n\t The new string is "<<s1;
    cout<<"\n\t second string is "<<s2;
  
 }

void mstring :: concat()                                // funtion to concat the string
{
   int i;

   length();
        

    for(i=0;s2[i]!='\0';i++)

     s1[l1++]=s2[i];
     s1[l1]='\0';

  
    cout<<"\n\tThe Concatenated String is "<<s1;
}
 
 int mstring :: substring()                          //function to check for substring in a entered string
  {

    int flag=0;
    int i=0,j=0;
    length();
   while(i<l1-l2+1) 
    { 
      if(s1[i+j]==s2[j]) 
            j=j+1; 
        else if(j>=l2) 
          { 
            flag=1; 
            break; 
          } 
        else
          { 
            i++; 
            j=0; 
          } 
    } 
    
      return(flag); 
  
  } 
 
 
 void mstring :: reverse()                          //function to Reverse a string
 { 
 
    int i,j,l1=0;
   
     cout<<"\n\tEnter the String";
     cin>>s1;
 
    for(j=0;s1[j]!='\0';j++)
     
       l1++;
     
     for(i=0;i<=(l1-1);i++)
     
       s2[(l1-1)-i]=s1[i];
         s2[l1]='\0';
     
     
     cout<<"\n\tThe Reverse of the String is "<<s2;
      
 }
 
 
 void mstring :: equal()                            // function to check if string is Equal          
 {

      cout<<"\n\tEnter the First String";
      cin>>s1;
      cout<<"\n\tEnter the Second String";
      cin>>s2;
   int i,a=0,l1=0,l2=0;
   for(i=0;s1[i]!='\0';i++)
   l1++;
   for(i=0;s2[i]!='\0';i++)
   l2++;
   
   for(i=0;s1[i]!='\0';i++)
      if(s1[i]==s2[i])
      {
        a++;
      }
  
    if(a=i&&l1==l2)
      cout<<"\n\t The String is Equal";
    else
    {
     cout<<"\n\tThe String is Not equal";
    }        
    
 }
 
  

 int main()                                                   //Main program
 {
 
  int flag;
  mstring s;
  char ch;
  int op,x,y;
 do
{
 cout<<"\n\t---------------------------MENU---------------------------";
 cout<<"\n\t1)Length";
 cout<<"\n\t2)Copy";
 cout<<"\n\t3)Concatenate";
 cout<<"\n\t4)Reverse";
 cout<<"\n\t5)Substring";
 cout<<"\n\t6)Equal\n";
 cout<<"\nEnter you choice \n";
 cin>>op;

              switch(op)
                {
                       case 1:
                       s.length();
                             break;

                       case 2:
                       s.copy();
                             break;

                       case 3:
                       s.concat();
                             break;
                       
                       case 4 :
                       s.reverse();
                             break;
                       
                       case 5:
                       flag=s.substring();
                       if(flag==1) 
                            cout<<"\n\t It is a Sub string"; 
                       else 
                            cout<<"\n\t It is not a sub string"; 
                             break; 
                    
                       case 6:
                       s.equal();
                             break;
                       
                      default :
                      cout<<"\n\tInvalid Choice";
   }
       
            
    cout<<"\n\t Do you want to continue ? (y/n) \n\t";
    cin>>ch; 
   
   }   while(ch=='y'||ch=='Y');
 
     return 0;
 
 }