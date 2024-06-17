#include "cars.h"
#include <iostream>
#include <string>
#include <cstring>

//конструктор без параметров
Cars::Cars() 
    {
        std::string str = "конструктор без параметров";
         std::cout <<  str << this->car_name<< std::endl;
          cnt_cars ++;
    }

  //конструктор с параметрами
     Cars::Cars(std::string name, int cnt_cldr, int pwr)

    {
         car_name = name; 
         cnt_cylinder = cnt_cldr;
         power = pwr;
         std::string str = "конструктор c параметрами ";
         std::cout <<  str << this->car_name << std::endl;
          cnt_cars ++;
    }  

     // конструктор копирования
    Cars::Cars(const Cars &c)
    {
        car_name = c.car_name; 
         cnt_cylinder = c.cnt_cylinder;
         power = c.power;
     
         std::string str = "конструктор  копирования  ";
         std::cout <<  str << this->car_name << std::endl;
         cnt_cars ++;
    }

     //деструктор
    Cars::~Cars()
    {
       std::string str = "Деструктор  ";
        std::cout <<  str << this->car_name<< std::endl;
        cnt_cars --; 
    }

   // перегрузка оператора << дружественная функция
   
 /* std::ostream&  operator<< (std::ostream &os, const Cars &c)
    {
       os<< "Марка машины " <<c.car_name << std::endl
        << "Число цилиндров  "<< c.cnt_cylinder<< std::endl
        << "Мощность " << c.power<< std::endl << std::endl;
       return os;
    } */

  
   
   /* std::istream& operator >> (std::istream &is,   Cars& c)
    {
        is >> c.car_name;
        is >> c.cnt_cylinder;
        is >> c.power;
        return is;

    }*/

    //перегрузка оператора присвоения
    Cars&   Cars::operator= (const Cars& c)
    {
         if (&c == this)  return *this;
         
         this->car_name = c.car_name;
         this->cnt_cylinder = c.cnt_cylinder;
         this->power = c.power;
              
         return *this;
    
    }
    
 