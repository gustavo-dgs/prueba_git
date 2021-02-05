#ifndef PRODUCTO_H
#define PRODUCTO_H
#include "DBOperacion.h"
#include "Clasebase.h"
#include "Usuario.h"
#include "Empresa.h"

class Producto : public ClaseBase{
    protected: int id_producto;
    std::string tienda;
    std::string descripcion;
    int precio;
    int cantidad;
    int id_categoria;
public:
    Producto();
    Producto(int,std::string,std::string,int,int,std::string);
    ~Prodcuto();

    int getId_producto()const;
    void setId_producto(int value);
    std::string getTienda()const;
    void setTienda(const std::string &value);
    std::string getDescripcion()const;
    void setDescripcion(const std::string &value);
    int getPrecio()const;
    void setPrecio(int value);
    int getCantidad()const;
    void setCantidad(int value);
    int getId_Categoria()const;
    void setId_categoria(int value);

    void crear();
    bool consultar(std::string,std::string);
    void actualizar();
    void eliminar();

    void modificarStock(int);
};

#endif
#include "ClaseBase.h"