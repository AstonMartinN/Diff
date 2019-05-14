#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "tree.h"


std::vector<std::string> parse(){
    std::string str;
    std::getline(std::cin, str);
    std::vector<std::string> list;
    std::string tmp;
    for(int i = 0; i <= str.size(); i++){
        if(str[i] == ' ' || i == str.size()){
            if(tmp.size() != 0){
                list.push_back(tmp);
            }
            tmp = "";
            continue;
        }else{
            tmp += str[i];
        }
    }
    return list;
}

Node * isfunction(std::string lexem){
    if(lexem == "sin")
        return new Sin();
    if(lexem == "cos")
        return new Cos();
    if(lexem == "ln")
        return new Ln();
    if(lexem == "sqrt")
        return new Sqrt();
    if(lexem == "exp")
        return new Exp();
    return NULL;
}

Node * isoper(std::string lexem){
    if(lexem == "+")
        return new Plus();
    if(lexem == "-")
        return new Minus();
    if(lexem == "*")
        return new Mult();
    if(lexem == "/")
        return new Div();
    return NULL;
}

Node * isterm(std::string lexem){
    int num = atoi(lexem.data());
    if(num != 0)
        return new Const(num);
    else
        return new Var(lexem);
    return NULL;
}

Node * build_tree(std::vector<std::string> input, int &count){
    if(count >= input.size())
        return NULL;
    Node * tmp;
    if(input[count] == "("){
        count++;
        Node * left = build_tree(input, count);
        if(input[++count] == ")") // count = count + 1
            return left;
        tmp = isoper(input[count]);
        count++;
        Node * right = build_tree(input, count);
        if(input[++count] != ")"){
            std::cout << "ERROR )" << std::endl;
            return 0;
        }
        tmp -> set_left(left);
        tmp -> set_right(right);
        return tmp;
    }
    //tmp = isoper(input[count]);
    //if(tmp != NULL)
    //    return tmp;
    tmp = isfunction(input[count]);
    if(tmp != NULL){
        Node * right = build_tree(input, ++count);
        tmp -> set_right(right);
        return tmp;
    }
    tmp = isterm(input[count]);
    return tmp;
}

int print_tree(Node * input){
    if(input == NULL)
        return 0;
    print_tree(input -> get_left());
            input -> print();
    print_tree(input -> get_right());
    return 0;
}

int delete_tree(Node * input){
    if(input == NULL)
        return 0;
    delete_tree(input -> get_left());
    delete_tree(input -> get_right());
    delete input;
    return 0;
}

int print_tree2(Node * input){
    std::vector< Node * > one;
    std::vector< Node * > two;
    int hmax = 6, width = (1 << hmax) - hmax;
    one.push_back(input);
    for(int level = 0; level < hmax; level++){
        std::string filler(width - 1, ' ');
        for(int i = 0; i < one.size() ; i++){
            Node * elem = one[i];
            if(elem != NULL){
                std::cout << filler;
                elem -> print();
                std::cout << filler;
                two.push_back(elem -> get_left());
                two.push_back(elem -> get_right());
            } else {
                std::cout << filler << "(--)" << filler;
                two.push_back(NULL);
                two.push_back(NULL);
            }
        }
        std::cout << std::endl;
        std::cout << "-------------------------------------------------" << std::endl;
        std::cout << std::endl;
        one = two;
        two.clear();
        width /= 2;
    }
    return 0;
}
int print_function(Node * input){
    if(input -> get_left() != NULL){
        std::cout << "(";
        print_function(input -> get_left());
        std::cout << ")";
    }
    input -> print();
    if(input -> get_right() != NULL){
        std::cout << "(";
        print_function(input -> get_right());
        std::cout << ")";
    }
    return 0;
}

int main(){
    std::vector<std::string> list;
    list = parse();
    for(int i = 0; i < list.size(); i++){
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
    int count = 0;
    Node * tree = build_tree(list, count);
    std::cout << "good build" << std::endl;
    print_function(tree);
    std::cout << "good print" << std::endl;
    Node * cop = tree -> diff();
    print_function(cop);

    delete_tree(cop);
    delete_tree(tree);
    return 0;
}
