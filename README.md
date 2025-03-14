## Exercise 00: Conversion of scalar types

C++98 Cast Types provides four types of explicit cast operators to handle conversions more safely and explicitly than C-style casting. Here’s a breakdown:

### static_cast: </br>
- **Used for conversions between compatible types.**</br>
- **Example: Converting from one numeric type to another (e.g., int to float), or safely downcasting from a base class to a derived class (when it's known to be safe at compile time).**</br>
- **Syntax: static_cast<type>(expression).**</br>


## Exercise 01: Serialization
```c
#include <iostream>
#include <cstdint> // For uintptr_t

typedef struct Data {
    int a;
    std::string b;
} data;

int main() {
    
    data value;

    value.a = 42;
    value.b = "Nigel";
    
    data* ptr = &value; // Pointer to data

    // Serialize pointer: Convert the pointer to an integer
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    std::cout << "Serialized pointer (as integer): " << raw << std::endl;

    // Deserialize pointer: Convert the integer back to a pointer
    data* deserializedPtr = reinterpret_cast<data*>(raw);
    std::cout << "Deserialized value: " << deserializedPtr->a << std::endl;
    std::cout << "Deserialized value: " << deserializedPtr->b << std::endl;
    return 0;
}
```
### output
```sql
➜  ex01 git:(main) ✗ ./serialization
Serialized pointer (as integer): 140701832926068
Deserialized value->a: 42
Deserialized value->b: Nigel
➜  ex01 git:(main)
```
