#include <iostream>
using namespace std;

class Node
{
   int elem;
   Node* next;
   Node* prev;
friend class Dll;
};

class Dll
{
private:
   Node* header;
   Node* trailer;
public:
   Dll()
   {
      header = new Node;
      trailer = new Node;
      header->next =trailer;
      trailer->prev = header;
   }

   void insert(int n)
   {
      int a;
      for(int i = 0 ; i < n ; i++)
      {
         cin >> a;
         Node* newNode = new Node;
         newNode->elem = a;
         newNode->prev = trailer->prev;
         trailer->prev->next = newNode;
         newNode->next = trailer;
         trailer->prev = newNode;
      }
   }

   void sum()
   {
      int s=0;
      for(Node* i = header->next ; i != trailer ; i=i->next)
      {
         if(i == header->next)
         {
            s = i->elem + i->next->elem;
         }
         else if(i == trailer->prev)
         {
            s = i->elem + i->prev->elem;
         }
         else
         {
            s = i->elem + i->prev->elem + i->next->elem;
         }
         cout << s << ' ';
      }
      cout << '\n';
   }
   void solution()
   {
      int n; cin >> n;
      insert(n);
      sum();
   }
};

int main()
{
   int test_case; cin >> test_case;
   for(int i = 0 ; i < test_case; i++)
   {
      Dll dll;
      dll.solution();
   }
}