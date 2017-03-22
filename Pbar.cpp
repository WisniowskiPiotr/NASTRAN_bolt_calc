


Pbar::Pbar(bool cbar, uint id, Material* mat, double diam){
  // check input
  if(diam<=0)
    throw "Wrong diam parapeters"
  // assign
  (cbar==true)? Type=CBAR: Type=CBEAM;
  Id=id;
  Mat=&mat;
  Diam=diam;
  A=0.25*PI*Diam*Diam;
  I1=0.25*PI*Diam*Diam*Diam*Diam/16;
  I2=I1;
  I12=0;
  J=0;
  Nsm=0;
}; 

Pbar::Pbar(bool cbar, uint id, Material* mat, double a, double i1, double i2, double j=0, double nsm=0){
  // check input
  if(a<0 || i1<0 || i2<0 || i12<0 || j<0 || nms<0)
    throw "Wrong diam parapeters"
  // assign
  (cbar==true)? Type=CBAR: Type=CBEAM;
  Id=id;
  Mat=&mat;
  Diam=sqrt(4*a/PI);
  A=a;
  I1=i1;
  I2=i1;
  I12=i12;
  J=j;
  Nsm=nsm;
}; 