/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package ejercicio_grafica;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.StringTokenizer;
import javax.swing.JFrame;
import static javax.swing.WindowConstants.EXIT_ON_CLOSE;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.data.category.CategoryDataset;
import org.jfree.data.category.DefaultCategoryDataset;
import java.util.ArrayList;

public class Ejercicio_Grafica extends JFrame {
    
    ArrayList<String> lE = new ArrayList();
    ArrayList<Integer> lH = new ArrayList();
    ArrayList<Integer> lM = new ArrayList();
    
    public Ejercicio_Grafica(String appTitle) {
        super(appTitle);

        // Create Dataset  
        CategoryDataset dataset = createDataset();

        //Create chart  
        JFreeChart chart = ChartFactory.createBarChart(
                "Reporte de Base de Datos", //Chart Title  
                "Estado", // Category axis  
                "Población", // Value axis  
                dataset,
                PlotOrientation.VERTICAL,
                true, true, false
        );

        ChartPanel panel = new ChartPanel(chart);
        setContentPane(panel);
        setLocationRelativeTo(null);
    }

    private CategoryDataset createDataset() {
        DefaultCategoryDataset dataset = new DefaultCategoryDataset();
        
        try {
            FileReader file = new FileReader("src/Recursos/data.txt");
            BufferedReader br = new BufferedReader(file);
            String line, token;
            StringTokenizer t;
            int c = 0;

            line = br.readLine();
            while (line != null) {
                String aux = null;
                c = 0;
                t = new StringTokenizer(line, ",");
                while (t.hasMoreTokens()) {
                    token = t.nextToken();
                    c++;
                    switch(c)
                    {
                        case 5:
                            int index;
                            aux = token;
                            token = t.nextToken();
                            if(!lE.contains(token))
                            {
                                lE.add(token);
                                lH.add(0);
                                lM.add(0);
                            }
                            
                            index = lE.indexOf(token);
                            
                            if(aux.equalsIgnoreCase("H"))
                            {
                                lH.set(index, lH.get(index)+1);
                            }
                            else
                            {
                                lM.set(index, lM.get(index)+1);
                            }
                            break;
                    }
                }
                line = br.readLine();
            }
            
            for(int i=0; i<lE.size(); i++)
            {
                dataset.addValue(lM.get(i), "Mujeres", lE.get(i));
                dataset.addValue(lH.get(i), "Hombres", lE.get(i));
                System.out.println(lM.get(i) + "\t" + lH.get(i) + "\t" + lE.get(i));
            }
            file.close();
        } catch (IOException e) {
            System.out.println("Exception");
        }

        return dataset;
    }

    public static void main(String[] args) {
        Ejercicio_Grafica grafica = new Ejercicio_Grafica("Gráfica");
        grafica.pack();
        grafica.setVisible(true);
        grafica.setLocationRelativeTo(null);
        grafica.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

}
