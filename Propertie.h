
class Propertie
{
  protected:
  ElementType type;
  uint Id;
  Material* Mat;

  public:
  uint GetId(); // get Pid
  Material* GetMaterial(); // get material
  virtual ~Propertie(); // write proper destructor for derived class
}

class Psolid : public Propertie
{
  protected:

  public:
  Psolid(uint id, Material* mat);

  ~Psolid();

};

class Pshell : public Propertie
{
  protected:
  double T;
  Material* Mid2;
  double It;
  Material* Mid3;
  double Ts;
  double Nsm;
  double Z1;
  double Z2;
  Material* Mid4;

  public:
  Pshell(uint id, Material* mat, double T);
  double GetT();
  Material* GetMid2();
  double GetiT();
  Material* GetMid3();
  double GetTs();
  double GetNsm();
  double GetZ1();
  double GetZ2();
  Material* GetMid4();

  ~Pshell();
};

class Pbar : public Propertie // currently CBEAM supported as CBAR
{
  protected:
  double Diam; // diameter of Rod section for reference
  double A;
  double I1;
  double I2;
  double I12;
  double J;
  double NSM;
  double C[2];
  double D[2];
  double E[2];
  double F[2];
  double K[2];

  public:
  Pbar(uint id, Material* mat, double diam)
  Pbar(uint id, Material* mat, double a, double i1, double i2, double j, double nsm)

  double GetDiam();
  double GetA();
  double GetI1();
  double GetI2();
  double GetJ();
  double GetNSM();
  // more soon

  ~Pbar();
};

class PboltNF
{
  protected:
  Pbar* PropData;
  double NominalDiameter; // d
  double Pitch; // P
  double BearingDiamMaxH; // De Max bearing diam under head
  double BearingDiamMaxN; // De Max bearing diam under nut
  double BearingDiamMin; // Di Min bearing diam
  double BoltRm; // Reb stress limit of bolt
  double PermPressH; // pdop permissible pressure under head
  double PermPressN; // pdop permissible pressure under nut
  double Friction; // fi friction coeff
  double FrictionThreadMax; // friction coeff in thread
  double FrictionThreadMin;
  double FrictionBearingMax; // friction coeff at bearing surfaces
  double FrictionBearingMin;
  double TighteningFact; // tughtening factor
  double NonThreaded; // non threaded length of bolt from bearing surfaces
  bool Nut; // if nut equal true
  double DLfact; // DL factor from figure
  double UtilityFact; // bolt utility factor
  // more soon

  public:
  PboltNF();
  ~PboltNF();



};



