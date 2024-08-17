/*Write a class template named Triad that has 3 private data members with independent type template parameters. The class should have a constructor, access functions, and a print() member function that is defined outside the class.

The following program should compile and run:

#include <iostream>
#include <string>

int main()
{
	Triad<int, int, int> t1{ 1, 2, 3 };
	t1.print();
	std::cout << '\n';
	std::cout << t1.first() << '\n';

	using namespace std::literals::string_literals;
	const Triad t2{ 1, 2.3, "Hello"s };
	t2.print();
	std::cout << '\n';

	return 0;
}
and produce the output:

[1, 2, 3]
1
[1, 2.3, Hello]
*/

#include <iostream>
#include <string>

template <typename T,typename U,typename V>
class Triad{
  private:
    T data1;
    U data2;
    V data3;

  public:
    Triad(const T& a,const U& b,const V& c) : data1{a},data2{b},data3{c} {}

    const T& first() const {
      return data1;
    }

    const U& second() const {
      return data2;
    }

    const V& third() const {
      return data3;
    }

    void print() const ;

};

template <typename T,typename U,typename V>
 void Triad<T,U,V>::print() const {
      std::cout<<'['<<data1<<", "<<data2<<", "<<data3<<']';
    }


int main()
{
	Triad<int, int, int> t1{ 1, 2, 3 };
	t1.print();
	std::cout << '\n';
	std::cout << t1.first() << '\n';

	using namespace std::literals::string_literals;
	const Triad t2{ 1, 2.3, "Hello"s };
	t2.print();
	std::cout << '\n';

	return 0;
}

