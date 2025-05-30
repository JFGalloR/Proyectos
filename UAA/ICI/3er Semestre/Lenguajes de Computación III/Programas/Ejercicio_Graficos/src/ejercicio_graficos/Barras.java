package ejercicio_graficos;

import javax.swing.JFrame;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.data.category.CategoryDataset;
import org.jfree.data.category.DefaultCategoryDataset;

public class Barras extends JFrame {

    public Barras(String appTitle) {
        super(appTitle);

        // Create Dataset  
        CategoryDataset dataset = createDataset();

        //Create chart  
        JFreeChart chart = ChartFactory.createBarChart(
                "Bar Chart Example", //Chart Title  
                "Year", // Category axis  
                "Population in Million", // Value axis  
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

        // Population in 2005  
        dataset.addValue(10, "USA", "2005");
        dataset.addValue(15, "India", "2005");
        dataset.addValue(20, "China", "2005");

        // Population in 2010  
        dataset.addValue(15, "USA", "2010");
        dataset.addValue(20, "India", "2010");
        dataset.addValue(25, "China", "2010");

        // Population in 2015  
        dataset.addValue(20, "USA", "2015");
        dataset.addValue(25, "India", "2015");
        dataset.addValue(30, "China", "2015");

        return dataset;
    }
}
