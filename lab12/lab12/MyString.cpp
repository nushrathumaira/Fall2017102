#include "MyString.hpp"

// use initializer list 
MyString::MyString() : data(NULL), size(0){}

MyString::MyString(const char* string)
  : data(new char[strlen(string)+1]), size(strlen(string)){

  for(int i =0; i < this->size ; i++){
   this->data[i] = string[i];
  }
  this->data[this->size] = '\0';
}
MyString::MyString(const MyString& myString)
  : data(new char[myString.size + 1]), size(myString.size){
  for(int i=0; i < this->size; i++)
  {
     this->data[i] = myString.data[i];
   }
  this->data[this->size] = '\0';
}
MyString::~MyString(){

if(this->size > 0)
{
  delete [] this->data;
}

}
int MyString::len () const {
  return this->size;
}
MyString& MyString::operator= (const MyString& myString){
  if(myString.size > this->size){
    delete [] this->data;
    this->data = new char[myString.size + 1];
    this->size = myString.size;
    
  }
  for(int i=0; i < myString.size; i++)
  {
     this->data[i] = myString.data[i];
   }
  this->data[this->size] = '\0';
  return *this;
}
MyString& MyString::operator= (const char* string){
  if(strlen(string) > this->size){
    delete [] this->data;
    this->data = new char[strlen(string) + 1];
    this->size = strlen(string);
    
  }
  for(int i=0; i < strlen(string); i++)
  {
     this->data[i] = string[i];
   }
  this->data[this->size] = '\0';
  return *this;
}
MyString operator+ (const MyString& myString1, const MyString& myString2){
  char* combinedString = new char[myString1.size + myString2.size + 1];
  int combinedStringIndex = 0;
  for(int i =0; i < myString1.size; i++)
  {
      combinedString[combinedStringIndex] = myString1[i];
      combinedStringIndex++;
  }
  for(int i =0; i < myString2.size; i++)
  {
      combinedString[combinedStringIndex] = myString2[i];
      combinedStringIndex++;
  }
  combinedString[combinedStringIndex] = '\0';
  
  MyString tempMyString(combinedString);
  delete [] combinedString;
  return tempMyString;
}
  
MyString operator+ (const MyString& myString, const char* string){
  return myString + MyString(string);
}
MyString operator+ (const char* string, const MyString& myString){
  return MyString(string) + myString;
}
char MyString::operator[] (int ndx) const{
  if(ndx >=0 && ndx < this->size){
  return this->data[ndx];
  }
  else{
  cout << "Invalid array index! terminating !" << endl;
  exit(-1);
  }
}
ostream& operator<<(ostream& os, const MyString& myString){
  for(int i =0; i < myString.size ; i++)
  {
     os << myString.data[i];
  }
  return os;
}
