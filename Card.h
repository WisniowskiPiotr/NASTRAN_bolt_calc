

class Card
{
  private:
  vector<string> Fields;

  public:
  Card(string& name); // creates card with already defined type field
  void InsertField(string& field, uint& poz=0); // inserts field in card on spec position. if poz=0 creates new field on back.
  string GetFieldStr(uint& poz); // gets field directly defauld is type od card
  int GetFieldInt(uint& poz); // converts field to int
  uint GetFieldID(uint& poz); // converts field to uint
  double GetFieldReal(uint& poz); // converts field to real

};