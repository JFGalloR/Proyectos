
package ejercicio_graficos;

import javax.swing.JFrame;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.PiePlot3D;
import org.jfree.data.general.DefaultPieDataset;
import org.jfree.data.general.PieDataset;
import org.jfree.util.Rotation;

public class Ejercicio_Graficos extends JFrame {

    public static void main(String[] args) {
        Ventana v = new Ventana();
        v.show();
    }
}
