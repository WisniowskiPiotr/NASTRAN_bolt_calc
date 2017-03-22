

Class Model
{
  private:
  vector<Node> nodes;
  vector<Element> elements;
  vector<Propertie> properties;
  //vector<Bolt> bolts;
  vector<Material> materials;

  public:
  Model();
  Model(string& path);
  void Readmdl(string& path); // reads another file to existing model

  Node* GetNode(uint ID); // gets node by its ID
  Element* GetElement(uint ID); // gets element by its ID
  Propertie* GetPropertie(uint ID); // gets prop by its ID
  //Bolt* GetBolt(uint ID); // gets bolt params by its prop ID
  Material* GetMaterial(uint ID); // gets mat by its ID

  vector<Element*> GetElementsByNode(Node comm_node); // gets elements by common node;
  vector<Element*> GetAdjacentElements(Element first_element); // gets elements by adjacent element
  vector<Element*> GetAdjacentBoltElements(Element first_element); // gets next bolt elements in single bolt connection

~Model(); // napisac zeby nie było wyceków pamiewci


};