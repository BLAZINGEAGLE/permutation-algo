
#include<iostream>
#include<string>
#include<math.h>

using namespace std;

//Forward declarations
int fact(int x);
string perm(string str, int permIndex);

//Algorithm test
int main()
{
	string str = "GAME";
	int length = str.length();
	
	for(int k = 0; k < fact(length); k++)
		cout << ":::: " << perm(str, k) << "\n" << endl;
	 
	system("pause");
}

string perm(string str, int permIndex)
{
	auto temp_str = str;
	int length = str.length();
	if(length == 1)
		return str;

	int f = fact(length - 1);
	int k = int(floor(permIndex/f));
	
	int j = permIndex % f;
	string sub = str.erase(k, 1);
	string psub = perm(sub, j);
	psub = temp_str[k] + psub;

	return psub;
}

//The factorial function. You might want to write a more efficient function
//One that does not employ recursion
int fact(int x)
{
	if(x <= 1)
		return 1;

	return x * fact(x - 1);
}
