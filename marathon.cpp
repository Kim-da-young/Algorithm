#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>

using namespace std;

int main()
{
	vector<string> par = { "marina", "josipa", "nikola", "vinko", "filipa" };
	vector<string> com = { "josipa", "filipa", "marina", "nikola" };
	ostringstream vts;
	copy(par.begin(), par.end(), ostream_iterator<string>(vts, ""));
	string a = vts.str();
	for (int i = 0; i < com.size(); i++)
	{
		int j = a.find(com[i]);
		cout << a << endl;
		cout << j << "   " << com[i] << " " << com[i].length() << endl;
		a.erase(j, com[i].length());
		cout << a << endl << endl;
	}
	cout << a << endl;
	return 0;
}
