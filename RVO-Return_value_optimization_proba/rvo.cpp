#include <iostream>
using namespace std;
struct Blob {
    Blob() {
        cout<<("[BLob::Ctor] Default")<<endl;
    }

    Blob(Blob const&) {
        cout<<("[Blob::Ctor] Copy")<<endl;
    }
};

auto Foo(Blob* const b) -> Blob {
    Blob c=Blob(*b);
    return c;
}

int main(void) {
    Blob b;
    auto B = Foo(&b);

}