#ifndef TREE_H
#define TREE_H

class Node{
    Node * left;
    Node * right;
public:
	Node(){
		left = NULL;
		right = NULL;
	};
    int set_left(Node * ptr){
        left = ptr;
        return 0;
    }
    int set_right(Node * ptr){
        right = ptr;
        return 0;
    }
	Node * get_left(){
		return left;
	}
	Node * get_right(){
		return right;
	}
	virtual int print(){};
    
    virtual Node * copy(){};
    //virtual Node * copy();
    //virtual Node * diff(Node * input);
};

class Operator:public Node{
public:
    Operator(){};
};
class Term:public Node{
public: 
    Term(){};
};
class Sin:public Operator{
public:
    Sin(){};
    virtual int print();
    virtual Node * copy();
};
class Cos:public Operator{
public:
    Cos(){};
    virtual int print();
    virtual Node * copy();
};
class Ln:public Operator{
public:
    Ln(){};
    virtual int print();
    virtual Node * copy();
};
class Exp:public Operator{
public:
    Exp(){};
    virtual int print();
    virtual Node * copy();
};
class Sqrt:public Operator{
public:
    Sqrt(){};
    virtual int print();
    virtual Node * copy();
};
class Plus:public Operator{
public:
    Plus(){};
    virtual int print();
    virtual Node * copy();
};
class Minus:public Operator{
public:
    Minus(){};
    virtual int print();
    virtual Node * copy();
};
class Mult:public Operator{
public:
    Mult(){};
    virtual int print();
    virtual Node * copy();
};
class Div:public Operator{
public:
    Div(){};
    virtual int print();
    virtual Node * copy();
};
class Const:public Term{
    int value;
public:
    Const(int value){
        Const::value = value;
    }
    virtual int print();
    virtual Node * diff(Node * input);
    virtual Node * copy();
};
class Var:public Term{
	std::string name;
public:
    Var(std::string name){
		Var::name = name;
	}
    virtual int print();
    virtual Node * copy(Node * input);
};
Node * Const::diff(Node * input){
    return new Const(0);
}
Node * Const::copy(){
    return new Const(value);
}
int Sin::print(){
	std::cout << "SIN";// << std::endl;
	return 0;
}
int Cos::print(){
    std::cout << "COS";// << std::endl;
    return 0;
}
int Ln::print(){
    std::cout << "Ln";// << std::endl;
    return 0;
}
int Exp::print(){
    std::cout << "EXP";// << std::endl;
    return 0;
}
int Sqrt::print(){
    std::cout << "SQRT";// << std::endl;
    return 0;
}
int Const::print(){
    std::cout << value ;//<< std::endl;
    return 0;
}
int Var::print(){
    std::cout << name ;//<< std::endl;
    return 0;
}

int Plus::print(){
    std::cout << "+" ;//<< std::endl;
    return 0;
}
int Minus::print(){
    std::cout << "-" ;//<< std::endl;
    return 0;
}
int Mult::print(){
    std::cout << "*" ;//<< std::endl;
    return 0;
}
int Div::print(){
    std::cout << "/" ;//<< std::endl;
    return 0;
}
/*

Node * Var::diff(){
    return new Const(1);
} 
Node * Sin::diff(){
    Node * tmp = new Cos();
    Cos -> set_right(right -> copy())
    Node * tmp2 = new Mult();
    tmp2 -> set_left(tmp);
    tmp2 -> set_right(right -> diff());
}*/
#endif
