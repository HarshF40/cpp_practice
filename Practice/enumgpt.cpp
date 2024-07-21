//Problem: Define an enumeration for the days of the week. Write a function that takes a day as input and returns the next day. Bonus: Add functionality to convert the enumeration to a string and vice versa.

#include<iostream>
#include<string>
#include<type_traits>

enum Days : int {
  Error = 0,
  Sun,
  Mon,
  Tue,
  Wednes,
  Thurs,
  Fri,
  Sat,
};

Days getday(){
  std::string s{};
  std::cout<<'\n'<<"Enter A day: ";
  std::cin>>s;
  if(s=="Sunday")
  return Sun;
  else if(s=="Monday")
  return Mon;
  else if(s=="Tuesday")
  return Tue;
  else if(s=="Wednesday")
  return Wednes;
  else if(s=="Thursday")
  return Thurs;
  else if(s=="Friday")
  return Fri;
  else if(s=="Saturday")
  return Sat;
  else {
  std::cout<<"Error!\n";
  return Error;
  }
}

Days getnextday(Days day){
  switch(day){
    case Error : return Error;
    case Sat : return Sun;
    default : return (static_cast<Days>(static_cast<std::underlying_type_t<Days>>(day) + 1));
  }
}

std::string_view getDaystr(Days day){
  switch(day){
    case Sun : return "Sunday";
    case Mon : return "Monday";
    case Tue : return "Tuesday";
    case Wednes : return "Wednesday";
    case Thurs : return "Thursday";
    case Fri : return "Friday";
    case Sat : return "Saturday";
    default : return "???";
  }
}

std::ostream& operator<<(std::ostream& os, Days day){
  return os<<getDaystr(day);
}

int main(){
  Days day{getday()};
  Days nextday{getnextday(day)};
  std::cout<<"The next day: "<<nextday<<'\n';
}