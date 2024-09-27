// Simple lotto 649 numbers generated

int myArray[49] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48, 49};
int myresult[6] = {1, 2, 3, 4, 5, 6};

void setup() {
  randomSeed(analogRead(0));
  Serial.begin(115200);
  }
void loop() {
  // Randomly shuffle the order of myArray then place 0-6 array elements into myresults array
  randomize(myArray);
  for (int i = 0; i < 6; i++) {
    myresult[i] = myArray[i];
  }
  Serial.println("");
  // Now using a qsort method sort the choose number 
  int n = sizeof(myresult) / sizeof(myresult[0]);
  qsort(myresult, n, sizeof(int), compare);
  for(int i = 0; i < 6; i++){
    Serial.print(myresult[i]);
    Serial.print("    ");
  }
  Serial.println("");
  
  delay(2000);
}
void swap (int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void randomize(int myArray[]) {
  // How many times do I want to reshuffle the array to really mix the random order of the shuffled array (between 2 - 5 times)
  for (int myi = 0 ; myi < random(2,5); myi++) {
    for (int i = 0; i < 49; i++) {
      long j = random(0, 49);
      swap(&myArray[i], &myArray[j]);
    }
  }
}

// Comparison function
int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}
