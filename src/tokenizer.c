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
      return s+1;
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
  return word+i;
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

char *copy_str(char *inStr, short len){
  char *copy = malloc((len + 1) * sizeof(char));
  int i;
  for(i = 0; i < len; i++){
    copy[i] = inStr[i];//creating the copy
  }
  copy[i] = '\0';// creating the zero terminator and set it at the end
  return copy;
}

char **tokenize(char *s){
  int numWords = count_words(s);
  char **tokens = malloc((numWords+1) * sizeof(char *));
  char *portion = s;
  int i;
  for(i=0; i < numWords; i++){
    portion = word_start(portion);//next word
    int length = word_length(portion);
    tokens[i] = copy_str(portion, length);
    portion = word_terminator(portion);
  }
  tokens[i] = 0;//last token null
  return tokens;
}
void print_tokens(char **tokens){
  int i;
  for(i=0; tokens[i] != 0; i++){
    printf("%s\n",*(tokens));
  }
}
void free_tokens(char **tokens){
  int i;
  for(i = 0; tokens[i] != 0; i++){
    free(tokens[i]);
  }
  free(tokens[i]);
}

int word_length(char *str){
  int length = 0;
  int i;
  for(i = 0; *(str+i) != '\0'; i++){
    if(non_space_char(*(str+1))){
	length += 1;
      }
      else{
	break;//found the end of the word
      }
  }
  return length;
}

short string_length(char *str){
  short length = 0;
  int i = 0;
  for(i=0; *(str+i) != '\0'; i++){
    length += 1;//stops at zero terminator
  }
  return length;
}
