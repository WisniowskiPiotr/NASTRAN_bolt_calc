
class Propertie
{
  protected:
  ElementType type;
  uint Id;
  Material* Mat;

  public:
  ElementType GetType(){return type;}; // get prop type
  uint GetId(){return Id;}; // get Pid
  Material GetMaterial(){return *Mat;}; // get material
}

class Psolid : public Propertie
{
  protected:

  public:
  Psolid(uint& id, Material& mat);
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

  public:
  Pshell(uint& id, Material& mat, double& t, double& nsm=0, double& z1=0, double& z2=0);
  Pshell(uint& id, Material& mat, double& t, Material& mid2, Material& mid3, double& it=1.0, double& ts=0.8333, double& nsm=0, double& z1=0, double& z2=0);
  double GetT(){return T;};
  Material GetMid2(){return *Mid2;};
  double GetiT(){return It;};
  Material GetMid3(){return *Mid3;};
  double GetTs(){return Ts;};
  double GetNsm(){return Nsm;};
  double GetZ1(){return Z1;};
  double GetZ2(){return Z2;};
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
  double Nsm;

  public:
  Pbar(bool& cbar, uint& id, Material& mat, double& diam); 
  Pbar(bool& cbar, uint& id, Material& mat, double& a, double& i1, double& i2, double& j=0, double& nsm=0);

  double GetDiam(){return Diam;};
  double GetA(){return A;};
  double GetI1(){return I1;};
  double GetI2(){return I2;};
  double GetI12(){return I12;};
  double GetJ(){return J;};
  double GetNsm(){return Nsm;};
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
};



