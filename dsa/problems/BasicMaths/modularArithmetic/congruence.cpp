// A ≡ B (mod C)
// this means that A / C gives the same remainder as B / C
// or the difference between A and B is divisibe by C
// Modular arithmetic deals with remainders
// divide a by n and let the quotient be q and the remainder r, then we have
// a = nq + r which implies a ≡ r (mod n)
#include<iostream>
int main(void){
	const int B = 0;
	const int C = 5;
	for(int A = 0; A < 100; A++){
		if(!((A-B)%C))
			std::cout<<A<<" ";
	}
	return 0;
}
