#include "Orden.h"

Orden::Orden(){
    this->id_orden= 0;
    this->tienda = "";
    this->transportista = 0;
    this->estatus = "";
    this->calificacion = 0;
    this->fecha = "";
    this->tipo = "";

    Orden::Orden(int id_orden, std::string tienda, int transportista,
        std::string estatus, int calificacion, std::string fecha,std::string tipo){
        this->id_orden= id_orden;
        this->tienda = tienda;
        this->transportista = transportista;
        this->estatus = estatus;
        this->calificacion = calificacion;
        this->fecha = fecha;
        this->tipo = tipo;
    }
    
    Orden::~Orden(){}

    int getId_orden()const{
        return id_orden;
    }
    void setId_orden(int value){
        id_orden=value;
    }
    std::string getTienda()const{
        return tienda;
    }
    void setTienda(const std::string &value){
        tienda=value;
    }
    int getTransportista()const{
        return transportista;
    }
    void setTransportista(int value){
        transportista=value;
    }
    std::string getEstatus()const{
        return estatus;
    }
    void setEstatus(const std::string &value){
        estatus=value;
    }
    int getCalificacion()const{
        return calificacion;
    }
    void setCalificacion(int value){
        calificacion=value;
    }
    std::string getTipo()const{
        return tipo;
    }
    void setTipo(const std::string &value){
        tipo=value;
    }

    void Orden::crear(){
        dbOperacion->prepararQuery("INSERT INTO ordenes (id_orden, tienda, transportista, estatus, calificacion,"
                                "fecha,tipo) VALUES(?,?,?,?,?,?,?)");
        dbOperacion->agregarInt(id_orden);
        dbOperacion->agregarString(tienda);
        dbOperacion->agregarInt(transportista);
        dbOperacion->agregarString(estatus);
        dbOperacion->agregarInt(calificacion);
        dbOperacion->agregarString(fecha);
        dbOperacion->agregar(tipo);

        dbOperacion->ejecutar();
    }

    bool Orden::consultar(std::string campo, std::string valor){
        sql::ResultSet *res;
        bool seEncontro;

        dbOperacion->prepararQuery("SELECT * FROM ordenes WHERE " + campo + "=?");
        if (campo.compare("id_orden") == 0){
            dbOperacion->agregarInt(stoi(valor));
        }else{
            dbOperacion->agregarString(valor);
        }

        res = dbOperacion->ejecutar();

        if (res->next()){
            id_orden = res->getInt("id_orden");
            tienda = res->getString("tienda");
            transportista = res->getInt("transportista");
            estatus = res->getString("estatus");
            calificacion = res->getInt("calificacion");
            fecha = res->getString("fecha");
            tipo = res->getString("tipo");

            seEncontro = true;

        }else{
            seEncontro = false;
        }

        delete res;

        return seEncontro;
    }

    void Orden::actualizar(){
        dbOperacion->prepararQuery("UPDATE ordenes SET tienda=?, transportista=?, estatus=?, calificacion=?,"
                                "fecha=?, tipo=? WHERE id_orden = ?");
        dbOperacion->agregarInt(id_orden);
        dbOperacion->agregarString(tienda);
        dbOperacion->agregarInt(transportista);
        dbOperacion->agregarString(estatus);
        dbOperacion->agregarInt(calificacion);
        dbOperacion->agregarString(fecha);
        dbOperacion->agregar(tipo);

        dbOperacion->ejecutar();
    }

    void Orden::eliminar(){
    dbOperacion->prepararQuery("DELETE FROM ordenes WHERE id_orden = ?");

    dbOperacion->agregarString(id_orden);

    dbOperacion->ejecutar();

    void Orden::actualizarOrdenAVerificada(){
        dbOperacion->prepararQuery("UPDATE estatus FORM ordenes");
        setEstatus("Verificada");
    }

    void Orden::actualizarOrdenAPorDespachar(){
        dbOperacion->prepararQuery("UPDATE estatus FORM ordenes");
        setEstatus("Por Despachar");
    }

    void Orden::actualizarOrdenAEnEnvio(){
        dbOperacion->prepararQuery("UPDATE estatus FORM ordenes");
        setEstatus("En Envio");
    }

    void Orden::actualizarOrdenAEntregada(){
        dbOperacion->prepararQuery("UPDATE estatus FORM ordenes");
        setEstatus("Entregada");
    }

    void Orden::cancelarOrden(){
        dbOperacion->prepararQuery("UPDATE estatus FORM ordenes");
        setEstatus("Cancelada");
    }

    void Orden::añadirProducto(){
        dbOperacion->prepararQuery("UPDATE estatus FORM ordenes");
        
    }
}
