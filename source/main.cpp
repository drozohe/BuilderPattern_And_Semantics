#include "HtmlBuilder.h"
#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char* argv[]) {
    cout << "C++ Builder pattern" << endl;

    // HtmlBuilder builder{"ul"};
    // builder.addChild("li", "hello");
    // builder.addChild("li", "world");
    // cout << builder.str() << endl;

    // // use fluent interface with a list of consoles and videogames
    // HtmlBuilder builder2{"ul"};
    // builder2
    //     .addChild("li", "PlayStation 5")
    //     .addChild("li", "Xbox Series X")
    //     .addChild("li", "Nintendo Switch")
    //     .addChild("li", "PC");
    // cout << builder2.str() << endl;

    // // Usar move semantics
    // HtmlBuilder builder3 = std::move(builder2);
    // cout << builder3.str() << endl;

    // // Usar copy semantics
    // HtmlElement element1{"div", "Hello World"};
    // HtmlElement element2 = element1; // copy constructor
    // HtmlElement element3;
    // element3 = element1; // copy assignment operator

    // cout << element2.str() << endl;
    // cout << element3.str() << endl;

// Crear un HtmlBuilder y agregar elementos usando unique_ptr
    // unique_ptr<HtmlBuilder> builder = make_unique<HtmlBuilder>("ul");
    // builder->addChild("li", "hello");
    // builder->addChild("li", "world");
    // cout << builder->str() << endl;

    // // Usar la interfaz fluida para agregar elementos
    // unique_ptr<HtmlBuilder> builder2 = make_unique<HtmlBuilder>("ul");
    // builder2->addChild("li", "PlayStation 5")
    //         .addChild("li", "Xbox Series X")
    //         .addChild("li", "Nintendo Switch")
    //         .addChild("li", "PC");
    // cout << builder2->str() << endl;

    // // Usar move semantics con unique_ptr
    // unique_ptr<HtmlBuilder> builder3 = std::move(builder2);
    // cout << builder3->str() << endl;

    // // Usar copy semantics con shared_ptr
    // shared_ptr<HtmlElement> element1 = make_shared<HtmlElement>("div", "Hello World");
    // shared_ptr<HtmlElement> element2 = element1; // shared_ptr copy
    // shared_ptr<HtmlElement> element3 = make_shared<HtmlElement>();
    // *element3 = *element1; // copy assignment operator

    // cout << element2->str() << endl;
    // cout << element3->str() << endl;

    // Crear una estructura HTML compleja
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