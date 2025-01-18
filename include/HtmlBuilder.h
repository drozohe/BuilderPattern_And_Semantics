#ifndef HTML_BUILDER_H
#define HTML_BUILDER_H

#include <string>
#include <vector>
#include <iostream>
#include <memory>

#include "HtmlElement.h"

class HtmlBuilder {
    HtmlElement root;
public:
    HtmlElement& getRoot();
    HtmlBuilder(std::string root_name);
    HtmlBuilder& addChild(std::string child_name, std::string child_text);
    std::string str() const;
    
    HtmlBuilder(HtmlBuilder&& other) noexcept;
    HtmlBuilder& operator=(HtmlBuilder&& other) noexcept;

    HtmlBuilder(const HtmlBuilder& other) = delete;
    HtmlBuilder& operator=(const HtmlBuilder& other) = delete;

};
#endif // HTML_BUILDER_H    
    