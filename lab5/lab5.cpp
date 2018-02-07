#include "lab5.h"

using namespace std;

void bubble_sort(int* arr, int length)
{
  int number_swaps = -1;
  while(number_swaps != 0)
  {
    number_swaps = 0;
    for(int index =0; index < length -1; index++){
       if(arr[index] > arr[index+1]){
        swap(arr[index],arr[index+1]);
        number_swaps++;
        }
    }
  }

}


int main(int argc, char const *argv[]){

 /*http://www.cplusplus.com/doc/tutorial/files/ */
 /*
 ifstream/ofstream , stream classes to read/write to files
 */
 /*Since the first task that is performed on a file stream is generally to open a file, these    three classes include a constructor that automatically calls the open member function and has the exact same parameters as this member.*/
 /*ofstream myfile ("example.bin", ios::out | ios::app | ios::binary); */
 // constructor
 ifstream in_file(argv[1], ios::in);
 ofstream out_file(argv[2], ios::out);
 
 if(in_file.is_open() && out_file.is_open())
 {
   int length = 0;
   int num;
   // if i want to use formatted input , i should know the data type of file data in file
   // and read it into variable of according data type
   // since my file is txt file with lost of integers, I use >> operator to read it into 
   // an integer variable called num and do it in a loop so all intergers are taken into a
   //account

   while(in_file >> num)
   {
     length++;
   }
   // to reset a file and read from it a second time, use clear and seekg
   in_file.clear();
   in_file.seekg(0,ios::beg);
   
   int* arr = (int*)malloc(sizeof(int) * length);
   
   for(int i =0; i < length ; i++)
	in_file >> arr[i];
   //call bubble sort
   bubble_sort(arr, length);
   // output arr to out_file
   for(int i=0; i < length; i++)
        out_file << arr[i] << '\n';
   
 }
 else
 {
    cerr<<"Please provide an input and output file!"<<endl;
  }

  
 return 0;
}
