#include "stack.h"

void createStack(List &L) //membuat posisi tumpukan paling atas bernilai nil
{
    /*  I.P. Sembarang List
        F.P. terbentuk list kosong */
    top(L) = Nil;

}

address alokasi(infotype data, string isi, double h, int ke) //membuat elemen atau tumpukan baru
{
    /*  I.P. terdefinisi suatu data yang akan dialokasikan ke memori
        F.P. mengaklokasikan P yang menunjuk pada element baru */
    address P;
    P = new ElmList;

    P->Obat = data;
    P->kadaluarsa = isi;
    harga(P) = h;
    tumpukan_ke(P) = ke;
    next(P)=NULL;

    return P; //mengembalikan pada p, dimana dia dipanggil
}

void push(List &L, address P) //menambah tumpukan ke paling atas
{
    /*  I.P. L sembarang bisa masih kosong atau terisi,
        p alamat element yang telah dialokasikan pada fungsi utama*/
    /*  F.P. menempatkan element P awal list*/
    // list masih kosong
    if (top(L)==NULL){ // jika kosong maka top = p
        top(L)=P;
    }else{
        // list ada isinya
        next(P)=top(L); //jika ada maka next nya = top
        top(L)=P;
    }
}

void pop(List &L, address &P){ //menghapus tumpukan paling atas
    if (top(L) != Nil){
        P = top(L);
        top(L) = next(top(L));
        next(P) = Nil;
        dealokasi(P);
    }
}

void dealokasi(address &P) //menghapus node atau alamat dari memori
{
    /*  I.P. Element P
    F.P. element P dealokasi */
    delete P;
}

void viewList(List L) //menampilkan isi stack dari atas ke bawah
{
    /*  I.P. Sembarang List
        F.P. menampilkan isi dari list */
    address q = top(L);
    do
    {
        cout<< Obat(q) <<"    | " << kadaluarsa(q) <<"               | " << harga(q) << " |  " << "Tumpukan ke : " << tumpukan_ke(q)  << endl;
        q=next(q);
    }
    while(q!=Nil);
}

void reverseStack(List &L) {
    List temp;
    createStack(temp);
    
    address P = NULL;

    while (top(L) != Nil) {
        P = top(L);           // ambil elemen paling atas
        top(L) = next(P);     // pindahkan top ke elemen berikutnya
        next(P) = Nil;        // putus hubungan elemen
        push(temp, P);        // push ke stack sementara
    }

    // salin kembali ke stack utama
    top(L) = top(temp);
}
// void push(List &L, address P)
// {
    // 	if (top(L)==NULL){
        //         top(L)=P;
        //     }else{
            //         // list ada isinya
            //         address last =top(L);
            //         while(next(last)!=Nil)
            //         {
                //         	last=next(last);
                // 		}
                // 		next(last)=P;
                //     }
                
                // }
// address findElm(List L, infotype x){
// 	address P = top(L);
// 	while(P != NULL && Obat(P) != x){
// 		P = next(P);
// 	}
// 	return P;
// }
// void insertAfter(List &L, address P, address Prec){
// 	if (Prec != NULL){
// 		next(P) = next(Prec);
// 		next(Prec) = P;
// 	}
// }

// void delLast(List &L, address &P) {
// 	if (top(L) != Nil) {
// 		address prec = top(L);
// 		address last = top(L);
// 		while (next(last) != Nil) 
// 		{
// 			prec = last;
// 			last = next(last);
// 		}
// 		next(prec) = Nil;
// 		dealokasi(last);
// 	}
// }
// void delAfter(List &L, address &P, address Prec) {
// 	if (Prec != Nil) {
// 		P = next(Prec);
// 		if (P != Nil) 
// 		{
// 			next(Prec) = next(P);
// 			next(P) = Nil;
// 			dealokasi(P);
// 		}
// 	}
// }	

