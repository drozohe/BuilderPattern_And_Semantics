#include "HtmlElement.h"
#include <sstream>
#include <memory>

using namespace std;
HtmlElement::HtmlElement() 
{
    cout << "ctor called" << endl;
}

HtmlElement::HtmlElement(const string& name, const string& text) : name(name), text(text) 
{
    cout << "ctor called with name and text" << endl;
}

string HtmlElement::str(int indent) const 
{
    ostringstream oss;
    string i(indent_size * indent, ' ');
    oss << i << "<" << name << ">" << endl;
    if (text.size() > 0) 
    {
        oss << string(indent_size * (indent + 1), ' ') << text << endl;
    }
    
    for (const auto& e : elements) 
    {
        oss << e.str(indent + 1);
    }
    
    oss << i << "</" << name << ">" << endl;
    return oss.str();
}

HtmlElement::HtmlElement(HtmlElement &&other) noexcept // move constructor
{
    cout << "move ctor called" << endl;
    name = std::move(other.name);
    text = std::move(other.text);
    elements = std::move(other.elements);
}
HtmlElement &HtmlElement::operator=(HtmlElement &&other) noexcept // move assignment operator
{
    cout << "move assignment operator called" << endl;
    if (this == &other) return *this;
    name = std::move(other.name);
    text = std::move(other.text);
    elements = std::move(other.elements);
    return *this;
}
HtmlElement::HtmlElement(const HtmlElement &other) // copy constructor
{
    cout << "copy ctor called" << endl;
    name = other.name;
    text = other.text;
    elements = other.elements;
}
HtmlElement &HtmlElement::operator=(const HtmlElement &other) // copy assignment operator
{
    cout << "copy assignment operator called" << endl;
    if (this == &other) return *this;
    name = other.name;
    text = other.text;
    elements = other.elements;
    return *this;
}
