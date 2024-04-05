#include <iostream>
using namespace std;

class Node
{
private:
   int elem;
   Node* prev;
   Node* next;
friend class Dll;
};

class Dll
{
private:
   Node* header;
   Node* trailer;
   int n;
   Node* p;
public:

   Dll()
   {
      header = new Node;
      trailer = new Node;
      n = 0;
      header->next = trailer;
      trailer->prev = header;
      p = header->next;
   }
   void begin()
   {
      this->p = header->next;   
   }
   void end()
   {
      this->p = trailer;
   }
   void insert(int e)
   {
      Node* newNode = new Node;
      newNode->elem = e;
      p->prev->next = newNode;
      newNode->prev = p->prev;
      p->prev = newNode;
      newNode->next = p;
      n++;
   }

   void erase()
   {
      if(n==0)
      {
         cout << "Empty\n";
         return;
      }
      if(trailer == p)
      {
         return;
      }
      p->prev->next = p->next;
      p->next->prev = p->prev;
      delete p;
      n--;
      begin();
   }
   void nextP()
   {
      if(p == trailer)
      {
         return;
      }
      p = p->next;
   }
   void prevP()
   {
      if(p==header)
      {
         return;
      }
      p = p->prev;
   }
   void print()
   {
      if(n == 0)
      {
         cout << "Empty\n"; 
         return;
      }
      for(Node* i = header->next ; i != trailer ; i = i->next)
      {
         cout << i->elem << ' ';
      }
      cout << '\n';
      return;
   }
   void find(int e)
   {
      Node* curNode = header->next;
      bool flg = false;
      for(int i = 0 ; i < n ; i++)
      {
         if(curNode->elem == e)
         {
            cout << i << ' ';
            flg = true;
         }
         curNode = curNode->next;
      }
      if(!flg)
      {
         cout << -1;
      }
      cout << '\n';
      return;
   }
   void upper(int e)
   {
      Node* curNode = header->next;
      bool flg = false;
      for(int i = 0 ; i < n ; i++)
      {
         if(curNode->elem > e)
         {
            cout << i << ' ';
            flg = true;
         }
         curNode = curNode->next;
      }
      if(!flg)
      {
         cout << -1;
      }
      cout << '\n';
      return;      
   }
};

int main()
{
   Dll dll;
   int test_case;
   cin >> test_case;
   string s; int a;
   for(int i = 0 ; i < test_case ; i++)
   {
      cin >> s;
      if(s == "find")
      {
         cin >> a;
         dll.find(a);
      }
      else if(s == "print")
      {
         dll.print();
      }
      else if(s == "prevP")
      {
         dll.prevP();
      }
      else if(s == "nextP")
      {
         dll.nextP();
      }
      else if(s == "erase")
      {
         dll.erase();
      }
      else if(s == "insert")
      {
         cin >> a;
         dll.insert(a);
      }
      else if(s == "end")
      {
         dll.end();
      }
      else if(s == "begin")
      {
         dll.begin();
      }
      else if(s=="upper")
      {
         cin >> a;
         dll.upper(a);
      }
   }
}