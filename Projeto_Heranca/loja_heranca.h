#ifndef _LOJA_H_
#define _LOJA_H_

#include <iostream>
#include <string>

using namespace std;

class Produto{
private:
    string nome;
    unsigned preco;
public:
    inline Produto(const char *N="", const unsigned &P=0): nome(N), preco(P) {}
    istream &digitar(istream &I);
    ostream &imprimir(ostream &O) const;
    istream &ler(istream &arq);
    inline ostream &salvar(ostream &O) const {return imprimir(O);}
    friend ostream &operator<<(ostream &O, const Produto &P);
    friend istream &operator>>(istream &I, Produto &P);
};

inline istream &operator>>(istream &I, Produto &P) {return P.digitar(I);}
inline ostream &operator<<(ostream &O, Produto &P) {return P.imprimir(O);}

class Livro: public Produto{
private:
    string autor;
public:
    inline Livro(const char *N="", const unsigned &P=0, const char *A =""): Produto(N, P), autor(A) {}
    istream &digitar(istream &I);
    ostream &imprimir(ostream &O) const;
    istream &ler(istream &I);
    inline ostream &salvar(ostream &O) const {return imprimir(O);}
    friend ostream &operator<<(ostream &O, const Livro &P);
    friend istream &operator>>(istream &I, Livro &P);
//    friend class ListaLivro;
};

inline istream &operator>>(istream &I, Livro &X) {return X.digitar(I);}
inline ostream &operator<<(ostream &O, Livro &X) {return X.imprimir(O);}

class CD: public Produto{
private:
    unsigned numFaixas;
public:
    inline CD(const char *N="", const unsigned &P=0, const unsigned &F = 0): Produto(N, P), numFaixas(F) {}
    istream &digitar(istream &I);
    ostream &imprimir(ostream &O) const;
    istream &ler(istream &I);
    inline ostream &salvar(ostream &O) const {return imprimir(O);}
    friend ostream &operator<<(ostream &O, const CD &P);
    friend istream &operator>>(istream &I, CD &P);
};

inline istream &operator>>(istream &I, CD &X) {return X.digitar(I);}
inline ostream &operator<<(ostream &O, CD &X) {return X.imprimir(O);}

class DVD: public Produto{
private:
    unsigned duracao;
public:
    inline DVD(const char *N="", const unsigned &P=0, const unsigned &D = 0): Produto (N,P), duracao(D) {}
    istream &digitar(istream &I);
    ostream &imprimir(ostream &O) const;
    istream &ler(istream &I);
    inline ostream &salvar(ostream &O) const {return imprimir(O);}
    friend ostream &operator<<(ostream &O, const DVD &P);
    friend istream &operator>>(istream &I, DVD &P);
};

inline istream &operator>>(istream &I, DVD &X) {return X.digitar(I);}
inline ostream &operator<<(ostream &O, DVD &X) {return X.imprimir(O);}

class ListaLivro{
private:
    Livro *livros;
    unsigned tam;
public:
    inline ListaLivro(): livros(NULL), tam(0) {}
    inline ListaLivro(unsigned const &T): livros(new Livro [T]), tam(T) {}
    ~ListaLivro();
    void incluir(const Livro &L);
    void excluir(const unsigned &id);
    void imprimir() const;
    void ler(istream &I);
    void salvar(ostream &O) const;
};

class ListaCD{
private:
    CD *cds;
    unsigned tam;
public:
    inline ListaCD(): cds(NULL), tam(0) {}
    ~ListaCD();
    void incluir(const CD &L);
    void excluir(unsigned id);
    void imprimir() const;
    void ler(istream &I);
    void salvar(ostream &O) const;
};

class ListaDVD{
private:
    DVD *dvds;
    unsigned N;
public:
    void incluir(const DVD &L);
    void excluir(unsigned id);
    void imprimir() const;
    void ler(istream &I);
    void salvar(ostream &O) const;
};

class Loja{
private:
    ListaLivro LL;
    ListaCD LC;
    ListaDVD LD;
public:
    inline Loja(): LL(), LC(), LD() {}
    inline void incluirLivro(const Livro &X) {LL.incluir(X);}
    inline void excluirLivro(unsigned id) {LL.excluir(id);}
    inline void incluirDVD(const DVD &X) {LD.incluir(X);}
    inline void excluirDVD(unsigned id) {LD.excluir(id);}
    inline void incluirCD(const CD &X) {LC.incluir(X);}
    inline void excluirCD(unsigned id) {LC.excluir(id);}
    void imprimir() const;
    void ler(const char* arq);
    void salvar(const char* arq) const;
};
#endif // _LOJA_H_
