#include <stdio.h>

typedef struct Borilacka_vjestina{
    void (**vtable)();
    int br;
    
    
}Borilacka_vjestina;

typedef struct MuayThai{
    void (**vtable)();
    int br;
    
}MuayThai;

typedef struct JiuJitsu{
    void (**vtable)();
    int br;
}JiuJitsu;

void MozesLiSakomUGlavuBorilacka(){printf("Ovisi\n");};
void MozesLiSakomUGlavuMuay(){printf("Moreš\n");};
void MozesLiSakomUGlavuJiu(){printf("Nemoš, valjda?\n");};

void MozesLiZagusitiBorilacka(){printf("Ovisi\n");};
void MozesLiZagusitiMuay(){printf("Nemoš\n");};
void MozesLiZagusitiJiu(){printf("Itekako\n");};

void BrBorilacka(Borilacka_vjestina const *obj){printf("%d\n",obj->br);};
void BrMuay(MuayThai const *obj){printf("%d\n",obj->br);};
void BrJiu(JiuJitsu const *obj){printf("%d\n",obj->br);};



void (*BorilackaVtable[])()={&MozesLiSakomUGlavuBorilacka,&MozesLiZagusitiBorilacka,&BrBorilacka};
void (*MuayTable[])()={&MozesLiSakomUGlavuMuay,&MozesLiZagusitiMuay,&BrMuay};
void (*JiuJitsuTable[])()={&MozesLiSakomUGlavuJiu,&MozesLiZagusitiJiu,&BrJiu};

void MozesLiSakom(Borilacka_vjestina const* obj){
    obj->vtable[0]();
}
void MozesLiZagusiti(Borilacka_vjestina const *obj){
    obj->vtable[1]();
}
void Br(Borilacka_vjestina const *obj){
    obj->vtable[2](obj);
}

int main(void){
    Borilacka_vjestina br={BorilackaVtable,10};
    MuayThai mt={MuayTable,11};
    JiuJitsu jt={JiuJitsuTable,12};
    

    Borilacka_vjestina *ptr=&br;
    Borilacka_vjestina *ptr2=(Borilacka_vjestina *)&mt;
    Borilacka_vjestina *ptr3=(Borilacka_vjestina *)&jt;

    //Borilacka
    Br(ptr);
    MozesLiSakom(ptr);
    MozesLiZagusiti(ptr);
    

    //Muay
    Br(ptr2);
    MozesLiSakom(ptr2);
    MozesLiZagusiti(ptr2);
    

    //JiuJitsu
    Br(ptr3);
    MozesLiSakom(ptr3);
    MozesLiZagusiti(ptr3);
    
    
}