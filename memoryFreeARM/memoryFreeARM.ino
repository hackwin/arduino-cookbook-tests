/* Measure the amount of free dynamic memory on ARM-based Arduino */

String a = "a";

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print("Memory Free: ");
  Serial.print(memoryFree());
  Serial.print(" bytes.  ");
  Serial.print("String length: ");
  Serial.println(a.length());
  a += "a";
}

extern "C" char *sbrk(int incr);

int memoryFree(){
  int freeValue;
  freeValue = &freeValue - reinterpret_cast<int*>(sbrk(0));
  return freeValue;
}
