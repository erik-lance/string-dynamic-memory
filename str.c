#include <stdio.h> //printf
#include <stdlib.h> //malloc
#include <string.h> //strlen
#include "str.h"

/*
* Creates a new String struct with null value
* @return The empty string created
*/
String* create(){
  String* newStr = (String*)malloc(sizeof(String));
  newStr->nextLetter = NULL;
  return (newStr);
}

/*
* Adds given letter at the end of the string
* @param s address to the first character of the string
* @param c character to be added
* @return pointer to the first letter of the string
*/
String* add(String* s, char c){
  String* head = s;

  while(s->nextLetter != NULL){
    s = s->nextLetter;
  }
  s->letter = c;
  s->nextLetter = create();
  return head;
}

/*
* Inserts a letter to a given position in the string
* @param s address to the first character of the string
* @param c character to be added
* @param pos index to insert the character
* @return pointer to the first letter of the string
*/
String* insert(String* s, char c, int pos){
  String* newStr = create(); 
  int i;

  for(i=0; i<pos; i++){
    add(newStr, s->letter);
    s = s->nextLetter;
  }
  add(newStr, c); //add the new letter
  while (s->nextLetter != NULL){
    add(newStr, s->letter);
    s = s->nextLetter;
  }

  return newStr;
}

/*
* Deletes the letter in the given position in the string
* @param s address to the first character of the string
* @param pos index to insert the character
* @return pointer to the first letter of the string
*/
String* delete(String* s, int pos){
  String* newStr = create(); 
  int i;

  for(i=0; i<pos; i++){
    add(newStr, s->letter);
    s = s->nextLetter;
  }
  s = s->nextLetter; //skip the node
  while (s->nextLetter != NULL){
    add(newStr, s->letter);
    s = s->nextLetter;
  }

  return newStr;
}

String* substitute(String* s, char *find, char *replace){
  String* newStr = create();
  String* temp = s; //store head
  int i=0, j=0;
  int findIndex=0, findLength = strlen(find);
  int replaceLength = strlen(replace), replaceIndex=0;

  
  while(findIndex != findLength && s != NULL){
    //printf("index: %d %c==%c\n",i, s->letter, *(find+findIndex));
    if(s->letter == *(find+findIndex))
      findIndex++;
    else
      findIndex=0;
    s = s->nextLetter;
    i++;
  }
  
  if(findIndex != findLength){
    printf("Error: substitution couldn’t be performed\n");
    return NULL;
  }
  else { //REPLACING PART

    //printf("%d %d %d %d\n", i, findLength, replaceLength,i-findLength);
    while (temp != NULL){
      if(j >= i-findLength && replaceIndex != replaceLength){
        add(newStr, *(replace+replaceIndex)); 
        replaceIndex++;

        if(j < i)
          temp = temp->nextLetter;
      }
      //takes care of skipping the find word
      else if(j >= i-findLength && j < i)
        temp = temp->nextLetter;
      else{ 
        add(newStr, temp->letter); //add yung hindi irereplace
        temp = temp->nextLetter;
      }   


      j++;
    }
  }

  return newStr;
}

int compare(String* s1, String* s2){

  while (s1->nextLetter != NULL && s2->nextLetter != NULL){
    if(s1->letter != s2->letter)
      return 0;
    s1 = s1->nextLetter;
    s2 = s2->nextLetter;
  }

  if(s1->nextLetter != NULL || s2->nextLetter != NULL)
    return 0; 

  return 1;
}

int getLength(String* s){
  int length = 0;
  while (s->nextLetter != NULL){
    length++;
    s = s->nextLetter;
  }

  return length;
}


void print (String* s){
  while(s != NULL){
    printf("%c", s->letter);
    s = s->nextLetter;
  }
  printf("\n");

}

