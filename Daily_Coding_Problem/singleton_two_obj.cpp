/* Implement the singleton pattern with a twist. First, instead of storing one instance, store two instances. 
 * And in every even call of getInstance(), return the first instance and in every odd call of getInstance(), 
 * return the second instance.
 */

#include<iostream>

using namespace std;

class singleton
{
   singleton() { };
   singleton(const singleton& obj) { };
   singleton& operator = (const singleton& obj) {};

   static singleton* obj1;
   static singleton* obj2;
   static int count;
   public:
   static singleton* GetObj();
};

singleton* singleton::obj1 = NULL;
singleton* singleton::obj2 = NULL;
int singleton::count = 1;

singleton* singleton::GetObj() {
   singleton* tmpObj = NULL;
   if(count == 1 && obj1 == NULL) {
     tmpObj = obj1 = new singleton();
   } if(count == 0 && obj2 == NULL) {
     tmpObj = obj2 = new singleton();
   } else if (count == 1) {
     tmpObj = obj1;
   } else {
     tmpObj = obj2;
   }
   count = (count+1)%2;
   return tmpObj;
}

int main()
{
   singleton* obj1 = singleton::GetObj();
   singleton* obj2 = singleton::GetObj();
   singleton* obj3 = singleton::GetObj();
   singleton* obj4 = singleton::GetObj();
   cout<<"Object-1: "<<obj1<<" object-2: "<<obj2<<" object-3: "<<obj3<<" object-4: "<<obj4<<endl;
   return 0;
}
