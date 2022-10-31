#include <iostream>
using namespace std;
 
struct node
 
{
 
    int col;
 
    int data;
 
    node *next;
 
};
 
 
 
node** create(int &r, int &c)
 
{   
    
    
   
 
   cout<<"Enter order of matrix "<<endl;
 
   cin>>r>>c;
   
   node** a=new node*[r];
   
    
    
    
    
    
    
    
    
    int m=0;
 
 
 
    for(int i=0;i<r;i++)
 
    {
 
       cout<<"enter no of elements in row "<<i<<endl;
 
       cin>>m;
       
       if(m==0){ 
           a[i]=NULL;
           continue;
       }
 
       node *p,*q;
 
       p=new node();
 
       cout<<"enter column and value of elements of row "<<i <<" make sure in proper sequence "<<endl;
 
       cin>>p->col>>p->data;
 
       p->next=NULL;
 
       a[i]=p;
 
       q=p;
 
 
 
       for(int j=1;j<m;j++)
 
       {   node *t=new node();
 
           cin>>t->col>>t->data;
 
           t->next=NULL;
 
           q->next=t;
 
           q=t;
 
       }
 
 
 
    }
    return a;
 
}
 
void Display(node **a,int row,int col)
 
{  node *p;
 
    for(int i=0;i<row;i++)
 
    {   p=a[i];
 
        for(int j=0;j<col;j++)
 
        {
 
            if(p!=NULL && j==p->col) 
 
            {
 
             cout<<p->data<<" ";
 
             p=p->next;
 
            }
 
 
 
            else cout<<"0 ";
 
        }
 
        cout<<endl;
 
    }
 
}
 
int main()
 
{
 
   
 
   int r,c;
 
   node **a=NULL;
 
   a=create(r,c);
 
   Display(a,r,c);
 
    return 0;
 
}