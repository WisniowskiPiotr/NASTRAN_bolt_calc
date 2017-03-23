

Class Model
{
  private:
  int Sol;
  bool Results;
  vector<Node> Nodes;
  vector<Element> Elements;
  vector<Propertie> Properties;
  //vector<Bolt> bolts;
  vector<Material> Materials;
  vector<Card> Cards;

  void ReadCard(string& line);
  void UpdMdl();

  public:
  Model(string& path);
  void ReadMdl(string& path); // reads another file to existing model

  Node* GetNode(uint& ID); // gets node by its ID
  Element* GetElement(uint& ID); // gets element by its ID
  Propertie* GetPropertie(uint& ID); // gets prop by its ID
  //Bolt* GetBolt(uint& ID); // gets bolt params by its prop ID
  Material* GetMaterial(uint& ID); // gets mat by its ID

  vector<Element*> GetElementsByNode(Node& comm_node); // gets elements by common node;
  vector<Element*> GetAdjacentElements(Element& first_element); // gets elements by adjacent element
  vector<Element*> GetAdjacentBoltElements(Element& first_element); // gets next bolt elements in single bolt connection

};