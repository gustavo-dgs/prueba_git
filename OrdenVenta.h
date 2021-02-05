#ifndef ORDENVENTA_H
#define ORDENVENTA_H
#include "DBOperacion.h"
#include "Clasebase.h"
#include "Orden.h"
#include "Usuario.h"


class OrdenVenta : public Entidad, public ClaseBase{
    protected: int id_orden;
    int cliente;
    int total;
    std::string tipo_de_pago;
public:
    OrdenVenta();
    OrdenVenta(int,std::string,int,std::string,int,std::string,std::string);
    ~OrdenVenta();

    int getId_orden()const;
    void setId_orden(int value);
    int getCliente()const;
    void setCliente(int value);
    int getTotal()const;
    void setTotal(int value);
    std::string getTipo_de_pago()const;
    void setTipo_de_pago(const std::string &value);

    void crear();
    bool consultar(std::string,std::string);
    void actualizar();
    void eliminar();

    void calcularTotal(int value);
};

#endif
#include "ClaseBase.h"