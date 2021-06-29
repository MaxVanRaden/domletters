#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int main (){
  //variables
  string input; //for storing the total input
  string line; //for adding each line to the input
  string word; //for analyzing each word
  int total = 0; //the total dominant letter count for the string
  int count = 0; //used to track the max number of occurences of a letter in a word

  while(getline(cin, line)) { //Populate input with the entire input file, adding a space after each line to prevent words sticking together
    input += line;
    input += " ";
  }
  for(int i = 0; input[i]; i++) { //Iterate through the input string, stopping when the input string is out of valid characters
    if(!isspace(input[i])) { //if not whitespace, add character to word
      word += input[i];
    }
    else { //found whitespace, parse word
      if(word[0]) {
        for(int j = 0; word[j]; j++) { //outer loop of blunt force trama
          int current = 1; //count of current letter appearances in word
          if(!isalpha(word[j])) {//if a character in the word is not alphabetic, exit the loop and continue on to next word
            count = 0;
            break;
          }
          for(int k = 0; word[k]; k++) { //inner loop of blunt force trama parsing, checks each letter against the outer loop's letter to get count
            if(j != k) {//not the same location in the string
              if(toupper(word[j]) == toupper(word[k]))
                current++;
            }
          }
          if(current > count)//checks if the current letter appears more often then the last most common letter
            count = current;
        }
        total += count; //adds most commonly appearing letter count to total
        word.clear(); //reset variables
        count = 0;
      }
    }
  }
  cout << total;
  return 0;
}
