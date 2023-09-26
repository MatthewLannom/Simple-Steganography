/**
 * @file main.cpp
 * @author Kevin Austin
 * @date 2023-09-24
 * @brief Encodes or decodes ppm files
 * 
 * Takes the given ppm file and depending on whether the user wants to encode or decode, will act respectively
 */

#include <iostream>
#include <fstream>
#include <vector>

#include "Steganography.h"

using namespace std;

int main() {
  Steganography Steg;
  string opchoice;
  string ppmfile1;
  string textfile;
  
  int c=0;
  while(c != 1){
    cout << "Would you like to encode or decode? Please type either an 'e' for encode or a 'd' for decode" << endl; //Prompting the user for a choice
    cin >> opchoice; //Getting input from the console
    
    if(opchoice == "e" || opchoice == "E"){
      string ppmfile2;
      cout << "Please enter a PPM file name" << endl; //Prompting user
      cin >> ppmfile1; //Getting ppm file name from the console
      cout << "Please enter a text file name" << endl; //Prompting user
      cin >> textfile; //Getting text file name from the console
      Steg.readImage(ppmfile1); //Reading in a ppmfile
      cout << "PPM file has been read" << endl; 
      Steg.readCipherText(textfile); //Reading in a text file
      cout << "Text file has been read" << endl;
      Steg.encipher(); //Encoding text into the image
      cout << "Text has been encoded" << endl;
      cout << "Please enter a PPM file name to store the enciphered image" << endl; //Prompting user
      cin >> ppmfile2; //Getting ppm file name from the console
      Steg.printImage(ppmfile2); //Writing the enciphered image into another ppmfile
      
      c = 1; //Exiting the loop
    }
    else if(opchoice == "d" || opchoice == "D"){
      cout << "Please enter a PPM file name" << endl; //Prompting user
      cin >> ppmfile1; //Getting ppm file name from the console
      Steg.readImage(ppmfile1); //Reading in a ppm file
      cout << "File has been read" << endl;
      Steg.decipher(); //Deciphering the hidden text
      cout << "Text has been deciphered" << endl;
      cout << "Please enter a text file name to store the deciphered text" << endl;
      cin >> textfile; //Getting textfile name from the console
      Steg.printCipherText(textfile); //Writing the deciphered text into a file

      c = 1; //Exiting the loop
    }
    else {
      cout << "Input must be e or d" << endl; //Letting the user know that their input is invalid before looping back to ask them again
	}
  }
  
  return 0;
}
