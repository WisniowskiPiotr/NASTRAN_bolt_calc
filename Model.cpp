#include <iostream>
#include <string>
#include <locale>
#include <stdlib.h> 


using namespace std;

Model::ReadCard(string& line) //gets part of a card from single line
{
  bool newcard=false;
  bool longformat=false;

  size_t s=line.size();
  string tmpstr="";

  if (isalpha(line[0])) // check if its a new bulk card
    newcard=true;
  for (int i=0; i<s; i++) // iterate every char in line
  {
    if (line[i]==',' // case of freeformat - fields separated by ,
    || (longformat==false && tmpstr.size()==8 ) // case of stdformat
    || (longformat==true && i==7) // case of first field in longformat
    || (longformat==true && tmpstr.size()==16 )) // case of long format
    {
      if (newcard) // if new card create new card and insert it in vector
        Cards.push_back(new Card(tmpstr));
      else // if continuation push data to last card in vector
        Cards.back(new Card(tmpstr));
      tmpstr="";
    } 
    else
    {
      if (line[i]=='*')
        longformat=true;
      else
        if (line[i]!=" ")
          tmpstr.pushback(line[i]);
    };
  };
};

Model::UpdMdl()
{
  size_t s=Cards.size();
  for (int i=0; i<s; i++) //search for Materials // possible for parraleziation
  {
    if (Cards[i].GetFieldStr()=="MAT1")
      // check if same ID does not appear
      uint id=Cards[i].GetFieldID();
      size_t sv=Materials.size();
      bool unique;
      for (int j=0; j<sv; j++)
        if ()
      // 
  };
};

Model::Model(string& path)
{
  Sol=0;
  Results=false;
  ReadMdl(path);
};

void ReadMdl(string& path)
{
  string line;
  ifstream myfile (path);

  if (myfile.is_open())
  {
    while ( getline (myfile,line) and casectr==false)
    {
      size_t s=line.size();
      if (s>9) // if not - useless card - dont read it
      { 
        // convert line to uppercase
        {
          locale loc;
          for(int i=0; i<s; i++)
            line[i]=toupper(line[i],loc);
        };
        // check Sol and if force values are punched
        if (Sol==0 && line.find("SOL ")!=line.npos
          Sol=atoi(line.substr(5));
        if (Results==false && line.find("ELFORCE")!=line.npos && line.find("PUNCH")!=line.npos)
          Results=true;

        // get cards readed
        ReadCard(line);
      };
    };
    myfile.close();
  };
  else 
    throw "Unable to open file"; 

  // cards readed - time connect them
  UpdMdl();
};

Node* GetNode(uint& ID); // gets node by its ID
Element* GetElement(uint& ID); // gets element by its ID
Propertie* GetPropertie(uint& ID); // gets prop by its ID
//Bolt* GetBolt(uint& ID); // gets bolt params by its prop ID
Material* GetMaterial(uint& ID); // gets mat by its ID

vector<Element*> GetElementsByNode(Node& comm_node); // gets elements by common node;
vector<Element*> GetAdjacentElements(Element& first_element); // gets elements by adjacent element
vector<Element*> GetAdjacentBoltElements(Element& first_element); // gets next bolt elements in single bolt connection
