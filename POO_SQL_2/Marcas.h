#pragma once
#include <iostream>
#include "Producto.h"
#include <mysql.h>
#include "ConexionBD.h"
#include <string>

using namespace std;

class Marcas :
    public Producto {
	// atributos
	private: string marca;
	// constructor
	public:Marcas() {
	  }
	  Marcas(string pro, string desc, string fi, int idpro, int idmar, int exi, double costo, double venta, string mar) : Producto(pro, desc, fi, idpro, idmar, exi, costo, venta) {
		  marca = mar;
	  }

	  // METODOS
	  //set (modificar)
	  void setProducto(string pro) { producto = pro; }
	  void setDescripcion(string desc) { descripcion = desc; }
	  void setFechaIngreso(string fi) { fecha_ingreso = fi; }
	  void setIDProducto(int idpro) { idproducto = idpro; }
	  void setIDMarca(int idmar) { idmarca = idmar; }
	  void setExistencia(int exi) { existencia = exi; }
	  void setPrecioCosto(double costo) { precio_costo = costo; }
	  void setPrecioVenta(double venta) { precio_venta = venta; }
	  void setMarca(string mar) { marca = mar; }

	  //get (mostrar)
	  string getProducto() { return producto; }
	  string getDescripcion() { return descripcion; }
	  string getFechaIngreso() { return fecha_ingreso; }
	  int getIDProducto() { return idproducto; }
	  int getIDMarca() { return idmarca; }
	  int getExistencia() { return existencia; }
	  double getPrecioCosto() { return precio_costo; }
	  double getPrecioVenta() { return precio_venta; }
	  string getMarca() { return marca; }


	  // metodo
	  void crear() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  string ID1 = to_string(idproducto);
			  string ID2 = to_string(idmarca);
			  string ID3 = to_string(precio_costo);
			  string ID4 = to_string(precio_venta);
			  string ID5 = to_string(existencia);
			  string insert = "INSERT INTO marcasyproductos.productos (idProductos,Producto,idMarca,Descripcion,Precio_costo,Precio_venta,Existencia,Fecha_ingreso)VALUES('"+ ID1 +"','" + producto + "','" + ID2 + "','" + descripcion + "'," + ID3 + "," + ID4 + "," + ID5 + ", '" + fecha_ingreso + "');";
			  string insert = "INSERT INTO marcasyproductos.marcas (idMarca,Marca)VALUES('" + ID2 + "','" + marca + "');";
			  const char* i = insert.c_str();
			  q_estado = mysql_query(cn.getConectar(), i);
			  if (!q_estado) {
				  cout << "Ingreso exitoso.." << endl;
			  }
			  else {
				  cout << "Error al ingresar información" << endl;
			  }
		  }
		  else {
			  cout << "Error en la conexion" << endl;
		  }
		  cn.cerrar_conexion();
	  }
	  void leer() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila;
		  MYSQL_RES* resultado;
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  string consulta = " select * from marcasyproductos.productos";
			  string consulta = " select * from marcasyproductos.marcas";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  cout << "-----------------PRODUCTOS--------------------" << endl;
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << endl;
				  }
			  }
			  else {
				  cout << "Error al ingresar informacion" << endl;
			  }
		  }else{
			  cout << "Error en la conexion" << endl;
		  }
		  cn.cerrar_conexion();

	  }
};

