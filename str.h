typedef struct Node {
    char letter;
    struct Node* nextLetter;
} String;

//Operations for "String"

/*
* Put all operations/methods here
*/

String* create(); //returns an empty struct Node*
String* add(String* s, char c);
String* insert(String* s, char c, int pos);
String* delete(String* s, int pos);
String* substitute(String* s, char *find, char *replace);

int compare(String* s1, String* s2);
int getLength(String* s);

void print(String* s);