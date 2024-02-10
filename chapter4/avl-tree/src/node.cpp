#include "node.h"

void Node::updateHeightAndBalance(){
    height = balance = 1;
    if(left != NULL){
	balance -= left->height;
	height = left->height + 1;
    }
    if(right != NULL){
	balance += right->height;	
	if(right->height >= height) height = right->height + 1;
    }
}
