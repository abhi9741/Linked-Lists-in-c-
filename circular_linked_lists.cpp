#include<iostream>
using namespace std;
const int maxlenght=10;
struct node
        {
         float data;
         node* next;
         node* prev;
        };

struct list
        {
         node* firstnode;
        };

list* makenull()
        {
         list* temp = new list();
         node *temp1 = new node();
         temp->firstnode=temp1;

         temp1->data=-1e200;
         temp1->next=NULL;
         temp1->prev=NULL;
         return temp;
        }

void erase(list* listptr)
        {
         node* cnode =listptr->firstnode;
         node* pnode;
         while (!(cnode->next==NULL))
         {
          pnode=cnode->next;
         delete cnode;
         cnode=pnode;
       }
       delete listptr->firstnode;
       delete listptr;
       }

node* first(list* listptr)
        {
         return listptr->firstnode;
        }

node* end(list* listptr)
        {
         node* l=listptr->firstnode;
         int c=1;
         while(!(c=0))
          {
           if (l->next==NULL)
           {
            c=0;
            return l;
           }
           else
           {
            l=l->next;
           }
          }
        }

int insert(float x,int pos,list* listptr)
        {
          if (pos==0)
          {
            node* nnode=new node();
            node* fnode=listptr->firstnode;
            nnode->next=fnode;
            nnode->data=x;
            listptr->firstnode=nnode;
          }

        else if (pos==1)
        {
         listptr->firstnode->data=x;
        }
        else {
         int c=1;
         node* pnode=listptr->firstnode;
         while (c<pos-1)
         {
          // node* temp=pnode;
          pnode=pnode->next;
          c++;
         }

         node* cnode=pnode->next;
        //  cout<<"cnode"<<cnode<<"\n";
        //  cout<<"pnode"<<pnode<<"\n";
         node* newnode=new node();
        //  cout<<"newnode"<<newnode<<"\n";
         newnode->data=x;

         newnode->next=cnode;
        //  cout<<"newnode next"<<newnode->next<<"\n";
         newnode->prev=pnode;
        //  cout<<"newnode prev"<<newnode->prev<<"\n";

         if (cnode==NULL)
         {
          cnode=cnode;
         }
         else{
         cnode->prev=newnode;

        //  cout<<"cnode prev"<<cnode->prev;
       }
         pnode->next=newnode;
        //  cout<<"pnode next"<<pnode->next<<"\n";

       }}

void printlist(list* listptr)
        {
         node* ptr=listptr->firstnode;
         int c=1;
         cout<<"{ ";
         while (!(c==0))
         {
         if (ptr->next==NULL)
         {
          cout<<ptr->data;
          c=0;
         }
         else
         {
          cout<<ptr->data<<"  ,";
          ptr=ptr->next;
         }
         }
         cout<<" }"<<"\n";
        }

int remove(int pos,list* listptr)
        {
         int c=1;
         node* prevnode=listptr->firstnode;

         if (prevnode==NULL)
         {return -1;}
         else{
         while (c<pos-1)
         {
          prevnode=prevnode->next;

          if (prevnode==NULL)
          {return -1;}
          c++;
         }
         node* anode=prevnode->next;
         if (anode==NULL)
         {return -1;}
        else{
        anode=anode->next;
        if (anode==NULL)
        {return -1;}
        else{
        prevnode->next=anode;
        anode->prev=prevnode;
        return 0;
      }
    }
  }
}

int locate(float x,list* listptr)
        {
         int l=1;
         node* cnode=listptr->firstnode;
         int c=1;
         while (!(c==0))
         {
          if ((cnode->data==x))
         {
          c=0;
          return l;
         }
         else
         {
          cnode=cnode->next;
          if (cnode==NULL)
          {
            return -1;
          }
          l++;
         }
         }
        }

float retrieve(int pos,list* listptr)
  {
    int p=1;
    node* cnode=listptr->firstnode;

    if (p==pos)
    {
      float f=cnode->data;

      return f;
    }
    else
    {
      float f=0;
    while (p<pos)
    {
      cnode=cnode->next;

      if (cnode==NULL)
      {
        return -1;
      }
      p++;
      if (p==pos)
      {
        f=cnode->data;
        return f;
      }
    }
  }
}

int len(list* listptr)
{
  node* cnode=listptr->firstnode;
  int i=1;
  while (!(cnode->next==NULL))
  {
    cnode=cnode->next;
    i++;
  }
  return i;
}

void sort(list* listptr)
{
 node* pnode=listptr->firstnode;
 node* cnode=pnode->next;

 if (cnode==NULL)
 {
  float bikki=0.5;
}
else
{int i=0;
  int lenght=len(listptr);
  while(i<lenght)
  {
    pnode=listptr->firstnode;
    cnode=pnode->next;
    while (!(pnode->next==NULL))
    {
      if ((pnode->data) > (cnode->data))
      {
        float temp=pnode->data;

        pnode->data=cnode->data;
        cnode->data=temp;
        pnode=cnode;
        cnode=cnode->next;
      }
      else
      {
        pnode=cnode;
        cnode=cnode->next;
      }
    }i++;
  }
}
}


list* sorted(list* listptr)
{
  node* cnode=listptr->firstnode;
  list* ll= makenull();
  node* lnode=ll->firstnode;
  while (!(cnode==NULL))
  {
    lnode->data=cnode->data;

    node* tempnode=new node();
    lnode->next=tempnode;
    tempnode->prev=lnode;
    lnode=lnode->next;
    cnode=cnode->next;
  }
  sort(ll);
  return ll;
}

int main()
	{
   list* l= makenull(); //l is the pointer to the list,not the name.
   cout<<"list pointer = "<<l<<"\n";
   cout<<"list head "<<l->firstnode<<"\n";
   cout<<"list head next "<<l->firstnode<<"\n";

   //cout<<end(l)<<"\n";
   /*
   these does not work as second arguement of insert function should be an integer.
   insert(11,end(l),l);
   insert(13,end(l),l);
   insert(14,end(l),l);
   insert(15,end(l),l);
   */
   /*cout<<"insert 1"<<"\n";
   insert(23.1,1,l);
   cout<<"insert 2"<<"\n";
   insert(24,2,l);
   cout<<"insert 3"<<"\n";
   insert(13,3,l);
   //insert(-13,0,l);
   printlist(l);
   cout<<remove(2,l)<<"\n";
   printlist(l);
   cout<<locate(15,l)<<"\n";
   cout<<retrieve(2,l)<<"\n";
   cout<<retrieve(3,l)<<"\n";
   insert(-13,0,l);
   cout<<"-------------------"<<"\n";
   cout<<remove(4,l)<<"\n";
   cout<<"list"<<"\n";
   printlist(l);
   cout<<"sorted list "<<"\n";
   sort(l);
   printlist(l);
   cout<<len(l)<<"\n";
   cout<<"==============="<<"\n";
   cout<<sorted(l)<<"\n";
   list* ll=sorted(l);
   printlist(ll);
   erase(l);
   /*
   cout<<"-------------------"<<"\n";
   cout<<"the below segmentation error is caused due to printing an erased list"<<"\n";
   printlist(l);
   */

   return 0;
	}
