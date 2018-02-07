#include "Date.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){

  int lineCount;
  int month;
  int day;
  int year;
   
   ifstream inputFile(argv[1]);
   ofstream outputFile(argv[2]);

 
  if(!inputFile.is_open()){
    cout << "Error opening input file!" << endl;
}
 
 if(!outputFile.is_open()){
    cout << "Error opening output file!" << endl;
}
  inputFile >> lineCount;
  Date dates[lineCount];
  int count = 0;
  while((inputFile >> month >> day >> year) && count <= lineCount){
     
          dates[count].set_month(month);
          dates[count].set_day(day);
          dates[count].set_year(year);
          count++;
}
     sort(&dates[0], &dates[lineCount], Date::compare);

   for(int i=0; i < lineCount ; i++){

      outputFile << dates[i].print() << endl;
}

   return 0;


}
