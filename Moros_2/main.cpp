#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long data_t;

inline char simb( data_t val )
{
   return val < 10 ? '0' + val : 'A' + val - 10;
}


ostream& operator << ( ostream& stream, vector<data_t>& obj )
{
   stream << "{[" <<  obj.size() << "]: ";
   for( vector<data_t>::iterator i = obj.begin(); i != obj.end(); i++ )
      stream << *i << ( i + 1 != obj.end() ? ", " : " " );
   return stream << "}";
};

string Print(string s)
{
    string t = "";
    for(int i = 4; i < (int)s.size() - 1; i++)
    {
        t += s[i];
    }
    return t;
}

int main( int argc, char **argv )
{
   bool debug = argc > 1;
   while( true )
    {
      int metr = 10;
      data_t ch, zn;
      cout << "Enter n - ";
      cin >> ch;
      cout << "Enter m - ";
      cin >> zn;
      string sval( "0." );
      vector<data_t> list;
      data_t ost = ch % zn;
      while( true )
      {
         data_t ch = ost * metr;
         ost = ch % zn;
         sval.push_back( simb( ch / zn ) );
         if( debug ) cout << ost << " -> " << list << endl;
         if( 0 == ost ) break;
         vector<data_t>::iterator it =
            find( list.begin(), list.end(), ost );
         if( it == list.end() )
            list.push_back( ost );
         else {
            ost = list.end() - it;
            break;
         }
      };
      if( ost != 0 )
      {
         string::iterator is = sval.end() - ost;
         sval.insert( is, '(' );
         sval += ")";
      }
      cout << "Period is " << Print(sval) << endl;
      cout << "Enter 'F' if you want to stop this work or another button if you want continue!" << endl;
      string stop;
      cin >> stop;
      if( stop == "F" || stop == "f")
        return 0;
   }
}

