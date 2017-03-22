
class Node
{
  private:
  uint Id;
  uint Pcid;
  uint Acid;
  double X;
  double Y;
  double Z;

  public:
  Node(uint id, double x, double y double z, uint pcid=0, uint acid=0);
  uint GetId(){return Id;}; // get ID
  uint GetPcid(){return Pcid;}; // get pCID ID
  uint GetAcid(){return Acid;}; // get aCID ID
  double GetX(){return X;}; // get X coordinate
  double GetY(){return Y;}; // get Y coordinate
  double GetZ(){return Z;}; // get Z coordinate
  ~Node();

}