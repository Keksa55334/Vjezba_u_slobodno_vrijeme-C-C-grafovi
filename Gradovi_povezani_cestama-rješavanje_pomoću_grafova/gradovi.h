#include <vector>
#include <set>

using namespace std;
int NumRoads(vector<vector<int> > V);
int NumTrios(vector<vector<int> > V, set<tuple<int, int, int> > trios);
int NumTriosGraph(vector<vector<int> > V);
bool IsConnected(vector<vector<int> > V);
bool IsOrganized(vector<vector<int> > V);
int ShortestPath(vector<vector<int> > V, pair<int, int> C);
int Preplavljivanje(vector<int> lista_dohvacenih,int br_koraka,vector<vector<int> > V,int destinacija);
bool Preplavljivanje2(vector<int> lista_dohvacenih,vector<vector<int> > V);
bool Search(vector<bool> lista,int prijasnji,int grad,vector<vector<int> > V,bool *booldzina);