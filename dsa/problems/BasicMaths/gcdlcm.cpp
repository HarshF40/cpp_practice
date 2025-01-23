// (a*b) / GCD = LCM
// GCD is found by long division method, divided until you get remainder as 0, 
// the point when remainder is 0, the quotient is GCD
// __gcd
#include<iostream>
int gcd(int divident, int divisor){
	if(divisor % divident == 0)
		return divident;
	return gcd(divisor%divident, divident);
}

int main(void){
	const int GCD = gcd(12, 18);
	std::cout<<GCD<<"\n";
	const int LCM = (12 * 18) / GCD;
	std::cout<<LCM;
	return 0;
}
