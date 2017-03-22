

class Element
{
  private:
  uint Id;
  ElementType Type;
  Propertie* Pid;
  vector<Node*> Nodes;

  public:
  Element(uint id, ElementType type, vector<Node*> nodes, Propertie* pid);

  bool CheckElementCid();

  uint GetId(); // get element Id
  Propertie* GetPid(); // get element Propertie
  vector<Node*> GetNodes(); // get element Nodes

  ~Element();
}