#include <bits/stdc++.h>
#include <vector>
#include "gradovi.h"

int NumRoads(vector<vector<int>> V){
    int i=0;
    int j=0;
    int br_cesti=0;
    for(int i=0;i<V.size();i++){
        vector<int> trenutacno=V[i];
        br_cesti+=trenutacno.size();
    }
    return br_cesti/2;
}

int ShortestPath(vector<vector<int> > V, pair<int, int> C){
    int br_koraka=0;
    vector<int> lista_dohvacenih;
    lista_dohvacenih.push_back(C.first);
    return Preplavljivanje(lista_dohvacenih,br_koraka,V,C.second);

}
int Preplavljivanje(vector<int> lista_dohvacenih,int br_koraka,vector<vector<int> > V,int destinacija){
    br_koraka+=1;
    bool nasli=false;
    vector<int> lista_dohvacenih2;
    for(int i=0;i<lista_dohvacenih.size();i++){//dodavanje u kopiju
        lista_dohvacenih2.push_back(lista_dohvacenih[i]);
        
    }
    
    
    for(int i=0;i<lista_dohvacenih.size();i++){
        
        vector<int> gradovi=V[lista_dohvacenih[i]];
        for(int j=0;j<gradovi.size();j++){
            if(!(find(lista_dohvacenih.begin(), lista_dohvacenih.end(), gradovi[j]) != lista_dohvacenih.end())){
                lista_dohvacenih2.push_back(gradovi[j]);
            }
            
            if(gradovi[j]==destinacija){
                
                nasli=true;
                
            }
        }
        
    }
    
    if(nasli){
        return br_koraka;
    }
    else if(lista_dohvacenih.size()==lista_dohvacenih2.size()){
        return -1;
    }else{
        
        return Preplavljivanje(lista_dohvacenih2,br_koraka,V,destinacija);
    }

}

bool IsConnected(vector<vector<int> > V){
    vector<int> lista_dohvacenih;
    lista_dohvacenih.push_back(0);
    return Preplavljivanje2(lista_dohvacenih,V);

}
bool Preplavljivanje2(vector<int> lista_dohvacenih,vector<vector<int>> V){
     vector<int> lista_dohvacenih2;
    for(int i=0;i<lista_dohvacenih.size();i++){//dodavanje u kopiju
        lista_dohvacenih2.push_back(lista_dohvacenih[i]);
        
    }
    
    
    for(int i=0;i<lista_dohvacenih.size();i++){
        
        vector<int> gradovi=V[lista_dohvacenih[i]];
        for(int j=0;j<gradovi.size();j++){
            if(!(find(lista_dohvacenih.begin(), lista_dohvacenih.end(), gradovi[j]) != lista_dohvacenih.end())){
                lista_dohvacenih2.push_back(gradovi[j]);
            }
            
            
            
        }
        
    }
    
    
    if(lista_dohvacenih.size()==lista_dohvacenih2.size()){
        sort( lista_dohvacenih.begin(), lista_dohvacenih.end() );//micanje duplikata
        lista_dohvacenih.erase( unique( lista_dohvacenih.begin(), lista_dohvacenih.end() ),lista_dohvacenih.end() );
        if(lista_dohvacenih.size()==V.size()){

            return true;
        }else{
            return false;
        }
    }else{
        
        return Preplavljivanje2(lista_dohvacenih2,V);
    }

}

int NumTrios(vector<vector<int> > V, set<tuple<int, int, int> > trios){
    int br=0;
    for(auto i=trios.begin();i!=trios.end();i++){
        tuple<int,int,int> tup=(*i);
        int prvi=get<0>(tup);
        int drugi=get<1>(tup);
        int treci=get<2>(tup);
        vector<int> susjedi_prvi=V[prvi];
        vector<int> susjedi_drugi=V[drugi];
        vector<int> susjedi_treci=V[treci];
        bool p2=false,p3=false,d1=false,d3=false,t1=false,t2=false;
        for(int j=0;j<susjedi_prvi.size();j++){
            if(susjedi_prvi[j]==drugi){
                p2=true;
            }
            if(susjedi_prvi[j]==treci){
                p3=true;
            }
        }

        for(int j=0;j<susjedi_drugi.size();j++){
            if(susjedi_drugi[j]==prvi){
                d1=true;
            }
            if(susjedi_drugi[j]==treci){
                d3=true;
            }
        }

        for(int j=0;j<susjedi_treci.size();j++){
            if(susjedi_treci[j]==drugi){
                t2=true;
            }
            if(susjedi_treci[j]==prvi){
                t1=true;
            }
        }

        if(p2 && p3 && d1 && d3 && t2 && t1){
            br+=1;
        }

    }
    return br;
}
int NumTriosGraph(vector<vector<int> > V){
    set<tuple<int,int,int>> set1;
    for(int i=0;i<V.size();i++){
        for(int j=0;j<V.size();j++){
            for(int k=0;k<V.size();k++){
                tuple<int,int,int> tup(i,j,k);
                set1.insert(tup);
            }
        }
    }
    return NumTrios(V,set1)/6;
}
bool IsOrganized(vector<vector<int> > V){
    
    bool booldzina=true;
    vector<bool> lista;
    lista.push_back(true);
    for(int i=1;i<V.size();i++){
        lista.push_back(false);
    }
    booldzina=Search(lista,-1,0,V,&booldzina);
    bool bool2=IsConnected(V);
    return (booldzina && bool2);
}
bool Search(vector<bool> lista,int prijasnji,int grad,vector<vector<int> > V,bool *booldzina){
    vector<int> susjedi=V[grad];
    
    
    for(int i=0;i<susjedi.size();i++){
        
        if(susjedi[i]==prijasnji){
            ;
        }else if(lista[susjedi[i]]!=true){
            lista[susjedi[i]]=true;
            
            Search(lista,grad,susjedi[i],V,booldzina);
        }else{
            *booldzina=false;
        }
    }
    
    return *booldzina;

    
}
