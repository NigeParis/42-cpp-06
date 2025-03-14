# 42-cpp-06
```c
#include <iostream>
#include <stdint.h> // For uintptr_t

int main() {
    int value = 42;
    int* ptr = &value; // Pointer to an integer

    // Serialize pointer: Convert the pointer to an integer
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    std::cout << "Serialized pointer (as integer): " << raw << std::endl;

    // Deserialize pointer: Convert the integer back to a pointer
    int* deserializedPtr = reinterpret_cast<int*>(raw);
    std::cout << "Deserialized value: " << *deserializedPtr << std::endl;

    return 0;
}
```
##output
```c
Serialized pointer (as integer): 140701943735160
Deserialized value: 42
```
