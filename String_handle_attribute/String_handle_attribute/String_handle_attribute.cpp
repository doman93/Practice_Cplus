#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>


using namespace std;


int main()
{
	int n, q, i;
	cin >> n >> q;
	string temp;
	vector<string> hrml;
	vector<string> quer;
	cin.ignore();

	for (i = 0; i < n; i++)
	{
		getline(cin, temp);
		hrml.push_back(temp);
	}
	for (i = 0; i < q; i++)
	{
		getline(cin, temp);
		quer.push_back(temp);
	}

	map<string, string> m;
	vector<string> tag;

	for (i = 0; i < n; i++)
	{
		temp = hrml[i];
		// In string, " will be understand as \"
		// Remove all " in the string
		temp.erase(remove(temp.begin(), temp.end(), '\"'), temp.end());
		// Remove all > in the string
		temp.erase(remove(temp.begin(), temp.end(), '>'), temp.end());

		if (temp.substr(0, 2) == "</")
		{
			tag.pop_back();
		}
		else
		{
			stringstream ss;
			ss.str("");
			ss << temp;
			string t1, p1, v1;
			char ch;
			// auto read string without space " "
			ss >> ch >> t1 >> p1 >> ch >> v1;
			string temp1 = "";
			if (tag.size() > 0)
			{
				temp1 = *tag.rbegin();
				temp1 = temp1 + "." + t1;
			}
			else
			{
				temp1 = t1;
			}
			tag.push_back(temp1);
			m[*tag.rbegin() + "~" + p1] = v1;
			while (ss)  // equivalent to ss  >> p1 >> ch >> v1
				//  while (!a)  equi. a == 0   ; while(a)  equi. a! = 0 
			{
				ss >> p1 >> ch >> v1;
				m[*tag.rbegin() + "~" + p1] = v1;
			}
		}

	}

	for (i = 0; i < q; i++) {
		if (m.find(quer[i]) == m.end())
			cout << "Not Found!\n";
		else
			cout << m[quer[i]] << endl;
	}
	return 0;

}
