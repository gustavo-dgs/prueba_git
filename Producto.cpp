#include "Producto.h"

Producto::Producto(){
    this->id_producto= 0;
    this->tienda = "";
    this->descripcion = "";
    this->precio = 0;
    this->cantidad = 0;
    this->id_categoria = 0;

    Producto::Producto(int id_producto, std::string tienda, std::string descripcion,
        int precio, int cantidad, int id_categoria){
        this->id_producto= id_producto;
        this->tienda = tienda;
        this->descripcion = descripcion;
        this->precio = precio;
        this->cantidad = cantidad;
        this->id_categoria = id_categoria;
    }
    
    Producto::~Producto(){}

    int getId_producto()const{
        return id_producto;
    }
    void setId_producto(int value){
        id_producto=value;
    }
    std::string getTienda()const{
        return tienda;
    }
    void setTienda(const std::string &value){
        tienda=value;
    }
    std::string getDescripcion()const{
        return descripcion;
    }
    void setDescripcion(const std::string &value){
        descripcion=value;
    }
    int getPrecio()const{
        return precio;
    }
    void setPrecio(int value){
        precio=value;
    }
    int getCantidad()const{
        return cantidad;
    }
    void setCantidad(int value){
        cantidad=value;
    }
    int getId_Categoria()const{
        return id_ategoria;
    }
    void setId_categoria(int value){
        id_categoria=value;
    }

    void Producto::crear(){
        dbOperacion->prepararQuery("INSERT INTO productos (id_producto, tienda, descripcion, precio, cantidad,"
                                "id_categoria) VALUES(?,?,?,?,?,?)");
        dbOperacion->agregarInt(id_producto);
        dbOperacion->agregarString(tienda);
        dbOperacion->agregarString(descripcion);
        dbOperacion->agregarInt(precio);
        dbOperacion->agregarInt(cantidad);
        dbOperacion->agregarInt(id_categoria);

        dbOperacion->ejecutar();
    }

    bool Producto::consultar(std::string campo, std::string valor){
        sql::ResultSet *res;
        bool seEncontro;

        dbOperacion->prepararQuery("SELECT * FROM productos WHERE " + campo + "=?");
        if (campo.compare("id_producto") == 0){
            dbOperacion->agregarInt(stoi(valor));
        }else{
            dbOperacion->agregarString(valor);
        }

        res = dbOperacion->ejecutar();

        if (res->next()){
            id_producto = res->getInt("id_producto");
            tienda = res->getString("tienda");
            descripcion = res->getString("descripcion");
            precio = res->getInt("precio");
            cantidad = res->getInt("cantidad");
            id_categoria = res->getInt("id_categoria");

            seEncontro = true;

        }else{
            seEncontro = false;
        }

        delete res;

        return seEncontro;
    }

    void Producto::actualizar(){
        dbOperacion->prepararQuery("UPDATE productos SET tienda=?, descripcion=?, precio=?, cantidad=?,"
                                "WHERE id_producto = ?");
        dbOperacion->agregarInt(id_producto);
        dbOperacion->agregarString(tienda);
        dbOperacion->agregarString(descripcion);
        dbOperacion->agregarInt(precio);
        dbOperacion->agregarInt(cantidad);
        dbOperacion->agregarInt(id_categoria);

        dbOperacion->ejecutar();
    }

    void Producto::eliminar(){
        dbOperacion->prepararQuery("DELETE FROM productos WHERE id_producto = ?");

        dbOperacion->agregarString(id_producto);

        dbOperacion->ejecutar();
    }

    void Producto::modificarStock(int value){
        dbOperacion->prepararQuery("MODIFY cantidad FROM productos");
        cantidad=cantidad+value;
    }