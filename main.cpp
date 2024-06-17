#include "cars.h"
#include "lorry.hpp"
#include <iostream>

  std::ostream& operator<< (std::ostream& os, const Cars& c) {
    os << "Марка машины " << c.get_car_name() << std::endl
        << "Число цилиндров  " << c.get_cnt_cylinder() << std::endl
        << "Мощность " << c.get_power() << std::endl;
    return os;
}

std::ostream& operator<< (std::ostream& os, const Lorry& c) {
    os << static_cast<const Cars&>(c)
        << "Емкость " << c.get_capacity() << std::endl << std::endl;

    return os;
} 


//перегрузка оператора  ввода для Cars
std::istream &operator>>(std::istream &is, Cars &c)
{
    std::string name{};
    int cnt_cylinder{};
    int power{};

    is >> name;
    c.set_car_name(name);

    is >> cnt_cylinder;
    c.set_cnt_cylinder(cnt_cylinder);

    is >> power;
    c.set_power(power);

    return is;
}


//перегрузка оператора  ввода для Lorry
std::istream &operator>>(std::istream &is, Lorry &c)
{
    is >> static_cast<Cars &>(c);

    int capacity;
    is >> capacity;
    c.set_capacity(capacity);

    return is;
}

int count() {
    return Cars::cnt_cars;
}

int main()
{
   Cars Lada; // создание объекта конструктор без параметров
   std::cout <<"вывод значений полей объеккта LADA " << std::endl;
    Lada.set_car_name("Lada"); // создание объекта
    Lada.set_cnt_cylinder(4); // заполнение полей
    Lada.set_power(160);
    std::cout <<"вывод значений полей объеккта LADA после присвоения значений" << std::endl;
    std::cout <<  Lada << std::endl;

   Cars Volga("Volga", 8,200); //создание объекта конструктор с параметрами
   std::cout <<"вывод значений полей объеккта VOLGA" << std::endl;
   std::cout << Volga.get_car_name()<< std::endl; // вывод значений полей
   std::cout << Volga.get_cnt_cylinder()<< std::endl;
   std::cout <<Volga.get_power() << std::endl<< std::endl;

   Cars Lada1(Lada); // создание объекта конструктор копирования
    std::cout <<"вывод значений полей скопированного объекта LADA1" << std::endl;
   std::cout << Lada1 << std::endl<< std::endl;       
    std::cout <<"Установка полей LADA1" << std::endl;
   Lada1.set_car_name("Lada1"); // установка значений полей
   Lada1.set_cnt_cylinder(16); //
   Lada1.set_power(180); //
    std::cout <<"вывод значений полей  LADA1 после присвоения" << std::endl;

    
    Lada1 = Lada; //перегруженный оператор присвоения
                  
    std::cout <<"вsвод значений полей LADA1 после присвоения значений LADA" << std::endl;              
    std::cout << Lada1;  //вывод полей

   std::cout <<  "количество объектов " << count() << std::endl;

    Cars Avto; // новый объект
    std::cout <<"ввод значений полей AVTO" << std::endl;  
    std::cin>>Avto; // перегруженый оператор ввода
    std::cout << Avto;  //вывод полей
       


    Lorry Maz("Maz", 8, 200, 400); //объект дочернего класса
    std::cout << "Значения полей объекта MAZ" << std::endl;
    std::cout << Maz.get_car_name() << std::endl;
    std::cout << Maz. get_cnt_cylinder() << std::endl;
    std::cout << Maz.get_power() << std:: endl;
     std::cout << Maz.get_capacity() << std::endl;

    Lorry Kraz; //объект дочернего класса
    // чтение полей объекта
    std::cout << "Значения полей объекта KRAZ" << std::endl;
    std::cout << Kraz.get_car_name() << std::endl;    
    std::cout << Kraz. get_cnt_cylinder() << std::endl;
    std::cout << Kraz.get_power() << std:: endl;
    std::cout << Kraz.get_capacity() << std::endl;
    
   std::cout << Kraz; // перегруженный оператор 

    Kraz = Maz; //оператор присвоения перегруженый
    std::cout << "Значения полей объекта KRAZ после присвоения значений MAZ" << std::endl;
    std::cout << Kraz; // оператор вывода перегруженый в классе Cars
    
    Lorry Man("Man", 10 ,600, 400);
    std::cout << Man;

    Maz = Man;
     std::cout << "Значения полей объекта Maz  после присвоения значений MAN" << std::endl;
    std::cout << Maz.get_car_name() << std::endl;    
    std::cout << Maz. get_cnt_cylinder() << std::endl;
    std::cout << Maz.get_power() << std:: endl;
    std::cout << Maz.get_capacity() << std::endl;

    std::cout <<  "количество объектов " << count() << std::endl;

    {
    Lorry Avto1(Man);
    Lorry Avto2(Man);
    std::cout <<  "количество объектов " << count() << std::endl;
    }

    std::cout <<  "количество объектов " << count() << std::endl;
    return 0;
}