#include <stdio.h>
#include "str.h"

int main(void) {

  String *s1, *s2;

  s1 = create();
  s2 = create();
  
  add (s1, 'H');
  add (s1, 'e');
  add (s1, 'l');
  add (s1, 'l');
  add (s1, 'o');
  add (s1, '!');

  add (s2, 'H');
  add (s2, 'e');
  add (s2, 'l');
  add (s2, 'l');
  add (s2, 'o');
  add (s2, ' ');
  add (s2, 'W');
  add (s2, 'o');
  add (s2, 'r');
  add (s2, 'l');
  add (s2, 'd');
  add (s2, '!');
  
  print(s1);
  print(insert(s1, 'i', 2));
  print(delete(s1, 2));
  print(s2);
  print(substitute(s2, "World", "LEZGOOOOOOOOOooooooo"));
  printf("%d\n%d\n", getLength(s2), compare(s1,s2));


  //Dont mind everything below, am just testing stuff -Christian
  printf("\n\n\n\n");
  String *test;

  test = create();

  add (test, 'H');
  add (test, 'e');
  add (test, 'l');
  add (test, 'l');
  add (test, 'o');
  add (test, ' ');
  add (test, 'W');
  add (test, 'o');
  add (test, 'r');
  add (test, 'l');
  add (test, 'd');
  add (test, '!');

  print(test);
  print(delete(test, 0));
  print(insert(test, 'o', 5));
  print(substitute(test, "Hello World", "Nyaa~~"));
  print(substitute(test, "llo World!", "ntai Haven     ~ Y E S ~"));
  print(substitute(test, " ", "~<insert space>~"));

  print(substitute(substitute(test, "Hello World!", "ABDEEFG"), "DEE", "JKLMOP"));

  return 0;
}