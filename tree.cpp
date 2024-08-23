#include "tree.h"

FunctionCallNode::FunctionCallNode (const std::string &name, Node *arg, funcTable &table) 
: m_fdtor(table.getFunc(name)), m_arg(arg), m_table(table), m_name(name) {}

GenericType FunctionCallNode::eval(varTable& vm) {     

    // Call the function on arguments
    std::cout << "function call" << std::endl;
    m_fdtor = m_table.getFunc(m_name);
    return m_fdtor.second.first(m_arg->eval(vm), m_fdtor.second.second, m_fdtor.first);
}