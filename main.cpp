#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include "tree.h"




int main(int argv, char * *argc){
    std::vector<std::string> list;
    list = parse();
    for(int i = 0; i < list.size(); i++){
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
    Node * tree = build_tree(list, count);
    std::cout << "good build" << std::endl;
    print_function(tree);
    std::cout << "good print" << std::endl;
    Node * difir = tree -> diff();
    print_function(difir);
    std::cout << "good diff and print" << std::endl;
    std::cout << "Value: " << difir -> get_value(atoi(argc[1])) << std::endl;
    delete_tree(difir);
    delete_tree(tree);
    return 0;
}
