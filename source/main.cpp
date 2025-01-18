#include "HtmlBuilder.h"
#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char* argv[]) {
    cout << "C++ Builder pattern" << endl;

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