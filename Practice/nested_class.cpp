#include<iostream>
#include<string>
#include<string_view>

class Employee{


  public:

    using IDtype = int;

    class Printer{


      public:

        void printer(const Employee& e) const {
          //can't access the private member of outer class directly because this class doesnt have access to this pointer of outer class
          //We can use an object of outer class to access the private members because this class is a member of the outer class.
          std::cout<<"\nName: "<<e.m_name<<"\nId: "<<e.m_id<<"\nWage: "<<e.m_wage;
        }

    };

  private:

    std::string m_name{};
    IDtype m_id{};
    double m_wage{};

  public:
    Employee(std::string_view name,IDtype id,double wage) : 
      m_name{name},
      m_id{id},
      m_wage{wage}
    {}

};

int main(){
  Employee john{"john",6,72000};
  const Employee::Printer P{};
  P.printer(john);
return 0;
}
