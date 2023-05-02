#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string createCDE(string text){
  int ascii = 0;

  for(long unsigned int i = 0; i < text.size(); i++){
    ascii = ascii + text[i];
  }

  int CDE = ascii%256;
  char charCDE = CDE;
  string textWithCDE = text + charCDE;

  return textWithCDE;
}

string generateError(string text){
  srand(time(nullptr));
  float ascii = 0;

  for(long unsigned int i = 0; i < text.size(); i++){
    float percent = rand() % 50;
    text[i] = text[i] * (1 + (percent/1000));
    ascii = ascii + text[i];
  }

  int CDE = (int)ascii%256;
  char charCDE = CDE;
  string textWithCDE = text + charCDE;

  return textWithCDE;
}

void compareText(string original, string modified){
  int originalCode, modifiedCode;
  
  originalCode = original[original.size()-1];
  modifiedCode = modified[modified.size()-1];

  if(originalCode == modifiedCode){
    cout << "Não houve erro na transmissão." << endl;
  } else {
    cout << "Houve erro na transmissão." << endl;
  }
}

int main(){
  string originalText = createCDE("Ola, mundo");
  string modifiedText = generateError(originalText);
  
  cout << "Texto transmitido: " << originalText << endl;
  cout << "Texto recebido: " << modifiedText << endl;

  compareText(originalText, modifiedText);

  return 0;
}