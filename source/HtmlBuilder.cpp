#include "HtmlBuilder.h"

using namespace std;
HtmlElement &HtmlBuilder::getRoot()
{
    return root;
}
HtmlBuilder::HtmlBuilder(std::string root_name)
{
    root.name = root_name;
}
HtmlBuilder& HtmlBuilder::addChild(std::string child_name, std::string child_text)
{
    HtmlElement e{child_name, child_text};
    root.elements.emplace_back(e);
    return *this;
}
std::string HtmlBuilder::str() const
{
    return root.str();
}

HtmlBuilder::HtmlBuilder(HtmlBuilder &&other) noexcept // move constructor
{
    cout << "move ctor called" << endl;
    root = std::move(other.root);
}

HtmlBuilder &HtmlBuilder::operator=(HtmlBuilder &&other) noexcept // move assignment operator
{
    cout << "move assignment operator called" << endl;
    if (this == &other) return *this;
    root = std::move(other.root);
    return *this;
}
