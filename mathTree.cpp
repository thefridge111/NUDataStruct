// mathTree.cpp
#include <iostream>
#include <sstream>
#include "mathTree.h"
#include <stdlib.h>

using namespace std;

string stringify(long double x) {
    ostringstream o;
    if (!(o << x))
        throw;
    return o.str();
}

mathTree::mathTree() {
    root = NULL;
}

mathTree::~mathTree() {
    delete root;
}

void mathTree::ReadExpression(string s) {
    string remaining;
    
    root = new treeNode;            //Create tree root
    
    remaining = _readex(root, s);   //Call readex to build tree
    
    if (remaining.length() > 0) {   //Check for remaining characters from strings
        throw 2;                    //Only invalid strings will have characters left
    }
}


string mathTree::_readex(treeNode* t, string exp) {
    int b;                          //Stores location of next space
    
    if (exp.length() > 0) {         //Check that there are characters in string
                                    
        while (isspace(exp[0])) {   //Removes leading spaces
            exp.erase(0,1);
        }

        if (isdigit(exp[0]) || isdigit(exp[1])) {
            b = exp.find_first_of(' ');
            istringstream(exp.substr(0,b)) >> t->value;
            t->leafNode = true;
            t->lChild = NULL;
            t->rChild = NULL;
            exp.erase(0,b);
            return exp;
        } else {
            t->op = exp[0];                 //Sets operators from front of string
            t->leafNode = false;            //and places into current node's op
            t->lChild = new treeNode;       //variable. Erases front string value
            t->rChild = new treeNode;       //Creates new children and calls readex
            exp.erase(0,1);                 //on children; left first, right second.
            exp = _readex(t->lChild, exp);
            exp = _readex(t->rChild, exp);
            return exp;                     //Returns remaining string.
        }
    } else {
        cout << "No length." << endl;       //Notifies user of improperly formatted
        throw 1;                            //or formed strings, throws exception
    }
}

double mathTree::ExpressionValue() {
    double result;
    
    result = _evaluate(root);               
    
    return result;
}

double mathTree::_evaluate(treeNode* t) {
    char opera;                         //Stores operator value for computation. 
    double result, l, r;                //Stores numerical values for computation.
                                        //l: left child value, r: right child value
    if (t->lChild != NULL) {        
        l = _evaluate(t->lChild);       //If not a leaf node, calls evaluate on left Child
    } 
    
    if(t->leafNode) {                   //If a leaf node, stores node value 
        result = t->value;
        return result;
    } else {                            //If an not leaf node, stores operator
        opera = t->op;
    }
    
    if (t->lChild != NULL) {            //If not a leaf node, calls evaluate on right Child
        r = _evaluate(t->rChild);
    }
    
    switch(opera) {                     //Parses operator values to act accordingly
        case '+':                       //NOTE: Does not do modulo arithmetic because evaluating two doubles.
            result = l + r;             //Addition
            break;
        case '-':
            result = l - r;             //Subtraction
            break;
        case '*':   
            result = l * r;             //Multiplication
            break;
        case '/':
            result = l / r;             //Division
            break;
        default:
            cout << "Unrecognized operator." << endl;   //If operator falls outside
    }                                                   //recognized values.
    return result;                      //Returns value/operator for parent computation
}

string mathTree::ReturnInfix() {
    string infix_Notation;
    infix_Notation += _inorder(root);   //Inorder traverses tree, formatting output
                                        //as it goes.
    return infix_Notation;             
}

string mathTree::_inorder(treeNode* t) {
    string inorder_Notation;;
    if (t->lChild != NULL) {            //While theres a left child continues traversing
        inorder_Notation += '(';        //down tree to left child leaf. Adds parentheses
        inorder_Notation += _inorder(t->lChild); //for formatting purposes.
    } 
    
    if(t->leafNode) {
        inorder_Notation += (stringify(t->value));  //Grabs operator/value as appropriate
    } else {
        inorder_Notation += (t->op);
    }
       
    if (t->rChild != NULL) {            //Traverses to end of right children. Closes parentheses for 
        inorder_Notation += _inorder(t->rChild);    //formatting purposes.
        inorder_Notation += ')';
    }
    
    return inorder_Notation;
}
