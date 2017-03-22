

class Material
{
  protected:
  uint Id;

  public:
  uint GetId(){return Id;}; // get material Id
};

class Mat1 : public Material
{
  protected:
  double E;
  double G;
  double Nu;
  double Ro;
  double A;
  double Tref;
  double Ge;
  double St;
  double Sc;
  double Ss;

  bool CheckNu(); // check if Nu is ok
  void CalcG(); // calculate G when only E and Nu is provided
  void CalcNu(); // calculate Nu when only E and G is provided

  public:
  Mat1(uint id, double e, double gnu, double ro=0, double a=0, double tref=0, double ge=0, double st=0, double sc=0, double ss=0);

  double GetE(){return E;};
  double GetG(){return G;};
  double GetNu(){return Nu;};
  double GetRo(){return Ro;};
  double GetA(){return A;};
  double GetTref(){return Tref;};
  double GetGe(){return Ge;};
  double GetSt(){return St;};
  double GetSc(){return Sc;};
  double GetSs(){return Ss;};
}

