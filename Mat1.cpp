
bool Mat1::CheckNu(double& n){ // check if Nu is ok
  if(n>-1 and n<0.5)
    return true;
  else
    return false;
};

void Mat1::CalcG(){ // calculate G when only E and Nu is provided
  if CheckNu(Nu)
    G=E/(2*(Nu+1));
};

void Mat1::CalcNu(){ // calculate Nu when only E and G is provided
  double n=(E/(2*G))-1;
  if CheckNu(n)
    Nu=n;
  else
    throw "Calculated Poisons ratio out of range" ; // get better exception handling
}; 

Mat1::Mat1(uint id, double e, double gnu, double ro=0, double a=0, double tref=0, double ge=0, double st=0, double sc=0, double ss=0){
  // check input
  if(e<=0 || gnu<=-1 || ro<0 || a<0 || ge<0 || st<0 || sc<0 || ss<0)
    throw "Wrong material parapeters"
  // assign
  Id=id;
  E=e;
  if CheckNu(gnu){
    Nu=gnu;
    CalcG();
    };
  else{
    G=gnu;
    CalcNu();
    };
  Ro=ro;
  A=a;
  Tref=tref;
  Ge=ge;
  St=st;
  Sc=sc;
  Ss=ss;
};
