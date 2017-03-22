

Pshell::Pshell(uint id, Material mat, double t, double nsm=0, double z1=0, double z2=0){
  // check input
  if(t<0 || nsm<0)
    throw "Wrong membr parapeters"
  // assign
  Type=MEMBR;
  Id=id;
  Mat=&mat;
  T=t;
  Nsm=nsm;
  (z1==0)? Z1=-T/2: Z1=z1;
  (z2==0)? Z2=T/2: Z2=z2;
  IT=0;
  Ts=0;
  Mid2=null;
  Mid3=null;
};

Pshell::Pshell(uint id, Material mat, double t, Material mid2, Material mid3, double it=1.0, double ts=0.8333, double nsm=0, double z1=0, double z2=0)){
  // check input
  if(t<0 || nsm<0)
    throw "Wrong membr parapeters"
  // assign
  Type=SHELL;
  Id=id;
  Mat=&mat;
  T=t;
  Mid2=&mid2;
  Mid3=&mid3;
  Nsm=nsm;
  (z1==0)? Z1=-T/2: Z1=z1;
  (z2==0)? Z2=T/2: Z2=z2;
  It=it;
  Ts=ts;
};

