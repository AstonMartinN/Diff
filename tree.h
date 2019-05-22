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
	virtual double get_value(double point){};
	virtual double get_value_dif(double point){};
	
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
	virtual double get_value(double point);
	virtual double get_value_dif(double point);
};
class Cos:public Operator{
public:
    Cos(){};
    virtual int print();
    virtual Node * copy();
    virtual Node * diff();
	virtual double get_value(double point);
	virtual double get_value_dif(double point);
};
class Ln:public Operator{
public:
    Ln(){};
    virtual int print();
    virtual Node * copy();
    virtual Node * diff();
	virtual double get_value(double point);
	virtual double get_value_dif(double point);
};
class Exp:public Operator{
public:
    Exp(){};
    virtual int print();
    virtual Node * copy();
    virtual Node * diff();
	virtual double get_value(double point);
	virtual double get_value_dif(double point);
};
class Sqrt:public Operator{
public:
    Sqrt(){};
    virtual int print();
    virtual Node * copy();
    virtual Node * diff();
	virtual double get_value(double point);
	virtual double get_value_dif(double point);
};
class Plus:public Operator{
public:
    Plus(){};
    virtual int print();
    virtual Node * copy();
    virtual Node * diff();
	virtual double get_value(double point);
	virtual double get_value_dif(double point);
};
class Minus:public Operator{
public:
    Minus(){};
    virtual int print();
    virtual Node * copy();
    virtual Node * diff();
	virtual double get_value(double point);
	virtual double get_value_dif(double point);
};
class Mult:public Operator{
public:
    Mult(){};
    virtual int print();
    virtual Node * copy();
    virtual Node * diff();
	virtual double get_value(double point);
	virtual double get_value_dif(double point);
};
class Div:public Operator{
public:
    Div(){};
    virtual int print();
    virtual Node * copy();
    virtual Node * diff();
	virtual double get_value(double point);
	virtual double get_value_dif(double point);
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
	virtual double get_value(double point);
	virtual double get_value_dif(double point);
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
	virtual double get_value(double point);
	virtual double get_value_dif(double point);
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


double Sin::get_value(double point){
	return sin(point);
}
double Cos::get_value(double point){
    return cos(point);
}
double Ln::get_value(double point){
    return log(point);
}
double Exp::get_value(double point){
    return exp(point);
}
double Sqrt::get_value(double point){
    return sqrt(point);
}
double Const::get_value(double point){
    return value;
}
double Var::get_value(double point){
    return point;
}
double Plus::get_value(double point){
    return get_left() -> get_value(point) + get_right() -> get_value(point) ;
}
double Minus::get_value(double point){
    return get_left() -> get_value(point) - get_right() -> get_value(point);
}
double Mult::get_value(double point){
    return get_left() -> get_value(point) * get_right() -> get_value(point);
}
double Div::get_value(double point){
    return get_left() -> get_value(point) / get_right() -> get_value(point);
}


////////////////////////////////////////////////////*****************
double Sin::get_value_dif(double point){
	return cos(point) * (get_right() -> get_value_dif(point));
}
double Cos::get_value_dif(double point){
    return -1 * sin(point) * (get_right() -> get_value_dif(point));
}
double Ln::get_value_dif(double point){
    return (1 / point) * (get_right() -> get_value_dif(point));
}
double Exp::get_value_dif(double point){
    return exp(point) * (get_right() -> get_value_dif(point));
}
double Sqrt::get_value_dif(double point){
    return (1 / (2*sqrt(point))) * (get_right() -> get_value_dif(point));
}
double Const::get_value_dif(double point){
    return 0;
}
double Var::get_value_dif(double point){
    return 1;
}
double Plus::get_value_dif(double point){
    return get_left() -> get_value_dif(point) + get_right() -> get_value_dif(point) ;
}
double Minus::get_value_dif(double point){
    return get_left() -> get_value_dif(point) - get_right() -> get_value_dif(point);
}
double Mult::get_value_dif(double point){
    return  (get_left() -> get_value_dif(point) * get_right() -> get_value(point) ) + (get_left() -> get_value(point) * get_right() -> get_value_dif(point));
}
double Div::get_value_dif(double point){
    double tmp = (get_left() -> get_value_dif(point) * get_right() -> get_value(point) ) - (get_left() -> get_value(point) * get_right() -> get_value_dif(point));
	return tmp / (get_right() -> get_value(point) * get_right() -> get_value(point) );
}
////////////////////////////////////////////////////////////////

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

#endif

