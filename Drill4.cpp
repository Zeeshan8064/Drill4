#include<iostream>
#include<cmath>
#include<vector>
#include"std_lib_facilities.h"
using namespace std;

int main() {
	//double a = 0.0;  
	//cout << "Input a= "; cin >> a; 
	int count=0;
	constexpr double m_per_inch = 0.0254, m_per_ft=0.3048,
	m_per_cm=0.01;
	double length=0.0,b=0.0,min=0.0,max=0.0,sum=0.0;
	char ch{}, unit{};
	bool flag = 0;
	vector<double>v;
	do {
		//cout << "a= " << a << endl;
		//cout << "b= " << b << endl;
		//a==b ? cout << "equal\n" : (abs(a - b) <= static_cast<float> (1) / 100) ? cout << "Almost equal!" << endl :
		//a > b ? cout << "smaller value is " << b << endl : cout <<"smaller value is " << a << endl;
		double metre = 0.0;
		cout << "Input a double= "; cin >> b;
		cout << "Please enter a length followed by a unit(c,m,i,f)= ";
		cin >> length >> unit;
		
			if (flag == 0) {
				min = max = b;
				cout << "max= " << max << endl << "min= " << min << endl;}
			else if (b > max){
				max = b;
				cout << "This is the maximum value so far! " << b << endl;}
			else if ( b < min){
				min = b;
				cout << "This is the minimum value so far! " << b << endl;}
			else{
				cout << "Min & Max is unchanged!"<<endl;} 
			
		switch(unit) {
		case 'i':
			cout << "Length= " << length << unit << endl;
			metre = m_per_inch*length;
			v.push_back(metre);
			sum += metre; 
			break;
		case 'c':
			cout << "Length= " << length << unit<<endl; 
			metre = m_per_cm * length;
			v.push_back(metre);
			sum += metre;
			break;
		case 'm':
			cout << "Length= " << length << unit<<endl;
			metre = length;
			sum += metre;
			v.push_back(metre);
			break;
		case 'f':
			cout << "Length= " << length << unit<<endl;
			metre = m_per_ft * length;
			v.push_back(metre);
			sum += metre;
			break;
		default:
			cout << "Sorry,I don't know a unit called '" << unit << "'\n"; break;
		}

		cout << "Press 'y' to continue= ";
			cin >> ch;
			count += 1;
			flag = 1;
	} while (ch == 'y');

	cout << "Number of values entered are= " << count<<endl;
	cout << "Sum of Length entered is= " << sum <<"m"<< endl;
	cout << "Max value entered is= " << max << endl;
	cout << "Min value entered is= " << min << endl;
	sort(v.begin(), v.end());
	cout << "Sorted lengths in vector are: \n";
	for (auto x : v)
		cout << x << " ";
	return 0;
}