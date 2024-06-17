#pragma once

#include <string.h>
#include <cstring>
#include <iostream>

class Cars
{

   friend int count();

private:
   // protected:
   std::string car_name = " Car"; // марка машины
   int cnt_cylinder = 0;          // число цилиндров
   int power = 0;                 // мощность

   static inline int cnt_cars{0}; // количество созданных объектов

public:
  
   std::string get_car_name() const;  
   void set_car_name(std::string name); //

   int get_cnt_cylinder() const;
   void set_cnt_cylinder(int cnt);

   int get_power() const;
   void set_power(int pwr);

   // конструктор без параметров
   Cars();

   // конструктор с параметрами
   Cars(std::string name, int cnt_cldr, int pwr);

   // конструктор копирования
   Cars(const Cars &c);

   // деструктор
   ~Cars();

   // перегрузка оператора =
   Cars &operator=(const Cars &c);
};
    