#include "OrdenVenta.h"

OrdenVenta::OrdenVenta(){
    this->id_orden= 0;
    this->cliente = 0;
    this->total = 0;
    this->tipo_de_pago = "";

    OrdenVenta::OrdenVenta(int id_orden, int cliente, int total, std::string tipo_de_pago){
        this->id_orden= id_orden;
        this->cliente = cliente;
        this->total = total;
        this->tipo_de_pago = tipo_de_pago;
    }
    
    OrdenVenta::~OrdenVenta(){}

    int getId_orden()const{
        return id_orden;
    }
    void setId_orden(int value){
        id_orden=value;
    }
    int getCliente()const{
        return cliente;
    }
    void setCliente(int value){
        cliente=value;
    }
    int getTotal()const{
        return total;
    }
    void setTotal(int value){
        total=value;
    }
    std::string getTipo_de_pago()const{
        return tipo_de_pago;
    }
    void setTipo_de_pago(const std::string &value){
        tipo_de_pago=value;
    }
    

    void OrdenVenta::crear(){
        dbOperacion->prepararQuery("INSERT INTO ordenes de venta (id_orden, cliente, total,"
                                "tipo_de_pago) VALUES(?,?,?,?,?,?,?)");
        dbOperacion->agregarInt(id_orden);
        dbOperacion->agregarInt(cliente);
        dbOperacion->agregarInt(total);
        dbOperacion->agregarString(tipo_de_pago);

        dbOperacion->ejecutar();
    }

    bool OrdenVenta::consultar(std::string campo, std::string valor){
        sql::ResultSet *res;
        bool seEncontro;

        dbOperacion->prepararQuery("SELECT * FROM ordenes de venta WHERE " + campo + "=?");
        if (campo.compare("id_orden") == 0){
            dbOperacion->agregarInt(stoi(valor));
        }else{
            dbOperacion->agregarString(valor);
        }

        res = dbOperacion->ejecutar();

        if (res->next()){
            id_orden = res->getInt("id_orden");
            cliente = res->getInt("cliente");
            total = res->getInt("total");
            tipo_de_pago = res->getString("tipo_de_pago");

            seEncontro = true;

        }else{
            seEncontro = false;
        }

        delete res;

        return seEncontro;
    }

    void OrdenVenta::actualizar(){
        dbOperacion->prepararQuery("UPDATE ordenes de venta SET tienda=?, cliente=?, total=?, tipo_de_pago=?,"
                                "fecha=?, tipo=? WHERE id_orden = ?");
        dbOperacion->agregarInt(id_orden);
        dbOperacion->agregarInt(cliente);
        dbOperacion->agregarInt(total);
        dbOperacion->agregarString(tipo_de_pago);

        dbOperacion->ejecutar();
    }

    void OrdenVenta::eliminar(){
    dbOperacion->prepararQuery("DELETE FROM ordenes de venta WHERE id_orden = ?");

    dbOperacion->agregarString(id_orden);

    dbOperacion->ejecutar();

    void OrdenVenta::calcularTotal(){
        dbOperacion->prepararQuery("CALCULATE total FROM ordenes");
        total=total+(total*0.12); //IVA
    }


}