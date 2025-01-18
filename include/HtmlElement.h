#ifndef HTML_ELEMENT_H
#define HTML_ELEMENT_H

#include <string>
#include <vector>
#include <iostream>
#include <memory>

class HtmlBuilder;
class HtmlElement {
    friend class HtmlBuilder;
    std::string name;
    std::string text;
    const size_t indent_size = 2;
public:
    HtmlElement();
    HtmlElement(const std::string& name, const std::string& text);
    std::string str(int indent = 0) const;
    
    HtmlElement(HtmlElement&& other) noexcept; // move constructor
    HtmlElement& operator=(HtmlElement&& other) noexcept; // move assignment operator
    
    HtmlElement(const HtmlElement& other); // copy constructor
    HtmlElement& operator=(const HtmlElement& other); // copy assignment operator
    
    std::vector<HtmlElement> elements;
};

#endif