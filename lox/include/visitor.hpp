#ifndef _VISITOR_HPP_
#define _VISITOR_HPP_

class Binary;
class Assign;
class Call;
class Get;
class Grouping;
class Literal;
class Logical;
class Set;
class Super;
class This;
class Unary;
class Variable;

class Visitor {
public:
  virtual void visit(Binary &expr) = 0;
  virtual void visit(Assign &expr) = 0;
  virtual void visit(Call &expr) = 0;
  virtual void visit(Get &expr) = 0;
  virtual void visit(Grouping &expr) = 0;
  virtual void visit(Literal &expr) = 0;
  virtual void visit(Logical &expr) = 0;
  virtual void visit(Set &expr) = 0;
  virtual void visit(Super &expr) = 0;
  virtual void visit(This &expr) = 0;
  virtual void visit(Unary &expr) = 0;
  virtual void visit(Variable &expr) = 0;
};

#endif