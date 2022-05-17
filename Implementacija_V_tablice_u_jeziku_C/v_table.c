#include <stdio.h>


typedef struct {
    void (**vtable)();
    
}Animal;

typedef struct Dog{
    void (**vtable)();
    
}Dog;

typedef struct Fox{
    void (**vtable)();
    int fox;//ovo sam stavia da probam samo hoće li raditi ako u createAnimal
            //samo stavim return return &(Animal){.vtable=FoxVtable, .fox=5});
            //umjesto return (Animal *)(&(Fox) {.vtable=FoxVtable,.fox=5});
            //zanimalo me hoće li se ponašati animal kao fox ako ima vtablicu foxa
            //logično je da nebi trebalo al eto iša sam provjeriti
            //SPOILER ALERT:neće
    
}Fox;





void WhatDoesTheAnimalSay(Animal const* obj){printf("Animal noises\n");};
void WhatDoesTheDogSay(Dog const* obj){printf("woof\n");};
void WhatDoesTheFoxSay(Fox const* obj){printf("Ring-ding-ding-ding-dingeringeding!   %d\n",obj->fox);};

static void (*AnimalVtable[])()={&WhatDoesTheAnimalSay};
static void (*DogVtable[])()= {&WhatDoesTheDogSay};
static void (*FoxVtable[])() ={&WhatDoesTheFoxSay};

//factory
Animal *createAnimal(int a){
    if(a==1){
        return &(Animal) {.vtable=AnimalVtable};
    }
    if(a==2){
        return (Animal *)(&(Dog) {.vtable=DogVtable});
    }
    if(a==3){
        return (Animal *)(&(Fox) {.vtable=FoxVtable,.fox=5});
    }

}

void WhatDoesItSay(Animal const* obj){
    obj->vtable[0](obj);
}

int main(){
    
    Animal *ptr1= createAnimal(1);
    Animal *ptr2=createAnimal(2);
    Animal *ptr3=createAnimal(3);

    WhatDoesItSay(ptr1);
    WhatDoesItSay(ptr2);
    WhatDoesItSay(ptr3);
}