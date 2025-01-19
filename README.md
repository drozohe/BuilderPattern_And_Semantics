# BuilderPattern_And_Semantics

## Overview
This project demonstrates the Builder Pattern in C++ to construct a complex HTML structure. The Builder Pattern is used to create an object step by step, allowing for more readable and maintainable code. Additionally, the project showcases the use of move semantics to efficiently manage resources.

## Project Structure
- `include/`: Contains header files for `HtmlBuilder` and `HtmlElement`.
- `source/`: Contains implementation files for `HtmlBuilder`, `HtmlElement`, and the `main` function.
- `output/`: Contains build output files.
- `.gitignore`: Specifies files and directories to be ignored by Git.
- `LICENSE`: Contains the MIT license for the project.
- `README.md`: Contains the project description.
- `BuilderPatternAndSemantics.code-workspace`: VS Code workspace configuration file.

## Code Explanation

### `include/HtmlElement.h`
Defines the `HtmlElement` class, which represents an HTML element. It includes:
- **Member Variables**:
  - `name`: The name of the HTML element (e.g., `div`, `p`).
  - `text`: The text content of the HTML element.
  - `elements`: A vector of child `HtmlElement` objects.
  - `indent_size`: The size of indentation for pretty-printing the HTML.
- **Constructors**:
  - Default constructor.
  - Parameterized constructor to initialize `name` and `text`.
  - **Move constructor and move assignment operator** for efficient resource management.
  - Copy constructor and copy assignment operator.
- **Methods**:
  - `str(int indent = 0) const`: Generates the HTML string representation of the element with proper indentation.

### `include/HtmlBuilder.h`
Defines the `HtmlBuilder` class, which helps in constructing `HtmlElement` objects. It includes:
- **Member Variables**:
  - `root`: The root `HtmlElement` being constructed.
- **Constructors**:
  - Parameterized constructor to initialize the root element's name.
  - **Move constructor and move assignment operator** for efficient resource management.
  - **Deleted copy constructor and copy assignment operator** to prevent copying.
- **Methods**:
  - `getRoot()`: Returns a reference to the root `HtmlElement`.
  - `addChild(std::string child_name, std::string child_text)`: Adds a child element to the root.
  - `str() const`: Generates the HTML string representation of the root element.

### `source/HtmlElement.cpp`
Implements the `HtmlElement` class. It includes:
- **Constructors**:
  - Default constructor.
  - Parameterized constructor to initialize `name` and `text`.
  - **Move constructor and move assignment operator** for efficient resource management.
  - Copy constructor and copy assignment operator.
- **Methods**:
  - `str(int indent = 0) const`: Generates the HTML string representation of the element with proper indentation.

### `source/HtmlBuilder.cpp`
Implements the `HtmlBuilder` class. It includes:
- **Constructors**:
  - Parameterized constructor to initialize the root element's name.
  - **Move constructor and move assignment operator** for efficient resource management.
  - **Deleted copy constructor and copy assignment operator** to prevent copying.
- **Methods**:
  - `getRoot()`: Returns a reference to the root `HtmlElement`.
  - `addChild(std::string child_name, std::string child_text)`: Adds a child element to the root.
  - `str() const`: Generates the HTML string representation of the root element.

### `source/main.cpp`
The entry point of the application. It demonstrates the use of the `HtmlBuilder` to create a complex HTML structure. It includes:
- Creating an `HtmlBuilder` for the root `html` element.
- Adding child elements like `head`, `title`, `body`, `h1`, `p`, and `ul` with `li` elements.
- Printing the generated HTML string to the console.

### Design Pattern: Builder Pattern
The Builder Pattern is used to construct a complex object step by step. In this workspace:
- `HtmlElement` represents the complex object.
- `HtmlBuilder` is the builder that constructs the `HtmlElement` object.

### Semantics
- **Move Semantics**: Used in `HtmlElement` and `HtmlBuilder` to efficiently transfer resources without copying. This is particularly useful when dealing with large objects or resources that are expensive to copy.
  - **Move Constructor**: Transfers ownership of resources from one object to another without copying.
  - **Move Assignment Operator**: Transfers ownership of resources from one object to another without copying, and cleans up the resources of the original object.
- **Copy Semantics**: Provided for completeness but deleted in `HtmlBuilder` to prevent copying. Copying can be expensive and unnecessary in this context.

### Example Usage
In the `main.cpp` file, we demonstrate how to use the `HtmlBuilder` to create a complex HTML structure:
```cpp
#include "HtmlBuilder.h"
#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char* argv[]) {
    cout << "C++ Builder pattern" << endl;

    // Create a complex HTML structure
    unique_ptr<HtmlBuilder> builder = make_unique<HtmlBuilder>("html");
    builder->addChild("head", "")
            .addChild("title", "Complex HTML Structure");

    unique_ptr<HtmlBuilder> bodyBuilder = make_unique<HtmlBuilder>("body");
    bodyBuilder->addChild("h1", "Welcome to My Website")
                .addChild("p", "This is a paragraph.");

    unique_ptr<HtmlBuilder> listBuilder = make_unique<HtmlBuilder>("ul");
    listBuilder->addChild("li", "Item 1")
                .addChild("li", "Item 2")
                .addChild("li", "Item 3");

    bodyBuilder->getRoot().elements.emplace_back(std::move(listBuilder->getRoot()));
    builder->getRoot().elements.emplace_back(std::move(bodyBuilder->getRoot()));

    cout << builder->str() << endl;

    return 0;
}
```

This example creates an HTML structure with nested elements and prints it to the console. The use of move semantics ensures efficient resource management.

Move Semantics in Action
Here are some code snippets highlighting where move semantics are used:

### Move Semantics in Action
Here are some code snippets highlighting where move semantics are used:

##### **Move Constructor in `HtmlElement`**
```cpp

// filepath: include/HtmlElement.h
HtmlElement(HtmlElement&& other) noexcept
    : name(std::move(other.name)),
      text(std::move(other.text)),
      elements(std::move(other.elements)) {}
```
  - The move constructor is called when an `HtmlElement` object is initialized with an rvalue reference (e.g., `HtmlElement newElement = std::move(oldElement);`).
  - std::move is used to cast the member variables (name, text, elements) to `rvalue`references.
  - **The resources (e.g., strings and vectors) are transferred from other to the new object without copying.**
  - The other object is left in a valid but unspecified state.
  
##### **Move Assignment Operator in `HtmlElement`**
```cpp
  // filepath: include/HtmlElement.h
HtmlElement& operator=(HtmlElement&& other) noexcept {
    if (this != &other) {
        name = std::move(other.name);
        text = std::move(other.text);
        elements = std::move(other.elements);
    }
    return *this;
}
```
 - The move assignment operator is called when an existing `HtmlElement` object is assigned an rvalue reference (e.g., `existingElement = std::move(newElement);)`.
 - std::move is used to cast the member variables (name, text, elements) to rvalue references.
 - The resources are transferred from other to the existing object without copying.
 - The other object is left in a valid but unspecified state.
 - The existing object's resources are cleaned up before the transfer to avoid memory leaks.

### Move Constructor in `HtmlBuilder`
```cpp
// filepath: include/HtmlBuilder.h
HtmlBuilder(HtmlBuilder&& other) noexcept
    : root(std::move(other.root)) {}
```

**Explanation**:
1. The move constructor is called when an `HtmlBuilder` object is initialized with an rvalue reference (e.g., `HtmlBuilder newBuilder = std::move(oldBuilder);`).
2. `std::move` is used to cast the `root` member variable to an rvalue reference.
3. The `root` `HtmlElement` is transferred from `other` to the new `HtmlBuilder` object without copying.
4. The `other` object is left in a valid but unspecified state.

### Move Assignment Operator in `HtmlBuilder`
```cpp
// filepath: include/HtmlBuilder.h
HtmlBuilder& operator=(HtmlBuilder&& other) noexcept {
    if (this != &other) {
        root = std::move(other.root);
    }
    return *this;
}
```
**Explanation**:
1. The move assignment operator is called when an existing `HtmlBuilder` object is assigned an rvalue reference (e.g., `existingBuilder = std::move(newBuilder);`).
2. `std::move` is used to cast the `root` member variable to an rvalue reference.
3. The `root` `HtmlElement` is transferred from `other` to the existing `HtmlBuilder` object without copying.
4. The `other` object is left in a valid but unspecified state.
5. The existing object's `root` is cleaned up before the transfer to avoid memory leaks.