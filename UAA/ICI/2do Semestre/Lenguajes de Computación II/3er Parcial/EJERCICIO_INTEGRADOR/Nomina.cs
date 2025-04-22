using System;

// Clase del tipo nómina.
public class Nomina
{
	// Atributos de la clase.
	private int diasLab;

	// Get y Set del atributo.
	public int DiasLab { get; set; }

	// Método para realizar el calculo de nómina.
	public decimal CalcularNomina(int  diasLab, decimal valorDia)
	{
		// Operación para obtención de nómina.
		return diasLab * valorDia;
	}
}
