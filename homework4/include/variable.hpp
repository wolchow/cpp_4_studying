#pragma once

#include <string>

#include "astnode.hpp"

class Variable : public ASTNode {
    public: 
        Variable(std::string var) 
            : ASTNode(var)
            , var_(var) {}
    
    std::string get_name() const { return var_; }

    private:
        std::string var_;

};