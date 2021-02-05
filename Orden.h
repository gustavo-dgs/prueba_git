#ifndef ORDEN_H
#define ORDEN_H
#include "DBOperacion.h"
#include "Clasebase.h"
#include "Usuario.h"
#include "Empresa.h"

class Orden : public Entidad, public ClaseBase{
    protected: int id_orden;
    std::string tienda;
    int transportista;
    std::string estatus;
    int calificacion;
    std::string fecha;
    std::string tipo;
public:
    Orden();
    Orden(int,std::string,int,std::string,int,std::string,std::string);
    ~Orden();

    int getId_orden()const;
    void setId_orden(int value);
    std::string getTienda()const;
    void setTienda(const std::string &value);
    int getTransportista()const;
    void setTransportista(int value);
    std::string getEstatus()const;
    void setEstatus(const std::string &value);
    int getCalificacion()const;
    void setCalificacion(int value);
    std::string getTipo()const;
    void setTipo(const std::string &value);

    void crear();
    bool consultar(std::string,std::string);
    void actualizar();
    void eliminar();

    void actualizarOrdenAVerificada();
    void actualizarOrdenAPorDespachar();
    void actualizarOrdenAEnEnvio();
    void actualizarOrdenAEntregada();
    void cancelarOrden();
    void añadirProducto();

};

#endif
#include "ClaseBase.h"