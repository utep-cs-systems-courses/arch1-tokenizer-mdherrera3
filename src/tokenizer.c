#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  //checking what c is
  if((c == '\t' || c == ' ') && c != 0){
      //returns a digit due to return type
      return 1; // returns if char is a space or c
    }
    return 0;
}

int non_space_char(char c){
  //checking what c is
  //inverse of space char
  if((c != '\t' || c != ' ') && c != 0){
    return 1;
  }
  return 0;
}

char *word_start(char *s){
  int i;
  for(i=0; *(s+1) !='\0';i++){
    //word starts once there is no space
    if(non_space_char(*(s+1))){
      return s+1
    }
  }
  return s + 1;// if we go through entire word given then the start is at the start
}

char *word_terminator(char *word){
  int i;
  for(i=0;*(word+i) != '\0';i++){
    if(space_char){
      return word+i;
      }
  }
  return word+i
}

int count_words(char *s){
  int wordCount;
  char *start = word_start(s);
  while(*start != '\0'){
    if(non_space_char(*start)){
      wordCount += 1;
    }
    start = word_terminator(start);//we found the start of the word we can go directly to the end
    start = word_start(start);//finding the start of the next word
  }
  return wordCount;
}

char *copy_str(char inStr, short len){
  char *copy = malloc((len + 1) * sizeOf(char));
  int i;
  for(i = 0; i < len; i++){
    copy[i] = inStr[i];//creating the copy
  }
  copy[i] = '\0';// creating the zero terminator and set it at the end
  return copy;
}


