#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


const int ID_LEN = 4;
const int TITLE_LEN = 25;
const int PRICE_LEN = 10;

int main(int argc, char const *argv[]) {
	
	//ifstream finput (argv[1]);
	//ofstream foutput (argv[2]);
	std::ifstream finput("input.txt");
	/*
	if (finput.is_open()) {

		cout << "input file works ok!" << endl;

	}
	else {
		cout << "input file can't be opened!" << endl;
		finput.close();
	}
	*/
	std::ofstream foutput("output.txt");

	
	/*
	if (foutput.is_open()) {
	cout << "output file works ok!" << endl;
	}
	else {
	cout << "output file can't be opened!" << endl;
	foutput.close();
	}
	*/
	//string line;
	int lineCount = 0;
	int id; 
	std::string bookTitle;
	//long double price;


	

	/*
	Simply use these lines before attempting to input/output a currency value, 
	given that in is an ifstream and out is an ofstream. 
	in.imbue(std::locale("en_US.UTF-8"));  out.imbue(std::locale("en_US.UTF-8"));
	*/

	finput.imbue(std::locale("en_US.UTF-8"));
	foutput.imbue(std::locale("en_US.UTF-8"));


	
	/*
	while (getline(finput, line)) {
		lineCount++;
	}
	*/
	
	//cout << "total no. of line" << lineCount << endl;
	
	foutput << std::setw(ID_LEN) << "ID"
		    << std::setw(TITLE_LEN + 2) << "TITLE"
		    << std::setw(PRICE_LEN) << "PRICE"
		    << std::endl;

	while (finput >> id) {

		long double price;
		long double sumOfPrice = 0;
		int countOfPrice = 0;
		while (finput >> std::get_money(price)) {
			sumOfPrice += price;
			countOfPrice++;
		}
		finput.clear();
		std::getline(finput, bookTitle);

		if (bookTitle.length() > TITLE_LEN) {
			bookTitle.erase(TITLE_LEN - 1, std::string::npos);
			bookTitle.replace(TITLE_LEN - 3, std::string::npos, 3, '.');
		}
		foutput << std::setw(ID_LEN) << id
			<< std::setw(TITLE_LEN + 2) << bookTitle
			<< std::setw(PRICE_LEN) << std::put_money(sumOfPrice / (long double)countOfPrice)
			<< std::endl;

	}
	

	finput.close();
	foutput.close();
	//while (1);
	//cout << "Please enter a price value." << endl;
	//cin >> get_money(price);
	//cout << price << endl;
	return 0;
}
