#include <iostream>
#include <string>

using namespace std;

#include "hmap.cpp"

size_t stringhash1 (const string& s, size_t htsize)
{

	size_t x = 0;

	for (char c : s)
	{
		x += c;
	}

	return x % htsize;
}

void testHMapCore ()
{

	//m(size,hashfn)
	HashMap<string,double> m(7,stringhash1);

	m["Kalin"] = 1.84;
	m["Kalin"] = 1.85;
	m["Ivan"] = 1.86;

	assert (m["Kalin"] == 1.85);
	assert (m["Ivan"] == 1.86);

	assert (m.containsKey("Kalin") == true);
	assert (m.containsKey("Petar") == false);

}
void testHMapCannonical ()
{
	HashMap<string,double> m(7,stringhash1);

	m["Kalin"] = 1.85;
	m["Ivan"] = 1.86;

	HashMap<string,double> m1(m);
	assert (m1["Kalin"] == 1.85);
	assert (m1["Ivan"] == 1.86);
	assert (m1.containsKey("Kalin") == true);
	assert (m1.containsKey("Petar") == false);

	m["Petar"] = 1.75;
	assert (m1.containsKey("Petar") == false);

	m1  = m;
	assert (m1.containsKey("Petar") == true);

	m["Zdravko"] = 1.79;
	assert (m1.containsKey("Zdravko") == false);
}

int main ()
{
	testHMapCore();
	testHMapCannonical();
}