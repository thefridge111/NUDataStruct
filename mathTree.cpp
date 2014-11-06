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
    // Add content here
}

mathTree::~mathTree() {
    delete root;
}

void mathTree::ReadExpression(string s) {
    string remaining;
    
    root = new treeNode;
    
    remaining = _readex(root, s);
    if (remaining.length() > 0) {
        throw 2;
    }
}


string mathTree::_readex(treeNode* t, string exp) {
    int b;
    //cout << "initial: " << exp << endl;
    if (exp.length() > 0) {
        while (isspace(exp[0])) {
            exp.erase(0,1);
        }

        if (isdigit(exp[0]) || isdigit(exp[1])) {
            b = exp.find_first_of(' ');
            istringstream(exp.substr(0,b)) >> t->value;
            t->leafNode = true;
            t->lChild = NULL;
            t->rChild = NULL;
            exp.erase(0,b);
            //cout << "value: " << t->value << endl;
            //cout << "exp: " << exp << endl;
            return exp;
        } else {
            t->op = exp[0];
            t->leafNode = false;
            t->lChild = new treeNode;
            t->rChild = new treeNode;
            exp.erase(0,1);
            //cout << "op: " << t->op << endl;
            //cout << "exp1: " << exp << endl;
            exp = _readex(t->lChild, exp);
            //cout << "left1: " << exp << endl;
            exp = _readex(t->rChild, exp);
            //cout << "left: " << exp << endl;
            return exp;
        }
    } else {
        cout << "No length." << endl;
        throw 1;
    }
}

double mathTree::ExpressionValue() {
    double result;
    
    result = _evaluate(root);
    
    return result;
}

double mathTree::_evaluate(treeNode* t) {
    char opera;
    double result, k, l;
    
    if (t->lChild != NULL) {
        k = _evaluate(t->lChild);
    } 
    
    if(t->leafNode) {
        result = t->value;
        return result;
    } else {
        opera = t->op;
    }
    
    if (t->lChild != NULL) {
        l = _evaluate(t->rChild);
    }
    switch(opera) {
        case '+':
            result = k + l;
            break;
        case '-':
            result = k - l;
            break;
        case '*':
            result = k * l;
            break;
        case '/':
            result = k / l;
            break;
        default:
            cout << "Unrecognized operator." << endl;
    } 
    return result;
}

string mathTree::ReturnInfix() {
    string infix_Notation;
    //cout << "here" << endl;
    infix_Notation += _inorder(root);
    
    return infix_Notation;
}

string mathTree::_inorder(treeNode* t) {
    string inorder_Notation;
    //cout << "value: " << t->value << endl;
    //cout << "op: " << t->op << endl;
    if (t->lChild != NULL) {
        inorder_Notation += '(';
        inorder_Notation += _inorder(t->lChild);
    } 
    
    if(t->leafNode) {
        inorder_Notation += (stringify(t->value));
    } else {
        inorder_Notation += (t->op);
    }
       
    if (t->rChild != NULL) {
        inorder_Notation += _inorder(t->rChild);
        inorder_Notation += ')';
    }
    
    return inorder_Notation;
    
    /*string inorder_Notation;
    
    if (t->lChild != NULL) {
        inorder_Notation += _inorder(t->lChild);
    } 
    
    if(t->leafNode) {
        inorder_Notation += (t->value + ',');
    } else {
        inorder_Notation += (t->op + ',');
    }
    
    if (t->rChild != NULL) {
        inorder_Notation += _inorder(t->rChild);
    }
    */
}
