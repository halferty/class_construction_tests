#include <stdio.h>

void printPerson(char *);
void printFlavor(char *);
void printArray(void *[], void (*)(void *));

int main() {
  char *flavors[4] = {
    "Choc", "Stra", "Vann", 0
  };
  char *people[5] = {
    "Aristotle", "Lincoln", "Confucius", "Shakespeare", 0
  };
  // Casts just to avoid warnings.
  printArray((void *)flavors, (void *)printFlavor);
  printArray((void *)people, (void *)printPerson);
  return 0;
}
void printPerson(char *thePerson) {
  printf("The person: %s\n", thePerson);
}
void printFlavor(char *theFlavor) {
  printf("The flavor: %s\n", theFlavor);
}
void printArray(void *theArray[], void (*printFunction)(void *theElement)) {
  int n;
  for (n = 0; theArray[n]; n++) {
    (*printFunction)(theArray[n]);
  }
  printf("---\n");
}

