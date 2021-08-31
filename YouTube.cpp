#include <iostream>

//using namespace std;	// --> std'nin hepsini kullan demektir.
using std::cout;   // --> std dizinindeki cout u kullan demektir.

int main()
{
	cout << "Hello World!";
}





#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int sayi = 10;
	cout << "Hello World! " << endl <<'\n' << "My name is ismail. " << sayi;		// --> Ýstediðin kadar "<<" iþareti kullan...Ýþlev ayný..
	
	int variable;
	cout << "\nEnter a number: ";
	cin >> variable;
	cout << "Number is:\t" << variable;
}





#include <iostream>

using namespace std;


int main(){
	
	int sayi = 12;
	long uzun_tam_sayi = 2112321212;
	double long uzun_kesirli_sayi = 12.1233333333333333333333333331111111111111111111111132132132312;
	string message = "Nasilsin gardasimmm";
	
	cout << sayi <<endl << uzun_tam_sayi << endl << uzun_kesirli_sayi << endl << message << endl;
	
	int a=1, b=2, c;
	
	c = (a>b)? a:b;																					// --> Primitive gösterim. if koþullarý yani........
	
	cout << c;
}
