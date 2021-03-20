/* Measure the amount of free dynamic memory on AVR-based Arduino */

String a = "a";

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print("SRAM Free: ");
  Serial.print(memoryFree());
  Serial.print(" bytes.  ");
  Serial.print("String length: ");
  Serial.println(a.length());
  a += "a";
}

extern int *__brkval;

int memoryFree(){
  int freeValue;
  if((int)__brkval == 0){
    freeValue = ((int)&freeValue)-((int)__malloc_heap_start);  
  }
  else{
    freeValue = ((int)&freeValue)-((int)__brkval);  
  }
  return freeValue;
}
