## Exercise 00: Conversion of scalar types

C++98 Cast Types provides four types of explicit cast operators to handle conversions more safely and explicitly than C-style casting. Here’s a breakdown:</br>
- Note : For each exercise, type conversion must be handled using a specific type of casting.
- Your choice will be reviewed during the correction.

### static_cast: </br>
- *Used for conversions between compatible types.*</br>
- *Example: Converting from one numeric type to another (e.g., int to float), or safely downcasting from a base class to a derived class (when it's known to be safe at compile time).*</br>
- *Syntax: static_cast<type>(expression).*</br>

### dynamic_cast: </br>
- *Used for safe casting of polymorphic types (i.e., objects with virtual functions).*</br>
- *Checks at runtime whether the cast is valid, and returns nullptr for invalid casts when dealing with pointers.* </br>
- *Example: Casting a base class pointer to a derived class pointer.* </br>
- *Syntax: dynamic_cast<type>(expression).* </br>

### const_cast:
- *Used to add or remove the const or volatile qualifier from a variable.* </br>
- *Example: Removing const from a pointer to call a function that doesn’t take a const parameter.* </br>
- *Syntax: const_cast<type>(expression).* </br>

### reinterpret_cast:
- *Used for low-level, unsafe type conversions.* </br>
- *Allows conversion between unrelated types (e.g., converting a pointer to an integer or vice versa).* </br>
- *Should be used with caution, as it may break type safety.* </br>
- *Syntax: reinterpret_cast<type>(expression).* </br>


## Exercise 01: Serialization
```c
#include <iostream>

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
    unsigned long raw = reinterpret_cast<unsigned long>(ptr);
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


## Exercise 02: Polymorphism

Polymorphism: Implementing a system where objects of different derived classes can be treated uniformly via a base class.<\br>

using: <\br> 

```cpp
cpp dynamic_cast<C&>();
```

```cpp

              ->  object -> citroen
class -> car  ->  object -> Volvo
              ->  object -> jaguar
 ```

dynamic_cast in C++ is a casting operator used to safely 
convert pointers or references between classes in an inheritance hierarchy. <\br> It is particularly useful for performing downcasting, which is the process of converting a base class pointer or reference to a derived class pointer or reference. The key feature of dynamic_cast is that it performs runtime type checking, ensuring the validity of the cast. <\br>
Key Points about dynamic_cast:<\br>

 - Type-Safe Cast: It checks at runtime whether the cast is possible, 
  and if it's invalid, it either returns nullptr (for pointers) or throws a std::bad_cast exception (for references).<\br>

 - Usage Scope: It works only with polymorphic types, i.e., classes that
   have at least one virtual function.<\br>

 - Performance: Since it performs runtime type checking, 
   it has a slight performance overhead.<\br>