#include "cars.h"
#include <string>

class Lorry : public Cars
    {
    private:
        int capacity =0;
    public:
       
       Lorry():Cars()
       {

       }
      
       Lorry(std::string name, int cnt_cldr, int pwr, int caps): 
               Cars(name, cnt_cldr, pwr)
         {
            capacity = caps;
         }

       Lorry&  operator= (const Lorry& a) 
         {
              Cars::operator=( a);
               this->capacity = a.capacity;
               return *this;
         }
       
        
        

       int get_capacity() const {return capacity;}
       void set_capacity(int cnt){capacity = cnt;}  


   // friend std::ostream& operator << (std::ostream &os, const Lorry& c);
    

    };

 
 /* std::ostream& operator << (std::ostream &os, const Lorry& c)
    {
          os<< "Марка машины " <<c.car_name << std::endl
        << "Число цилиндров  "<< c.cnt_cylinder<< std::endl
        << "Мощность " << c.power<< std::endl 
        << "Емкость " << c.capacity << std:: endl << std::endl;

       return os;
    } */

     
  
    

    