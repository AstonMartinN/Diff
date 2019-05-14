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
    virtual Node * diff(){};
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
    virtual Node * diff();
};
class Cos:public Operator{
public:
    Cos(){};
    virtual int print();
    virtual Node * copy();
    virtual Node * diff();
};
class Ln:public Operator{
public:
    Ln(){};
    virtual int print();
    virtual Node * copy();
    virtual Node * diff();
};
class Exp:public Operator{
public:
    Exp(){};
    virtual int print();
    virtual Node * copy();
    virtual Node * diff();
};
class Sqrt:public Operator{
public:
    Sqrt(){};
    virtual int print();
    virtual Node * copy();
    virtual Node * diff();
};
class Plus:public Operator{
public:
    Plus(){};
    virtual int print();
    virtual Node * copy();
    virtual Node * diff();
};
class Minus:public Operator{
public:
    Minus(){};
    virtual int print();
    virtual Node * copy();
    virtual Node * diff();
};
class Mult:public Operator{
public:
    Mult(){};
    virtual int print();
    virtual Node * copy();
    virtual Node * diff();
};
class Div:public Operator{
public:
    Div(){};
    virtual int print();
    virtual Node * copy();
    virtual Node * diff();
};

class Const:public Term{
    int value;
public:
    Const(int value){
        Const::value = value;
    }
    virtual int print();
    virtual Node * diff();
    virtual Node * copy();
};
class Var:public Term{
	std::string name;
public:
    Var(std::string name){
		Var::name = name;
	}
    virtual int print();
    virtual Node * copy();
    virtual Node * diff();
};

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

Node * Sin::copy(){
	Node * tmp = new Sin();
	if(get_left() != NULL)
		tmp -> set_left(get_left() -> copy());
	if(get_right() != NULL)
		tmp -> set_right(get_right() -> copy());
	return tmp;
}
Node * Cos::copy(){
	Node * tmp = new Cos();
	if(get_left() != NULL)
		tmp -> set_left(get_left() -> copy());
	if(get_right() != NULL)
		tmp -> set_right(get_right() -> copy());
	return tmp;
}
Node * Ln::copy(){
	Node * tmp = new Ln();
	if(get_left() != NULL)
		tmp -> set_left(get_left() -> copy());
	if(get_right() != NULL)
		tmp -> set_right(get_right() -> copy());
	return tmp;
}
Node * Exp::copy(){
	Node * tmp = new Exp();
	if(get_left() != NULL)
		tmp -> set_left(get_left() -> copy());
	if(get_right() != NULL)
		tmp -> set_right(get_right() -> copy());
	return tmp;
}
Node * Sqrt::copy(){
	Node * tmp = new Sqrt();
	if(get_left() != NULL)
		tmp -> set_left(get_left() -> copy());
	if(get_right() != NULL)
		tmp -> set_right(get_right() -> copy());
	return tmp;
}
Node * Var::copy(){
	Node * tmp = new Var(name);
	if(get_left() != NULL)
		tmp -> set_left(get_left() -> copy());
	if(get_right() != NULL)
		tmp -> set_right(get_right() -> copy());
	return tmp;
}
Node * Plus::copy(){
	Node * tmp = new Plus();
	if(get_left() != NULL)
		tmp -> set_left(get_left() -> copy());
	if(get_right() != NULL)
		tmp -> set_right(get_right() -> copy());
	return tmp;
}
Node * Minus::copy(){
	Node * tmp = new Minus();
	if(get_left() != NULL)
		tmp -> set_left(get_left() -> copy());
	if(get_right() != NULL)
		tmp -> set_right(get_right() -> copy());
	return tmp;
}
Node * Mult::copy(){
	Node * tmp = new Mult();
	if(get_left() != NULL)
		tmp -> set_left(get_left() -> copy());
	if(get_right() != NULL)
		tmp -> set_right(get_right() -> copy());
	return tmp;
}
Node * Div::copy(){
	Node * tmp = new Div();
	if(get_left() != NULL)
		tmp -> set_left(get_left() -> copy());
	if(get_right() != NULL)
		tmp -> set_right(get_right() -> copy());
	return tmp;
}




Node * Const::diff(){
    return new Const(0);
}

Node * Sin::diff(){
	Node * tmp = new Mult();
	Node * tmp2 = new Cos();
	if(get_right() != NULL)
		tmp2 -> set_right(get_right() -> copy());
	tmp -> set_left(tmp2);
	if(get_right() != NULL)
		tmp -> set_right(get_right() -> diff());
	return tmp;
}


Node * Cos::diff(){
	Node * tmp = new Mult();
	Node * tmp2 = new Sin();
	Node * null = new Const(0);
	Node * min = new Minus();
	min -> set_left(null);
	min -> set_right(get_right() -> copy());
	if(get_right() != NULL)
		tmp2 -> set_right(min);
	tmp -> set_left(tmp2);
	if(get_right() != NULL)
		tmp -> set_right(get_right() -> diff());
	return tmp;
}




Node * Ln::diff(){
	Node * tmp = new Div();
	tmp -> set_left(new Const(1));
	if(get_right() != NULL)
		tmp -> set_right(get_right() -> copy());
	Node * mul = new Mult();
	mul -> set_left(tmp);
	if(get_right() != NULL)
		mul -> set_right(get_right() -> diff());
	return mul;
}

Node * Exp::diff(){
	Node * tmp = new Mult();
	if(get_right() != NULL)
		tmp -> set_right(get_right() -> diff());
	tmp -> set_left(copy());
	return tmp;
}

Node * Sqrt::diff(){
    Node * div = new Div();
    Node * mult = new Mult();
    div -> set_left(new Const(1));
    mult -> set_left(new Const(2));
    mult -> set_right(copy());
    div -> set_right(mult);
	return div;
}
Node * Var::diff(){
	return new Const(1);
}

Node * Mult::diff(){
    Node * plus = new Plus();
    Node * mult1 = new Mult();
    Node * mult2 = new Mult();
    mult1 -> set_left(get_left() -> diff());
    mult1 -> set_right(get_right() -> copy());
    mult2 -> set_left( get_left() -> copy());
    mult2 -> set_right(get_right() -> diff());
    plus -> set_left(mult1);
    plus -> set_right(mult2);
    return plus;
}

Node * Plus::diff(){
    Node * pls = new Plus();
    pls -> set_left(get_left() -> diff());
    pls -> set_right(get_right() -> diff());
    return pls;
}

Node * Minus::diff(){
    Node * minus = new Minus();
    minus -> set_left(get_left() -> diff());
    minus -> set_right(get_right() -> diff());
    return minus;
}

Node * Div::diff(){
    Node * div = new Div();
    
    Node * min = new Minus();
    Node * mult1 = new Mult();
    Node * mult2 = new Mult();
    mult1 -> set_left(get_left() -> diff());
    mult1 -> set_right(get_right() -> copy());
    mult2 -> set_left( get_left() -> copy());
    mult2 -> set_right(get_right() -> diff());
    min -> set_left( mult1 );
    min -> set_right( mult2 );
    
    div -> set_left(min);

    Node * mult3 = new Mult();
    mult3 -> set_left(get_right() -> copy());
    mult3 -> set_right(get_right() -> copy());
    
    div -> set_right(mult3);
    return div;
}
#endif

