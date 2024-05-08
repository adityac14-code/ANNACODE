/*Name: yash yogesh sonawane
Seat no  - S190274279
	Computer department
	Practical no: 3 A book consisits of chapters, chapters consists of sections and sections consisits of subsections 
     construct a tree and print the nodes*/

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct node
{   char name[20];
     node *next;
     node *down;
      int flag;
};
class Gll
{   char ch[20];    int n,i;    
     node *head=NULL,*temp=NULL,*t1=NULL,*t2=NULL;
     public:
     node *create();
     void insertb();
     void insertc();
     void insert();
     void insert();
     void displayb(); 
};
node *Gll::create()
{
    node *p=new(struct node);
    p->next=NULL;
    p->down=NULL;
    p->flag=0;
    cout<<"\n Enter the name: ";
    cin>>p->name;
    return p;
}
void Gll::insertb()
{      
         if(head==NULL)
           {    t1=create();
                head=t1;
           }
           else
           {
              cout<<"\n Book exist";
           }   
}     
void Gll::insertc()
{     
      if(head==NULL)
          { 
                  cout<<"\n There is no book";   
           }
           else
           {    cout<<"\n How many chapters you want to insert: ";
                cin>>n;
                for(i=0;i<n;i++)
                {
                t1=create();
                if(head->flag==0)
                {  head->down=t1;   head->flag=1;    }
                else
                {   temp=head;
                     temp=temp->down;
                    while(temp->next!=NULL)
                         temp=temp->next;
                     temp->next=t1;
                }
                }
          }                        
} 
void Gll::inserts()
{     
         if(head==NULL)
          { 
                  cout<<"\n There is no book";   
           }
           else
           {    cout<<"\n Enter the name of chapter on which  you want to enter the section: ";
                 cin>>ch;
                 temp=head;
               if(temp->flag==0)
               {   cout<<"\n Their are no chapters in book";
               }
               else
               {    temp=temp->down;
                while(temp!=NULL)
                 { 
                      if(!strcmp(ch,temp->name))
                      {   
                                cout<<"\n How many sections you want to enter: ";
                                cin>>n;
                                for(i=0;i<n;i++)
                                {   
                                           t1=create();
                                               if(temp->flag==0)
                                               {      temp->down=t1;                   
                                                        temp->flag=1;  cout<<"\n******";
                                                        t2=temp->down;
                                               }
                                              else
                                               {           
                                                              cout<<"\n#####";
                                                               while(t2->next!=NULL)
                                                               {     t2=t2->next;          }
                                                                       t2->next=t1;                 
                                                 }   
                                 }                              
                                   break;       
                       }  
                               temp=temp->next;
                  }
                }    
         }
}
void Gll::insertss()
{     
         if(head==NULL)
          { 
                  cout<<"\n There is no book";   
           }
           else
           {    cout<<"\n Enter the name of chapter on which  you want to enter the section: ";
                 cin>>ch;
                
                 temp=head;
               if(temp->flag==0)
               {   cout<<"\n Their are no chapters in book";
               }
               else
               {    temp=temp->down;
                while(temp!=NULL)
                 { 
                      if(!strcmp(ch,temp->name))
                      {       
                         cout<<"\n Enter name of section in which you want to enter the subsection: ";
                         cin>>ch;
                        if(temp->flag==0)
                        {   cout<<"\n Their are no sections";   }
                         else
                         {       
			temp=temp->down;
                                 while(temp!=NULL)
                                 {
                                     if(!strcmp(ch,temp->name))
                                     {
                                      cout<<"\n How many subsections you want to enter: ";
                                        cin>>n;
                    				for(i=0;i<n;i++)
                                   {
                                           t1=create();
                                               if(temp->flag==0)
                                               {      
											   			temp->down=t1;
                                                        temp->flag=1;  
														cout<<"\n******";
                                                        t2=temp->down;
                                               }
                                              else
                                               {           
                                                              cout<<"\n#####";
                                                               while(t2->next!=NULL)
                                                               {     t2=t2->next;          
                                                                     t2->next=t1;
															   }
                                                 }   
                                        }                              
                                         break;
                                     }      temp=temp->next;
                                   }
                          }       
                       }
                               temp=temp->next;
                  }
                }    
         }
} 
void Gll::displayb()
{       
                if(head==NULL)
                {  
					cout<<"\n Book not exist"; 
                }
                else
                {
                 temp=head;
                    cout<<"\n NAME OF BOOK:  "<<temp->name;
                         if(temp->flag==1)
                         {
                         temp=temp->down;
                           while(temp!=NULL)
                           {     cout<<"\n\t\tNAME OF CHAPTER:  "<<temp->name;
                                 t1=temp;
                                 if(t1->flag==1)
                                 {  t1=t1->down;
                                    while(t1!=NULL)
                                    {     cout<<"\n\t\t\t\tNAME OF SECTION:  "<<t1->name;
                                          t2=t1;
                                          if(t2->flag==1)
                                          {  t2=t2->down;
                                          while(t2!=NULL)
                                          {     cout<<"\n\t\t\t\t\t\tNAME OF SUBSECTION:  "<<t2->name;     
                                          t2=t2->next;
                                          }
                                          }     
                                          t1=t1->next;
                                    }
                                 }   
                                  temp=temp->next;
                           }
                          }
                }                           
}                  
int main()
{    Gll g;   
	 int x;  
       while(1)
      {     
	  		cout<<"\n ***** Tree For Book *****";
            cout<<"\n 1.Insert book";
            cout<<"\n 2.Insert chapter";
            cout<<"\n 3.Insert section";
            cout<<"\n 4.Insert subsection";
            cout<<"\n 5.Display book";
            cout<<"\n 6.Exit";
            cout<<"\n\n Enter your choice: ";
            cin>>x;
           switch(x)
           {   case 1:           g.insertb();
                                         break;             
                case 2:          g.insertc();
                                         break;      
                case 3:          g.inserts();
                                         break;
                case 4:          g.insertss();
                                         break;    
                case 5:          g.displayb();
                                         break;      
                case 6:  
				exit(0);
           }
       }
       return 0;
}

/*OUTPUT*/

/****** Tree For Book *****
 1.Insert book
 2.Insert chapter
 3.Insert section
 4.Insert subsection
 5.Display book
 6.Exit

 Enter your choice: 1

 Enter the name: se

 ***** Tree For Book *****
 1.Insert book
 2.Insert chapter
 3.Insert section
 4.Insert subsection
 5.Display book
 6.Exit

 Enter your choice: 2

 How many chapters you want to insert: 1

 Enter the name: se.char

 ***** Tree For Book *****
 1.Insert book
 2.Insert chapter
 3.Insert section
 4.Insert subsection
 5.Display book
 6.Exit

 Enter your choice: 3

 Enter the name of chapter on which  you want to enter the section: se.char

 How many sections you want to enter: 1

 Enter the name: se.char1

******
 ***** Tree For Book *****
 1.Insert book
 2.Insert chapter
 3.Insert section
 4.Insert subsection
 5.Display book
 6.Exit

 Enter your choice: 4

 Enter the name of chapter on which  you want to enter the section: se.char

 Enter name of section in which you want to enter the subsection: se.char1

 How many subsections you want to enter: 1

 Enter the name: se.char1.1

******
 ***** Tree For Book *****
 1.Insert book
 2.Insert chapter
 3.Insert section
 4.Insert subsection
 5.Display book
 6.Exit

 Enter your choice: 5

 NAME OF BOOKs:  se
		NAME OF CHAPTERs:  se.char
				NAME OF SECTIONs:  se.char1
						NAME OF SUBSECTIONs:  se.char1.1*/





























