class Visitor {
  public:
    virtual void visit(int element) = 0;
};

class SumVisitor : Visitor {
  private:
    int sum = 0;

  public:
    void visit(int element) override { sum += element; }
    int getSum() { return sum; }
};