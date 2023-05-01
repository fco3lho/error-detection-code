#include <iostream>
#include <string>

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
  string modifiedText = createCDE("OlW, mundo");
  
  cout << "Texto transmitido: " << originalText << endl;
  cout << "Texto recebido: " << modifiedText << endl;

  compareText(originalText, modifiedText);

  return 0;
}