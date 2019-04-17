#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
	Node *n = new Node{new Student(s), NULL};
	if(!head){
		head = n;
		tail = n;
	}else{
		tail->next = n;
		tail = n;
	}
}

std::string StudentRoll::toString() const {
  	std::string s = "[";
	Node *n = this->head;
	while(n){
		s+=n->s->toString();
		if(n->next)s+=",";
		n=n->next;
	}
	s+="]";
	return s;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  head = tail = NULL;
  Node *n = orig.head;
  while(n){
  	this->insertAtTail(*(n->s));
	n = n->next;
  }
}

StudentRoll::~StudentRoll() {
  Node *n = this->head;
  while(n){
  	Node *tmp = n;
	n = n->next;
	delete tmp;
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...

  Node *n = this->head;
  while(n){
  	Node *tmp = n;
	n = n->next;
	delete tmp;
  }
  head = tail = NULL;
  n = right.head;
  while(n){
  	this->insertAtTail(*(n->s));
	n = n->next;
  }
  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





