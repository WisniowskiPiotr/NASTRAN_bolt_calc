

Card::Card(string& name)
{
  Fields.resize(1);
  Fields[0]=name;
};

void Card::InsertField(string& field, uint& poz=0)
{
  if (poz==0)
    {Fields.push_back(field)};
  else
    {
    if (Fields.size<=poz)
      Fields.resize(poz+1);
    Fields[poz]=field;
    }
};

string Card::GetFieldStr(uint& poz=0)
{
  return Fields[poz];
};

int Card::GetFieldInt(uint& poz)
{
  return stoi(GetFieldStr(poz));
};
uint Card::GetFieldID(uint& poz=1);
{
  return GetFieldInt(poz);
};
double Card::GetFieldReal(uint& poz)
{
  size_t s=Fields[poz].size; // need to add E in case 1.1-1
  bool now=false;
  for (int i=0; i<s; i++)
    {
      if (Fields[poz][i]=='E')
        break;
      if (now==true and (Fields[poz][i]=='+' || Fields[poz][i]=='-')
        {
        Fields[poz].insert(i,'E');
        break;
        };
      if (isDigit(Fields[poz][i])
        now=true;
    };
  return strtod(GetFieldStr(poz));
};;