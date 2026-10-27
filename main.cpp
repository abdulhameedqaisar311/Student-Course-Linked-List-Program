#include <iostream>

using namespace std;
struct student
{
    int rollNo;
    student*next;
};
struct course
{
    int courseID;
    student*studentHead;
    course*next;
};

void insertcourse(course*&head,int id)
{
   course*c=new course;
   c->courseID=id;
   c->studentHead=NULL;
   c->next=NULL;
   if(head==NULL)
   {
       head=c;
       cout<<"Course Added Successfully"<<endl;
       return;
   }
   course*s=head;
   while(s->next!=NULL)
        s=s->next;
   s->next=c;
   cout<<"Course Added Successfully"<<endl;
}
course*findcourse(course*head,int id)
{
    while(head!=NULL)
    {
        if(head->courseID==id)
            return head;
        head=head->next;
    }
    return NULL;
}
void addstudent(course*head,int courseid,int rollno )
{
    course*c=findcourse(head,courseid);
    if(c==NULL)
    {
        cout<<"No such Course exists"<<endl;
        return;
    }
    student*s=new student;
    s->rollNo=rollno;
    s->next=NULL;
    if(c->studentHead==NULL)
    {
        c->studentHead=s;
        cout<<"Student Added Successfully"<<endl;
        return;
    }
    student*p=c->studentHead;
    while(p->next!=NULL)
        p=p->next;
    p->next=s;
    cout<<"Student Added Successfully"<<endl;
}
void display(course*head)
{
    while(head!=NULL)
    {
        cout<<"\nCourse "<<head->courseID<<" : ";
        student*s=head->studentHead;
        while(s!=NULL)
        {
            cout<<s->rollNo<<" ";
            s=s->next;
        }
        head=head->next;
    }
}

int main()
{
    course*head=NULL;
    int choice;
    cout<<"**********************************"<<endl;
    cout<<"Student-Course Linked List Program"<<endl;
    cout<<"**********************************"<<endl;
    do
    {
        cout<<"\n1.Insert Course"<<endl;
        cout<<"2.Insert Student in Specific Course"<<endl;
        cout<<"3.All courses and Students"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            {
                int courseid;
                cout<<"\nEnter Course ID: ";
                cin>>courseid;
                insertcourse(head,courseid);
                break;
            }
        case 2:
            {
                cout<<"\nEnter Course ID: ";
                int id;
                cin>>id;
                cout<<"\nEnter Student Roll Number: ";
                int roll;
                cin>>roll;
                addstudent(head,id,roll);
                break;
            }
        case 3:
            {
                cout<<"\nAll Courses and their Enrolled Students: ";
                display(head);
                break;
            }
        }
    }while(choice!=4);
}
